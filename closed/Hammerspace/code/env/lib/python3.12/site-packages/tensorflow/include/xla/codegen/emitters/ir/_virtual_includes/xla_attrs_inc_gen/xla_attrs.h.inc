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
namespace xla {
class IndexingMapAttr;
class BackendKindAttr;
namespace detail {
struct IndexingMapAttrStorage;
} // namespace detail
class IndexingMapAttr : public ::mlir::Attribute::AttrBase<IndexingMapAttr, ::mlir::Attribute, detail::IndexingMapAttrStorage> {
public:
  using Base::Base;
  // Returns the indexing map constructed from IndexingMapAttr.
  xla::IndexingMap getIndexingMap() const;

  // Returns the number of indexing map results.
  int64_t getNumResults() const;
  static constexpr ::llvm::StringLiteral name = "xla.indexing_map";
  static constexpr ::llvm::StringLiteral dialectName = "xla";
  using Base::getChecked;
  static IndexingMapAttr get(::mlir::MLIRContext *context, ::mlir::AffineMap map, ::llvm::ArrayRef<::xla::IndexingMap::Variable> dim_vars, ::llvm::ArrayRef<::xla::IndexingMap::Variable> range_vars, ::llvm::ArrayRef<::std::pair<::mlir::AffineExpr, ::xla::Interval>> constraints);
  static IndexingMapAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::mlir::AffineMap map, ::llvm::ArrayRef<::xla::IndexingMap::Variable> dim_vars, ::llvm::ArrayRef<::xla::IndexingMap::Variable> range_vars, ::llvm::ArrayRef<::std::pair<::mlir::AffineExpr, ::xla::Interval>> constraints);
  static IndexingMapAttr get(::mlir::MLIRContext *context, const ::xla::IndexingMap&indexing_map);
  static IndexingMapAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, const ::xla::IndexingMap&indexing_map);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::AffineMap map, ::llvm::ArrayRef<::xla::IndexingMap::Variable> dim_vars, ::llvm::ArrayRef<::xla::IndexingMap::Variable> range_vars, ::llvm::ArrayRef<::std::pair<::mlir::AffineExpr, ::xla::Interval>> constraints);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::AffineMap map, ::llvm::ArrayRef<::xla::IndexingMap::Variable> dim_vars, ::llvm::ArrayRef<::xla::IndexingMap::Variable> range_vars, ::llvm::ArrayRef<::std::pair<::mlir::AffineExpr, ::xla::Interval>> constraints);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"indexing_map"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::AffineMap getMap() const;
  ::llvm::ArrayRef<::xla::IndexingMap::Variable> getDimVars() const;
  ::llvm::ArrayRef<::xla::IndexingMap::Variable> getRangeVars() const;
  ::llvm::ArrayRef<::std::pair<::mlir::AffineExpr, ::xla::Interval>> getConstraints() const;
};
namespace detail {
struct BackendKindAttrStorage;
} // namespace detail
class BackendKindAttr : public ::mlir::Attribute::AttrBase<BackendKindAttr, ::mlir::Attribute, detail::BackendKindAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xla.backend_kind";
  static constexpr ::llvm::StringLiteral dialectName = "xla";
  static BackendKindAttr get(::mlir::MLIRContext *context, ::xla::BackendKind value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"backend_kind"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::xla::BackendKind getValue() const;
};
} // namespace xla
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::IndexingMapAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::BackendKindAttr)

#endif  // GET_ATTRDEF_CLASSES

