/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::emitc::ArrayType,
::mlir::emitc::LValueType,
::mlir::emitc::OpaqueType,
::mlir::emitc::PointerType,
::mlir::emitc::SignedSizeTType,
::mlir::emitc::PtrDiffTType,
::mlir::emitc::SizeTType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::emitc::ArrayType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::ArrayType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::emitc::LValueType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::LValueType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::emitc::OpaqueType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::OpaqueType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::emitc::PointerType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::PointerType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::emitc::SignedSizeTType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::SignedSizeTType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::emitc::PtrDiffTType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::PtrDiffTType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Case(::mlir::emitc::SizeTType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::emitc::SizeTType::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::emitc::ArrayType>([&](auto t) {
      printer << ::mlir::emitc::ArrayType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::emitc::LValueType>([&](auto t) {
      printer << ::mlir::emitc::LValueType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::emitc::OpaqueType>([&](auto t) {
      printer << ::mlir::emitc::OpaqueType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::emitc::PointerType>([&](auto t) {
      printer << ::mlir::emitc::PointerType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::emitc::SignedSizeTType>([&](auto t) {
      printer << ::mlir::emitc::SignedSizeTType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::emitc::PtrDiffTType>([&](auto t) {
      printer << ::mlir::emitc::PtrDiffTType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::emitc::SizeTType>([&](auto t) {
      printer << ::mlir::emitc::SizeTType::getMnemonic();
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace emitc {
namespace detail {
struct ArrayTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<int64_t>, Type>;
  ArrayTypeStorage(::llvm::ArrayRef<int64_t> shape, Type elementType) : shape(std::move(shape)), elementType(std::move(elementType)) {}

  KeyTy getAsKey() const {
    return KeyTy(shape, elementType);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (shape == std::get<0>(tblgenKey)) && (elementType == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static ArrayTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto shape = std::move(std::get<0>(tblgenKey));
    auto elementType = std::move(std::get<1>(tblgenKey));
    shape = allocator.copyInto(shape);
    return new (allocator.allocate<ArrayTypeStorage>()) ArrayTypeStorage(std::move(shape), std::move(elementType));
  }

  ::llvm::ArrayRef<int64_t> shape;
  Type elementType;
};
} // namespace detail
ArrayType ArrayType::get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType) {
  return Base::get(context, std::move(shape), std::move(elementType));
}

ArrayType ArrayType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType) {
  return Base::getChecked(emitError, context, shape, elementType);
}

ArrayType ArrayType::get(ArrayRef<int64_t> shape, Type elementType) {
  return Base::get(elementType.getContext(), shape, elementType);
}

ArrayType ArrayType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ArrayRef<int64_t> shape, Type elementType) {
  return Base::getChecked(emitError, elementType.getContext(), shape, elementType);
}

::llvm::LogicalResult ArrayType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, Type elementType) {
  if (::mlir::failed(verify(emitError, shape, elementType)))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::ArrayRef<int64_t> ArrayType::getShape() const {
  return getImpl()->shape;
}

Type ArrayType::getElementType() const {
  return getImpl()->elementType;
}

} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::ArrayType)
namespace mlir {
namespace emitc {
namespace detail {
struct LValueTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<Type>;
  LValueTypeStorage(Type valueType) : valueType(std::move(valueType)) {}

  KeyTy getAsKey() const {
    return KeyTy(valueType);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (valueType == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static LValueTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto valueType = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<LValueTypeStorage>()) LValueTypeStorage(std::move(valueType));
  }

  Type valueType;
};
} // namespace detail
LValueType LValueType::get(::mlir::MLIRContext *context, Type valueType) {
  return Base::get(context, std::move(valueType));
}

LValueType LValueType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, Type valueType) {
  return Base::getChecked(emitError, context, valueType);
}

LValueType LValueType::get(Type valueType) {
  return Base::get(valueType.getContext(), valueType);
}

LValueType LValueType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, Type valueType) {
  return Base::getChecked(emitError, valueType.getContext(), valueType);
}

::llvm::LogicalResult LValueType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, Type valueType) {
  if (::mlir::failed(verify(emitError, valueType)))
    return ::mlir::failure();
  return ::mlir::success();
}

::mlir::Type LValueType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<Type> _result_valueType;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'valueType'
  _result_valueType = ::mlir::FieldParser<Type>::parse(odsParser);
  if (::mlir::failed(_result_valueType)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse EmitC_LValueType parameter 'valueType' which is to be a `Type`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_valueType));
  return odsParser.getChecked<LValueType>(odsLoc, odsParser.getContext(),
      Type((*_result_valueType)));
}

void LValueType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << getValueType();
  odsPrinter << ">";
}

Type LValueType::getValueType() const {
  return getImpl()->valueType;
}

} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::LValueType)
namespace mlir {
namespace emitc {
namespace detail {
struct OpaqueTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::llvm::StringRef>;
  OpaqueTypeStorage(::llvm::StringRef value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static OpaqueTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    value = allocator.copyInto(value);
    return new (allocator.allocate<OpaqueTypeStorage>()) OpaqueTypeStorage(std::move(value));
  }

  ::llvm::StringRef value;
};
} // namespace detail
OpaqueType OpaqueType::get(::mlir::MLIRContext *context, ::llvm::StringRef value) {
  return Base::get(context, std::move(value));
}

OpaqueType OpaqueType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::StringRef value) {
  return Base::getChecked(emitError, context, value);
}

::llvm::LogicalResult OpaqueType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::StringRef value) {
  if (::mlir::failed(verify(emitError, value)))
    return ::mlir::failure();
  return ::mlir::success();
}

::mlir::Type OpaqueType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<std::string> _result_value;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'value'
  _result_value = ::mlir::FieldParser<std::string>::parse(odsParser);
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse EmitC_OpaqueType parameter 'value' which is to be a `::llvm::StringRef`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_value));
  return odsParser.getChecked<OpaqueType>(odsLoc, odsParser.getContext(),
      ::llvm::StringRef((*_result_value)));
}

