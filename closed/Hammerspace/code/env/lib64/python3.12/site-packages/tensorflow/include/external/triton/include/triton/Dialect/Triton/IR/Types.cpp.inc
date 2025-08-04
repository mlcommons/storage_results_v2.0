/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::triton::PointerType,
::mlir::triton::TensorDescType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::triton::PointerType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::PointerType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::TensorDescType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::TensorDescType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::triton::PointerType>([&](auto t) {
      printer << ::mlir::triton::PointerType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::TensorDescType>([&](auto t) {
      printer << ::mlir::triton::TensorDescType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace triton {
namespace detail {
struct PointerTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<Type, int>;
  PointerTypeStorage(Type pointeeType, int addressSpace) : pointeeType(std::move(pointeeType)), addressSpace(std::move(addressSpace)) {}

  KeyTy getAsKey() const {
    return KeyTy(pointeeType, addressSpace);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (pointeeType == std::get<0>(tblgenKey)) && (addressSpace == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static PointerTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto pointeeType = std::move(std::get<0>(tblgenKey));
    auto addressSpace = std::move(std::get<1>(tblgenKey));
    return new (allocator.allocate<PointerTypeStorage>()) PointerTypeStorage(std::move(pointeeType), std::move(addressSpace));
  }

  Type pointeeType;
  int addressSpace;
};
} // namespace detail
PointerType PointerType::get(Type pointeeType, int addressSpace) {
  return Base::get(pointeeType.getContext(), pointeeType, addressSpace);
}

Type PointerType::getPointeeType() const {
  return getImpl()->pointeeType;
}

int PointerType::getAddressSpace() const {
  return getImpl()->addressSpace;
}

} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::PointerType)
namespace mlir {
namespace triton {
namespace detail {
struct TensorDescTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<RankedTensorType>;
  TensorDescTypeStorage(RankedTensorType blockType) : blockType(std::move(blockType)) {}

  KeyTy getAsKey() const {
    return KeyTy(blockType);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (blockType == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static TensorDescTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto blockType = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<TensorDescTypeStorage>()) TensorDescTypeStorage(std::move(blockType));
  }

  RankedTensorType blockType;
};
} // namespace detail
TensorDescType TensorDescType::get(::mlir::MLIRContext *context, RankedTensorType blockType) {
  return Base::get(context, std::move(blockType));
}

::mlir::Type TensorDescType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<RankedTensorType> _result_blockType;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'blockType'
  _result_blockType = ::mlir::FieldParser<RankedTensorType>::parse(odsParser);
  if (::mlir::failed(_result_blockType)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse TT_TensorDescType parameter 'blockType' which is to be a `RankedTensorType`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_blockType));
  return TensorDescType::get(odsParser.getContext(),
      RankedTensorType((*_result_blockType)));
}

void TensorDescType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getBlockType());
  odsPrinter << ">";
}

RankedTensorType TensorDescType::getBlockType() const {
  return getImpl()->blockType;
}

} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::TensorDescType)
namespace mlir {
namespace triton {

/// Parse a type registered to this dialect.
::mlir::Type TritonDialect::parseType(::mlir::DialectAsmParser &parser) const {
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
void TritonDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace triton
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

