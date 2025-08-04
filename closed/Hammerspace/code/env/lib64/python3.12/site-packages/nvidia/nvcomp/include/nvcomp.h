/*
 * SPDX-FileCopyrightText: Copyright (c) 2017-2024 NVIDIA CORPORATION & AFFILIATES.
 * All rights reserved. SPDX-License-Identifier: LicenseRef-NvidiaProprietary
 *
 * NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
 * property and proprietary rights in and to this material, related
 * documentation and any modifications thereto. Any use, reproduction,
 * disclosure or distribution of this material and related documentation
 * without an express license agreement from NVIDIA CORPORATION or
 * its affiliates is strictly prohibited.
*/

#pragma once

#include "nvcomp/shared_types.h"
#include "nvcomp/version.h"
#include "nvcomp_export.h"

#include <cuda_runtime.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NVCC__
#define NVCOMP_HOST_DEVICE_FUNCTION
#else
#define NVCOMP_HOST_DEVICE_FUNCTION __host__ __device__
#endif

/******************************************************************************
 * CONSTANTS ******************************************************************
 *****************************************************************************/

/* Supported datatypes */
typedef enum nvcompType_t
{
  NVCOMP_TYPE_CHAR = 0,      // 1B
  NVCOMP_TYPE_UCHAR = 1,     // 1B
  NVCOMP_TYPE_SHORT = 2,     // 2B
  NVCOMP_TYPE_USHORT = 3,    // 2B
  NVCOMP_TYPE_INT = 4,       // 4B
  NVCOMP_TYPE_UINT = 5,      // 4B
  NVCOMP_TYPE_LONGLONG = 6,  // 8B
  NVCOMP_TYPE_ULONGLONG = 7, // 8B
  NVCOMP_TYPE_UINT8 = 8,     // 1B
  NVCOMP_TYPE_FLOAT16 = 9,   // 2B
  NVCOMP_TYPE_BITS = 0xff    // 1b
} nvcompType_t;


/**
 * @brief nvCOMP properties.
 */
typedef struct
{
    /// nvCOMP library version.
    uint32_t version;        
    /// Version of CUDA Runtime with which nvCOMP library was built.
    uint32_t cudart_version;  
} nvcompProperties_t;


/******************************************************************************
 * FUNCTION PROTOTYPES ********************************************************
 *****************************************************************************/

/**
 * @brief Provides nvCOMP library properties.
 *
 * @param[out] properties Set nvCOMP properties in nvcompProperties_t handle.
 *
 * @return nvcompErrorInvalidValue is properties is nullptr, nvcompSuccess otherwise
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompGetProperties(nvcompProperties_t* properties);

/**
 * @brief Computes the required temporary workspace required to perform
 * decompression.
 *
 * @param metadata_ptr The metadata.
 * @param temp_bytes The size of the required temporary workspace in bytes
 * (output).
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 *
 * @deprecated This interface is deprecated and will be removed in future releases, 
 * please switch to the compression schemes specific interfaces in nvcomp/cascaded.h,
 * nvcomp/lz4.h, nvcomp/snappy, nvcomp/bitcomp.h, nvcomp/gdeflate.h, nvcomp/zstd.h,
 * nvcomp/deflate.h and nvcomp/ans.h.
 */
NVCOMP_EXPORT
nvcompStatus_t
nvcompDecompressGetTempSize(const void* metadata_ptr, size_t* temp_bytes);

/**
 * @brief Computes the size of the uncompressed data in bytes.
 *
 * @param metadata_ptr The metadata.
 * @param output_bytes The size of the uncompressed data (output).
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 *
 * @deprecated This interface is deprecated and will be removed in future releases, 
 * please switch to the compression schemes specific interfaces in nvcomp/cascaded.h,
 * nvcomp/lz4.h, nvcomp/snappy, nvcomp/bitcomp.h, nvcomp/gdeflate.h, nvcomp/zstd.h,
 * nvcomp/deflate.h and nvcomp/ans.h.
 */
NVCOMP_EXPORT
nvcompStatus_t
nvcompDecompressGetOutputSize(const void* metadata_ptr, size_t* output_bytes);

/**
 * @brief Get the type of the compressed data.
 *
 * @param metadata_ptr The metadata.
 * @param type The data type (output).
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 *
 * @deprecated This interface is deprecated and will be removed in future releases, 
 * please switch to the compression schemes specific interfaces in nvcomp/cascaded.h,
 * nvcomp/lz4.h, nvcomp/snappy, nvcomp/bitcomp.h, nvcomp/gdeflate.h, nvcomp/zstd.h,
 * nvcomp/deflate.h and nvcomp/ans.h.
 */
NVCOMP_EXPORT
nvcompStatus_t
nvcompDecompressGetType(const void* metadata_ptr, nvcompType_t* type);

/**
 * @brief Perform the asynchronous decompression.
 *
 * @param in_ptr The compressed data on the device to decompress.
 * @param in_bytes The size of the compressed data.
 * @param temp_ptr The temporary workspace on the device.
 * @param temp_bytes The size of the temporary workspace.
 * @param metadata_ptr The metadata.
 * @param out_ptr The output location on the device.
 * @param out_bytes The size of the output location.
 * @param stream The cuda stream to operate on.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 *
 * @deprecated This interface is deprecated and will be removed in future releases, 
 * please switch to the compression schemes specific interfaces in nvcomp/cascaded.h,
 * nvcomp/lz4.h, nvcomp/snappy, nvcomp/bitcomp.h, nvcomp/gdeflate.h, nvcomp/zstd.h,
 * nvcomp/deflate.h and nvcomp/ans.h.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompDecompressAsync(
    const void* in_ptr,
    size_t in_bytes,
    void* temp_ptr,
    size_t temp_bytes,
    void* metadata_ptr,
    void* out_ptr,
    size_t out_bytes,
    cudaStream_t stream);

#ifdef __cplusplus
}
#endif
