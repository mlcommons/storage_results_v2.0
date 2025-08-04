/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: NVGPUOps.td                                                          *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::triton::nvgpu::ClusterArriveOp,
::mlir::triton::nvgpu::ClusterCTAIdOp,
::mlir::triton::nvgpu::ClusterWaitOp,
::mlir::triton::nvgpu::FenceAsyncSharedOp,
::mlir::triton::nvgpu::LoadAcquireOp,
::mlir::triton::nvgpu::LoadMatrixOp,
::mlir::triton::nvgpu::SparseWGMMAOp,
::mlir::triton::nvgpu::StoreMatrixOp,
::mlir::triton::nvgpu::WGMMACommitGroupOp,
::mlir::triton::nvgpu::WGMMAFenceOp,
::mlir::triton::nvgpu::WGMMAOp,
::mlir::triton::nvgpu::WGMMAWaitGroupOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace triton {
namespace nvgpu {

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(32)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 32-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::LLVM::LLVMPointerType>(type))) && ((::llvm::cast<::mlir::LLVM::LLVMPointerType>(type).getAddressSpace() == 1)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be LLVM pointer in address space 1, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(1)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 1-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps4(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((((::llvm::isa<::mlir::Float8E4M3FNType>(type))) || ((::llvm::isa<::mlir::Float8E4M3FNUZType>(type))) || ((::llvm::isa<::mlir::Float8E5M2Type>(type))) || ((::llvm::isa<::mlir::Float8E5M2FNUZType>(type))) || ((type.isF16())) || ((::llvm::isa<::mlir::BFloat16Type>(type))) || ((type.isF32())) || ((type.isF64()))) || (((type.isSignlessInteger(1))) || ((type.isSignlessInteger(8))) || ((type.isSignlessInteger(16))) || ((type.isSignlessInteger(32))) || ((type.isSignlessInteger(64)))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be floating-point or integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps5(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::LLVM::LLVMPointerType>(type))) && ((::llvm::cast<::mlir::LLVM::LLVMPointerType>(type).getAddressSpace() == 3)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be LLVM pointer in address space 3, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps6(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((::llvm::isa<::mlir::LLVM::LLVMStructType>(type)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be LLVM structure type, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps7(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::LLVM::LLVMStructType>(type))) || ((type.isSignlessInteger(64))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be wgmma operand A/B type, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_NVGPUOps8(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(32)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be variadic of 32-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(1)))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 1-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps2(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::BoolAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: bool attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps2(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps2(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps3(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::triton::nvgpu::MemSemanticAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: allowed 32-bit signless integer cases: 1, 2, 3, 4";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps3(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps3(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps4(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::triton::nvgpu::MemSyncScopeAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: allowed 32-bit signless integer cases: 1, 2, 3";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps4(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps4(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps5(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::UnitAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: unit attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps5(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps5(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps6(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps6(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps6(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps7(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps7(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps7(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps8(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::triton::nvgpu::WGMMALayoutAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: wgmma layout, either 'row' or 'col'";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_NVGPUOps8(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_NVGPUOps8(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
} // namespace nvgpu
} // namespace triton
} // namespace mlir
namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::ClusterArriveOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
ClusterArriveOpGenericAdaptorBase::ClusterArriveOpGenericAdaptorBase(ClusterArriveOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

bool ClusterArriveOpGenericAdaptorBase::getRelaxed() {
  auto attr = getRelaxedAttr();
  return attr.getValue().getZExtValue();
}

} // namespace detail
ClusterArriveOpAdaptor::ClusterArriveOpAdaptor(ClusterArriveOp op) : ClusterArriveOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ClusterArriveOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_relaxed = getProperties().relaxed; (void)tblgen_relaxed;
  if (!tblgen_relaxed) return emitError(loc, "'nvgpu.cluster_arrive' op ""requires attribute 'relaxed'");

  if (tblgen_relaxed && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_relaxed))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_relaxed).getType().isSignlessInteger(1)))))
    return emitError(loc, "'nvgpu.cluster_arrive' op ""attribute 'relaxed' failed to satisfy constraint: 1-bit signless integer attribute");
  return ::mlir::success();
}

::llvm::LogicalResult ClusterArriveOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.relaxed;
       auto attr = dict.get("relaxed");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `relaxed` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute ClusterArriveOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.relaxed;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("relaxed",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code ClusterArriveOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.relaxed.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> ClusterArriveOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "relaxed")
      return prop.relaxed;
  return std::nullopt;
}

void ClusterArriveOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "relaxed") {
       prop.relaxed = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.relaxed)>>(value);
       return;
    }
}

void ClusterArriveOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.relaxed) attrs.append("relaxed", prop.relaxed);
}

::llvm::LogicalResult ClusterArriveOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getRelaxedAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps1(attr, "relaxed", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult ClusterArriveOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.relaxed)))
    return ::mlir::failure();
  return ::mlir::success();
}

void ClusterArriveOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.relaxed);
}

bool ClusterArriveOp::getRelaxed() {
  auto attr = getRelaxedAttr();
  return attr.getValue().getZExtValue();
}

void ClusterArriveOp::setRelaxed(bool attrValue) {
  getProperties().relaxed = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(1), attrValue);
}

void ClusterArriveOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::IntegerAttr relaxed) {
  odsState.getOrAddProperties<Properties>().relaxed = relaxed;
}

void ClusterArriveOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr relaxed) {
  odsState.getOrAddProperties<Properties>().relaxed = relaxed;
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ClusterArriveOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, bool relaxed) {
  odsState.getOrAddProperties<Properties>().relaxed = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(1), relaxed);
}

void ClusterArriveOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, bool relaxed) {
  odsState.getOrAddProperties<Properties>().relaxed = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(1), relaxed);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ClusterArriveOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<ClusterArriveOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult ClusterArriveOp::verifyInvariantsImpl() {
  auto tblgen_relaxed = getProperties().relaxed; (void)tblgen_relaxed;
  if (!tblgen_relaxed) return emitOpError("requires attribute 'relaxed'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps1(*this, tblgen_relaxed, "relaxed")))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::LogicalResult ClusterArriveOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult ClusterArriveOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void ClusterArriveOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::ClusterArriveOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::ClusterCTAIdOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
ClusterCTAIdOpAdaptor::ClusterCTAIdOpAdaptor(ClusterCTAIdOp op) : ClusterCTAIdOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ClusterCTAIdOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void ClusterCTAIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result) {
  odsState.addTypes(result);
}

void ClusterCTAIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState) {
        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(ClusterCTAIdOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::mlir::detail::reportFatalInferReturnTypesError(odsState);
        
}

void ClusterCTAIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ClusterCTAIdOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

void ClusterCTAIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(ClusterCTAIdOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

::llvm::LogicalResult ClusterCTAIdOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult ClusterCTAIdOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::llvm::LogicalResult ClusterCTAIdOp::inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes) {
  inferredReturnTypes.resize(1);
  ::mlir::Builder odsBuilder(context);
  ::mlir::Type odsInferredType0 = odsBuilder.getIntegerType(32);
  inferredReturnTypes[0] = odsInferredType0;
  return ::mlir::success();
}

::mlir::ParseResult ClusterCTAIdOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  ::mlir::Type odsBuildableType0 = parser.getBuilder().getIntegerType(32);
  result.addTypes(odsBuildableType0);
  return ::mlir::success();
}

void ClusterCTAIdOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

void ClusterCTAIdOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::ClusterCTAIdOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::ClusterWaitOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
ClusterWaitOpAdaptor::ClusterWaitOpAdaptor(ClusterWaitOp op) : ClusterWaitOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ClusterWaitOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void ClusterWaitOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState) {
}

void ClusterWaitOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ClusterWaitOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult ClusterWaitOp::verifyInvariantsImpl() {
  return ::mlir::success();
}

::llvm::LogicalResult ClusterWaitOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult ClusterWaitOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void ClusterWaitOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::ClusterWaitOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::FenceAsyncSharedOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
FenceAsyncSharedOpGenericAdaptorBase::FenceAsyncSharedOpGenericAdaptorBase(FenceAsyncSharedOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

bool FenceAsyncSharedOpGenericAdaptorBase::getBCluster() {
  auto attr = getBClusterAttr();
  return attr.getValue();
}

} // namespace detail
FenceAsyncSharedOpAdaptor::FenceAsyncSharedOpAdaptor(FenceAsyncSharedOp op) : FenceAsyncSharedOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult FenceAsyncSharedOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_bCluster = getProperties().bCluster; (void)tblgen_bCluster;
  if (!tblgen_bCluster) return emitError(loc, "'nvgpu.fence_async_shared' op ""requires attribute 'bCluster'");

  if (tblgen_bCluster && !((::llvm::isa<::mlir::BoolAttr>(tblgen_bCluster))))
    return emitError(loc, "'nvgpu.fence_async_shared' op ""attribute 'bCluster' failed to satisfy constraint: bool attribute");
  return ::mlir::success();
}

::llvm::LogicalResult FenceAsyncSharedOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.bCluster;
       auto attr = dict.get("bCluster");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `bCluster` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute FenceAsyncSharedOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.bCluster;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("bCluster",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code FenceAsyncSharedOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.bCluster.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> FenceAsyncSharedOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "bCluster")
      return prop.bCluster;
  return std::nullopt;
}

void FenceAsyncSharedOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "bCluster") {
       prop.bCluster = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.bCluster)>>(value);
       return;
    }
}

void FenceAsyncSharedOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.bCluster) attrs.append("bCluster", prop.bCluster);
}

::llvm::LogicalResult FenceAsyncSharedOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getBClusterAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps2(attr, "bCluster", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult FenceAsyncSharedOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.bCluster)))
    return ::mlir::failure();
  return ::mlir::success();
}

void FenceAsyncSharedOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.bCluster);
}

bool FenceAsyncSharedOp::getBCluster() {
  auto attr = getBClusterAttr();
  return attr.getValue();
}

void FenceAsyncSharedOp::setBCluster(bool attrValue) {
  getProperties().bCluster = ::mlir::Builder((*this)->getContext()).getBoolAttr(attrValue);
}

void FenceAsyncSharedOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::BoolAttr bCluster) {
  odsState.getOrAddProperties<Properties>().bCluster = bCluster;
}

void FenceAsyncSharedOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::BoolAttr bCluster) {
  odsState.getOrAddProperties<Properties>().bCluster = bCluster;
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void FenceAsyncSharedOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, bool bCluster) {
  odsState.getOrAddProperties<Properties>().bCluster = odsBuilder.getBoolAttr(bCluster);
}

void FenceAsyncSharedOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, bool bCluster) {
  odsState.getOrAddProperties<Properties>().bCluster = odsBuilder.getBoolAttr(bCluster);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void FenceAsyncSharedOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<FenceAsyncSharedOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult FenceAsyncSharedOp::verifyInvariantsImpl() {
  auto tblgen_bCluster = getProperties().bCluster; (void)tblgen_bCluster;
  if (!tblgen_bCluster) return emitOpError("requires attribute 'bCluster'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps2(*this, tblgen_bCluster, "bCluster")))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::LogicalResult FenceAsyncSharedOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult FenceAsyncSharedOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void FenceAsyncSharedOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::FenceAsyncSharedOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::LoadAcquireOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
LoadAcquireOpGenericAdaptorBase::LoadAcquireOpGenericAdaptorBase(LoadAcquireOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

std::pair<unsigned, unsigned> LoadAcquireOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
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

::mlir::triton::nvgpu::MemSemantic LoadAcquireOpGenericAdaptorBase::getSem() {
  auto attr = getSemAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::MemSyncScope LoadAcquireOpGenericAdaptorBase::getScope() {
  auto attr = getScopeAttr();
  return attr.getValue();
}

} // namespace detail
LoadAcquireOpAdaptor::LoadAcquireOpAdaptor(LoadAcquireOp op) : LoadAcquireOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult LoadAcquireOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_scope = getProperties().scope; (void)tblgen_scope;
  if (!tblgen_scope) return emitError(loc, "'nvgpu.ld_acquire' op ""requires attribute 'scope'");
  auto tblgen_sem = getProperties().sem; (void)tblgen_sem;
  if (!tblgen_sem) return emitError(loc, "'nvgpu.ld_acquire' op ""requires attribute 'sem'");

  if (tblgen_sem && !((::llvm::isa<::mlir::triton::nvgpu::MemSemanticAttr>(tblgen_sem))))
    return emitError(loc, "'nvgpu.ld_acquire' op ""attribute 'sem' failed to satisfy constraint: allowed 32-bit signless integer cases: 1, 2, 3, 4");

  if (tblgen_scope && !((::llvm::isa<::mlir::triton::nvgpu::MemSyncScopeAttr>(tblgen_scope))))
    return emitError(loc, "'nvgpu.ld_acquire' op ""attribute 'scope' failed to satisfy constraint: allowed 32-bit signless integer cases: 1, 2, 3");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> LoadAcquireOp::getODSOperandIndexAndLength(unsigned index) {
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

::mlir::MutableOperandRange LoadAcquireOp::getMaskMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::llvm::LogicalResult LoadAcquireOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.scope;
       auto attr = dict.get("scope");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `scope` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.sem;
       auto attr = dict.get("sem");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `sem` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute LoadAcquireOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.scope;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("scope",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.sem;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("sem",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code LoadAcquireOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.scope.getAsOpaquePointer()), 
    llvm::hash_value(prop.sem.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> LoadAcquireOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "scope")
      return prop.scope;

    if (name == "sem")
      return prop.sem;
  return std::nullopt;
}

void LoadAcquireOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "scope") {
       prop.scope = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.scope)>>(value);
       return;
    }

    if (name == "sem") {
       prop.sem = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.sem)>>(value);
       return;
    }
}

void LoadAcquireOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.scope) attrs.append("scope", prop.scope);

    if (prop.sem) attrs.append("sem", prop.sem);
}

::llvm::LogicalResult LoadAcquireOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getScopeAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps4(attr, "scope", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getSemAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps3(attr, "sem", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult LoadAcquireOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.scope)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.sem)))
    return ::mlir::failure();
  return ::mlir::success();
}

void LoadAcquireOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.scope);
  writer.writeAttribute(prop.sem);
}

