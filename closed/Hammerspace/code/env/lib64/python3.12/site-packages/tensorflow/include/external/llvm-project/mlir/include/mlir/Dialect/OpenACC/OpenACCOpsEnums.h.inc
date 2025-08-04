/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: OpenACCOps.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace acc {
// DefaultValue Clause
enum class ClauseDefaultValue : uint32_t {
  Present = 0,
  None = 1,
};

::std::optional<ClauseDefaultValue> symbolizeClauseDefaultValue(uint32_t);
::llvm::StringRef stringifyClauseDefaultValue(ClauseDefaultValue);
::std::optional<ClauseDefaultValue> symbolizeClauseDefaultValue(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForClauseDefaultValue() {
  return 1;
}


inline ::llvm::StringRef stringifyEnum(ClauseDefaultValue enumValue) {
  return stringifyClauseDefaultValue(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<ClauseDefaultValue> symbolizeEnum<ClauseDefaultValue>(::llvm::StringRef str) {
  return symbolizeClauseDefaultValue(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::ClauseDefaultValue, ::mlir::acc::ClauseDefaultValue> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::ClauseDefaultValue> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for DefaultValue Clause");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::ClauseDefaultValue> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::ClauseDefaultValue>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid DefaultValue Clause specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::ClauseDefaultValue>, std::optional<::mlir::acc::ClauseDefaultValue>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::ClauseDefaultValue>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::ClauseDefaultValue>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::ClauseDefaultValue> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::ClauseDefaultValue>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid DefaultValue Clause specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::ClauseDefaultValue value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::ClauseDefaultValue> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::acc::ClauseDefaultValue getEmptyKey() {
    return static_cast<::mlir::acc::ClauseDefaultValue>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::ClauseDefaultValue getTombstoneKey() {
    return static_cast<::mlir::acc::ClauseDefaultValue>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::ClauseDefaultValue &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::acc::ClauseDefaultValue &lhs, const ::mlir::acc::ClauseDefaultValue &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace acc {
// Differentiate between combined constructs
enum class CombinedConstructsType : uint32_t {
  KernelsLoop = 1,
  ParallelLoop = 2,
  SerialLoop = 3,
};

::std::optional<CombinedConstructsType> symbolizeCombinedConstructsType(uint32_t);
::llvm::StringRef stringifyCombinedConstructsType(CombinedConstructsType);
::std::optional<CombinedConstructsType> symbolizeCombinedConstructsType(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForCombinedConstructsType() {
  return 3;
}


inline ::llvm::StringRef stringifyEnum(CombinedConstructsType enumValue) {
  return stringifyCombinedConstructsType(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<CombinedConstructsType> symbolizeEnum<CombinedConstructsType>(::llvm::StringRef str) {
  return symbolizeCombinedConstructsType(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::CombinedConstructsType, ::mlir::acc::CombinedConstructsType> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::CombinedConstructsType> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for Differentiate between combined constructs");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::CombinedConstructsType> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::CombinedConstructsType>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid Differentiate between combined constructs specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::CombinedConstructsType>, std::optional<::mlir::acc::CombinedConstructsType>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::CombinedConstructsType>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::CombinedConstructsType>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::CombinedConstructsType> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::CombinedConstructsType>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid Differentiate between combined constructs specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::CombinedConstructsType value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::CombinedConstructsType> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::acc::CombinedConstructsType getEmptyKey() {
    return static_cast<::mlir::acc::CombinedConstructsType>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::CombinedConstructsType getTombstoneKey() {
    return static_cast<::mlir::acc::CombinedConstructsType>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::CombinedConstructsType &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::acc::CombinedConstructsType &lhs, const ::mlir::acc::CombinedConstructsType &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace acc {
// constructs supported by OpenACC
enum class Construct : uint64_t {
  acc_construct_parallel = 0,
  acc_construct_kernels = 1,
  acc_construct_loop = 2,
  acc_construct_data = 3,
  acc_construct_enter_data = 4,
  acc_construct_exit_data = 5,
  acc_construct_host_data = 6,
  acc_construct_atomic = 7,
  acc_construct_declare = 8,
  acc_construct_init = 9,
  acc_construct_shutdown = 10,
  acc_construct_set = 11,
  acc_construct_update = 12,
  acc_construct_routine = 13,
  acc_construct_wait = 14,
  acc_construct_runtime_api = 15,
  acc_construct_serial = 16,
};

::std::optional<Construct> symbolizeConstruct(uint64_t);
::llvm::StringRef stringifyConstruct(Construct);
::std::optional<Construct> symbolizeConstruct(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForConstruct() {
  return 16;
}


inline ::llvm::StringRef stringifyEnum(Construct enumValue) {
  return stringifyConstruct(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<Construct> symbolizeEnum<Construct>(::llvm::StringRef str) {
  return symbolizeConstruct(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::Construct, ::mlir::acc::Construct> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::Construct> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for constructs supported by OpenACC");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::Construct> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::Construct>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid constructs supported by OpenACC specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::Construct>, std::optional<::mlir::acc::Construct>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::Construct>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::Construct>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::Construct> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::Construct>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid constructs supported by OpenACC specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::Construct value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::Construct> {
  using StorageInfo = ::llvm::DenseMapInfo<uint64_t>;

  static inline ::mlir::acc::Construct getEmptyKey() {
    return static_cast<::mlir::acc::Construct>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::Construct getTombstoneKey() {
    return static_cast<::mlir::acc::Construct>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::Construct &val) {
    return StorageInfo::getHashValue(static_cast<uint64_t>(val));
  }

  static bool isEqual(const ::mlir::acc::Construct &lhs, const ::mlir::acc::Construct &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace acc {
// data clauses supported by OpenACC
enum class DataClause : uint64_t {
  acc_copyin = 1,
  acc_copyin_readonly = 2,
  acc_copy = 3,
  acc_copyout = 4,
  acc_copyout_zero = 5,
  acc_present = 6,
  acc_create = 7,
  acc_create_zero = 8,
  acc_delete = 9,
  acc_attach = 10,
  acc_detach = 11,
  acc_no_create = 12,
  acc_private = 13,
  acc_firstprivate = 14,
  acc_deviceptr = 15,
  acc_getdeviceptr = 16,
  acc_update_host = 17,
  acc_update_self = 18,
  acc_update_device = 19,
  acc_use_device = 20,
  acc_reduction = 21,
  acc_declare_device_resident = 22,
  acc_declare_link = 23,
  acc_cache = 24,
  acc_cache_readonly = 25,
};

::std::optional<DataClause> symbolizeDataClause(uint64_t);
::llvm::StringRef stringifyDataClause(DataClause);
::std::optional<DataClause> symbolizeDataClause(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForDataClause() {
  return 25;
}


inline ::llvm::StringRef stringifyEnum(DataClause enumValue) {
  return stringifyDataClause(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<DataClause> symbolizeEnum<DataClause>(::llvm::StringRef str) {
  return symbolizeDataClause(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::DataClause, ::mlir::acc::DataClause> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::DataClause> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for data clauses supported by OpenACC");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::DataClause> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::DataClause>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid data clauses supported by OpenACC specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::DataClause>, std::optional<::mlir::acc::DataClause>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::DataClause>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::DataClause>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::DataClause> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::DataClause>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid data clauses supported by OpenACC specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::DataClause value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::DataClause> {
  using StorageInfo = ::llvm::DenseMapInfo<uint64_t>;

  static inline ::mlir::acc::DataClause getEmptyKey() {
    return static_cast<::mlir::acc::DataClause>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::DataClause getTombstoneKey() {
    return static_cast<::mlir::acc::DataClause>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::DataClause &val) {
    return StorageInfo::getHashValue(static_cast<uint64_t>(val));
  }

  static bool isEqual(const ::mlir::acc::DataClause &lhs, const ::mlir::acc::DataClause &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace acc {
// built-in device type supported by OpenACC
enum class DeviceType : uint32_t {
  None = 0,
  Star = 1,
  Default = 2,
  Host = 3,
  Multicore = 4,
  Nvidia = 5,
  Radeon = 6,
};

::std::optional<DeviceType> symbolizeDeviceType(uint32_t);
::llvm::StringRef stringifyDeviceType(DeviceType);
::std::optional<DeviceType> symbolizeDeviceType(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForDeviceType() {
  return 6;
}


inline ::llvm::StringRef stringifyEnum(DeviceType enumValue) {
  return stringifyDeviceType(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<DeviceType> symbolizeEnum<DeviceType>(::llvm::StringRef str) {
  return symbolizeDeviceType(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::DeviceType, ::mlir::acc::DeviceType> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::DeviceType> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for built-in device type supported by OpenACC");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::DeviceType> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::DeviceType>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid built-in device type supported by OpenACC specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::DeviceType>, std::optional<::mlir::acc::DeviceType>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::DeviceType>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::DeviceType>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::DeviceType> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::DeviceType>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid built-in device type supported by OpenACC specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::DeviceType value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::DeviceType> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::acc::DeviceType getEmptyKey() {
    return static_cast<::mlir::acc::DeviceType>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::DeviceType getTombstoneKey() {
    return static_cast<::mlir::acc::DeviceType>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::DeviceType &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::acc::DeviceType &lhs, const ::mlir::acc::DeviceType &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace acc {
// Differentiate the different gang arg values
enum class GangArgType : uint32_t {
  Num = 0,
  Dim = 1,
  Static = 2,
};

::std::optional<GangArgType> symbolizeGangArgType(uint32_t);
::llvm::StringRef stringifyGangArgType(GangArgType);
::std::optional<GangArgType> symbolizeGangArgType(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForGangArgType() {
  return 2;
}


inline ::llvm::StringRef stringifyEnum(GangArgType enumValue) {
  return stringifyGangArgType(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<GangArgType> symbolizeEnum<GangArgType>(::llvm::StringRef str) {
  return symbolizeGangArgType(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::GangArgType, ::mlir::acc::GangArgType> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::GangArgType> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for Differentiate the different gang arg values");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::GangArgType> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::GangArgType>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid Differentiate the different gang arg values specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::GangArgType>, std::optional<::mlir::acc::GangArgType>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::GangArgType>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::GangArgType>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::GangArgType> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::GangArgType>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid Differentiate the different gang arg values specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::GangArgType value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::GangArgType> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::acc::GangArgType getEmptyKey() {
    return static_cast<::mlir::acc::GangArgType>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::GangArgType getTombstoneKey() {
    return static_cast<::mlir::acc::GangArgType>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::GangArgType &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::acc::GangArgType &lhs, const ::mlir::acc::GangArgType &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace acc {
// built-in reduction operations supported by OpenACC
enum class ReductionOperator : uint32_t {
  AccAdd = 0,
  AccMul = 1,
  AccMax = 2,
  AccMin = 3,
  AccIand = 4,
  AccIor = 5,
  AccXor = 6,
  AccEqv = 7,
  AccNeqv = 8,
  AccLand = 9,
  AccLor = 10,
};

::std::optional<ReductionOperator> symbolizeReductionOperator(uint32_t);
::llvm::StringRef stringifyReductionOperator(ReductionOperator);
::std::optional<ReductionOperator> symbolizeReductionOperator(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForReductionOperator() {
  return 10;
}


inline ::llvm::StringRef stringifyEnum(ReductionOperator enumValue) {
  return stringifyReductionOperator(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<ReductionOperator> symbolizeEnum<ReductionOperator>(::llvm::StringRef str) {
  return symbolizeReductionOperator(str);
}
} // namespace acc
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::acc::ReductionOperator, ::mlir::acc::ReductionOperator> {
  template <typename ParserT>
  static FailureOr<::mlir::acc::ReductionOperator> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for built-in reduction operations supported by OpenACC");

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::ReductionOperator> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::ReductionOperator>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid built-in reduction operations supported by OpenACC specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::acc::ReductionOperator>, std::optional<::mlir::acc::ReductionOperator>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::acc::ReductionOperator>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::acc::ReductionOperator>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::acc::ReductionOperator> attr = ::mlir::acc::symbolizeEnum<::mlir::acc::ReductionOperator>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid built-in reduction operations supported by OpenACC specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::acc::ReductionOperator value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::acc::ReductionOperator> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::acc::ReductionOperator getEmptyKey() {
    return static_cast<::mlir::acc::ReductionOperator>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::acc::ReductionOperator getTombstoneKey() {
    return static_cast<::mlir::acc::ReductionOperator>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::acc::ReductionOperator &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::acc::ReductionOperator &lhs, const ::mlir::acc::ReductionOperator &rhs) {
    return lhs == rhs;
  }
};
}

