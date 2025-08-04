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
#include "nvcomp/deflate.h"

namespace nvcomp {

/**
 * @brief Format specification for Deflate compression
 */
struct DeflateFormatSpecHeader {
/**
 * Compression algorithm to use. Permitted values are:
 * - 0: highest-throughput, entropy-only compression (use for symmetric compression/decompression performance)
 * - 1: high-throughput, low compression ratio (default)
 * - 2: medium-througput, medium compression ratio, beat Zlib level 1 on the compression ratio
 * - 3: placeholder for further compression level support, will fall into MEDIUM_COMPRESSION at this point
 * - 4: lower-throughput, higher compression ratio, beat Zlib level 6 on the compression ratio
 * - 5: lowest-throughput, highest compression ratio
 */
    int algo;
};

/**
 * @brief High-level interface class for Deflate compressor
 */
struct DeflateManager : PimplManager {

  // If user_stream is specified, the lifetime of the DeflateManager instance must
  // extend beyond that of the user_stream
  NVCOMP_EXPORT
  DeflateManager(
    size_t uncomp_chunk_size, const nvcompBatchedDeflateOpts_t& format_opts,
    cudaStream_t user_stream = 0, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  // This signature is deprecated, in favour of the one that does not accept a
  // device_id, and instead gets the device from the stream.
  NVCOMP_EXPORT
  [[deprecated]] DeflateManager(
    size_t uncomp_chunk_size, const nvcompBatchedDeflateOpts_t& format_opts,
    cudaStream_t user_stream, const int device_id, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  NVCOMP_EXPORT
  ~DeflateManager();
};

} // namespace nvcomp
