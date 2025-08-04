/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MPIOps.td                                                            *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::mpi::AllReduceOp,
::mlir::mpi::Barrier,
::mlir::mpi::CommRankOp,
::mlir::mpi::CommSizeOp,
::mlir::mpi::ErrorClassOp,
::mlir::mpi::FinalizeOp,
::mlir::mpi::IRecvOp,
::mlir::mpi::ISendOp,
::mlir::mpi::InitOp,
::mlir::mpi::RecvOp,
::mlir::mpi::RetvalCheckOp,
::mlir::mpi::SendOp,
::mlir::mpi::Wait
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace mpi {

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MPIOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::MemRefType>(type))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be memref of any type values, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MPIOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::mpi::RetvalType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be MPI function call return value, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MPIOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(32)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 32-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MPIOps4(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::mpi::RequestType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be MPI asynchronous request handler, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MPIOps5(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(1)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 1-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MPIOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::mpi::MPI_OpClassEnumAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: MPI operation class";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MPIOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MPIOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MPIOps2(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::mpi::MPI_ErrorClassEnumAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: MPI error class name";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MPIOps2(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MPIOps2(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
} // namespace mpi
} // namespace mlir
namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::AllReduceOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
AllReduceOpGenericAdaptorBase::AllReduceOpGenericAdaptorBase(AllReduceOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

::mlir::mpi::MPI_OpClassEnum AllReduceOpGenericAdaptorBase::getOp() {
  auto attr = getOpAttr();
  return attr.getValue();
}

} // namespace detail
AllReduceOpAdaptor::AllReduceOpAdaptor(AllReduceOp op) : AllReduceOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult AllReduceOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_op = getProperties().op; (void)tblgen_op;
  if (!tblgen_op) return emitError(loc, "'mpi.allreduce' op ""requires attribute 'op'");

  if (tblgen_op && !((::llvm::isa<::mlir::mpi::MPI_OpClassEnumAttr>(tblgen_op))))
    return emitError(loc, "'mpi.allreduce' op ""attribute 'op' failed to satisfy constraint: MPI operation class");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> AllReduceOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::llvm::LogicalResult AllReduceOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.op;
       auto attr = dict.get("op");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `op` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute AllReduceOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.op;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("op",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AllReduceOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.op.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> AllReduceOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "op")
      return prop.op;
  return std::nullopt;
}

void AllReduceOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "op") {
       prop.op = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.op)>>(value);
       return;
    }
}

void AllReduceOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.op) attrs.append("op", prop.op);
}

::llvm::LogicalResult AllReduceOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getOpAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MPIOps1(attr, "op", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult AllReduceOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.op)))
    return ::mlir::failure();
  return ::mlir::success();
}

void AllReduceOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.op);
}

::mlir::mpi::MPI_OpClassEnum AllReduceOp::getOp() {
  auto attr = getOpAttr();
  return attr.getValue();
}

void AllReduceOp::setOp(::mlir::mpi::MPI_OpClassEnum attrValue) {
  getProperties().op = ::mlir::mpi::MPI_OpClassEnumAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void AllReduceOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Value sendbuf, ::mlir::Value recvbuf, ::mlir::mpi::MPI_OpClassEnumAttr op) {
  odsState.addOperands(sendbuf);
  odsState.addOperands(recvbuf);
  odsState.getOrAddProperties<Properties>().op = op;
  if (retval)
    odsState.addTypes(retval);
}

void AllReduceOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value sendbuf, ::mlir::Value recvbuf, ::mlir::mpi::MPI_OpClassEnumAttr op) {
  odsState.addOperands(sendbuf);
  odsState.addOperands(recvbuf);
  odsState.getOrAddProperties<Properties>().op = op;
  odsState.addTypes(resultTypes);
}

void AllReduceOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Value sendbuf, ::mlir::Value recvbuf, ::mlir::mpi::MPI_OpClassEnum op) {
  odsState.addOperands(sendbuf);
  odsState.addOperands(recvbuf);
  odsState.getOrAddProperties<Properties>().op = ::mlir::mpi::MPI_OpClassEnumAttr::get(odsBuilder.getContext(), op);
  if (retval)
    odsState.addTypes(retval);
}

void AllReduceOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value sendbuf, ::mlir::Value recvbuf, ::mlir::mpi::MPI_OpClassEnum op) {
  odsState.addOperands(sendbuf);
  odsState.addOperands(recvbuf);
  odsState.getOrAddProperties<Properties>().op = ::mlir::mpi::MPI_OpClassEnumAttr::get(odsBuilder.getContext(), op);
  odsState.addTypes(resultTypes);
}

void AllReduceOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<AllReduceOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult AllReduceOp::verifyInvariantsImpl() {
  auto tblgen_op = getProperties().op; (void)tblgen_op;
  if (!tblgen_op) return emitOpError("requires attribute 'op'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MPIOps1(*this, tblgen_op, "op")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult AllReduceOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult AllReduceOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand sendbufRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> sendbufOperands(&sendbufRawOperand, 1);  ::llvm::SMLoc sendbufOperandsLoc;
  (void)sendbufOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand recvbufRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> recvbufOperands(&recvbufRawOperand, 1);  ::llvm::SMLoc recvbufOperandsLoc;
  (void)recvbufOperandsLoc;
  ::mlir::mpi::MPI_OpClassEnumAttr opAttr;
  ::mlir::Type sendbufRawType{};
  ::llvm::ArrayRef<::mlir::Type> sendbufTypes(&sendbufRawType, 1);
  ::mlir::Type recvbufRawType{};
  ::llvm::ArrayRef<::mlir::Type> recvbufTypes(&recvbufRawType, 1);
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  if (parser.parseLParen())
    return ::mlir::failure();

  sendbufOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(sendbufRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  recvbufOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(recvbufRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseCustomAttributeWithFallback(opAttr, ::mlir::Type{})) {
    return ::mlir::failure();
  }
  if (opAttr) result.getOrAddProperties<AllReduceOp::Properties>().op = opAttr;
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::MemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    sendbufRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::MemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    recvbufRawType = type;
  }
  if (::mlir::succeeded(parser.parseOptionalArrow())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  if (parser.resolveOperands(sendbufOperands, sendbufTypes, sendbufOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(recvbufOperands, recvbufTypes, recvbufOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void AllReduceOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getSendbuf();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getRecvbuf();
  _odsPrinter << ",";
  _odsPrinter << ' ';
_odsPrinter.printStrippedAttrOrType(getOpAttr());
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("op");
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getSendbuf().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::MemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getRecvbuf().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::MemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  if (getRetval()) {
    _odsPrinter << ' ' << "->";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::AllReduceOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::Barrier definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
BarrierAdaptor::BarrierAdaptor(Barrier op) : BarrierGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult BarrierAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> Barrier::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void Barrier::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval) {
  if (retval)
    odsState.addTypes(retval);
}

void Barrier::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  odsState.addTypes(resultTypes);
}

void Barrier::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult Barrier::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult Barrier::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult Barrier::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (::mlir::succeeded(parser.parseOptionalColon())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  return ::mlir::success();
}

void Barrier::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  if (getRetval()) {
    _odsPrinter << ' ' << ":";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::Barrier)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::CommRankOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
CommRankOpAdaptor::CommRankOpAdaptor(CommRankOp op) : CommRankOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult CommRankOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void CommRankOp::getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn) {
  auto resultGroup0 = getODSResults(0);
  if (!resultGroup0.empty())
    setNameFn(*resultGroup0.begin(), "retval");
  auto resultGroup1 = getODSResults(1);
  if (!resultGroup1.empty())
    setNameFn(*resultGroup1.begin(), "rank");
}

std::pair<unsigned, unsigned> CommRankOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true, false};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void CommRankOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Type rank) {
  if (retval)
    odsState.addTypes(retval);
  odsState.addTypes(rank);
}

void CommRankOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() >= 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CommRankOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() >= 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult CommRankOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSResults(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult CommRankOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult CommRankOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::Type, 1> allResultTypes;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  if (parser.parseTypeList(allResultTypes))
    return ::mlir::failure();
  result.addTypes(allResultTypes);
  return ::mlir::success();
}

void CommRankOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter << getOperation()->getResultTypes();
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::CommRankOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::CommSizeOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
CommSizeOpAdaptor::CommSizeOpAdaptor(CommSizeOp op) : CommSizeOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult CommSizeOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void CommSizeOp::getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn) {
  auto resultGroup0 = getODSResults(0);
  if (!resultGroup0.empty())
    setNameFn(*resultGroup0.begin(), "retval");
  auto resultGroup1 = getODSResults(1);
  if (!resultGroup1.empty())
    setNameFn(*resultGroup1.begin(), "size");
}

std::pair<unsigned, unsigned> CommSizeOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true, false};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void CommSizeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Type size) {
  if (retval)
    odsState.addTypes(retval);
  odsState.addTypes(size);
}

void CommSizeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() >= 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CommSizeOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() >= 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult CommSizeOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSResults(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult CommSizeOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult CommSizeOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::Type, 1> allResultTypes;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  if (parser.parseTypeList(allResultTypes))
    return ::mlir::failure();
  result.addTypes(allResultTypes);
  return ::mlir::success();
}

void CommSizeOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter << getOperation()->getResultTypes();
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::CommSizeOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::ErrorClassOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
ErrorClassOpAdaptor::ErrorClassOpAdaptor(ErrorClassOp op) : ErrorClassOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ErrorClassOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void ErrorClassOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type errclass, ::mlir::Value val) {
  odsState.addOperands(val);
  odsState.addTypes(errclass);
}

void ErrorClassOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value val) {
  odsState.addOperands(val);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ErrorClassOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult ErrorClassOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult ErrorClassOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult ErrorClassOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand valRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> valOperands(&valRawOperand, 1);  ::llvm::SMLoc valOperandsLoc;
  (void)valOperandsLoc;
  ::mlir::Type valRawType{};
  ::llvm::ArrayRef<::mlir::Type> valTypes(&valRawType, 1);

  valOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(valRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::mpi::RetvalType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    valRawType = type;
  }
  ::mlir::Type odsBuildableType0 = parser.getBuilder().getType<::mlir::mpi::RetvalType>();
  result.addTypes(odsBuildableType0);
  if (parser.resolveOperands(valOperands, valTypes, valOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ErrorClassOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getVal();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getVal().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::mpi::RetvalType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::ErrorClassOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::FinalizeOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
FinalizeOpAdaptor::FinalizeOpAdaptor(FinalizeOp op) : FinalizeOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult FinalizeOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> FinalizeOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void FinalizeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval) {
  if (retval)
    odsState.addTypes(retval);
}

void FinalizeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  odsState.addTypes(resultTypes);
}

void FinalizeOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult FinalizeOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult FinalizeOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult FinalizeOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (::mlir::succeeded(parser.parseOptionalColon())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  return ::mlir::success();
}

void FinalizeOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  if (getRetval()) {
    _odsPrinter << ' ' << ":";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::FinalizeOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::IRecvOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
IRecvOpAdaptor::IRecvOpAdaptor(IRecvOp op) : IRecvOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult IRecvOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void IRecvOp::getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn) {
  auto resultGroup0 = getODSResults(0);
  if (!resultGroup0.empty())
    setNameFn(*resultGroup0.begin(), "retval");
  auto resultGroup1 = getODSResults(1);
  if (!resultGroup1.empty())
    setNameFn(*resultGroup1.begin(), "req");
}

std::pair<unsigned, unsigned> IRecvOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true, false};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void IRecvOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Type req, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  if (retval)
    odsState.addTypes(retval);
  odsState.addTypes(req);
}

void IRecvOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  assert(resultTypes.size() >= 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void IRecvOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() >= 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult IRecvOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSResults(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps4(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult IRecvOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult IRecvOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand refRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> refOperands(&refRawOperand, 1);  ::llvm::SMLoc refOperandsLoc;
  (void)refOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand tagRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> tagOperands(&tagRawOperand, 1);  ::llvm::SMLoc tagOperandsLoc;
  (void)tagOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand rankRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> rankOperands(&rankRawOperand, 1);  ::llvm::SMLoc rankOperandsLoc;
  (void)rankOperandsLoc;
  ::mlir::Type refRawType{};
  ::llvm::ArrayRef<::mlir::Type> refTypes(&refRawType, 1);
  ::mlir::Type tagRawType{};
  ::llvm::ArrayRef<::mlir::Type> tagTypes(&tagRawType, 1);
  ::mlir::Type rankRawType{};
  ::llvm::ArrayRef<::mlir::Type> rankTypes(&rankRawType, 1);
  ::llvm::SmallVector<::mlir::Type, 1> allResultTypes;
  if (parser.parseLParen())
    return ::mlir::failure();

  refOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(refRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  tagOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(tagRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  rankOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(rankRawOperand))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::MemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    refRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    tagRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    rankRawType = type;
  }
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseTypeList(allResultTypes))
    return ::mlir::failure();
  result.addTypes(allResultTypes);
  if (parser.resolveOperands(refOperands, refTypes, refOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(tagOperands, tagTypes, tagOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(rankOperands, rankTypes, rankOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void IRecvOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getRef();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getTag();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getRank();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getRef().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::MemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getTag().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getRank().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ' ' << "->";
  _odsPrinter << ' ';
  _odsPrinter << getOperation()->getResultTypes();
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::IRecvOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::ISendOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
ISendOpAdaptor::ISendOpAdaptor(ISendOp op) : ISendOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ISendOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void ISendOp::getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn) {
  auto resultGroup0 = getODSResults(0);
  if (!resultGroup0.empty())
    setNameFn(*resultGroup0.begin(), "retval");
  auto resultGroup1 = getODSResults(1);
  if (!resultGroup1.empty())
    setNameFn(*resultGroup1.begin(), "req");
}

std::pair<unsigned, unsigned> ISendOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true, false};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void ISendOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Type req, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  if (retval)
    odsState.addTypes(retval);
  odsState.addTypes(req);
}

void ISendOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  assert(resultTypes.size() >= 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ISendOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() >= 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult ISendOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSResults(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps4(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult ISendOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult ISendOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand refRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> refOperands(&refRawOperand, 1);  ::llvm::SMLoc refOperandsLoc;
  (void)refOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand tagRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> tagOperands(&tagRawOperand, 1);  ::llvm::SMLoc tagOperandsLoc;
  (void)tagOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand rankRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> rankOperands(&rankRawOperand, 1);  ::llvm::SMLoc rankOperandsLoc;
  (void)rankOperandsLoc;
  ::mlir::Type refRawType{};
  ::llvm::ArrayRef<::mlir::Type> refTypes(&refRawType, 1);
  ::mlir::Type tagRawType{};
  ::llvm::ArrayRef<::mlir::Type> tagTypes(&tagRawType, 1);
  ::mlir::Type rankRawType{};
  ::llvm::ArrayRef<::mlir::Type> rankTypes(&rankRawType, 1);
  ::llvm::SmallVector<::mlir::Type, 1> allResultTypes;
  if (parser.parseLParen())
    return ::mlir::failure();

  refOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(refRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  tagOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(tagRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  rankOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(rankRawOperand))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::MemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    refRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    tagRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    rankRawType = type;
  }
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseTypeList(allResultTypes))
    return ::mlir::failure();
  result.addTypes(allResultTypes);
  if (parser.resolveOperands(refOperands, refTypes, refOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(tagOperands, tagTypes, tagOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(rankOperands, rankTypes, rankOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ISendOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getRef();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getTag();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getRank();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getRef().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::MemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getTag().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getRank().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ' ' << "->";
  _odsPrinter << ' ';
  _odsPrinter << getOperation()->getResultTypes();
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::ISendOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::InitOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
InitOpAdaptor::InitOpAdaptor(InitOp op) : InitOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult InitOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> InitOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void InitOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval) {
  if (retval)
    odsState.addTypes(retval);
}

void InitOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  odsState.addTypes(resultTypes);
}

void InitOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult InitOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult InitOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult InitOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (::mlir::succeeded(parser.parseOptionalColon())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  return ::mlir::success();
}

void InitOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  if (getRetval()) {
    _odsPrinter << ' ' << ":";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::InitOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::RecvOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
RecvOpAdaptor::RecvOpAdaptor(RecvOp op) : RecvOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult RecvOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> RecvOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void RecvOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  if (retval)
    odsState.addTypes(retval);
}

void RecvOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  odsState.addTypes(resultTypes);
}

void RecvOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult RecvOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult RecvOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult RecvOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand refRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> refOperands(&refRawOperand, 1);  ::llvm::SMLoc refOperandsLoc;
  (void)refOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand tagRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> tagOperands(&tagRawOperand, 1);  ::llvm::SMLoc tagOperandsLoc;
  (void)tagOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand rankRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> rankOperands(&rankRawOperand, 1);  ::llvm::SMLoc rankOperandsLoc;
  (void)rankOperandsLoc;
  ::mlir::Type refRawType{};
  ::llvm::ArrayRef<::mlir::Type> refTypes(&refRawType, 1);
  ::mlir::Type tagRawType{};
  ::llvm::ArrayRef<::mlir::Type> tagTypes(&tagRawType, 1);
  ::mlir::Type rankRawType{};
  ::llvm::ArrayRef<::mlir::Type> rankTypes(&rankRawType, 1);
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  if (parser.parseLParen())
    return ::mlir::failure();

  refOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(refRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  tagOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(tagRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  rankOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(rankRawOperand))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::MemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    refRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    tagRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    rankRawType = type;
  }
  if (::mlir::succeeded(parser.parseOptionalArrow())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  if (parser.resolveOperands(refOperands, refTypes, refOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(tagOperands, tagTypes, tagOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(rankOperands, rankTypes, rankOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void RecvOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getRef();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getTag();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getRank();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getRef().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::MemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getTag().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getRank().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  if (getRetval()) {
    _odsPrinter << ' ' << "->";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::RecvOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::RetvalCheckOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
RetvalCheckOpGenericAdaptorBase::RetvalCheckOpGenericAdaptorBase(RetvalCheckOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

::mlir::mpi::MPI_ErrorClassEnum RetvalCheckOpGenericAdaptorBase::getErrclass() {
  auto attr = getErrclassAttr();
  return attr.getValue();
}

} // namespace detail
RetvalCheckOpAdaptor::RetvalCheckOpAdaptor(RetvalCheckOp op) : RetvalCheckOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult RetvalCheckOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_errclass = getProperties().errclass; (void)tblgen_errclass;
  if (!tblgen_errclass) return emitError(loc, "'mpi.retval_check' op ""requires attribute 'errclass'");

  if (tblgen_errclass && !((::llvm::isa<::mlir::mpi::MPI_ErrorClassEnumAttr>(tblgen_errclass))))
    return emitError(loc, "'mpi.retval_check' op ""attribute 'errclass' failed to satisfy constraint: MPI error class name");
  return ::mlir::success();
}

::llvm::LogicalResult RetvalCheckOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.errclass;
       auto attr = dict.get("errclass");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `errclass` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute RetvalCheckOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.errclass;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("errclass",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code RetvalCheckOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.errclass.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> RetvalCheckOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "errclass")
      return prop.errclass;
  return std::nullopt;
}

void RetvalCheckOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "errclass") {
       prop.errclass = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.errclass)>>(value);
       return;
    }
}

void RetvalCheckOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.errclass) attrs.append("errclass", prop.errclass);
}

::llvm::LogicalResult RetvalCheckOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getErrclassAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MPIOps2(attr, "errclass", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult RetvalCheckOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.errclass)))
    return ::mlir::failure();
  return ::mlir::success();
}

void RetvalCheckOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.errclass);
}

