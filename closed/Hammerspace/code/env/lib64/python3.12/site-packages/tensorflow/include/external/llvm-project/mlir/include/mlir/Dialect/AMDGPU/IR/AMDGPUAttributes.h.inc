/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace amdgpu {
class DPPPermAttr;
class sched_barrier_opt_enumAttr;
class MFMAPermBAttr;
namespace detail {
struct DPPPermAttrStorage;
} // namespace detail
class DPPPermAttr : public ::mlir::Attribute::AttrBase<DPPPermAttr, ::mlir::Attribute, detail::DPPPermAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "amdgpu.dpp_perm";
  static constexpr ::llvm::StringLiteral dialectName = "amdgpu";
  static DPPPermAttr get(::mlir::MLIRContext *context, ::mlir::amdgpu::DPPPerm value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"dpp_perm"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::amdgpu::DPPPerm getValue() const;
};
namespace detail {
struct sched_barrier_opt_enumAttrStorage;
} // namespace detail
class sched_barrier_opt_enumAttr : public ::mlir::Attribute::AttrBase<sched_barrier_opt_enumAttr, ::mlir::Attribute, detail::sched_barrier_opt_enumAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "amdgpu.sched_barrier_opt";
  static constexpr ::llvm::StringLiteral dialectName = "amdgpu";
  static sched_barrier_opt_enumAttr get(::mlir::MLIRContext *context, ::mlir::amdgpu::sched_barrier_opt_enum value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"sched_barrier_opt"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::amdgpu::sched_barrier_opt_enum getValue() const;
};
namespace detail {
struct MFMAPermBAttrStorage;
} // namespace detail
class MFMAPermBAttr : public ::mlir::Attribute::AttrBase<MFMAPermBAttr, ::mlir::Attribute, detail::MFMAPermBAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "amdgpu.mfma_perm_b";
  static constexpr ::llvm::StringLiteral dialectName = "amdgpu";
  static MFMAPermBAttr get(::mlir::MLIRContext *context, ::mlir::amdgpu::MFMAPermB value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"mfma_perm_b"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::amdgpu::MFMAPermB getValue() const;
};
} // namespace amdgpu
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::DPPPermAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::sched_barrier_opt_enumAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amdgpu::MFMAPermBAttr)

#endif  // GET_ATTRDEF_CLASSES

