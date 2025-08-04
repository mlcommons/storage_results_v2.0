/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: XeGPU.td                                                             *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace xegpu {
class AllocNbarrierOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class AtomicRMWOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class CreateDescOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class CreateNdDescOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class DpasOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class FenceOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class InitNbarrierOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class LoadGatherOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class LoadNdOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class NbarrierArriveOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class NbarrierWaitOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class PrefetchNdOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class PrefetchOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class StoreNdOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class StoreScatterOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class UpdateNdOffsetOp;
} // namespace xegpu
} // namespace mlir
namespace mlir {
namespace xegpu {
class UpdateOffsetOp;
} // namespace xegpu
} // namespace mlir
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::AllocNbarrierOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AllocNbarrierOpGenericAdaptorBase {
public:
  struct Properties {
    using nbarrier_numTy = ::mlir::IntegerAttr;
    nbarrier_numTy nbarrier_num;

    auto getNbarrierNum() {
      auto &propStorage = this->nbarrier_num;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setNbarrierNum(const ::mlir::IntegerAttr &propValue) {
      this->nbarrier_num = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.nbarrier_num == this->nbarrier_num &&
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
  AllocNbarrierOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.alloc_nbarrier", odsAttrs.getContext());
  }

  AllocNbarrierOpGenericAdaptorBase(AllocNbarrierOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getNbarrierNumAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().nbarrier_num);
    return attr;
  }

  uint64_t getNbarrierNum();
};
} // namespace detail
template <typename RangeT>
class AllocNbarrierOpGenericAdaptor : public detail::AllocNbarrierOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AllocNbarrierOpGenericAdaptorBase;
public:
  AllocNbarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AllocNbarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : AllocNbarrierOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AllocNbarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AllocNbarrierOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AllocNbarrierOpGenericAdaptor(RangeT values, const AllocNbarrierOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AllocNbarrierOp, typename = std::enable_if_t<std::is_same_v<LateInst, AllocNbarrierOp>>>
  AllocNbarrierOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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
class AllocNbarrierOpAdaptor : public AllocNbarrierOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AllocNbarrierOpGenericAdaptor::AllocNbarrierOpGenericAdaptor;
  AllocNbarrierOpAdaptor(AllocNbarrierOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AllocNbarrierOp : public ::mlir::Op<AllocNbarrierOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AllocNbarrierOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AllocNbarrierOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("nbarrier_num")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getNbarrierNumAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getNbarrierNumAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.alloc_nbarrier");
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
  ::mlir::IntegerAttr getNbarrierNumAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().nbarrier_num);
  }

  uint64_t getNbarrierNum();
  void setNbarrierNumAttr(::mlir::IntegerAttr attr) {
    getProperties().nbarrier_num = attr;
  }

  void setNbarrierNum(uint64_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::IntegerAttr nbarrier_num);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr nbarrier_num);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, uint64_t nbarrier_num);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, uint64_t nbarrier_num);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::AllocNbarrierOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::AtomicRMWOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AtomicRMWOpGenericAdaptorBase {
public:
  struct Properties {
    using kindTy = ::mlir::arith::AtomicRMWKindAttr;
    kindTy kind;

    auto getKind() {
      auto &propStorage = this->kind;
      return ::llvm::cast<::mlir::arith::AtomicRMWKindAttr>(propStorage);
    }
    void setKind(const ::mlir::arith::AtomicRMWKindAttr &propValue) {
      this->kind = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.kind == this->kind &&
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
  AtomicRMWOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.atomic_rmw", odsAttrs.getContext());
  }

  AtomicRMWOpGenericAdaptorBase(AtomicRMWOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::arith::AtomicRMWKindAttr getKindAttr() {
    auto attr = ::llvm::cast<::mlir::arith::AtomicRMWKindAttr>(getProperties().kind);
    return attr;
  }

  ::mlir::arith::AtomicRMWKind getKind();
};
} // namespace detail
template <typename RangeT>
class AtomicRMWOpGenericAdaptor : public detail::AtomicRMWOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AtomicRMWOpGenericAdaptorBase;
public:
  AtomicRMWOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AtomicRMWOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : AtomicRMWOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AtomicRMWOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AtomicRMWOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AtomicRMWOpGenericAdaptor(RangeT values, const AtomicRMWOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AtomicRMWOp, typename = std::enable_if_t<std::is_same_v<LateInst, AtomicRMWOp>>>
  AtomicRMWOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  ValueT getMask() {
    return (*getODSOperands(1).begin());
  }

  ValueT getValue() {
    return (*getODSOperands(2).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AtomicRMWOpAdaptor : public AtomicRMWOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AtomicRMWOpGenericAdaptor::AtomicRMWOpGenericAdaptor;
  AtomicRMWOpAdaptor(AtomicRMWOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AtomicRMWOp : public ::mlir::Op<AtomicRMWOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AtomicRMWOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AtomicRMWOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("kind")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getKindAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getKindAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.atomic_rmw");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getMask() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(2).begin());
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMaskMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(2);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSResults(0).begin());
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
  ::mlir::arith::AtomicRMWKindAttr getKindAttr() {
    return ::llvm::cast<::mlir::arith::AtomicRMWKindAttr>(getProperties().kind);
  }

  ::mlir::arith::AtomicRMWKind getKind();
  void setKindAttr(::mlir::arith::AtomicRMWKindAttr attr) {
    getProperties().kind = attr;
  }

  void setKind(::mlir::arith::AtomicRMWKind attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::arith::AtomicRMWKindAttr kind, ::mlir::Value tensorDesc, ::mlir::Value mask, ::mlir::Value value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::arith::AtomicRMWKindAttr kind, ::mlir::Value tensorDesc, ::mlir::Value mask, ::mlir::Value value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::arith::AtomicRMWKind kind, ::mlir::Value tensorDesc, ::mlir::Value mask, ::mlir::Value value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::arith::AtomicRMWKind kind, ::mlir::Value tensorDesc, ::mlir::Value mask, ::mlir::Value value);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::AtomicRMWOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::CreateDescOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class CreateDescOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  CreateDescOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.create_tdesc", odsAttrs.getContext());
  }

  CreateDescOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class CreateDescOpGenericAdaptor : public detail::CreateDescOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::CreateDescOpGenericAdaptorBase;
public:
  CreateDescOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  CreateDescOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : CreateDescOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  CreateDescOpGenericAdaptor(RangeT values, const CreateDescOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = CreateDescOp, typename = std::enable_if_t<std::is_same_v<LateInst, CreateDescOp>>>
  CreateDescOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSource() {
    return (*getODSOperands(0).begin());
  }

  ValueT getOffsets() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class CreateDescOpAdaptor : public CreateDescOpGenericAdaptor<::mlir::ValueRange> {
public:
  using CreateDescOpGenericAdaptor::CreateDescOpGenericAdaptor;
  CreateDescOpAdaptor(CreateDescOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class CreateDescOp : public ::mlir::Op<CreateDescOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::xegpu::TensorDescType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::ViewLikeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CreateDescOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = CreateDescOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.create_tdesc");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getSource() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::VectorType> getOffsets() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getSourceMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getOffsetsMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSResults(0).begin());
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, xegpu::TensorDescType TensorDesc, mlir::Value source, llvm::ArrayRef<OpFoldResult> offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, xegpu::TensorDescType TensorDesc, mlir::Value source, llvm::ArrayRef<int64_t> offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type TensorDesc, ::mlir::Value source, ::mlir::Value offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value offsets);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }

  mlir::VectorType getOffsetsType() {
    return getOffsets().getType();
  }

  size_t getNumOffsets() {
    return getOffsetsType().getNumElements();
  }

  mlir::Value getViewSource() { return getSource(); }

  unsigned getSourceMemorySpace() {
    auto srcTy = getSource().getType();
    if (auto memrefTy = llvm::dyn_cast<mlir::MemRefType>(srcTy)) {
      auto attr = memrefTy.getMemorySpace();
      if (attr) {
        if (auto intAttr = llvm::dyn_cast<mlir::IntegerAttr>(attr))
          return static_cast<unsigned>(intAttr.getInt());
        if (auto memSpaceAttr = llvm::dyn_cast<MemorySpaceAttr>(attr))
          return static_cast<unsigned>(memSpaceAttr.getValue());
      }
    }
    // take global as default memory scope.
    return static_cast<unsigned>(MemorySpace::Global);
  }

};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::CreateDescOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::CreateNdDescOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class CreateNdDescOpGenericAdaptorBase {
public:
  struct Properties {
    using const_offsetsTy = ::mlir::DenseI64ArrayAttr;
    const_offsetsTy const_offsets;

    auto getConstOffsets() {
      auto &propStorage = this->const_offsets;
      return ::llvm::cast<::mlir::DenseI64ArrayAttr>(propStorage);
    }
    void setConstOffsets(const ::mlir::DenseI64ArrayAttr &propValue) {
      this->const_offsets = propValue;
    }
    using const_shapeTy = ::mlir::DenseI64ArrayAttr;
    const_shapeTy const_shape;

    auto getConstShape() {
      auto &propStorage = this->const_shape;
      return ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(propStorage);
    }
    void setConstShape(const ::mlir::DenseI64ArrayAttr &propValue) {
      this->const_shape = propValue;
    }
    using const_stridesTy = ::mlir::DenseI64ArrayAttr;
    const_stridesTy const_strides;

    auto getConstStrides() {
      auto &propStorage = this->const_strides;
      return ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(propStorage);
    }
    void setConstStrides(const ::mlir::DenseI64ArrayAttr &propValue) {
      this->const_strides = propValue;
    }
    using operandSegmentSizesTy = std::array<int32_t, 4>;
    operandSegmentSizesTy operandSegmentSizes;
    ::llvm::ArrayRef<int32_t> getOperandSegmentSizes() const {
      auto &propStorage = this->operandSegmentSizes;
      return propStorage;
    }
    void setOperandSegmentSizes(::llvm::ArrayRef<int32_t> propValue) {
      auto &propStorage = this->operandSegmentSizes;
      ::llvm::copy(propValue, propStorage.begin());
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.const_offsets == this->const_offsets &&
        rhs.const_shape == this->const_shape &&
        rhs.const_strides == this->const_strides &&
        rhs.operandSegmentSizes == this->operandSegmentSizes &&
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
  CreateNdDescOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.create_nd_tdesc", odsAttrs.getContext());
  }

  CreateNdDescOpGenericAdaptorBase(CreateNdDescOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::DenseI64ArrayAttr getConstOffsetsAttr() {
    auto attr = ::llvm::cast<::mlir::DenseI64ArrayAttr>(getProperties().const_offsets);
    return attr;
  }

  ::llvm::ArrayRef<int64_t> getConstOffsets();
  ::mlir::DenseI64ArrayAttr getConstShapeAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(getProperties().const_shape);
    return attr;
  }

  ::std::optional<::llvm::ArrayRef<int64_t>> getConstShape();
  ::mlir::DenseI64ArrayAttr getConstStridesAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(getProperties().const_strides);
    return attr;
  }

  ::std::optional<::llvm::ArrayRef<int64_t>> getConstStrides();
};
} // namespace detail
template <typename RangeT>
class CreateNdDescOpGenericAdaptor : public detail::CreateNdDescOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::CreateNdDescOpGenericAdaptorBase;
public:
  CreateNdDescOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  CreateNdDescOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : CreateNdDescOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  CreateNdDescOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : CreateNdDescOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  CreateNdDescOpGenericAdaptor(RangeT values, const CreateNdDescOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = CreateNdDescOp, typename = std::enable_if_t<std::is_same_v<LateInst, CreateNdDescOp>>>
  CreateNdDescOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSource() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOffsets() {
    return getODSOperands(1);
  }

  RangeT getShape() {
    return getODSOperands(2);
  }

  RangeT getStrides() {
    return getODSOperands(3);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class CreateNdDescOpAdaptor : public CreateNdDescOpGenericAdaptor<::mlir::ValueRange> {
public:
  using CreateNdDescOpGenericAdaptor::CreateNdDescOpGenericAdaptor;
  CreateNdDescOpAdaptor(CreateNdDescOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class CreateNdDescOp : public ::mlir::Op<CreateNdDescOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::xegpu::TensorDescType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::ViewLikeOpInterface::Trait, ::mlir::OffsetSizeAndStrideOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CreateNdDescOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = CreateNdDescOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("const_offsets"), ::llvm::StringRef("const_shape"), ::llvm::StringRef("const_strides"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getConstOffsetsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getConstOffsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getConstShapeAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getConstShapeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getConstStridesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getConstStridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.create_nd_tdesc");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getSource() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::Operation::operand_range getOffsets() {
    return getODSOperands(1);
  }

  ::mlir::Operation::operand_range getShape() {
    return getODSOperands(2);
  }

  ::mlir::Operation::operand_range getStrides() {
    return getODSOperands(3);
  }

  ::mlir::OpOperand &getSourceMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getOffsetsMutable();
  ::mlir::MutableOperandRange getShapeMutable();
  ::mlir::MutableOperandRange getStridesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSResults(0).begin());
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
  ::mlir::DenseI64ArrayAttr getConstOffsetsAttr() {
    return ::llvm::cast<::mlir::DenseI64ArrayAttr>(getProperties().const_offsets);
  }

  ::llvm::ArrayRef<int64_t> getConstOffsets();
  ::mlir::DenseI64ArrayAttr getConstShapeAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(getProperties().const_shape);
  }

  ::std::optional<::llvm::ArrayRef<int64_t>> getConstShape();
  ::mlir::DenseI64ArrayAttr getConstStridesAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(getProperties().const_strides);
  }

  ::std::optional<::llvm::ArrayRef<int64_t>> getConstStrides();
  void setConstOffsetsAttr(::mlir::DenseI64ArrayAttr attr) {
    getProperties().const_offsets = attr;
  }

  void setConstOffsets(::llvm::ArrayRef<int64_t> attrValue);
  void setConstShapeAttr(::mlir::DenseI64ArrayAttr attr) {
    getProperties().const_shape = attr;
  }

  void setConstShape(::std::optional<::llvm::ArrayRef<int64_t>> attrValue);
  void setConstStridesAttr(::mlir::DenseI64ArrayAttr attr) {
    getProperties().const_strides = attr;
  }

  void setConstStrides(::std::optional<::llvm::ArrayRef<int64_t>> attrValue);
  ::mlir::Attribute removeConstShapeAttr() {
      auto &attr = getProperties().const_shape;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeConstStridesAttr() {
      auto &attr = getProperties().const_strides;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type tdesc, TypedValue<MemRefType> source, llvm::ArrayRef<OpFoldResult> offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type tdesc, TypedValue<MemRefType>  source, llvm::ArrayRef<OpFoldResult> offsets, llvm::ArrayRef<OpFoldResult> shape, llvm::ArrayRef<OpFoldResult> strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type tdesc, TypedValue<IntegerType>  source, llvm::ArrayRef<OpFoldResult> offsets, llvm::ArrayRef<OpFoldResult> shape, llvm::ArrayRef<OpFoldResult> strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type TensorDesc, ::mlir::Value source, ::mlir::ValueRange offsets, ::mlir::ValueRange shape, ::mlir::ValueRange strides, ::mlir::DenseI64ArrayAttr const_offsets, /*optional*/::mlir::DenseI64ArrayAttr const_shape, /*optional*/::mlir::DenseI64ArrayAttr const_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::ValueRange offsets, ::mlir::ValueRange shape, ::mlir::ValueRange strides, ::mlir::DenseI64ArrayAttr const_offsets, /*optional*/::mlir::DenseI64ArrayAttr const_shape, /*optional*/::mlir::DenseI64ArrayAttr const_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type TensorDesc, ::mlir::Value source, ::mlir::ValueRange offsets, ::mlir::ValueRange shape, ::mlir::ValueRange strides, ::llvm::ArrayRef<int64_t> const_offsets, /*optional*/::mlir::DenseI64ArrayAttr const_shape, /*optional*/::mlir::DenseI64ArrayAttr const_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::ValueRange offsets, ::mlir::ValueRange shape, ::mlir::ValueRange strides, ::llvm::ArrayRef<int64_t> const_offsets, /*optional*/::mlir::DenseI64ArrayAttr const_shape, /*optional*/::mlir::DenseI64ArrayAttr const_strides);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  /// Returns the type of the source memref operand.
  Type getSourceType() {
    return getSource().getType();
  }

  /// Returns the type of the result TensorDesc.
  xegpu::TensorDescType getType() {
    return getTensorDesc().getType();
  }

  /// Return the element type of the TensorDesc
  Type getElementType() {
    return getType().getElementType();
  }

  /// Return the shape of the TensorDesc
  llvm::ArrayRef<int64_t> getTensorDescShape() {
    return getType().getShape();
  }

  /// wrapper for matching with OffsetSizeAndStrideOpInterface
  OperandRange getSizes() {
    return getShape();
  }

  ArrayRef<int64_t> getStaticOffsets(){
    return getConstOffsets();
  }

  /// wrapper for matching with OffsetSizeAndStrideOpInterface
  /// If source is IntegerType or `const_shape` is filled,
  /// it will return `const_shape`, such that mixes of `shape`
  /// and `const_shape` will be used to represent the shape of
  /// source operand. They overide static shape from source memref type.
  ArrayRef<int64_t> getStaticSizes() {
    auto attr = getConstShapeAttr();
    if (llvm::isa<IntegerType>(getSourceType()) || attr)
      return attr;

    auto memrefType = llvm::dyn_cast<MemRefType>(getSourceType());
    assert(memrefType && "Incorrect use of getStaticSizes");
    return memrefType.getShape();
  }

  /// wrapper for matching with OffsetSizeAndStrideOpInterface
  /// If source is IntegerType or `const_strides` is filled, it
  /// will return `const_strides`, such that mixes of `strides`
  /// and `const_strides` will be used to represent the strides of
  /// source operand. They overide static strides from source memref type.
  ArrayRef<int64_t> getStaticStrides() {
    auto attr = getConstStridesAttr();
    if (llvm::isa<IntegerType>(getSourceType()) || attr)
      return attr;

    auto memrefType = llvm::dyn_cast<MemRefType>(getSourceType());
    assert(memrefType && "Incorrect use of getStaticStrides");
    auto [strides, offset] = memrefType.getStridesAndOffset();
    // reuse the storage of ConstStridesAttr since strides from
    // memref is not persistant
    setConstStrides(strides);
    attr = getConstStridesAttr();
    return attr;
  }

  /// Return the expected rank of each of the`static_offsets`,
  /// `static_shape` and `static_strides` attributes.
  std::array<unsigned, 3> getArrayAttrMaxRanks() {
    unsigned rank;
    if (auto ty = llvm::dyn_cast<MemRefType>(getSourceType())) {
      rank = ty.getRank();
    } else {
      rank = (unsigned)getMixedOffsets().size();
    }
    return {rank, rank, rank};
  }

  /// Return the number of leading operands before the `offsets`,
  /// `shape` and `strides` operands.
  static unsigned getOffsetSizeAndStrideStartOperandIndex() { return 1; }

  mlir::Value getViewSource() { return getSource(); }

  unsigned getSourceMemorySpace() {
    auto srcTy = getSourceType();
    if (auto memrefTy = llvm::dyn_cast<mlir::MemRefType>(srcTy)) {
      auto attr = memrefTy.getMemorySpace();
      if (attr) {
        if (auto intAttr = llvm::dyn_cast<mlir::IntegerAttr>(attr)) {
          return static_cast<unsigned>(intAttr.getInt());
        }
        if (auto memSpaceAttr = llvm::dyn_cast<MemorySpaceAttr>(attr))
          return static_cast<unsigned>(memSpaceAttr.getValue());
      }
    }
    // take global as default memory scope.
    return static_cast<unsigned>(MemorySpace::Global);
  }

};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::CreateNdDescOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::DpasOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DpasOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  DpasOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.dpas", odsAttrs.getContext());
  }

  DpasOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class DpasOpGenericAdaptor : public detail::DpasOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DpasOpGenericAdaptorBase;
public:
  DpasOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  DpasOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : DpasOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  DpasOpGenericAdaptor(RangeT values, const DpasOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = DpasOp, typename = std::enable_if_t<std::is_same_v<LateInst, DpasOp>>>
  DpasOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getLhs() {
    return (*getODSOperands(0).begin());
  }

  ValueT getRhs() {
    return (*getODSOperands(1).begin());
  }

  ValueT getAcc() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DpasOpAdaptor : public DpasOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DpasOpGenericAdaptor::DpasOpGenericAdaptor;
  DpasOpAdaptor(DpasOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class DpasOp : public ::mlir::Op<DpasOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::VectorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DpasOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DpasOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.dpas");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::VectorType> getLhs() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::VectorType> getRhs() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::VectorType> getAcc() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ::mlir::TypedValue<::mlir::VectorType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*operands.begin());
  }

  ::mlir::OpOperand &getLhsMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getRhsMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getAccMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::VectorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSResults(0).begin());
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs, /*optional*/::mlir::Value acc);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs, /*optional*/::mlir::Value acc);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  VectorType getLhsType() {
    return getLhs().getType();
  }

  VectorType getRhsType() {
    return getRhs().getType();
  }

  VectorType getAccType() {
    if (getAcc())
      return getAcc().getType();
    return {};
  }

  VectorType getResultType() {
    return getResult().getType();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::DpasOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::FenceOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class FenceOpGenericAdaptorBase {
public:
  struct Properties {
    using fence_scopeTy = ::mlir::xegpu::FenceScopeAttr;
    fence_scopeTy fence_scope;

    auto getFenceScope() {
      auto &propStorage = this->fence_scope;
      return ::llvm::cast<::mlir::xegpu::FenceScopeAttr>(propStorage);
    }
    void setFenceScope(const ::mlir::xegpu::FenceScopeAttr &propValue) {
      this->fence_scope = propValue;
    }
    using memory_kindTy = ::mlir::xegpu::MemorySpaceAttr;
    memory_kindTy memory_kind;

    auto getMemoryKind() {
      auto &propStorage = this->memory_kind;
      return ::llvm::cast<::mlir::xegpu::MemorySpaceAttr>(propStorage);
    }
    void setMemoryKind(const ::mlir::xegpu::MemorySpaceAttr &propValue) {
      this->memory_kind = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.fence_scope == this->fence_scope &&
        rhs.memory_kind == this->memory_kind &&
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
  FenceOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.fence", odsAttrs.getContext());
  }

  FenceOpGenericAdaptorBase(FenceOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::xegpu::MemorySpaceAttr getMemoryKindAttr() {
    auto attr = ::llvm::cast<::mlir::xegpu::MemorySpaceAttr>(getProperties().memory_kind);
    return attr;
  }

  ::mlir::xegpu::MemorySpace getMemoryKind();
  ::mlir::xegpu::FenceScopeAttr getFenceScopeAttr() {
    auto attr = ::llvm::cast<::mlir::xegpu::FenceScopeAttr>(getProperties().fence_scope);
    return attr;
  }

  ::mlir::xegpu::FenceScope getFenceScope();
};
} // namespace detail
template <typename RangeT>
class FenceOpGenericAdaptor : public detail::FenceOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::FenceOpGenericAdaptorBase;
public:
  FenceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  FenceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : FenceOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  FenceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : FenceOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  FenceOpGenericAdaptor(RangeT values, const FenceOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = FenceOp, typename = std::enable_if_t<std::is_same_v<LateInst, FenceOp>>>
  FenceOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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
class FenceOpAdaptor : public FenceOpGenericAdaptor<::mlir::ValueRange> {
public:
  using FenceOpGenericAdaptor::FenceOpGenericAdaptor;
  FenceOpAdaptor(FenceOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class FenceOp : public ::mlir::Op<FenceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = FenceOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = FenceOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("fence_scope"), ::llvm::StringRef("memory_kind")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getFenceScopeAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getFenceScopeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getMemoryKindAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getMemoryKindAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.fence");
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
  ::mlir::xegpu::MemorySpaceAttr getMemoryKindAttr() {
    return ::llvm::cast<::mlir::xegpu::MemorySpaceAttr>(getProperties().memory_kind);
  }

  ::mlir::xegpu::MemorySpace getMemoryKind();
  ::mlir::xegpu::FenceScopeAttr getFenceScopeAttr() {
    return ::llvm::cast<::mlir::xegpu::FenceScopeAttr>(getProperties().fence_scope);
  }

  ::mlir::xegpu::FenceScope getFenceScope();
  void setMemoryKindAttr(::mlir::xegpu::MemorySpaceAttr attr) {
    getProperties().memory_kind = attr;
  }

  void setMemoryKind(::mlir::xegpu::MemorySpace attrValue);
  void setFenceScopeAttr(::mlir::xegpu::FenceScopeAttr attr) {
    getProperties().fence_scope = attr;
  }

  void setFenceScope(::mlir::xegpu::FenceScope attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::xegpu::MemorySpaceAttr memory_kind, ::mlir::xegpu::FenceScopeAttr fence_scope);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::xegpu::MemorySpaceAttr memory_kind, ::mlir::xegpu::FenceScopeAttr fence_scope);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::xegpu::MemorySpace memory_kind, ::mlir::xegpu::FenceScope fence_scope);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::xegpu::MemorySpace memory_kind, ::mlir::xegpu::FenceScope fence_scope);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }

};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::FenceOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::InitNbarrierOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class InitNbarrierOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  InitNbarrierOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.init_nbarrier", odsAttrs.getContext());
  }

  InitNbarrierOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class InitNbarrierOpGenericAdaptor : public detail::InitNbarrierOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::InitNbarrierOpGenericAdaptorBase;