::mlir::triton::nvgpu::MemSemantic LoadAcquireOp::getSem() {
  auto attr = getSemAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::MemSyncScope LoadAcquireOp::getScope() {
  auto attr = getScopeAttr();
  return attr.getValue();
}

void LoadAcquireOp::setSem(::mlir::triton::nvgpu::MemSemantic attrValue) {
  getProperties().sem = ::mlir::triton::nvgpu::MemSemanticAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void LoadAcquireOp::setScope(::mlir::triton::nvgpu::MemSyncScope attrValue) {
  getProperties().scope = ::mlir::triton::nvgpu::MemSyncScopeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void LoadAcquireOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value addr, /*optional*/::mlir::Value mask, ::mlir::triton::nvgpu::MemSemanticAttr sem, ::mlir::triton::nvgpu::MemSyncScopeAttr scope) {
  odsState.addOperands(addr);
  if (mask)
    odsState.addOperands(mask);
  odsState.getOrAddProperties<Properties>().sem = sem;
  odsState.getOrAddProperties<Properties>().scope = scope;
  odsState.addTypes(result);
}

void LoadAcquireOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value addr, /*optional*/::mlir::Value mask, ::mlir::triton::nvgpu::MemSemanticAttr sem, ::mlir::triton::nvgpu::MemSyncScopeAttr scope) {
  odsState.addOperands(addr);
  if (mask)
    odsState.addOperands(mask);
  odsState.getOrAddProperties<Properties>().sem = sem;
  odsState.getOrAddProperties<Properties>().scope = scope;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void LoadAcquireOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value addr, /*optional*/::mlir::Value mask, ::mlir::triton::nvgpu::MemSemantic sem, ::mlir::triton::nvgpu::MemSyncScope scope) {
  odsState.addOperands(addr);
  if (mask)
    odsState.addOperands(mask);
  odsState.getOrAddProperties<Properties>().sem = ::mlir::triton::nvgpu::MemSemanticAttr::get(odsBuilder.getContext(), sem);
  odsState.getOrAddProperties<Properties>().scope = ::mlir::triton::nvgpu::MemSyncScopeAttr::get(odsBuilder.getContext(), scope);
  odsState.addTypes(result);
}

void LoadAcquireOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value addr, /*optional*/::mlir::Value mask, ::mlir::triton::nvgpu::MemSemantic sem, ::mlir::triton::nvgpu::MemSyncScope scope) {
  odsState.addOperands(addr);
  if (mask)
    odsState.addOperands(mask);
  odsState.getOrAddProperties<Properties>().sem = ::mlir::triton::nvgpu::MemSemanticAttr::get(odsBuilder.getContext(), sem);
  odsState.getOrAddProperties<Properties>().scope = ::mlir::triton::nvgpu::MemSyncScopeAttr::get(odsBuilder.getContext(), scope);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void LoadAcquireOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<LoadAcquireOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult LoadAcquireOp::verifyInvariantsImpl() {
  auto tblgen_scope = getProperties().scope; (void)tblgen_scope;
  if (!tblgen_scope) return emitOpError("requires attribute 'scope'");
  auto tblgen_sem = getProperties().sem; (void)tblgen_sem;
  if (!tblgen_sem) return emitOpError("requires attribute 'sem'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps3(*this, tblgen_sem, "sem")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps4(*this, tblgen_scope, "scope")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    if (valueGroup1.size() > 1) {
      return emitOpError("operand group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup1.size();
    }

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps4(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult LoadAcquireOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult LoadAcquireOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::triton::nvgpu::MemSemanticAttr semAttr;
  ::mlir::triton::nvgpu::MemSyncScopeAttr scopeAttr;
  ::mlir::OpAsmParser::UnresolvedOperand addrRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> addrOperands(&addrRawOperand, 1);  ::llvm::SMLoc addrOperandsLoc;
  (void)addrOperandsLoc;
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> maskOperands;
  ::llvm::SMLoc maskOperandsLoc;
  (void)maskOperandsLoc;
  ::llvm::ArrayRef<::mlir::Type> addrTypes;
  ::llvm::ArrayRef<::mlir::Type> resultTypes;

  {
    ::llvm::StringRef attrStr;
    ::mlir::NamedAttrList attrStorage;
    auto loc = parser.getCurrentLocation();
    if (parser.parseOptionalKeyword(&attrStr, {"relaxed","acquire","release","acq_rel"})) {
      ::mlir::StringAttr attrVal;
      ::mlir::OptionalParseResult parseResult =
        parser.parseOptionalAttribute(attrVal,
                                      parser.getBuilder().getNoneType(),
                                      "sem", attrStorage);
      if (parseResult.has_value()) {
        if (failed(*parseResult))
          return ::mlir::failure();
        attrStr = attrVal.getValue();
      } else {
        return parser.emitError(loc, "expected string or keyword containing one of the following enum values for attribute 'sem' [relaxed, acquire, release, acq_rel]");
      }
    }
    if (!attrStr.empty()) {
      auto attrOptional = ::mlir::triton::nvgpu::symbolizeMemSemantic(attrStr);
      if (!attrOptional)
        return parser.emitError(loc, "invalid ")
               << "sem attribute specification: \"" << attrStr << '"';;

      semAttr = ::mlir::triton::nvgpu::MemSemanticAttr::get(parser.getBuilder().getContext(), *attrOptional);
        result.getOrAddProperties<LoadAcquireOp::Properties>().sem = semAttr;
    }
  }
  if (parser.parseComma())
    return ::mlir::failure();

  {
    ::llvm::StringRef attrStr;
    ::mlir::NamedAttrList attrStorage;
    auto loc = parser.getCurrentLocation();
    if (parser.parseOptionalKeyword(&attrStr, {"gpu","cta","sys"})) {
      ::mlir::StringAttr attrVal;
      ::mlir::OptionalParseResult parseResult =
        parser.parseOptionalAttribute(attrVal,
                                      parser.getBuilder().getNoneType(),
                                      "scope", attrStorage);
      if (parseResult.has_value()) {
        if (failed(*parseResult))
          return ::mlir::failure();
        attrStr = attrVal.getValue();
      } else {
        return parser.emitError(loc, "expected string or keyword containing one of the following enum values for attribute 'scope' [gpu, cta, sys]");
      }
    }
    if (!attrStr.empty()) {
      auto attrOptional = ::mlir::triton::nvgpu::symbolizeMemSyncScope(attrStr);
      if (!attrOptional)
        return parser.emitError(loc, "invalid ")
               << "scope attribute specification: \"" << attrStr << '"';;

      scopeAttr = ::mlir::triton::nvgpu::MemSyncScopeAttr::get(parser.getBuilder().getContext(), *attrOptional);
        result.getOrAddProperties<LoadAcquireOp::Properties>().scope = scopeAttr;
    }
  }
  if (parser.parseComma())
    return ::mlir::failure();

  addrOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(addrRawOperand))
    return ::mlir::failure();
  if (::mlir::succeeded(parser.parseOptionalComma())) {

  {
    maskOperandsLoc = parser.getCurrentLocation();
    ::mlir::OpAsmParser::UnresolvedOperand operand;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalOperand(operand);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      maskOperands.push_back(operand);
    }
  }
  }
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

  ::mlir::FunctionType addr__result_functionType;
  if (parser.parseType(addr__result_functionType))
    return ::mlir::failure();
  addrTypes = addr__result_functionType.getInputs();
  resultTypes = addr__result_functionType.getResults();
  ::mlir::Type odsBuildableType0 = parser.getBuilder().getIntegerType(1);
  result.addTypes(resultTypes);
  if (parser.resolveOperands(addrOperands, addrTypes, addrOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(maskOperands, odsBuildableType0, maskOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void LoadAcquireOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';

  {
    auto caseValue = getSem();
    auto caseValueStr = stringifyMemSemantic(caseValue);
    _odsPrinter << caseValueStr;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';

  {
    auto caseValue = getScope();
    auto caseValueStr = stringifyMemSyncScope(caseValue);
    _odsPrinter << caseValueStr;
  }
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getAddr();
  if (getMask()) {
    _odsPrinter << ",";
    _odsPrinter << ' ';
    if (::mlir::Value value = getMask())
      _odsPrinter << value;
  }
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("sem");
  elidedAttrs.push_back("scope");
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter.printFunctionalType(::llvm::ArrayRef<::mlir::Type>(getAddr().getType()), ::llvm::ArrayRef<::mlir::Type>(getResult().getType()));
}

void LoadAcquireOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  effects.emplace_back(::mlir::MemoryEffects::Read::get(), 0, false, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::LoadAcquireOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::LoadMatrixOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
LoadMatrixOpGenericAdaptorBase::LoadMatrixOpGenericAdaptorBase(LoadMatrixOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

::mlir::UnitAttr LoadMatrixOpGenericAdaptorBase::getTransAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().trans);
  if (!attr)
    attr = ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr);
  return attr;
}

bool LoadMatrixOpGenericAdaptorBase::getTrans() {
  auto attr = getTransAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

} // namespace detail
LoadMatrixOpAdaptor::LoadMatrixOpAdaptor(LoadMatrixOp op) : LoadMatrixOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult LoadMatrixOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_trans = getProperties().trans; (void)tblgen_trans;

  if (tblgen_trans && !((::llvm::isa<::mlir::UnitAttr>(tblgen_trans))))
    return emitError(loc, "'nvgpu.ldmatrix' op ""attribute 'trans' failed to satisfy constraint: unit attribute");
  return ::mlir::success();
}

::llvm::LogicalResult LoadMatrixOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.trans;
       auto attr = dict.get("trans");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `trans` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute LoadMatrixOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.trans;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("trans",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code LoadMatrixOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.trans.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> LoadMatrixOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "trans")
      return prop.trans;
  return std::nullopt;
}

void LoadMatrixOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "trans") {
       prop.trans = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.trans)>>(value);
       return;
    }
}

void LoadMatrixOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.trans) attrs.append("trans", prop.trans);
}

::llvm::LogicalResult LoadMatrixOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getTransAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps5(attr, "trans", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult LoadMatrixOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readOptionalAttribute(prop.trans)))
    return ::mlir::failure();
  return ::mlir::success();
}

void LoadMatrixOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  writer.writeOptionalAttribute(prop.trans);
}

bool LoadMatrixOp::getTrans() {
  auto attr = getTransAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

void LoadMatrixOp::setTrans(bool attrValue) {
    auto &odsProp = getProperties().trans;
    if (attrValue)
      odsProp = ((attrValue) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr);
    else
      odsProp = nullptr;
}

void LoadMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value addr, /*optional*/::mlir::UnitAttr trans) {
  odsState.addOperands(addr);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = trans;
  }
  odsState.addTypes(result);
}

void LoadMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value addr, /*optional*/::mlir::UnitAttr trans) {
  odsState.addOperands(addr);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = trans;
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void LoadMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value addr, /*optional*/bool trans) {
  odsState.addOperands(addr);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = ((trans) ? odsBuilder.getUnitAttr() : nullptr);
  }
  odsState.addTypes(result);
}

void LoadMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value addr, /*optional*/bool trans) {
  odsState.addOperands(addr);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = ((trans) ? odsBuilder.getUnitAttr() : nullptr);
  }
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void LoadMatrixOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<LoadMatrixOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult LoadMatrixOp::verifyInvariantsImpl() {
  auto tblgen_trans = getProperties().trans; (void)tblgen_trans;

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps5(*this, tblgen_trans, "trans")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps5(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult LoadMatrixOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult LoadMatrixOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand addrRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> addrOperands(&addrRawOperand, 1);  ::llvm::SMLoc addrOperandsLoc;
  (void)addrOperandsLoc;
  ::llvm::ArrayRef<::mlir::Type> addrTypes;
  ::llvm::ArrayRef<::mlir::Type> resultTypes;

  addrOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(addrRawOperand))
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

  ::mlir::FunctionType addr__result_functionType;
  if (parser.parseType(addr__result_functionType))
    return ::mlir::failure();
  addrTypes = addr__result_functionType.getInputs();
  resultTypes = addr__result_functionType.getResults();
  result.addTypes(resultTypes);
  if (parser.resolveOperands(addrOperands, addrTypes, addrOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void LoadMatrixOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getAddr();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getTransAttr();
     if(attr && (attr == ((false) ? odsBuilder.getUnitAttr() : nullptr)))
       elidedAttrs.push_back("trans");
  }
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter.printFunctionalType(::llvm::ArrayRef<::mlir::Type>(getAddr().getType()), ::llvm::ArrayRef<::mlir::Type>(getResult().getType()));
}

void LoadMatrixOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  effects.emplace_back(::mlir::MemoryEffects::Read::get(), 0, false, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::LoadMatrixOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::SparseWGMMAOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
SparseWGMMAOpGenericAdaptorBase::SparseWGMMAOpGenericAdaptorBase(SparseWGMMAOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

uint32_t SparseWGMMAOpGenericAdaptorBase::getM() {
  auto attr = getMAttr();
  return attr.getValue().getZExtValue();
}

uint32_t SparseWGMMAOpGenericAdaptorBase::getN() {
  auto attr = getNAttr();
  return attr.getValue().getZExtValue();
}

uint32_t SparseWGMMAOpGenericAdaptorBase::getK() {
  auto attr = getKAttr();
  return attr.getValue().getZExtValue();
}

::mlir::triton::nvgpu::WGMMAEltType SparseWGMMAOpGenericAdaptorBase::getEltTypeC() {
  auto attr = getEltTypeCAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType SparseWGMMAOpGenericAdaptorBase::getEltTypeA() {
  auto attr = getEltTypeAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType SparseWGMMAOpGenericAdaptorBase::getEltTypeB() {
  auto attr = getEltTypeBAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout SparseWGMMAOpGenericAdaptorBase::getLayoutA() {
  auto attr = getLayoutAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout SparseWGMMAOpGenericAdaptorBase::getLayoutB() {
  auto attr = getLayoutBAttr();
  return attr.getValue();
}

} // namespace detail
SparseWGMMAOpAdaptor::SparseWGMMAOpAdaptor(SparseWGMMAOp op) : SparseWGMMAOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult SparseWGMMAOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_eltTypeA = getProperties().eltTypeA; (void)tblgen_eltTypeA;
  if (!tblgen_eltTypeA) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'eltTypeA'");
  auto tblgen_eltTypeB = getProperties().eltTypeB; (void)tblgen_eltTypeB;
  if (!tblgen_eltTypeB) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'eltTypeB'");
  auto tblgen_eltTypeC = getProperties().eltTypeC; (void)tblgen_eltTypeC;
  if (!tblgen_eltTypeC) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'eltTypeC'");
  auto tblgen_k = getProperties().k; (void)tblgen_k;
  if (!tblgen_k) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'k'");
  auto tblgen_layoutA = getProperties().layoutA; (void)tblgen_layoutA;
  if (!tblgen_layoutA) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'layoutA'");
  auto tblgen_layoutB = getProperties().layoutB; (void)tblgen_layoutB;
  if (!tblgen_layoutB) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'layoutB'");
  auto tblgen_m = getProperties().m; (void)tblgen_m;
  if (!tblgen_m) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'm'");
  auto tblgen_n = getProperties().n; (void)tblgen_n;
  if (!tblgen_n) return emitError(loc, "'nvgpu.wgmma_sp' op ""requires attribute 'n'");

  if (tblgen_m && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_m))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_m).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'm' failed to satisfy constraint: 32-bit signless integer attribute");

  if (tblgen_n && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_n))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_n).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'n' failed to satisfy constraint: 32-bit signless integer attribute");

  if (tblgen_k && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_k))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_k).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'k' failed to satisfy constraint: 32-bit signless integer attribute");

  if (tblgen_eltTypeC && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(tblgen_eltTypeC))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'eltTypeC' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

  if (tblgen_eltTypeA && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(tblgen_eltTypeA))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'eltTypeA' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

  if (tblgen_eltTypeB && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(tblgen_eltTypeB))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'eltTypeB' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

  if (tblgen_layoutA && !((::llvm::isa<::mlir::triton::nvgpu::WGMMALayoutAttr>(tblgen_layoutA))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'layoutA' failed to satisfy constraint: wgmma layout, either 'row' or 'col'");

  if (tblgen_layoutB && !((::llvm::isa<::mlir::triton::nvgpu::WGMMALayoutAttr>(tblgen_layoutB))))
    return emitError(loc, "'nvgpu.wgmma_sp' op ""attribute 'layoutB' failed to satisfy constraint: wgmma layout, either 'row' or 'col'");
  return ::mlir::success();
}

::llvm::LogicalResult SparseWGMMAOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.eltTypeA;
       auto attr = dict.get("eltTypeA");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `eltTypeA` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.eltTypeB;
       auto attr = dict.get("eltTypeB");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `eltTypeB` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.eltTypeC;
       auto attr = dict.get("eltTypeC");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `eltTypeC` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.k;
       auto attr = dict.get("k");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `k` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.layoutA;
       auto attr = dict.get("layoutA");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `layoutA` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.layoutB;
       auto attr = dict.get("layoutB");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `layoutB` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.m;
       auto attr = dict.get("m");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `m` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.n;
       auto attr = dict.get("n");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `n` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute SparseWGMMAOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.eltTypeA;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("eltTypeA",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.eltTypeB;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("eltTypeB",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.eltTypeC;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("eltTypeC",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.k;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("k",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.layoutA;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("layoutA",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.layoutB;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("layoutB",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.m;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("m",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.n;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("n",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code SparseWGMMAOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.eltTypeA.getAsOpaquePointer()), 
    llvm::hash_value(prop.eltTypeB.getAsOpaquePointer()), 
    llvm::hash_value(prop.eltTypeC.getAsOpaquePointer()), 
    llvm::hash_value(prop.k.getAsOpaquePointer()), 
    llvm::hash_value(prop.layoutA.getAsOpaquePointer()), 
    llvm::hash_value(prop.layoutB.getAsOpaquePointer()), 
    llvm::hash_value(prop.m.getAsOpaquePointer()), 
    llvm::hash_value(prop.n.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> SparseWGMMAOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "eltTypeA")
      return prop.eltTypeA;

    if (name == "eltTypeB")
      return prop.eltTypeB;

    if (name == "eltTypeC")
      return prop.eltTypeC;

    if (name == "k")
      return prop.k;

    if (name == "layoutA")
      return prop.layoutA;

    if (name == "layoutB")
      return prop.layoutB;

    if (name == "m")
      return prop.m;

    if (name == "n")
      return prop.n;
  return std::nullopt;
}

void SparseWGMMAOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "eltTypeA") {
       prop.eltTypeA = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.eltTypeA)>>(value);
       return;
    }

    if (name == "eltTypeB") {
       prop.eltTypeB = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.eltTypeB)>>(value);
       return;
    }

    if (name == "eltTypeC") {
       prop.eltTypeC = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.eltTypeC)>>(value);
       return;
    }

    if (name == "k") {
       prop.k = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.k)>>(value);
       return;
    }

    if (name == "layoutA") {
       prop.layoutA = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.layoutA)>>(value);
       return;
    }

    if (name == "layoutB") {
       prop.layoutB = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.layoutB)>>(value);
       return;
    }

    if (name == "m") {
       prop.m = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.m)>>(value);
       return;
    }

    if (name == "n") {
       prop.n = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.n)>>(value);
       return;
    }
}

void SparseWGMMAOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.eltTypeA) attrs.append("eltTypeA", prop.eltTypeA);

    if (prop.eltTypeB) attrs.append("eltTypeB", prop.eltTypeB);

    if (prop.eltTypeC) attrs.append("eltTypeC", prop.eltTypeC);

    if (prop.k) attrs.append("k", prop.k);

    if (prop.layoutA) attrs.append("layoutA", prop.layoutA);

    if (prop.layoutB) attrs.append("layoutB", prop.layoutB);

    if (prop.m) attrs.append("m", prop.m);

    if (prop.n) attrs.append("n", prop.n);
}

::llvm::LogicalResult SparseWGMMAOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getEltTypeAAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(attr, "eltTypeA", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getEltTypeBAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(attr, "eltTypeB", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getEltTypeCAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(attr, "eltTypeC", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getKAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "k", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getLayoutAAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(attr, "layoutA", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getLayoutBAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(attr, "layoutB", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getMAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "m", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getNAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "n", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult SparseWGMMAOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.eltTypeA)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.eltTypeB)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.eltTypeC)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.k)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.layoutA)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.layoutB)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.m)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.n)))
    return ::mlir::failure();
  return ::mlir::success();
}

void SparseWGMMAOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.eltTypeA);
  writer.writeAttribute(prop.eltTypeB);
  writer.writeAttribute(prop.eltTypeC);
  writer.writeAttribute(prop.k);
  writer.writeAttribute(prop.layoutA);
  writer.writeAttribute(prop.layoutB);
  writer.writeAttribute(prop.m);
  writer.writeAttribute(prop.n);
}

uint32_t SparseWGMMAOp::getM() {
  auto attr = getMAttr();
  return attr.getValue().getZExtValue();
}

uint32_t SparseWGMMAOp::getN() {
  auto attr = getNAttr();
  return attr.getValue().getZExtValue();
}

uint32_t SparseWGMMAOp::getK() {
  auto attr = getKAttr();
  return attr.getValue().getZExtValue();
}

