/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::triton::gpu::AsyncTokenType,
::mlir::triton::gpu::MemDescType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::triton::gpu::AsyncTokenType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::AsyncTokenType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::MemDescType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::MemDescType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::triton::gpu::AsyncTokenType>([&](auto t) {
      printer << ::mlir::triton::gpu::AsyncTokenType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::MemDescType>([&](auto t) {
      printer << ::mlir::triton::gpu::MemDescType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace triton {
namespace gpu {
} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::AsyncTokenType)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct MemDescTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<int64_t>, Type, Attribute, Attribute, bool, ::llvm::ArrayRef<int64_t>>;
  MemDescTypeStorage(::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape) : shape(std::move(shape)), elementType(std::move(elementType)), encoding(std::move(encoding)), memorySpace(std::move(memorySpace)), mutableMemory(std::move(mutableMemory)), allocShape(std::move(allocShape)) {}

  KeyTy getAsKey() const {
    return KeyTy(shape, elementType, encoding, memorySpace, mutableMemory, allocShape);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (shape == std::get<0>(tblgenKey)) && (elementType == std::get<1>(tblgenKey)) && (encoding == std::get<2>(tblgenKey)) && (memorySpace == std::get<3>(tblgenKey)) && (mutableMemory == std::get<4>(tblgenKey)) && (allocShape == std::get<5>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey), std::get<5>(tblgenKey));
  }

  static MemDescTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto shape = std::move(std::get<0>(tblgenKey));
    auto elementType = std::move(std::get<1>(tblgenKey));
    auto encoding = std::move(std::get<2>(tblgenKey));
    auto memorySpace = std::move(std::get<3>(tblgenKey));
    auto mutableMemory = std::move(std::get<4>(tblgenKey));
    auto allocShape = std::move(std::get<5>(tblgenKey));
    shape = allocator.copyInto(shape);
    allocShape = allocator.copyInto(allocShape);
    return new (allocator.allocate<MemDescTypeStorage>()) MemDescTypeStorage(std::move(shape), std::move(elementType), std::move(encoding), std::move(memorySpace), std::move(mutableMemory), std::move(allocShape));
  }

  ::llvm::ArrayRef<int64_t> shape;
  Type elementType;
  Attribute encoding;
  Attribute memorySpace;
  bool mutableMemory;
  ::llvm::ArrayRef<int64_t> allocShape;
};
} // namespace detail
MemDescType MemDescType::get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape) {
  return Base::get(context, std::move(shape), std::move(elementType), std::move(encoding), std::move(memorySpace), std::move(mutableMemory), std::move(allocShape));
}

MemDescType MemDescType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape) {
  return Base::getChecked(emitError, context, shape, elementType, encoding, memorySpace, mutableMemory, allocShape);
}

MemDescType MemDescType::get(llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace) {
  return Base::get(elementType.getContext(), shape, elementType, encoding, memorySpace, /*mutableMemory=*/false, /*allocShape=*/shape);
}

MemDescType MemDescType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace) {
  return Base::getChecked(emitError, elementType.getContext(), shape, elementType, encoding, memorySpace, /*mutableMemory=*/false, /*allocShape=*/shape);
}

MemDescType MemDescType::get(llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory) {
  return Base::get(elementType.getContext(), shape, elementType, encoding, memorySpace, mutableMemory, /*allocShape=*/shape);
}

MemDescType MemDescType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory) {
  return Base::getChecked(emitError, elementType.getContext(), shape, elementType, encoding, memorySpace, mutableMemory, /*allocShape=*/shape);
}

MemDescType MemDescType::get(llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, llvm::ArrayRef<int64_t> allocShape) {
  return Base::get(elementType.getContext(), shape, elementType, encoding, memorySpace, mutableMemory, allocShape);
}

MemDescType MemDescType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, llvm::ArrayRef<int64_t> allocShape) {
  return Base::getChecked(emitError, elementType.getContext(), shape, elementType, encoding, memorySpace, mutableMemory, allocShape);
}

::llvm::LogicalResult MemDescType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape) {
  if (::mlir::failed(verify(emitError, shape, elementType, encoding, memorySpace, mutableMemory, allocShape)))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::ArrayRef<int64_t> MemDescType::getShape() const {
  return getImpl()->shape;
}

Type MemDescType::getElementType() const {
  return getImpl()->elementType;
}

Attribute MemDescType::getEncoding() const {
  return getImpl()->encoding;
}

Attribute MemDescType::getMemorySpace() const {
  return getImpl()->memorySpace;
}

bool MemDescType::getMutableMemory() const {
  return getImpl()->mutableMemory;
}

::llvm::ArrayRef<int64_t> MemDescType::getAllocShape() const {
  return getImpl()->allocShape;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::MemDescType)
namespace mlir {
namespace triton {
namespace gpu {

/// Parse a type registered to this dialect.
::mlir::Type TritonGPUDialect::parseType(::mlir::DialectAsmParser &parser) const {
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
void TritonGPUDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace gpu
} // namespace triton
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

