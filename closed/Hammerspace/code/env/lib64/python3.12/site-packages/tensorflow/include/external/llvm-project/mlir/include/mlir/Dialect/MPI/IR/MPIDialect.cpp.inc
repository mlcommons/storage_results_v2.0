/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MPI.td                                                               *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mpi::MPIDialect)
namespace mlir {
namespace mpi {

MPIDialect::MPIDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<MPIDialect>())
    
     {
  
  initialize();
}

MPIDialect::~MPIDialect() = default;

} // namespace mpi
} // namespace mlir
