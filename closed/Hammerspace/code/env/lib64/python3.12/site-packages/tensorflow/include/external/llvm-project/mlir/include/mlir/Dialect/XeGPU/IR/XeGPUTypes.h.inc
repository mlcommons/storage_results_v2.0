/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace xegpu {
class TensorDescType;
class NbarrierType;
namespace detail {
struct TensorDescTypeStorage;
} // namespace detail
class TensorDescType : public ::mlir::Type::TypeBase<TensorDescType, ::mlir::TensorType, detail::TensorDescTypeStorage, ::mlir::ShapedType::Trait> {
public:
  using Base::Base;
  using TensorType::clone;
  using mlir::ShapedType::Trait<TensorDescType>::getElementTypeBitWidth;
  using mlir::ShapedType::Trait<TensorDescType>::getRank;
  using mlir::ShapedType::Trait<TensorDescType>::getNumElements;
  using mlir::ShapedType::Trait<TensorDescType>::isDynamicDim;
  using mlir::ShapedType::Trait<TensorDescType>::hasStaticShape;
  using mlir::ShapedType::Trait<TensorDescType>::getNumDynamicDims;
  using mlir::ShapedType::Trait<TensorDescType>::getDimSize;
  using mlir::ShapedType::Trait<TensorDescType>::getDynamicDimIndex;

  TensorDescType clone(::mlir::Type elementType) {
    return llvm::cast<TensorDescType>(cloneWith(getShape(), elementType));
  }

  BlockTensorDescAttr getEncodingAsBlockTensorDescAttr() const {
    return llvm::dyn_cast_if_present<BlockTensorDescAttr>(getEncoding());
  }

  ScatterTensorDescAttr getEncodingAsScatterTensorDescAttr() const {
    return llvm::dyn_cast_if_present<ScatterTensorDescAttr>(getEncoding());
  }

  SGMapAttr getSGMapAttr() const {
    return llvm::dyn_cast_if_present<SGMapAttr>(getSgMap());
  }

  xegpu::MemorySpace getMemorySpace() const {
    auto block_attr = getEncodingAsBlockTensorDescAttr();
    if (block_attr && block_attr.getMemorySpace())
      return block_attr.getMemorySpace().getValue();

    auto scatter_attr = getEncodingAsScatterTensorDescAttr();
    if (scatter_attr && scatter_attr.getMemorySpace())
      return scatter_attr.getMemorySpace().getValue();

    // return default value
    return MemorySpace::Global;
  }

  int getArrayLength() {
    auto attr = getEncoding();
    auto block_attr = mlir::dyn_cast_if_present<BlockTensorDescAttr>(attr);
    assert((!attr || block_attr) && "invalid on non BlockTensorDescAttr.");
    if (block_attr && block_attr.getArrayLength())
      return block_attr.getArrayLength().getInt();
    // return default value
    return 1;
  }

  bool getBoundaryCheck() {
    auto attr = getEncoding();
    auto block_attr = mlir::dyn_cast_if_present<BlockTensorDescAttr>(attr);
    assert((!attr || block_attr) && "invalid on non BlockTensorDescAttr.");
    if (block_attr && block_attr.getBoundaryCheck())
      return block_attr.getBoundaryCheck().getValue();
    // return default value
    return true;
  }

  bool isScattered() {
    return bool(getEncodingAsScatterTensorDescAttr());
  }

  int getChunkSize() {
    auto attr = getEncoding();
    auto scatter_attr = mlir::dyn_cast_if_present<ScatterTensorDescAttr>(attr);
    assert((!attr || scatter_attr) && "invalid on non ScatterTensorDescAttr.");
    if (scatter_attr && scatter_attr.getChunkSize())
      return scatter_attr.getChunkSize().getInt();
    return 1;
  }
  static constexpr ::llvm::StringLiteral name = "xegpu.tensor_desc";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static TensorDescType get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, mlir::Type elementType, mlir::Attribute encoding, mlir::Attribute sg_map);
  static TensorDescType get(llvm::ArrayRef<int64_t> shape, mlir::Type elementType, int array_length = 1, bool boundary_check = true, xegpu::MemorySpace memory_space = xegpu::MemorySpace::Global, mlir::Attribute sg_map = mlir::Attribute());
  static TensorDescType get(llvm::ArrayRef<int64_t> shape, mlir::Type elementType, int chunk_size = 1, xegpu::MemorySpace memory_space = xegpu::MemorySpace::Global, mlir::Attribute sg_map = mlir::Attribute());
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"tensor_desc"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getShape() const;
  mlir::Type getElementType() const;
  mlir::Attribute getEncoding() const;
  mlir::Attribute getSgMap() const;
};
class NbarrierType : public ::mlir::Type::TypeBase<NbarrierType, mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static NbarrierType get(mlir::MLIRContext *context) {
    return Base::get(context);
  };
  static constexpr ::llvm::StringLiteral name = "xegpu.nbarrier";
  static constexpr ::llvm::StringLiteral dialectName = "xegpu";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"nbarrier"};
  }

};
} // namespace xegpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::TensorDescType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::xegpu::NbarrierType)

#endif  // GET_TYPEDEF_CLASSES

