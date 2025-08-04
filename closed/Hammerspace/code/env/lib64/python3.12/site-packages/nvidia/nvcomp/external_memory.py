# SPDX-FileCopyrightText: Copyright (c) 2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# SPDX-License-Identifier: LicenseRef-NvidiaProprietary
#
# NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
# property and proprietary rights in and to this material, related
# documentation and any modifications thereto. Any use, reproduction,
# disclosure or distribution of this material and related documentation
# without an express license agreement from NVIDIA CORPORATION or
# its affiliates is strictly prohibited.

class ExternalMemory:
    def __init__(self, mem_handle, stream_handle = None):
        self.__mem_handle = mem_handle
        self.__stream_handle = stream_handle
    
    @property
    def ptr(self):
        return self.__mem_handle.ptr
    
    def __del__(self):
        # Make sure self.__stream_handle's reference count is decreased after
        # that of self.__mem_handle.
        del self.__mem_handle
        del self.__stream_handle
