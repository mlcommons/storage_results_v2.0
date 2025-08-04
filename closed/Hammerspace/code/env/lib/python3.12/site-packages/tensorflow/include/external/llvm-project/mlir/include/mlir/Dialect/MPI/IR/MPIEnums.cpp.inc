/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Definitions                                                   *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MPI.td                                                               *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace mpi {
::llvm::StringRef stringifyMPI_ErrorClassEnum(MPI_ErrorClassEnum val) {
  switch (val) {
    case MPI_ErrorClassEnum::MPI_SUCCESS: return "MPI_SUCCESS";
    case MPI_ErrorClassEnum::MPI_ERR_ACCESS: return "MPI_ERR_ACCESS";
    case MPI_ErrorClassEnum::MPI_ERR_AMODE: return "MPI_ERR_AMODE";
    case MPI_ErrorClassEnum::MPI_ERR_ARG: return "MPI_ERR_ARG";
    case MPI_ErrorClassEnum::MPI_ERR_ASSERT: return "MPI_ERR_ASSERT";
    case MPI_ErrorClassEnum::MPI_ERR_BAD_FILE: return "MPI_ERR_BAD_FILE";
    case MPI_ErrorClassEnum::MPI_ERR_BASE: return "MPI_ERR_BASE";
    case MPI_ErrorClassEnum::MPI_ERR_BUFFER: return "MPI_ERR_BUFFER";
    case MPI_ErrorClassEnum::MPI_ERR_COMM: return "MPI_ERR_COMM";
    case MPI_ErrorClassEnum::MPI_ERR_CONVERSION: return "MPI_ERR_CONVERSION";
    case MPI_ErrorClassEnum::MPI_ERR_COUNT: return "MPI_ERR_COUNT";
    case MPI_ErrorClassEnum::MPI_ERR_DIMS: return "MPI_ERR_DIMS";
    case MPI_ErrorClassEnum::MPI_ERR_DISP: return "MPI_ERR_DISP";
    case MPI_ErrorClassEnum::MPI_ERR_DUP_DATAREP: return "MPI_ERR_DUP_DATAREP";
    case MPI_ErrorClassEnum::MPI_ERR_ERRHANDLER: return "MPI_ERR_ERRHANDLER";
    case MPI_ErrorClassEnum::MPI_ERR_FILE: return "MPI_ERR_FILE";
    case MPI_ErrorClassEnum::MPI_ERR_FILE_EXISTS: return "MPI_ERR_FILE_EXISTS";
    case MPI_ErrorClassEnum::MPI_ERR_FILE_IN_USE: return "MPI_ERR_FILE_IN_USE";
    case MPI_ErrorClassEnum::MPI_ERR_GROUP: return "MPI_ERR_GROUP";
    case MPI_ErrorClassEnum::MPI_ERR_INFO: return "MPI_ERR_INFO";
    case MPI_ErrorClassEnum::MPI_ERR_INFO_KEY: return "MPI_ERR_INFO_KEY";
    case MPI_ErrorClassEnum::MPI_ERR_INFO_NOKEY: return "MPI_ERR_INFO_NOKEY";
    case MPI_ErrorClassEnum::MPI_ERR_INFO_VALUE: return "MPI_ERR_INFO_VALUE";
    case MPI_ErrorClassEnum::MPI_ERR_IN_STATUS: return "MPI_ERR_IN_STATUS";
    case MPI_ErrorClassEnum::MPI_ERR_INTERN: return "MPI_ERR_INTERN";
    case MPI_ErrorClassEnum::MPI_ERR_IO: return "MPI_ERR_IO";
    case MPI_ErrorClassEnum::MPI_ERR_KEYVAL: return "MPI_ERR_KEYVAL";
    case MPI_ErrorClassEnum::MPI_ERR_LOCKTYPE: return "MPI_ERR_LOCKTYPE";
    case MPI_ErrorClassEnum::MPI_ERR_NAME: return "MPI_ERR_NAME";
    case MPI_ErrorClassEnum::MPI_ERR_NO_MEM: return "MPI_ERR_NO_MEM";
    case MPI_ErrorClassEnum::MPI_ERR_NO_SPACE: return "MPI_ERR_NO_SPACE";
    case MPI_ErrorClassEnum::MPI_ERR_NO_SUCH_FILE: return "MPI_ERR_NO_SUCH_FILE";
    case MPI_ErrorClassEnum::MPI_ERR_NOT_SAME: return "MPI_ERR_NOT_SAME";
    case MPI_ErrorClassEnum::MPI_ERR_OP: return "MPI_ERR_OP";
    case MPI_ErrorClassEnum::MPI_ERR_OTHER: return "MPI_ERR_OTHER";
    case MPI_ErrorClassEnum::MPI_ERR_PENDING: return "MPI_ERR_PENDING";
    case MPI_ErrorClassEnum::MPI_ERR_PORT: return "MPI_ERR_PORT";
    case MPI_ErrorClassEnum::MPI_ERR_PROC_ABORTED: return "MPI_ERR_PROC_ABORTED";
    case MPI_ErrorClassEnum::MPI_ERR_QUOTA: return "MPI_ERR_QUOTA";
    case MPI_ErrorClassEnum::MPI_ERR_RANK: return "MPI_ERR_RANK";
    case MPI_ErrorClassEnum::MPI_ERR_READ_ONLY: return "MPI_ERR_READ_ONLY";
    case MPI_ErrorClassEnum::MPI_ERR_REQUEST: return "MPI_ERR_REQUEST";
    case MPI_ErrorClassEnum::MPI_ERR_RMA_ATTACH: return "MPI_ERR_RMA_ATTACH";
    case MPI_ErrorClassEnum::MPI_ERR_RMA_CONFLICT: return "MPI_ERR_RMA_CONFLICT";
    case MPI_ErrorClassEnum::MPI_ERR_RMA_FLAVOR: return "MPI_ERR_RMA_FLAVOR";
    case MPI_ErrorClassEnum::MPI_ERR_RMA_RANGE: return "MPI_ERR_RMA_RANGE";
    case MPI_ErrorClassEnum::MPI_ERR_RMA_SHARED: return "MPI_ERR_RMA_SHARED";
    case MPI_ErrorClassEnum::MPI_ERR_RMA_SYNC: return "MPI_ERR_RMA_SYNC";
    case MPI_ErrorClassEnum::MPI_ERR_ROOT: return "MPI_ERR_ROOT";
    case MPI_ErrorClassEnum::MPI_ERR_SERVICE: return "MPI_ERR_SERVICE";
    case MPI_ErrorClassEnum::MPI_ERR_SESSION: return "MPI_ERR_SESSION";
    case MPI_ErrorClassEnum::MPI_ERR_SIZE: return "MPI_ERR_SIZE";
    case MPI_ErrorClassEnum::MPI_ERR_SPAWN: return "MPI_ERR_SPAWN";
    case MPI_ErrorClassEnum::MPI_ERR_TAG: return "MPI_ERR_TAG";
    case MPI_ErrorClassEnum::MPI_ERR_TOPOLOGY: return "MPI_ERR_TOPOLOGY";
    case MPI_ErrorClassEnum::MPI_ERR_TRUNCATE: return "MPI_ERR_TRUNCATE";
    case MPI_ErrorClassEnum::MPI_ERR_TYPE: return "MPI_ERR_TYPE";
    case MPI_ErrorClassEnum::MPI_ERR_UNKNOWN: return "MPI_ERR_UNKNOWN";
    case MPI_ErrorClassEnum::MPI_ERR_UNSUPPORTED_DATAREP: return "MPI_ERR_UNSUPPORTED_DATAREP";
    case MPI_ErrorClassEnum::MPI_ERR_UNSUPPORTED_OPERATION: return "MPI_ERR_UNSUPPORTED_OPERATION";
    case MPI_ErrorClassEnum::MPI_ERR_VALUE_TOO_LARGE: return "MPI_ERR_VALUE_TOO_LARGE";
    case MPI_ErrorClassEnum::MPI_ERR_WIN: return "MPI_ERR_WIN";
    case MPI_ErrorClassEnum::MPI_ERR_LASTCODE: return "MPI_ERR_LASTCODE";
  }
  return "";
}

::std::optional<MPI_ErrorClassEnum> symbolizeMPI_ErrorClassEnum(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<MPI_ErrorClassEnum>>(str)
      .Case("MPI_SUCCESS", MPI_ErrorClassEnum::MPI_SUCCESS)
      .Case("MPI_ERR_ACCESS", MPI_ErrorClassEnum::MPI_ERR_ACCESS)
      .Case("MPI_ERR_AMODE", MPI_ErrorClassEnum::MPI_ERR_AMODE)
      .Case("MPI_ERR_ARG", MPI_ErrorClassEnum::MPI_ERR_ARG)
      .Case("MPI_ERR_ASSERT", MPI_ErrorClassEnum::MPI_ERR_ASSERT)
      .Case("MPI_ERR_BAD_FILE", MPI_ErrorClassEnum::MPI_ERR_BAD_FILE)
      .Case("MPI_ERR_BASE", MPI_ErrorClassEnum::MPI_ERR_BASE)
      .Case("MPI_ERR_BUFFER", MPI_ErrorClassEnum::MPI_ERR_BUFFER)
      .Case("MPI_ERR_COMM", MPI_ErrorClassEnum::MPI_ERR_COMM)
      .Case("MPI_ERR_CONVERSION", MPI_ErrorClassEnum::MPI_ERR_CONVERSION)
      .Case("MPI_ERR_COUNT", MPI_ErrorClassEnum::MPI_ERR_COUNT)
      .Case("MPI_ERR_DIMS", MPI_ErrorClassEnum::MPI_ERR_DIMS)
      .Case("MPI_ERR_DISP", MPI_ErrorClassEnum::MPI_ERR_DISP)
      .Case("MPI_ERR_DUP_DATAREP", MPI_ErrorClassEnum::MPI_ERR_DUP_DATAREP)
      .Case("MPI_ERR_ERRHANDLER", MPI_ErrorClassEnum::MPI_ERR_ERRHANDLER)
      .Case("MPI_ERR_FILE", MPI_ErrorClassEnum::MPI_ERR_FILE)
      .Case("MPI_ERR_FILE_EXISTS", MPI_ErrorClassEnum::MPI_ERR_FILE_EXISTS)
      .Case("MPI_ERR_FILE_IN_USE", MPI_ErrorClassEnum::MPI_ERR_FILE_IN_USE)
      .Case("MPI_ERR_GROUP", MPI_ErrorClassEnum::MPI_ERR_GROUP)
      .Case("MPI_ERR_INFO", MPI_ErrorClassEnum::MPI_ERR_INFO)
      .Case("MPI_ERR_INFO_KEY", MPI_ErrorClassEnum::MPI_ERR_INFO_KEY)
      .Case("MPI_ERR_INFO_NOKEY", MPI_ErrorClassEnum::MPI_ERR_INFO_NOKEY)
      .Case("MPI_ERR_INFO_VALUE", MPI_ErrorClassEnum::MPI_ERR_INFO_VALUE)
      .Case("MPI_ERR_IN_STATUS", MPI_ErrorClassEnum::MPI_ERR_IN_STATUS)
      .Case("MPI_ERR_INTERN", MPI_ErrorClassEnum::MPI_ERR_INTERN)
      .Case("MPI_ERR_IO", MPI_ErrorClassEnum::MPI_ERR_IO)
      .Case("MPI_ERR_KEYVAL", MPI_ErrorClassEnum::MPI_ERR_KEYVAL)
      .Case("MPI_ERR_LOCKTYPE", MPI_ErrorClassEnum::MPI_ERR_LOCKTYPE)
      .Case("MPI_ERR_NAME", MPI_ErrorClassEnum::MPI_ERR_NAME)
      .Case("MPI_ERR_NO_MEM", MPI_ErrorClassEnum::MPI_ERR_NO_MEM)
      .Case("MPI_ERR_NO_SPACE", MPI_ErrorClassEnum::MPI_ERR_NO_SPACE)
      .Case("MPI_ERR_NO_SUCH_FILE", MPI_ErrorClassEnum::MPI_ERR_NO_SUCH_FILE)
      .Case("MPI_ERR_NOT_SAME", MPI_ErrorClassEnum::MPI_ERR_NOT_SAME)
      .Case("MPI_ERR_OP", MPI_ErrorClassEnum::MPI_ERR_OP)
      .Case("MPI_ERR_OTHER", MPI_ErrorClassEnum::MPI_ERR_OTHER)
      .Case("MPI_ERR_PENDING", MPI_ErrorClassEnum::MPI_ERR_PENDING)
      .Case("MPI_ERR_PORT", MPI_ErrorClassEnum::MPI_ERR_PORT)
      .Case("MPI_ERR_PROC_ABORTED", MPI_ErrorClassEnum::MPI_ERR_PROC_ABORTED)
      .Case("MPI_ERR_QUOTA", MPI_ErrorClassEnum::MPI_ERR_QUOTA)
      .Case("MPI_ERR_RANK", MPI_ErrorClassEnum::MPI_ERR_RANK)
      .Case("MPI_ERR_READ_ONLY", MPI_ErrorClassEnum::MPI_ERR_READ_ONLY)
      .Case("MPI_ERR_REQUEST", MPI_ErrorClassEnum::MPI_ERR_REQUEST)
      .Case("MPI_ERR_RMA_ATTACH", MPI_ErrorClassEnum::MPI_ERR_RMA_ATTACH)
      .Case("MPI_ERR_RMA_CONFLICT", MPI_ErrorClassEnum::MPI_ERR_RMA_CONFLICT)
      .Case("MPI_ERR_RMA_FLAVOR", MPI_ErrorClassEnum::MPI_ERR_RMA_FLAVOR)
      .Case("MPI_ERR_RMA_RANGE", MPI_ErrorClassEnum::MPI_ERR_RMA_RANGE)
      .Case("MPI_ERR_RMA_SHARED", MPI_ErrorClassEnum::MPI_ERR_RMA_SHARED)
      .Case("MPI_ERR_RMA_SYNC", MPI_ErrorClassEnum::MPI_ERR_RMA_SYNC)
      .Case("MPI_ERR_ROOT", MPI_ErrorClassEnum::MPI_ERR_ROOT)
      .Case("MPI_ERR_SERVICE", MPI_ErrorClassEnum::MPI_ERR_SERVICE)
      .Case("MPI_ERR_SESSION", MPI_ErrorClassEnum::MPI_ERR_SESSION)
      .Case("MPI_ERR_SIZE", MPI_ErrorClassEnum::MPI_ERR_SIZE)
      .Case("MPI_ERR_SPAWN", MPI_ErrorClassEnum::MPI_ERR_SPAWN)
      .Case("MPI_ERR_TAG", MPI_ErrorClassEnum::MPI_ERR_TAG)
      .Case("MPI_ERR_TOPOLOGY", MPI_ErrorClassEnum::MPI_ERR_TOPOLOGY)
      .Case("MPI_ERR_TRUNCATE", MPI_ErrorClassEnum::MPI_ERR_TRUNCATE)
      .Case("MPI_ERR_TYPE", MPI_ErrorClassEnum::MPI_ERR_TYPE)
      .Case("MPI_ERR_UNKNOWN", MPI_ErrorClassEnum::MPI_ERR_UNKNOWN)
      .Case("MPI_ERR_UNSUPPORTED_DATAREP", MPI_ErrorClassEnum::MPI_ERR_UNSUPPORTED_DATAREP)
      .Case("MPI_ERR_UNSUPPORTED_OPERATION", MPI_ErrorClassEnum::MPI_ERR_UNSUPPORTED_OPERATION)
      .Case("MPI_ERR_VALUE_TOO_LARGE", MPI_ErrorClassEnum::MPI_ERR_VALUE_TOO_LARGE)
      .Case("MPI_ERR_WIN", MPI_ErrorClassEnum::MPI_ERR_WIN)
      .Case("MPI_ERR_LASTCODE", MPI_ErrorClassEnum::MPI_ERR_LASTCODE)
      .Default(::std::nullopt);
}
::std::optional<MPI_ErrorClassEnum> symbolizeMPI_ErrorClassEnum(uint32_t value) {
  switch (value) {
  case 0: return MPI_ErrorClassEnum::MPI_SUCCESS;
  case 1: return MPI_ErrorClassEnum::MPI_ERR_ACCESS;
  case 2: return MPI_ErrorClassEnum::MPI_ERR_AMODE;
  case 3: return MPI_ErrorClassEnum::MPI_ERR_ARG;
  case 4: return MPI_ErrorClassEnum::MPI_ERR_ASSERT;
  case 5: return MPI_ErrorClassEnum::MPI_ERR_BAD_FILE;
  case 6: return MPI_ErrorClassEnum::MPI_ERR_BASE;
  case 7: return MPI_ErrorClassEnum::MPI_ERR_BUFFER;
  case 8: return MPI_ErrorClassEnum::MPI_ERR_COMM;
  case 9: return MPI_ErrorClassEnum::MPI_ERR_CONVERSION;
  case 10: return MPI_ErrorClassEnum::MPI_ERR_COUNT;
  case 11: return MPI_ErrorClassEnum::MPI_ERR_DIMS;
  case 12: return MPI_ErrorClassEnum::MPI_ERR_DISP;
  case 13: return MPI_ErrorClassEnum::MPI_ERR_DUP_DATAREP;
  case 14: return MPI_ErrorClassEnum::MPI_ERR_ERRHANDLER;
  case 15: return MPI_ErrorClassEnum::MPI_ERR_FILE;
  case 16: return MPI_ErrorClassEnum::MPI_ERR_FILE_EXISTS;
  case 17: return MPI_ErrorClassEnum::MPI_ERR_FILE_IN_USE;
  case 18: return MPI_ErrorClassEnum::MPI_ERR_GROUP;
  case 19: return MPI_ErrorClassEnum::MPI_ERR_INFO;
  case 20: return MPI_ErrorClassEnum::MPI_ERR_INFO_KEY;
  case 21: return MPI_ErrorClassEnum::MPI_ERR_INFO_NOKEY;
  case 22: return MPI_ErrorClassEnum::MPI_ERR_INFO_VALUE;
  case 23: return MPI_ErrorClassEnum::MPI_ERR_IN_STATUS;
  case 24: return MPI_ErrorClassEnum::MPI_ERR_INTERN;
  case 25: return MPI_ErrorClassEnum::MPI_ERR_IO;
  case 26: return MPI_ErrorClassEnum::MPI_ERR_KEYVAL;
  case 27: return MPI_ErrorClassEnum::MPI_ERR_LOCKTYPE;
  case 28: return MPI_ErrorClassEnum::MPI_ERR_NAME;
  case 29: return MPI_ErrorClassEnum::MPI_ERR_NO_MEM;
  case 30: return MPI_ErrorClassEnum::MPI_ERR_NO_SPACE;
  case 31: return MPI_ErrorClassEnum::MPI_ERR_NO_SUCH_FILE;
  case 32: return MPI_ErrorClassEnum::MPI_ERR_NOT_SAME;
  case 33: return MPI_ErrorClassEnum::MPI_ERR_OP;
  case 34: return MPI_ErrorClassEnum::MPI_ERR_OTHER;
  case 35: return MPI_ErrorClassEnum::MPI_ERR_PENDING;
  case 36: return MPI_ErrorClassEnum::MPI_ERR_PORT;
  case 37: return MPI_ErrorClassEnum::MPI_ERR_PROC_ABORTED;
  case 38: return MPI_ErrorClassEnum::MPI_ERR_QUOTA;
  case 39: return MPI_ErrorClassEnum::MPI_ERR_RANK;
  case 40: return MPI_ErrorClassEnum::MPI_ERR_READ_ONLY;
  case 41: return MPI_ErrorClassEnum::MPI_ERR_REQUEST;
  case 42: return MPI_ErrorClassEnum::MPI_ERR_RMA_ATTACH;
  case 43: return MPI_ErrorClassEnum::MPI_ERR_RMA_CONFLICT;
  case 44: return MPI_ErrorClassEnum::MPI_ERR_RMA_FLAVOR;
  case 45: return MPI_ErrorClassEnum::MPI_ERR_RMA_RANGE;
  case 46: return MPI_ErrorClassEnum::MPI_ERR_RMA_SHARED;
  case 47: return MPI_ErrorClassEnum::MPI_ERR_RMA_SYNC;
  case 48: return MPI_ErrorClassEnum::MPI_ERR_ROOT;
  case 49: return MPI_ErrorClassEnum::MPI_ERR_SERVICE;
  case 50: return MPI_ErrorClassEnum::MPI_ERR_SESSION;
  case 51: return MPI_ErrorClassEnum::MPI_ERR_SIZE;
  case 52: return MPI_ErrorClassEnum::MPI_ERR_SPAWN;
  case 53: return MPI_ErrorClassEnum::MPI_ERR_TAG;
  case 54: return MPI_ErrorClassEnum::MPI_ERR_TOPOLOGY;
  case 55: return MPI_ErrorClassEnum::MPI_ERR_TRUNCATE;
  case 56: return MPI_ErrorClassEnum::MPI_ERR_TYPE;
  case 57: return MPI_ErrorClassEnum::MPI_ERR_UNKNOWN;
  case 58: return MPI_ErrorClassEnum::MPI_ERR_UNSUPPORTED_DATAREP;
  case 59: return MPI_ErrorClassEnum::MPI_ERR_UNSUPPORTED_OPERATION;
  case 60: return MPI_ErrorClassEnum::MPI_ERR_VALUE_TOO_LARGE;
  case 61: return MPI_ErrorClassEnum::MPI_ERR_WIN;
  case 62: return MPI_ErrorClassEnum::MPI_ERR_LASTCODE;
  default: return ::std::nullopt;
  }
}

} // namespace mpi
} // namespace mlir

