/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/// Get the order of reps (tiles of this layout that tile the whole tensor). The fastest-changing axis first
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getRepOrder() const {
      return getImpl()->getRepOrder(getImpl(), *this);
  }
/// Get the shape of the CTAs per CGA.
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getCTAsPerCGA() const {
      return getImpl()->getCTAsPerCGA(getImpl(), *this);
  }
/// Get the order of the CTAs per CGA. The fastest-changing axis first
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getCTAOrder() const {
      return getImpl()->getCTAOrder(getImpl(), *this);
  }
/// Get the shape of the warps per CTA.
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getWarpsPerCTA() const {
      return getImpl()->getWarpsPerCTA(getImpl(), *this);
  }
/// Get the order of the warps per CTA. The fastest-changing axis first
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getWarpOrder() const {
      return getImpl()->getWarpOrder(getImpl(), *this);
  }
/// Get the shape of the threads per warp
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getThreadsPerWarp() const {
      return getImpl()->getThreadsPerWarp(getImpl(), *this);
  }
/// Get the order of the threads per warp. The fastest-changing axis first
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getThreadOrder() const {
      return getImpl()->getThreadOrder(getImpl(), *this);
  }
/// Get the shape of the values per thread.
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getSizePerThread() const {
      return getImpl()->getSizePerThread(getImpl(), *this);
  }
/// Each CTA processes 1/CTASplitNum of the tensor.
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getCTASplitNum() const {
      return getImpl()->getCTASplitNum(getImpl(), *this);
  }
/// Gets the number of contiguous elements per thread.
SmallVector<unsigned> mlir::triton::gpu::DistributedEncodingTrait::getContigPerThread() const {
      return getImpl()->getContigPerThread(getImpl(), *this);
  }
/// Convert to LinearLayout.
LinearLayout mlir::triton::gpu::DistributedEncodingTrait::toLinearLayout(ArrayRef<int64_t> shape) const {
      return getImpl()->toLinearLayout(getImpl(), *this, shape);
  }
/// Return whether the layout support reduction op.
bool mlir::triton::gpu::MmaEncodingTrait::supportReduction() const {
      return getImpl()->supportReduction(getImpl(), *this);
  }
/// Return size per thread for dot operands.
SmallVector<unsigned> mlir::triton::gpu::MmaEncodingTrait::getSizePerThreadForOperand(int opIdx, int kWidth) const {
      return getImpl()->getSizePerThreadForOperand(getImpl(), *this, opIdx, kWidth);
  }
/// Return the number of threads per warp for dot operands.
SmallVector<unsigned> mlir::triton::gpu::MmaEncodingTrait::getThreadsPerWarpForOperand(int opIdx) const {
      return getImpl()->getThreadsPerWarpForOperand(getImpl(), *this, opIdx);
  }
/// Get the order of reps (tiles of this layout that tile the whole tensor). The fastest-changing axis first
SmallVector<unsigned> mlir::triton::gpu::MmaEncodingTrait::getRepOrderForOperand(int opIdx) const {
      return getImpl()->getRepOrderForOperand(getImpl(), *this, opIdx);
  }
/// Return total element size per thread.
unsigned mlir::triton::gpu::TritonGPU_AttrTrait::getTotalElemsPerThread(ArrayRef<int64_t> tensorShape, Type eltTy) const {
      return getImpl()->getTotalElemsPerThread(getImpl(), *this, tensorShape, eltTy);
  }
/// Return element size per thread in each dimension.
SmallVector<unsigned> mlir::triton::gpu::TritonGPU_AttrTrait::getElemsPerThread(ArrayRef<int64_t> tensorShape, Type eltTy) const {
      return getImpl()->getElemsPerThread(getImpl(), *this, tensorShape, eltTy);
  }
