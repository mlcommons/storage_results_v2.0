/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: xla_cpu_dialect.td                                                   *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace xla {
namespace cpu {

class XlaCpuDialect : public ::mlir::Dialect {
  explicit XlaCpuDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~XlaCpuDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("xla_cpu");
  }

  /// Parse a type registered to this dialect.
  ::mlir::Type parseType(::mlir::DialectAsmParser &parser) const override;

  /// Print a type registered to this dialect.
  void printType(::mlir::Type type,
                 ::mlir::DialectAsmPrinter &os) const override;
};
} // namespace cpu
} // namespace xla
MLIR_DECLARE_EXPLICIT_TYPE_ID(::xla::cpu::XlaCpuDialect)
