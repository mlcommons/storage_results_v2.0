/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
class TransposeOpInterface;
namespace detail {
struct TransposeOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::mlir::Value (*getSrc)(const Concept *impl, ::mlir::Operation *);
    ::mlir::ArrayRef<int32_t> (*getOrder)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::triton::TransposeOpInterface;
    Model() : Concept{getSrc, getOrder} {}

    static inline ::mlir::Value getSrc(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::ArrayRef<int32_t> getOrder(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::triton::TransposeOpInterface;
    FallbackModel() : Concept{getSrc, getOrder} {}

    static inline ::mlir::Value getSrc(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::ArrayRef<int32_t> getOrder(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};
template <typename ConcreteOp>
struct TransposeOpInterfaceTrait;

} // namespace detail
class TransposeOpInterface : public ::mlir::OpInterface<TransposeOpInterface, detail::TransposeOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<TransposeOpInterface, detail::TransposeOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::TransposeOpInterfaceTrait<ConcreteOp> {};
  /// Get the source operand of the transposition.
  ::mlir::Value getSrc();
  /// Get the order of the transposition.
  ::mlir::ArrayRef<int32_t> getOrder();
};
namespace detail {
  template <typename ConcreteOp>
  struct TransposeOpInterfaceTrait : public ::mlir::OpInterface<TransposeOpInterface, detail::TransposeOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    static ::llvm::LogicalResult verifyTrait(::mlir::Operation *op) {
      return ::mlir::triton::impl::verifyTransposeOpInterface(op);
    }
  };
}// namespace detail
} // namespace triton
} // namespace mlir
namespace mlir {
namespace triton {
template<typename ConcreteOp>
::mlir::Value detail::TransposeOpInterfaceInterfaceTraits::Model<ConcreteOp>::getSrc(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getSrc();
}
template<typename ConcreteOp>
::mlir::ArrayRef<int32_t> detail::TransposeOpInterfaceInterfaceTraits::Model<ConcreteOp>::getOrder(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOrder();
}
template<typename ConcreteOp>
::mlir::Value detail::TransposeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getSrc(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getSrc(tablegen_opaque_val);
}
template<typename ConcreteOp>
::mlir::ArrayRef<int32_t> detail::TransposeOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getOrder(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getOrder(tablegen_opaque_val);
}
} // namespace triton
} // namespace mlir
