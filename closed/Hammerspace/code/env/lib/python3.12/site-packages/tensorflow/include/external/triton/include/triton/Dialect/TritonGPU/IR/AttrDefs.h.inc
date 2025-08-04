/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace triton {
namespace gpu {
class CTALayoutAttr;
class SharedEncodingAttr;
class LinearEncodingAttr;
class BlockedEncodingAttr;
class AMDMfmaEncodingAttr;
class AMDWmmaEncodingAttr;
class NvidiaMmaEncodingAttr;
class SliceEncodingAttr;
class DotOperandEncodingAttr;
class SharedMemorySpaceAttr;
namespace detail {
struct CTALayoutAttrStorage;
} // namespace detail
class CTALayoutAttr : public ::mlir::Attribute::AttrBase<CTALayoutAttr, ::mlir::Attribute, detail::CTALayoutAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait> {
public:
  using Base::Base;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const {
    llvm::report_fatal_error(
      "Unsupported getElemsPerThread in CTALayoutAttr.");
  }
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const {
    llvm::report_fatal_error(
      "Unsupported getTotalElemsPerThread in CTALayoutAttr.");
  }

  static CTALayoutAttr getDefault(MLIRContext *context, int rank) {
    SmallVector<unsigned> CTAsPerCGA(rank, 1);
    SmallVector<unsigned> CTASplitNum(rank, 1);
    SmallVector<unsigned> CTAOrder;
    for (int i = rank - 1; i >= 0; --i)
      CTAOrder.push_back(i);
    return get(context, CTAsPerCGA, CTASplitNum, CTAOrder);
  }
  static constexpr ::llvm::StringLiteral name = "triton.gpu.cta_layout";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static CTALayoutAttr get(::mlir::MLIRContext *context, ArrayRef<unsigned> CTAsPerCGA, ArrayRef<unsigned> CTASplitNum, ArrayRef<unsigned> CTAOrder);
  static CTALayoutAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ArrayRef<unsigned> CTAsPerCGA, ArrayRef<unsigned> CTASplitNum, ArrayRef<unsigned> CTAOrder);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<unsigned> CTAsPerCGA, ::llvm::ArrayRef<unsigned> CTASplitNum, ::llvm::ArrayRef<unsigned> CTAOrder);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<unsigned> CTAsPerCGA, ::llvm::ArrayRef<unsigned> CTASplitNum, ::llvm::ArrayRef<unsigned> CTAOrder);
  ::llvm::ArrayRef<unsigned> getCTAsPerCGA() const;
  ::llvm::ArrayRef<unsigned> getCTASplitNum() const;
  ::llvm::ArrayRef<unsigned> getCTAOrder() const;
};
namespace detail {
struct SharedEncodingAttrStorage;
} // namespace detail
class SharedEncodingAttr : public ::mlir::Attribute::AttrBase<SharedEncodingAttr, ::mlir::Attribute, detail::SharedEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  int32_t getAlignment() const;
  static constexpr ::llvm::StringLiteral name = "triton.gpu.shared_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  static SharedEncodingAttr get(::mlir::MLIRContext *context, unsigned vec, unsigned perPhase, unsigned maxPhase, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout, bool hasLeadingOffset);
  static SharedEncodingAttr get(::mlir::MLIRContext *context, unsigned vec, unsigned perPhase, unsigned maxPhase, ArrayRef<unsigned> order, CTALayoutAttr CTALayout);
  static SharedEncodingAttr get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, unsigned typeWidthInBit);
  static SharedEncodingAttr get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, unsigned typeWidthInBit, bool needTrans);
  static SharedEncodingAttr get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, Type eltTy);
  static SharedEncodingAttr get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, Type eltTy, bool needTrans);
  static SharedEncodingAttr get(::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, Type eltTy);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"shared"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getVec() const;
  unsigned getPerPhase() const;
  unsigned getMaxPhase() const;
  ::llvm::ArrayRef<unsigned> getOrder() const;
  CTALayoutAttr getCTALayout() const;
  bool getHasLeadingOffset() const;
};
namespace detail {
struct LinearEncodingAttrStorage;
} // namespace detail
class LinearEncodingAttr : public ::mlir::Attribute::AttrBase<LinearEncodingAttr, ::mlir::Attribute, detail::LinearEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  SmallVector<unsigned> getContigPerThread() const;
  SmallVector<unsigned> getOrder() const;

  // Generalizes get{Warp,Thread,CTA}Order to linear layouts.
  // Returns the order of the dimensions `dimName` of the layout.
  // If more than dimension is of size one, it uses defaultOrder to determine
  // the order of the dimensions of size one.
  SmallVector<unsigned> orderPerDim(StringAttr dimName,
                                    ArrayRef<unsigned> defaultOrder) const;

  // Generalizes getThreadsPerWarp, getWarpsPerCTA, getCTAsPerCGA to linear layouts.
  // Returns the bases of the dimensions `dimName` of the layout.
  // If skipBroadcast is false, we count a base zero
  SmallVector<unsigned> basesPerDim(StringAttr dimName,
                                    bool skipBroadcast = true) const;
  static constexpr ::llvm::StringLiteral name = "triton.gpu.linear_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static LinearEncodingAttr get(::mlir::MLIRContext *context, LinearLayout linearLayout);
  static LinearEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, LinearLayout linearLayout);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, LinearLayout linearLayout);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, LinearLayout linearLayout);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"linear"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  const LinearLayout &getLinearLayout() const;
};
namespace detail {
struct BlockedEncodingAttrStorage;
} // namespace detail
class BlockedEncodingAttr : public ::mlir::Attribute::AttrBase<BlockedEncodingAttr, ::mlir::Attribute, detail::BlockedEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  SmallVector<unsigned> getContigPerThread() {
    // Block encoding is dense stride layout. The elements per thread are contiguous.
    return getSizePerThread();
  };
  static constexpr ::llvm::StringLiteral name = "triton.gpu.blocked_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static BlockedEncodingAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout);
  static BlockedEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout);
  static BlockedEncodingAttr get(::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, CTALayoutAttr CTALayout);
  static BlockedEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, CTALayoutAttr CTALayout);
  static BlockedEncodingAttr get(::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, unsigned numCTAs);
  static BlockedEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, unsigned numCTAs);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"blocked"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<unsigned> getSizePerThread__() const;
  ::llvm::ArrayRef<unsigned> getThreadsPerWarp__() const;
  ::llvm::ArrayRef<unsigned> getWarpsPerCTA__() const;
  ::llvm::ArrayRef<unsigned> getOrder() const;
  CTALayoutAttr getCTALayout() const;
};
namespace detail {
struct AMDMfmaEncodingAttrStorage;
} // namespace detail
class AMDMfmaEncodingAttr : public ::mlir::Attribute::AttrBase<AMDMfmaEncodingAttr, ::mlir::Attribute, detail::AMDMfmaEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait, ::mlir::triton::gpu::MmaEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  bool supportReduction() const {
    return true;
  }
  SmallVector<unsigned> getSizePerThreadForOperand(int kWidth, int opIdx) const;
  unsigned getTotalElemsPerThreadForOperand(ArrayRef<int64_t> shape, Type eltTy, int kWidth, int opIdx) const;
  SmallVector<int64_t> getInstrShapeForOperand(int kWidth, int opIdx) const;
  SmallVector<int64_t> getRepForOperand(ArrayRef<int64_t> operandShape, int kWidth, int opIdx) const;
  SmallVector<unsigned> getRepOrderForOperand(int opIdx) const;
  SmallVector<unsigned> getThreadsPerWarpForOperand(int opIdx) const;

  SmallVector<unsigned> getContigPerThread() {
    auto rank = getWarpsPerCTA().size();
    SmallVector<unsigned> contigPerThread(rank, 1);
    if (getIsTransposed())
      contigPerThread[rank - 1] = 4;
    else
      contigPerThread[rank - 2] = 4;
    return contigPerThread;
  };

  static constexpr ::llvm::StringLiteral name = "triton.gpu.amd_mfma_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static AMDMfmaEncodingAttr get(::mlir::MLIRContext *context, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout);
  static AMDMfmaEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"amd_mfma"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getVersionMajor() const;
  unsigned getVersionMinor() const;
  ::llvm::ArrayRef<unsigned> getWarpsPerCTA__() const;
  unsigned getMDim() const;
  unsigned getNDim() const;
  bool getIsTransposed() const;
  CTALayoutAttr getCTALayout() const;
};
namespace detail {
struct AMDWmmaEncodingAttrStorage;
} // namespace detail
class AMDWmmaEncodingAttr : public ::mlir::Attribute::AttrBase<AMDWmmaEncodingAttr, ::mlir::Attribute, detail::AMDWmmaEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait, ::mlir::triton::gpu::MmaEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  bool supportReduction() const {
    return true;
  }
  SmallVector<unsigned> getSizePerThreadForOperand(int kWidth, int opIdx) const;
  unsigned getTotalElemsPerThreadForOperand(ArrayRef<int64_t> shape, Type eltTy, int kWidth, int opIdx) const;
  SmallVector<int64_t> getElemsPerInstrForOperands() const;
  SmallVector<int64_t> getRepForOperand(ArrayRef<int64_t> operandShape,
                                        Type elemType, int kWidth, int opIdx) const;
  SmallVector<unsigned> getRepOrderForOperand(int opIdx) const;
  SmallVector<unsigned> getThreadsPerWarpForOperand(int opIdx) const;
  static SmallVector<unsigned> getMNKDimPerInstr();

  SmallVector<unsigned> getContigPerThread() {
    auto rank = getWarpsPerCTA().size();
    assert(rank == 2 || rank == 3);
    SmallVector<unsigned> contigPerThread(rank, 1);
    if (getVersion() == 2) {
      contigPerThread[rank - 2] = 8;
    }
    return contigPerThread;
  };
  static constexpr ::llvm::StringLiteral name = "triton.gpu.amd_wmma_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static AMDWmmaEncodingAttr get(::mlir::MLIRContext *context, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout);
  static AMDWmmaEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"amd_wmma"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getVersion() const;
  bool getIsTransposed() const;
  ::llvm::ArrayRef<unsigned> getWarpsPerCTA__() const;
  CTALayoutAttr getCTALayout() const;
};
namespace detail {
struct NvidiaMmaEncodingAttrStorage;
} // namespace detail
class NvidiaMmaEncodingAttr : public ::mlir::Attribute::AttrBase<NvidiaMmaEncodingAttr, ::mlir::Attribute, detail::NvidiaMmaEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait, ::mlir::triton::gpu::MmaEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  bool isVolta() const;
  bool isTuring() const;
  bool isAmpere() const;
  bool isHopper() const;

  SmallVector<int64_t> getRepForOperand(ArrayRef<int64_t> shape,
                                        int bitwidth, int kWidth,
                                        int opIdx) const;
  SmallVector<unsigned> getRepOrderForOperand(int opIdx) const;
  SmallVector<unsigned> getThreadsPerWarpForOperand(int opIdx) const;

  bool supportReduction() const {
    if (isAmpere() || isHopper()) {
      return true;
    }
    return false;
  };
  SmallVector<unsigned> getSizePerThreadForOperand(int kWidth, int opIdx) const;

  SmallVector<unsigned> getContigPerThread() {
    assert(isAmpere() || isHopper());
    auto rank = getWarpsPerCTA().size();
    SmallVector<unsigned> contigPerThread(rank, 1);
    contigPerThread[rank - 1] = 2;
    return contigPerThread;
  };

  static constexpr ::llvm::StringLiteral name = "triton.gpu.nvidia_mma_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  static NvidiaMmaEncodingAttr get(::mlir::MLIRContext *context, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout, ::llvm::ArrayRef<unsigned> instrShape);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"nvidia_mma"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getVersionMajor() const;
  unsigned getVersionMinor() const;
  ::llvm::ArrayRef<unsigned> getWarpsPerCTA__() const;
  CTALayoutAttr getCTALayout() const;
  ::llvm::ArrayRef<unsigned> getInstrShape() const;
};
namespace detail {
struct SliceEncodingAttrStorage;
} // namespace detail
class SliceEncodingAttr : public ::mlir::Attribute::AttrBase<SliceEncodingAttr, ::mlir::Attribute, detail::SliceEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  template<class T>
  SmallVector<T> paddedShape(ArrayRef<T> shape) const;

  SmallVector<unsigned> getContigPerThread() {
    auto parentLayout = mlir::cast<DistributedEncodingTrait>(getParent());
    auto parentContigPerThread = parentLayout.getContigPerThread();
    parentContigPerThread.erase(parentContigPerThread.begin() + getDim());
    return parentContigPerThread;
  };
  static constexpr ::llvm::StringLiteral name = "triton.gpu.slice_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  static SliceEncodingAttr get(::mlir::MLIRContext *context, unsigned dim, Attribute parent);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"slice"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getDim() const;
  Attribute getParent() const;
};
namespace detail {
struct DotOperandEncodingAttrStorage;
} // namespace detail
class DotOperandEncodingAttr : public ::mlir::Attribute::AttrBase<DotOperandEncodingAttr, ::mlir::Attribute, detail::DotOperandEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait> {
public:
  using Base::Base;
  unsigned getTotalElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;
  SmallVector<unsigned> getElemsPerThread(ArrayRef<int64_t> shape, Type eltTy) const;

