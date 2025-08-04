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

#ifndef NVCOMP_CASCADED_H
#define NVCOMP_CASCADED_H

#include "nvcomp.h"

#include <cuda_runtime.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Batched compression/decompression interface
 *****************************************************************************/

/**
 * @brief Structure that stores the compression configuration
 */
typedef struct
{
  /**
   * @brief The size of each internal chunk of data to decompress independently with
   * 
   * Cascaded compression. The value should be in the range of [512, 16384]
   * depending on the datatype of the input and the shared memory size of
   * the GPU being used.  This is not the size of chunks passed into the API.
   * Recommended size is 4096.
   *
   * @note Not currently used and a default of 4096 is just used.
   */
  size_t internal_chunk_bytes;

  /**
   * @brief The datatype used to define the bit-width for compression
   */
  nvcompType_t type;

  /**
   * @brief The number of Run Length Encodings to perform.
   */
  int num_RLEs;

  /**
   * @brief The number of Delta Encodings to perform.
   */
  int num_deltas;

  /**
   * @brief Whether or not to bitpack the final layers.
   */
  int use_bp;
} nvcompBatchedCascadedOpts_t;

// Default options for batched compression
static const nvcompBatchedCascadedOpts_t nvcompBatchedCascadedDefaultOpts
    = {4096, NVCOMP_TYPE_INT, 2, 1, 1};

const size_t nvcompCascadedCompressionMaxAllowedChunkSize = 1 << 24;

/**
 * The most restrictive of minimum alignment requirements for void-type CUDA memory buffers
 * used for input, output, or temporary memory, passed to compression or decompression functions.
 * In all cases, typed memory buffers must still be aligned to their type's size, e.g., 4 bytes for `int`.
 */
const size_t nvcompCascadedRequiredAlignment = 8;