::mlir::triton::nvgpu::WGMMAEltType SparseWGMMAOp::getEltTypeC() {
  auto attr = getEltTypeCAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType SparseWGMMAOp::getEltTypeA() {
  auto attr = getEltTypeAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType SparseWGMMAOp::getEltTypeB() {
  auto attr = getEltTypeBAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout SparseWGMMAOp::getLayoutA() {
  auto attr = getLayoutAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout SparseWGMMAOp::getLayoutB() {
  auto attr = getLayoutBAttr();
  return attr.getValue();
}

void SparseWGMMAOp::setM(uint32_t attrValue) {
  getProperties().m = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void SparseWGMMAOp::setN(uint32_t attrValue) {
  getProperties().n = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void SparseWGMMAOp::setK(uint32_t attrValue) {
  getProperties().k = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void SparseWGMMAOp::setEltTypeC(::mlir::triton::nvgpu::WGMMAEltType attrValue) {
  getProperties().eltTypeC = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void SparseWGMMAOp::setEltTypeA(::mlir::triton::nvgpu::WGMMAEltType attrValue) {
  getProperties().eltTypeA = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void SparseWGMMAOp::setEltTypeB(::mlir::triton::nvgpu::WGMMAEltType attrValue) {
  getProperties().eltTypeB = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void SparseWGMMAOp::setLayoutA(::mlir::triton::nvgpu::WGMMALayout attrValue) {
  getProperties().layoutA = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void SparseWGMMAOp::setLayoutB(::mlir::triton::nvgpu::WGMMALayout attrValue) {
  getProperties().layoutB = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void SparseWGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value opA, ::mlir::Value metaA, ::mlir::Value opB, ::mlir::Value opC, ::mlir::IntegerAttr m, ::mlir::IntegerAttr n, ::mlir::IntegerAttr k, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeC, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeA, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeB, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutA, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(metaA);
  odsState.addOperands(opB);
  odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = m;
  odsState.getOrAddProperties<Properties>().n = n;
  odsState.getOrAddProperties<Properties>().k = k;
  odsState.getOrAddProperties<Properties>().eltTypeC = eltTypeC;
  odsState.getOrAddProperties<Properties>().eltTypeA = eltTypeA;
  odsState.getOrAddProperties<Properties>().eltTypeB = eltTypeB;
  odsState.getOrAddProperties<Properties>().layoutA = layoutA;
  odsState.getOrAddProperties<Properties>().layoutB = layoutB;
  odsState.addTypes(res);
}

void SparseWGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value opA, ::mlir::Value metaA, ::mlir::Value opB, ::mlir::Value opC, ::mlir::IntegerAttr m, ::mlir::IntegerAttr n, ::mlir::IntegerAttr k, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeC, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeA, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeB, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutA, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(metaA);
  odsState.addOperands(opB);
  odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = m;
  odsState.getOrAddProperties<Properties>().n = n;
  odsState.getOrAddProperties<Properties>().k = k;
  odsState.getOrAddProperties<Properties>().eltTypeC = eltTypeC;
  odsState.getOrAddProperties<Properties>().eltTypeA = eltTypeA;
  odsState.getOrAddProperties<Properties>().eltTypeB = eltTypeB;
  odsState.getOrAddProperties<Properties>().layoutA = layoutA;
  odsState.getOrAddProperties<Properties>().layoutB = layoutB;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void SparseWGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value opA, ::mlir::Value metaA, ::mlir::Value opB, ::mlir::Value opC, uint32_t m, uint32_t n, uint32_t k, ::mlir::triton::nvgpu::WGMMAEltType eltTypeC, ::mlir::triton::nvgpu::WGMMAEltType eltTypeA, ::mlir::triton::nvgpu::WGMMAEltType eltTypeB, ::mlir::triton::nvgpu::WGMMALayout layoutA, ::mlir::triton::nvgpu::WGMMALayout layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(metaA);
  odsState.addOperands(opB);
  odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), m);
  odsState.getOrAddProperties<Properties>().n = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), n);
  odsState.getOrAddProperties<Properties>().k = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), k);
  odsState.getOrAddProperties<Properties>().eltTypeC = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeC);
  odsState.getOrAddProperties<Properties>().eltTypeA = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeA);
  odsState.getOrAddProperties<Properties>().eltTypeB = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeB);
  odsState.getOrAddProperties<Properties>().layoutA = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutA);
  odsState.getOrAddProperties<Properties>().layoutB = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutB);
  odsState.addTypes(res);
}

void SparseWGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value opA, ::mlir::Value metaA, ::mlir::Value opB, ::mlir::Value opC, uint32_t m, uint32_t n, uint32_t k, ::mlir::triton::nvgpu::WGMMAEltType eltTypeC, ::mlir::triton::nvgpu::WGMMAEltType eltTypeA, ::mlir::triton::nvgpu::WGMMAEltType eltTypeB, ::mlir::triton::nvgpu::WGMMALayout layoutA, ::mlir::triton::nvgpu::WGMMALayout layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(metaA);
  odsState.addOperands(opB);
  odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), m);
  odsState.getOrAddProperties<Properties>().n = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), n);
  odsState.getOrAddProperties<Properties>().k = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), k);
  odsState.getOrAddProperties<Properties>().eltTypeC = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeC);
  odsState.getOrAddProperties<Properties>().eltTypeA = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeA);
  odsState.getOrAddProperties<Properties>().eltTypeB = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeB);
  odsState.getOrAddProperties<Properties>().layoutA = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutA);
  odsState.getOrAddProperties<Properties>().layoutB = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutB);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void SparseWGMMAOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 4u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<SparseWGMMAOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult SparseWGMMAOp::verifyInvariantsImpl() {
  auto tblgen_eltTypeA = getProperties().eltTypeA; (void)tblgen_eltTypeA;
  if (!tblgen_eltTypeA) return emitOpError("requires attribute 'eltTypeA'");
  auto tblgen_eltTypeB = getProperties().eltTypeB; (void)tblgen_eltTypeB;
  if (!tblgen_eltTypeB) return emitOpError("requires attribute 'eltTypeB'");
  auto tblgen_eltTypeC = getProperties().eltTypeC; (void)tblgen_eltTypeC;
  if (!tblgen_eltTypeC) return emitOpError("requires attribute 'eltTypeC'");
  auto tblgen_k = getProperties().k; (void)tblgen_k;
  if (!tblgen_k) return emitOpError("requires attribute 'k'");
  auto tblgen_layoutA = getProperties().layoutA; (void)tblgen_layoutA;
  if (!tblgen_layoutA) return emitOpError("requires attribute 'layoutA'");
  auto tblgen_layoutB = getProperties().layoutB; (void)tblgen_layoutB;
  if (!tblgen_layoutB) return emitOpError("requires attribute 'layoutB'");
  auto tblgen_m = getProperties().m; (void)tblgen_m;
  if (!tblgen_m) return emitOpError("requires attribute 'm'");
  auto tblgen_n = getProperties().n; (void)tblgen_n;
  if (!tblgen_n) return emitOpError("requires attribute 'n'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_m, "m")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_n, "n")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_k, "k")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(*this, tblgen_eltTypeC, "eltTypeC")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(*this, tblgen_eltTypeA, "eltTypeA")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(*this, tblgen_eltTypeB, "eltTypeB")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(*this, tblgen_layoutA, "layoutA")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(*this, tblgen_layoutB, "layoutB")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps7(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps7(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup3 = getODSOperands(3);

    for (auto v : valueGroup3) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult SparseWGMMAOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult SparseWGMMAOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand opARawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> opAOperands(&opARawOperand, 1);  ::llvm::SMLoc opAOperandsLoc;
  (void)opAOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand metaARawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> metaAOperands(&metaARawOperand, 1);  ::llvm::SMLoc metaAOperandsLoc;
  (void)metaAOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand opBRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> opBOperands(&opBRawOperand, 1);  ::llvm::SMLoc opBOperandsLoc;
  (void)opBOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand opCRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> opCOperands(&opCRawOperand, 1);  ::llvm::SMLoc opCOperandsLoc;
  (void)opCOperandsLoc;
  ::llvm::ArrayRef<::mlir::Type> allOperandTypes;
  ::llvm::ArrayRef<::mlir::Type> resTypes;

  opAOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(opARawOperand))
    return ::mlir::failure();
  if (parser.parseKeyword("meta"))
    return ::mlir::failure();

  metaAOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(metaARawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  opBOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(opBRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  opCOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(opCRawOperand))
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

  ::mlir::FunctionType allOperand__res_functionType;
  if (parser.parseType(allOperand__res_functionType))
    return ::mlir::failure();
  allOperandTypes = allOperand__res_functionType.getInputs();
  resTypes = allOperand__res_functionType.getResults();
  result.addTypes(resTypes);
  if (parser.resolveOperands(::llvm::concat<const ::mlir::OpAsmParser::UnresolvedOperand>(opAOperands, metaAOperands, opBOperands, opCOperands), allOperandTypes, parser.getNameLoc(), result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void SparseWGMMAOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getOpA();
  _odsPrinter << ' ' << "meta";
  _odsPrinter << ' ';
  _odsPrinter << getMetaA();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getOpB();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getOpC();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter.printFunctionalType(getOperation()->getOperandTypes(), ::llvm::ArrayRef<::mlir::Type>(getRes().getType()));
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::SparseWGMMAOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::StoreMatrixOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
StoreMatrixOpGenericAdaptorBase::StoreMatrixOpGenericAdaptorBase(StoreMatrixOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

std::pair<unsigned, unsigned> StoreMatrixOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
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

::mlir::UnitAttr StoreMatrixOpGenericAdaptorBase::getTransAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().trans);
  if (!attr)
    attr = ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr);
  return attr;
}

bool StoreMatrixOpGenericAdaptorBase::getTrans() {
  auto attr = getTransAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder(odsAttrs.getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

} // namespace detail
StoreMatrixOpAdaptor::StoreMatrixOpAdaptor(StoreMatrixOp op) : StoreMatrixOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult StoreMatrixOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_trans = getProperties().trans; (void)tblgen_trans;

  if (tblgen_trans && !((::llvm::isa<::mlir::UnitAttr>(tblgen_trans))))
    return emitError(loc, "'nvgpu.stmatrix' op ""attribute 'trans' failed to satisfy constraint: unit attribute");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> StoreMatrixOp::getODSOperandIndexAndLength(unsigned index) {
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

::mlir::MutableOperandRange StoreMatrixOp::getValsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::llvm::LogicalResult StoreMatrixOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.trans;
       auto attr = dict.get("trans");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `trans` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute StoreMatrixOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.trans;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("trans",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code StoreMatrixOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.trans.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> StoreMatrixOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "trans")
      return prop.trans;
  return std::nullopt;
}

void StoreMatrixOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "trans") {
       prop.trans = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.trans)>>(value);
       return;
    }
}

void StoreMatrixOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.trans) attrs.append("trans", prop.trans);
}

::llvm::LogicalResult StoreMatrixOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getTransAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps5(attr, "trans", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult StoreMatrixOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readOptionalAttribute(prop.trans)))
    return ::mlir::failure();
  return ::mlir::success();
}

void StoreMatrixOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  writer.writeOptionalAttribute(prop.trans);
}

bool StoreMatrixOp::getTrans() {
  auto attr = getTransAttr();
    if (!attr)
      return ((false) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr) != nullptr;
  return attr != nullptr;
}

void StoreMatrixOp::setTrans(bool attrValue) {
    auto &odsProp = getProperties().trans;
    if (attrValue)
      odsProp = ((attrValue) ? ::mlir::Builder((*this)->getContext()).getUnitAttr() : nullptr);
    else
      odsProp = nullptr;
}

void StoreMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value addr, ::mlir::ValueRange vals, /*optional*/::mlir::UnitAttr trans) {
  odsState.addOperands(addr);
  odsState.addOperands(vals);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = trans;
  }
}

void StoreMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value addr, ::mlir::ValueRange vals, /*optional*/::mlir::UnitAttr trans) {
  odsState.addOperands(addr);
  odsState.addOperands(vals);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = trans;
  }
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void StoreMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value addr, ::mlir::ValueRange vals, /*optional*/bool trans) {
  odsState.addOperands(addr);
  odsState.addOperands(vals);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = ((trans) ? odsBuilder.getUnitAttr() : nullptr);
  }
}

void StoreMatrixOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value addr, ::mlir::ValueRange vals, /*optional*/bool trans) {
  odsState.addOperands(addr);
  odsState.addOperands(vals);
  if (trans) {
    odsState.getOrAddProperties<Properties>().trans = ((trans) ? odsBuilder.getUnitAttr() : nullptr);
  }
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void StoreMatrixOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<StoreMatrixOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult StoreMatrixOp::verifyInvariantsImpl() {
  auto tblgen_trans = getProperties().trans; (void)tblgen_trans;

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps5(*this, tblgen_trans, "trans")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps5(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps8(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult StoreMatrixOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult StoreMatrixOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> allOperands;
  ::llvm::SmallVector<::mlir::Type, 1> allOperandTypes;
  [[maybe_unused]] ::llvm::SMLoc allOperandLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(allOperands))
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

  if (parser.parseTypeList(allOperandTypes))
    return ::mlir::failure();
  if (parser.resolveOperands(allOperands, allOperandTypes, allOperandLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void StoreMatrixOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getOperation()->getOperands();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getTransAttr();
     if(attr && (attr == ((false) ? odsBuilder.getUnitAttr() : nullptr)))
       elidedAttrs.push_back("trans");
  }
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter << getOperation()->getOperandTypes();
}

void StoreMatrixOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  effects.emplace_back(::mlir::MemoryEffects::Write::get(), 0, false, ::mlir::SideEffects::DefaultResource::get());
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::StoreMatrixOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::WGMMACommitGroupOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
WGMMACommitGroupOpAdaptor::WGMMACommitGroupOpAdaptor(WGMMACommitGroupOp op) : WGMMACommitGroupOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult WGMMACommitGroupOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void WGMMACommitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState) {
}

void WGMMACommitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void WGMMACommitGroupOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult WGMMACommitGroupOp::verifyInvariantsImpl() {
  return ::mlir::success();
}

::llvm::LogicalResult WGMMACommitGroupOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult WGMMACommitGroupOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void WGMMACommitGroupOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::WGMMACommitGroupOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::WGMMAFenceOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
WGMMAFenceOpAdaptor::WGMMAFenceOpAdaptor(WGMMAFenceOp op) : WGMMAFenceOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult WGMMAFenceOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void WGMMAFenceOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState) {
}

void WGMMAFenceOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void WGMMAFenceOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult WGMMAFenceOp::verifyInvariantsImpl() {
  return ::mlir::success();
}

::llvm::LogicalResult WGMMAFenceOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult WGMMAFenceOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  return ::mlir::success();
}

void WGMMAFenceOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::WGMMAFenceOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::WGMMAOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
WGMMAOpGenericAdaptorBase::WGMMAOpGenericAdaptorBase(WGMMAOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

std::pair<unsigned, unsigned> WGMMAOpGenericAdaptorBase::getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
  bool isVariadic[] = {false, false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperandsSize - 3) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

uint32_t WGMMAOpGenericAdaptorBase::getM() {
  auto attr = getMAttr();
  return attr.getValue().getZExtValue();
}

uint32_t WGMMAOpGenericAdaptorBase::getN() {
  auto attr = getNAttr();
  return attr.getValue().getZExtValue();
}

uint32_t WGMMAOpGenericAdaptorBase::getK() {
  auto attr = getKAttr();
  return attr.getValue().getZExtValue();
}

::mlir::triton::nvgpu::WGMMAEltType WGMMAOpGenericAdaptorBase::getEltTypeC() {
  auto attr = getEltTypeCAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType WGMMAOpGenericAdaptorBase::getEltTypeA() {
  auto attr = getEltTypeAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType WGMMAOpGenericAdaptorBase::getEltTypeB() {
  auto attr = getEltTypeBAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout WGMMAOpGenericAdaptorBase::getLayoutA() {
  auto attr = getLayoutAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout WGMMAOpGenericAdaptorBase::getLayoutB() {
  auto attr = getLayoutBAttr();
  return attr.getValue();
}

} // namespace detail
WGMMAOpAdaptor::WGMMAOpAdaptor(WGMMAOp op) : WGMMAOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult WGMMAOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_eltTypeA = getProperties().eltTypeA; (void)tblgen_eltTypeA;
  if (!tblgen_eltTypeA) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'eltTypeA'");
  auto tblgen_eltTypeB = getProperties().eltTypeB; (void)tblgen_eltTypeB;
  if (!tblgen_eltTypeB) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'eltTypeB'");
  auto tblgen_eltTypeC = getProperties().eltTypeC; (void)tblgen_eltTypeC;
  if (!tblgen_eltTypeC) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'eltTypeC'");
  auto tblgen_k = getProperties().k; (void)tblgen_k;
  if (!tblgen_k) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'k'");
  auto tblgen_layoutA = getProperties().layoutA; (void)tblgen_layoutA;
  if (!tblgen_layoutA) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'layoutA'");
  auto tblgen_layoutB = getProperties().layoutB; (void)tblgen_layoutB;
  if (!tblgen_layoutB) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'layoutB'");
  auto tblgen_m = getProperties().m; (void)tblgen_m;
  if (!tblgen_m) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'm'");
  auto tblgen_n = getProperties().n; (void)tblgen_n;
  if (!tblgen_n) return emitError(loc, "'nvgpu.wgmma' op ""requires attribute 'n'");

  if (tblgen_m && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_m))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_m).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'm' failed to satisfy constraint: 32-bit signless integer attribute");

  if (tblgen_n && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_n))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_n).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'n' failed to satisfy constraint: 32-bit signless integer attribute");

  if (tblgen_k && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_k))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_k).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'k' failed to satisfy constraint: 32-bit signless integer attribute");

  if (tblgen_eltTypeC && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(tblgen_eltTypeC))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'eltTypeC' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

  if (tblgen_eltTypeA && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(tblgen_eltTypeA))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'eltTypeA' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

  if (tblgen_eltTypeB && !((::llvm::isa<::mlir::triton::nvgpu::WGMMAEltTypeAttr>(tblgen_eltTypeB))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'eltTypeB' failed to satisfy constraint: wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

  if (tblgen_layoutA && !((::llvm::isa<::mlir::triton::nvgpu::WGMMALayoutAttr>(tblgen_layoutA))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'layoutA' failed to satisfy constraint: wgmma layout, either 'row' or 'col'");

  if (tblgen_layoutB && !((::llvm::isa<::mlir::triton::nvgpu::WGMMALayoutAttr>(tblgen_layoutB))))
    return emitError(loc, "'nvgpu.wgmma' op ""attribute 'layoutB' failed to satisfy constraint: wgmma layout, either 'row' or 'col'");
  return ::mlir::success();
}

std::pair<unsigned, unsigned> WGMMAOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, false, false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 3) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::MutableOperandRange WGMMAOp::getOpCMutable() {
  auto range = getODSOperandIndexAndLength(3);
  auto mutableRange = ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
  return mutableRange;
}

::llvm::LogicalResult WGMMAOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.eltTypeA;
       auto attr = dict.get("eltTypeA");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `eltTypeA` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.eltTypeB;
       auto attr = dict.get("eltTypeB");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `eltTypeB` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.eltTypeC;
       auto attr = dict.get("eltTypeC");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `eltTypeC` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.k;
       auto attr = dict.get("k");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `k` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.layoutA;
       auto attr = dict.get("layoutA");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `layoutA` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.layoutB;
       auto attr = dict.get("layoutB");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `layoutB` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.m;
       auto attr = dict.get("m");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `m` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.n;
       auto attr = dict.get("n");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `n` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute WGMMAOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.eltTypeA;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("eltTypeA",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.eltTypeB;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("eltTypeB",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.eltTypeC;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("eltTypeC",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.k;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("k",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.layoutA;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("layoutA",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.layoutB;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("layoutB",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.m;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("m",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.n;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("n",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code WGMMAOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.eltTypeA.getAsOpaquePointer()), 
    llvm::hash_value(prop.eltTypeB.getAsOpaquePointer()), 
    llvm::hash_value(prop.eltTypeC.getAsOpaquePointer()), 
    llvm::hash_value(prop.k.getAsOpaquePointer()), 
    llvm::hash_value(prop.layoutA.getAsOpaquePointer()), 
    llvm::hash_value(prop.layoutB.getAsOpaquePointer()), 
    llvm::hash_value(prop.m.getAsOpaquePointer()), 
    llvm::hash_value(prop.n.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> WGMMAOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "eltTypeA")
      return prop.eltTypeA;

    if (name == "eltTypeB")
      return prop.eltTypeB;

    if (name == "eltTypeC")
      return prop.eltTypeC;

    if (name == "k")
      return prop.k;

    if (name == "layoutA")
      return prop.layoutA;

    if (name == "layoutB")
      return prop.layoutB;

    if (name == "m")
      return prop.m;

    if (name == "n")
      return prop.n;
  return std::nullopt;
}

void WGMMAOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "eltTypeA") {
       prop.eltTypeA = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.eltTypeA)>>(value);
       return;
    }

    if (name == "eltTypeB") {
       prop.eltTypeB = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.eltTypeB)>>(value);
       return;
    }

    if (name == "eltTypeC") {
       prop.eltTypeC = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.eltTypeC)>>(value);
       return;
    }

    if (name == "k") {
       prop.k = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.k)>>(value);
       return;
    }

    if (name == "layoutA") {
       prop.layoutA = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.layoutA)>>(value);
       return;
    }

    if (name == "layoutB") {
       prop.layoutB = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.layoutB)>>(value);
       return;
    }

    if (name == "m") {
       prop.m = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.m)>>(value);
       return;
    }

    if (name == "n") {
       prop.n = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.n)>>(value);
       return;
    }
}

void WGMMAOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.eltTypeA) attrs.append("eltTypeA", prop.eltTypeA);

    if (prop.eltTypeB) attrs.append("eltTypeB", prop.eltTypeB);

    if (prop.eltTypeC) attrs.append("eltTypeC", prop.eltTypeC);

    if (prop.k) attrs.append("k", prop.k);

    if (prop.layoutA) attrs.append("layoutA", prop.layoutA);

    if (prop.layoutB) attrs.append("layoutB", prop.layoutB);

    if (prop.m) attrs.append("m", prop.m);

    if (prop.n) attrs.append("n", prop.n);
}

::llvm::LogicalResult WGMMAOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getEltTypeAAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(attr, "eltTypeA", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getEltTypeBAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(attr, "eltTypeB", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getEltTypeCAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(attr, "eltTypeC", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getKAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "k", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getLayoutAAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(attr, "layoutA", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getLayoutBAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(attr, "layoutB", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getMAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "m", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getNAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "n", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult WGMMAOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.eltTypeA)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.eltTypeB)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.eltTypeC)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.k)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.layoutA)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.layoutB)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.m)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.n)))
    return ::mlir::failure();
  return ::mlir::success();
}

void WGMMAOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.eltTypeA);
  writer.writeAttribute(prop.eltTypeB);
  writer.writeAttribute(prop.eltTypeC);
  writer.writeAttribute(prop.k);
  writer.writeAttribute(prop.layoutA);
  writer.writeAttribute(prop.layoutB);
  writer.writeAttribute(prop.m);
  writer.writeAttribute(prop.n);
}

uint32_t WGMMAOp::getM() {
  auto attr = getMAttr();
  return attr.getValue().getZExtValue();
}

uint32_t WGMMAOp::getN() {
  auto attr = getNAttr();
  return attr.getValue().getZExtValue();
}

uint32_t WGMMAOp::getK() {
  auto attr = getKAttr();
  return attr.getValue().getZExtValue();
}

::mlir::triton::nvgpu::WGMMAEltType WGMMAOp::getEltTypeC() {
  auto attr = getEltTypeCAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType WGMMAOp::getEltTypeA() {
  auto attr = getEltTypeAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMAEltType WGMMAOp::getEltTypeB() {
  auto attr = getEltTypeBAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout WGMMAOp::getLayoutA() {
  auto attr = getLayoutAAttr();
  return attr.getValue();
}

::mlir::triton::nvgpu::WGMMALayout WGMMAOp::getLayoutB() {
  auto attr = getLayoutBAttr();
  return attr.getValue();
}

void WGMMAOp::setM(uint32_t attrValue) {
  getProperties().m = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void WGMMAOp::setN(uint32_t attrValue) {
  getProperties().n = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void WGMMAOp::setK(uint32_t attrValue) {
  getProperties().k = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void WGMMAOp::setEltTypeC(::mlir::triton::nvgpu::WGMMAEltType attrValue) {
  getProperties().eltTypeC = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void WGMMAOp::setEltTypeA(::mlir::triton::nvgpu::WGMMAEltType attrValue) {
  getProperties().eltTypeA = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void WGMMAOp::setEltTypeB(::mlir::triton::nvgpu::WGMMAEltType attrValue) {
  getProperties().eltTypeB = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void WGMMAOp::setLayoutA(::mlir::triton::nvgpu::WGMMALayout attrValue) {
  getProperties().layoutA = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void WGMMAOp::setLayoutB(::mlir::triton::nvgpu::WGMMALayout attrValue) {
  getProperties().layoutB = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void WGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value opA, ::mlir::Value opB, ::mlir::Value useC, /*optional*/::mlir::Value opC, ::mlir::IntegerAttr m, ::mlir::IntegerAttr n, ::mlir::IntegerAttr k, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeC, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeA, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeB, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutA, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(opB);
  odsState.addOperands(useC);
  if (opC)
    odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = m;
  odsState.getOrAddProperties<Properties>().n = n;
  odsState.getOrAddProperties<Properties>().k = k;
  odsState.getOrAddProperties<Properties>().eltTypeC = eltTypeC;
  odsState.getOrAddProperties<Properties>().eltTypeA = eltTypeA;
  odsState.getOrAddProperties<Properties>().eltTypeB = eltTypeB;
  odsState.getOrAddProperties<Properties>().layoutA = layoutA;
  odsState.getOrAddProperties<Properties>().layoutB = layoutB;
  odsState.addTypes(res);
}

void WGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value opA, ::mlir::Value opB, ::mlir::Value useC, /*optional*/::mlir::Value opC, ::mlir::IntegerAttr m, ::mlir::IntegerAttr n, ::mlir::IntegerAttr k, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeC, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeA, ::mlir::triton::nvgpu::WGMMAEltTypeAttr eltTypeB, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutA, ::mlir::triton::nvgpu::WGMMALayoutAttr layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(opB);
  odsState.addOperands(useC);
  if (opC)
    odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = m;
  odsState.getOrAddProperties<Properties>().n = n;
  odsState.getOrAddProperties<Properties>().k = k;
  odsState.getOrAddProperties<Properties>().eltTypeC = eltTypeC;
  odsState.getOrAddProperties<Properties>().eltTypeA = eltTypeA;
  odsState.getOrAddProperties<Properties>().eltTypeB = eltTypeB;
  odsState.getOrAddProperties<Properties>().layoutA = layoutA;
  odsState.getOrAddProperties<Properties>().layoutB = layoutB;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void WGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value opA, ::mlir::Value opB, ::mlir::Value useC, /*optional*/::mlir::Value opC, uint32_t m, uint32_t n, uint32_t k, ::mlir::triton::nvgpu::WGMMAEltType eltTypeC, ::mlir::triton::nvgpu::WGMMAEltType eltTypeA, ::mlir::triton::nvgpu::WGMMAEltType eltTypeB, ::mlir::triton::nvgpu::WGMMALayout layoutA, ::mlir::triton::nvgpu::WGMMALayout layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(opB);
  odsState.addOperands(useC);
  if (opC)
    odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), m);
  odsState.getOrAddProperties<Properties>().n = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), n);
  odsState.getOrAddProperties<Properties>().k = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), k);
  odsState.getOrAddProperties<Properties>().eltTypeC = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeC);
  odsState.getOrAddProperties<Properties>().eltTypeA = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeA);
  odsState.getOrAddProperties<Properties>().eltTypeB = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeB);
  odsState.getOrAddProperties<Properties>().layoutA = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutA);
  odsState.getOrAddProperties<Properties>().layoutB = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutB);
  odsState.addTypes(res);
}

void WGMMAOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value opA, ::mlir::Value opB, ::mlir::Value useC, /*optional*/::mlir::Value opC, uint32_t m, uint32_t n, uint32_t k, ::mlir::triton::nvgpu::WGMMAEltType eltTypeC, ::mlir::triton::nvgpu::WGMMAEltType eltTypeA, ::mlir::triton::nvgpu::WGMMAEltType eltTypeB, ::mlir::triton::nvgpu::WGMMALayout layoutA, ::mlir::triton::nvgpu::WGMMALayout layoutB) {
  odsState.addOperands(opA);
  odsState.addOperands(opB);
  odsState.addOperands(useC);
  if (opC)
    odsState.addOperands(opC);
  odsState.getOrAddProperties<Properties>().m = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), m);
  odsState.getOrAddProperties<Properties>().n = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), n);
  odsState.getOrAddProperties<Properties>().k = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), k);
  odsState.getOrAddProperties<Properties>().eltTypeC = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeC);
  odsState.getOrAddProperties<Properties>().eltTypeA = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeA);
  odsState.getOrAddProperties<Properties>().eltTypeB = ::mlir::triton::nvgpu::WGMMAEltTypeAttr::get(odsBuilder.getContext(), eltTypeB);
  odsState.getOrAddProperties<Properties>().layoutA = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutA);
  odsState.getOrAddProperties<Properties>().layoutB = ::mlir::triton::nvgpu::WGMMALayoutAttr::get(odsBuilder.getContext(), layoutB);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void WGMMAOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() >= 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<WGMMAOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult WGMMAOp::verifyInvariantsImpl() {
  auto tblgen_eltTypeA = getProperties().eltTypeA; (void)tblgen_eltTypeA;
  if (!tblgen_eltTypeA) return emitOpError("requires attribute 'eltTypeA'");
  auto tblgen_eltTypeB = getProperties().eltTypeB; (void)tblgen_eltTypeB;
  if (!tblgen_eltTypeB) return emitOpError("requires attribute 'eltTypeB'");
  auto tblgen_eltTypeC = getProperties().eltTypeC; (void)tblgen_eltTypeC;
  if (!tblgen_eltTypeC) return emitOpError("requires attribute 'eltTypeC'");
  auto tblgen_k = getProperties().k; (void)tblgen_k;
  if (!tblgen_k) return emitOpError("requires attribute 'k'");
  auto tblgen_layoutA = getProperties().layoutA; (void)tblgen_layoutA;
  if (!tblgen_layoutA) return emitOpError("requires attribute 'layoutA'");
  auto tblgen_layoutB = getProperties().layoutB; (void)tblgen_layoutB;
  if (!tblgen_layoutB) return emitOpError("requires attribute 'layoutB'");
  auto tblgen_m = getProperties().m; (void)tblgen_m;
  if (!tblgen_m) return emitOpError("requires attribute 'm'");
  auto tblgen_n = getProperties().n; (void)tblgen_n;
  if (!tblgen_n) return emitOpError("requires attribute 'n'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_m, "m")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_n, "n")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_k, "k")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(*this, tblgen_eltTypeC, "eltTypeC")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(*this, tblgen_eltTypeA, "eltTypeA")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps7(*this, tblgen_eltTypeB, "eltTypeB")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(*this, tblgen_layoutA, "layoutA")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps8(*this, tblgen_layoutB, "layoutB")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps7(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps7(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup3 = getODSOperands(3);

    if (valueGroup3.size() > 1) {
      return emitOpError("operand group starting at #") << index
          << " requires 0 or 1 element, but found " << valueGroup3.size();
    }

    for (auto v : valueGroup3) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult WGMMAOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult WGMMAOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand opARawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> opAOperands(&opARawOperand, 1);  ::llvm::SMLoc opAOperandsLoc;
  (void)opAOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand opBRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> opBOperands(&opBRawOperand, 1);  ::llvm::SMLoc opBOperandsLoc;
  (void)opBOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand useCRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> useCOperands(&useCRawOperand, 1);  ::llvm::SMLoc useCOperandsLoc;
  (void)useCOperandsLoc;
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> opCOperands;
  ::llvm::SMLoc opCOperandsLoc;
  (void)opCOperandsLoc;
  ::llvm::ArrayRef<::mlir::Type> allOperandTypes;
  ::llvm::ArrayRef<::mlir::Type> resTypes;

  opAOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(opARawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  opBOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(opBRawOperand))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  useCOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(useCRawOperand))
    return ::mlir::failure();
  if (::mlir::succeeded(parser.parseOptionalComma())) {

  {
    opCOperandsLoc = parser.getCurrentLocation();
    ::mlir::OpAsmParser::UnresolvedOperand operand;
    ::mlir::OptionalParseResult parseResult =
                                    parser.parseOptionalOperand(operand);
    if (parseResult.has_value()) {
      if (failed(*parseResult))
        return ::mlir::failure();
      opCOperands.push_back(operand);
    }
  }
  }
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

  ::mlir::FunctionType allOperand__res_functionType;
  if (parser.parseType(allOperand__res_functionType))
    return ::mlir::failure();
  allOperandTypes = allOperand__res_functionType.getInputs();
  resTypes = allOperand__res_functionType.getResults();
  result.addTypes(resTypes);
  if (parser.resolveOperands(::llvm::concat<const ::mlir::OpAsmParser::UnresolvedOperand>(opAOperands, opBOperands, useCOperands, opCOperands), allOperandTypes, parser.getNameLoc(), result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void WGMMAOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getOpA();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getOpB();
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getUseC();
  if (getOpC()) {
    _odsPrinter << ",";
    _odsPrinter << ' ';
    if (::mlir::Value value = getOpC())
      _odsPrinter << value;
  }
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  _odsPrinter.printFunctionalType(getOperation()->getOperandTypes(), ::llvm::ArrayRef<::mlir::Type>(getRes().getType()));
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::WGMMAOp)

namespace mlir {
namespace triton {
namespace nvgpu {

//===----------------------------------------------------------------------===//
// ::mlir::triton::nvgpu::WGMMAWaitGroupOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
WGMMAWaitGroupOpGenericAdaptorBase::WGMMAWaitGroupOpGenericAdaptorBase(WGMMAWaitGroupOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

uint32_t WGMMAWaitGroupOpGenericAdaptorBase::getPendings() {
  auto attr = getPendingsAttr();
  return attr.getValue().getZExtValue();
}

} // namespace detail
WGMMAWaitGroupOpAdaptor::WGMMAWaitGroupOpAdaptor(WGMMAWaitGroupOp op) : WGMMAWaitGroupOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult WGMMAWaitGroupOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_pendings = getProperties().pendings; (void)tblgen_pendings;
  if (!tblgen_pendings) return emitError(loc, "'nvgpu.wgmma_wait_group' op ""requires attribute 'pendings'");

  if (tblgen_pendings && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_pendings))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_pendings).getType().isSignlessInteger(32)))))
    return emitError(loc, "'nvgpu.wgmma_wait_group' op ""attribute 'pendings' failed to satisfy constraint: 32-bit signless integer attribute");
  return ::mlir::success();
}

::llvm::LogicalResult WGMMAWaitGroupOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.pendings;
       auto attr = dict.get("pendings");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `pendings` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute WGMMAWaitGroupOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.pendings;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("pendings",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code WGMMAWaitGroupOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.pendings.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> WGMMAWaitGroupOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "pendings")
      return prop.pendings;
  return std::nullopt;
}

void WGMMAWaitGroupOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "pendings") {
       prop.pendings = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.pendings)>>(value);
       return;
    }
}

void WGMMAWaitGroupOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.pendings) attrs.append("pendings", prop.pendings);
}

::llvm::LogicalResult WGMMAWaitGroupOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getPendingsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(attr, "pendings", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult WGMMAWaitGroupOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.pendings)))
    return ::mlir::failure();
  return ::mlir::success();
}

void WGMMAWaitGroupOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.pendings);
}

uint32_t WGMMAWaitGroupOp::getPendings() {
  auto attr = getPendingsAttr();
  return attr.getValue().getZExtValue();
}

void WGMMAWaitGroupOp::setPendings(uint32_t attrValue) {
  getProperties().pendings = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type output, ::mlir::Value input, ::mlir::IntegerAttr pendings) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().pendings = pendings;
  odsState.addTypes(output);
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::IntegerAttr pendings) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().pendings = pendings;

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(WGMMAWaitGroupOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::mlir::detail::reportFatalInferReturnTypesError(odsState);
        
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr pendings) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().pendings = pendings;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type output, ::mlir::Value input, uint32_t pendings) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().pendings = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), pendings);
  odsState.addTypes(output);
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, uint32_t pendings) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().pendings = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), pendings);

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(WGMMAWaitGroupOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::mlir::detail::reportFatalInferReturnTypesError(odsState);
        
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint32_t pendings) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().pendings = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), pendings);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<WGMMAWaitGroupOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

void WGMMAWaitGroupOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<WGMMAWaitGroupOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(WGMMAWaitGroupOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

::llvm::LogicalResult WGMMAWaitGroupOp::verifyInvariantsImpl() {
  auto tblgen_pendings = getProperties().pendings; (void)tblgen_pendings;
  if (!tblgen_pendings) return emitOpError("requires attribute 'pendings'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_NVGPUOps6(*this, tblgen_pendings, "pendings")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_NVGPUOps6(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  if (!((((*this->getODSOperands(0).begin()).getType()) == ((*this->getODSResults(0).begin()).getType()) && ((*this->getODSResults(0).begin()).getType()) == ((*this->getODSOperands(0).begin()).getType()))))
    return emitOpError("failed to verify that all of {input, output} have same type");
  return ::mlir::success();
}

::llvm::LogicalResult WGMMAWaitGroupOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::llvm::LogicalResult WGMMAWaitGroupOp::inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes) {
  inferredReturnTypes.resize(1);
  ::mlir::Builder odsBuilder(context);
  if (operands.size() <= 0)
    return ::mlir::failure();
  ::mlir::Type odsInferredType0 = operands[0].getType();
  inferredReturnTypes[0] = odsInferredType0;
  return ::mlir::success();
}

::mlir::ParseResult WGMMAWaitGroupOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(&inputRawOperand, 1);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type inputRawType{};
  ::llvm::ArrayRef<::mlir::Type> inputTypes(&inputRawType, 1);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperand))
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
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    inputRawType = type;
  }
  result.addTypes(inputTypes[0]);
  if (parser.resolveOperands(inputOperands, inputTypes, inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void WGMMAWaitGroupOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getInput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

} // namespace nvgpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::nvgpu::WGMMAWaitGroupOp)


#endif  // GET_OP_CLASSES

