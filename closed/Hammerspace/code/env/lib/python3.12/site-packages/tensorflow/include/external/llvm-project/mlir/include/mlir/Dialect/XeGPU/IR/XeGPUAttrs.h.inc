/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace xegpu {
class BlockTensorDescAttr;
class ScatterTensorDescAttr;
class MemorySpaceAttr;
class CachePolicyAttr;
class FenceScopeAttr;
class SGMapAttr;
namespace detail {
struct BlockTensorDescAttrStorage;
} // namespace detail
class BlockTensorDescAttr : public ::mlir::Attribute::AttrBase<BlockTensorDescAttr, ::mlir::Attribute, detail::BlockTensorDescAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xegpu.block_tdesc_attr";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static BlockTensorDescAttr get(::mlir::MLIRContext *context, MemorySpaceAttr memory_space, IntegerAttr array_length, BoolAttr boundary_check);
  static BlockTensorDescAttr get(::mlir::MLIRContext *context, xegpu::MemorySpace memory_space = xegpu::MemorySpace::Global, int array_length = 1, bool boundary_check = true);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"block_tdesc_attr"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  MemorySpaceAttr getMemorySpace() const;
  IntegerAttr getArrayLength() const;
  BoolAttr getBoundaryCheck() const;
};
namespace detail {
struct ScatterTensorDescAttrStorage;
} // namespace detail
class ScatterTensorDescAttr : public ::mlir::Attribute::AttrBase<ScatterTensorDescAttr, ::mlir::Attribute, detail::ScatterTensorDescAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xegpu.scatter_tdesc_attr";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static ScatterTensorDescAttr get(::mlir::MLIRContext *context, MemorySpaceAttr memory_space, IntegerAttr chunk_size);
  static ScatterTensorDescAttr get(::mlir::MLIRContext *context, xegpu::MemorySpace memory_space = xegpu::MemorySpace::Global, int chunk_size = 1);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"scatter_tdesc_attr"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  MemorySpaceAttr getMemorySpace() const;
  IntegerAttr getChunkSize() const;
};
namespace detail {
struct MemorySpaceAttrStorage;
} // namespace detail
class MemorySpaceAttr : public ::mlir::Attribute::AttrBase<MemorySpaceAttr, ::mlir::Attribute, detail::MemorySpaceAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xegpu.memory_space";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static MemorySpaceAttr get(::mlir::MLIRContext *context, ::mlir::xegpu::MemorySpace value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"memory_space"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::xegpu::MemorySpace getValue() const;
};
namespace detail {
struct CachePolicyAttrStorage;
} // namespace detail
class CachePolicyAttr : public ::mlir::Attribute::AttrBase<CachePolicyAttr, ::mlir::Attribute, detail::CachePolicyAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xegpu.cache_hint";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static CachePolicyAttr get(::mlir::MLIRContext *context, ::mlir::xegpu::CachePolicy value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"cache_hint"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::xegpu::CachePolicy getValue() const;
};
namespace detail {
struct FenceScopeAttrStorage;
} // namespace detail
class FenceScopeAttr : public ::mlir::Attribute::AttrBase<FenceScopeAttr, ::mlir::Attribute, detail::FenceScopeAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xegpu.fence_scope";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static FenceScopeAttr get(::mlir::MLIRContext *context, ::mlir::xegpu::FenceScope value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"fence_scope"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::xegpu::FenceScope getValue() const;
};
namespace detail {
struct SGMapAttrStorage;
} // namespace detail
class SGMapAttr : public ::mlir::Attribute::AttrBase<SGMapAttr, ::mlir::Attribute, detail::SGMapAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xegpu.sg_map";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  using Base::getChecked;
  static SGMapAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data);
  static SGMapAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<uint32_t> wi_layout, ::llvm::ArrayRef<uint32_t> wi_data);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"sg_map"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<uint32_t> getWiLayout() const;
  ::llvm::ArrayRef<uint32_t> getWiData() const;
};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::BlockTensorDescAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::ScatterTensorDescAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::MemorySpaceAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::CachePolicyAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::FenceScopeAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::SGMapAttr)

#endif  // GET_ATTRDEF_CLASSES

