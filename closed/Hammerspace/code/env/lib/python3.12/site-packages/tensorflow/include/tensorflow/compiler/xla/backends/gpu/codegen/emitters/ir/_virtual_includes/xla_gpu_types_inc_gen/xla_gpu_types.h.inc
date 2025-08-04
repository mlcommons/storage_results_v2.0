/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace xla {
namespace gpu {
class IndexedVectorType;
namespace detail {
struct IndexedVectorTypeStorage;
} // namespace detail
class IndexedVectorType : public ::mlir::Type::TypeBase<IndexedVectorType, ::mlir::Type, detail::IndexedVectorTypeStorage, ::mlir::ShapedType::Trait, ::mlir::ValueSemantics> {
public:
  using Base::Base;
  IndexedVectorType cloneWith(std::optional<llvm::ArrayRef<int64_t>> shape,
                              mlir::Type elementType) const {
      return IndexedVectorType::get(getContext(), shape.value_or(getShape()),
                                    elementType, getIndexingMapAttr());
  }

  bool hasRank() const { return true; }
  static constexpr ::llvm::StringLiteral name = "xla_gpu.indexed_vector";
  static constexpr ::llvm::StringLiteral dialectName = "xla_gpu";
  using Base::getChecked;
  static IndexedVectorType get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, ::xla::IndexingMapAttr indexing_map_attr);
  static IndexedVectorType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, ::xla::IndexingMapAttr indexing_map_attr);
  static ::llvm::LogicalResult verifyInvariantsImpl(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, ::xla::IndexingMapAttr indexing_map_attr);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, ::xla::IndexingMapAttr indexing_map_attr);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"indexed_vector"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getShape() const;
  mlir::Type getElementType() const;
  ::xla::IndexingMapAttr getIndexingMapAttr() const;
};
} // namespace gpu
} // namespace xla
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::gpu::IndexedVectorType)

#endif  // GET_TYPEDEF_CLASSES

