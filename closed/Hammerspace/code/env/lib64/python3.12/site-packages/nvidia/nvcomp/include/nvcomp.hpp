/*
 * SPDX-FileCopyrightText: Copyright (c) 2020-2024 NVIDIA CORPORATION & AFFILIATES.
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

#include "nvcomp.h"

#include <cstdint>
#include <cuda_runtime.h>
#include <stdexcept>
#include <string>

namespace nvcomp
{

/******************************************************************************
 * CLASSES ********************************************************************
 *****************************************************************************/

/**
 * @brief The top-level exception throw by nvcomp C++ methods.
 */
class NVCompException : public std::runtime_error
{
public:
  /**
   * @brief Create a new NVCompException.
   *
   * @param[in] err The error associated with the exception.
   * @param[in] msg The error message.
   */
  NVCompException(nvcompStatus_t err, const std::string& msg) :
      std::runtime_error(msg + " : code=" + std::to_string(err) + "."),
      m_err(err)
  {
    // do nothing
  }

  nvcompStatus_t get_error() const
  {
    return m_err;
  }

private:
  nvcompStatus_t m_err;
};



/******************************************************************************
 * INLINE DEFINITIONS AND HELPER FUNCTIONS ************************************
 *****************************************************************************/

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename T>
__device__ __host__ constexpr nvcompType_t TypeOfConst()
{
  // This is as a single statement so that it can be constexpr in C++11 code.
  return std::is_same<T, int8_t>::value ?
    NVCOMP_TYPE_CHAR : (
  std::is_same<T, uint8_t>::value ?
    NVCOMP_TYPE_UCHAR : (
  std::is_same<T, int16_t>::value ?
    NVCOMP_TYPE_SHORT : (
  std::is_same<T, uint16_t>::value ?
    NVCOMP_TYPE_USHORT : (
  std::is_same<T, int32_t>::value ?
    NVCOMP_TYPE_INT : (
  std::is_same<T, uint32_t>::value ?
    NVCOMP_TYPE_UINT : (
  std::is_same<T, int64_t>::value ?
    NVCOMP_TYPE_LONGLONG : (
  std::is_same<T, uint64_t>::value ?
    NVCOMP_TYPE_ULONGLONG : (
    NVCOMP_TYPE_BITS
  ))))))));
}

template <typename T>
inline nvcompType_t TypeOf()
{
  auto type = TypeOfConst<T>();
  if (type != NVCOMP_TYPE_BITS) {
    return type;
  }
  throw NVCompException(
      nvcompErrorNotSupported, "nvcomp does not support the given type.");
}

#endif // DOXYGEN_SHOULD_SKIP_THIS

} // namespace nvcomp
