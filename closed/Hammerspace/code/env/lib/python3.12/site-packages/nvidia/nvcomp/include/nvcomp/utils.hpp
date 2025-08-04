/*
 * SPDX-FileCopyrightText: Copyright (c) 2018-2024 NVIDIA CORPORATION & AFFILIATES.
 * All rights reserved. SPDX-License-Identifier: LicenseRef-NvidiaProprietary
 *
 * NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
 * property and proprietary rights in and to this material, related
 * documentation and any modifications thereto. Any use, reproduction,
 * disclosure or distribution of this material and related documentation
 * without an express license agreement from NVIDIA CORPORATION or
 * its affiliates is strictly prohibited.
*/

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#pragma once

#include <cassert>
#include <limits>
#include <type_traits>
#include "nvcomp.h"

namespace nvcomp {

template <typename U, typename T>
constexpr NVCOMP_HOST_DEVICE_FUNCTION U roundUpDiv(U const num, T const chunk)
{
  return (num + chunk - 1) / chunk;
}

template <typename U, typename T>
constexpr NVCOMP_HOST_DEVICE_FUNCTION U roundDownTo(U const num, T const chunk)
{
  return (num / chunk) * chunk;
}

template <typename U, typename T>
constexpr NVCOMP_HOST_DEVICE_FUNCTION U roundUpTo(U const num, T const chunk)
{
  return roundUpDiv(num, chunk) * chunk;
}

template<typename T>
constexpr NVCOMP_HOST_DEVICE_FUNCTION T roundUpPow2(const T x)
{
  size_t res = 1;
  while(res < x) {
    res *= 2;
  }
  return res;
}

/**
 * @brief Calculate the first aligned location after `ptr`.
 *
 * @tparam T Type such that the alignment requirement is satisfied.
 * @param ptr Input pointer.
 * @return The first pointer after `ptr` that satisfy the alignment requirement.
 */
template <typename T>
constexpr NVCOMP_HOST_DEVICE_FUNCTION T* roundUpToAlignment(void* ptr)
{
  return reinterpret_cast<T*>(
      roundUpTo(reinterpret_cast<uintptr_t>(ptr), sizeof(T)));
}

template <typename T>
constexpr NVCOMP_HOST_DEVICE_FUNCTION const T* roundUpToAlignment(const void* ptr)
{
  return reinterpret_cast<const T*>(
      roundUpTo(reinterpret_cast<uintptr_t>(ptr), sizeof(T)));
}


template <typename OutputT, typename InputT>
constexpr NVCOMP_HOST_DEVICE_FUNCTION bool is_cast_valid(const InputT i)
{
  static_assert(
      std::numeric_limits<OutputT>::is_integer && std::numeric_limits<InputT>::is_integer,
      "Types for is_cast_valid must both be integers");
  if (std::is_unsigned<InputT>::value) {
      // The minimum bound is always satisfied, so just check the maximum bound.
      // Use larger type, breaking tie with InputT, which is already known unsigned.
      using largerT = typename std::conditional<(sizeof(OutputT) > sizeof(InputT)), OutputT, InputT>::type;
      return static_cast<largerT>(i) <= static_cast<largerT>((std::numeric_limits<OutputT>::max)());
  }

  // At this point, InputT is signed, but because this code will still be compiled
  // for unsigned InputT, force InputT to be signed, to avoid warnings about signed
  // vs. unsigned comparison.
  using signedInputT = typename std::make_signed<InputT>::type;
  using signedOutputT = typename std::make_signed<OutputT>::type;

  // Check whether the input is less than the minimum value of OutputT.
  // I.e. a negative signed integer is casting to an unsigned
  // Note, if OutputT is unsigned, the minimum is zero, which is safe to cast to
  // a signed type.
  if (static_cast<signedInputT>(i)
      < static_cast<signedOutputT>((std::numeric_limits<OutputT>::min)())) {
    return false;
  }

  // Because we've already checked whether the inputT is "too negative", if it's
  // negative at all this is valid
  // InputT is signed and larger than the minimum value of OutputT.
  if (static_cast<signedInputT>(i) <= static_cast<signedInputT>(0)) {
    return true;
  }

  // InputT is signed, but larger than zero, so can be cast to unsigned.
  using unsignedInputT = typename std::make_unsigned<InputT>::type;
  using unsignedOutputT = typename std::make_unsigned<OutputT>::type;

  return static_cast<unsignedInputT>(i)
         <= static_cast<unsignedOutputT>((std::numeric_limits<OutputT>::max)());
}

/**
 * @brief Cast to int, with debug-only range check, for CUDA kernel launch grid
 * or block dimensions
 */
template <typename S>
constexpr unsigned int cuda_dim_cast(const S i)
{
  static_assert(
      std::numeric_limits<S>::is_integer,
      "Type for cuda_dim_cast must be integer");

  assert(is_cast_valid<unsigned int>(i));

  return static_cast<unsigned int>(i);
}

}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
