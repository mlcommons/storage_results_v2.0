/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MPI.td                                                               *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace mpi {
// MPI error class name
enum class MPI_ErrorClassEnum : uint32_t {
  MPI_SUCCESS = 0,
  MPI_ERR_ACCESS = 1,
  MPI_ERR_AMODE = 2,
  MPI_ERR_ARG = 3,
  MPI_ERR_ASSERT = 4,
  MPI_ERR_BAD_FILE = 5,
  MPI_ERR_BASE = 6,
  MPI_ERR_BUFFER = 7,
  MPI_ERR_COMM = 8,
  MPI_ERR_CONVERSION = 9,
  MPI_ERR_COUNT = 10,
  MPI_ERR_DIMS = 11,
  MPI_ERR_DISP = 12,
  MPI_ERR_DUP_DATAREP = 13,
  MPI_ERR_ERRHANDLER = 14,
  MPI_ERR_FILE = 15,
  MPI_ERR_FILE_EXISTS = 16,
  MPI_ERR_FILE_IN_USE = 17,
  MPI_ERR_GROUP = 18,
  MPI_ERR_INFO = 19,
  MPI_ERR_INFO_KEY = 20,
  MPI_ERR_INFO_NOKEY = 21,
  MPI_ERR_INFO_VALUE = 22,
  MPI_ERR_IN_STATUS = 23,
  MPI_ERR_INTERN = 24,
  MPI_ERR_IO = 25,
  MPI_ERR_KEYVAL = 26,
  MPI_ERR_LOCKTYPE = 27,
  MPI_ERR_NAME = 28,
  MPI_ERR_NO_MEM = 29,
  MPI_ERR_NO_SPACE = 30,
  MPI_ERR_NO_SUCH_FILE = 31,
  MPI_ERR_NOT_SAME = 32,
  MPI_ERR_OP = 33,
  MPI_ERR_OTHER = 34,
  MPI_ERR_PENDING = 35,
  MPI_ERR_PORT = 36,
  MPI_ERR_PROC_ABORTED = 37,
  MPI_ERR_QUOTA = 38,
  MPI_ERR_RANK = 39,
  MPI_ERR_READ_ONLY = 40,
  MPI_ERR_REQUEST = 41,
  MPI_ERR_RMA_ATTACH = 42,
  MPI_ERR_RMA_CONFLICT = 43,
  MPI_ERR_RMA_FLAVOR = 44,
  MPI_ERR_RMA_RANGE = 45,
  MPI_ERR_RMA_SHARED = 46,
  MPI_ERR_RMA_SYNC = 47,
  MPI_ERR_ROOT = 48,
  MPI_ERR_SERVICE = 49,
  MPI_ERR_SESSION = 50,
  MPI_ERR_SIZE = 51,
  MPI_ERR_SPAWN = 52,
  MPI_ERR_TAG = 53,
  MPI_ERR_TOPOLOGY = 54,
  MPI_ERR_TRUNCATE = 55,
  MPI_ERR_TYPE = 56,
  MPI_ERR_UNKNOWN = 57,
  MPI_ERR_UNSUPPORTED_DATAREP = 58,
  MPI_ERR_UNSUPPORTED_OPERATION = 59,
  MPI_ERR_VALUE_TOO_LARGE = 60,
  MPI_ERR_WIN = 61,
  MPI_ERR_LASTCODE = 62,
};

::std::optional<MPI_ErrorClassEnum> symbolizeMPI_ErrorClassEnum(uint32_t);
::llvm::StringRef stringifyMPI_ErrorClassEnum(MPI_ErrorClassEnum);
::std::optional<MPI_ErrorClassEnum> symbolizeMPI_ErrorClassEnum(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMPI_ErrorClassEnum() {
  return 62;
}


inline ::llvm::StringRef stringifyEnum(MPI_ErrorClassEnum enumValue) {
  return stringifyMPI_ErrorClassEnum(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<MPI_ErrorClassEnum> symbolizeEnum<MPI_ErrorClassEnum>(::llvm::StringRef str) {
  return symbolizeMPI_ErrorClassEnum(str);
}
} // namespace mpi
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::mpi::MPI_ErrorClassEnum, ::mlir::mpi::MPI_ErrorClassEnum> {
  template <typename ParserT>
  static FailureOr<::mlir::mpi::MPI_ErrorClassEnum> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for MPI error class name");

    // Symbolize the keyword.
    if (::std::optional<::mlir::mpi::MPI_ErrorClassEnum> attr = ::mlir::mpi::symbolizeEnum<::mlir::mpi::MPI_ErrorClassEnum>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid MPI error class name specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::mpi::MPI_ErrorClassEnum>, std::optional<::mlir::mpi::MPI_ErrorClassEnum>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::mpi::MPI_ErrorClassEnum>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::mpi::MPI_ErrorClassEnum>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::mpi::MPI_ErrorClassEnum> attr = ::mlir::mpi::symbolizeEnum<::mlir::mpi::MPI_ErrorClassEnum>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid MPI error class name specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::mpi::MPI_ErrorClassEnum value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::mpi::MPI_ErrorClassEnum> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::mpi::MPI_ErrorClassEnum getEmptyKey() {
    return static_cast<::mlir::mpi::MPI_ErrorClassEnum>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::mpi::MPI_ErrorClassEnum getTombstoneKey() {
    return static_cast<::mlir::mpi::MPI_ErrorClassEnum>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::mpi::MPI_ErrorClassEnum &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::mpi::MPI_ErrorClassEnum &lhs, const ::mlir::mpi::MPI_ErrorClassEnum &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace mpi {
// MPI operation class
enum class MPI_OpClassEnum : uint32_t {
  MPI_OP_NULL = 0,
  MPI_MAX = 1,
  MPI_MIN = 2,
  MPI_SUM = 3,
  MPI_PROD = 4,
  MPI_LAND = 5,
  MPI_BAND = 6,
  MPI_LOR = 7,
  MPI_BOR = 8,
  MPI_LXOR = 9,
  MPI_BXOR = 10,
  MPI_MINLOC = 11,
  MPI_MAXLOC = 12,
  MPI_REPLACE = 13,
};

::std::optional<MPI_OpClassEnum> symbolizeMPI_OpClassEnum(uint32_t);
::llvm::StringRef stringifyMPI_OpClassEnum(MPI_OpClassEnum);
::std::optional<MPI_OpClassEnum> symbolizeMPI_OpClassEnum(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForMPI_OpClassEnum() {
  return 13;
}


inline ::llvm::StringRef stringifyEnum(MPI_OpClassEnum enumValue) {
  return stringifyMPI_OpClassEnum(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<MPI_OpClassEnum> symbolizeEnum<MPI_OpClassEnum>(::llvm::StringRef str) {
  return symbolizeMPI_OpClassEnum(str);
}
} // namespace mpi
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::mpi::MPI_OpClassEnum, ::mlir::mpi::MPI_OpClassEnum> {
  template <typename ParserT>
  static FailureOr<::mlir::mpi::MPI_OpClassEnum> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for MPI operation class");

    // Symbolize the keyword.
    if (::std::optional<::mlir::mpi::MPI_OpClassEnum> attr = ::mlir::mpi::symbolizeEnum<::mlir::mpi::MPI_OpClassEnum>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid MPI operation class specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::mpi::MPI_OpClassEnum>, std::optional<::mlir::mpi::MPI_OpClassEnum>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::mpi::MPI_OpClassEnum>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::mpi::MPI_OpClassEnum>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::mpi::MPI_OpClassEnum> attr = ::mlir::mpi::symbolizeEnum<::mlir::mpi::MPI_OpClassEnum>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid MPI operation class specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::mpi::MPI_OpClassEnum value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::mpi::MPI_OpClassEnum> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::mpi::MPI_OpClassEnum getEmptyKey() {
    return static_cast<::mlir::mpi::MPI_OpClassEnum>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::mpi::MPI_OpClassEnum getTombstoneKey() {
    return static_cast<::mlir::mpi::MPI_OpClassEnum>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::mpi::MPI_OpClassEnum &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::mpi::MPI_OpClassEnum &lhs, const ::mlir::mpi::MPI_OpClassEnum &rhs) {
    return lhs == rhs;
  }
};
}

