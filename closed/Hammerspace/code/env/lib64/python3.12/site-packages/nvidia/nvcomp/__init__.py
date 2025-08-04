# SPDX-FileCopyrightText: Copyright (c) 2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# SPDX-License-Identifier: LicenseRef-NvidiaProprietary
#
# NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
# property and proprietary rights in and to this material, related
# documentation and any modifications thereto. Any use, reproduction,
# disclosure or distribution of this material and related documentation
# without an express license agreement from NVIDIA CORPORATION or
# its affiliates is strictly prohibited.

# we need to have that defined and accessible before any other nvcomp import

from nvidia.nvcomp.nvcomp_impl import *

__version__ = nvcomp_impl.__version__
__cuda_version__ = nvcomp_impl.__cuda_version__
__doc__ =  nvcomp_impl.__doc__
__git_sha__ = ''
