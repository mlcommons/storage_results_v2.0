/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ROCDLOps.td                                                          *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::ROCDL::ROCDLDialect)
namespace mlir {
namespace ROCDL {

ROCDLDialect::ROCDLDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<ROCDLDialect>())
    , kernelAttrName(context), reqdWorkGroupSizeAttrName(context), flatWorkGroupSizeAttrName(context), maxFlatWorkGroupSizeAttrName(context), wavesPerEuAttrName(context), unsafeFpAtomicsAttrName(context), lastUseAttrName(context), noRemoteMemoryAttrName(context), noFineGrainedMemoryAttrName(context), ignoreDenormalModeAttrName(context)
     {
  getContext()->loadDialect<LLVM::LLVMDialect>();
  initialize();
}

ROCDLDialect::~ROCDLDialect() = default;

} // namespace ROCDL
} // namespace mlir
