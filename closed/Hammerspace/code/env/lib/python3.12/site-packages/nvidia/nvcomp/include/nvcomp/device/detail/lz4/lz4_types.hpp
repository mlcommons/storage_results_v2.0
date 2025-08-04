/*
 * SPDX-FileCopyrightText: Copyright (c) 2023-2024 NVIDIA CORPORATION & AFFILIATES.
 * All rights reserved. SPDX-License-Identifier: LicenseRef-NvidiaProprietary
 *
 * NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
 * property and proprietary rights in and to this material, related
 * documentation and any modifications thereto. Any use, reproduction,
 * disclosure or distribution of this material and related documentation
 * without an express license agreement from NVIDIA CORPORATION or
 * its affiliates is strictly prohibited.
*/

/*
 * DISCLAIMER: Device APIs are experimental and might be subject
 * to change in the next nvComp releases.
*/

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#pragma once

#include "../../../utils.hpp"

#include <cstdint>
#include <array>

namespace nvcomp {
namespace device {
namespace detail {
namespace lz4 {

// This restricts us to 4GB chunk sizes (total buffer can be up to
// max(size_t)). We actually artificially restrict it to much less, to
// limit what we have to test, as well as to encourage users to exploit some
// parallelism.
using position_type = uint32_t;

// Limits lookback to 64 KB
using offset_type = uint16_t;

struct sequence
{
  uint32_t distance;
  uint32_t match_length;
  uint32_t literal_length;
};

static constexpr uint32_t WARP_SIZE_U = 32;

using LZ4DecompressBuffer = std::array<uint8_t, WARP_SIZE_U*sizeof(uint64_t)>;

struct LZ4DecompressWarpMemory
{
  // hack to expose buffer size since size() is not a static member of array
  static constexpr auto BUFFER_SIZE = std::tuple_size<LZ4DecompressBuffer>::value;

  alignas(8) LZ4DecompressBuffer buffer;
  sequence sequences[WARP_SIZE_U];
  unsigned int ix_literal[WARP_SIZE_U];
  int ix_output[WARP_SIZE_U];
};


/**
 * @brief Get the size of the hash table needed for the given maximum chunk
 * size.
 *
 * @param[in] max_uncomp_chunk_size The maximum chunk size to process.
 *
 * @return The number of elements/slots required in the hashtable.
 */
constexpr NVCOMP_HOST_DEVICE_FUNCTION size_t getHashTableSize(
    const size_t max_uncomp_chunk_size)
{
  constexpr const position_type MAX_HASH_TABLE_SIZE = 1U << 14;

  using namespace nvcomp;
  // when chunk size is smaller than the max hashtable size round the
  // hashtable size up to the nearest power of 2 of the chunk size.
  // The lower load factor from a significantly larger hashtable size compared
  // to the chunk size doesn't increase performance, however having a smaller
  // hashtable which yields much high cache utilization does.
  return std::min(roundUpPow2(max_uncomp_chunk_size),
      static_cast<size_t>(MAX_HASH_TABLE_SIZE));
}


} // namespace lz4
} // namespace detail
} // namespace device
} // namespace nvcomp

#endif // DOXYGEN_SHOULD_SKIP_THIS