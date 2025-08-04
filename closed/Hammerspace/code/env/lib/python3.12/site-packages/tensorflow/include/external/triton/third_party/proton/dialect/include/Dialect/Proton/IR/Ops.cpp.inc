/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ProtonOps.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::triton::proton::RecordOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace triton {
namespace proton {

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::BoolAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: bool attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_ProtonOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps2(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && ((!::llvm::cast<::mlir::IntegerAttr>(attr).getValue().isNegative()))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit signless integer attribute whose value is non-negative";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps2(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_ProtonOps2(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps3(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::triton::proton::MetricAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: allowed 32-bit signless integer cases: 0";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps3(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_ProtonOps3(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps4(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::triton::proton::GranularityAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: allowed 32-bit signless integer cases: 0, 1";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_ProtonOps4(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_ProtonOps4(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
} // namespace proton
} // namespace triton
} // namespace mlir
namespace mlir {
namespace triton {
namespace proton {

//===----------------------------------------------------------------------===//
// ::mlir::triton::proton::RecordOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
RecordOpGenericAdaptorBase::RecordOpGenericAdaptorBase(RecordOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

bool RecordOpGenericAdaptorBase::getIsStart() {
  auto attr = getIsStartAttr();
  return attr.getValue();
}

uint32_t RecordOpGenericAdaptorBase::getRegionId() {
  auto attr = getRegionIdAttr();
  return attr.getValue().getZExtValue();
}

::mlir::triton::proton::MetricAttr RecordOpGenericAdaptorBase::getMetricAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::triton::proton::MetricAttr>(getProperties().metric);
  return attr;
}

::mlir::triton::proton::Metric RecordOpGenericAdaptorBase::getMetric() {
  auto attr = getMetricAttr();
  return attr.getValue();
}

::mlir::triton::proton::GranularityAttr RecordOpGenericAdaptorBase::getGranularityAttr() {
  auto attr = ::llvm::dyn_cast_or_null<::mlir::triton::proton::GranularityAttr>(getProperties().granularity);
  return attr;
}

::mlir::triton::proton::Granularity RecordOpGenericAdaptorBase::getGranularity() {
  auto attr = getGranularityAttr();
  return attr.getValue();
}

} // namespace detail
RecordOpAdaptor::RecordOpAdaptor(RecordOp op) : RecordOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult RecordOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_granularity = getProperties().granularity; (void)tblgen_granularity;
  auto tblgen_isStart = getProperties().isStart; (void)tblgen_isStart;
  if (!tblgen_isStart) return emitError(loc, "'proton.record' op ""requires attribute 'isStart'");
  auto tblgen_metric = getProperties().metric; (void)tblgen_metric;
  auto tblgen_regionId = getProperties().regionId; (void)tblgen_regionId;
  if (!tblgen_regionId) return emitError(loc, "'proton.record' op ""requires attribute 'regionId'");

  if (tblgen_isStart && !((::llvm::isa<::mlir::BoolAttr>(tblgen_isStart))))
    return emitError(loc, "'proton.record' op ""attribute 'isStart' failed to satisfy constraint: bool attribute");

  if (tblgen_regionId && !((((::llvm::isa<::mlir::IntegerAttr>(tblgen_regionId))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_regionId).getType().isSignlessInteger(32)))) && ((!::llvm::cast<::mlir::IntegerAttr>(tblgen_regionId).getValue().isNegative()))))
    return emitError(loc, "'proton.record' op ""attribute 'regionId' failed to satisfy constraint: 32-bit signless integer attribute whose value is non-negative");

  if (tblgen_metric && !((::llvm::isa<::mlir::triton::proton::MetricAttr>(tblgen_metric))))
    return emitError(loc, "'proton.record' op ""attribute 'metric' failed to satisfy constraint: allowed 32-bit signless integer cases: 0");

  if (tblgen_granularity && !((::llvm::isa<::mlir::triton::proton::GranularityAttr>(tblgen_granularity))))
    return emitError(loc, "'proton.record' op ""attribute 'granularity' failed to satisfy constraint: allowed 32-bit signless integer cases: 0, 1");
  return ::mlir::success();
}

::llvm::LogicalResult RecordOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.granularity;
       auto attr = dict.get("granularity");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `granularity` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.isStart;
       auto attr = dict.get("isStart");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `isStart` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.metric;
       auto attr = dict.get("metric");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `metric` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.regionId;
       auto attr = dict.get("regionId");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `regionId` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute RecordOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.granularity;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("granularity",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.isStart;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("isStart",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.metric;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("metric",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.regionId;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("regionId",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code RecordOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.granularity.getAsOpaquePointer()), 
    llvm::hash_value(prop.isStart.getAsOpaquePointer()), 
    llvm::hash_value(prop.metric.getAsOpaquePointer()), 
    llvm::hash_value(prop.regionId.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> RecordOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "granularity")
      return prop.granularity;

    if (name == "isStart")
      return prop.isStart;

    if (name == "metric")
      return prop.metric;

    if (name == "regionId")
      return prop.regionId;
  return std::nullopt;
}

void RecordOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "granularity") {
       prop.granularity = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.granularity)>>(value);
       return;
    }

    if (name == "isStart") {
       prop.isStart = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.isStart)>>(value);
       return;
    }

    if (name == "metric") {
       prop.metric = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.metric)>>(value);
       return;
    }

    if (name == "regionId") {
       prop.regionId = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.regionId)>>(value);
       return;
    }
}

void RecordOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.granularity) attrs.append("granularity", prop.granularity);

    if (prop.isStart) attrs.append("isStart", prop.isStart);

    if (prop.metric) attrs.append("metric", prop.metric);

    if (prop.regionId) attrs.append("regionId", prop.regionId);
}

::llvm::LogicalResult RecordOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getGranularityAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps4(attr, "granularity", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getIsStartAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps1(attr, "isStart", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getMetricAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps3(attr, "metric", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getRegionIdAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps2(attr, "regionId", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult RecordOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readOptionalAttribute(prop.granularity)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.isStart)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readOptionalAttribute(prop.metric)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.regionId)))
    return ::mlir::failure();
  return ::mlir::success();
}

void RecordOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;

  writer.writeOptionalAttribute(prop.granularity);
  writer.writeAttribute(prop.isStart);

  writer.writeOptionalAttribute(prop.metric);
  writer.writeAttribute(prop.regionId);
}

bool RecordOp::getIsStart() {
  auto attr = getIsStartAttr();
  return attr.getValue();
}

uint32_t RecordOp::getRegionId() {
  auto attr = getRegionIdAttr();
  return attr.getValue().getZExtValue();
}

::mlir::triton::proton::Metric RecordOp::getMetric() {
  auto attr = getMetricAttr();
  return attr.getValue();
}

::mlir::triton::proton::Granularity RecordOp::getGranularity() {
  auto attr = getGranularityAttr();
  return attr.getValue();
}

void RecordOp::setIsStart(bool attrValue) {
  getProperties().isStart = ::mlir::Builder((*this)->getContext()).getBoolAttr(attrValue);
}

void RecordOp::setRegionId(uint32_t attrValue) {
  getProperties().regionId = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void RecordOp::setMetric(::mlir::triton::proton::Metric attrValue) {
  getProperties().metric = ::mlir::triton::proton::MetricAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void RecordOp::setGranularity(::mlir::triton::proton::Granularity attrValue) {
  getProperties().granularity = ::mlir::triton::proton::GranularityAttr::get(::mlir::Builder((*this)->getContext()).getContext(), attrValue);
}

void RecordOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::BoolAttr isStart, ::mlir::IntegerAttr regionId, ::mlir::triton::proton::MetricAttr metric, ::mlir::triton::proton::GranularityAttr granularity) {
  odsState.getOrAddProperties<Properties>().isStart = isStart;
  odsState.getOrAddProperties<Properties>().regionId = regionId;
  if (metric) {
    odsState.getOrAddProperties<Properties>().metric = metric;
  }
  if (granularity) {
    odsState.getOrAddProperties<Properties>().granularity = granularity;
  }
}

void RecordOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::BoolAttr isStart, ::mlir::IntegerAttr regionId, ::mlir::triton::proton::MetricAttr metric, ::mlir::triton::proton::GranularityAttr granularity) {
  odsState.getOrAddProperties<Properties>().isStart = isStart;
  odsState.getOrAddProperties<Properties>().regionId = regionId;
  if (metric) {
    odsState.getOrAddProperties<Properties>().metric = metric;
  }
  if (granularity) {
    odsState.getOrAddProperties<Properties>().granularity = granularity;
  }
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void RecordOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, bool isStart, uint32_t regionId, ::mlir::triton::proton::Metric metric, ::mlir::triton::proton::Granularity granularity) {
  odsState.getOrAddProperties<Properties>().isStart = odsBuilder.getBoolAttr(isStart);
  odsState.getOrAddProperties<Properties>().regionId = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), regionId);
  odsState.getOrAddProperties<Properties>().metric = ::mlir::triton::proton::MetricAttr::get(odsBuilder.getContext(), metric);
  odsState.getOrAddProperties<Properties>().granularity = ::mlir::triton::proton::GranularityAttr::get(odsBuilder.getContext(), granularity);
}

void RecordOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, bool isStart, uint32_t regionId, ::mlir::triton::proton::Metric metric, ::mlir::triton::proton::Granularity granularity) {
  odsState.getOrAddProperties<Properties>().isStart = odsBuilder.getBoolAttr(isStart);
  odsState.getOrAddProperties<Properties>().regionId = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), regionId);
  odsState.getOrAddProperties<Properties>().metric = ::mlir::triton::proton::MetricAttr::get(odsBuilder.getContext(), metric);
  odsState.getOrAddProperties<Properties>().granularity = ::mlir::triton::proton::GranularityAttr::get(odsBuilder.getContext(), granularity);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void RecordOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<RecordOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

void RecordOp::populateDefaultProperties(::mlir::OperationName opName, Properties &properties) {
  ::mlir::Builder odsBuilder(opName.getContext());
  if (!properties.metric)
    properties.metric = ::mlir::triton::proton::MetricAttr::get(odsBuilder.getContext(), Metric::CYCLE);
  if (!properties.granularity)
    properties.granularity = ::mlir::triton::proton::GranularityAttr::get(odsBuilder.getContext(), Granularity::WARPGROUP);
}

::llvm::LogicalResult RecordOp::verifyInvariantsImpl() {
  auto tblgen_granularity = getProperties().granularity; (void)tblgen_granularity;
  auto tblgen_isStart = getProperties().isStart; (void)tblgen_isStart;
  if (!tblgen_isStart) return emitOpError("requires attribute 'isStart'");
  auto tblgen_metric = getProperties().metric; (void)tblgen_metric;
  auto tblgen_regionId = getProperties().regionId; (void)tblgen_regionId;
  if (!tblgen_regionId) return emitOpError("requires attribute 'regionId'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps1(*this, tblgen_isStart, "isStart")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps2(*this, tblgen_regionId, "regionId")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps3(*this, tblgen_metric, "metric")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_ProtonOps4(*this, tblgen_granularity, "granularity")))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::LogicalResult RecordOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult RecordOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::llvm::SmallVector<::mlir::OpAsmParser::UnresolvedOperand, 4> allOperands;
  if (parser.parseLParen())
    return ::mlir::failure();
  [[maybe_unused]] ::llvm::SMLoc allOperandLoc = parser.getCurrentLocation();
  if (parser.parseOperandList(allOperands))
    return ::mlir::failure();
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
  return ::mlir::success();
}

void RecordOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << "(";
  _odsPrinter << getOperation()->getOperands();
  _odsPrinter << ")";
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getMetricAttr();
     if(attr && (attr == ::mlir::triton::proton::MetricAttr::get(odsBuilder.getContext(), Metric::CYCLE)))
       elidedAttrs.push_back("metric");
  }
  {
     ::mlir::Builder odsBuilder(getContext());
     ::mlir::Attribute attr = getGranularityAttr();
     if(attr && (attr == ::mlir::triton::proton::GranularityAttr::get(odsBuilder.getContext(), Granularity::WARPGROUP)))
       elidedAttrs.push_back("granularity");
  }
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
}

} // namespace proton
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::proton::RecordOp)


#endif  // GET_OP_CLASSES

