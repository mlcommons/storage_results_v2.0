/*
 * Copyright (c) 2020 - 2024, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */

#ifndef NVJPEG2K_HEADER
#define NVJPEG2K_HEADER

#include <stdlib.h>
#include <stdint.h>

#ifdef _NVJPEG2K_DISABLE_CUDA_TOOLKIT_HEADERS
typedef void* cudaStream_t;
typedef enum libraryPropertyType_t
{
    MAJOR_VERSION,
    MINOR_VERSION,
    PATCH_LEVEL
} libraryPropertyType;
#else
#include "cuda_runtime_api.h"
#include "library_types.h"
#endif

#include "nvjpeg2k_version.h"

#ifndef NVJPEG2KAPI
#ifdef _WIN32
#define NVJPEG2KAPI __declspec(dllexport)
#elif  __GNUC__ >= 4
#define NVJPEG2KAPI __attribute__ ((visibility ("default")))
#else
#define NVJPEG2KAPI
#endif
#endif

#if defined(__cplusplus)
  extern "C" {
#endif


// Prototype for device memory allocation, modelled after cudaMalloc()
typedef int (*nvjpeg2kDeviceMalloc)(void**, size_t);
// Prototype for device memory release
typedef int (*nvjpeg2kDeviceFree)(void*);

// Prototype for pinned memory allocation, modelled after cudaHostAlloc()
typedef int (*nvjpeg2kPinnedMalloc)(void**, size_t, unsigned int flags);
// Prototype for pinned memory release
typedef int (*nvjpeg2kPinnedFree)(void*);

typedef struct 
{
    nvjpeg2kDeviceMalloc device_malloc;
    nvjpeg2kDeviceFree device_free;
} nvjpeg2kDeviceAllocator_t;

typedef struct 
{
    nvjpeg2kPinnedMalloc pinned_malloc;
    nvjpeg2kPinnedFree   pinned_free;
} nvjpeg2kPinnedAllocator_t;

// Prototype for extended device allocation
typedef int (*nvjpeg2kDeviceMallocV2)(void* ctx, void **ptr, size_t size, cudaStream_t stream);
// Prototype for extended device free
typedef int (*nvjpeg2kDeviceFreeV2)(void* ctx, void *ptr, size_t size, cudaStream_t stream);

// Prototype for extended pinned allocation
typedef int (*nvjpeg2kPinnedMallocV2)(void* ctx, void **ptr, size_t size, cudaStream_t stream);
// Prototype for extended pinned free
typedef int (*nvjpeg2kPinnedFreeV2)(void* ctx, void *ptr, size_t size, cudaStream_t stream);

typedef struct nvjpeg2kPinnedAllocatorV2
{
    nvjpeg2kPinnedMallocV2 pinned_malloc;
    nvjpeg2kPinnedFreeV2   pinned_free;
    void *pinned_ctx;
} nvjpeg2kPinnedAllocatorV2_t;

typedef struct nvjpeg2kDeviceAllocatorV2
{
    nvjpeg2kDeviceMallocV2 device_malloc;
    nvjpeg2kDeviceFreeV2 device_free;
    void *device_ctx;
} nvjpeg2kDeviceAllocatorV2_t;


typedef enum
{
    NVJPEG2K_STATUS_SUCCESS                       = 0,
    NVJPEG2K_STATUS_NOT_INITIALIZED               = 1,
    NVJPEG2K_STATUS_INVALID_PARAMETER             = 2,
    NVJPEG2K_STATUS_BAD_JPEG                      = 3,
    NVJPEG2K_STATUS_JPEG_NOT_SUPPORTED            = 4,
    NVJPEG2K_STATUS_ALLOCATOR_FAILURE             = 5,
    NVJPEG2K_STATUS_EXECUTION_FAILED              = 6,
    NVJPEG2K_STATUS_ARCH_MISMATCH                 = 7,
    NVJPEG2K_STATUS_INTERNAL_ERROR                = 8,
    NVJPEG2K_STATUS_IMPLEMENTATION_NOT_SUPPORTED  = 9,
} nvjpeg2kStatus_t;

typedef enum 
{
    NVJPEG2K_BACKEND_DEFAULT = 0
} nvjpeg2kBackend_t;

typedef enum 
{
    NVJPEG2K_COLORSPACE_NOT_SUPPORTED = -1,
    NVJPEG2K_COLORSPACE_UNKNOWN       = 0,
    NVJPEG2K_COLORSPACE_SRGB          = 1,
    NVJPEG2K_COLORSPACE_GRAY          = 2,
    NVJPEG2K_COLORSPACE_SYCC          = 3
} nvjpeg2kColorSpace_t;

typedef struct 
{
    uint32_t component_width;
    uint32_t component_height; 
    uint8_t  precision;
    uint8_t  sgn;
} nvjpeg2kImageComponentInfo_t;

typedef struct 
{
    uint32_t image_width;
    uint32_t image_height;
    uint32_t tile_width;
    uint32_t tile_height;
    uint32_t num_tiles_x; // no of tiles in horizontal direction
    uint32_t num_tiles_y; // no of tiles in vertical direction
    uint32_t num_components;
} nvjpeg2kImageInfo_t;

typedef enum
{
    NVJPEG2K_UINT8 = 0,
    NVJPEG2K_UINT16 = 1,
    NVJPEG2K_INT16 = 2
} nvjpeg2kImageType_t;

typedef enum
{
    NVJPEG2K_FORMAT_PLANAR = 0,
    NVJPEG2K_FORMAT_INTERLEAVED = 1 
} nvjpeg2kImageFormat_t;

typedef struct
{
    void **pixel_data;
    size_t *pitch_in_bytes;
    nvjpeg2kImageType_t pixel_type;
    uint32_t num_components; 
} nvjpeg2kImage_t;

#define NVJPEG2K_MAXRES 33

typedef enum 
{
    NVJPEG2K_LRCP = 0,
    NVJPEG2K_RLCP = 1,
    NVJPEG2K_RPCL = 2,
    NVJPEG2K_PCRL = 3,
    NVJPEG2K_CPRL = 4
} nvjpeg2kProgOrder;

typedef enum 
{
    NVJPEG2K_STREAM_J2K  = 0,
    NVJPEG2K_STREAM_JP2  = 1
} nvjpeg2kBitstreamType;

// contains parameters present in the COD and SIZ headers of the JPEG 2000 bitstream
typedef struct 
{
    nvjpeg2kBitstreamType stream_type;
    nvjpeg2kColorSpace_t color_space;
    uint16_t rsiz; // should be set to 0
    uint32_t image_width;
    uint32_t image_height;
    uint32_t enable_tiling;
    uint32_t tile_width;
    uint32_t tile_height;
    uint32_t num_components;
    nvjpeg2kImageComponentInfo_t *image_comp_info;
    uint32_t enable_SOP_marker; // should be set to 0
    uint32_t enable_EPH_marker;  // should be set to 0
    nvjpeg2kProgOrder prog_order;
    uint32_t num_layers;  // should be set to 1
    uint32_t mct_mode;
    uint32_t num_resolutions;
    uint32_t code_block_w;
    uint32_t code_block_h;
    uint32_t encode_modes; // should be set to 0
    uint32_t irreversible;
    uint32_t num_precincts_init; // to enable, set to a non zero value corresponding to the no of valid entries in precinct_width and precinct_height
    uint32_t precinct_width[NVJPEG2K_MAXRES];  // should be a power of 2
    uint32_t precinct_height[NVJPEG2K_MAXRES]; // should be a power of 2
} nvjpeg2kEncodeConfig_t;

struct nvjpeg2kHandle;
typedef struct nvjpeg2kHandle* nvjpeg2kHandle_t;

struct nvjpeg2kDecodeState;
typedef struct nvjpeg2kDecodeState* nvjpeg2kDecodeState_t;

struct nvjpeg2kStream;
typedef struct nvjpeg2kStream* nvjpeg2kStream_t;

struct nvjpeg2kDecodeParams;
typedef struct nvjpeg2kDecodeParams* nvjpeg2kDecodeParams_t;


struct nvjpeg2kEncoder;
typedef struct nvjpeg2kEncoder* nvjpeg2kEncoder_t;

struct nvjpeg2kEncodeState;
typedef struct nvjpeg2kEncodeState* nvjpeg2kEncodeState_t;

struct nvjpeg2kEncodeParams;
typedef struct nvjpeg2kEncodeParams* nvjpeg2kEncodeParams_t;

// returns library's property values
// IN         type         : Version type, MAJOR_VERSION, MINOR_VERSION or PATCH_LEVEL
// IN/OUT     value        : Version number
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kGetCudartProperty(libraryPropertyType type, int *value);

// returns CUDA Toolkit property values that was used for building library, 
// IN         type         : Version type, MAJOR_VERSION, MINOR_VERSION or PATCH_LEVEL
// IN/OUT     value        : Version number
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kGetProperty(libraryPropertyType type, int *value);

// Initialization of nvjpeg2k handle
// IN/OUT     handle        : nvjpeg2k handle instance
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kCreateSimple(nvjpeg2kHandle_t *handle);

// Initialization of nvjpeg2k handle with extended custom allocators
// IN         backend       : Backend to use. Currently NVJPEG2K_BACKEND_DEFAULT is supported.
// IN         dev_allocator : Pointer to nvjpeg2kDeviceAllocatorV2_t. If NULL - use default cuda calls (cudaMalloc/cudaFree)
// IN         pinned_allocator : Pointer to nvjpeg2kPinnedAllocatorV2_t. If NULL - use default cuda calls (cudaHostAlloc/cudaFreeHost)
// IN/OUT     handle        : nvjpeg2k handle instance
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kCreate(
        nvjpeg2kBackend_t backend,
        nvjpeg2kDeviceAllocator_t *device_allocator, 
        nvjpeg2kPinnedAllocator_t *pinned_allocator, 
        nvjpeg2kHandle_t *handle);

// Initialization of nvjpeg2k handle with extended custom allocators
// IN         backend       : Backend to use. Currently NVJPEG2K_BACKEND_DEFAULT is supported.
// IN         dev_allocator : Pointer to nvjpeg2kDeviceAllocatorV2_t. Cannot be NULL.
// IN         pinned_allocator : Pointer to nvjpeg2kPinnedAllocatorV2_t. Cannot be NULL.
// IN/OUT     handle        : nvjpeg2k handle instance
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kCreateV2(nvjpeg2kBackend_t backend,
        nvjpeg2kDeviceAllocatorV2_t *dev_allocator,
        nvjpeg2kPinnedAllocatorV2_t *pinned_allocator,
        nvjpeg2kHandle_t *handle);

// Release the handle and resources.
// IN/OUT     handle: instance handle to release 
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDestroy(nvjpeg2kHandle_t handle);

// Sets padding for device memory allocations. After success on this call any device memory allocation
// would be padded to the multiple of specified number of bytes. 
// IN         padding: padding size
// IN/OUT     handle: nvjpeg2k handle
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kSetDeviceMemoryPadding(
        size_t padding, 
        nvjpeg2kHandle_t handle);

// Retrieves padding for pinned host memory allocations
// IN/OUT     padding: padding size currently used in handle.
// IN         handle: nvjpeg2k handle
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kGetDeviceMemoryPadding(
        size_t *padding,
        nvjpeg2kHandle_t handle);

// Sets padding for pinned host memory allocations. After success on this call any pinned host memory allocation
// would be padded to the multiple of specified number of bytes. 
// IN         padding: padding size
// IN/OUT     handle: nvjpeg2k handle
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kSetPinnedMemoryPadding(
        size_t padding, 
        nvjpeg2kHandle_t handle);

// Retrieves padding for pinned host memory allocations
// IN/OUT     padding: padding size currently used in handle.
// IN         handle: nvjpeg2k handle
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kGetPinnedMemoryPadding(
        size_t *padding, 
        nvjpeg2kHandle_t handle);


nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeStateCreate(
        nvjpeg2kHandle_t handle, 
        nvjpeg2kDecodeState_t *decode_state);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeStateDestroy(nvjpeg2kDecodeState_t decode_state);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamCreate(nvjpeg2kStream_t *stream_handle);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamDestroy(nvjpeg2kStream_t stream_handle);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamParse(nvjpeg2kHandle_t handle,
        const unsigned char *data, 
        size_t length, 
        int save_metadata,
        int save_stream,
        nvjpeg2kStream_t stream_handle);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamParseFile(nvjpeg2kHandle_t handle,
        const char *filename, 
        nvjpeg2kStream_t stream_handle);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamGetImageInfo(nvjpeg2kStream_t stream_handle,
        nvjpeg2kImageInfo_t* image_info);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamGetImageComponentInfo(nvjpeg2kStream_t stream_handle,
        nvjpeg2kImageComponentInfo_t* component_info,
        uint32_t component_id);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamGetResolutionsInTile(nvjpeg2kStream_t stream_handle, 
        uint32_t tile_id,
        uint32_t* num_res);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamGetTileComponentDim(nvjpeg2kStream_t stream_handle, 
        uint32_t component_id,
        uint32_t tile_id, 
        uint32_t* tile_width, 
        uint32_t* tile_height);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamGetResolutionComponentDim(nvjpeg2kStream_t stream_handle, 
        uint32_t component_id,
        uint32_t tile_id,
        uint32_t res_level,
        uint32_t* res_width,
        uint32_t* res_height );

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kStreamGetColorSpace(nvjpeg2kStream_t stream_handle, 
        nvjpeg2kColorSpace_t* color_space);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeParamsCreate(
        nvjpeg2kDecodeParams_t *decode_params);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeParamsDestroy(nvjpeg2kDecodeParams_t decode_params);


nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeParamsSetDecodeArea(nvjpeg2kDecodeParams_t decode_params,
        uint32_t start_x,
        uint32_t end_x, 
        uint32_t start_y, 
        uint32_t end_y);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeParamsSetRGBOutput(nvjpeg2kDecodeParams_t decode_params,
        int32_t force_rgb);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeParamsSetOutputFormat(nvjpeg2kDecodeParams_t decode_params,
        nvjpeg2kImageFormat_t format);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecode(nvjpeg2kHandle_t handle, 
        nvjpeg2kDecodeState_t decode_state, 
        nvjpeg2kStream_t jpeg2k_stream, 
        nvjpeg2kImage_t* decode_output,
        cudaStream_t stream);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeImage(nvjpeg2kHandle_t handle, 
        nvjpeg2kDecodeState_t decode_state, 
        nvjpeg2kStream_t jpeg2k_stream, 
        nvjpeg2kDecodeParams_t decode_params,
        nvjpeg2kImage_t* decode_output,
        cudaStream_t stream);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kDecodeTile(nvjpeg2kHandle_t handle, 
        nvjpeg2kDecodeState_t decode_state, 
        nvjpeg2kStream_t jpeg2k_stream, 
        nvjpeg2kDecodeParams_t decode_params,
        uint32_t tile_id,
        uint32_t num_res_levels,
        nvjpeg2kImage_t* decode_output,
        cudaStream_t stream);


/// Encoder APIs
nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncoderCreateSimple(nvjpeg2kEncoder_t *enc_handle);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncoderDestroy(nvjpeg2kEncoder_t enc_handle);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeStateCreate(
        nvjpeg2kEncoder_t enc_handle, 
        nvjpeg2kEncodeState_t *encode_state);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeStateDestroy(nvjpeg2kEncodeState_t encode_state);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeParamsCreate(nvjpeg2kEncodeParams_t *encode_params);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeParamsDestroy(nvjpeg2kEncodeParams_t encode_params);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeParamsSetEncodeConfig(nvjpeg2kEncodeParams_t encode_params, 
        nvjpeg2kEncodeConfig_t* encoder_config);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeParamsSetQuality(nvjpeg2kEncodeParams_t encode_params, 
        double target_psnr);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeParamsSetInputFormat(nvjpeg2kEncodeParams_t encode_params,
        nvjpeg2kImageFormat_t format);

nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncode(nvjpeg2kEncoder_t enc_handle,
        nvjpeg2kEncodeState_t encode_state,
        const nvjpeg2kEncodeParams_t encode_params,
        const nvjpeg2kImage_t *input_image,
        cudaStream_t stream);


nvjpeg2kStatus_t NVJPEG2KAPI nvjpeg2kEncodeRetrieveBitstream(nvjpeg2kEncoder_t enc_handle,
          nvjpeg2kEncodeState_t encode_state,
          unsigned char *compressed_data,
          size_t *length,
          cudaStream_t stream);

#if defined(__cplusplus)
  }
#endif

#endif
