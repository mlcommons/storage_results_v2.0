/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mlir::mpi::MPI_ErrorClassEnumAttr,
::mlir::mpi::MPI_OpClassEnumAttr

#endif  // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::mpi::MPI_ErrorClassEnumAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mpi::MPI_ErrorClassEnumAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::mpi::MPI_OpClassEnumAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mpi::MPI_OpClassEnumAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::llvm::LogicalResult>(def)    .Case<::mlir::mpi::MPI_ErrorClassEnumAttr>([&](auto t) {
      printer << ::mlir::mpi::MPI_ErrorClassEnumAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::mpi::MPI_OpClassEnumAttr>([&](auto t) {
      printer << ::mlir::mpi::MPI_OpClassEnumAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace mpi {
namespace detail {
struct MPI_ErrorClassEnumAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::mpi::MPI_ErrorClassEnum>;
  MPI_ErrorClassEnumAttrStorage(::mlir::mpi::MPI_ErrorClassEnum value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static MPI_ErrorClassEnumAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<MPI_ErrorClassEnumAttrStorage>()) MPI_ErrorClassEnumAttrStorage(std::move(value));
  }

  ::mlir::mpi::MPI_ErrorClassEnum value;
};
} // namespace detail
MPI_ErrorClassEnumAttr MPI_ErrorClassEnumAttr::get(::mlir::MLIRContext *context, ::mlir::mpi::MPI_ErrorClassEnum value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute MPI_ErrorClassEnumAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::mpi::MPI_ErrorClassEnum> _result_value;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::mpi::MPI_ErrorClassEnum> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::mpi::symbolizeMPI_ErrorClassEnum(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::mpi::MPI_ErrorClassEnum" << " to be one of: " << "MPI_SUCCESS" << ", " << "MPI_ERR_ACCESS" << ", " << "MPI_ERR_AMODE" << ", " << "MPI_ERR_ARG" << ", " << "MPI_ERR_ASSERT" << ", " << "MPI_ERR_BAD_FILE" << ", " << "MPI_ERR_BASE" << ", " << "MPI_ERR_BUFFER" << ", " << "MPI_ERR_COMM" << ", " << "MPI_ERR_CONVERSION" << ", " << "MPI_ERR_COUNT" << ", " << "MPI_ERR_DIMS" << ", " << "MPI_ERR_DISP" << ", " << "MPI_ERR_DUP_DATAREP" << ", " << "MPI_ERR_ERRHANDLER" << ", " << "MPI_ERR_FILE" << ", " << "MPI_ERR_FILE_EXISTS" << ", " << "MPI_ERR_FILE_IN_USE" << ", " << "MPI_ERR_GROUP" << ", " << "MPI_ERR_INFO" << ", " << "MPI_ERR_INFO_KEY" << ", " << "MPI_ERR_INFO_NOKEY" << ", " << "MPI_ERR_INFO_VALUE" << ", " << "MPI_ERR_IN_STATUS" << ", " << "MPI_ERR_INTERN" << ", " << "MPI_ERR_IO" << ", " << "MPI_ERR_KEYVAL" << ", " << "MPI_ERR_LOCKTYPE" << ", " << "MPI_ERR_NAME" << ", " << "MPI_ERR_NO_MEM" << ", " << "MPI_ERR_NO_SPACE" << ", " << "MPI_ERR_NO_SUCH_FILE" << ", " << "MPI_ERR_NOT_SAME" << ", " << "MPI_ERR_OP" << ", " << "MPI_ERR_OTHER" << ", " << "MPI_ERR_PENDING" << ", " << "MPI_ERR_PORT" << ", " << "MPI_ERR_PROC_ABORTED" << ", " << "MPI_ERR_QUOTA" << ", " << "MPI_ERR_RANK" << ", " << "MPI_ERR_READ_ONLY" << ", " << "MPI_ERR_REQUEST" << ", " << "MPI_ERR_RMA_ATTACH" << ", " << "MPI_ERR_RMA_CONFLICT" << ", " << "MPI_ERR_RMA_FLAVOR" << ", " << "MPI_ERR_RMA_RANGE" << ", " << "MPI_ERR_RMA_SHARED" << ", " << "MPI_ERR_RMA_SYNC" << ", " << "MPI_ERR_ROOT" << ", " << "MPI_ERR_SERVICE" << ", " << "MPI_ERR_SESSION" << ", " << "MPI_ERR_SIZE" << ", " << "MPI_ERR_SPAWN" << ", " << "MPI_ERR_TAG" << ", " << "MPI_ERR_TOPOLOGY" << ", " << "MPI_ERR_TRUNCATE" << ", " << "MPI_ERR_TYPE" << ", " << "MPI_ERR_UNKNOWN" << ", " << "MPI_ERR_UNSUPPORTED_DATAREP" << ", " << "MPI_ERR_UNSUPPORTED_OPERATION" << ", " << "MPI_ERR_VALUE_TOO_LARGE" << ", " << "MPI_ERR_WIN" << ", " << "MPI_ERR_LASTCODE")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MPI_ErrorClassAttr parameter 'value' which is to be a `::mlir::mpi::MPI_ErrorClassEnum`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_value));
  return MPI_ErrorClassEnumAttr::get(odsParser.getContext(),
      ::mlir::mpi::MPI_ErrorClassEnum((*_result_value)));
}

void MPI_ErrorClassEnumAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << stringifyMPI_ErrorClassEnum(getValue());
  odsPrinter << ">";
}

::mlir::mpi::MPI_ErrorClassEnum MPI_ErrorClassEnumAttr::getValue() const {
  return getImpl()->value;
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::MPI_ErrorClassEnumAttr)
namespace mlir {
namespace mpi {
namespace detail {
struct MPI_OpClassEnumAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::mpi::MPI_OpClassEnum>;
  MPI_OpClassEnumAttrStorage(::mlir::mpi::MPI_OpClassEnum value) : value(std::move(value)) {}

  KeyTy getAsKey() const {
    return KeyTy(value);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static MPI_OpClassEnumAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto value = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<MPI_OpClassEnumAttrStorage>()) MPI_OpClassEnumAttrStorage(std::move(value));
  }

  ::mlir::mpi::MPI_OpClassEnum value;
};
} // namespace detail
MPI_OpClassEnumAttr MPI_OpClassEnumAttr::get(::mlir::MLIRContext *context, ::mlir::mpi::MPI_OpClassEnum value) {
  return Base::get(context, std::move(value));
}

::mlir::Attribute MPI_OpClassEnumAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::mpi::MPI_OpClassEnum> _result_value;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::mpi::MPI_OpClassEnum> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::mpi::symbolizeMPI_OpClassEnum(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::llvm::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::mpi::MPI_OpClassEnum" << " to be one of: " << "MPI_OP_NULL" << ", " << "MPI_MAX" << ", " << "MPI_MIN" << ", " << "MPI_SUM" << ", " << "MPI_PROD" << ", " << "MPI_LAND" << ", " << "MPI_BAND" << ", " << "MPI_LOR" << ", " << "MPI_BOR" << ", " << "MPI_LXOR" << ", " << "MPI_BXOR" << ", " << "MPI_MINLOC" << ", " << "MPI_MAXLOC" << ", " << "MPI_REPLACE")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MPI_OpClassAttr parameter 'value' which is to be a `::mlir::mpi::MPI_OpClassEnum`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_value));
  return MPI_OpClassEnumAttr::get(odsParser.getContext(),
      ::mlir::mpi::MPI_OpClassEnum((*_result_value)));
}

void MPI_OpClassEnumAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << stringifyMPI_OpClassEnum(getValue());
  odsPrinter << ">";
}

::mlir::mpi::MPI_OpClassEnum MPI_OpClassEnumAttr::getValue() const {
  return getImpl()->value;
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::MPI_OpClassEnumAttr)
namespace mlir {
namespace mpi {

/// Parse an attribute registered to this dialect.
::mlir::Attribute MPIDialect::parseAttribute(::mlir::DialectAsmParser &parser,
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
void MPIDialect::printAttribute(::mlir::Attribute attr,
                         ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedAttributePrinter(attr, printer)))
    return;
  
}
} // namespace mpi
} // namespace mlir

#endif  // GET_ATTRDEF_CLASSES