::mlir::mpi::MPI_ErrorClassEnum RetvalCheckOp::getErrclass() {
  auto attr = getErrclassAttr();
  return attr.getValue();
}

void RetvalCheckOp::setErrclass(::mlir::mpi::MPI_ErrorClassEnum attrValue) {
  getProperties().errclass = ::mlir::mpi::MPI_ErrorClassEnumAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void RetvalCheckOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value val, ::mlir::mpi::MPI_ErrorClassEnumAttr errclass) {
  odsState.addOperands(val);
  odsState.getOrAddProperties<Properties>().errclass = errclass;
  odsState.addTypes(res);
}

void RetvalCheckOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value val, ::mlir::mpi::MPI_ErrorClassEnumAttr errclass) {
  odsState.addOperands(val);
  odsState.getOrAddProperties<Properties>().errclass = errclass;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void RetvalCheckOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value val, ::mlir::mpi::MPI_ErrorClassEnum errclass) {
  odsState.addOperands(val);
  odsState.getOrAddProperties<Properties>().errclass = ::mlir::mpi::MPI_ErrorClassEnumAttr::get(odsBuilder.getContext(), errclass);
  odsState.addTypes(res);
}

void RetvalCheckOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value val, ::mlir::mpi::MPI_ErrorClassEnum errclass) {
  odsState.addOperands(val);
  odsState.getOrAddProperties<Properties>().errclass = ::mlir::mpi::MPI_ErrorClassEnumAttr::get(odsBuilder.getContext(), errclass);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void RetvalCheckOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<RetvalCheckOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult RetvalCheckOp::verifyInvariantsImpl() {
  auto tblgen_errclass = getProperties().errclass; (void)tblgen_errclass;
  if (!tblgen_errclass) return emitOpError("requires attribute 'errclass'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MPIOps2(*this, tblgen_errclass, "errclass")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps5(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult RetvalCheckOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult RetvalCheckOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand valRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> valOperands(&valRawOperand, 1);  ::llvm::SMLoc valOperandsLoc;
  (void)valOperandsLoc;
  ::mlir::mpi::MPI_ErrorClassEnumAttr errclassAttr;
  ::mlir::Type resRawType{};
  ::llvm::ArrayRef<::mlir::Type> resTypes(&resRawType, 1);

  valOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(valRawOperand))
    return ::mlir::failure();
  if (parser.parseEqual())
    return ::mlir::failure();

  if (parser.parseCustomAttributeWithFallback(errclassAttr, ::mlir::Type{})) {
    return ::mlir::failure();
  }
  if (errclassAttr) result.getOrAddProperties<RetvalCheckOp::Properties>().errclass = errclassAttr;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    resRawType = type;
  }
  ::mlir::Type odsBuildableType0 = parser.getBuilder().getType<::mlir::mpi::RetvalType>();
  result.addTypes(resTypes);
  if (parser.resolveOperands(valOperands, odsBuildableType0, valOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void RetvalCheckOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getVal();
  _odsPrinter << ' ' << "=";
  _odsPrinter << ' ';
_odsPrinter.printStrippedAttrOrType(getErrclassAttr());
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("errclass");
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getRes().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::RetvalCheckOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::SendOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
SendOpAdaptor::SendOpAdaptor(SendOp op) : SendOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult SendOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> SendOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void SendOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  if (retval)
    odsState.addTypes(retval);
}

void SendOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ref, ::mlir::Value tag, ::mlir::Value rank) {
  odsState.addOperands(ref);
  odsState.addOperands(tag);
  odsState.addOperands(rank);
  odsState.addTypes(resultTypes);
}

void SendOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult SendOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult SendOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult SendOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand refRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> refOperands(&refRawOperand, 1);  ::llvm::SMLoc refOperandsLoc;
  (void)refOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand tagRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> tagOperands(&tagRawOperand, 1);  ::llvm::SMLoc tagOperandsLoc;
  (void)tagOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand rankRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> rankOperands(&rankRawOperand, 1);  ::llvm::SMLoc rankOperandsLoc;
  (void)rankOperandsLoc;
  ::mlir::Type refRawType{};
  ::llvm::ArrayRef<::mlir::Type> refTypes(&refRawType, 1);
  ::mlir::Type tagRawType{};
  ::llvm::ArrayRef<::mlir::Type> tagTypes(&tagRawType, 1);
  ::mlir::Type rankRawType{};
  ::llvm::ArrayRef<::mlir::Type> rankTypes(&rankRawType, 1);
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  if (parser.parseLParen())
    return ::mlir::failure();

  refOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(refRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  tagOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(tagRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  rankOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(rankRawOperand))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::MemRefType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    refRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    tagRawType = type;
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::mlir::IntegerType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    rankRawType = type;
  }
  if (::mlir::succeeded(parser.parseOptionalArrow())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  if (parser.resolveOperands(refOperands, refTypes, refOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(tagOperands, tagTypes, tagOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(rankOperands, rankTypes, rankOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void SendOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getRef();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getTag();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getRank();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getRef().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::MemRefType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getTag().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  {
    auto type = getRank().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::IntegerType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  if (getRetval()) {
    _odsPrinter << ' ' << "->";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::SendOp)

namespace mlir {
namespace mpi {

//===----------------------------------------------------------------------===//
// ::mlir::mpi::Wait definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
WaitAdaptor::WaitAdaptor(Wait op) : WaitGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult WaitAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

std::pair<unsigned, unsigned> Wait::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

void Wait::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type retval, ::mlir::Value req) {
  odsState.addOperands(req);
  if (retval)
    odsState.addTypes(retval);
}

void Wait::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value req) {
  odsState.addOperands(req);
  odsState.addTypes(resultTypes);
}

void Wait::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult Wait::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps4(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    if (valueGroup0.size() > 1) {
      return emitOpError("result group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup0.size();
    }

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MPIOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult Wait::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult Wait::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand reqRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> reqOperands(&reqRawOperand, 1);  ::llvm::SMLoc reqOperandsLoc;
  (void)reqOperandsLoc;
  ::mlir::Type reqRawType{};
  ::llvm::ArrayRef<::mlir::Type> reqTypes(&reqRawType, 1);
  ::llvm::SmallVector<::mlir::Type, 1> retvalTypes;
  if (parser.parseLParen())
    return ::mlir::failure();

  reqOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(reqRawOperand))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::mpi::RequestType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    reqRawType = type;
  }
  if (::mlir::succeeded(parser.parseOptionalArrow())) {

  {
    ::mlir::Type optionalType;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalType(optionalType);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      retvalTypes.push_back(optionalType);
    }
  }
  }
  result.addTypes(retvalTypes);
  if (parser.resolveOperands(reqOperands, reqTypes, reqOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void Wait::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getReq();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getReq().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::mpi::RequestType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  if (getRetval()) {
    _odsPrinter << ' ' << "->";
    _odsPrinter << ' ';
    _odsPrinter << (getRetval() ? ::llvm::ArrayRef<::mlir::Type>(getRetval().getType()) : ::llvm::ArrayRef<::mlir::Type>());
  }
}

} // namespace mpi
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::Wait)


#endif  // GET_OP_CLASSES