namespace mlir {
namespace mpi {
::llvm::StringRef stringifyMPI_OpClassEnum(MPI_OpClassEnum val) {
  switch (val) {
    case MPI_OpClassEnum::MPI_OP_NULL: return "MPI_OP_NULL";
    case MPI_OpClassEnum::MPI_MAX: return "MPI_MAX";
    case MPI_OpClassEnum::MPI_MIN: return "MPI_MIN";
    case MPI_OpClassEnum::MPI_SUM: return "MPI_SUM";
    case MPI_OpClassEnum::MPI_PROD: return "MPI_PROD";
    case MPI_OpClassEnum::MPI_LAND: return "MPI_LAND";
    case MPI_OpClassEnum::MPI_BAND: return "MPI_BAND";
    case MPI_OpClassEnum::MPI_LOR: return "MPI_LOR";
    case MPI_OpClassEnum::MPI_BOR: return "MPI_BOR";
    case MPI_OpClassEnum::MPI_LXOR: return "MPI_LXOR";
    case MPI_OpClassEnum::MPI_BXOR: return "MPI_BXOR";
    case MPI_OpClassEnum::MPI_MINLOC: return "MPI_MINLOC";
    case MPI_OpClassEnum::MPI_MAXLOC: return "MPI_MAXLOC";
    case MPI_OpClassEnum::MPI_REPLACE: return "MPI_REPLACE";
  }
  return "";
}

::std::optional<MPI_OpClassEnum> symbolizeMPI_OpClassEnum(::llvm::StringRef str) {
  return ::llvm::StringSwitch<::std::optional<MPI_OpClassEnum>>(str)
      .Case("MPI_OP_NULL", MPI_OpClassEnum::MPI_OP_NULL)
      .Case("MPI_MAX", MPI_OpClassEnum::MPI_MAX)
      .Case("MPI_MIN", MPI_OpClassEnum::MPI_MIN)
      .Case("MPI_SUM", MPI_OpClassEnum::MPI_SUM)
      .Case("MPI_PROD", MPI_OpClassEnum::MPI_PROD)
      .Case("MPI_LAND", MPI_OpClassEnum::MPI_LAND)
      .Case("MPI_BAND", MPI_OpClassEnum::MPI_BAND)
      .Case("MPI_LOR", MPI_OpClassEnum::MPI_LOR)
      .Case("MPI_BOR", MPI_OpClassEnum::MPI_BOR)
      .Case("MPI_LXOR", MPI_OpClassEnum::MPI_LXOR)
      .Case("MPI_BXOR", MPI_OpClassEnum::MPI_BXOR)
      .Case("MPI_MINLOC", MPI_OpClassEnum::MPI_MINLOC)
      .Case("MPI_MAXLOC", MPI_OpClassEnum::MPI_MAXLOC)
      .Case("MPI_REPLACE", MPI_OpClassEnum::MPI_REPLACE)
      .Default(::std::nullopt);
}
::std::optional<MPI_OpClassEnum> symbolizeMPI_OpClassEnum(uint32_t value) {
  switch (value) {
  case 0: return MPI_OpClassEnum::MPI_OP_NULL;
  case 1: return MPI_OpClassEnum::MPI_MAX;
  case 2: return MPI_OpClassEnum::MPI_MIN;
  case 3: return MPI_OpClassEnum::MPI_SUM;
  case 4: return MPI_OpClassEnum::MPI_PROD;
  case 5: return MPI_OpClassEnum::MPI_LAND;
  case 6: return MPI_OpClassEnum::MPI_BAND;
  case 7: return MPI_OpClassEnum::MPI_LOR;
  case 8: return MPI_OpClassEnum::MPI_BOR;
  case 9: return MPI_OpClassEnum::MPI_LXOR;
  case 10: return MPI_OpClassEnum::MPI_BXOR;
  case 11: return MPI_OpClassEnum::MPI_MINLOC;
  case 12: return MPI_OpClassEnum::MPI_MAXLOC;
  case 13: return MPI_OpClassEnum::MPI_REPLACE;
  default: return ::std::nullopt;
  }
}

} // namespace mpi
} // namespace mlir

