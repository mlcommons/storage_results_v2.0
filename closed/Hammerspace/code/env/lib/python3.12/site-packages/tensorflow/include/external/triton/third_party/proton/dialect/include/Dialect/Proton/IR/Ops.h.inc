/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ProtonOps.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
namespace proton {
class RecordOp;
} // namespace proton
} // namespace triton
} // namespace mlir
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlir {
namespace triton {
namespace proton {

//===----------------------------------------------------------------------===//
// ::mlir::triton::proton::RecordOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RecordOpGenericAdaptorBase {
public:
  struct Properties {
    using granularityTy = ::mlir::triton::proton::GranularityAttr;
    granularityTy granularity;

    auto getGranularity() {
      auto &propStorage = this->granularity;
      return ::llvm::dyn_cast_or_null<::mlir::triton::proton::GranularityAttr>(propStorage);
    }
    void setGranularity(const ::mlir::triton::proton::GranularityAttr &propValue) {
      this->granularity = propValue;
    }
    using isStartTy = ::mlir::BoolAttr;
    isStartTy isStart;

    auto getIsStart() {
      auto &propStorage = this->isStart;
      return ::llvm::cast<::mlir::BoolAttr>(propStorage);
    }
    void setIsStart(const ::mlir::BoolAttr &propValue) {
      this->isStart = propValue;
    }
    using metricTy = ::mlir::triton::proton::MetricAttr;
    metricTy metric;

    auto getMetric() {
      auto &propStorage = this->metric;
      return ::llvm::dyn_cast_or_null<::mlir::triton::proton::MetricAttr>(propStorage);
    }
    void setMetric(const ::mlir::triton::proton::MetricAttr &propValue) {
      this->metric = propValue;
    }
    using regionIdTy = ::mlir::IntegerAttr;
    regionIdTy regionId;

    auto getRegionId() {
      auto &propStorage = this->regionId;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setRegionId(const ::mlir::IntegerAttr &propValue) {
      this->regionId = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.granularity == this->granularity &&
        rhs.isStart == this->isStart &&
        rhs.metric == this->metric &&
        rhs.regionId == this->regionId &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  RecordOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("proton.record", odsAttrs.getContext());
  }

  RecordOpGenericAdaptorBase(RecordOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getIsStartAttr() {
    auto attr = ::llvm::cast<::mlir::BoolAttr>(getProperties().isStart);
    return attr;
  }

  bool getIsStart();
  ::mlir::IntegerAttr getRegionIdAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().regionId);
    return attr;
  }

  uint32_t getRegionId();
  ::mlir::triton::proton::MetricAttr getMetricAttr();
  ::mlir::triton::proton::Metric getMetric();
  ::mlir::triton::proton::GranularityAttr getGranularityAttr();
  ::mlir::triton::proton::Granularity getGranularity();
};
} // namespace detail
template <typename RangeT>
class RecordOpGenericAdaptor : public detail::RecordOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RecordOpGenericAdaptorBase;
public:
  RecordOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RecordOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RecordOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RecordOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : RecordOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RecordOpGenericAdaptor(RangeT values, const RecordOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RecordOp, typename = std::enable_if_t<std::is_same_v<LateInst, RecordOp>>>
  RecordOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RecordOpAdaptor : public RecordOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RecordOpGenericAdaptor::RecordOpGenericAdaptor;
  RecordOpAdaptor(RecordOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RecordOp : public ::mlir::Op<RecordOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RecordOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RecordOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("granularity"), ::llvm::StringRef("isStart"), ::llvm::StringRef("metric"), ::llvm::StringRef("regionId")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getGranularityAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getGranularityAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIsStartAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIsStartAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getMetricAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getMetricAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getRegionIdAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getRegionIdAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("proton.record");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::BoolAttr getIsStartAttr() {
    return ::llvm::cast<::mlir::BoolAttr>(getProperties().isStart);
  }

  bool getIsStart();
  ::mlir::IntegerAttr getRegionIdAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().regionId);
  }

  uint32_t getRegionId();
  ::mlir::triton::proton::MetricAttr getMetricAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::triton::proton::MetricAttr>(getProperties().metric);
  }

  ::mlir::triton::proton::Metric getMetric();
  ::mlir::triton::proton::GranularityAttr getGranularityAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::triton::proton::GranularityAttr>(getProperties().granularity);
  }

  ::mlir::triton::proton::Granularity getGranularity();
  void setIsStartAttr(::mlir::BoolAttr attr) {
    getProperties().isStart = attr;
  }

  void setIsStart(bool attrValue);
  void setRegionIdAttr(::mlir::IntegerAttr attr) {
    getProperties().regionId = attr;
  }

  void setRegionId(uint32_t attrValue);
  void setMetricAttr(::mlir::triton::proton::MetricAttr attr) {
    getProperties().metric = attr;
  }

  void setMetric(::mlir::triton::proton::Metric attrValue);
  void setGranularityAttr(::mlir::triton::proton::GranularityAttr attr) {
    getProperties().granularity = attr;
  }

  void setGranularity(::mlir::triton::proton::Granularity attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::BoolAttr isStart, ::mlir::IntegerAttr regionId, ::mlir::triton::proton::MetricAttr metric = nullptr, ::mlir::triton::proton::GranularityAttr granularity = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::BoolAttr isStart, ::mlir::IntegerAttr regionId, ::mlir::triton::proton::MetricAttr metric = nullptr, ::mlir::triton::proton::GranularityAttr granularity = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, bool isStart, uint32_t regionId, ::mlir::triton::proton::Metric metric = Metric::CYCLE, ::mlir::triton::proton::Granularity granularity = Granularity::WARPGROUP);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, bool isStart, uint32_t regionId, ::mlir::triton::proton::Metric metric = Metric::CYCLE, ::mlir::triton::proton::Granularity granularity = Granularity::WARPGROUP);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace proton
} // namespace triton
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::proton::RecordOp)


#endif  // GET_OP_CLASSES

