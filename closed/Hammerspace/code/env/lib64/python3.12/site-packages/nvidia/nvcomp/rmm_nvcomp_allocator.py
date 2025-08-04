# SPDX-FileCopyrightText: Copyright (c) 2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# SPDX-License-Identifier: LicenseRef-NvidiaProprietary
#
# NVIDIA CORPORATION, its affiliates and licensors retain all intellectual
# property and proprietary rights in and to this material, related
# documentation and any modifications thereto. Any use, reproduction,
# disclosure or distribution of this material and related documentation
# without an express license agreement from NVIDIA CORPORATION or
# its affiliates is strictly prohibited.

"""Custom allocator implementation for using RMM memory resources with nvcomp.

It is legal to import this module without RMM installed. However, using
rmm_nvcomp_allocator will raise an error at runtime in that case.
Due to implementation constraints, the same is true for cupy, which is also
a runtime dependency of rmm_nvcomp_allocator."""

from . import CudaStream
from .external_memory import ExternalMemory

try:
    import rmm
    from rmm._cuda.stream import Stream as RmmStream
except ImportError:
    rmm = None

try:
    import cupy
    from cupy.cuda.stream import ExternalStream as CupyExternalStream
except ImportError:
    cupy = None

def rmm_nvcomp_allocator(nbytes: int, cuda_stream: CudaStream):
    """
    An nvcomp allocator that makes use of RMM.

    Usage
    --------
    >>> from nvidia.nvcomp.rmm_nvcomp_allocator import rmm_nvcomp_allocator
    >>> nvcomp.set_device_allocator(rmm_nvcomp_allocator)
    """
    if rmm is None:
        raise ModuleNotFoundError("No module named 'rmm' found.")
    if cupy is None:
        raise ModuleNotFoundError("No module named 'cupy' found.")
    
    # RMM allocations are performed through rmm.DeviceBuffer instantiations.
    # These take an RMM-defined CUDA stream wrapper. Unfortunately, this wrapper
    # is not directly constructible from a portable representation of a CUDA
    # stream, such as a cudaStream_t pointer viewed as an integer. The shortest
    # path to creating the RMM stream wrapper from the latter is by first
    # constructing a cupy ExternalStream from it and then wrapping this.
    # Unfortunately, this requires that cupy be installed. Hopefully, a solution
    # with fewer dependencies will be possible in the future.

    cupy_stream = CupyExternalStream(cuda_stream.ptr, cuda_stream.device)
    rmm_stream = RmmStream(obj=cupy_stream)
    buf = rmm.DeviceBuffer(size=nbytes, stream=rmm_stream)
    return ExternalMemory(buf, cuda_stream)
