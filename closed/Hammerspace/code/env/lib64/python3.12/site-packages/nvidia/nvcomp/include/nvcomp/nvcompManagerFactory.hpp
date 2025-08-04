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

#include "nvcompManager.hpp"
#include "ans.hpp"
#include "gdeflate.hpp"
#include "lz4.hpp"
#include "snappy.hpp"
#include "bitcomp.hpp"
#include "cascaded.hpp"
#include "zstd.hpp"
#include "deflate.hpp"
#include "gzip.hpp"

#include <cassert>
#include <stdint.h>

namespace nvcomp {

/**
 * @brief Construct a ManagerBase from a buffer
 *
 * This synchronizes the stream
 */
NVCOMP_EXPORT
std::shared_ptr<nvcompManagerBase> create_manager(
    const uint8_t* comp_buffer, cudaStream_t stream = 0,
    ChecksumPolicy checksum_policy = NoComputeNoVerify);

/**
 * @brief Construct a ManagerBase from a buffer
 *
 * @deprecated
 * This signature is deprecated, in favour of the one that does not accept a
 * device_id, and instead gets the device from the stream.
 */
NVCOMP_EXPORT
[[deprecated]] std::shared_ptr<nvcompManagerBase> create_manager(
    const uint8_t* comp_buffer, cudaStream_t stream,
    const int device_id, ChecksumPolicy checksum_policy=NoComputeNoVerify);

} // namespace nvcomp
