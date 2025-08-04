/*
 * SPDX-FileCopyrightText: Copyright (c) 2021-2024 NVIDIA CORPORATION & AFFILIATES.
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

#include <cstdint>

#include <nvcomp_export.h>

namespace gdeflate {

/**
 * @brief Perform decompression on the CPU.
 *
 * @param[in] in_ptr The pointers on the CPU, to the compressed chunks.
 * @param[in] in_bytes The size of each compressed batch item on the CPU.
 * @param[in] batch_size The number of batch items.
 * @param[out] out_ptr The pointers on the CPU, to where to uncompress each chunk (output).
 * @param[out] out_bytes The pointers on the CPU to store the uncompressed sizes (output).
 * Initially this array must contain the output buffer capacities (in bytes). The decompressor
 * will increase these with the number of bytes actually written. To retrieve the actual decompressed
 * sizes, after the decompression, simply subtract the initial byte capacities.
 *
 */
NVCOMP_EXPORT
void decompressCPU(
    const void* const* in_ptr,
    const size_t* in_bytes,
    size_t batch_size,
    void* const* out_ptr,
    size_t* out_bytes);

/**
 * @brief Perform compression on the CPU.
 *
 * @param[in] in_ptr The pointers on the CPU, to uncompressed batched items.
 * @param[in] in_bytes The size of each uncompressed batch item on the CPU.
 * @param[in] max_chunk_size The maximum size of a chunk.
 * @param[in] batch_size The number of batch items.
 * @param[out] out_ptr The pointers on the CPU, to the output location for each compressed batch item (output).
 * @param[out] out_bytes The compressed size of each chunk on the CPU (output).
 *
 */
NVCOMP_EXPORT
void compressCPU(
    const void* const* in_ptr,
    const size_t* in_bytes,
    const size_t max_chunk_size,
    size_t batch_size,
    void* const* out_ptr,
    size_t* out_bytes);

} // namespace gdeflate