  SmallVector<unsigned> getRepOrder() const;
  SmallVector<unsigned> getCTAsPerCGA() const;
  SmallVector<unsigned> getCTAOrder() const;
  SmallVector<unsigned> getCTASplitNum() const;
  SmallVector<unsigned> getWarpsPerCTA() const;
  SmallVector<unsigned> getWarpOrder() const;
  SmallVector<unsigned> getThreadsPerWarp() const;
  SmallVector<unsigned> getThreadOrder() const;

  SmallVector<unsigned> getSizePerThread() const;

  LinearLayout toLinearLayout(ArrayRef<int64_t> shape) const;

  SmallVector<unsigned> getContigPerThread() {
    auto rank = getWarpsPerCTA().size();
    assert(rank == 2 || rank == 3);
    SmallVector<unsigned> contigPerThread(rank, 1);
    auto kWidth = getKWidth();
    assert(kWidth != 0 && "Do not support kWidth=0");
    if (getOpIdx() == 0)
      contigPerThread[rank - 1] = kWidth;
    else
      contigPerThread[rank - 2] = kWidth;
    return contigPerThread;
  };
  static constexpr ::llvm::StringLiteral name = "triton.gpu.dot_operand_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static DotOperandEncodingAttr get(::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, unsigned kWidth);
  static DotOperandEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, unsigned kWidth);
  static DotOperandEncodingAttr get(::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, Type eltTy);
  static DotOperandEncodingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, Type eltTy);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned opIdx, Attribute parent, unsigned kWidth);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned opIdx, Attribute parent, unsigned kWidth);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"dot_op"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getOpIdx() const;
  Attribute getParent() const;
  unsigned getKWidth() const;
};
class SharedMemorySpaceAttr : public ::mlir::Attribute::AttrBase<SharedMemorySpaceAttr, ::mlir::Attribute, ::mlir::AttributeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "ttg.shared_memory";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"shared_memory"};
  }

};
} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::CTALayoutAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::SharedEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::LinearEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::BlockedEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::AMDMfmaEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::AMDWmmaEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::NvidiaMmaEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::SliceEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::DotOperandEncodingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::SharedMemorySpaceAttr)

#endif  // GET_ATTRDEF_CLASSES

