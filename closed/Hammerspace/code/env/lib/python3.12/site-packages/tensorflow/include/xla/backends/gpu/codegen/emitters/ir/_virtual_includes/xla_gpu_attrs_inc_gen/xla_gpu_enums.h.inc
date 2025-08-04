/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: xla_gpu_attrs.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace xla {
namespace gpu {
// element-wise op type
enum class MemorySpace : uint32_t {
  kRegisters = 0,
  kSharedMemory = 1,
};

::std::optional<MemorySpace> symbolizeMemorySpace(uint32_t);
::llvm::StringRef stringifyMemorySpace(MemorySpace);
::std::optional<MemorySpace> symbolizeMemorySpace(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMemorySpace() {
  return 1;
}


inline ::llvm::StringRef stringifyEnum(MemorySpace enumValue) {
  return stringifyMemorySpace(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<MemorySpace> symbolizeEnum<MemorySpace>(::llvm::StringRef str) {
  return symbolizeMemorySpace(str);
}
} // namespace gpu
} // namespace xla

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::xla::gpu::MemorySpace, ::xla::gpu::MemorySpace> {
  template <typename ParserT>
  static FailureOr<::xla::gpu::MemorySpace> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for element-wise op type");

    // Symbolize the keyword.
    if (::std::optional<::xla::gpu::MemorySpace> attr = ::xla::gpu::symbolizeEnum<::xla::gpu::MemorySpace>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid element-wise op type specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::xla::gpu::MemorySpace>, std::optional<::xla::gpu::MemorySpace>> {
  template <typename ParserT>
  static FailureOr<std::optional<::xla::gpu::MemorySpace>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::xla::gpu::MemorySpace>{};

    // Symbolize the keyword.
    if (::std::optional<::xla::gpu::MemorySpace> attr = ::xla::gpu::symbolizeEnum<::xla::gpu::MemorySpace>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid element-wise op type specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::xla::gpu::MemorySpace value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::xla::gpu::MemorySpace> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::xla::gpu::MemorySpace getEmptyKey() {
    return static_cast<::xla::gpu::MemorySpace>(StorageInfo::getEmptyKey());
  }

  static inline ::xla::gpu::MemorySpace getTombstoneKey() {
    return static_cast<::xla::gpu::MemorySpace>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::xla::gpu::MemorySpace &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::xla::gpu::MemorySpace &lhs, const ::xla::gpu::MemorySpace &rhs) {
    return lhs == rhs;
  }
};
}

