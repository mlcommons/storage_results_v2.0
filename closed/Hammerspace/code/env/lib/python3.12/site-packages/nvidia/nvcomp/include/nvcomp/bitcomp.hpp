/*
 * SPDX-FileCopyrightText: Copyright (c) 2020-2024 NVIDIA CORPORATION & AFFILIATES.
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
#include "nvcompManager.hpp"
#include "nvcomp/bitcomp.h"

namespace nvcomp {

/**
 * @bried Format specification for Bitcomp compression
 */
struct BitcompFormatSpecHeader {
  /**
   * @brief Bitcomp algorithm options,
   *
   * - 0 : Default algorithm, usually gives the best compression ratios
   * - 1 : "Sparse" algorithm, works well on sparse data (with lots of zeroes).
   *        and is usually a faster than the default algorithm.
   */
  int algo;
  /**
   * @brief One of nvcomp's possible data types
   */
  nvcompType_t data_type;
};

/**
 * @brief High-level interface class for Bitcomp compressor
 * 
 * @note Any uncompressed data buffer to be compressed MUST be a size that is a
 * multiple of the data type size, else compression may crash or result in
 * invalid output.
 */
struct BitcompManager : PimplManager {

  // If user_stream is specified, the lifetime of the BitcompManager instance must
  // extend beyond that of the user_stream
  NVCOMP_EXPORT
  BitcompManager(
    size_t uncomp_chunk_size, const nvcompBatchedBitcompOpts_t& format_opts,
    cudaStream_t user_stream = 0, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  // This signature is deprecated, in favour of the one that does not accept a
  // device_id, and instead gets the device from the stream.
  NVCOMP_EXPORT
  [[deprecated]] BitcompManager(
    size_t uncomp_chunk_size, const nvcompBatchedBitcompOpts_t& format_opts,
    cudaStream_t user_stream, const int device_id, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  NVCOMP_EXPORT
  ~BitcompManager();
};

} // namespace nvcomp
