/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: AMDGPU.td                                                            *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace amdgpu {
class DPPOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class ExtPackedFp8Op;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class LDSBarrierOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class MFMAOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class PackedStochRoundFp8Op;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class PackedTrunc2xFp8Op;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferAtomicCmpswapOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferAtomicFaddOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferAtomicFmaxOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferAtomicSmaxOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferAtomicUminOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferLoadOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class RawBufferStoreOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class SchedBarrierOp;
} // namespace amdgpu
} // namespace mlir
namespace mlir {
namespace amdgpu {
class WMMAOp;
} // namespace amdgpu
} // namespace mlir
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::DPPOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DPPOpGenericAdaptorBase {
public:
  struct Properties {
    using bank_maskTy = ::mlir::IntegerAttr;
    bank_maskTy bank_mask;

    auto getBankMask() {
      auto &propStorage = this->bank_mask;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setBankMask(const ::mlir::IntegerAttr &propValue) {
      this->bank_mask = propValue;
    }
    using bound_ctrlTy = ::mlir::BoolAttr;
    bound_ctrlTy bound_ctrl;

    auto getBoundCtrl() {
      auto &propStorage = this->bound_ctrl;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundCtrl(const ::mlir::BoolAttr &propValue) {
      this->bound_ctrl = propValue;
    }
    using kindTy = ::mlir::amdgpu::DPPPermAttr;
    kindTy kind;

    auto getKind() {
      auto &propStorage = this->kind;
      return ::llvm::cast<::mlir::amdgpu::DPPPermAttr>(propStorage);
    }
    void setKind(const ::mlir::amdgpu::DPPPermAttr &propValue) {
      this->kind = propValue;
    }
    using permArgumentTy = ::mlir::Attribute;
    permArgumentTy permArgument;

    auto getPermArgument() {
      auto &propStorage = this->permArgument;
      return ::llvm::dyn_cast_or_null<::mlir::Attribute>(propStorage);
    }
    void setPermArgument(const ::mlir::Attribute &propValue) {
      this->permArgument = propValue;
    }
    using row_maskTy = ::mlir::IntegerAttr;
    row_maskTy row_mask;

    auto getRowMask() {
      auto &propStorage = this->row_mask;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setRowMask(const ::mlir::IntegerAttr &propValue) {
      this->row_mask = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.bank_mask == this->bank_mask &&
        rhs.bound_ctrl == this->bound_ctrl &&
        rhs.kind == this->kind &&
        rhs.permArgument == this->permArgument &&
        rhs.row_mask == this->row_mask &&
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
  DPPOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.dpp", odsAttrs.getContext());
  }

  DPPOpGenericAdaptorBase(DPPOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::amdgpu::DPPPermAttr getKindAttr() {
    auto attr = ::llvm::cast<::mlir::amdgpu::DPPPermAttr>(getProperties().kind);
    return attr;
  }

  ::mlir::amdgpu::DPPPerm getKind();
  ::mlir::Attribute getPermArgumentAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::Attribute>(getProperties().permArgument);
    return attr;
  }

  ::std::optional<::mlir::Attribute> getPermArgument();
  ::mlir::IntegerAttr getRowMaskAttr();
  uint32_t getRowMask();
  ::mlir::IntegerAttr getBankMaskAttr();
  uint32_t getBankMask();
  ::mlir::BoolAttr getBoundCtrlAttr();
  bool getBoundCtrl();
};
} // namespace detail
template <typename RangeT>
class DPPOpGenericAdaptor : public detail::DPPOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DPPOpGenericAdaptorBase;
public:
  DPPOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  DPPOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : DPPOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  DPPOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : DPPOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  DPPOpGenericAdaptor(RangeT values, const DPPOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = DPPOp, typename = std::enable_if_t<std::is_same_v<LateInst, DPPOp>>>
  DPPOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getOld() {
    return (*getODSOperands(0).begin());
  }

  ValueT getSrc() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DPPOpAdaptor : public DPPOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DPPOpGenericAdaptor::DPPOpGenericAdaptor;
  DPPOpAdaptor(DPPOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class DPPOp : public ::mlir::Op<DPPOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameTypeOperands> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DPPOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DPPOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("bank_mask"), ::llvm::StringRef("bound_ctrl"), ::llvm::StringRef("kind"), ::llvm::StringRef("permArgument"), ::llvm::StringRef("row_mask")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBankMaskAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBankMaskAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getBoundCtrlAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getBoundCtrlAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getKindAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getKindAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getPermArgumentAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getPermArgumentAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr getRowMaskAttrName() {
    return getAttributeNameForIndex(4);
  }

  static ::mlir::StringAttr getRowMaskAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 4);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.dpp");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getOld() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getSrc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getOldMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getSrcMutable() {
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
  ::mlir::amdgpu::DPPPermAttr getKindAttr() {
    return ::llvm::cast<::mlir::amdgpu::DPPPermAttr>(getProperties().kind);
  }

  ::mlir::amdgpu::DPPPerm getKind();
  ::mlir::Attribute getPermArgumentAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::Attribute>(getProperties().permArgument);
  }

  ::std::optional<::mlir::Attribute> getPermArgument();
  ::mlir::IntegerAttr getRowMaskAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().row_mask);
  }

  uint32_t getRowMask();
  ::mlir::IntegerAttr getBankMaskAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().bank_mask);
  }

  uint32_t getBankMask();
  ::mlir::BoolAttr getBoundCtrlAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().bound_ctrl);
  }

  bool getBoundCtrl();
  void setKindAttr(::mlir::amdgpu::DPPPermAttr attr) {
    getProperties().kind = attr;
  }

  void setKind(::mlir::amdgpu::DPPPerm attrValue);
  void setPermArgumentAttr(::mlir::Attribute attr) {
    getProperties().permArgument = attr;
  }

  void setRowMaskAttr(::mlir::IntegerAttr attr) {
    getProperties().row_mask = attr;
  }

  void setRowMask(uint32_t attrValue);
  void setBankMaskAttr(::mlir::IntegerAttr attr) {
    getProperties().bank_mask = attr;
  }

  void setBankMask(uint32_t attrValue);
  void setBoundCtrlAttr(::mlir::BoolAttr attr) {
    getProperties().bound_ctrl = attr;
  }

  void setBoundCtrl(bool attrValue);
  ::mlir::Attribute removePermArgumentAttr() {
      auto &attr = getProperties().permArgument;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value old, ::mlir::Value src, ::mlir::amdgpu::DPPPermAttr kind, /*optional*/::mlir::Attribute permArgument, ::mlir::IntegerAttr row_mask = nullptr, ::mlir::IntegerAttr bank_mask = nullptr, ::mlir::BoolAttr bound_ctrl = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value old, ::mlir::Value src, ::mlir::amdgpu::DPPPermAttr kind, /*optional*/::mlir::Attribute permArgument, ::mlir::IntegerAttr row_mask = nullptr, ::mlir::IntegerAttr bank_mask = nullptr, ::mlir::BoolAttr bound_ctrl = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value old, ::mlir::Value src, ::mlir::amdgpu::DPPPerm kind, /*optional*/::mlir::Attribute permArgument, uint32_t row_mask = 0xf, uint32_t bank_mask = 0xf, bool bound_ctrl = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value old, ::mlir::Value src, ::mlir::amdgpu::DPPPerm kind, /*optional*/::mlir::Attribute permArgument, uint32_t row_mask = 0xf, uint32_t bank_mask = 0xf, bool bound_ctrl = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
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
    assert(index < 5 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::DPPOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::ExtPackedFp8Op declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ExtPackedFp8OpGenericAdaptorBase {
public:
  struct Properties {
    using indexTy = ::mlir::IntegerAttr;
    indexTy index;

    auto getIndex() {
      auto &propStorage = this->index;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setIndex(const ::mlir::IntegerAttr &propValue) {
      this->index = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.index == this->index &&
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
  ExtPackedFp8OpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.ext_packed_fp8", odsAttrs.getContext());
  }

  ExtPackedFp8OpGenericAdaptorBase(ExtPackedFp8Op op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getIndexAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().index);
    return attr;
  }

  uint32_t getIndex();
};
} // namespace detail
template <typename RangeT>
class ExtPackedFp8OpGenericAdaptor : public detail::ExtPackedFp8OpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ExtPackedFp8OpGenericAdaptorBase;
public:
  ExtPackedFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ExtPackedFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ExtPackedFp8OpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ExtPackedFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ExtPackedFp8OpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ExtPackedFp8OpGenericAdaptor(RangeT values, const ExtPackedFp8OpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ExtPackedFp8Op, typename = std::enable_if_t<std::is_same_v<LateInst, ExtPackedFp8Op>>>
  ExtPackedFp8OpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ExtPackedFp8OpAdaptor : public ExtPackedFp8OpGenericAdaptor<::mlir::ValueRange> {
public:
  using ExtPackedFp8OpGenericAdaptor::ExtPackedFp8OpGenericAdaptor;
  ExtPackedFp8OpAdaptor(ExtPackedFp8Op op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ExtPackedFp8Op : public ::mlir::Op<ExtPackedFp8Op, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::FloatType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ExtPackedFp8OpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ExtPackedFp8OpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("index")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getIndexAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getIndexAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.ext_packed_fp8");
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

  ::mlir::OpOperand &getSourceMutable() {
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

  ::mlir::TypedValue<::mlir::FloatType> getRes() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::FloatType>>(*getODSResults(0).begin());
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
  ::mlir::IntegerAttr getIndexAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().index);
  }

  uint32_t getIndex();
  void setIndexAttr(::mlir::IntegerAttr attr) {
    getProperties().index = attr;
  }

  void setIndex(uint32_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value source, ::mlir::IntegerAttr index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::IntegerAttr index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value source, uint32_t index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, uint32_t index);
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
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::ExtPackedFp8Op)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::LDSBarrierOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class LDSBarrierOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  LDSBarrierOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.lds_barrier", odsAttrs.getContext());
  }

  LDSBarrierOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class LDSBarrierOpGenericAdaptor : public detail::LDSBarrierOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::LDSBarrierOpGenericAdaptorBase;
public:
  LDSBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  LDSBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : LDSBarrierOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  LDSBarrierOpGenericAdaptor(RangeT values, const LDSBarrierOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = LDSBarrierOp, typename = std::enable_if_t<std::is_same_v<LateInst, LDSBarrierOp>>>
  LDSBarrierOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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
class LDSBarrierOpAdaptor : public LDSBarrierOpGenericAdaptor<::mlir::ValueRange> {
public:
  using LDSBarrierOpGenericAdaptor::LDSBarrierOpGenericAdaptor;
  LDSBarrierOpAdaptor(LDSBarrierOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class LDSBarrierOp : public ::mlir::Op<LDSBarrierOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = LDSBarrierOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = LDSBarrierOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.lds_barrier");
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

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::LDSBarrierOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::MFMAOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MFMAOpGenericAdaptorBase {
public:
  struct Properties {
    using abidTy = ::mlir::IntegerAttr;
    abidTy abid;

    auto getAbid() {
      auto &propStorage = this->abid;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setAbid(const ::mlir::IntegerAttr &propValue) {
      this->abid = propValue;
    }
    using blgpTy = ::mlir::amdgpu::MFMAPermBAttr;
    blgpTy blgp;

    auto getBlgp() {
      auto &propStorage = this->blgp;
      return ::llvm::dyn_cast_or_null<::mlir::amdgpu::MFMAPermBAttr>(propStorage);
    }
    void setBlgp(const ::mlir::amdgpu::MFMAPermBAttr &propValue) {
      this->blgp = propValue;
    }
    using blocksTy = ::mlir::IntegerAttr;
    blocksTy blocks;

    auto getBlocks() {
      auto &propStorage = this->blocks;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setBlocks(const ::mlir::IntegerAttr &propValue) {
      this->blocks = propValue;
    }
    using cbszTy = ::mlir::IntegerAttr;
    cbszTy cbsz;

    auto getCbsz() {
      auto &propStorage = this->cbsz;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setCbsz(const ::mlir::IntegerAttr &propValue) {
      this->cbsz = propValue;
    }
    using kTy = ::mlir::IntegerAttr;
    kTy k;

    auto getK() {
      auto &propStorage = this->k;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setK(const ::mlir::IntegerAttr &propValue) {
      this->k = propValue;
    }
    using mTy = ::mlir::IntegerAttr;
    mTy m;

    auto getM() {
      auto &propStorage = this->m;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setM(const ::mlir::IntegerAttr &propValue) {
      this->m = propValue;
    }
    using nTy = ::mlir::IntegerAttr;
    nTy n;

    auto getN() {
      auto &propStorage = this->n;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setN(const ::mlir::IntegerAttr &propValue) {
      this->n = propValue;
    }
    using negateATy = ::mlir::UnitAttr;
    negateATy negateA;

    auto getNegateA() {
      auto &propStorage = this->negateA;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setNegateA(const ::mlir::UnitAttr &propValue) {
      this->negateA = propValue;
    }
    using negateBTy = ::mlir::UnitAttr;
    negateBTy negateB;

    auto getNegateB() {
      auto &propStorage = this->negateB;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setNegateB(const ::mlir::UnitAttr &propValue) {
      this->negateB = propValue;
    }
    using negateCTy = ::mlir::UnitAttr;
    negateCTy negateC;

    auto getNegateC() {
      auto &propStorage = this->negateC;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setNegateC(const ::mlir::UnitAttr &propValue) {
      this->negateC = propValue;
    }
    using reducePrecisionTy = ::mlir::UnitAttr;
    reducePrecisionTy reducePrecision;

    auto getReducePrecision() {
      auto &propStorage = this->reducePrecision;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setReducePrecision(const ::mlir::UnitAttr &propValue) {
      this->reducePrecision = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.abid == this->abid &&
        rhs.blgp == this->blgp &&
        rhs.blocks == this->blocks &&
        rhs.cbsz == this->cbsz &&
        rhs.k == this->k &&
        rhs.m == this->m &&
        rhs.n == this->n &&
        rhs.negateA == this->negateA &&
        rhs.negateB == this->negateB &&
        rhs.negateC == this->negateC &&
        rhs.reducePrecision == this->reducePrecision &&
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
  MFMAOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.mfma", odsAttrs.getContext());
  }

  MFMAOpGenericAdaptorBase(MFMAOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getMAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().m);
    return attr;
  }

  uint32_t getM();
  ::mlir::IntegerAttr getNAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().n);
    return attr;
  }

  uint32_t getN();
  ::mlir::IntegerAttr getKAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().k);
    return attr;
  }

  uint32_t getK();
  ::mlir::IntegerAttr getBlocksAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().blocks);
    return attr;
  }

  uint32_t getBlocks();
  ::mlir::IntegerAttr getCbszAttr();
  uint32_t getCbsz();
  ::mlir::IntegerAttr getAbidAttr();
  uint32_t getAbid();
  ::mlir::amdgpu::MFMAPermBAttr getBlgpAttr();
  ::mlir::amdgpu::MFMAPermB getBlgp();
  ::mlir::UnitAttr getReducePrecisionAttr();
  bool getReducePrecision();
  ::mlir::UnitAttr getNegateAAttr();
  bool getNegateA();
  ::mlir::UnitAttr getNegateBAttr();
  bool getNegateB();
  ::mlir::UnitAttr getNegateCAttr();
  bool getNegateC();
};
} // namespace detail
template <typename RangeT>
class MFMAOpGenericAdaptor : public detail::MFMAOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MFMAOpGenericAdaptorBase;
public:
  MFMAOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MFMAOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MFMAOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  MFMAOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : MFMAOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  MFMAOpGenericAdaptor(RangeT values, const MFMAOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = MFMAOp, typename = std::enable_if_t<std::is_same_v<LateInst, MFMAOp>>>
  MFMAOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSourceA() {
    return (*getODSOperands(0).begin());
  }

  ValueT getSourceB() {
    return (*getODSOperands(1).begin());
  }

  ValueT getDestC() {
    return (*getODSOperands(2).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MFMAOpAdaptor : public MFMAOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MFMAOpGenericAdaptor::MFMAOpGenericAdaptor;
  MFMAOpAdaptor(MFMAOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class MFMAOp : public ::mlir::Op<MFMAOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MFMAOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MFMAOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("abid"), ::llvm::StringRef("blgp"), ::llvm::StringRef("blocks"), ::llvm::StringRef("cbsz"), ::llvm::StringRef("k"), ::llvm::StringRef("m"), ::llvm::StringRef("n"), ::llvm::StringRef("negateA"), ::llvm::StringRef("negateB"), ::llvm::StringRef("negateC"), ::llvm::StringRef("reducePrecision")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getAbidAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAbidAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getBlgpAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getBlgpAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getBlocksAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getBlocksAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getCbszAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getCbszAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr getKAttrName() {
    return getAttributeNameForIndex(4);
  }

  static ::mlir::StringAttr getKAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 4);
  }

  ::mlir::StringAttr getMAttrName() {
    return getAttributeNameForIndex(5);
  }

  static ::mlir::StringAttr getMAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 5);
  }

  ::mlir::StringAttr getNAttrName() {
    return getAttributeNameForIndex(6);
  }

  static ::mlir::StringAttr getNAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 6);
  }

  ::mlir::StringAttr getNegateAAttrName() {
    return getAttributeNameForIndex(7);
  }

  static ::mlir::StringAttr getNegateAAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 7);
  }

  ::mlir::StringAttr getNegateBAttrName() {
    return getAttributeNameForIndex(8);
  }

  static ::mlir::StringAttr getNegateBAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 8);
  }

  ::mlir::StringAttr getNegateCAttrName() {
    return getAttributeNameForIndex(9);
  }

  static ::mlir::StringAttr getNegateCAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 9);
  }

  ::mlir::StringAttr getReducePrecisionAttrName() {
    return getAttributeNameForIndex(10);
  }

  static ::mlir::StringAttr getReducePrecisionAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 10);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.mfma");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getSourceA() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getSourceB() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getDestC() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(2).begin());
  }

  ::mlir::OpOperand &getSourceAMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getSourceBMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getDestCMutable() {
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

  ::mlir::TypedValue<::mlir::Type> getDestD() {
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
  ::mlir::IntegerAttr getMAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().m);
  }

  uint32_t getM();
  ::mlir::IntegerAttr getNAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().n);
  }

  uint32_t getN();
  ::mlir::IntegerAttr getKAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().k);
  }

  uint32_t getK();
  ::mlir::IntegerAttr getBlocksAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().blocks);
  }

  uint32_t getBlocks();
  ::mlir::IntegerAttr getCbszAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().cbsz);
  }

  uint32_t getCbsz();
  ::mlir::IntegerAttr getAbidAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().abid);
  }

  uint32_t getAbid();
  ::mlir::amdgpu::MFMAPermBAttr getBlgpAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::amdgpu::MFMAPermBAttr>(getProperties().blgp);
  }

  ::mlir::amdgpu::MFMAPermB getBlgp();
  ::mlir::UnitAttr getReducePrecisionAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().reducePrecision);
  }

  bool getReducePrecision();
  ::mlir::UnitAttr getNegateAAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().negateA);
  }

  bool getNegateA();
  ::mlir::UnitAttr getNegateBAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().negateB);
  }

  bool getNegateB();
  ::mlir::UnitAttr getNegateCAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().negateC);
  }

  bool getNegateC();
  void setMAttr(::mlir::IntegerAttr attr) {
    getProperties().m = attr;
  }

  void setM(uint32_t attrValue);
  void setNAttr(::mlir::IntegerAttr attr) {
    getProperties().n = attr;
  }

  void setN(uint32_t attrValue);
  void setKAttr(::mlir::IntegerAttr attr) {
    getProperties().k = attr;
  }

  void setK(uint32_t attrValue);
  void setBlocksAttr(::mlir::IntegerAttr attr) {
    getProperties().blocks = attr;
  }

  void setBlocks(uint32_t attrValue);
  void setCbszAttr(::mlir::IntegerAttr attr) {
    getProperties().cbsz = attr;
  }

  void setCbsz(uint32_t attrValue);
  void setAbidAttr(::mlir::IntegerAttr attr) {
    getProperties().abid = attr;
  }

  void setAbid(uint32_t attrValue);
  void setBlgpAttr(::mlir::amdgpu::MFMAPermBAttr attr) {
    getProperties().blgp = attr;
  }

  void setBlgp(::mlir::amdgpu::MFMAPermB attrValue);
  void setReducePrecisionAttr(::mlir::UnitAttr attr) {
    getProperties().reducePrecision = attr;
  }

  void setReducePrecision(bool attrValue);
  void setNegateAAttr(::mlir::UnitAttr attr) {
    getProperties().negateA = attr;
  }

  void setNegateA(bool attrValue);
  void setNegateBAttr(::mlir::UnitAttr attr) {
    getProperties().negateB = attr;
  }

  void setNegateB(bool attrValue);
  void setNegateCAttr(::mlir::UnitAttr attr) {
    getProperties().negateC = attr;
  }

  void setNegateC(bool attrValue);
  ::mlir::Attribute removeReducePrecisionAttr() {
      auto &attr = getProperties().reducePrecision;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeNegateAAttr() {
      auto &attr = getProperties().negateA;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeNegateBAttr() {
      auto &attr = getProperties().negateB;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeNegateCAttr() {
      auto &attr = getProperties().negateC;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type destD, ::mlir::IntegerAttr m, ::mlir::IntegerAttr n, ::mlir::IntegerAttr k, ::mlir::IntegerAttr blocks, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, ::mlir::IntegerAttr cbsz = nullptr, ::mlir::IntegerAttr abid = nullptr, ::mlir::amdgpu::MFMAPermBAttr blgp = nullptr, /*optional*/::mlir::UnitAttr reducePrecision = nullptr, /*optional*/::mlir::UnitAttr negateA = nullptr, /*optional*/::mlir::UnitAttr negateB = nullptr, /*optional*/::mlir::UnitAttr negateC = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr m, ::mlir::IntegerAttr n, ::mlir::IntegerAttr k, ::mlir::IntegerAttr blocks, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, ::mlir::IntegerAttr cbsz = nullptr, ::mlir::IntegerAttr abid = nullptr, ::mlir::amdgpu::MFMAPermBAttr blgp = nullptr, /*optional*/::mlir::UnitAttr reducePrecision = nullptr, /*optional*/::mlir::UnitAttr negateA = nullptr, /*optional*/::mlir::UnitAttr negateB = nullptr, /*optional*/::mlir::UnitAttr negateC = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type destD, uint32_t m, uint32_t n, uint32_t k, uint32_t blocks, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, uint32_t cbsz = 0, uint32_t abid = 0, ::mlir::amdgpu::MFMAPermB blgp = ::mlir::amdgpu::MFMAPermB::none, /*optional*/bool reducePrecision = false, /*optional*/bool negateA = false, /*optional*/bool negateB = false, /*optional*/bool negateC = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, uint32_t m, uint32_t n, uint32_t k, uint32_t blocks, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, uint32_t cbsz = 0, uint32_t abid = 0, ::mlir::amdgpu::MFMAPermB blgp = ::mlir::amdgpu::MFMAPermB::none, /*optional*/bool reducePrecision = false, /*optional*/bool negateA = false, /*optional*/bool negateB = false, /*optional*/bool negateC = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
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
    assert(index < 11 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::MFMAOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::PackedStochRoundFp8Op declarations
//===----------------------------------------------------------------------===//

namespace detail {
class PackedStochRoundFp8OpGenericAdaptorBase {
public:
  struct Properties {
    using storeIndexTy = ::mlir::IntegerAttr;
    storeIndexTy storeIndex;

    auto getStoreIndex() {
      auto &propStorage = this->storeIndex;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setStoreIndex(const ::mlir::IntegerAttr &propValue) {
      this->storeIndex = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.storeIndex == this->storeIndex &&
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
  PackedStochRoundFp8OpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.packed_stoch_round_fp8", odsAttrs.getContext());
  }

  PackedStochRoundFp8OpGenericAdaptorBase(PackedStochRoundFp8Op op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getStoreIndexAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().storeIndex);
    return attr;
  }

  uint32_t getStoreIndex();
};
} // namespace detail
template <typename RangeT>
class PackedStochRoundFp8OpGenericAdaptor : public detail::PackedStochRoundFp8OpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::PackedStochRoundFp8OpGenericAdaptorBase;
public:
  PackedStochRoundFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  PackedStochRoundFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : PackedStochRoundFp8OpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  PackedStochRoundFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : PackedStochRoundFp8OpGenericAdaptor(values, attrs, Properties{}, {}) {}

  PackedStochRoundFp8OpGenericAdaptor(RangeT values, const PackedStochRoundFp8OpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = PackedStochRoundFp8Op, typename = std::enable_if_t<std::is_same_v<LateInst, PackedStochRoundFp8Op>>>
  PackedStochRoundFp8OpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  ValueT getStochiasticParam() {
    return (*getODSOperands(1).begin());
  }

  ValueT getExisting() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class PackedStochRoundFp8OpAdaptor : public PackedStochRoundFp8OpGenericAdaptor<::mlir::ValueRange> {
public:
  using PackedStochRoundFp8OpGenericAdaptor::PackedStochRoundFp8OpGenericAdaptor;
  PackedStochRoundFp8OpAdaptor(PackedStochRoundFp8Op op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class PackedStochRoundFp8Op : public ::mlir::Op<PackedStochRoundFp8Op, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::VectorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PackedStochRoundFp8OpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = PackedStochRoundFp8OpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("storeIndex")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getStoreIndexAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getStoreIndexAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.packed_stoch_round_fp8");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::FloatType> getSource() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::FloatType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::IntegerType> getStochiasticParam() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::VectorType> getExisting() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ::mlir::TypedValue<::mlir::VectorType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*operands.begin());
  }

  ::mlir::OpOperand &getSourceMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getStochiasticParamMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getExistingMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::VectorType> getRes() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSResults(0).begin());
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
  ::mlir::IntegerAttr getStoreIndexAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().storeIndex);
  }

  uint32_t getStoreIndex();
  void setStoreIndexAttr(::mlir::IntegerAttr attr) {
    getProperties().storeIndex = attr;
  }

  void setStoreIndex(uint32_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value source, ::mlir::Value stochiasticParam, ::mlir::IntegerAttr storeIndex, /*optional*/::mlir::Value existing);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value stochiasticParam, ::mlir::IntegerAttr storeIndex, /*optional*/::mlir::Value existing);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value source, ::mlir::Value stochiasticParam, uint32_t storeIndex, /*optional*/::mlir::Value existing);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value stochiasticParam, uint32_t storeIndex, /*optional*/::mlir::Value existing);
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
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::PackedStochRoundFp8Op)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::PackedTrunc2xFp8Op declarations
//===----------------------------------------------------------------------===//

namespace detail {
class PackedTrunc2xFp8OpGenericAdaptorBase {
public:
  struct Properties {
    using wordIndexTy = ::mlir::IntegerAttr;
    wordIndexTy wordIndex;

    auto getWordIndex() {
      auto &propStorage = this->wordIndex;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setWordIndex(const ::mlir::IntegerAttr &propValue) {
      this->wordIndex = propValue;
    }
    using operandSegmentSizesTy = std::array<int32_t, 3>;
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
        rhs.wordIndex == this->wordIndex &&
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
  PackedTrunc2xFp8OpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.packed_trunc_2xfp8", odsAttrs.getContext());
  }

  PackedTrunc2xFp8OpGenericAdaptorBase(PackedTrunc2xFp8Op op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getWordIndexAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().wordIndex);
    return attr;
  }

  uint32_t getWordIndex();
};
} // namespace detail
template <typename RangeT>
class PackedTrunc2xFp8OpGenericAdaptor : public detail::PackedTrunc2xFp8OpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::PackedTrunc2xFp8OpGenericAdaptorBase;
public:
  PackedTrunc2xFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  PackedTrunc2xFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : PackedTrunc2xFp8OpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  PackedTrunc2xFp8OpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : PackedTrunc2xFp8OpGenericAdaptor(values, attrs, Properties{}, {}) {}

  PackedTrunc2xFp8OpGenericAdaptor(RangeT values, const PackedTrunc2xFp8OpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = PackedTrunc2xFp8Op, typename = std::enable_if_t<std::is_same_v<LateInst, PackedTrunc2xFp8Op>>>
  PackedTrunc2xFp8OpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSourceA() {
    return (*getODSOperands(0).begin());
  }

  ValueT getSourceB() {
    auto operands = getODSOperands(1);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  ValueT getExisting() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class PackedTrunc2xFp8OpAdaptor : public PackedTrunc2xFp8OpGenericAdaptor<::mlir::ValueRange> {
public:
  using PackedTrunc2xFp8OpGenericAdaptor::PackedTrunc2xFp8OpGenericAdaptor;
  PackedTrunc2xFp8OpAdaptor(PackedTrunc2xFp8Op op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class PackedTrunc2xFp8Op : public ::mlir::Op<PackedTrunc2xFp8Op, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::VectorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PackedTrunc2xFp8OpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = PackedTrunc2xFp8OpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("wordIndex"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getWordIndexAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getWordIndexAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.packed_trunc_2xfp8");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::FloatType> getSourceA() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::FloatType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::FloatType> getSourceB() {
    auto operands = getODSOperands(1);
    return operands.empty() ? ::mlir::TypedValue<::mlir::FloatType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::FloatType>>(*operands.begin());
  }

  ::mlir::TypedValue<::mlir::VectorType> getExisting() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ::mlir::TypedValue<::mlir::VectorType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*operands.begin());
  }

  ::mlir::OpOperand &getSourceAMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getSourceBMutable();
  ::mlir::MutableOperandRange getExistingMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::VectorType> getRes() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::VectorType>>(*getODSResults(0).begin());
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
  ::mlir::IntegerAttr getWordIndexAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().wordIndex);
  }

  uint32_t getWordIndex();
  void setWordIndexAttr(::mlir::IntegerAttr attr) {
    getProperties().wordIndex = attr;
  }

  void setWordIndex(uint32_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value sourceA, /*optional*/::mlir::Value sourceB, ::mlir::IntegerAttr wordIndex, /*optional*/::mlir::Value existing);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value sourceA, /*optional*/::mlir::Value sourceB, ::mlir::IntegerAttr wordIndex, /*optional*/::mlir::Value existing);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type res, ::mlir::Value sourceA, /*optional*/::mlir::Value sourceB, uint32_t wordIndex, /*optional*/::mlir::Value existing);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value sourceA, /*optional*/::mlir::Value sourceB, uint32_t wordIndex, /*optional*/::mlir::Value existing);
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
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::PackedTrunc2xFp8Op)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferAtomicCmpswapOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferAtomicCmpswapOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
    }
    using operandSegmentSizesTy = std::array<int32_t, 5>;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferAtomicCmpswapOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_atomic_cmpswap", odsAttrs.getContext());
  }

  RawBufferAtomicCmpswapOpGenericAdaptorBase(RawBufferAtomicCmpswapOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferAtomicCmpswapOpGenericAdaptor : public detail::RawBufferAtomicCmpswapOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferAtomicCmpswapOpGenericAdaptorBase;
public:
  RawBufferAtomicCmpswapOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferAtomicCmpswapOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferAtomicCmpswapOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferAtomicCmpswapOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferAtomicCmpswapOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferAtomicCmpswapOpGenericAdaptor(RangeT values, const RawBufferAtomicCmpswapOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferAtomicCmpswapOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferAtomicCmpswapOp>>>
  RawBufferAtomicCmpswapOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSrc() {
    return (*getODSOperands(0).begin());
  }

  ValueT getCmp() {
    return (*getODSOperands(1).begin());
  }

  ValueT getMemref() {
    return (*getODSOperands(2).begin());
  }

  RangeT getIndices() {
    return getODSOperands(3);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(4);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferAtomicCmpswapOpAdaptor : public RawBufferAtomicCmpswapOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferAtomicCmpswapOpGenericAdaptor::RawBufferAtomicCmpswapOpGenericAdaptor;
  RawBufferAtomicCmpswapOpAdaptor(RawBufferAtomicCmpswapOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferAtomicCmpswapOp : public ::mlir::Op<RawBufferAtomicCmpswapOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<3>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferAtomicCmpswapOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferAtomicCmpswapOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_atomic_cmpswap");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getSrc() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getCmp() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(2).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(3);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(4);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getSrcMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getCmpMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(2);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type value, ::mlir::Value src, ::mlir::Value cmp, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value src, ::mlir::Value cmp, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type value, ::mlir::Value src, ::mlir::Value cmp, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value src, ::mlir::Value cmp, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferAtomicCmpswapOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferAtomicFaddOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferAtomicFaddOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferAtomicFaddOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_atomic_fadd", odsAttrs.getContext());
  }

  RawBufferAtomicFaddOpGenericAdaptorBase(RawBufferAtomicFaddOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferAtomicFaddOpGenericAdaptor : public detail::RawBufferAtomicFaddOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferAtomicFaddOpGenericAdaptorBase;
public:
  RawBufferAtomicFaddOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferAtomicFaddOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferAtomicFaddOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferAtomicFaddOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferAtomicFaddOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferAtomicFaddOpGenericAdaptor(RangeT values, const RawBufferAtomicFaddOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferAtomicFaddOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferAtomicFaddOp>>>
  RawBufferAtomicFaddOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  ValueT getMemref() {
    return (*getODSOperands(1).begin());
  }

  RangeT getIndices() {
    return getODSOperands(2);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferAtomicFaddOpAdaptor : public RawBufferAtomicFaddOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferAtomicFaddOpGenericAdaptor::RawBufferAtomicFaddOpGenericAdaptor;
  RawBufferAtomicFaddOpAdaptor(RawBufferAtomicFaddOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferAtomicFaddOp : public ::mlir::Op<RawBufferAtomicFaddOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferAtomicFaddOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferAtomicFaddOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_atomic_fadd");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(2);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferAtomicFaddOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferAtomicFmaxOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferAtomicFmaxOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferAtomicFmaxOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_atomic_fmax", odsAttrs.getContext());
  }

  RawBufferAtomicFmaxOpGenericAdaptorBase(RawBufferAtomicFmaxOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferAtomicFmaxOpGenericAdaptor : public detail::RawBufferAtomicFmaxOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferAtomicFmaxOpGenericAdaptorBase;
public:
  RawBufferAtomicFmaxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferAtomicFmaxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferAtomicFmaxOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferAtomicFmaxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferAtomicFmaxOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferAtomicFmaxOpGenericAdaptor(RangeT values, const RawBufferAtomicFmaxOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferAtomicFmaxOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferAtomicFmaxOp>>>
  RawBufferAtomicFmaxOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  ValueT getMemref() {
    return (*getODSOperands(1).begin());
  }

  RangeT getIndices() {
    return getODSOperands(2);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferAtomicFmaxOpAdaptor : public RawBufferAtomicFmaxOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferAtomicFmaxOpGenericAdaptor::RawBufferAtomicFmaxOpGenericAdaptor;
  RawBufferAtomicFmaxOpAdaptor(RawBufferAtomicFmaxOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferAtomicFmaxOp : public ::mlir::Op<RawBufferAtomicFmaxOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferAtomicFmaxOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferAtomicFmaxOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_atomic_fmax");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(2);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferAtomicFmaxOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferAtomicSmaxOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferAtomicSmaxOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferAtomicSmaxOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_atomic_smax", odsAttrs.getContext());
  }

  RawBufferAtomicSmaxOpGenericAdaptorBase(RawBufferAtomicSmaxOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferAtomicSmaxOpGenericAdaptor : public detail::RawBufferAtomicSmaxOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferAtomicSmaxOpGenericAdaptorBase;
public:
  RawBufferAtomicSmaxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferAtomicSmaxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferAtomicSmaxOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferAtomicSmaxOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferAtomicSmaxOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferAtomicSmaxOpGenericAdaptor(RangeT values, const RawBufferAtomicSmaxOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferAtomicSmaxOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferAtomicSmaxOp>>>
  RawBufferAtomicSmaxOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  ValueT getMemref() {
    return (*getODSOperands(1).begin());
  }

  RangeT getIndices() {
    return getODSOperands(2);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferAtomicSmaxOpAdaptor : public RawBufferAtomicSmaxOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferAtomicSmaxOpGenericAdaptor::RawBufferAtomicSmaxOpGenericAdaptor;
  RawBufferAtomicSmaxOpAdaptor(RawBufferAtomicSmaxOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferAtomicSmaxOp : public ::mlir::Op<RawBufferAtomicSmaxOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferAtomicSmaxOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferAtomicSmaxOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_atomic_smax");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::IntegerType> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(2);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferAtomicSmaxOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferAtomicUminOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferAtomicUminOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferAtomicUminOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_atomic_umin", odsAttrs.getContext());
  }

  RawBufferAtomicUminOpGenericAdaptorBase(RawBufferAtomicUminOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferAtomicUminOpGenericAdaptor : public detail::RawBufferAtomicUminOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferAtomicUminOpGenericAdaptorBase;
public:
  RawBufferAtomicUminOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferAtomicUminOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferAtomicUminOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferAtomicUminOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferAtomicUminOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferAtomicUminOpGenericAdaptor(RangeT values, const RawBufferAtomicUminOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferAtomicUminOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferAtomicUminOp>>>
  RawBufferAtomicUminOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  ValueT getMemref() {
    return (*getODSOperands(1).begin());
  }

  RangeT getIndices() {
    return getODSOperands(2);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferAtomicUminOpAdaptor : public RawBufferAtomicUminOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferAtomicUminOpGenericAdaptor::RawBufferAtomicUminOpGenericAdaptor;
  RawBufferAtomicUminOpAdaptor(RawBufferAtomicUminOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferAtomicUminOp : public ::mlir::Op<RawBufferAtomicUminOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferAtomicUminOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferAtomicUminOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_atomic_umin");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::IntegerType> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(2);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferAtomicUminOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferLoadOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferLoadOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
    }
    using operandSegmentSizesTy = std::array<int32_t, 3>;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferLoadOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_load", odsAttrs.getContext());
  }

  RawBufferLoadOpGenericAdaptorBase(RawBufferLoadOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferLoadOpGenericAdaptor : public detail::RawBufferLoadOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferLoadOpGenericAdaptorBase;
public:
  RawBufferLoadOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferLoadOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferLoadOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferLoadOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferLoadOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferLoadOpGenericAdaptor(RangeT values, const RawBufferLoadOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferLoadOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferLoadOp>>>
  RawBufferLoadOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getMemref() {
    return (*getODSOperands(0).begin());
  }

  RangeT getIndices() {
    return getODSOperands(1);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferLoadOpAdaptor : public RawBufferLoadOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferLoadOpGenericAdaptor::RawBufferLoadOpGenericAdaptor;
  RawBufferLoadOpAdaptor(RawBufferLoadOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferLoadOp : public ::mlir::Op<RawBufferLoadOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferLoadOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferLoadOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_load");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(0).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(1);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(2);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferLoadOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::RawBufferStoreOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class RawBufferStoreOpGenericAdaptorBase {
public:
  struct Properties {
    using boundsCheckTy = ::mlir::BoolAttr;
    boundsCheckTy boundsCheck;

    auto getBoundsCheck() {
      auto &propStorage = this->boundsCheck;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setBoundsCheck(const ::mlir::BoolAttr &propValue) {
      this->boundsCheck = propValue;
    }
    using indexOffsetTy = ::mlir::IntegerAttr;
    indexOffsetTy indexOffset;

    auto getIndexOffset() {
      auto &propStorage = this->indexOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setIndexOffset(const ::mlir::IntegerAttr &propValue) {
      this->indexOffset = propValue;
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
        rhs.boundsCheck == this->boundsCheck &&
        rhs.indexOffset == this->indexOffset &&
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
  RawBufferStoreOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.raw_buffer_store", odsAttrs.getContext());
  }

  RawBufferStoreOpGenericAdaptorBase(RawBufferStoreOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getBoundsCheckAttr();
  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
    return attr;
  }

  ::std::optional<uint32_t> getIndexOffset();
};
} // namespace detail
template <typename RangeT>
class RawBufferStoreOpGenericAdaptor : public detail::RawBufferStoreOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::RawBufferStoreOpGenericAdaptorBase;
public:
  RawBufferStoreOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  RawBufferStoreOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : RawBufferStoreOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  RawBufferStoreOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs) : RawBufferStoreOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  RawBufferStoreOpGenericAdaptor(RangeT values, const RawBufferStoreOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = RawBufferStoreOp, typename = std::enable_if_t<std::is_same_v<LateInst, RawBufferStoreOp>>>
  RawBufferStoreOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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

  ValueT getMemref() {
    return (*getODSOperands(1).begin());
  }

  RangeT getIndices() {
    return getODSOperands(2);
  }

  ValueT getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ValueT{} : (*operands.begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class RawBufferStoreOpAdaptor : public RawBufferStoreOpGenericAdaptor<::mlir::ValueRange> {
public:
  using RawBufferStoreOpGenericAdaptor::RawBufferStoreOpGenericAdaptor;
  RawBufferStoreOpAdaptor(RawBufferStoreOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class RawBufferStoreOp : public ::mlir::Op<RawBufferStoreOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RawBufferStoreOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = RawBufferStoreOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("boundsCheck"), ::llvm::StringRef("indexOffset"), ::llvm::StringRef("operandSegmentSizes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getBoundsCheckAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getBoundsCheckAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIndexOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIndexOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
   return (*this)->getName().getAttributeNames().back();
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
   return name.getAttributeNames().back();
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.raw_buffer_store");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getValue() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::MemRefType> getMemref() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::MemRefType>>(*getODSOperands(1).begin());
  }

  ::mlir::Operation::operand_range getIndices() {
    return getODSOperands(2);
  }

  ::mlir::TypedValue<::mlir::IntegerType> getSgprOffset() {
    auto operands = getODSOperands(3);
    return operands.empty() ? ::mlir::TypedValue<::mlir::IntegerType>{} : ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*operands.begin());
  }

  ::mlir::OpOperand &getValueMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getMemrefMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange getSgprOffsetMutable();
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
  ::mlir::BoolAttr getBoundsCheckAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().boundsCheck);
  }

  bool getBoundsCheck();
  ::mlir::IntegerAttr getIndexOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().indexOffset);
  }

  ::std::optional<uint32_t> getIndexOffset();
  void setBoundsCheckAttr(::mlir::BoolAttr attr) {
    getProperties().boundsCheck = attr;
  }

  void setBoundsCheck(bool attrValue);
  void setIndexOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().indexOffset = attr;
  }

  void setIndexOffset(::std::optional<uint32_t> attrValue);
  ::mlir::Attribute removeIndexOffsetAttr() {
      auto &attr = getProperties().indexOffset;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, ::mlir::BoolAttr boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value, ::mlir::Value memref, ::mlir::ValueRange indices, bool boundsCheck, /*optional*/::mlir::IntegerAttr indexOffset, /*optional*/::mlir::Value sgprOffset);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::RawBufferStoreOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::SchedBarrierOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class SchedBarrierOpGenericAdaptorBase {
public:
  struct Properties {
    using optsTy = ::mlir::amdgpu::sched_barrier_opt_enumAttr;
    optsTy opts;

    auto getOpts() {
      auto &propStorage = this->opts;
      return ::llvm::cast<::mlir::amdgpu::sched_barrier_opt_enumAttr>(propStorage);
    }
    void setOpts(const ::mlir::amdgpu::sched_barrier_opt_enumAttr &propValue) {
      this->opts = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.opts == this->opts &&
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
  SchedBarrierOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.sched_barrier", odsAttrs.getContext());
  }

  SchedBarrierOpGenericAdaptorBase(SchedBarrierOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::amdgpu::sched_barrier_opt_enumAttr getOptsAttr() {
    auto attr = ::llvm::cast<::mlir::amdgpu::sched_barrier_opt_enumAttr>(getProperties().opts);
    return attr;
  }

  ::mlir::amdgpu::sched_barrier_opt_enum getOpts();
};
} // namespace detail
template <typename RangeT>
class SchedBarrierOpGenericAdaptor : public detail::SchedBarrierOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::SchedBarrierOpGenericAdaptorBase;
public:
  SchedBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  SchedBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : SchedBarrierOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  SchedBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : SchedBarrierOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  SchedBarrierOpGenericAdaptor(RangeT values, const SchedBarrierOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = SchedBarrierOp, typename = std::enable_if_t<std::is_same_v<LateInst, SchedBarrierOp>>>
  SchedBarrierOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

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
class SchedBarrierOpAdaptor : public SchedBarrierOpGenericAdaptor<::mlir::ValueRange> {
public:
  using SchedBarrierOpGenericAdaptor::SchedBarrierOpGenericAdaptor;
  SchedBarrierOpAdaptor(SchedBarrierOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class SchedBarrierOp : public ::mlir::Op<SchedBarrierOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SchedBarrierOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = SchedBarrierOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("opts")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getOptsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOptsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.sched_barrier");
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
  ::mlir::amdgpu::sched_barrier_opt_enumAttr getOptsAttr() {
    return ::llvm::cast<::mlir::amdgpu::sched_barrier_opt_enumAttr>(getProperties().opts);
  }

  ::mlir::amdgpu::sched_barrier_opt_enum getOpts();
  void setOptsAttr(::mlir::amdgpu::sched_barrier_opt_enumAttr attr) {
    getProperties().opts = attr;
  }

  void setOpts(::mlir::amdgpu::sched_barrier_opt_enum attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::amdgpu::sched_barrier_opt_enumAttr opts);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::amdgpu::sched_barrier_opt_enumAttr opts);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::amdgpu::sched_barrier_opt_enum opts);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::amdgpu::sched_barrier_opt_enum opts);
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
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::SchedBarrierOp)

namespace mlir {
namespace amdgpu {

//===----------------------------------------------------------------------===//
// ::mlir::amdgpu::WMMAOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class WMMAOpGenericAdaptorBase {
public:
  struct Properties {
    using clampTy = ::mlir::UnitAttr;
    clampTy clamp;

    auto getClamp() {
      auto &propStorage = this->clamp;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setClamp(const ::mlir::UnitAttr &propValue) {
      this->clamp = propValue;
    }
    using subwordOffsetTy = ::mlir::IntegerAttr;
    subwordOffsetTy subwordOffset;

    auto getSubwordOffset() {
      auto &propStorage = this->subwordOffset;
      return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(propStorage);
    }
    void setSubwordOffset(const ::mlir::IntegerAttr &propValue) {
      this->subwordOffset = propValue;
    }
    using unsignedATy = ::mlir::UnitAttr;
    unsignedATy unsignedA;

    auto getUnsignedA() {
      auto &propStorage = this->unsignedA;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setUnsignedA(const ::mlir::UnitAttr &propValue) {
      this->unsignedA = propValue;
    }
    using unsignedBTy = ::mlir::UnitAttr;
    unsignedBTy unsignedB;

    auto getUnsignedB() {
      auto &propStorage = this->unsignedB;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setUnsignedB(const ::mlir::UnitAttr &propValue) {
      this->unsignedB = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.clamp == this->clamp &&
        rhs.subwordOffset == this->subwordOffset &&
        rhs.unsignedA == this->unsignedA &&
        rhs.unsignedB == this->unsignedB &&
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
  WMMAOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("amdgpu.wmma", odsAttrs.getContext());
  }

  WMMAOpGenericAdaptorBase(WMMAOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getSubwordOffsetAttr();
  uint32_t getSubwordOffset();
  ::mlir::UnitAttr getUnsignedAAttr();
  bool getUnsignedA();
  ::mlir::UnitAttr getUnsignedBAttr();
  bool getUnsignedB();
  ::mlir::UnitAttr getClampAttr();
  bool getClamp();
};
} // namespace detail
template <typename RangeT>
class WMMAOpGenericAdaptor : public detail::WMMAOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::WMMAOpGenericAdaptorBase;
public:
  WMMAOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  WMMAOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : WMMAOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  WMMAOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : WMMAOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  WMMAOpGenericAdaptor(RangeT values, const WMMAOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = WMMAOp, typename = std::enable_if_t<std::is_same_v<LateInst, WMMAOp>>>
  WMMAOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getSourceA() {
    return (*getODSOperands(0).begin());
  }

  ValueT getSourceB() {
    return (*getODSOperands(1).begin());
  }

  ValueT getDestC() {
    return (*getODSOperands(2).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class WMMAOpAdaptor : public WMMAOpGenericAdaptor<::mlir::ValueRange> {
public:
  using WMMAOpGenericAdaptor::WMMAOpGenericAdaptor;
  WMMAOpAdaptor(WMMAOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class WMMAOp : public ::mlir::Op<WMMAOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = WMMAOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = WMMAOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("clamp"), ::llvm::StringRef("subwordOffset"), ::llvm::StringRef("unsignedA"), ::llvm::StringRef("unsignedB")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getClampAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getClampAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getSubwordOffsetAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getSubwordOffsetAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getUnsignedAAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getUnsignedAAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getUnsignedBAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getUnsignedBAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("amdgpu.wmma");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::Type> getSourceA() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getSourceB() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(1).begin());
  }

  ::mlir::TypedValue<::mlir::Type> getDestC() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::Type>>(*getODSOperands(2).begin());
  }

  ::mlir::OpOperand &getSourceAMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getSourceBMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getDestCMutable() {
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

  ::mlir::TypedValue<::mlir::Type> getDestD() {
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
  ::mlir::IntegerAttr getSubwordOffsetAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::IntegerAttr>(getProperties().subwordOffset);
  }

  uint32_t getSubwordOffset();
  ::mlir::UnitAttr getUnsignedAAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().unsignedA);
  }

  bool getUnsignedA();
  ::mlir::UnitAttr getUnsignedBAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().unsignedB);
  }

  bool getUnsignedB();
  ::mlir::UnitAttr getClampAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().clamp);
  }

  bool getClamp();
  void setSubwordOffsetAttr(::mlir::IntegerAttr attr) {
    getProperties().subwordOffset = attr;
  }

  void setSubwordOffset(uint32_t attrValue);
  void setUnsignedAAttr(::mlir::UnitAttr attr) {
    getProperties().unsignedA = attr;
  }

  void setUnsignedA(bool attrValue);
  void setUnsignedBAttr(::mlir::UnitAttr attr) {
    getProperties().unsignedB = attr;
  }

  void setUnsignedB(bool attrValue);
  void setClampAttr(::mlir::UnitAttr attr) {
    getProperties().clamp = attr;
  }

  void setClamp(bool attrValue);
  ::mlir::Attribute removeUnsignedAAttr() {
      auto &attr = getProperties().unsignedA;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeUnsignedBAttr() {
      auto &attr = getProperties().unsignedB;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeClampAttr() {
      auto &attr = getProperties().clamp;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type destD, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, ::mlir::IntegerAttr subwordOffset, /*optional*/::mlir::UnitAttr unsignedA = nullptr, /*optional*/::mlir::UnitAttr unsignedB = nullptr, /*optional*/::mlir::UnitAttr clamp = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, ::mlir::IntegerAttr subwordOffset, /*optional*/::mlir::UnitAttr unsignedA = nullptr, /*optional*/::mlir::UnitAttr unsignedB = nullptr, /*optional*/::mlir::UnitAttr clamp = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type destD, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, uint32_t subwordOffset = 0, /*optional*/bool unsignedA = false, /*optional*/bool unsignedB = false, /*optional*/bool clamp = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value sourceA, ::mlir::Value sourceB, ::mlir::Value destC, uint32_t subwordOffset = 0, /*optional*/bool unsignedA = false, /*optional*/bool unsignedB = false, /*optional*/bool clamp = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
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
    assert(index < 4 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::WMMAOp)


#endif  // GET_OP_CLASSES