public:
  InitNbarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  InitNbarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : InitNbarrierOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  InitNbarrierOpGenericAdaptor(RangeT values, const InitNbarrierOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = InitNbarrierOp, typename = std::enable_if_t<std::is_same_v<LateInst, InitNbarrierOp>>>
  InitNbarrierOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getNbarrierId() {
    return (*getODSOperands(0).begin());
  }

  ValueT getParticipantThreadNum() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class InitNbarrierOpAdaptor : public InitNbarrierOpGenericAdaptor<::mlir::ValueRange> {
public:
  using InitNbarrierOpGenericAdaptor::InitNbarrierOpGenericAdaptor;
  InitNbarrierOpAdaptor(InitNbarrierOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class InitNbarrierOp : public ::mlir::Op<InitNbarrierOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::xegpu::NbarrierType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = InitNbarrierOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = InitNbarrierOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.init_nbarrier");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::IntegerType> getNbarrierId() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::IntegerType> getParticipantThreadNum() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getNbarrierIdMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getParticipantThreadNumMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::NbarrierType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::NbarrierType>>(*getODSResults(0).begin());
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value nbarrier_id, ::mlir::Value participant_thread_num);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value nbarrier_id, ::mlir::Value participant_thread_num);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::InitNbarrierOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::LoadGatherOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class LoadGatherOpGenericAdaptorBase {
public:
  struct Properties {
    using l1_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l1_hintTy l1_hint;

    auto getL1Hint() {
      auto &propStorage = this->l1_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL1Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l1_hint = propValue;
    }
    using l2_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l2_hintTy l2_hint;

    auto getL2Hint() {
      auto &propStorage = this->l2_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL2Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l2_hint = propValue;
    }
    using l3_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l3_hintTy l3_hint;

    auto getL3Hint() {
      auto &propStorage = this->l3_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL3Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l3_hint = propValue;
    }
    using transposeTy = ::mlir::UnitAttr;
    transposeTy transpose;

    auto getTranspose() {
      auto &propStorage = this->transpose;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setTranspose(const ::mlir::UnitAttr &propValue) {
      this->transpose = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.l1_hint == this->l1_hint &&
        rhs.l2_hint == this->l2_hint &&
        rhs.l3_hint == this->l3_hint &&
        rhs.transpose == this->transpose &&
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
  LoadGatherOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.load", odsAttrs.getContext());
  }

  LoadGatherOpGenericAdaptorBase(LoadGatherOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::UnitAttr getTransposeAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().transpose);
    return attr;
  }

  ::std::optional<bool> getTranspose();
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
};
} // namespace detail
template <typename RangeT>
class LoadGatherOpGenericAdaptor : public detail::LoadGatherOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::LoadGatherOpGenericAdaptorBase;
public:
  LoadGatherOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  LoadGatherOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : LoadGatherOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  LoadGatherOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : LoadGatherOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  LoadGatherOpGenericAdaptor(RangeT values, const LoadGatherOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = LoadGatherOp, typename = std::enable_if_t<std::is_same_v<LateInst, LoadGatherOp>>>
  LoadGatherOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  ValueT getMask() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class LoadGatherOpAdaptor : public LoadGatherOpGenericAdaptor<::mlir::ValueRange> {
public:
  using LoadGatherOpGenericAdaptor::LoadGatherOpGenericAdaptor;
  LoadGatherOpAdaptor(LoadGatherOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class LoadGatherOp : public ::mlir::Op<LoadGatherOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = LoadGatherOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = LoadGatherOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("l1_hint"), ::llvm::StringRef("l2_hint"), ::llvm::StringRef("l3_hint"), ::llvm::StringRef("transpose")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getL1HintAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getL1HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getL2HintAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getL2HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getL3HintAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getL3HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getTransposeAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getTransposeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.load");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getMask() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMaskMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSResults(0).begin());
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
  ::mlir::UnitAttr getTransposeAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().transpose);
  }

  ::std::optional<bool> getTranspose();
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
  void setTransposeAttr(::mlir::UnitAttr attr) {
    getProperties().transpose = attr;
  }

  void setTranspose(bool attrValue);
  void setL1HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l1_hint = attr;
  }

  void setL1Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL2HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l2_hint = attr;
  }

  void setL2Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL3HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l3_hint = attr;
  }

  void setL3Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  ::mlir::Attribute removeTransposeAttr() {
      auto &attr = getProperties().transpose;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL1HintAttr() {
      auto &attr = getProperties().l1_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL2HintAttr() {
      auto &attr = getProperties().l2_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL3HintAttr() {
      auto &attr = getProperties().l3_hint;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type value, ::mlir::Value TensorDesc, ::mlir::Value mask, /*optional*/::mlir::UnitAttr transpose, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, ::mlir::Value mask, /*optional*/::mlir::UnitAttr transpose, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }

  mlir::Type getElementType() {
    auto type = getValue().getType();
    return getElementTypeOrSelf(type);
  }

  Type getValueType() {
    return getValue().getType();
  }

  Type getMaskType() {
    return getMask().getType();
  }

};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::LoadGatherOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::LoadNdOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class LoadNdOpGenericAdaptorBase {
public:
  struct Properties {
    using l1_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l1_hintTy l1_hint;

    auto getL1Hint() {
      auto &propStorage = this->l1_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL1Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l1_hint = propValue;
    }
    using l2_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l2_hintTy l2_hint;

    auto getL2Hint() {
      auto &propStorage = this->l2_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL2Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l2_hint = propValue;
    }
    using l3_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l3_hintTy l3_hint;

    auto getL3Hint() {
      auto &propStorage = this->l3_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL3Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l3_hint = propValue;
    }
    using packedTy = ::mlir::UnitAttr;
    packedTy packed;

    auto getPacked() {
      auto &propStorage = this->packed;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setPacked(const ::mlir::UnitAttr &propValue) {
      this->packed = propValue;
    }
    using transposeTy = ::mlir::DenseI64ArrayAttr;
    transposeTy transpose;

    auto getTranspose() {
      auto &propStorage = this->transpose;
      return ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(propStorage);
    }
    void setTranspose(const ::mlir::DenseI64ArrayAttr &propValue) {
      this->transpose = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.l1_hint == this->l1_hint &&
        rhs.l2_hint == this->l2_hint &&
        rhs.l3_hint == this->l3_hint &&
        rhs.packed == this->packed &&
        rhs.transpose == this->transpose &&
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
  LoadNdOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.load_nd", odsAttrs.getContext());
  }

  LoadNdOpGenericAdaptorBase(LoadNdOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::UnitAttr getPackedAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().packed);
    return attr;
  }

  ::std::optional<bool> getPacked();
  ::mlir::DenseI64ArrayAttr getTransposeAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(getProperties().transpose);
    return attr;
  }

  ::std::optional<::llvm::ArrayRef<int64_t>> getTranspose();
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
};
} // namespace detail
template <typename RangeT>
class LoadNdOpGenericAdaptor : public detail::LoadNdOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::LoadNdOpGenericAdaptorBase;
public:
  LoadNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  LoadNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : LoadNdOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  LoadNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : LoadNdOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  LoadNdOpGenericAdaptor(RangeT values, const LoadNdOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = LoadNdOp, typename = std::enable_if_t<std::is_same_v<LateInst, LoadNdOp>>>
  LoadNdOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class LoadNdOpAdaptor : public LoadNdOpGenericAdaptor<::mlir::ValueRange> {
public:
  using LoadNdOpGenericAdaptor::LoadNdOpGenericAdaptor;
  LoadNdOpAdaptor(LoadNdOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class LoadNdOp : public ::mlir::Op<LoadNdOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = LoadNdOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = LoadNdOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("l1_hint"), ::llvm::StringRef("l2_hint"), ::llvm::StringRef("l3_hint"), ::llvm::StringRef("packed"), ::llvm::StringRef("transpose")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getL1HintAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getL1HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getL2HintAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getL2HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getL3HintAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getL3HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getPackedAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getPackedAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr getTransposeAttrName() {
    return getAttributeNameForIndex(4);
  }

  static ::mlir::StringAttr getTransposeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 4);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.load_nd");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSResults(0).begin());
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
  ::mlir::UnitAttr getPackedAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().packed);
  }

  ::std::optional<bool> getPacked();
  ::mlir::DenseI64ArrayAttr getTransposeAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::DenseI64ArrayAttr>(getProperties().transpose);
  }

  ::std::optional<::llvm::ArrayRef<int64_t>> getTranspose();
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
  void setPackedAttr(::mlir::UnitAttr attr) {
    getProperties().packed = attr;
  }

  void setPacked(bool attrValue);
  void setTransposeAttr(::mlir::DenseI64ArrayAttr attr) {
    getProperties().transpose = attr;
  }

  void setTranspose(::std::optional<::llvm::ArrayRef<int64_t>> attrValue);
  void setL1HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l1_hint = attr;
  }

  void setL1Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL2HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l2_hint = attr;
  }

  void setL2Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL3HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l3_hint = attr;
  }

  void setL3Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  ::mlir::Attribute removePackedAttr() {
      auto &attr = getProperties().packed;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeTransposeAttr() {
      auto &attr = getProperties().transpose;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL1HintAttr() {
      auto &attr = getProperties().l1_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL2HintAttr() {
      auto &attr = getProperties().l2_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL3HintAttr() {
      auto &attr = getProperties().l3_hint;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type value, ::mlir::Value TensorDesc, /*optional*/::mlir::UnitAttr packed, /*optional*/::mlir::DenseI64ArrayAttr transpose, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, /*optional*/::mlir::UnitAttr packed, /*optional*/::mlir::DenseI64ArrayAttr transpose, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 5 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  VectorType getType() {
    return llvm::dyn_cast<VectorType>(getValue().getType());
  }

  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::LoadNdOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::NbarrierArriveOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class NbarrierArriveOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  NbarrierArriveOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.nbarrier_arrive", odsAttrs.getContext());
  }

  NbarrierArriveOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class NbarrierArriveOpGenericAdaptor : public detail::NbarrierArriveOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::NbarrierArriveOpGenericAdaptorBase;
public:
  NbarrierArriveOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  NbarrierArriveOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : NbarrierArriveOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  NbarrierArriveOpGenericAdaptor(RangeT values, const NbarrierArriveOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = NbarrierArriveOp, typename = std::enable_if_t<std::is_same_v<LateInst, NbarrierArriveOp>>>
  NbarrierArriveOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getNbarrier() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class NbarrierArriveOpAdaptor : public NbarrierArriveOpGenericAdaptor<::mlir::ValueRange> {
public:
  using NbarrierArriveOpGenericAdaptor::NbarrierArriveOpGenericAdaptor;
  NbarrierArriveOpAdaptor(NbarrierArriveOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class NbarrierArriveOp : public ::mlir::Op<NbarrierArriveOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = NbarrierArriveOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = NbarrierArriveOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.nbarrier_arrive");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::NbarrierType> getNbarrier() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::NbarrierType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getNbarrierMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value nbarrier);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value nbarrier);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::NbarrierArriveOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::NbarrierWaitOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class NbarrierWaitOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  NbarrierWaitOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.nbarrier_wait", odsAttrs.getContext());
  }

  NbarrierWaitOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class NbarrierWaitOpGenericAdaptor : public detail::NbarrierWaitOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::NbarrierWaitOpGenericAdaptorBase;
public:
  NbarrierWaitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  NbarrierWaitOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : NbarrierWaitOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  NbarrierWaitOpGenericAdaptor(RangeT values, const NbarrierWaitOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = NbarrierWaitOp, typename = std::enable_if_t<std::is_same_v<LateInst, NbarrierWaitOp>>>
  NbarrierWaitOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getNbarrier() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class NbarrierWaitOpAdaptor : public NbarrierWaitOpGenericAdaptor<::mlir::ValueRange> {
public:
  using NbarrierWaitOpGenericAdaptor::NbarrierWaitOpGenericAdaptor;
  NbarrierWaitOpAdaptor(NbarrierWaitOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class NbarrierWaitOp : public ::mlir::Op<NbarrierWaitOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = NbarrierWaitOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = NbarrierWaitOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.nbarrier_wait");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::NbarrierType> getNbarrier() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::NbarrierType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getNbarrierMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value nbarrier);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value nbarrier);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::NbarrierWaitOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::PrefetchNdOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class PrefetchNdOpGenericAdaptorBase {
public:
  struct Properties {
    using l1_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l1_hintTy l1_hint;

    auto getL1Hint() {
      auto &propStorage = this->l1_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL1Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l1_hint = propValue;
    }
    using l2_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l2_hintTy l2_hint;

    auto getL2Hint() {
      auto &propStorage = this->l2_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL2Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l2_hint = propValue;
    }
    using l3_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l3_hintTy l3_hint;

    auto getL3Hint() {
      auto &propStorage = this->l3_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL3Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l3_hint = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.l1_hint == this->l1_hint &&
        rhs.l2_hint == this->l2_hint &&
        rhs.l3_hint == this->l3_hint &&
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
  PrefetchNdOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.prefetch_nd", odsAttrs.getContext());
  }

  PrefetchNdOpGenericAdaptorBase(PrefetchNdOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
};
} // namespace detail
template <typename RangeT>
class PrefetchNdOpGenericAdaptor : public detail::PrefetchNdOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::PrefetchNdOpGenericAdaptorBase;
public:
  PrefetchNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  PrefetchNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : PrefetchNdOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  PrefetchNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : PrefetchNdOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  PrefetchNdOpGenericAdaptor(RangeT values, const PrefetchNdOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = PrefetchNdOp, typename = std::enable_if_t<std::is_same_v<LateInst, PrefetchNdOp>>>
  PrefetchNdOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class PrefetchNdOpAdaptor : public PrefetchNdOpGenericAdaptor<::mlir::ValueRange> {
public:
  using PrefetchNdOpGenericAdaptor::PrefetchNdOpGenericAdaptor;
  PrefetchNdOpAdaptor(PrefetchNdOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class PrefetchNdOp : public ::mlir::Op<PrefetchNdOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PrefetchNdOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = PrefetchNdOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("l1_hint"), ::llvm::StringRef("l2_hint"), ::llvm::StringRef("l3_hint")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getL1HintAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getL1HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getL2HintAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getL2HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getL3HintAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getL3HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.prefetch_nd");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
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
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
  void setL1HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l1_hint = attr;
  }

  void setL1Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL2HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l2_hint = attr;
  }

  void setL2Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL3HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l3_hint = attr;
  }

  void setL3Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  ::mlir::Attribute removeL1HintAttr() {
      auto &attr = getProperties().l1_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL2HintAttr() {
      auto &attr = getProperties().l2_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL3HintAttr() {
      auto &attr = getProperties().l3_hint;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value TensorDesc, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::PrefetchNdOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::PrefetchOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class PrefetchOpGenericAdaptorBase {
public:
  struct Properties {
    using l1_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l1_hintTy l1_hint;

    auto getL1Hint() {
      auto &propStorage = this->l1_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL1Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l1_hint = propValue;
    }
    using l2_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l2_hintTy l2_hint;

    auto getL2Hint() {
      auto &propStorage = this->l2_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL2Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l2_hint = propValue;
    }
    using l3_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l3_hintTy l3_hint;

    auto getL3Hint() {
      auto &propStorage = this->l3_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL3Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l3_hint = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.l1_hint == this->l1_hint &&
        rhs.l2_hint == this->l2_hint &&
        rhs.l3_hint == this->l3_hint &&
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
  PrefetchOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.prefetch", odsAttrs.getContext());
  }

  PrefetchOpGenericAdaptorBase(PrefetchOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
};
} // namespace detail
template <typename RangeT>
class PrefetchOpGenericAdaptor : public detail::PrefetchOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::PrefetchOpGenericAdaptorBase;
public:
  PrefetchOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  PrefetchOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : PrefetchOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  PrefetchOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : PrefetchOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  PrefetchOpGenericAdaptor(RangeT values, const PrefetchOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = PrefetchOp, typename = std::enable_if_t<std::is_same_v<LateInst, PrefetchOp>>>
  PrefetchOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class PrefetchOpAdaptor : public PrefetchOpGenericAdaptor<::mlir::ValueRange> {
public:
  using PrefetchOpGenericAdaptor::PrefetchOpGenericAdaptor;
  PrefetchOpAdaptor(PrefetchOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class PrefetchOp : public ::mlir::Op<PrefetchOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PrefetchOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = PrefetchOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("l1_hint"), ::llvm::StringRef("l2_hint"), ::llvm::StringRef("l3_hint")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getL1HintAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getL1HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getL2HintAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getL2HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getL3HintAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getL3HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.prefetch");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
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
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
  void setL1HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l1_hint = attr;
  }

  void setL1Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL2HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l2_hint = attr;
  }

  void setL2Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL3HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l3_hint = attr;
  }

  void setL3Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  ::mlir::Attribute removeL1HintAttr() {
      auto &attr = getProperties().l1_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL2HintAttr() {
      auto &attr = getProperties().l2_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL3HintAttr() {
      auto &attr = getProperties().l3_hint;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value TensorDesc, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::PrefetchOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::StoreNdOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class StoreNdOpGenericAdaptorBase {
public:
  struct Properties {
    using l1_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l1_hintTy l1_hint;

    auto getL1Hint() {
      auto &propStorage = this->l1_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL1Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l1_hint = propValue;
    }
    using l2_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l2_hintTy l2_hint;

    auto getL2Hint() {
      auto &propStorage = this->l2_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL2Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l2_hint = propValue;
    }
    using l3_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l3_hintTy l3_hint;

    auto getL3Hint() {
      auto &propStorage = this->l3_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL3Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l3_hint = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.l1_hint == this->l1_hint &&
        rhs.l2_hint == this->l2_hint &&
        rhs.l3_hint == this->l3_hint &&
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
  StoreNdOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.store_nd", odsAttrs.getContext());
  }

  StoreNdOpGenericAdaptorBase(StoreNdOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
};
} // namespace detail
template <typename RangeT>
class StoreNdOpGenericAdaptor : public detail::StoreNdOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::StoreNdOpGenericAdaptorBase;
public:
  StoreNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  StoreNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : StoreNdOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  StoreNdOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : StoreNdOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  StoreNdOpGenericAdaptor(RangeT values, const StoreNdOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = StoreNdOp, typename = std::enable_if_t<std::is_same_v<LateInst, StoreNdOp>>>
  StoreNdOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getValue() {
    return (*getODSOperands(0).begin());
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class StoreNdOpAdaptor : public StoreNdOpGenericAdaptor<::mlir::ValueRange> {
public:
  using StoreNdOpGenericAdaptor::StoreNdOpGenericAdaptor;
  StoreNdOpAdaptor(StoreNdOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class StoreNdOp : public ::mlir::Op<StoreNdOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = StoreNdOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = StoreNdOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("l1_hint"), ::llvm::StringRef("l2_hint"), ::llvm::StringRef("l3_hint")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getL1HintAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getL1HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getL2HintAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getL2HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getL3HintAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getL3HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.store_nd");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
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
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
  void setL1HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l1_hint = attr;
  }

  void setL1Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL2HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l2_hint = attr;
  }

  void setL2Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL3HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l3_hint = attr;
  }

  void setL3Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  ::mlir::Attribute removeL1HintAttr() {
      auto &attr = getProperties().l1_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL2HintAttr() {
      auto &attr = getProperties().l2_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL3HintAttr() {
      auto &attr = getProperties().l3_hint;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value TensorDesc, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value TensorDesc, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  VectorType getValueType() {
    return llvm::dyn_cast<VectorType>(getValue().getType());
  }

  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::StoreNdOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::StoreScatterOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class StoreScatterOpGenericAdaptorBase {
public:
  struct Properties {
    using l1_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l1_hintTy l1_hint;

    auto getL1Hint() {
      auto &propStorage = this->l1_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL1Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l1_hint = propValue;
    }
    using l2_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l2_hintTy l2_hint;

    auto getL2Hint() {
      auto &propStorage = this->l2_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL2Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l2_hint = propValue;
    }
    using l3_hintTy = ::mlir::xegpu::CachePolicyAttr;
    l3_hintTy l3_hint;

    auto getL3Hint() {
      auto &propStorage = this->l3_hint;
      return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(propStorage);
    }
    void setL3Hint(const ::mlir::xegpu::CachePolicyAttr &propValue) {
      this->l3_hint = propValue;
    }
    using transposeTy = ::mlir::UnitAttr;
    transposeTy transpose;

    auto getTranspose() {
      auto &propStorage = this->transpose;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setTranspose(const ::mlir::UnitAttr &propValue) {
      this->transpose = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.l1_hint == this->l1_hint &&
        rhs.l2_hint == this->l2_hint &&
        rhs.l3_hint == this->l3_hint &&
        rhs.transpose == this->transpose &&
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
  StoreScatterOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.store", odsAttrs.getContext());
  }

  StoreScatterOpGenericAdaptorBase(StoreScatterOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::UnitAttr getTransposeAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().transpose);
    return attr;
  }

  ::std::optional<bool> getTranspose();
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
    return attr;
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
};
} // namespace detail
template <typename RangeT>
class StoreScatterOpGenericAdaptor : public detail::StoreScatterOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::StoreScatterOpGenericAdaptorBase;
public:
  StoreScatterOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  StoreScatterOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : StoreScatterOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  StoreScatterOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : StoreScatterOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  StoreScatterOpGenericAdaptor(RangeT values, const StoreScatterOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = StoreScatterOp, typename = std::enable_if_t<std::is_same_v<LateInst, StoreScatterOp>>>
  StoreScatterOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getValue() {
    return (*getODSOperands(0).begin());
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(1).begin());
  }

  ValueT getMask() {
    return (*getODSOperands(2).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class StoreScatterOpAdaptor : public StoreScatterOpGenericAdaptor<::mlir::ValueRange> {
public:
  using StoreScatterOpGenericAdaptor::StoreScatterOpGenericAdaptor;
  StoreScatterOpAdaptor(StoreScatterOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class StoreScatterOp : public ::mlir::Op<StoreScatterOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = StoreScatterOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = StoreScatterOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("l1_hint"), ::llvm::StringRef("l2_hint"), ::llvm::StringRef("l3_hint"), ::llvm::StringRef("transpose")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getL1HintAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getL1HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getL2HintAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getL2HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getL3HintAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getL3HintAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getTransposeAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getTransposeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.store");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getMask() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(2).begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMaskMutable() {
    auto range = getODSOperandIndexAndLength(2);
    return getOperation()->getOpOperand(range.first);
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
  ::mlir::UnitAttr getTransposeAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().transpose);
  }

  ::std::optional<bool> getTranspose();
  ::mlir::xegpu::CachePolicyAttr getL1HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l1_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL1Hint();
  ::mlir::xegpu::CachePolicyAttr getL2HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l2_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL2Hint();
  ::mlir::xegpu::CachePolicyAttr getL3HintAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::xegpu::CachePolicyAttr>(getProperties().l3_hint);
  }

  ::std::optional<::mlir::xegpu::CachePolicy> getL3Hint();
  void setTransposeAttr(::mlir::UnitAttr attr) {
    getProperties().transpose = attr;
  }

  void setTranspose(bool attrValue);
  void setL1HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l1_hint = attr;
  }

  void setL1Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL2HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l2_hint = attr;
  }

  void setL2Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  void setL3HintAttr(::mlir::xegpu::CachePolicyAttr attr) {
    getProperties().l3_hint = attr;
  }

  void setL3Hint(::std::optional<::mlir::xegpu::CachePolicy> attrValue);
  ::mlir::Attribute removeTransposeAttr() {
      auto &attr = getProperties().transpose;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL1HintAttr() {
      auto &attr = getProperties().l1_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL2HintAttr() {
      auto &attr = getProperties().l2_hint;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeL3HintAttr() {
      auto &attr = getProperties().l3_hint;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value TensorDesc, ::mlir::Value mask, /*optional*/::mlir::UnitAttr transpose, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value TensorDesc, ::mlir::Value mask, /*optional*/::mlir::UnitAttr transpose, /*optional*/::mlir::xegpu::CachePolicyAttr l1_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l2_hint, /*optional*/::mlir::xegpu::CachePolicyAttr l3_hint);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }

  Type getValueType() {
    return getValue().getType();
  }

  Type getMaskType() {
    return getMask().getType();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::StoreScatterOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::UpdateNdOffsetOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class UpdateNdOffsetOpGenericAdaptorBase {
public:
  struct Properties {
    using const_offsetsTy = ::mlir::DenseI64ArrayAttr;
    const_offsetsTy const_offsets;

    auto getConstOffsets() {
      auto &propStorage = this->const_offsets;
      return ::llvm::cast<::mlir::DenseI64ArrayAttr>(propStorage);
    }
    void setConstOffsets(const ::mlir::DenseI64ArrayAttr &propValue) {
      this->const_offsets = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.const_offsets == this->const_offsets &&
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
  UpdateNdOffsetOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.update_nd_offset", odsAttrs.getContext());
  }

  UpdateNdOffsetOpGenericAdaptorBase(UpdateNdOffsetOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::DenseI64ArrayAttr getConstOffsetsAttr() {
    auto attr = ::llvm::cast<::mlir::DenseI64ArrayAttr>(getProperties().const_offsets);
    return attr;
  }

  ::llvm::ArrayRef<int64_t> getConstOffsets();
};
} // namespace detail
template <typename RangeT>
class UpdateNdOffsetOpGenericAdaptor : public detail::UpdateNdOffsetOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::UpdateNdOffsetOpGenericAdaptorBase;
public:
  UpdateNdOffsetOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  UpdateNdOffsetOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : UpdateNdOffsetOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  UpdateNdOffsetOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : UpdateNdOffsetOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  UpdateNdOffsetOpGenericAdaptor(RangeT values, const UpdateNdOffsetOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = UpdateNdOffsetOp, typename = std::enable_if_t<std::is_same_v<LateInst, UpdateNdOffsetOp>>>
  UpdateNdOffsetOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOffsets() {
    return getODSOperands(1);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class UpdateNdOffsetOpAdaptor : public UpdateNdOffsetOpGenericAdaptor<::mlir::ValueRange> {
public:
  using UpdateNdOffsetOpGenericAdaptor::UpdateNdOffsetOpGenericAdaptor;
  UpdateNdOffsetOpAdaptor(UpdateNdOffsetOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class UpdateNdOffsetOp : public ::mlir::Op<UpdateNdOffsetOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::xegpu::TensorDescType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = UpdateNdOffsetOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = UpdateNdOffsetOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("const_offsets")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getConstOffsetsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getConstOffsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.update_nd_offset");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::Operation::operand_range getOffsets() {
    return getODSOperands(1);
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getOffsetsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSResults(0).begin());
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
  ::mlir::DenseI64ArrayAttr getConstOffsetsAttr() {
    return ::llvm::cast<::mlir::DenseI64ArrayAttr>(getProperties().const_offsets);
  }

  ::llvm::ArrayRef<int64_t> getConstOffsets();
  void setConstOffsetsAttr(::mlir::DenseI64ArrayAttr attr) {
    getProperties().const_offsets = attr;
  }

  void setConstOffsets(::llvm::ArrayRef<int64_t> attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value TensorDesc, ::mlir::ValueRange offsets, ::mlir::DenseI64ArrayAttr const_offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, ::mlir::ValueRange offsets, ::mlir::DenseI64ArrayAttr const_offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value TensorDesc, ::mlir::ValueRange offsets, ::llvm::ArrayRef<int64_t> const_offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, ::mlir::ValueRange offsets, ::llvm::ArrayRef<int64_t> const_offsets);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  void printProperties(::mlir::MLIRContext *ctx,
          ::mlir::OpAsmPrinter &p, const Properties &prop,
          ::mlir::ArrayRef<::llvm::StringRef> elidedProps) {
    Attribute propAttr = getPropertiesAsAttr(ctx, prop);
    if (propAttr)
      p << "<" << propAttr << ">";
  }

  static ::mlir::ParseResult parseProperties(::mlir::OpAsmParser &parser,
                                   ::mlir::OperationState &result) {
    if (mlir::succeeded(parser.parseOptionalLess())) {
      if (parser.parseAttribute(result.propertiesAttr) || parser.parseGreater())
        return failure();
    }
    return success();
  }


  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }

  SmallVector<OpFoldResult> getMixedOffsets() {
    Builder b(getContext());
    return getMixedValues(getConstOffsets(), getOffsets(), b);
  }

  size_t getNumOffsets() {
    return getMixedOffsets().size();
  }

  OpFoldResult getOffset(unsigned idx) {
    assert(idx < getNumOffsets() && "Invalid out of bound access.");
    return getMixedOffsets()[idx];
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::UpdateNdOffsetOp)

namespace mlir {
namespace xegpu {

//===----------------------------------------------------------------------===//
// ::mlir::xegpu::UpdateOffsetOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class UpdateOffsetOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  UpdateOffsetOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("xegpu.update_offset", odsAttrs.getContext());
  }

  UpdateOffsetOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class UpdateOffsetOpGenericAdaptor : public detail::UpdateOffsetOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::UpdateOffsetOpGenericAdaptorBase;
public:
  UpdateOffsetOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  UpdateOffsetOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : UpdateOffsetOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  UpdateOffsetOpGenericAdaptor(RangeT values, const UpdateOffsetOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = UpdateOffsetOp, typename = std::enable_if_t<std::is_same_v<LateInst, UpdateOffsetOp>>>
  UpdateOffsetOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensorDesc() {
    return (*getODSOperands(0).begin());
  }

  ValueT getOffsets() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class UpdateOffsetOpAdaptor : public UpdateOffsetOpGenericAdaptor<::mlir::ValueRange> {
public:
  using UpdateOffsetOpGenericAdaptor::UpdateOffsetOpGenericAdaptor;
  UpdateOffsetOpAdaptor(UpdateOffsetOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class UpdateOffsetOp : public ::mlir::Op<UpdateOffsetOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::xegpu::TensorDescType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = UpdateOffsetOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = UpdateOffsetOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("xegpu.update_offset");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getTensorDesc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::VectorType> getOffsets() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getTensorDescMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getOffsetsMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::xegpu::TensorDescType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::xegpu::TensorDescType>>(*getODSResults(0).begin());
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, mlir::Value TensorDesc, llvm::ArrayRef<OpFoldResult> offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, mlir::Value TensorDesc, llvm::ArrayRef<int64_t> offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value TensorDesc, ::mlir::Value offsets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value TensorDesc, ::mlir::Value offsets);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
  xegpu::TensorDescType getTensorDescType() {
    return getTensorDesc().getType();
  }

  mlir::VectorType getOffsetsType() {
    return getOffsets().getType();
  }

  size_t getNumOffsets() {
    return getOffsetsType().getNumElements();
  }
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::UpdateOffsetOp)


#endif  // GET_OP_CLASSES

