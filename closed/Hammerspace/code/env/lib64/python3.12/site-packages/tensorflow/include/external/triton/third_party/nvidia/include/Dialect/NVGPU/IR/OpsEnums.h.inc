/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: NVGPUOps.td                                                          *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
namespace nvgpu {
// allowed 32-bit signless integer cases: 1, 2, 3, 4
enum class MemSemantic : uint32_t {
  RELAXED = 1,
  ACQUIRE = 2,
  RELEASE = 3,
  ACQUIRE_RELEASE = 4,
};

::std::optional<MemSemantic> symbolizeMemSemantic(uint32_t);
::llvm::StringRef stringifyMemSemantic(MemSemantic);
::std::optional<MemSemantic> symbolizeMemSemantic(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMemSemantic() {
  return 4;
}


inline ::llvm::StringRef stringifyEnum(MemSemantic enumValue) {
  return stringifyMemSemantic(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<MemSemantic> symbolizeEnum<MemSemantic>(::llvm::StringRef str) {
  return symbolizeMemSemantic(str);
}

class MemSemanticAttr : public ::mlir::IntegerAttr {
public:
  using ValueType = MemSemantic;
  using ::mlir::IntegerAttr::IntegerAttr;
  static bool classof(::mlir::Attribute attr);
  static MemSemanticAttr get(::mlir::MLIRContext *context, MemSemantic val);
  MemSemantic getValue() const;
};
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::triton::nvgpu::MemSemantic, ::mlir::triton::nvgpu::MemSemantic> {
  template <typename ParserT>
  static FailureOr<::mlir::triton::nvgpu::MemSemantic> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for allowed 32-bit signless integer cases: 1, 2, 3, 4");

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::MemSemantic> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::MemSemantic>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 1, 2, 3, 4 specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::triton::nvgpu::MemSemantic>, std::optional<::mlir::triton::nvgpu::MemSemantic>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::triton::nvgpu::MemSemantic>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::triton::nvgpu::MemSemantic>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::MemSemantic> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::MemSemantic>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 1, 2, 3, 4 specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::triton::nvgpu::MemSemantic value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::triton::nvgpu::MemSemantic> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::triton::nvgpu::MemSemantic getEmptyKey() {
    return static_cast<::mlir::triton::nvgpu::MemSemantic>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::triton::nvgpu::MemSemantic getTombstoneKey() {
    return static_cast<::mlir::triton::nvgpu::MemSemantic>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::triton::nvgpu::MemSemantic &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::triton::nvgpu::MemSemantic &lhs, const ::mlir::triton::nvgpu::MemSemantic &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace triton {
namespace nvgpu {
// allowed 32-bit signless integer cases: 1, 2, 3
enum class MemSyncScope : uint32_t {
  GPU = 1,
  CTA = 2,
  SYSTEM = 3,
};

::std::optional<MemSyncScope> symbolizeMemSyncScope(uint32_t);
::llvm::StringRef stringifyMemSyncScope(MemSyncScope);
::std::optional<MemSyncScope> symbolizeMemSyncScope(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMemSyncScope() {
  return 3;
}


inline ::llvm::StringRef stringifyEnum(MemSyncScope enumValue) {
  return stringifyMemSyncScope(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<MemSyncScope> symbolizeEnum<MemSyncScope>(::llvm::StringRef str) {
  return symbolizeMemSyncScope(str);
}

class MemSyncScopeAttr : public ::mlir::IntegerAttr {
public:
  using ValueType = MemSyncScope;
  using ::mlir::IntegerAttr::IntegerAttr;
  static bool classof(::mlir::Attribute attr);
  static MemSyncScopeAttr get(::mlir::MLIRContext *context, MemSyncScope val);
  MemSyncScope getValue() const;
};
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::triton::nvgpu::MemSyncScope, ::mlir::triton::nvgpu::MemSyncScope> {
  template <typename ParserT>
  static FailureOr<::mlir::triton::nvgpu::MemSyncScope> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for allowed 32-bit signless integer cases: 1, 2, 3");

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::MemSyncScope> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::MemSyncScope>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 1, 2, 3 specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::triton::nvgpu::MemSyncScope>, std::optional<::mlir::triton::nvgpu::MemSyncScope>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::triton::nvgpu::MemSyncScope>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::triton::nvgpu::MemSyncScope>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::MemSyncScope> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::MemSyncScope>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 1, 2, 3 specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::triton::nvgpu::MemSyncScope value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::triton::nvgpu::MemSyncScope> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::triton::nvgpu::MemSyncScope getEmptyKey() {
    return static_cast<::mlir::triton::nvgpu::MemSyncScope>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::triton::nvgpu::MemSyncScope getTombstoneKey() {
    return static_cast<::mlir::triton::nvgpu::MemSyncScope>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::triton::nvgpu::MemSyncScope &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::triton::nvgpu::MemSyncScope &lhs, const ::mlir::triton::nvgpu::MemSyncScope &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace triton {
namespace nvgpu {
// wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'
enum class WGMMAEltType : uint32_t {
  s8 = 0,
  s32 = 1,
  e4m3 = 2,
  e5m2 = 3,
  f16 = 4,
  bf16 = 5,
  tf32 = 6,
  f32 = 7,
};

::std::optional<WGMMAEltType> symbolizeWGMMAEltType(uint32_t);
::llvm::StringRef stringifyWGMMAEltType(WGMMAEltType);
::std::optional<WGMMAEltType> symbolizeWGMMAEltType(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForWGMMAEltType() {
  return 7;
}


inline ::llvm::StringRef stringifyEnum(WGMMAEltType enumValue) {
  return stringifyWGMMAEltType(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<WGMMAEltType> symbolizeEnum<WGMMAEltType>(::llvm::StringRef str) {
  return symbolizeWGMMAEltType(str);
}

class WGMMAEltTypeAttr : public ::mlir::IntegerAttr {
public:
  using ValueType = WGMMAEltType;
  using ::mlir::IntegerAttr::IntegerAttr;
  static bool classof(::mlir::Attribute attr);
  static WGMMAEltTypeAttr get(::mlir::MLIRContext *context, WGMMAEltType val);
  WGMMAEltType getValue() const;
};
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::triton::nvgpu::WGMMAEltType, ::mlir::triton::nvgpu::WGMMAEltType> {
  template <typename ParserT>
  static FailureOr<::mlir::triton::nvgpu::WGMMAEltType> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32'");

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::WGMMAEltType> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::WGMMAEltType>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32' specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::triton::nvgpu::WGMMAEltType>, std::optional<::mlir::triton::nvgpu::WGMMAEltType>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::triton::nvgpu::WGMMAEltType>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::triton::nvgpu::WGMMAEltType>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::WGMMAEltType> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::WGMMAEltType>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid wgmma operand type, either 's8', 's32', 'e4m3', 'e5m2', 'f16', 'bf16', 'tf32', or 'f32' specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::triton::nvgpu::WGMMAEltType value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::triton::nvgpu::WGMMAEltType> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::triton::nvgpu::WGMMAEltType getEmptyKey() {
    return static_cast<::mlir::triton::nvgpu::WGMMAEltType>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::triton::nvgpu::WGMMAEltType getTombstoneKey() {
    return static_cast<::mlir::triton::nvgpu::WGMMAEltType>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::triton::nvgpu::WGMMAEltType &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::triton::nvgpu::WGMMAEltType &lhs, const ::mlir::triton::nvgpu::WGMMAEltType &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace triton {
namespace nvgpu {
// wgmma layout, either 'row' or 'col'
enum class WGMMALayout : uint32_t {
  row = 0,
  col = 1,
};

::std::optional<WGMMALayout> symbolizeWGMMALayout(uint32_t);
::llvm::StringRef stringifyWGMMALayout(WGMMALayout);
::std::optional<WGMMALayout> symbolizeWGMMALayout(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForWGMMALayout() {
  return 1;
}


inline ::llvm::StringRef stringifyEnum(WGMMALayout enumValue) {
  return stringifyWGMMALayout(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<WGMMALayout> symbolizeEnum<WGMMALayout>(::llvm::StringRef str) {
  return symbolizeWGMMALayout(str);
}

class WGMMALayoutAttr : public ::mlir::IntegerAttr {
public:
  using ValueType = WGMMALayout;
  using ::mlir::IntegerAttr::IntegerAttr;
  static bool classof(::mlir::Attribute attr);
  static WGMMALayoutAttr get(::mlir::MLIRContext *context, WGMMALayout val);
  WGMMALayout getValue() const;
};
} // namespace nvgpu
} // namespace triton
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::triton::nvgpu::WGMMALayout, ::mlir::triton::nvgpu::WGMMALayout> {
  template <typename ParserT>
  static FailureOr<::mlir::triton::nvgpu::WGMMALayout> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for wgmma layout, either 'row' or 'col'");

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::WGMMALayout> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::WGMMALayout>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid wgmma layout, either 'row' or 'col' specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::triton::nvgpu::WGMMALayout>, std::optional<::mlir::triton::nvgpu::WGMMALayout>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::triton::nvgpu::WGMMALayout>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::triton::nvgpu::WGMMALayout>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::nvgpu::WGMMALayout> attr = ::mlir::triton::nvgpu::symbolizeEnum<::mlir::triton::nvgpu::WGMMALayout>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid wgmma layout, either 'row' or 'col' specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::triton::nvgpu::WGMMALayout value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::triton::nvgpu::WGMMALayout> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::triton::nvgpu::WGMMALayout getEmptyKey() {
    return static_cast<::mlir::triton::nvgpu::WGMMALayout>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::triton::nvgpu::WGMMALayout getTombstoneKey() {
    return static_cast<::mlir::triton::nvgpu::WGMMALayout>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::triton::nvgpu::WGMMALayout &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::triton::nvgpu::WGMMALayout &lhs, const ::mlir::triton::nvgpu::WGMMALayout &rhs) {
    return lhs == rhs;
  }
};
}

