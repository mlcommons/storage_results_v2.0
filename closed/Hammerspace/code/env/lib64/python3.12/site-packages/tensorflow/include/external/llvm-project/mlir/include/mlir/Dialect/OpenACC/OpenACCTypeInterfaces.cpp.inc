/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/// Returns the pointer to the `var` if recoverable (such as in cases
/// where the current operation is a load from a memory slot).
::mlir::TypedValue<::mlir::acc::PointerLikeType> mlir::acc::MappableType::getVarPtr(::mlir::Value var) const {
      return getImpl()->getVarPtr(getImpl(), *this, var);
  }
/// Returns the size in bytes when computable. If this is an array-like
/// type, avoiding passing `accBounds` ensures a computation of the size
/// of whole type.
::std::optional<::llvm::TypeSize> mlir::acc::MappableType::getSizeInBytes(::mlir::Value var, ::mlir::ValueRange accBounds, const ::mlir::DataLayout & dataLayout) const {
      return getImpl()->getSizeInBytes(getImpl(), *this, var, accBounds, dataLayout);
  }
/// Returns the offset in bytes when computable.
::std::optional<::int64_t> mlir::acc::MappableType::getOffsetInBytes(::mlir::Value var, ::mlir::ValueRange accBounds, const ::mlir::DataLayout & dataLayout) const {
      return getImpl()->getOffsetInBytes(getImpl(), *this, var, accBounds, dataLayout);
  }
/// Returns explicit `acc.bounds` operations that envelop the whole
/// data structure. These operations are inserted using the provided builder
/// at the location set before calling this API.
::llvm::SmallVector<::mlir::Value> mlir::acc::MappableType::generateAccBounds(::mlir::Value var, ::mlir::OpBuilder & builder) const {
      return getImpl()->generateAccBounds(getImpl(), *this, var, builder);
  }
/// Returns the pointee type or null if the pointer has no pointee type
::mlir::Type mlir::acc::PointerLikeType::getElementType() const {
      return getImpl()->getElementType(getImpl(), *this);
  }
