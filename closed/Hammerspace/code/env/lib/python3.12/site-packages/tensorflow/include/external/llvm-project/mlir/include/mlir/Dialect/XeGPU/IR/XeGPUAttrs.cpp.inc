/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mlir::xegpu::BlockTensorDescAttr,
::mlir::xegpu::ScatterTensorDescAttr,
::mlir::xegpu::MemorySpaceAttr,
::mlir::xegpu::CachePolicyAttr,
::mlir::xegpu::FenceScopeAttr,
::mlir::xegpu::SGMapAttr

#endif  // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::xegpu::BlockTensorDescAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::BlockTensorDescAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::xegpu::ScatterTensorDescAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::ScatterTensorDescAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::xegpu::MemorySpaceAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::MemorySpaceAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::xegpu::CachePolicyAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::CachePolicyAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::xegpu::FenceScopeAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::FenceScopeAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::xegpu::SGMapAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::xegpu::SGMapAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::llvm::LogicalResult>(def)    .Case<::mlir::xegpu::BlockTensorDescAttr>([&](auto t) {
      printer << ::mlir::xegpu::BlockTensorDescAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::xegpu::ScatterTensorDescAttr>([&](auto t) {
      printer << ::mlir::xegpu::ScatterTensorDescAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::xegpu::MemorySpaceAttr>([&](auto t) {
      printer << ::mlir::xegpu::MemorySpaceAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::xegpu::CachePolicyAttr>([&](auto t) {
      printer << ::mlir::xegpu::CachePolicyAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::xegpu::FenceScopeAttr>([&](auto t) {
      printer << ::mlir::xegpu::FenceScopeAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::xegpu::SGMapAttr>([&](auto t) {
      printer << ::mlir::xegpu::SGMapAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace xegpu {
namespace detail {
struct BlockTensorDescAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<MemorySpaceAttr, IntegerAttr, BoolAttr>;
  BlockTensorDescAttrStorage(MemorySpaceAttr memory_space, IntegerAttr array_length, BoolAttr boundary_check) : memory_space(std::move(memory_space)), array_length(std::move(array_length)), boundary_check(std::move(boundary_check)) {}

  KeyTy getAsKey() const {
    return KeyTy(memory_space, array_length, boundary_check);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (memory_space == std::get<0>(tblgenKey)) && (array_length == std::get<1>(tblgenKey)) && (boundary_check == std::get<2>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey));
  }

  static BlockTensorDescAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto memory_space = std::move(std::get<0>(tblgenKey));
    auto array_length = std::move(std::get<1>(tblgenKey));
    auto boundary_check = std::move(std::get<2>(tblgenKey));
    return new (allocator.allocate<BlockTensorDescAttrStorage>()) BlockTensorDescAttrStorage(std::move(memory_space), std::move(array_length), std::move(boundary_check));
  }

  MemorySpaceAttr memory_space;
  IntegerAttr array_length;
  BoolAttr boundary_check;
};
} // namespace detail
BlockTensorDescAttr BlockTensorDescAttr::get(::mlir::MLIRContext *context, MemorySpaceAttr memory_space, IntegerAttr array_length, BoolAttr boundary_check) {
  return Base::get(context, std::move(memory_space), std::move(array_length), std::move(boundary_check));
}

::mlir::Attribute BlockTensorDescAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<MemorySpaceAttr> _result_memory_space;
  ::mlir::FailureOr<IntegerAttr> _result_array_length;
  ::mlir::FailureOr<BoolAttr> _result_boundary_check;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_memory_space = false;
  bool _seen_array_length = false;
  bool _seen_boundary_check = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_memory_space && _paramKey == "memory_space") {
        _seen_memory_space = true;

        // Parse variable 'memory_space'
        _result_memory_space = ::mlir::FieldParser<MemorySpaceAttr>::parse(odsParser);
        if (::mlir::failed(_result_memory_space)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_BlockTensorDescAttr parameter 'memory_space' which is to be a `MemorySpaceAttr`");
          return {};
        }
      } else if (!_seen_array_length && _paramKey == "array_length") {
        _seen_array_length = true;

        // Parse variable 'array_length'
        _result_array_length = ::mlir::FieldParser<IntegerAttr>::parse(odsParser);
        if (::mlir::failed(_result_array_length)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_BlockTensorDescAttr parameter 'array_length' which is to be a `IntegerAttr`");
          return {};
        }
      } else if (!_seen_boundary_check && _paramKey == "boundary_check") {
        _seen_boundary_check = true;

        // Parse variable 'boundary_check'
        _result_boundary_check = ::mlir::FieldParser<BoolAttr>::parse(odsParser);
        if (::mlir::failed(_result_boundary_check)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_BlockTensorDescAttr parameter 'boundary_check' which is to be a `BoolAttr`");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    ::llvm::StringRef _paramKey;
    if (!odsParser.parseOptionalKeyword(&_paramKey)) {
      if (!_loop_body(_paramKey)) return {};
      while (!odsParser.parseOptionalComma()) {
        ::llvm::StringRef _paramKey;
        if (odsParser.parseKeyword(&_paramKey)) {
          odsParser.emitError(odsParser.getCurrentLocation(),
                             "expected a parameter name in struct");
          return {};
        }
        if (!_loop_body(_paramKey)) return {};
      }
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  return BlockTensorDescAttr::get(odsParser.getContext(),
      MemorySpaceAttr((_result_memory_space.value_or(MemorySpaceAttr()))),
      IntegerAttr((_result_array_length.value_or(IntegerAttr()))),
      BoolAttr((_result_boundary_check.value_or(BoolAttr()))));
}

void BlockTensorDescAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if (!(getMemorySpace() == MemorySpaceAttr())) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "memory_space = ";
      if (!(getMemorySpace() == MemorySpaceAttr())) {
        odsPrinter.printStrippedAttrOrType(getMemorySpace());
      }
    }
    if (!(getArrayLength() == IntegerAttr())) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "array_length = ";
      if (!(getArrayLength() == IntegerAttr())) {
        odsPrinter.printStrippedAttrOrType(getArrayLength());
      }
    }
    if (!(getBoundaryCheck() == BoolAttr())) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "boundary_check = ";
      if (!(getBoundaryCheck() == BoolAttr())) {
        odsPrinter.printStrippedAttrOrType(getBoundaryCheck());
      }
    }
  }
  odsPrinter << ">";
}

MemorySpaceAttr BlockTensorDescAttr::getMemorySpace() const {
  return getImpl()->memory_space;
}

IntegerAttr BlockTensorDescAttr::getArrayLength() const {
  return getImpl()->array_length;
}

BoolAttr BlockTensorDescAttr::getBoundaryCheck() const {
  return getImpl()->boundary_check;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::BlockTensorDescAttr)
namespace mlir {
namespace xegpu {
namespace detail {
struct ScatterTensorDescAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<MemorySpaceAttr, IntegerAttr>;
  ScatterTensorDescAttrStorage(MemorySpaceAttr memory_space, IntegerAttr chunk_size) : memory_space(std::move(memory_space)), chunk_size(std::move(chunk_size)) {}

  KeyTy getAsKey() const {
    return KeyTy(memory_space, chunk_size);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (memory_space == std::get<0>(tblgenKey)) && (chunk_size == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static ScatterTensorDescAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto memory_space = std::move(std::get<0>(tblgenKey));
    auto chunk_size = std::move(std::get<1>(tblgenKey));
    return new (allocator.allocate<ScatterTensorDescAttrStorage>()) ScatterTensorDescAttrStorage(std::move(memory_space), std::move(chunk_size));
  }

  MemorySpaceAttr memory_space;
  IntegerAttr chunk_size;
};
} // namespace detail
ScatterTensorDescAttr ScatterTensorDescAttr::get(::mlir::MLIRContext *context, MemorySpaceAttr memory_space, IntegerAttr chunk_size) {
  return Base::get(context, std::move(memory_space), std::move(chunk_size));
}

::mlir::Attribute ScatterTensorDescAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<MemorySpaceAttr> _result_memory_space;
  ::mlir::FailureOr<IntegerAttr> _result_chunk_size;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_memory_space = false;
  bool _seen_chunk_size = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_memory_space && _paramKey == "memory_space") {
        _seen_memory_space = true;

        // Parse variable 'memory_space'
        _result_memory_space = ::mlir::FieldParser<MemorySpaceAttr>::parse(odsParser);
        if (::mlir::failed(_result_memory_space)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_ScatterTensorDescAttr parameter 'memory_space' which is to be a `MemorySpaceAttr`");
          return {};
        }
      } else if (!_seen_chunk_size && _paramKey == "chunk_size") {
        _seen_chunk_size = true;

        // Parse variable 'chunk_size'
        _result_chunk_size = ::mlir::FieldParser<IntegerAttr>::parse(odsParser);
        if (::mlir::failed(_result_chunk_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_ScatterTensorDescAttr parameter 'chunk_size' which is to be a `IntegerAttr`");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    ::llvm::StringRef _paramKey;
    if (!odsParser.parseOptionalKeyword(&_paramKey)) {
      if (!_loop_body(_paramKey)) return {};
      while (!odsParser.parseOptionalComma()) {
        ::llvm::StringRef _paramKey;
        if (odsParser.parseKeyword(&_paramKey)) {
          odsParser.emitError(odsParser.getCurrentLocation(),
                             "expected a parameter name in struct");
          return {};
        }
        if (!_loop_body(_paramKey)) return {};
      }
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  return ScatterTensorDescAttr::get(odsParser.getContext(),
      MemorySpaceAttr((_result_memory_space.value_or(MemorySpaceAttr()))),
      IntegerAttr((_result_chunk_size.value_or(IntegerAttr()))));
}

void ScatterTensorDescAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if (!(getMemorySpace() == MemorySpaceAttr())) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "memory_space = ";
      if (!(getMemorySpace() == MemorySpaceAttr())) {
        odsPrinter.printStrippedAttrOrType(getMemorySpace());
      }
    }
    if (!(getChunkSize() == IntegerAttr())) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "chunk_size = ";
      if (!(getChunkSize() == IntegerAttr())) {
        odsPrinter.printStrippedAttrOrType(getChunkSize());
      }
    }
  }
  odsPrinter << ">";
}

MemorySpaceAttr ScatterTensorDescAttr::getMemorySpace() const {
  return getImpl()->memory_space;
}

IntegerAttr ScatterTensorDescAttr::getChunkSize() const {
  return getImpl()->chunk_size;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::ScatterTensorDescAttr)
namespace mlir {
namespace xegpu {
namespace detail {
struct MemorySpaceAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::xegpu::MemorySpace>;
  MemorySpaceAttrStorage(::mlir::xegpu::MemorySpace value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static MemorySpaceAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<MemorySpaceAttrStorage>()) MemorySpaceAttrStorage(std::move(value));
  }

  ::mlir::xegpu::MemorySpace value;
};
} // namespace detail
MemorySpaceAttr MemorySpaceAttr::get(::mlir::MLIRContext *context, ::mlir::xegpu::MemorySpace value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute MemorySpaceAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::xegpu::MemorySpace> _result_value;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::xegpu::MemorySpace> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::xegpu::symbolizeMemorySpace(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::xegpu::MemorySpace" << " to be one of: " << "global" << ", " << "slm")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_MemorySpaceAttr parameter 'value' which is to be a `::mlir::xegpu::MemorySpace`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return MemorySpaceAttr::get(odsParser.getContext(),
      ::mlir::xegpu::MemorySpace((*_result_value)));
}

void MemorySpaceAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyMemorySpace(getValue());
}

::mlir::xegpu::MemorySpace MemorySpaceAttr::getValue() const {
  return getImpl()->value;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::MemorySpaceAttr)
namespace mlir {
namespace xegpu {
namespace detail {
struct CachePolicyAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::xegpu::CachePolicy>;
  CachePolicyAttrStorage(::mlir::xegpu::CachePolicy value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static CachePolicyAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<CachePolicyAttrStorage>()) CachePolicyAttrStorage(std::move(value));
  }

  ::mlir::xegpu::CachePolicy value;
};
} // namespace detail
CachePolicyAttr CachePolicyAttr::get(::mlir::MLIRContext *context, ::mlir::xegpu::CachePolicy value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute CachePolicyAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::xegpu::CachePolicy> _result_value;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::xegpu::CachePolicy> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::xegpu::symbolizeCachePolicy(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::xegpu::CachePolicy" << " to be one of: " << "cached" << ", " << "uncached" << ", " << "streaming" << ", " << "read_invalidate" << ", " << "write_back" << ", " << "write_through")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_CacheHintAttr parameter 'value' which is to be a `::mlir::xegpu::CachePolicy`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_value));
  return CachePolicyAttr::get(odsParser.getContext(),
      ::mlir::xegpu::CachePolicy((*_result_value)));
}

void CachePolicyAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << stringifyCachePolicy(getValue());
  odsPrinter << ">";
}

::mlir::xegpu::CachePolicy CachePolicyAttr::getValue() const {
  return getImpl()->value;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::CachePolicyAttr)
namespace mlir {
namespace xegpu {
namespace detail {
struct FenceScopeAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::xegpu::FenceScope>;
  FenceScopeAttrStorage(::mlir::xegpu::FenceScope value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static FenceScopeAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<FenceScopeAttrStorage>()) FenceScopeAttrStorage(std::move(value));
  }

  ::mlir::xegpu::FenceScope value;
};
} // namespace detail
FenceScopeAttr FenceScopeAttr::get(::mlir::MLIRContext *context, ::mlir::xegpu::FenceScope value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute FenceScopeAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::xegpu::FenceScope> _result_value;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::xegpu::FenceScope> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::xegpu::symbolizeFenceScope(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::xegpu::FenceScope" << " to be one of: " << "workgroup" << ", " << "gpu")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse XeGPU_FenceScopeAttr parameter 'value' which is to be a `::mlir::xegpu::FenceScope`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return FenceScopeAttr::get(odsParser.getContext(),
      ::mlir::xegpu::FenceScope((*_result_value)));
}

void FenceScopeAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyFenceScope(getValue());
}

::mlir::xegpu::FenceScope FenceScopeAttr::getValue() const {
  return getImpl()->value;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::FenceScopeAttr)
namespace mlir {
namespace xegpu {
namespace detail {
struct SGMapAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<uint32_t>, ::llvm::ArrayRef<uint32_t>>;
  SGMapAttrStorage(::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data) : wi_layout(std::move(wi_layout)), wi_data(std::move(wi_data)) {}

  KeyTy getAsKey() const {
    return KeyTy(wi_layout, wi_data);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (wi_layout == std::get<0>(tblgenKey)) && (wi_data == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static SGMapAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto wi_layout = std::move(std::get<0>(tblgenKey));
    auto wi_data = std::move(std::get<1>(tblgenKey));
    wi_layout = allocator.copyInto(wi_layout);
    wi_data = allocator.copyInto(wi_data);
    return new (allocator.allocate<SGMapAttrStorage>()) SGMapAttrStorage(std::move(wi_layout), std::move(wi_data));
  }

  ::llvm::ArrayRef<uint32_t> wi_layout;
  ::llvm::ArrayRef<uint32_t> wi_data;
};
} // namespace detail
SGMapAttr SGMapAttr::get(::mlir::MLIRContext *context, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data) {
  return Base::get(context, std::move(wi_layout), std::move(wi_data));
}

SGMapAttr SGMapAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data) {
  return Base::getChecked(emitError, context, wi_layout, wi_data);
}

::llvm::LogicalResult SGMapAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data) {
  if (::mlir::failed(verify(emitError, wi_layout, wi_data)))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::ArrayRef<uint32_t> SGMapAttr::getWiLayout() const {
  return getImpl()->wi_layout;
}

::llvm::ArrayRef<uint32_t> SGMapAttr::getWiData() const {
  return getImpl()->wi_data;
}

} // namespace xegpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::SGMapAttr)
namespace mlir {
namespace xegpu {

/// Parse an attribute registered to this dialect.
::mlir::Attribute XeGPUDialect::parseAttribute(::mlir::DialectAsmParser &parser,
                                      ::mlir::Type type) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef attrTag;
  {
    ::mlir::Attribute attr;
    auto parseResult = generatedAttributeParser(parser, &attrTag, type, attr);
    if (parseResult.has_value())
      return attr;
  }
  
  parser.emitError(typeLoc) << "unknown attribute `"
      << attrTag << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print an attribute registered to this dialect.
void XeGPUDialect::printAttribute(::mlir::Attribute attr,
                         ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedAttributePrinter(attr, printer)))
    return;
  
}
} // namespace xegpu
} // namespace mlir

#endif  // GET_ATTRDEF_CLASSES

