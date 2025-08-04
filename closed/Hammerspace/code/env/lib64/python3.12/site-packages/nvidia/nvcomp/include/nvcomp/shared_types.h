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

#include <stddef.h>

typedef enum nvcompStatus_t
{
  nvcompSuccess = 0,
  nvcompErrorInvalidValue = 10,
  nvcompErrorNotSupported = 11,
  nvcompErrorCannotDecompress = 12,
  nvcompErrorBadChecksum = 13,
  nvcompErrorCannotVerifyChecksums = 14,
  nvcompErrorOutputBufferTooSmall = 15,
  nvcompErrorWrongHeaderLength = 16,
  nvcompErrorAlignment = 17,
  nvcompErrorChunkSizeTooLarge = 18,
  nvcompErrorCudaError = 1000,
  nvcompErrorInternal = 10000,
} nvcompStatus_t;

/**
 * @brief Per-algorithm buffer alignment requirements.
 */
typedef struct
{
    /// Minimum alignment requirement of each input buffer.
    size_t input;
    /// Minimum alignment requirement of each output buffer.
    size_t output;
    /// Minimum alignment requirement of temporary-storage buffer, if any. For
    /// algorithms that do not use temporary storage, this field is always equal
    /// to 1.
    size_t temp;
} nvcompAlignmentRequirements_t;