/**
 * @brief Get the minimum buffer alignment requirements for compression.
 *
 * @param[in] format_opts Compression options.
 * @param[out] alignment_requirements The minimum buffer alignment requirements
 * for compression.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedCompressGetRequiredAlignments(
    nvcompBatchedCascadedOpts_t format_opts,
    nvcompAlignmentRequirements_t* alignment_requirements);

/**
 * @brief Get the amount of temporary memory required on the GPU for compression.
 *
 * @note Batched Cascaded compression does not require temp space, so
 * this will set *temp_bytes=0, unless an error is found with the format_opts.
 *
 * @param[in] num_chunks The number of chunks of memory in the batch.
 * @param[in] max_uncompressed_chunk_bytes The maximum size of a chunk in the
 * batch. This parameter is currently unused. Set it to either the actual value 
 * or zero.
 * @param[in] format_opts The Cascaded compression options and datatype to use.
 * @param[out] temp_bytes The amount of GPU memory that will be temporarily
 * required during compression.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedCompressGetTempSize(
    size_t num_chunks,
    size_t max_uncompressed_chunk_bytes,
    nvcompBatchedCascadedOpts_t format_opts,
    size_t* temp_bytes);

/**
 * @brief Get the amount of temporary memory required on the GPU for compression
 * with extra total bytes argument.
 *
 * @note Batched Cascaded compression does not require temp space, so
 * this will set *temp_bytes=0, unless an error is found with the format_opts.
 *
 * @param[in] num_chunks The number of chunks of memory in the batch.
 * @param[in] max_uncompressed_chunk_bytes The maximum size of a chunk in the
 * batch. This parameter is currently unused. Set it to either the actual value 
 * or zero.
 * @param[in] format_opts The Cascaded compression options and datatype to use.
 * @param[out] temp_bytes The amount of GPU memory that will be temporarily
 * required during compression.
 * @param[in] max_total_uncompressed_bytes Upper bound on the total uncompressed
 * size of all chunks
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedCompressGetTempSizeEx(
    size_t num_chunks,
    size_t max_uncompressed_chunk_bytes,
    nvcompBatchedCascadedOpts_t format_opts,
    size_t* temp_bytes,
    const size_t max_total_uncompressed_bytes);

/**
 * @brief Get the maximum size that a chunk of size at most max_uncompressed_chunk_bytes
 * could compress to. That is, the minimum amount of output memory required to be given
 * nvcompBatchedCascadedCompressAsync() for each chunk.
 *
 * @param[in] max_uncompressed_chunk_bytes The maximum size of a chunk before compression.
 * @param[in] format_opts The Cascaded compression options to use.
 * @param[out] max_compressed_chunk_bytes The maximum possible compressed size of the chunk.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedCompressGetMaxOutputChunkSize(
    size_t max_uncompressed_chunk_bytes,
    nvcompBatchedCascadedOpts_t format_opts,
    size_t* max_compressed_chunk_bytes);

/**
 * @brief Perform batched asynchronous compression.
 *
 * @note The current implementation does not support uncompressed size larger
 * than 4,294,967,295 bytes (max uint32_t).
 *
 * @note Violating any of the conditions listed in the parameter descriptions
 * below may result in undefined behaviour.
 *
 * @param[in] device_uncompressed_chunk_ptrs Array with size \p num_chunks of pointers
 * to the uncompressed data chunks. Both the pointers and the uncompressed data
 * should reside in device-accessible memory.
 * Each chunk must be aligned to the value in the `input` member of the
 * \ref nvcompAlignmentRequirements_t object output by
 * `nvcompBatchedCascadedCompressGetRequiredAlignments` when called with the same
 * \p format_opts.
 * @param[in] device_uncompressed_chunk_bytes Array with size \p num_chunks of
 * sizes of the uncompressed chunks in bytes.
 * The sizes should reside in device-accessible memory.
 * Each chunk size must be a multiple of the size of the data type specified by
 * format_opts.type, else this may crash or produce invalid output.
 * @param[in] max_uncompressed_chunk_bytes The size of the largest uncompressed chunk.
 * This parameter is currently unused. Set it to either the actual value 
 * or zero.
 * @param[in] num_chunks Number of chunks of data to compress.
 * @param[in] device_temp_ptr This argument is not used.
 * @param[in] temp_bytes This argument is not used.
 * @param[out] device_compressed_chunk_ptrs Array with size \p num_chunks of pointers
 * to the output compressed buffers. Both the pointers and the compressed
 * buffers should reside in device-accessible memory. Each compressed buffer
 * should be preallocated with the size given by
 * `nvcompBatchedCascadedCompressGetMaxOutputChunkSize`.
 * Each compressed buffer must be aligned to the value in the `output` member of the
 * \ref nvcompAlignmentRequirements_t object output by
 * `nvcompBatchedCascadedCompressGetRequiredAlignments` when called with the same
 * \p format_opts.
 * @param[out] device_compressed_chunk_bytes Array with size \p num_chunks, 
 * to be filled with the compressed sizes of each chunk.
 * The buffer should be preallocated in device-accessible memory.
 * @param[in] format_opts The cascaded format options. The format must be valid.
 * @param[in] stream The CUDA stream to operate on.
 *
 * @return nvcompSuccess if successfully launched, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedCompressAsync(
    const void* const* device_uncompressed_chunk_ptrs,
    const size_t* device_uncompressed_chunk_bytes,
    size_t max_uncompressed_chunk_bytes, // not used
    size_t num_chunks,
    void* device_temp_ptr, // not used
    size_t temp_bytes,     // not used
    void* const* device_compressed_chunk_ptrs,
    size_t* device_compressed_chunk_bytes,
    nvcompBatchedCascadedOpts_t format_opts,
    cudaStream_t stream);

/**
 * Minimum buffer alignment requirements for decompression.
 */
const nvcompAlignmentRequirements_t nvcompBatchedCascadedDecompressRequiredAlignments = {
    /*input=*/4, /*output=*/8, /*temp=*/1};

