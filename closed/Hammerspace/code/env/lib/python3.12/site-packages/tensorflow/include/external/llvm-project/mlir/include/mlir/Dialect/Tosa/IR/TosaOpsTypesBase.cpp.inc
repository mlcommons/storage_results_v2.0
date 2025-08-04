/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

mlir::tosa::shapeType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(mlir::tosa::shapeType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = mlir::tosa::shapeType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<mlir::tosa::shapeType>([&](auto t) {
      printer << mlir::tosa::shapeType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace tosa {
namespace detail {
struct shapeTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<int>;
  shapeTypeStorage(int rank) : rank(std::move(rank)) {}

  KeyTy getAsKey() const {
    return KeyTy(rank);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (rank == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static shapeTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto rank = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<shapeTypeStorage>()) shapeTypeStorage(std::move(rank));
  }

  int rank;
};
} // namespace detail
shapeType shapeType::get(::mlir::MLIRContext *context, int rank) {
  return Base::get(context, std::move(rank));
}

shapeType shapeType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, int rank) {
  return Base::getChecked(emitError, context, rank);
}

::llvm::LogicalResult shapeType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, int rank) {
  if (::mlir::failed(verify(emitError, rank)))
    return ::mlir::failure();
  return ::mlir::success();
}

::mlir::Type shapeType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<int> _result_rank;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'rank'
  _result_rank = ::mlir::FieldParser<int>::parse(odsParser);
  if (::mlir::failed(_result_rank)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse Tosa_Shape parameter 'rank' which is to be a `int`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_rank));
  return odsParser.getChecked<shapeType>(odsLoc, odsParser.getContext(),
      int((*_result_rank)));
}

void shapeType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getRank());
  odsPrinter << ">";
}

int shapeType::getRank() const {
  return getImpl()->rank;
}

} // namespace tosa
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(mlir::tosa::shapeType)
namespace mlir {
namespace tosa {

/// Parse a type registered to this dialect.
::mlir::Type TosaDialect::parseType(::mlir::DialectAsmParser &parser) const {
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
void TosaDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace tosa
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

