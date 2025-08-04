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

#ifndef NVCOMP_LZ4_H
#define NVCOMP_LZ4_H

#include "nvcomp.h"

#include <cuda_runtime.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Batched compression/decompression interface for LZ4
 *****************************************************************************/

/**
 * LZ4 compression options for the low-level API
 */
typedef struct
{
  nvcompType_t data_type;
} nvcompBatchedLZ4Opts_t;

static const nvcompBatchedLZ4Opts_t nvcompBatchedLZ4DefaultOpts = {NVCOMP_TYPE_CHAR};

const size_t nvcompLZ4CompressionMaxAllowedChunkSize = 1 << 24;

/**
 * The most restrictive of minimum alignment requirements for void-type CUDA memory buffers
 * used for input, output, or temporary memory, passed to compression or decompression functions.
 * In all cases, typed memory buffers must still be aligned to their type's size, e.g., 4 bytes for `int`.
 */
const size_t nvcompLZ4RequiredAlignment = 4;

/******************************************************************************
 * Batched compression/decompression interface
 *****************************************************************************/

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
nvcompStatus_t nvcompBatchedLZ4CompressGetRequiredAlignments(
    nvcompBatchedLZ4Opts_t format_opts,
    nvcompAlignmentRequirements_t* alignment_requirements);

/**
 * @brief Get the amount of temporary memory required on the GPU for compression.
 *
 * Chunk size must not exceed 16777216 bytes.
 * For best performance, a chunk size of 65536 bytes is recommended.
 *
 * @param[in] num_chunks The number of chunks of memory in the batch.
 * @param[in] max_uncompressed_chunk_bytes The maximum size of a chunk in the
 * batch.
 * @param[in] format_opts The LZ4 compression options to use.
 * @param[out] temp_bytes The amount of GPU memory that will be temporarily
 * required during compression.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4CompressGetTempSize(
    size_t num_chunks,
    size_t max_uncompressed_chunk_bytes,
    nvcompBatchedLZ4Opts_t format_opts,
    size_t* temp_bytes);

/**
 * @brief Get the amount of temporary memory required on the GPU for compression
 * with extra total bytes argument.
 *
 * Chunk size must not exceed 16777216 bytes.
 * For best performance, a chunk size of 65536 bytes is recommended.
 *
 * @param[in] num_chunks The number of chunks of memory in the batch.
 * @param[in] max_uncompressed_chunk_bytes The maximum size of a chunk in the
 * batch.
 * @param[in] format_opts The LZ4 compression options to use.
 * @param[out] temp_bytes The amount of GPU memory that will be temporarily
 * required during compression.
 * @param[in] max_total_uncompressed_bytes Upper bound on the total uncompressed
 * size of all chunks
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4CompressGetTempSizeEx(
    size_t num_chunks,
    size_t max_uncompressed_chunk_bytes,
    nvcompBatchedLZ4Opts_t format_opts,
    size_t* temp_bytes,
    const size_t max_total_uncompressed_bytes);

/**
 * @brief Get the maximum size that a chunk of size at most max_uncompressed_chunk_bytes
 * could compress to. That is, the minimum amount of output memory required to be given
 * nvcompBatchedLZ4CompressAsync() for each chunk.
 *
 * Chunk size must not exceed 16777216 bytes.
 * For best performance, a chunk size of 65536 bytes is recommended.
 *
 * @param[in] max_uncompressed_chunk_bytes The maximum size of a chunk before compression.
 * @param[in] format_opts The LZ4 compression options to use.
 * @param[out] max_compressed_chunk_bytes The maximum possible compressed size of the chunk.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4CompressGetMaxOutputChunkSize(
    size_t max_uncompressed_chunk_bytes,
    nvcompBatchedLZ4Opts_t format_opts,
    size_t* max_compressed_chunk_bytes);

/**
 * @brief Perform batched asynchronous compression.
 *
 * @note Violating any of the conditions listed in the parameter descriptions
 * below may result in undefined behaviour.
 *
 * @param[in] device_uncompressed_chunk_ptrs Array with size \p num_chunks of pointers
 * to the uncompressed data chunks. Both the pointers and the uncompressed data
 * should reside in device-accessible memory.
 * Each chunk must be aligned to the value in the `input` member of the
 * \ref nvcompAlignmentRequirements_t object output by
 * `nvcompBatchedLZ4CompressGetRequiredAlignments` when called with the same
 * \p format_opts.
 * @param[in] device_uncompressed_chunk_bytes Array with size \p num_chunks of
 * sizes of the uncompressed chunks in bytes.
 * The sizes should reside in device-accessible memory.
 * Each chunk size must be a multiple of the size of the data type specified by
 * format_opts.data_type.
 * Chunk sizes must not exceed 16777216 bytes. For best performance, a chunk size
 * of 65536 bytes is recommended.
 * @param[in] max_uncompressed_chunk_bytes The size of the largest uncompressed chunk.
 * @param[in] num_chunks Number of chunks of data to compress.
 * @param[in] device_temp_ptr The temporary GPU workspace.
 * Must be aligned to the value in the `temp` member of the
 * \ref nvcompAlignmentRequirements_t object output by
 * `nvcompBatchedLZ4CompressGetRequiredAlignments` when called with the same
 * \p format_opts.
 * @param[in] temp_bytes The size of the temporary GPU memory pointed to by
 * `device_temp_ptr`.
 * @param[out] device_compressed_chunk_ptrs Array with size \p num_chunks of pointers
 * to the output compressed buffers. Both the pointers and the compressed
 * buffers should reside in device-accessible memory. Each compressed buffer
 * should be preallocated with the size given by
 * `nvcompBatchedLZ4CompressGetMaxOutputChunkSize`.
 * Each compressed buffer must be aligned to the value in the `output` member of the
 * \ref nvcompAlignmentRequirements_t object output by
 * `nvcompBatchedLZ4CompressGetRequiredAlignments` when called with the same
 * \p format_opts.
 * @param[out] device_compressed_chunk_bytes Array with size \p num_chunks, 
 * to be filled with the compressed sizes of each chunk.
 * The buffer should be preallocated in device-accessible memory.
 * @param[in] format_opts The LZ4 compression options to use.
 * @param[in] stream The CUDA stream to operate on.
 *
 * @return nvcompSuccess if successfully launched, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4CompressAsync(
    const void* const* device_uncompressed_chunk_ptrs,
    const size_t* device_uncompressed_chunk_bytes,
    size_t max_uncompressed_chunk_bytes,
    size_t num_chunks,
    void* device_temp_ptr,
    size_t temp_bytes,
    void* const* device_compressed_chunk_ptrs,
    size_t* device_compressed_chunk_bytes,
    nvcompBatchedLZ4Opts_t format_opts,
    cudaStream_t stream);

/**
 * Minimum buffer alignment requirements for decompression.
 */