/**
 * @brief Get the amount of temporary memory required on the GPU for decompression.
 *
 * @param[in] num_chunks Number of chunks of data to be decompressed.
 * @param[in] max_uncompressed_chunk_bytes The size of the largest chunk in bytes
 * when uncompressed.
 * @param[out] temp_bytes The amount of GPU memory that will be temporarily required
 * during decompression.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedDecompressGetTempSize(
    size_t num_chunks, size_t max_uncompressed_chunk_bytes, size_t* temp_bytes);

/**
 * @brief Get the amount of temporary memory required on the GPU for decompression
 * with extra total bytes argument.
 *
 * @param[in] num_chunks Number of chunks of data to be decompressed.
 * @param[in] max_uncompressed_chunk_bytes The size of the largest chunk in bytes
 * when uncompressed.
 * @param[out] temp_bytes The amount of GPU memory that will be temporarily required
 * during decompression.
 * @param[in] max_total_uncompressed_bytes  The total decompressed size of all the chunks. 
 * Unused in Cascaded.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedDecompressGetTempSizeEx(
    size_t num_chunks, size_t max_uncompressed_chunk_bytes,
    size_t* temp_bytes, size_t max_total_uncompressed_bytes);

/**
 * @brief Asynchronously compute the number of bytes of uncompressed data for
 * each compressed chunk.
 *
 * @note Violating any of the conditions listed in the parameter descriptions
 * below may result in undefined behaviour.
 *
 * @param[in] device_compressed_chunk_ptrs Array with size \p num_chunks of
 * pointers in device-accessible memory to compressed buffers.
 * Each buffer must be aligned to the value in
 * `nvcompBatchedCascadedDecompressRequiredAlignments.input`.
 * @param[in] device_compressed_chunk_bytes Array with size \p num_chunks of sizes
 * of the compressed buffers in bytes. The sizes should reside in device-accessible memory.
 * @param[out] device_uncompressed_chunk_bytes Array with size \p num_chunks
 * to be filled with the sizes, in bytes, of each uncompressed data chunk.
 * If there is an error when retrieving the size of a chunk, the
 * uncompressed size of that chunk will be set to 0. This argument needs to
 * be preallocated in device-accessible memory.
 * @param[in] num_chunks Number of data chunks to compute sizes of.
 * @param[in] stream The CUDA stream to operate on.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedGetDecompressSizeAsync(
    const void* const* device_compressed_chunk_ptrs,
    const size_t* device_compressed_chunk_bytes,
    size_t* device_uncompressed_chunk_bytes,
    size_t num_chunks,
    cudaStream_t stream);

/**
 * @brief Perform batched asynchronous decompression.
 *
 * This function is used to decompress compressed buffers produced by
 * `nvcompBatchedCascadedCompressAsync`.
 *
 * @note Violating any of the conditions listed in the parameter descriptions
 * below may result in undefined behaviour.
 *
 * @param[in] device_compressed_chunk_ptrs Array with size \p num_chunks of pointers
 * in device-accessible memory to device-accessible compressed buffers.
 * Each buffer must be aligned to the value in
 * `nvcompBatchedCascadedDecompressRequiredAlignments.input`.
 * @param[in] device_compressed_chunk_bytes Array with size \p num_chunks of sizes of
 * the compressed buffers in bytes. The sizes should reside in device-accessible memory.
 * @param[in] device_uncompressed_buffer_bytes Array with size \p num_chunks of sizes,
 * in bytes, of the output buffers to be filled with uncompressed data for each chunk.
 * The sizes should reside in device-accessible memory. If a
 * size is not large enough to hold all decompressed data, the decompressor
 * will set the status in \p device_statuses corresponding to the
 * overflow chunk to `nvcompErrorCannotDecompress`.
 * @param[out] device_uncompressed_chunk_bytes Array with size \p num_chunks to
 * be filled with the actual number of bytes decompressed for every chunk.
 * This argument needs to be preallocated.
 * @param[in] num_chunks Number of chunks of data to decompress.
 * @param[in] device_temp_ptr This argument is not used.
 * @param[in] temp_bytes This argument is not used.
 * @param[out] device_uncompressed_chunk_ptrs Array with size \p num_chunks of
 * pointers in device-accessible memory to decompressed data. Each uncompressed
 * buffer needs to be preallocated in device-accessible memory, have the size
 * specified by the corresponding entry in \p device_uncompressed_buffer_bytes,
 * and be aligned to the value in
 * `nvcompBatchedCascadedDecompressRequiredAlignments.output`.
 * @param[out] device_statuses Array with size \p num_chunks of statuses in
 * device-accessible memory. This argument needs to be preallocated. For each
 * chunk, if the decompression is successful, the status will be set to
 * `nvcompSuccess`. If the decompression is not successful, for example due to
 * the corrupted input or out-of-bound errors, the status will be set to
 * `nvcompErrorCannotDecompress`.
 * @param[in] stream The CUDA stream to operate on.
 *
 * @return nvcompSuccess if successfully launched, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedCascadedDecompressAsync(
    const void* const* device_compressed_chunk_ptrs,
    const size_t* device_compressed_chunk_bytes,
    const size_t* device_uncompressed_buffer_bytes,
    size_t* device_uncompressed_chunk_bytes,
    size_t num_chunks,
    void* const device_temp_ptr, // not used
    size_t temp_bytes,           // not used
    void* const* device_uncompressed_chunk_ptrs,
    nvcompStatus_t* device_statuses,
    cudaStream_t stream);
    
#ifdef __cplusplus
}
#endif

#endif
