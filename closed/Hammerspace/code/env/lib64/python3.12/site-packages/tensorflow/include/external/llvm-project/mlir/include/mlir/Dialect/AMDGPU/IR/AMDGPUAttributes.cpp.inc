/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mlir::amdgpu::DPPPermAttr,
::mlir::amdgpu::sched_barrier_opt_enumAttr,
::mlir::amdgpu::MFMAPermBAttr

#endif  // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::amdgpu::DPPPermAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::amdgpu::DPPPermAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::amdgpu::sched_barrier_opt_enumAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::amdgpu::sched_barrier_opt_enumAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::amdgpu::MFMAPermBAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::amdgpu::MFMAPermBAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::llvm::LogicalResult>(def)    .Case<::mlir::amdgpu::DPPPermAttr>([&](auto t) {
      printer << ::mlir::amdgpu::DPPPermAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::amdgpu::sched_barrier_opt_enumAttr>([&](auto t) {
      printer << ::mlir::amdgpu::sched_barrier_opt_enumAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::amdgpu::MFMAPermBAttr>([&](auto t) {
      printer << ::mlir::amdgpu::MFMAPermBAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace amdgpu {
namespace detail {
struct DPPPermAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::amdgpu::DPPPerm>;
  DPPPermAttrStorage(::mlir::amdgpu::DPPPerm value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static DPPPermAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<DPPPermAttrStorage>()) DPPPermAttrStorage(std::move(value));
  }

  ::mlir::amdgpu::DPPPerm value;
};
} // namespace detail
DPPPermAttr DPPPermAttr::get(::mlir::MLIRContext *context, ::mlir::amdgpu::DPPPerm value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute DPPPermAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::amdgpu::DPPPerm> _result_value;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::amdgpu::DPPPerm> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::amdgpu::symbolizeDPPPerm(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::amdgpu::DPPPerm" << " to be one of: " << "quad_perm" << ", " << "row_shl" << ", " << "row_shr" << ", " << "row_ror" << ", " << "wave_shl" << ", " << "wave_shr" << ", " << "wave_ror" << ", " << "wave_rol" << ", " << "row_mirror" << ", " << "row_half_mirror" << ", " << "row_bcast_15" << ", " << "row_bcast_31")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse AMDGPU_DPPPermAttr parameter 'value' which is to be a `::mlir::amdgpu::DPPPerm`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return DPPPermAttr::get(odsParser.getContext(),
      ::mlir::amdgpu::DPPPerm((*_result_value)));
}

void DPPPermAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyDPPPerm(getValue());
}

::mlir::amdgpu::DPPPerm DPPPermAttr::getValue() const {
  return getImpl()->value;
}

} // namespace amdgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::amdgpu::DPPPermAttr)
namespace mlir {
namespace amdgpu {
namespace detail {
struct sched_barrier_opt_enumAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::amdgpu::sched_barrier_opt_enum>;
  sched_barrier_opt_enumAttrStorage(::mlir::amdgpu::sched_barrier_opt_enum value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static sched_barrier_opt_enumAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<sched_barrier_opt_enumAttrStorage>()) sched_barrier_opt_enumAttrStorage(std::move(value));
  }

  ::mlir::amdgpu::sched_barrier_opt_enum value;
};
} // namespace detail
sched_barrier_opt_enumAttr sched_barrier_opt_enumAttr::get(::mlir::MLIRContext *context, ::mlir::amdgpu::sched_barrier_opt_enum value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute sched_barrier_opt_enumAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::amdgpu::sched_barrier_opt_enum> _result_value;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::amdgpu::sched_barrier_opt_enum> {
      ::mlir::amdgpu::sched_barrier_opt_enum flags = {};
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      do {
        if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
          return ::mlir::failure();
        auto maybeEnum = ::mlir::amdgpu::symbolizesched_barrier_opt_enum(enumKeyword);
        if (!maybeEnum) {
            return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::amdgpu::sched_barrier_opt_enum" << " to be one of: " << "none" << ", " << "non_mem_non_sideffect" << ", " << "valu" << ", " << "salu" << ", " << "mfma_wmma" << ", " << "all_vmem" << ", " << "vmem_read" << ", " << "vmem_write" << ", " << "all_ds" << ", " << "ds_read" << ", " << "ds_write" << ", " << "transcendental")};
        }
        flags = flags | *maybeEnum;
      } while(::mlir::succeeded(odsParser.parseOptionalVerticalBar()));
      return flags;
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse AMDGPU_SchedBarrierOpOptAttr parameter 'value' which is to be a `::mlir::amdgpu::sched_barrier_opt_enum`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_value));
  return sched_barrier_opt_enumAttr::get(odsParser.getContext(),
      ::mlir::amdgpu::sched_barrier_opt_enum((*_result_value)));
}

void sched_barrier_opt_enumAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << stringifysched_barrier_opt_enum(getValue());
  odsPrinter << ">";
}

::mlir::amdgpu::sched_barrier_opt_enum sched_barrier_opt_enumAttr::getValue() const {
  return getImpl()->value;
}

} // namespace amdgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::amdgpu::sched_barrier_opt_enumAttr)
namespace mlir {
namespace amdgpu {
namespace detail {
struct MFMAPermBAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::amdgpu::MFMAPermB>;
  MFMAPermBAttrStorage(::mlir::amdgpu::MFMAPermB value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static MFMAPermBAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<MFMAPermBAttrStorage>()) MFMAPermBAttrStorage(std::move(value));
  }

  ::mlir::amdgpu::MFMAPermB value;
};
} // namespace detail
MFMAPermBAttr MFMAPermBAttr::get(::mlir::MLIRContext *context, ::mlir::amdgpu::MFMAPermB value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute MFMAPermBAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::amdgpu::MFMAPermB> _result_value;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::amdgpu::MFMAPermB> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::amdgpu::symbolizeMFMAPermB(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::amdgpu::MFMAPermB" << " to be one of: " << "none" << ", " << "bcast_first_32" << ", " << "bcast_second_32" << ", " << "rotate_16_right" << ", " << "bcast_first_16" << ", " << "bcast_second_16" << ", " << "bcast_third_16" << ", " << "bcast_fourth_16")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse AMDGPU_MFMAPermBAttr parameter 'value' which is to be a `::mlir::amdgpu::MFMAPermB`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return MFMAPermBAttr::get(odsParser.getContext(),
      ::mlir::amdgpu::MFMAPermB((*_result_value)));
}

void MFMAPermBAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyMFMAPermB(getValue());
}

::mlir::amdgpu::MFMAPermB MFMAPermBAttr::getValue() const {
  return getImpl()->value;
}

} // namespace amdgpu
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::amdgpu::MFMAPermBAttr)
namespace mlir {
namespace amdgpu {

/// Parse an attribute registered to this dialect.
::mlir::Attribute AMDGPUDialect::parseAttribute(::mlir::DialectAsmParser &parser,
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
void AMDGPUDialect::printAttribute(::mlir::Attribute attr,
                         ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedAttributePrinter(attr, printer)))
    return;
  
}
} // namespace amdgpu
} // namespace mlir

#endif  // GET_ATTRDEF_CLASSES

