/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Definitions                                                   *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ProtonOps.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
namespace proton {
::llvm::StringRef stringifyGranularity(Granularity val) {
  switch (val) {
    case Granularity::WARPGROUP: return "warpgroup";
    case Granularity::WARP: return "warp";
  }
  return "";
}

::std::optional<Granularity> symbolizeGranularity(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<Granularity>>(str)
      .Case("warpgroup", Granularity::WARPGROUP)
      .Case("warp", Granularity::WARP)
      .Default(::std::nullopt);
}
::std::optional<Granularity> symbolizeGranularity(uint32_t value) {
  switch (value) {
  case 0: return Granularity::WARPGROUP;
  case 1: return Granularity::WARP;
  default: return ::std::nullopt;
  }
}

bool GranularityAttr::classof(::mlir::Attribute attr) {
  return (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && (((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 0)) || ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 1)));
}
GranularityAttr GranularityAttr::get(::mlir::MLIRContext *context, Granularity val) {
  ::mlir::IntegerType intType = ::mlir::IntegerType::get(context, 32);
  ::mlir::IntegerAttr baseAttr = ::mlir::IntegerAttr::get(intType, static_cast<uint32_t>(val));
  return ::llvm::cast<GranularityAttr>(baseAttr);
}
Granularity GranularityAttr::getValue() const {
  return static_cast<Granularity>(::mlir::IntegerAttr::getInt());
}
} // namespace proton
} // namespace triton
} // namespace mlir

namespace mlir {
namespace triton {
namespace proton {
::llvm::StringRef stringifyMetric(Metric val) {
  switch (val) {
    case Metric::CYCLE: return "cycle";
  }
  return "";
}

::std::optional<Metric> symbolizeMetric(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<Metric>>(str)
      .Case("cycle", Metric::CYCLE)
      .Default(::std::nullopt);
}
::std::optional<Metric> symbolizeMetric(uint32_t value) {
  switch (value) {
  case 0: return Metric::CYCLE;
  default: return ::std::nullopt;
  }
}

bool MetricAttr::classof(::mlir::Attribute attr) {
  return (((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getInt() == 0));
}
MetricAttr MetricAttr::get(::mlir::MLIRContext *context, Metric val) {
  ::mlir::IntegerType intType = ::mlir::IntegerType::get(context, 32);
  ::mlir::IntegerAttr baseAttr = ::mlir::IntegerAttr::get(intType, static_cast<uint32_t>(val));
  return ::llvm::cast<MetricAttr>(baseAttr);
}
Metric MetricAttr::getValue() const {
  return static_cast<Metric>(::mlir::IntegerAttr::getInt());
}
} // namespace proton
} // namespace triton
} // namespace mlir

