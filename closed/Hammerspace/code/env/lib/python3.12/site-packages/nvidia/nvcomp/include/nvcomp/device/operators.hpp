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

#pragma once

#include <cuda/std/type_traits>
#include <stdint.h>

namespace nvcomp::device {
namespace detail {

enum class nvcomp_operator
{
  /// Selects between compression/decompression.
  direction,

  /// Selects the compression algorithm.
  algo,

  /// Selects threads group type to work on.
  grouptype,

  /// The format of the input data.
  datatype,

  /// The maximum uncompressed chunk size. (For compression only).
  max_uncomp_chunk_size
};

} // namespace detail

/**
 * @enum nvcomp_direction
 *
 * @brief Selection of compression or decompression.
 */
enum class nvcomp_direction
{
  compress,
  decompress
};

/**
 * @enum nvcomp_algo
 *
 * @brief The compression algorithm to be selected.
 */
enum class nvcomp_algo
{
  ans,
  zstd,
  bitcomp,
  lz4,
  deflate,
  gdeflate
};

/**
 * @enum nvcomp_datatype
 *
 * @brief The way in which the compression algo will interpret the input data.
 */
enum class nvcomp_datatype
{
  /// Data to be interpreted as consecutive bytes. If the input datatype is not included
  /// in the options below, uint8 should be selected.
  uint8,

  /// Data to be interpreted as consecutive IEEE half-precision floats.
  /// Requires the total number of input bytes per chunk to be divisible by two.
  float16,

  /// Data to be interpreted as consecutive bfloat16 values. Requires
  /// the total number of input bytes per chunk to be divisible by two.
  bfloat16
};

/**
 * @enum nvcomp_grouptype
 *
 * @brief Threads group type to work on.
 */
enum class nvcomp_grouptype
{
  /// Group provided to API expected to be single-warp-sized.
  warp
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace detail {

struct operator_expression
{
};

template <class ValueType, ValueType Value>
struct constant_operator_expression
    : operator_expression,
      public cuda::std::integral_constant<ValueType, Value>
{
};

} // namespace nvcomp::device::detail

template <nvcomp_algo Value>
struct Algo : public detail::constant_operator_expression<nvcomp_algo, Value>
{
};

template <nvcomp_direction Value>
struct Direction
    : public detail::constant_operator_expression<nvcomp_direction, Value>
{
};

template <nvcomp_datatype Value>
struct Datatype
    : public detail::constant_operator_expression<nvcomp_datatype, Value>
{
};

template <nvcomp_grouptype Value>
struct Grouptype
    : public detail::constant_operator_expression<nvcomp_grouptype, Value>
{
};

template <size_t Value>
struct MaxUncompChunkSize
    : public detail::constant_operator_expression<size_t, Value>
{
};

template <class T>
struct dependent_false : std::false_type
{
};

template <nvcomp_algo A>
struct dependent_false_algo : std::false_type
{
};

#endif // DOXYGEN_SHOULD_SKIP_THIS

} // namespace nvcomp::device
