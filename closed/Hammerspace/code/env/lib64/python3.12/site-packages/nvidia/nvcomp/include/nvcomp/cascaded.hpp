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
#include "nvcomp/cascaded.h"
#include "nvcompManager.hpp"

namespace nvcomp {

/**
 * @brief Format specification for Cascased compression
 */
struct CascadedFormatSpecHeader {
  nvcompBatchedCascadedOpts_t options;
};

/**
 * @brief High-level interface class for Cascaded compressor
 *
 * @note Any uncompressed data buffer to be compressed MUST be a size that is a
 * multiple of the data type size, else compression may crash or result in
 * invalid output.
 */
struct CascadedManager : PimplManager {

  // If user_stream is specified, the lifetime of the CascadedManager instance must
  // extend beyond that of the user_stream
  NVCOMP_EXPORT
  CascadedManager(
      size_t uncomp_chunk_size,
      const nvcompBatchedCascadedOpts_t& options = nvcompBatchedCascadedDefaultOpts,
      cudaStream_t user_stream = 0,
      ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  // This signature is deprecated, in favour of the one that does not accept a
  // device_id, and instead gets the device from the stream.
  NVCOMP_EXPORT
  [[deprecated]] CascadedManager(
      size_t uncomp_chunk_size,
      const nvcompBatchedCascadedOpts_t& options,
      cudaStream_t user_stream,
      int device_id,
      ChecksumPolicy checksum_policy = NoComputeNoVerify,
    BitstreamKind bitstream_kind = BitstreamKind::NVCOMP_NATIVE);

  NVCOMP_EXPORT
  virtual ~CascadedManager();
};

} // namespace nvcomp
