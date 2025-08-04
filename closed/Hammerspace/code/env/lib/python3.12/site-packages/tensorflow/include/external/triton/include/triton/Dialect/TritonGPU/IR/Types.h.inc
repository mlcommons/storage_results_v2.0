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
namespace triton {
namespace gpu {
class AsyncTokenType;
class MemDescType;
class AsyncTokenType : public ::mlir::Type::TypeBase<AsyncTokenType, ::mlir::Type, ::mlir::TypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "ttg.async.token";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"async.token"};
  }

};
namespace detail {
struct MemDescTypeStorage;
} // namespace detail
class MemDescType : public ::mlir::Type::TypeBase<MemDescType, ::mlir::Type, detail::MemDescTypeStorage, ::mlir::ShapedType::Trait> {
public:
  using Base::Base;
  MemDescType cloneWith(std::optional<ArrayRef<int64_t>> shape,
                        Type elementType) const {
    return MemDescType::get(shape.value_or(getShape()), elementType, getEncoding(), getMemorySpace(), getMutableMemory(), getAllocShape());
  }

  bool hasRank() const { return true; }
  static constexpr ::llvm::StringLiteral name = "ttg.memdesc";
  static constexpr ::llvm::StringLiteral dialectName = "ttg";
  using Base::getChecked;
  static MemDescType get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape);
  static MemDescType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape);
  static MemDescType get(llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace);
  static MemDescType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace);
  static MemDescType get(llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory);
  static MemDescType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory);
  static MemDescType get(llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, llvm::ArrayRef<int64_t> allocShape);
  static MemDescType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, llvm::ArrayRef<int64_t> allocShape);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, Type elementType, Attribute encoding, Attribute memorySpace, bool mutableMemory, ::llvm::ArrayRef<int64_t> allocShape);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"memdesc"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getShape() const;
  Type getElementType() const;
  Attribute getEncoding() const;
  Attribute getMemorySpace() const;
  bool getMutableMemory() const;
  ::llvm::ArrayRef<int64_t> getAllocShape() const;
};
} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::AsyncTokenType)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::MemDescType)

#endif  // GET_TYPEDEF_CLASSES

