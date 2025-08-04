/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Definitions                                                   *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: NVGPUOps.td                                                          *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
namespace nvgpu {
::llvm::StringRef stringifyMemSemantic(MemSemantic val) {
  switch (val) {
    case MemSemantic::RELAXED: return "relaxed";
    case MemSemantic::ACQUIRE: return "acquire";
    case MemSemantic::RELEASE: return "release";
    case MemSemantic::ACQUIRE_RELEASE: return "acq_rel";
  }
  return "";
}

::std::optional<MemSemantic> symbolizeMemSemantic(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<MemSemantic>>(str)
      .Case("relaxed", MemSemantic::RELAXED)
      .Case("acquire", MemSemantic::ACQUIRE)
      .Case("release", MemSemantic::RELEASE)
      .Case("acq_rel", MemSemantic::ACQUIRE_RELEASE)
      .Default(::std::nullopt);
}
::std::optional<MemSemantic> symbolizeMemSemantic(uint32_t value) {
  switch (value) {
  case 1: return MemSemantic::RELAXED;
  case 2: return MemSemantic::ACQUIRE;
  case 3: return MemSemantic::RELEASE;
  case 4: return MemSemantic::ACQUIRE_RELEASE;
  default: return ::std::nullopt;
  }
}

bool MemSemanticAttr::classof(::mlir::Attribute attr) {
  return (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && (((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 1)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 2)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 3)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 4)));
}
MemSemanticAttr MemSemanticAttr::get(::mlir::MLIRContext *context, MemSemantic val) {
  ::mlir::IntegerType intType = ::mlir::IntegerType::get(context, 32);
  ::mlir::IntegerAttr baseAttr = ::mlir::IntegerAttr::get(intType, static_cast<uint32_t>(val));
  return ::llvm::cast<MemSemanticAttr>(baseAttr);
}
MemSemantic MemSemanticAttr::getValue() const {
  return static_cast<MemSemantic>(::mlir::IntegerAttr::getInt());
}
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
namespace triton {
namespace nvgpu {
::llvm::StringRef stringifyMemSyncScope(MemSyncScope val) {
  switch (val) {
    case MemSyncScope::GPU: return "gpu";
    case MemSyncScope::CTA: return "cta";
    case MemSyncScope::SYSTEM: return "sys";
  }
  return "";
}

::std::optional<MemSyncScope> symbolizeMemSyncScope(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<MemSyncScope>>(str)
      .Case("gpu", MemSyncScope::GPU)
      .Case("cta", MemSyncScope::CTA)
      .Case("sys", MemSyncScope::SYSTEM)
      .Default(::std::nullopt);
}
::std::optional<MemSyncScope> symbolizeMemSyncScope(uint32_t value) {
  switch (value) {
  case 1: return MemSyncScope::GPU;
  case 2: return MemSyncScope::CTA;
  case 3: return MemSyncScope::SYSTEM;
  default: return ::std::nullopt;
  }
}

bool MemSyncScopeAttr::classof(::mlir::Attribute attr) {
  return (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && (((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 1)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 2)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 3)));
}
MemSyncScopeAttr MemSyncScopeAttr::get(::mlir::MLIRContext *context, MemSyncScope val) {
  ::mlir::IntegerType intType = ::mlir::IntegerType::get(context, 32);
  ::mlir::IntegerAttr baseAttr = ::mlir::IntegerAttr::get(intType, static_cast<uint32_t>(val));
  return ::llvm::cast<MemSyncScopeAttr>(baseAttr);
}
MemSyncScope MemSyncScopeAttr::getValue() const {
  return static_cast<MemSyncScope>(::mlir::IntegerAttr::getInt());
}
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
namespace triton {
namespace nvgpu {
::llvm::StringRef stringifyWGMMAEltType(WGMMAEltType val) {
  switch (val) {
    case WGMMAEltType::s8: return "s8";
    case WGMMAEltType::s32: return "s32";
    case WGMMAEltType::e4m3: return "e4m3";
    case WGMMAEltType::e5m2: return "e5m2";
    case WGMMAEltType::f16: return "f16";
    case WGMMAEltType::bf16: return "bf16";
    case WGMMAEltType::tf32: return "tf32";
    case WGMMAEltType::f32: return "f32";
  }
  return "";
}

::std::optional<WGMMAEltType> symbolizeWGMMAEltType(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<WGMMAEltType>>(str)
      .Case("s8", WGMMAEltType::s8)
      .Case("s32", WGMMAEltType::s32)
      .Case("e4m3", WGMMAEltType::e4m3)
      .Case("e5m2", WGMMAEltType::e5m2)
      .Case("f16", WGMMAEltType::f16)
      .Case("bf16", WGMMAEltType::bf16)
      .Case("tf32", WGMMAEltType::tf32)
      .Case("f32", WGMMAEltType::f32)
      .Default(::std::nullopt);
}
::std::optional<WGMMAEltType> symbolizeWGMMAEltType(uint32_t value) {
  switch (value) {
  case 0: return WGMMAEltType::s8;
  case 1: return WGMMAEltType::s32;
  case 2: return WGMMAEltType::e4m3;
  case 3: return WGMMAEltType::e5m2;
  case 4: return WGMMAEltType::f16;
  case 5: return WGMMAEltType::bf16;
  case 6: return WGMMAEltType::tf32;
  case 7: return WGMMAEltType::f32;
  default: return ::std::nullopt;
  }
}

bool WGMMAEltTypeAttr::classof(::mlir::Attribute attr) {
  return (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && (((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 0)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 1)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 2)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 3)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 4)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 5)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 6)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 7)));
}
WGMMAEltTypeAttr WGMMAEltTypeAttr::get(::mlir::MLIRContext *context, WGMMAEltType val) {
  ::mlir::IntegerType intType = ::mlir::IntegerType::get(context, 32);
  ::mlir::IntegerAttr baseAttr = ::mlir::IntegerAttr::get(intType, static_cast<uint32_t>(val));
  return ::llvm::cast<WGMMAEltTypeAttr>(baseAttr);
}
WGMMAEltType WGMMAEltTypeAttr::getValue() const {
  return static_cast<WGMMAEltType>(::mlir::IntegerAttr::getInt());
}
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
namespace triton {
namespace nvgpu {
::llvm::StringRef stringifyWGMMALayout(WGMMALayout val) {
  switch (val) {
    case WGMMALayout::row: return "row";
    case WGMMALayout::col: return "col";
  }
  return "";
}

::std::optional<WGMMALayout> symbolizeWGMMALayout(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<WGMMALayout>>(str)
      .Case("row", WGMMALayout::row)
      .Case("col", WGMMALayout::col)
      .Default(::std::nullopt);
}
::std::optional<WGMMALayout> symbolizeWGMMALayout(uint32_t value) {
  switch (value) {
  case 0: return WGMMALayout::row;
  case 1: return WGMMALayout::col;
  default: return ::std::nullopt;
  }
}

bool WGMMALayoutAttr::classof(::mlir::Attribute attr) {
  return (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && (((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 0)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 1)));
}
WGMMALayoutAttr WGMMALayoutAttr::get(::mlir::MLIRContext *context, WGMMALayout val) {
  ::mlir::IntegerType intType = ::mlir::IntegerType::get(context, 32);
  ::mlir::IntegerAttr baseAttr = ::mlir::IntegerAttr::get(intType, static_cast<uint32_t>(val));
  return ::llvm::cast<WGMMALayoutAttr>(baseAttr);
}
WGMMALayout WGMMALayoutAttr::getValue() const {
  return static_cast<WGMMALayout>(::mlir::IntegerAttr::getInt());
}
} // namespace nvgpu
} // namespace triton
} // namespace mlir

