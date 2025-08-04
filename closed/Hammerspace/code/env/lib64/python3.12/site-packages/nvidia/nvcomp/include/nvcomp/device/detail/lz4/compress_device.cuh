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

namespace nvcomp {
namespace device {
namespace detail {

template <>
class Compress<WarpGroup, nvcomp_datatype::uint8, nvcomp_algo::lz4> {
public:
  __device__ void execute(
    const void * const uncomp_chunk,
    void * const comp_chunk,
    const size_t uncomp_chunk_size,
    size_t * const comp_chunk_size,
    uint8_t * const /* shared_buffer */,
    uint8_t * const tmp_buffer,
    const size_t max_uncomp_chunk_size,
    WarpGroup& warp);
};

template <>
class ShmemSizeBlock<nvcomp_algo::lz4, nvcomp_direction::compress>
{
public:
  static constexpr __device__ __host__ size_t execute(const int /* warps_per_block */)
  {
    return 0;
  }
};

template <>
class ShmemSizeGroup<nvcomp_algo::lz4, nvcomp_direction::compress>
{
public:
  static constexpr __host__ __device__ size_t execute()
  {
    return 0;
  }
};

template <nvcomp_grouptype G>
class ShmemAlignment<G, nvcomp_algo::lz4, nvcomp_direction::compress>
{
public:
  static size_t constexpr __host__ __device__ execute()
  {
    return 0;
  }
};

template <nvcomp_grouptype G>
class TmpSizeGroup<G, nvcomp_algo::lz4, nvcomp_direction::compress>
{
public:
  static constexpr __host__ __device__ size_t execute(
      const size_t max_uncomp_chunk_size,
      const nvcomp_datatype /* dt */)
  {
    return sizeof(lz4::offset_type)*lz4::getHashTableSize(max_uncomp_chunk_size);
  }
};


template <nvcomp_grouptype G>
class TmpSizeTotal<G, nvcomp_algo::lz4, nvcomp_direction::compress>
{
public:
  static constexpr __device__ __host__ size_t execute(
    const size_t max_uncomp_chunk_size,
    const nvcomp_datatype dt,
    const size_t num_warps)
  {
    const size_t tmp_size_per_warp = TmpSizeGroup<G, nvcomp_algo::lz4, nvcomp_direction::compress>().execute(max_uncomp_chunk_size, dt);
    return num_warps * tmp_size_per_warp;
  }
};

template <>
class MaxCompChunkSize<nvcomp_algo::lz4>
{
public:
  static constexpr __host__ __device__ size_t execute(size_t max_uncomp_chunk_size)
  {
    using namespace nvcomp;
    const size_t expansion = max_uncomp_chunk_size + 1 + roundUpDiv(
        max_uncomp_chunk_size, 255);
    return roundUpTo(expansion, sizeof(size_t));
  }
};

} // namespace detail
} // namespace device
} // namespace nvcomp

#endif // DOXYGEN_SHOULD_SKIP_THIS