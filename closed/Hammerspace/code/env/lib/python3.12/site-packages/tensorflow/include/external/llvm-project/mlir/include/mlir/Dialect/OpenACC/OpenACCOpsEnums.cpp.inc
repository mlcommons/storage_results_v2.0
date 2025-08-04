/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Definitions                                                   *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: OpenACCOps.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace acc {
::llvm::StringRef stringifyClauseDefaultValue(ClauseDefaultValue val) {
  switch (val) {
    case ClauseDefaultValue::Present: return "present";
    case ClauseDefaultValue::None: return "none";
  }
  return "";
}

::std::optional<ClauseDefaultValue> symbolizeClauseDefaultValue(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<ClauseDefaultValue>>(str)
      .Case("present", ClauseDefaultValue::Present)
      .Case("none", ClauseDefaultValue::None)
      .Default(::std::nullopt);
}
::std::optional<ClauseDefaultValue> symbolizeClauseDefaultValue(uint32_t value) {
  switch (value) {
  case 0: return ClauseDefaultValue::Present;
  case 1: return ClauseDefaultValue::None;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

namespace mlir {
namespace acc {
::llvm::StringRef stringifyCombinedConstructsType(CombinedConstructsType val) {
  switch (val) {
    case CombinedConstructsType::KernelsLoop: return "kernels_loop";
    case CombinedConstructsType::ParallelLoop: return "parallel_loop";
    case CombinedConstructsType::SerialLoop: return "serial_loop";
  }
  return "";
}

::std::optional<CombinedConstructsType> symbolizeCombinedConstructsType(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<CombinedConstructsType>>(str)
      .Case("kernels_loop", CombinedConstructsType::KernelsLoop)
      .Case("parallel_loop", CombinedConstructsType::ParallelLoop)
      .Case("serial_loop", CombinedConstructsType::SerialLoop)
      .Default(::std::nullopt);
}
::std::optional<CombinedConstructsType> symbolizeCombinedConstructsType(uint32_t value) {
  switch (value) {
  case 1: return CombinedConstructsType::KernelsLoop;
  case 2: return CombinedConstructsType::ParallelLoop;
  case 3: return CombinedConstructsType::SerialLoop;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

namespace mlir {
namespace acc {
::llvm::StringRef stringifyConstruct(Construct val) {
  switch (val) {
    case Construct::acc_construct_parallel: return "acc_construct_parallel";
    case Construct::acc_construct_kernels: return "acc_construct_kernels";
    case Construct::acc_construct_loop: return "acc_construct_loop";
    case Construct::acc_construct_data: return "acc_construct_data";
    case Construct::acc_construct_enter_data: return "acc_construct_enter_data";
    case Construct::acc_construct_exit_data: return "acc_construct_exit_data";
    case Construct::acc_construct_host_data: return "acc_construct_host_data";
    case Construct::acc_construct_atomic: return "acc_construct_atomic";
    case Construct::acc_construct_declare: return "acc_construct_declare";
    case Construct::acc_construct_init: return "acc_construct_init";
    case Construct::acc_construct_shutdown: return "acc_construct_shutdown";
    case Construct::acc_construct_set: return "acc_construct_set";
    case Construct::acc_construct_update: return "acc_construct_update";
    case Construct::acc_construct_routine: return "acc_construct_routine";
    case Construct::acc_construct_wait: return "acc_construct_wait";
    case Construct::acc_construct_runtime_api: return "acc_construct_runtime_api";
    case Construct::acc_construct_serial: return "acc_construct_serial";
  }
  return "";
}

::std::optional<Construct> symbolizeConstruct(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<Construct>>(str)
      .Case("acc_construct_parallel", Construct::acc_construct_parallel)
      .Case("acc_construct_kernels", Construct::acc_construct_kernels)
      .Case("acc_construct_loop", Construct::acc_construct_loop)
      .Case("acc_construct_data", Construct::acc_construct_data)
      .Case("acc_construct_enter_data", Construct::acc_construct_enter_data)
      .Case("acc_construct_exit_data", Construct::acc_construct_exit_data)
      .Case("acc_construct_host_data", Construct::acc_construct_host_data)
      .Case("acc_construct_atomic", Construct::acc_construct_atomic)
      .Case("acc_construct_declare", Construct::acc_construct_declare)
      .Case("acc_construct_init", Construct::acc_construct_init)
      .Case("acc_construct_shutdown", Construct::acc_construct_shutdown)
      .Case("acc_construct_set", Construct::acc_construct_set)
      .Case("acc_construct_update", Construct::acc_construct_update)
      .Case("acc_construct_routine", Construct::acc_construct_routine)
      .Case("acc_construct_wait", Construct::acc_construct_wait)
      .Case("acc_construct_runtime_api", Construct::acc_construct_runtime_api)
      .Case("acc_construct_serial", Construct::acc_construct_serial)
      .Default(::std::nullopt);
}
::std::optional<Construct> symbolizeConstruct(uint64_t value) {
  switch (value) {
  case 0: return Construct::acc_construct_parallel;
  case 1: return Construct::acc_construct_kernels;
  case 2: return Construct::acc_construct_loop;
  case 3: return Construct::acc_construct_data;
  case 4: return Construct::acc_construct_enter_data;
  case 5: return Construct::acc_construct_exit_data;
  case 6: return Construct::acc_construct_host_data;
  case 7: return Construct::acc_construct_atomic;
  case 8: return Construct::acc_construct_declare;
  case 9: return Construct::acc_construct_init;
  case 10: return Construct::acc_construct_shutdown;
  case 11: return Construct::acc_construct_set;
  case 12: return Construct::acc_construct_update;
  case 13: return Construct::acc_construct_routine;
  case 14: return Construct::acc_construct_wait;
  case 15: return Construct::acc_construct_runtime_api;
  case 16: return Construct::acc_construct_serial;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

namespace mlir {
namespace acc {
::llvm::StringRef stringifyDataClause(DataClause val) {
  switch (val) {
    case DataClause::acc_copyin: return "acc_copyin";
    case DataClause::acc_copyin_readonly: return "acc_copyin_readonly";
    case DataClause::acc_copy: return "acc_copy";
    case DataClause::acc_copyout: return "acc_copyout";
    case DataClause::acc_copyout_zero: return "acc_copyout_zero";
    case DataClause::acc_present: return "acc_present";
    case DataClause::acc_create: return "acc_create";
    case DataClause::acc_create_zero: return "acc_create_zero";
    case DataClause::acc_delete: return "acc_delete";
    case DataClause::acc_attach: return "acc_attach";
    case DataClause::acc_detach: return "acc_detach";
    case DataClause::acc_no_create: return "acc_no_create";
    case DataClause::acc_private: return "acc_private";
    case DataClause::acc_firstprivate: return "acc_firstprivate";
    case DataClause::acc_deviceptr: return "acc_deviceptr";
    case DataClause::acc_getdeviceptr: return "acc_getdeviceptr";
    case DataClause::acc_update_host: return "acc_update_host";
    case DataClause::acc_update_self: return "acc_update_self";
    case DataClause::acc_update_device: return "acc_update_device";
    case DataClause::acc_use_device: return "acc_use_device";
    case DataClause::acc_reduction: return "acc_reduction";
    case DataClause::acc_declare_device_resident: return "acc_declare_device_resident";
    case DataClause::acc_declare_link: return "acc_declare_link";
    case DataClause::acc_cache: return "acc_cache";
    case DataClause::acc_cache_readonly: return "acc_cache_readonly";
  }
  return "";
}

::std::optional<DataClause> symbolizeDataClause(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<DataClause>>(str)
      .Case("acc_copyin", DataClause::acc_copyin)
      .Case("acc_copyin_readonly", DataClause::acc_copyin_readonly)
      .Case("acc_copy", DataClause::acc_copy)
      .Case("acc_copyout", DataClause::acc_copyout)
      .Case("acc_copyout_zero", DataClause::acc_copyout_zero)
      .Case("acc_present", DataClause::acc_present)
      .Case("acc_create", DataClause::acc_create)
      .Case("acc_create_zero", DataClause::acc_create_zero)
      .Case("acc_delete", DataClause::acc_delete)
      .Case("acc_attach", DataClause::acc_attach)
      .Case("acc_detach", DataClause::acc_detach)
      .Case("acc_no_create", DataClause::acc_no_create)
      .Case("acc_private", DataClause::acc_private)
      .Case("acc_firstprivate", DataClause::acc_firstprivate)
      .Case("acc_deviceptr", DataClause::acc_deviceptr)
      .Case("acc_getdeviceptr", DataClause::acc_getdeviceptr)
      .Case("acc_update_host", DataClause::acc_update_host)
      .Case("acc_update_self", DataClause::acc_update_self)
      .Case("acc_update_device", DataClause::acc_update_device)
      .Case("acc_use_device", DataClause::acc_use_device)
      .Case("acc_reduction", DataClause::acc_reduction)
      .Case("acc_declare_device_resident", DataClause::acc_declare_device_resident)
      .Case("acc_declare_link", DataClause::acc_declare_link)
      .Case("acc_cache", DataClause::acc_cache)
      .Case("acc_cache_readonly", DataClause::acc_cache_readonly)
      .Default(::std::nullopt);
}
::std::optional<DataClause> symbolizeDataClause(uint64_t value) {
  switch (value) {
  case 1: return DataClause::acc_copyin;
  case 2: return DataClause::acc_copyin_readonly;
  case 3: return DataClause::acc_copy;
  case 4: return DataClause::acc_copyout;
  case 5: return DataClause::acc_copyout_zero;
  case 6: return DataClause::acc_present;
  case 7: return DataClause::acc_create;
  case 8: return DataClause::acc_create_zero;
  case 9: return DataClause::acc_delete;
  case 10: return DataClause::acc_attach;
  case 11: return DataClause::acc_detach;
  case 12: return DataClause::acc_no_create;
  case 13: return DataClause::acc_private;
  case 14: return DataClause::acc_firstprivate;
  case 15: return DataClause::acc_deviceptr;
  case 16: return DataClause::acc_getdeviceptr;
  case 17: return DataClause::acc_update_host;
  case 18: return DataClause::acc_update_self;
  case 19: return DataClause::acc_update_device;
  case 20: return DataClause::acc_use_device;
  case 21: return DataClause::acc_reduction;
  case 22: return DataClause::acc_declare_device_resident;
  case 23: return DataClause::acc_declare_link;
  case 24: return DataClause::acc_cache;
  case 25: return DataClause::acc_cache_readonly;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

namespace mlir {
namespace acc {
::llvm::StringRef stringifyDeviceType(DeviceType val) {
  switch (val) {
    case DeviceType::None: return "none";
    case DeviceType::Star: return "star";
    case DeviceType::Default: return "default";
    case DeviceType::Host: return "host";
    case DeviceType::Multicore: return "multicore";
    case DeviceType::Nvidia: return "nvidia";
    case DeviceType::Radeon: return "radeon";
  }
  return "";
}

::std::optional<DeviceType> symbolizeDeviceType(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<DeviceType>>(str)
      .Case("none", DeviceType::None)
      .Case("star", DeviceType::Star)
      .Case("default", DeviceType::Default)
      .Case("host", DeviceType::Host)
      .Case("multicore", DeviceType::Multicore)
      .Case("nvidia", DeviceType::Nvidia)
      .Case("radeon", DeviceType::Radeon)
      .Default(::std::nullopt);
}
::std::optional<DeviceType> symbolizeDeviceType(uint32_t value) {
  switch (value) {
  case 0: return DeviceType::None;
  case 1: return DeviceType::Star;
  case 2: return DeviceType::Default;
  case 3: return DeviceType::Host;
  case 4: return DeviceType::Multicore;
  case 5: return DeviceType::Nvidia;
  case 6: return DeviceType::Radeon;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

namespace mlir {
namespace acc {
::llvm::StringRef stringifyGangArgType(GangArgType val) {
  switch (val) {
    case GangArgType::Num: return "Num";
    case GangArgType::Dim: return "Dim";
    case GangArgType::Static: return "Static";
  }
  return "";
}

::std::optional<GangArgType> symbolizeGangArgType(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<GangArgType>>(str)
      .Case("Num", GangArgType::Num)
      .Case("Dim", GangArgType::Dim)
      .Case("Static", GangArgType::Static)
      .Default(::std::nullopt);
}
::std::optional<GangArgType> symbolizeGangArgType(uint32_t value) {
  switch (value) {
  case 0: return GangArgType::Num;
  case 1: return GangArgType::Dim;
  case 2: return GangArgType::Static;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

namespace mlir {
namespace acc {
::llvm::StringRef stringifyReductionOperator(ReductionOperator val) {
  switch (val) {
    case ReductionOperator::AccAdd: return "add";
    case ReductionOperator::AccMul: return "mul";
    case ReductionOperator::AccMax: return "max";
    case ReductionOperator::AccMin: return "min";
    case ReductionOperator::AccIand: return "iand";
    case ReductionOperator::AccIor: return "ior";
    case ReductionOperator::AccXor: return "xor";
    case ReductionOperator::AccEqv: return "eqv";
    case ReductionOperator::AccNeqv: return "neqv";
    case ReductionOperator::AccLand: return "land";
    case ReductionOperator::AccLor: return "lor";
  }
  return "";
}

::std::optional<ReductionOperator> symbolizeReductionOperator(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<ReductionOperator>>(str)
      .Case("add", ReductionOperator::AccAdd)
      .Case("mul", ReductionOperator::AccMul)
      .Case("max", ReductionOperator::AccMax)
      .Case("min", ReductionOperator::AccMin)
      .Case("iand", ReductionOperator::AccIand)
      .Case("ior", ReductionOperator::AccIor)
      .Case("xor", ReductionOperator::AccXor)
      .Case("eqv", ReductionOperator::AccEqv)
      .Case("neqv", ReductionOperator::AccNeqv)
      .Case("land", ReductionOperator::AccLand)
      .Case("lor", ReductionOperator::AccLor)
      .Default(::std::nullopt);
}
::std::optional<ReductionOperator> symbolizeReductionOperator(uint32_t value) {
  switch (value) {
  case 0: return ReductionOperator::AccAdd;
  case 1: return ReductionOperator::AccMul;
  case 2: return ReductionOperator::AccMax;
  case 3: return ReductionOperator::AccMin;
  case 4: return ReductionOperator::AccIand;
  case 5: return ReductionOperator::AccIor;
  case 6: return ReductionOperator::AccXor;
  case 7: return ReductionOperator::AccEqv;
  case 8: return ReductionOperator::AccNeqv;
  case 9: return ReductionOperator::AccLand;
  case 10: return ReductionOperator::AccLor;
  default: return ::std::nullopt;
  }
}

} // namespace acc
} // namespace mlir

