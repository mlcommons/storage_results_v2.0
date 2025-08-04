/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::xegpu::TensorDescType,
::mlir::xegpu::NbarrierType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::xegpu::TensorDescType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::TensorDescType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::xegpu::NbarrierType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::NbarrierType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::xegpu::TensorDescType>([&](auto t) {
      printer << ::mlir::xegpu::TensorDescType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::xegpu::NbarrierType>([&](auto t) {
      printer << ::mlir::xegpu::NbarrierType::getMnemonic();
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace xegpu {
namespace detail {
struct TensorDescTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<int64_t>, mlir::Type, mlir::Attribute, mlir::Attribute>;
  TensorDescTypeStorage(::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, mlir::Attribute encoding, mlir::Attribute sg_map) : shape(std::move(shape)), elementType(std::move(elementType)), encoding(std::move(encoding)), sg_map(std::move(sg_map)) {}

  KeyTy getAsKey() const {
    return KeyTy(shape, elementType, encoding, sg_map);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (shape == std::get<0>(tblgenKey)) && (elementType == std::get<1>(tblgenKey)) && (encoding == std::get<2>(tblgenKey)) && (sg_map == std::get<3>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey));
  }

  static TensorDescTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto shape = std::move(std::get<0>(tblgenKey));
    auto elementType = std::move(std::get<1>(tblgenKey));
    auto encoding = std::move(std::get<2>(tblgenKey));
    auto sg_map = std::move(std::get<3>(tblgenKey));
    shape = allocator.copyInto(shape);
    return new (allocator.allocate<TensorDescTypeStorage>()) TensorDescTypeStorage(std::move(shape), std::move(elementType), std::move(encoding), std::move(sg_map));
  }

  ::llvm::ArrayRef<int64_t> shape;
  mlir::Type elementType;
  mlir::Attribute encoding;
  mlir::Attribute sg_map;
};
} // namespace detail
TensorDescType TensorDescType::get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, mlir::Attribute encoding, mlir::Attribute sg_map) {
  return Base::get(context, std::move(shape), std::move(elementType), std::move(encoding), std::move(sg_map));
}

::llvm::ArrayRef<int64_t> TensorDescType::getShape() const {
  return getImpl()->shape;
}

mlir::Type TensorDescType::getElementType() const {
  return getImpl()->elementType;
}

mlir::Attribute TensorDescType::getEncoding() const {
  return getImpl()->encoding;
}

mlir::Attribute TensorDescType::getSgMap() const {
  return getImpl()->sg_map;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::TensorDescType)
namespace mlir {
namespace xegpu {
} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::NbarrierType)
namespace mlir {
namespace xegpu {

/// Parse a type registered to this dialect.
::mlir::Type XeGPUDialect::parseType(::mlir::DialectAsmParser &parser) const {
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
void XeGPUDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace xegpu
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

