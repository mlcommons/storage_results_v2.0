/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: AMDGPU.td                                                            *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace amdgpu {
// The possible permutations for a DPP operation
enum class DPPPerm : uint32_t {
  quad_perm = 0,
  row_shl = 1,
  row_shr = 2,
  row_ror = 3,
  wave_shl = 4,
  wave_shr = 5,
  wave_ror = 6,
  wave_rol = 7,
  row_mirror = 8,
  row_half_mirror = 9,
  row_bcast_15 = 10,
  row_bcast_31 = 11,
};

::std::optional<DPPPerm> symbolizeDPPPerm(uint32_t);
::llvm::StringRef stringifyDPPPerm(DPPPerm);
::std::optional<DPPPerm> symbolizeDPPPerm(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForDPPPerm() {
  return 11;
}


inline ::llvm::StringRef stringifyEnum(DPPPerm enumValue) {
  return stringifyDPPPerm(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<DPPPerm> symbolizeEnum<DPPPerm>(::llvm::StringRef str) {
  return symbolizeDPPPerm(str);
}
} // namespace amdgpu
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::amdgpu::DPPPerm, ::mlir::amdgpu::DPPPerm> {
  template <typename ParserT>
  static FailureOr<::mlir::amdgpu::DPPPerm> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for The possible permutations for a DPP operation");

    // Symbolize the keyword.
    if (::std::optional<::mlir::amdgpu::DPPPerm> attr = ::mlir::amdgpu::symbolizeEnum<::mlir::amdgpu::DPPPerm>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid The possible permutations for a DPP operation specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::amdgpu::DPPPerm>, std::optional<::mlir::amdgpu::DPPPerm>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::amdgpu::DPPPerm>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::amdgpu::DPPPerm>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::amdgpu::DPPPerm> attr = ::mlir::amdgpu::symbolizeEnum<::mlir::amdgpu::DPPPerm>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid The possible permutations for a DPP operation specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::amdgpu::DPPPerm value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::amdgpu::DPPPerm> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::amdgpu::DPPPerm getEmptyKey() {
    return static_cast<::mlir::amdgpu::DPPPerm>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::amdgpu::DPPPerm getTombstoneKey() {
    return static_cast<::mlir::amdgpu::DPPPerm>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::amdgpu::DPPPerm &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::amdgpu::DPPPerm &lhs, const ::mlir::amdgpu::DPPPerm &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace amdgpu {
// The possible permutations of the lanes storing B available in an MFMA
enum class MFMAPermB : uint32_t {
  none = 0,
  bcast_first_32 = 1,
  bcast_second_32 = 2,
  rotate_16_right = 3,
  bcast_first_16 = 4,
  bcast_second_16 = 5,
  bcast_third_16 = 6,
  bcast_fourth_16 = 7,
};

::std::optional<MFMAPermB> symbolizeMFMAPermB(uint32_t);
::llvm::StringRef stringifyMFMAPermB(MFMAPermB);
::std::optional<MFMAPermB> symbolizeMFMAPermB(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMFMAPermB() {
  return 7;
}


inline ::llvm::StringRef stringifyEnum(MFMAPermB enumValue) {
  return stringifyMFMAPermB(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<MFMAPermB> symbolizeEnum<MFMAPermB>(::llvm::StringRef str) {
  return symbolizeMFMAPermB(str);
}
} // namespace amdgpu
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::amdgpu::MFMAPermB, ::mlir::amdgpu::MFMAPermB> {
  template <typename ParserT>
  static FailureOr<::mlir::amdgpu::MFMAPermB> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for The possible permutations of the lanes storing B available in an MFMA");

    // Symbolize the keyword.
    if (::std::optional<::mlir::amdgpu::MFMAPermB> attr = ::mlir::amdgpu::symbolizeEnum<::mlir::amdgpu::MFMAPermB>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid The possible permutations of the lanes storing B available in an MFMA specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::amdgpu::MFMAPermB>, std::optional<::mlir::amdgpu::MFMAPermB>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::amdgpu::MFMAPermB>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::amdgpu::MFMAPermB>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::amdgpu::MFMAPermB> attr = ::mlir::amdgpu::symbolizeEnum<::mlir::amdgpu::MFMAPermB>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid The possible permutations of the lanes storing B available in an MFMA specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::amdgpu::MFMAPermB value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::amdgpu::MFMAPermB> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::amdgpu::MFMAPermB getEmptyKey() {
    return static_cast<::mlir::amdgpu::MFMAPermB>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::amdgpu::MFMAPermB getTombstoneKey() {
    return static_cast<::mlir::amdgpu::MFMAPermB>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::amdgpu::MFMAPermB &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::amdgpu::MFMAPermB &lhs, const ::mlir::amdgpu::MFMAPermB &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace amdgpu {
// The possible options for scheduling barriers
enum class sched_barrier_opt_enum : uint32_t {
  none = 0,
  non_mem_non_sideffect = 1,
  valu = 2,
  salu = 4,
  mfma_wmma = 8,
  all_vmem = 16,
  vmem_read = 32,
  vmem_write = 64,
  all_ds = 128,
  ds_read = 256,
  ds_write = 512,
  transcendental = 1024,
};

::std::optional<sched_barrier_opt_enum> symbolizesched_barrier_opt_enum(uint32_t);
std::string stringifysched_barrier_opt_enum(sched_barrier_opt_enum);
::std::optional<sched_barrier_opt_enum> symbolizesched_barrier_opt_enum(::llvm::StringRef);

inline constexpr sched_barrier_opt_enum operator|(sched_barrier_opt_enum a, sched_barrier_opt_enum b) {
  return static_cast<sched_barrier_opt_enum>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}
inline constexpr sched_barrier_opt_enum operator&(sched_barrier_opt_enum a, sched_barrier_opt_enum b) {
  return static_cast<sched_barrier_opt_enum>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
}
inline constexpr sched_barrier_opt_enum operator^(sched_barrier_opt_enum a, sched_barrier_opt_enum b) {
  return static_cast<sched_barrier_opt_enum>(static_cast<uint32_t>(a) ^ static_cast<uint32_t>(b));
}
inline constexpr sched_barrier_opt_enum operator~(sched_barrier_opt_enum bits) {
  // Ensure only bits that can be present in the enum are set
  return static_cast<sched_barrier_opt_enum>(~static_cast<uint32_t>(bits) & static_cast<uint32_t>(2047u));
}
inline constexpr bool bitEnumContainsAll(sched_barrier_opt_enum bits, sched_barrier_opt_enum bit) {
  return (bits & bit) == bit;
}
inline constexpr bool bitEnumContainsAny(sched_barrier_opt_enum bits, sched_barrier_opt_enum bit) {
  return (static_cast<uint32_t>(bits) & static_cast<uint32_t>(bit)) != 0;
}
inline constexpr sched_barrier_opt_enum bitEnumClear(sched_barrier_opt_enum bits, sched_barrier_opt_enum bit) {
  return bits & ~bit;
}
inline constexpr sched_barrier_opt_enum bitEnumSet(sched_barrier_opt_enum bits, sched_barrier_opt_enum bit, /*optional*/bool value=true) {
  return value ? (bits | bit) : bitEnumClear(bits, bit);
}
  
inline std::string stringifyEnum(sched_barrier_opt_enum enumValue) {
  return stringifysched_barrier_opt_enum(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<sched_barrier_opt_enum> symbolizeEnum<sched_barrier_opt_enum>(::llvm::StringRef str) {
  return symbolizesched_barrier_opt_enum(str);
}
} // namespace amdgpu
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::amdgpu::sched_barrier_opt_enum, ::mlir::amdgpu::sched_barrier_opt_enum> {
  template <typename ParserT>
  static FailureOr<::mlir::amdgpu::sched_barrier_opt_enum> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for The possible options for scheduling barriers");

    // Symbolize the keyword.
    if (::std::optional<::mlir::amdgpu::sched_barrier_opt_enum> attr = ::mlir::amdgpu::symbolizeEnum<::mlir::amdgpu::sched_barrier_opt_enum>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid The possible options for scheduling barriers specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::amdgpu::sched_barrier_opt_enum>, std::optional<::mlir::amdgpu::sched_barrier_opt_enum>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::amdgpu::sched_barrier_opt_enum>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::amdgpu::sched_barrier_opt_enum>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::amdgpu::sched_barrier_opt_enum> attr = ::mlir::amdgpu::symbolizeEnum<::mlir::amdgpu::sched_barrier_opt_enum>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid The possible options for scheduling barriers specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::amdgpu::sched_barrier_opt_enum value) {
  auto valueStr = stringifyEnum(value);
  auto underlyingValue = static_cast<std::make_unsigned_t<::mlir::amdgpu::sched_barrier_opt_enum>>(value);
  if (underlyingValue && !llvm::has_single_bit(underlyingValue))
    return p << '"' << valueStr << '"';
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::amdgpu::sched_barrier_opt_enum> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::amdgpu::sched_barrier_opt_enum getEmptyKey() {
    return static_cast<::mlir::amdgpu::sched_barrier_opt_enum>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::amdgpu::sched_barrier_opt_enum getTombstoneKey() {
    return static_cast<::mlir::amdgpu::sched_barrier_opt_enum>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::amdgpu::sched_barrier_opt_enum &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::amdgpu::sched_barrier_opt_enum &lhs, const ::mlir::amdgpu::sched_barrier_opt_enum &rhs) {
    return lhs == rhs;
  }
};
}

