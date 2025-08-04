/*
 * SPDX-FileCopyrightText: Copyright (c) 2024 NVIDIA CORPORATION & AFFILIATES.
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

#include <stdint.h>
#include "../../operators.hpp"
#include "../../backend_common.hpp"

namespace nvcomp::device {
namespace detail {

namespace cg = cooperative_groups;

template <>
class ShmemSizeBlock<nvcomp_algo::ans, nvcomp_direction::decompress>
{
public:
  static __host__ __device__ constexpr size_t execute(int warps_per_block)
  {
    constexpr size_t SHMEM_PER_WARP = 2050;
    return SHMEM_PER_WARP * warps_per_block;
  }
};

template <>
class ShmemSizeGroup<nvcomp_algo::ans, nvcomp_direction::decompress>
{
public:
  static __host__ __device__ constexpr size_t execute()
  {
    constexpr size_t SHMEM_PER_WARP = 2050;
    return SHMEM_PER_WARP;
  }
};

template <>
class ShmemAlignment<nvcomp_grouptype::warp, nvcomp_algo::ans, nvcomp_direction::decompress>
{
public:
  static __host__ __device__ size_t constexpr execute()
  {
    constexpr size_t SHMEM_ALIGNMENT = 4;
    return SHMEM_ALIGNMENT;
  }
};

template <>
class TmpSizeTotal<nvcomp_grouptype::warp, nvcomp_algo::ans, nvcomp_direction::decompress>
{
public:
  static constexpr size_t execute(size_t max_uncomp_chunk_size)
  {
    return 0;
  }
};

template <>
class TmpSizeGroup<nvcomp_grouptype::warp, nvcomp_algo::ans, nvcomp_direction::decompress>
{
public:
  static __host__ __device__ size_t constexpr execute(size_t max_uncomp_chunk_size)
  {
    return 0;
  }
};

#define gen_decompress(data_type)   \
  template<>                        \
  class Decompress<                 \
    WarpGroup,                      \
    data_type,                      \
    nvcomp_algo::ans> {             \
  public:                           \
    __device__ void execute(        \
      const void *comp_chunk,       \
      void *uncomp_chunk,           \
      uint8_t *shared_buffer,       \
      uint8_t* tmp_buf,             \
      WarpGroup& group);            \
                                    \
    __device__ void execute(        \
      const void *comp_chunk,       \
      void *uncomp_chunk,           \
      size_t uncomp_chunk_size,     \
      size_t comp_chunk_size,       \
      uint8_t *shared_buffer,       \
      uint8_t* tmp_buf,             \
      WarpGroup& group);            \
  }

gen_decompress(nvcomp_datatype::uint8);
gen_decompress(nvcomp_datatype::float16);

}
}

#endif