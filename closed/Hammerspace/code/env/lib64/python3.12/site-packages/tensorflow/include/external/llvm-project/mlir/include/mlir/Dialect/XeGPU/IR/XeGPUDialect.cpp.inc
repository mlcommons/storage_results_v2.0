/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: XeGPU.td                                                             *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::xegpu::XeGPUDialect)
namespace mlir {
namespace xegpu {

XeGPUDialect::XeGPUDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<XeGPUDialect>())
    
     {
  getContext()->loadDialect<arith::ArithDialect>();
  initialize();
}

XeGPUDialect::~XeGPUDialect() = default;

} // namespace xegpu
} // namespace mlir
