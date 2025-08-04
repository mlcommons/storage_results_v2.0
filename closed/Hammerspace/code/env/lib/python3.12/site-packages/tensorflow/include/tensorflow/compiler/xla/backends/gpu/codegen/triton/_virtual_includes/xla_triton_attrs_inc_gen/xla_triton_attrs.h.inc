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
namespace xla {
class SparseDotMetaEncodingAttr;
namespace detail {
struct SparseDotMetaEncodingAttrStorage;
} // namespace detail
class SparseDotMetaEncodingAttr : public ::mlir::Attribute::AttrBase<SparseDotMetaEncodingAttr, ::mlir::Attribute, detail::SparseDotMetaEncodingAttrStorage, ::mlir::triton::gpu::TritonGPU_AttrTrait::Trait, ::mlir::triton::gpu::DistributedEncodingTrait::Trait> {
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
    return getSizePerThread();
  };
  static constexpr ::llvm::StringLiteral name = "triton.gpu.sparse_dot_meta_encoding";
  static constexpr ::llvm::StringLiteral dialectName = "triton_xla";
  static SparseDotMetaEncodingAttr get(::mlir::MLIRContext *context, Attribute parent);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"sparse_dot_meta"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  Attribute getParent() const;
};
} // namespace xla
} // namespace triton
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::xla::SparseDotMetaEncodingAttr)

#endif  // GET_ATTRDEF_CLASSES