void OpaqueType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printString(getValue());;
  odsPrinter << ">";
}

::llvm::StringRef OpaqueType::getValue() const {
  return getImpl()->value;
}

} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::OpaqueType)
namespace mlir {
namespace emitc {
namespace detail {
struct PointerTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<Type>;
  PointerTypeStorage(Type pointee) : pointee(std::move(pointee)) {}

  KeyTy getAsKey() const {
    return KeyTy(pointee);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (pointee == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static PointerTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto pointee = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<PointerTypeStorage>()) PointerTypeStorage(std::move(pointee));
  }

  Type pointee;
};
} // namespace detail
PointerType PointerType::get(::mlir::MLIRContext *context, Type pointee) {
  return Base::get(context, std::move(pointee));
}

PointerType PointerType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, Type pointee) {
  return Base::getChecked(emitError, context, pointee);
}

PointerType PointerType::get(Type pointee) {
  return Base::get(pointee.getContext(), pointee);
}

PointerType PointerType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, Type pointee) {
  return Base::getChecked(emitError, pointee.getContext(), pointee);
}

::llvm::LogicalResult PointerType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, Type pointee) {
  if (::mlir::failed(verify(emitError, pointee)))
    return ::mlir::failure();
  return ::mlir::success();
}

::mlir::Type PointerType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<Type> _result_pointee;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'pointee'
  _result_pointee = ::mlir::FieldParser<Type>::parse(odsParser);
  if (::mlir::failed(_result_pointee)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse EmitC_PointerType parameter 'pointee' which is to be a `Type`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_pointee));
  return odsParser.getChecked<PointerType>(odsLoc, odsParser.getContext(),
      Type((*_result_pointee)));
}

void PointerType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << getPointee();
  odsPrinter << ">";
}

Type PointerType::getPointee() const {
  return getImpl()->pointee;
}

} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::PointerType)
namespace mlir {
namespace emitc {
} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::SignedSizeTType)
namespace mlir {
namespace emitc {
} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::PtrDiffTType)
namespace mlir {
namespace emitc {
} // namespace emitc
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::emitc::SizeTType)
namespace mlir {
namespace emitc {

/// Parse a type registered to this dialect.
::mlir::Type EmitCDialect::parseType(::mlir::DialectAsmParser &parser) const {
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
void EmitCDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace emitc
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

