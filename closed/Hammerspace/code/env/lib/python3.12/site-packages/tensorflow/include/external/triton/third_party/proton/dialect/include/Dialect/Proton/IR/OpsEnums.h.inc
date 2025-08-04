/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ProtonOps.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace triton {
namespace proton {
// allowed 32-bit signless integer cases: 0, 1
enum class Granularity : uint32_t {
  WARPGROUP = 0,
  WARP = 1,
};

::std::optional<Granularity> symbolizeGranularity(uint32_t);
::llvm::StringRef stringifyGranularity(Granularity);
::std::optional<Granularity> symbolizeGranularity(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForGranularity() {
  return 1;
}


inline ::llvm::StringRef stringifyEnum(Granularity enumValue) {
  return stringifyGranularity(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<Granularity> symbolizeEnum<Granularity>(::llvm::StringRef str) {
  return symbolizeGranularity(str);
}

class GranularityAttr : public ::mlir::IntegerAttr {
public:
  using ValueType = Granularity;
  using ::mlir::IntegerAttr::IntegerAttr;
  static bool classof(::mlir::Attribute attr);
  static GranularityAttr get(::mlir::MLIRContext *context, Granularity val);
  Granularity getValue() const;
};
} // namespace proton
} // namespace triton
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::triton::proton::Granularity, ::mlir::triton::proton::Granularity> {
  template <typename ParserT>
  static FailureOr<::mlir::triton::proton::Granularity> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for allowed 32-bit signless integer cases: 0, 1");

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::proton::Granularity> attr = ::mlir::triton::proton::symbolizeEnum<::mlir::triton::proton::Granularity>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 0, 1 specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::triton::proton::Granularity>, std::optional<::mlir::triton::proton::Granularity>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::triton::proton::Granularity>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::triton::proton::Granularity>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::proton::Granularity> attr = ::mlir::triton::proton::symbolizeEnum<::mlir::triton::proton::Granularity>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 0, 1 specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::triton::proton::Granularity value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::triton::proton::Granularity> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::triton::proton::Granularity getEmptyKey() {
    return static_cast<::mlir::triton::proton::Granularity>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::triton::proton::Granularity getTombstoneKey() {
    return static_cast<::mlir::triton::proton::Granularity>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::triton::proton::Granularity &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::triton::proton::Granularity &lhs, const ::mlir::triton::proton::Granularity &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace triton {
namespace proton {
// allowed 32-bit signless integer cases: 0
enum class Metric : uint32_t {
  CYCLE = 0,
};

::std::optional<Metric> symbolizeMetric(uint32_t);
::llvm::StringRef stringifyMetric(Metric);
::std::optional<Metric> symbolizeMetric(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMetric() {
  return 0;
}


inline ::llvm::StringRef stringifyEnum(Metric enumValue) {
  return stringifyMetric(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<Metric> symbolizeEnum<Metric>(::llvm::StringRef str) {
  return symbolizeMetric(str);
}

class MetricAttr : public ::mlir::IntegerAttr {
public:
  using ValueType = Metric;
  using ::mlir::IntegerAttr::IntegerAttr;
  static bool classof(::mlir::Attribute attr);
  static MetricAttr get(::mlir::MLIRContext *context, Metric val);
  Metric getValue() const;
};
} // namespace proton
} // namespace triton
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::triton::proton::Metric, ::mlir::triton::proton::Metric> {
  template <typename ParserT>
  static FailureOr<::mlir::triton::proton::Metric> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for allowed 32-bit signless integer cases: 0");

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::proton::Metric> attr = ::mlir::triton::proton::symbolizeEnum<::mlir::triton::proton::Metric>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 0 specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::triton::proton::Metric>, std::optional<::mlir::triton::proton::Metric>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::triton::proton::Metric>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::triton::proton::Metric>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::triton::proton::Metric> attr = ::mlir::triton::proton::symbolizeEnum<::mlir::triton::proton::Metric>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid allowed 32-bit signless integer cases: 0 specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::triton::proton::Metric value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::triton::proton::Metric> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::triton::proton::Metric getEmptyKey() {
    return static_cast<::mlir::triton::proton::Metric>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::triton::proton::Metric getTombstoneKey() {
    return static_cast<::mlir::triton::proton::Metric>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::triton::proton::Metric &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::triton::proton::Metric &lhs, const ::mlir::triton::proton::Metric &rhs) {
    return lhs == rhs;
  }
};
}

