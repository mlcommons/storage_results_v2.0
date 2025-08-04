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
namespace cpu {
class CallFrameType;
class ErrorType;
class CallFrameType : public ::mlir::Type::TypeBase<CallFrameType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xla_cpu.call_frame";
  static constexpr ::llvm::StringLiteral dialectName = "xla_cpu";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"call_frame"};
  }

};
class ErrorType : public ::mlir::Type::TypeBase<ErrorType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xla_cpu.error";
  static constexpr ::llvm::StringLiteral dialectName = "xla_cpu";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"error"};
  }

};
} // namespace cpu
} // namespace xla
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::cpu::CallFrameType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::cpu::ErrorType)

#endif  // GET_TYPEDEF_CLASSES

