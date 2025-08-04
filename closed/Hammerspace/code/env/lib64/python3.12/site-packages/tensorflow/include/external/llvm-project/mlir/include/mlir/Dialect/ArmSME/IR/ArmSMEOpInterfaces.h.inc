/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

class ArmSMETileOpInterface;
namespace detail {
struct ArmSMETileOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    void (*setTileId)(const Concept *impl, ::mlir::Operation *, mlir::IntegerAttr);
    mlir::IntegerAttr (*getTileId)(const Concept *impl, ::mlir::Operation *);
    VectorType (*getTileType)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ArmSMETileOpInterface;
    Model() : Concept{setTileId, getTileId, getTileType} {}

    static inline void setTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::IntegerAttr tileId);
    static inline mlir::IntegerAttr getTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline VectorType getTileType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ArmSMETileOpInterface;
    FallbackModel() : Concept{setTileId, getTileId, getTileType} {}

    static inline void setTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::IntegerAttr tileId);
    static inline mlir::IntegerAttr getTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline VectorType getTileType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
    void setTileId(::mlir::Operation *tablegen_opaque_val, mlir::IntegerAttr tileId) const;
    mlir::IntegerAttr getTileId(::mlir::Operation *tablegen_opaque_val) const;
  };
};
template <typename ConcreteOp>
struct ArmSMETileOpInterfaceTrait;

} // namespace detail
class ArmSMETileOpInterface : public ::mlir::OpInterface<ArmSMETileOpInterface, detail::ArmSMETileOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<ArmSMETileOpInterface, detail::ArmSMETileOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::ArmSMETileOpInterfaceTrait<ConcreteOp> {};
  /// Sets the tile ID for this operation.
  void setTileId(mlir::IntegerAttr tileId);
  /// Returns the tile ID assigned to this operation. This will be null before
  /// tile allocation.
  mlir::IntegerAttr getTileId();
  /// Returns the VectorType of the tile used by this operation.
  VectorType getTileType();

    bool isInMemoryTile() {
      auto tileId = getTileId();
      return tileId && tileId.getInt() >= kInMemoryTileIdBase;
    }
};
namespace detail {
  template <typename ConcreteOp>
  struct ArmSMETileOpInterfaceTrait : public ::mlir::OpInterface<ArmSMETileOpInterface, detail::ArmSMETileOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    /// Sets the tile ID for this operation.
    void setTileId(mlir::IntegerAttr tileId) {
      if (!tileId)
          return;
        ::mlir::Operation* op = this->getOperation();
        op->setAttr("tile_id", tileId);
    }
    /// Returns the tile ID assigned to this operation. This will be null before
    /// tile allocation.
    mlir::IntegerAttr getTileId() {
      ::mlir::Operation* op = this->getOperation();
        return op->getAttrOfType<mlir::IntegerAttr>("tile_id");
    }
    static ::llvm::LogicalResult verifyTrait(::mlir::Operation *op) {
      return detail::verifyArmSMETileOpInterface(op);
    }

    bool isInMemoryTile() {
      auto tileId = getTileId();
      return tileId && tileId.getInt() >= kInMemoryTileIdBase;
    }
  
  };
}// namespace detail
template<typename ConcreteOp>
void detail::ArmSMETileOpInterfaceInterfaceTraits::Model<ConcreteOp>::setTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::IntegerAttr tileId) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).setTileId(tileId);
}
template<typename ConcreteOp>
mlir::IntegerAttr detail::ArmSMETileOpInterfaceInterfaceTraits::Model<ConcreteOp>::getTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getTileId();
}
template<typename ConcreteOp>
VectorType detail::ArmSMETileOpInterfaceInterfaceTraits::Model<ConcreteOp>::getTileType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getTileType();
}
template<typename ConcreteOp>
void detail::ArmSMETileOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::setTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::IntegerAttr tileId) {
  return static_cast<const ConcreteOp *>(impl)->setTileId(tablegen_opaque_val, tileId);
}
template<typename ConcreteOp>
mlir::IntegerAttr detail::ArmSMETileOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getTileId(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getTileId(tablegen_opaque_val);
}
template<typename ConcreteOp>
VectorType detail::ArmSMETileOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getTileType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getTileType(tablegen_opaque_val);
}
template<typename ConcreteModel, typename ConcreteOp>
void detail::ArmSMETileOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::setTileId(::mlir::Operation *tablegen_opaque_val, mlir::IntegerAttr tileId) const {
if (!tileId)
          return;
        ::mlir::Operation* op = this->getOperation();
        op->setAttr("tile_id", tileId);
}
template<typename ConcreteModel, typename ConcreteOp>
mlir::IntegerAttr detail::ArmSMETileOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getTileId(::mlir::Operation *tablegen_opaque_val) const {
::mlir::Operation* op = this->getOperation();
        return op->getAttrOfType<mlir::IntegerAttr>("tile_id");
}
