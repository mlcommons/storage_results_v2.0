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

#include "operators.hpp"
#include <cooperative_groups.h>

namespace nvcomp::device {
namespace detail {

template <nvcomp_algo A, nvcomp_direction D>
class ShmemSizeBlock;

template <nvcomp_algo A, nvcomp_direction D>
class ShmemSizeGroup;

template <nvcomp_grouptype G, nvcomp_algo A, nvcomp_direction D>
class TmpSizeTotal;

template <nvcomp_grouptype G, nvcomp_algo A, nvcomp_direction D>
class TmpSizeGroup;

template <nvcomp_grouptype G, nvcomp_algo A, nvcomp_direction D>
class ShmemAlignment;

template <nvcomp_algo A>
class MaxCompChunkSize;

template <typename CG, nvcomp_datatype DT, nvcomp_algo A>
class Compress;

template <typename CG, nvcomp_datatype DT, nvcomp_algo A>
class Decompress;

typedef cooperative_groups::__v1::thread_block_tile<32U, cooperative_groups::__v1::thread_block> WarpGroup;

} // namespace detail
} // namespace nvcomp::device

#endif // DOXYGEN_SHOULD_SKIP_THIS