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
namespace mpi {
class RetvalType;
class RequestType;
class StatusType;
class RetvalType : public ::mlir::Type::TypeBase<RetvalType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mpi.retval";
  static constexpr ::llvm::StringLiteral dialectName = "mpi";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"retval"};
  }

};
class RequestType : public ::mlir::Type::TypeBase<RequestType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mpi.request";
  static constexpr ::llvm::StringLiteral dialectName = "mpi";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"request"};
  }

};
class StatusType : public ::mlir::Type::TypeBase<StatusType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mpi.status";
  static constexpr ::llvm::StringLiteral dialectName = "mpi";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"status"};
  }

};
} // namespace mpi
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mpi::RetvalType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mpi::RequestType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mpi::StatusType)

#endif  // GET_TYPEDEF_CLASSES

