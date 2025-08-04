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
namespace mlir {
namespace tosa {
class shapeType;
namespace detail {
struct shapeTypeStorage;
} // namespace detail
class shapeType : public ::mlir::Type::TypeBase<shapeType, ::mlir::Type, detail::shapeTypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "tosa.shape";
  static constexpr ::llvm::StringLiteral dialectName = "tosa";
  using Base::getChecked;
  static shapeType get(::mlir::MLIRContext *context, int rank);
  static shapeType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, int rank);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, int rank);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, int rank);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"shape"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  int getRank() const;
};
} // namespace tosa
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(mlir::tosa::shapeType)

#endif  // GET_TYPEDEF_CLASSES

