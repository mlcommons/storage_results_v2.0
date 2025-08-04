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

#include "../../backend_common.hpp"
#include "../../operators.hpp"
#include "./lz4_types.hpp"

#include <type_traits>

namespace nvcomp {
namespace device {
namespace detail {

template <>
class Decompress<WarpGroup, nvcomp_datatype::uint8, nvcomp_algo::lz4> {
public:
  __device__ void execute(
      const void * const comp_chunk,
      void * const uncomp_chunk,
      const size_t comp_chunk_size,
      size_t * const decomp_chunk_size,
      uint8_t * const shared_buffer,
      uint8_t * const tmp_buffer,
      WarpGroup& warp);
};

template <>
class ShmemSizeGroup<nvcomp_algo::lz4, nvcomp_direction::decompress>
{
public:
  static constexpr size_t __host__ __device__ execute()
  {
    return sizeof(lz4::LZ4DecompressWarpMemory);
  }
};

template <>
class ShmemSizeBlock<nvcomp_algo::lz4, nvcomp_direction::decompress>
{
public:
  static constexpr size_t __device__ __host__ execute(int warps_per_block)
  {
    return warps_per_block * ShmemSizeGroup<nvcomp_algo::lz4, nvcomp_direction::decompress>::execute();
  }
};

template <nvcomp_grouptype G>
class ShmemAlignment<G, nvcomp_algo::lz4, nvcomp_direction::decompress>
{
public:
  static size_t constexpr __host__ __device__ execute()
  {
    return std::alignment_of<lz4::LZ4DecompressWarpMemory>::value;
  }
};

template <nvcomp_grouptype G>
class TmpSizeTotal<G, nvcomp_algo::lz4, nvcomp_direction::decompress>
{
public:
  static constexpr size_t __device__ __host__ execute(size_t max_uncomp_chunk_size)
  {
    return 0;
  }
};

template <nvcomp_grouptype G>
class TmpSizeGroup<G, nvcomp_algo::lz4, nvcomp_direction::decompress>
{
public:
  static constexpr size_t __device__ __host__ execute(size_t max_uncomp_chunk_size)
  {
    return 0;
  }
};

} // namespace detail
} // namespace device
} // namesapce nvcomp

#endif // DOXYGEN_SHOULD_SKIP_THIS