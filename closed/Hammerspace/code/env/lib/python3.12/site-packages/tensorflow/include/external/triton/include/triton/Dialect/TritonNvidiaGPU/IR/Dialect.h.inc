/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: TritonNvidiaGPUDialect.td                                            *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
namespace nvidia_gpu {

class TritonNvidiaGPUDialect : public ::mlir::Dialect {
  explicit TritonNvidiaGPUDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~TritonNvidiaGPUDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("ttng");
  }

    /// Provides a hook for verifying dialect attributes attached to the given
    /// op.
    ::llvm::LogicalResult verifyOperationAttribute(
        ::mlir::Operation *op, ::mlir::NamedAttribute attribute) override;

    static std::string getNumWarpsAttrName() { return "ttg.num-warps"; }
    static int getNumWarps(ModuleOp mod) {
      if(!mod->hasAttr("ttg.num-warps"))
        llvm::report_fatal_error(
            "TritonGPU module should contain a ttg.num-warps attribute");
      return cast<IntegerAttr>(mod->getAttr("ttg.num-warps")).getInt();
    }
    static int getNumCTAs(ModuleOp mod) {
      if(!mod->hasAttr("ttg.num-ctas"))
        llvm::report_fatal_error(
            "TritonGPU module should contain a ttg.num-ctas attribute");
      return cast<IntegerAttr>(mod->getAttr("ttg.num-ctas")).getInt();
    }
  };
} // namespace nvidia_gpu
} // namespace triton
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::triton::nvidia_gpu::TritonNvidiaGPUDialect)
