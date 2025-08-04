/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: VCIXOps.td                                                           *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::vcix::BinaryImmOp,
::mlir::vcix::BinaryOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace vcix {

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_VCIXOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::mlir::LLVM::isCompatibleVectorType(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be LLVM dialect-compatible vector type, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_VCIXOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((type.isSignlessInteger(64))) || ((type.isSignlessInteger(32))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 64-bit signless integer or 32-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_VCIXOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::mlir::LLVM::isCompatibleVectorType(type))) || ((type.isSignlessInteger(64))) || ((type.isSignlessInteger(32))) || ((type.isF16())) || ((type.isF32())) || ((type.isF64())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be LLVM dialect-compatible vector type or 64-bit signless integer or 32-bit signless integer or 16-bit float or 32-bit float or 64-bit float, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_VCIXOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) || (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(64))))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit signless integer attribute or 64-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_VCIXOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_VCIXOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
} // namespace vcix
} // namespace mlir
namespace mlir {
namespace vcix {

//===----------------------------------------------------------------------===//
// ::mlir::vcix::BinaryImmOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
BinaryImmOpGenericAdaptorBase::BinaryImmOpGenericAdaptorBase(BinaryImmOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

std::pair<unsigned, unsigned> BinaryImmOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Attribute BinaryImmOpGenericAdaptorBase::getOpcode() {
  auto attr = getOpcodeAttr();
  return attr;
}

::mlir::Attribute BinaryImmOpGenericAdaptorBase::getImm() {
  auto attr = getImmAttr();
  return attr;
}

} // namespace detail
BinaryImmOpAdaptor::BinaryImmOpAdaptor(BinaryImmOp op) : BinaryImmOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult BinaryImmOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_imm = getProperties().imm; (void)tblgen_imm;
  if (!tblgen_imm) return emitError(loc, "'vcix.v.iv' op ""requires attribute 'imm'");
  auto tblgen_opcode = getProperties().opcode; (void)tblgen_opcode;
  if (!tblgen_opcode) return emitError(loc, "'vcix.v.iv' op ""requires attribute 'opcode'");

  if (tblgen_opcode && !((((::llvm::isa<::mlir::IntegerAttr>(tblgen_opcode))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_opcode).getType().isSignlessInteger(32)))) || (((::llvm::isa<::mlir::IntegerAttr>(tblgen_opcode))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_opcode).getType().isSignlessInteger(64))))))
    return emitError(loc, "'vcix.v.iv' op ""attribute 'opcode' failed to satisfy constraint: 32-bit signless integer attribute or 64-bit signless integer attribute");

  if (tblgen_imm && !((((::llvm::isa<::mlir::IntegerAttr>(tblgen_imm))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_imm).getType().isSignlessInteger(32)))) || (((::llvm::isa<::mlir::IntegerAttr>(tblgen_imm))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_imm).getType().isSignlessInteger(64))))))
    return emitError(loc, "'vcix.v.iv' op ""attribute 'imm' failed to satisfy constraint: 32-bit signless integer attribute or 64-bit signless integer attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> BinaryImmOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::MutableOperandRange BinaryImmOp::getVlMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::llvm::LogicalResult BinaryImmOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.imm;
       auto attr = dict.get("imm");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `imm` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.opcode;
       auto attr = dict.get("opcode");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `opcode` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute BinaryImmOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.imm;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("imm",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.opcode;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("opcode",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code BinaryImmOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.imm.getAsOpaquePointer()), 
    llvm::hash_value(prop.opcode.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> BinaryImmOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "imm")
      return prop.imm;

    if (name == "opcode")
      return prop.opcode;
  return std::nullopt;
}

void BinaryImmOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "imm") {
       prop.imm = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.imm)>>(value);
       return;
    }

    if (name == "opcode") {
       prop.opcode = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.opcode)>>(value);
       return;
    }
}

void BinaryImmOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.imm) attrs.append("imm", prop.imm);

    if (prop.opcode) attrs.append("opcode", prop.opcode);
}

::llvm::LogicalResult BinaryImmOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getImmAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_VCIXOps1(attr, "imm", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getOpcodeAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_VCIXOps1(attr, "opcode", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult BinaryImmOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.imm)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.opcode)))
    return ::mlir::failure();
  return ::mlir::success();
}

void BinaryImmOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.imm);
  writer.writeAttribute(prop.opcode);
}

::mlir::Attribute BinaryImmOp::getOpcode() {
  auto attr = getOpcodeAttr();
  return attr;
}

::mlir::Attribute BinaryImmOp::getImm() {
  auto attr = getImmAttr();
  return attr;
}

void BinaryImmOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Attribute opcode, ::mlir::Value vs2, ::mlir::Attribute imm, /*optional*/::mlir::Value vl) {
  odsState.addOperands(vs2);
  if (vl)
    odsState.addOperands(vl);
  odsState.getOrAddProperties<Properties>().opcode = opcode;
  odsState.getOrAddProperties<Properties>().imm = imm;
  odsState.addTypes(res);
}

void BinaryImmOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Attribute opcode, ::mlir::Value vs2, ::mlir::Attribute imm, /*optional*/::mlir::Value vl) {
  odsState.addOperands(vs2);
  if (vl)
    odsState.addOperands(vl);
  odsState.getOrAddProperties<Properties>().opcode = opcode;
  odsState.getOrAddProperties<Properties>().imm = imm;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void BinaryImmOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<BinaryImmOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult BinaryImmOp::verifyInvariantsImpl() {
  auto tblgen_imm = getProperties().imm; (void)tblgen_imm;
  if (!tblgen_imm) return emitOpError("requires attribute 'imm'");
  auto tblgen_opcode = getProperties().opcode; (void)tblgen_opcode;
  if (!tblgen_opcode) return emitOpError("requires attribute 'opcode'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_VCIXOps1(*this, tblgen_opcode, "opcode")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_VCIXOps1(*this, tblgen_imm, "imm")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    if (valueGroup1.size() > 1) {
      return emitOpError("operand group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup1.size();
    }

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult BinaryImmOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace vcix
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::vcix::BinaryImmOp)

namespace mlir {
namespace vcix {

//===----------------------------------------------------------------------===//
// ::mlir::vcix::BinaryOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
BinaryOpGenericAdaptorBase::BinaryOpGenericAdaptorBase(BinaryOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

std::pair<unsigned, unsigned> BinaryOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Attribute BinaryOpGenericAdaptorBase::getOpcode() {
  auto attr = getOpcodeAttr();
  return attr;
}

} // namespace detail
BinaryOpAdaptor::BinaryOpAdaptor(BinaryOp op) : BinaryOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult BinaryOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_opcode = getProperties().opcode; (void)tblgen_opcode;
  if (!tblgen_opcode) return emitError(loc, "'vcix.v.sv' op ""requires attribute 'opcode'");

  if (tblgen_opcode && !((((::llvm::isa<::mlir::IntegerAttr>(tblgen_opcode))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_opcode).getType().isSignlessInteger(32)))) || (((::llvm::isa<::mlir::IntegerAttr>(tblgen_opcode))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_opcode).getType().isSignlessInteger(64))))))
    return emitError(loc, "'vcix.v.sv' op ""attribute 'opcode' failed to satisfy constraint: 32-bit signless integer attribute or 64-bit signless integer attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> BinaryOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 2) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::MutableOperandRange BinaryOp::getVlMutable() {
  auto range = getODSOperandIndexAndLength(2);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::llvm::LogicalResult BinaryOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.opcode;
       auto attr = dict.get("opcode");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `opcode` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute BinaryOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.opcode;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("opcode",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code BinaryOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.opcode.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> BinaryOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "opcode")
      return prop.opcode;
  return std::nullopt;
}

void BinaryOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "opcode") {
       prop.opcode = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.opcode)>>(value);
       return;
    }
}

void BinaryOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.opcode) attrs.append("opcode", prop.opcode);
}

::llvm::LogicalResult BinaryOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getOpcodeAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_VCIXOps1(attr, "opcode", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult BinaryOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.opcode)))
    return ::mlir::failure();
  return ::mlir::success();
}

void BinaryOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.opcode);
}

::mlir::Attribute BinaryOp::getOpcode() {
  auto attr = getOpcodeAttr();
  return attr;
}

void BinaryOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Attribute opcode, ::mlir::Value vs2, ::mlir::Value op, /*optional*/::mlir::Value vl) {
  odsState.addOperands(vs2);
  odsState.addOperands(op);
  if (vl)
    odsState.addOperands(vl);
  odsState.getOrAddProperties<Properties>().opcode = opcode;
  odsState.addTypes(res);
}

void BinaryOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Attribute opcode, ::mlir::Value vs2, ::mlir::Value op, /*optional*/::mlir::Value vl) {
  odsState.addOperands(vs2);
  odsState.addOperands(op);
  if (vl)
    odsState.addOperands(vl);
  odsState.getOrAddProperties<Properties>().opcode = opcode;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void BinaryOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<BinaryOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult BinaryOp::verifyInvariantsImpl() {
  auto tblgen_opcode = getProperties().opcode; (void)tblgen_opcode;
  if (!tblgen_opcode) return emitOpError("requires attribute 'opcode'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_VCIXOps1(*this, tblgen_opcode, "opcode")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    if (valueGroup2.size() > 1) {
      return emitOpError("operand group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup2.size();
    }

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_VCIXOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult BinaryOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

} // namespace vcix
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::vcix::BinaryOp)


#endif  // GET_OP_CLASSES

