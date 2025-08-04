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
namespace xla {
namespace gpu {
class MemorySpaceAttr;
class LayoutAttr;
namespace detail {
struct MemorySpaceAttrStorage;
} // namespace detail
class MemorySpaceAttr : public ::mlir::Attribute::AttrBase<MemorySpaceAttr, ::mlir::Attribute, detail::MemorySpaceAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xla_gpu.memory_space";
  static constexpr ::llvm::StringLiteral dialectName = "xla_gpu";
  static MemorySpaceAttr get(::mlir::MLIRContext *context, ::xla::gpu::MemorySpace value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"memory_space"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::xla::gpu::MemorySpace getValue() const;
};
namespace detail {
struct LayoutAttrStorage;
} // namespace detail
class LayoutAttr : public ::mlir::Attribute::AttrBase<LayoutAttr, ::mlir::Attribute, detail::LayoutAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "xla_gpu.layout";
  static constexpr ::llvm::StringLiteral dialectName = "xla_gpu";
  static LayoutAttr get(::mlir::MLIRContext *context, MemorySpaceAttr memory_space, IndexingMapAttr thread_map);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"layout"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  MemorySpaceAttr getMemorySpace() const;
  IndexingMapAttr getThreadMap() const;
};
} // namespace gpu
} // namespace xla
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::gpu::MemorySpaceAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::gpu::LayoutAttr)

#endif  // GET_ATTRDEF_CLASSES

