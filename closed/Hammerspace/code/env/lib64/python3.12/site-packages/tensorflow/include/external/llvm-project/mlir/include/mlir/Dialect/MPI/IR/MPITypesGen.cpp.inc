/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::mpi::RetvalType,
::mlir::mpi::RequestType,
::mlir::mpi::StatusType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::mpi::RetvalType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mpi::RetvalType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::mpi::RequestType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mpi::RequestType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::mpi::StatusType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mpi::StatusType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::mpi::RetvalType>([&](auto t) {
      printer << ::mlir::mpi::RetvalType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::mpi::RequestType>([&](auto t) {
      printer << ::mlir::mpi::RequestType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::mpi::StatusType>([&](auto t) {
      printer << ::mlir::mpi::StatusType::getMnemonic();
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace mpi {
} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::RetvalType)
namespace mlir {
namespace mpi {
} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::RequestType)
namespace mlir {
namespace mpi {
} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::StatusType)
namespace mlir {
namespace mpi {

/// Parse a type registered to this dialect.
::mlir::Type MPIDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void MPIDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace mpi
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

