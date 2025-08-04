/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ProtonDialect.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::proton::ProtonDialect)
namespace mlir {
namespace triton {
namespace proton {

ProtonDialect::ProtonDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<ProtonDialect>())
    
     {
  
  initialize();
}

ProtonDialect::~ProtonDialect() = default;

} // namespace proton
} // namespace triton
} // namespace mlir
