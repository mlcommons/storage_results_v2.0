/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Definitions                                                   *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: XeGPUAttrs.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace xegpu {
::llvm::StringRef stringifyCachePolicy(CachePolicy val) {
  switch (val) {
    case CachePolicy::CACHED: return "cached";
    case CachePolicy::UNCACHED: return "uncached";
    case CachePolicy::STREAMING: return "streaming";
    case CachePolicy::READ_INVALIDATE: return "read_invalidate";
    case CachePolicy::WRITE_BACK: return "write_back";
    case CachePolicy::WRITE_THROUGH: return "write_through";
  }
  return "";
}

::std::optional<CachePolicy> symbolizeCachePolicy(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<CachePolicy>>(str)
      .Case("cached", CachePolicy::CACHED)
      .Case("uncached", CachePolicy::UNCACHED)
      .Case("streaming", CachePolicy::STREAMING)
      .Case("read_invalidate", CachePolicy::READ_INVALIDATE)
      .Case("write_back", CachePolicy::WRITE_BACK)
      .Case("write_through", CachePolicy::WRITE_THROUGH)
      .Default(::std::nullopt);
}
::std::optional<CachePolicy> symbolizeCachePolicy(uint32_t value) {
  switch (value) {
  case 0: return CachePolicy::CACHED;
  case 1: return CachePolicy::UNCACHED;
  case 2: return CachePolicy::STREAMING;
  case 3: return CachePolicy::READ_INVALIDATE;
  case 4: return CachePolicy::WRITE_BACK;
  case 5: return CachePolicy::WRITE_THROUGH;
  default: return ::std::nullopt;
  }
}

} // namespace xegpu
} // namespace mlir

namespace mlir {
namespace xegpu {
::llvm::StringRef stringifyFenceScope(FenceScope val) {
  switch (val) {
    case FenceScope::Workgroup: return "workgroup";
    case FenceScope::GPU: return "gpu";
  }
  return "";
}

::std::optional<FenceScope> symbolizeFenceScope(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<FenceScope>>(str)
      .Case("workgroup", FenceScope::Workgroup)
      .Case("gpu", FenceScope::GPU)
      .Default(::std::nullopt);
}
::std::optional<FenceScope> symbolizeFenceScope(uint32_t value) {
  switch (value) {
  case 0: return FenceScope::Workgroup;
  case 1: return FenceScope::GPU;
  default: return ::std::nullopt;
  }
}

} // namespace xegpu
} // namespace mlir

namespace mlir {
namespace xegpu {
::llvm::StringRef stringifyMemorySpace(MemorySpace val) {
  switch (val) {
    case MemorySpace::Global: return "global";
    case MemorySpace::SLM: return "slm";
  }
  return "";
}

::std::optional<MemorySpace> symbolizeMemorySpace(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<MemorySpace>>(str)
      .Case("global", MemorySpace::Global)
      .Case("slm", MemorySpace::SLM)
      .Default(::std::nullopt);
}
::std::optional<MemorySpace> symbolizeMemorySpace(uint32_t value) {
  switch (value) {
  case 0: return MemorySpace::Global;
  case 3: return MemorySpace::SLM;
  default: return ::std::nullopt;
  }
}

} // namespace xegpu
} // namespace mlir

