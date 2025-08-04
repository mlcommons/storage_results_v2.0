/*
 * SPDX-FileCopyrightText: Copyright (c) 2022-2024 NVIDIA CORPORATION & AFFILIATES.
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
#include <memory>

#include "nvcompManager.hpp"
#include "nvcomp/lz4.h"

namespace nvcomp {

struct LZ4FormatSpecHeader {
  nvcompType_t data_type;
};

/**
 * @brief High-level interface class for LZ4 compressor
 *
 * @note Any uncompressed data buffer to be compressed MUST be a size that is a
 * multiple of the data type size, else compression may crash or result in
 * invalid output.
 */
struct LZ4Manager : PimplManager {

  // If user_stream is specified, the lifetime of the LZ4Manager must
  // extend beyond that of the user_stream
  NVCOMP_EXPORT
  LZ4Manager(
    size_t uncomp_chunk_size, const nvcompBatchedLZ4Opts_t& format_opts = nvcompBatchedLZ4DefaultOpts,
    cudaStream_t user_stream = 0, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  // This signature is deprecated, in favour of the one that does not accept a
  // device_id, and instead gets the device from the stream.
  NVCOMP_EXPORT
  [[deprecated]] LZ4Manager(
    size_t uncomp_chunk_size, const nvcompBatchedLZ4Opts_t& format_opts,
    cudaStream_t user_stream, const int device_id, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  NVCOMP_EXPORT
  ~LZ4Manager();
};

} // namespace nvcomp