const nvcompAlignmentRequirements_t nvcompBatchedLZ4DecompressRequiredAlignments = {
    /*input=*/1, /*output=*/1, /*temp=*/1};

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
nvcompStatus_t nvcompBatchedLZ4DecompressGetTempSize(
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
 * Unused in LZ4.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4DecompressGetTempSizeEx(
    size_t num_chunks, size_t max_uncompressed_chunk_bytes,
    size_t* temp_bytes, size_t max_total_uncompressed_bytes);

/**
 * @brief Asynchronously compute the number of bytes of uncompressed data for
 * each compressed chunk.
 *
 * This is needed when we do not know the expected output size.
 *
 * @note If the stream is corrupt, the calculated sizes will be invalid.
 *
 * @note Violating any of the conditions listed in the parameter descriptions
 * below may result in undefined behaviour.
 *
 * @param[in] device_compressed_chunk_ptrs Array with size \p num_chunks of
 * pointers in device-accessible memory to compressed buffers.
 * Each buffer must be aligned to the value in
 * `nvcompBatchedLZ4DecompressRequiredAlignments.input`.
 * @param[in] device_compressed_chunk_bytes Array with size \p num_chunks of sizes
 * of the compressed buffers in bytes. The sizes should reside in device-accessible memory.
 * @param[out] device_uncompressed_chunk_bytes Array with size \p num_chunks
 * to be filled with the sizes, in bytes, of each uncompressed data chunk.
 * This argument needs to be preallocated in device-accessible memory.
 * @param[in] num_chunks Number of data chunks to compute sizes of.
 * @param[in] stream The CUDA stream to operate on.
 *
 * @return nvcompSuccess if successful, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4GetDecompressSizeAsync(
    const void* const* device_compressed_chunk_ptrs,
    const size_t* device_compressed_chunk_bytes,
    size_t* device_uncompressed_chunk_bytes,
    size_t num_chunks,
    cudaStream_t stream);

/**
 * @brief Perform batched asynchronous decompression.
 *
 * @note Violating any of the conditions listed in the parameter descriptions
 * below may result in undefined behaviour.
 *
 * @note In the case where a chunk of compressed data is not a valid LZ4
 * block, 0 will be written for the size of the invalid chunk and
 * nvcompStatusCannotDecompress will be flagged for that chunk.
 *
 * @param[in] device_compressed_chunk_ptrs Array with size \p num_chunks of pointers
 * in device-accessible memory to device-accessible compressed buffers.
 * Each buffer must be aligned to the value in
 * `nvcompBatchedLZ4DecompressRequiredAlignments.input`.
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
 * This argument needs to be preallocated, but can be nullptr if desired,
 * in which case the actual sizes are not reported.
 * @param[in] num_chunks Number of chunks of data to decompress.
 * @param[in] device_temp_ptr The temporary GPU space.
 * Must be aligned to the value in `nvcompBatchedLZ4DecompressRequiredAlignments.temp`.
 * @param[in] temp_bytes The size of the temporary GPU space.
 * @param[out] device_uncompressed_chunk_ptrs Array with size \p num_chunks of
 * pointers in device-accessible memory to decompressed data. Each uncompressed
 * buffer needs to be preallocated in device-accessible memory, have the size
 * specified by the corresponding entry in \p device_uncompressed_buffer_bytes,
 * and be aligned to the value in
 * `nvcompBatchedLZ4DecompressRequiredAlignments.output`.
 * @param[out] device_statuses Array with size \p num_chunks of statuses in
 * device-accessible memory. This argument needs to be preallocated. For each
 * chunk, if the decompression is successful, the status will be set to
 * `nvcompSuccess`. If the decompression is not successful, for example due to
 * the corrupted input or out-of-bound errors, the status will be set to
 * `nvcompErrorCannotDecompress`.
 * Can be nullptr if desired, in which case error status is not reported.
 * @param[in] stream The CUDA stream to operate on.
 *
 * @return nvcompSuccess if successfully launched, and an error code otherwise.
 */
NVCOMP_EXPORT
nvcompStatus_t nvcompBatchedLZ4DecompressAsync(
    const void* const* device_compressed_chunk_ptrs,
    const size_t* device_compressed_chunk_bytes,
    const size_t* device_uncompressed_buffer_bytes,
    size_t* device_uncompressed_chunk_bytes,
    size_t num_chunks,
    void* const device_temp_ptr,
    size_t temp_bytes,
    void* const* device_uncompressed_chunk_ptrs,
    nvcompStatus_t* device_statuses,
    cudaStream_t stream);

#ifdef __cplusplus
}
#endif

#endif
