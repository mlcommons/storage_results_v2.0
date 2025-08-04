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
#include "nvcomp/ans.h"

namespace nvcomp {

/**
 * @brief Format specification for ANS compression
 */
struct ANSFormatSpecHeader {
  // Empty for now
};

/**
 * @brief High-level interface class for ANS compressor
 */
struct ANSManager : PimplManager {

  NVCOMP_EXPORT
  ANSManager(
    size_t uncomp_chunk_size, const nvcompBatchedANSOpts_t& format_opts,
    cudaStream_t user_stream = 0, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  // This signature is deprecated, in favour of the one that does not accept a
  // device_id, and instead gets the device from the stream.
  NVCOMP_EXPORT
  [[deprecated]] ANSManager(
    size_t uncomp_chunk_size, const nvcompBatchedANSOpts_t& format_opts,
    cudaStream_t user_stream, const int device_id, ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  NVCOMP_EXPORT
  ~ANSManager();
};

} // namespace nvcomp
