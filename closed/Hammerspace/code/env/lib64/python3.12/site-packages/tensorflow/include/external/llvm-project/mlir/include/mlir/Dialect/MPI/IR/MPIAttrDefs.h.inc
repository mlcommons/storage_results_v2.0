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
namespace mpi {
class MPI_ErrorClassEnumAttr;
class MPI_OpClassEnumAttr;
namespace detail {
struct MPI_ErrorClassEnumAttrStorage;
} // namespace detail
class MPI_ErrorClassEnumAttr : public ::mlir::Attribute::AttrBase<MPI_ErrorClassEnumAttr, ::mlir::Attribute, detail::MPI_ErrorClassEnumAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mpi.errclass";
  static constexpr ::llvm::StringLiteral dialectName = "mpi";
  static MPI_ErrorClassEnumAttr get(::mlir::MLIRContext *context, ::mlir::mpi::MPI_ErrorClassEnum value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"errclass"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::mpi::MPI_ErrorClassEnum getValue() const;
};
namespace detail {
struct MPI_OpClassEnumAttrStorage;
} // namespace detail
class MPI_OpClassEnumAttr : public ::mlir::Attribute::AttrBase<MPI_OpClassEnumAttr, ::mlir::Attribute, detail::MPI_OpClassEnumAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mpi.opclass";
  static constexpr ::llvm::StringLiteral dialectName = "mpi";
  static MPI_OpClassEnumAttr get(::mlir::MLIRContext *context, ::mlir::mpi::MPI_OpClassEnum value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"opclass"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::mpi::MPI_OpClassEnum getValue() const;
};
} // namespace mpi
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mpi::MPI_ErrorClassEnumAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mpi::MPI_OpClassEnumAttr)

#endif  // GET_ATTRDEF_CLASSES

