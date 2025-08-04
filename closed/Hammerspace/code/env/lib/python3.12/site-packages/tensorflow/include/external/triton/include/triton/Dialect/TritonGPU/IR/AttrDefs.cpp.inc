/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mlir::triton::gpu::CTALayoutAttr,
::mlir::triton::gpu::SharedEncodingAttr,
::mlir::triton::gpu::LinearEncodingAttr,
::mlir::triton::gpu::BlockedEncodingAttr,
::mlir::triton::gpu::AMDMfmaEncodingAttr,
::mlir::triton::gpu::AMDWmmaEncodingAttr,
::mlir::triton::gpu::NvidiaMmaEncodingAttr,
::mlir::triton::gpu::SliceEncodingAttr,
::mlir::triton::gpu::DotOperandEncodingAttr,
::mlir::triton::gpu::SharedMemorySpaceAttr

#endif  // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::triton::gpu::SharedEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::SharedEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::LinearEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::LinearEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::BlockedEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::BlockedEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::AMDMfmaEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::AMDMfmaEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::AMDWmmaEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::AMDWmmaEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::NvidiaMmaEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::NvidiaMmaEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::SliceEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::SliceEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::DotOperandEncodingAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::DotOperandEncodingAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::triton::gpu::SharedMemorySpaceAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::triton::gpu::SharedMemorySpaceAttr::get(parser.getContext());
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::llvm::LogicalResult>(def)    .Case<::mlir::triton::gpu::SharedEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::SharedEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::LinearEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::LinearEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::BlockedEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::BlockedEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::AMDMfmaEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::AMDMfmaEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::AMDWmmaEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::AMDWmmaEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::NvidiaMmaEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::NvidiaMmaEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::SliceEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::SliceEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::DotOperandEncodingAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::DotOperandEncodingAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::triton::gpu::SharedMemorySpaceAttr>([&](auto t) {
      printer << ::mlir::triton::gpu::SharedMemorySpaceAttr::getMnemonic();
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct CTALayoutAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<unsigned>, ::llvm::ArrayRef<unsigned>, ::llvm::ArrayRef<unsigned>>;
  CTALayoutAttrStorage(::llvm::ArrayRef<unsigned> CTAsPerCGA, ::llvm::ArrayRef<unsigned> CTASplitNum, ::llvm::ArrayRef<unsigned> CTAOrder) : CTAsPerCGA(std::move(CTAsPerCGA)), CTASplitNum(std::move(CTASplitNum)), CTAOrder(std::move(CTAOrder)) {}

  KeyTy getAsKey() const {
    return KeyTy(CTAsPerCGA, CTASplitNum, CTAOrder);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (CTAsPerCGA == std::get<0>(tblgenKey)) && (CTASplitNum == std::get<1>(tblgenKey)) && (CTAOrder == std::get<2>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey));
  }

  static CTALayoutAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto CTAsPerCGA = std::move(std::get<0>(tblgenKey));
    auto CTASplitNum = std::move(std::get<1>(tblgenKey));
    auto CTAOrder = std::move(std::get<2>(tblgenKey));
    CTAsPerCGA = allocator.copyInto(CTAsPerCGA);
    CTASplitNum = allocator.copyInto(CTASplitNum);
    CTAOrder = allocator.copyInto(CTAOrder);
    return new (allocator.allocate<CTALayoutAttrStorage>()) CTALayoutAttrStorage(std::move(CTAsPerCGA), std::move(CTASplitNum), std::move(CTAOrder));
  }

  ::llvm::ArrayRef<unsigned> CTAsPerCGA;
  ::llvm::ArrayRef<unsigned> CTASplitNum;
  ::llvm::ArrayRef<unsigned> CTAOrder;
};
} // namespace detail
CTALayoutAttr CTALayoutAttr::get(::mlir::MLIRContext *context, ArrayRef<unsigned> CTAsPerCGA, ArrayRef<unsigned> CTASplitNum, ArrayRef<unsigned> CTAOrder) {
  if (llvm::all_of(CTAsPerCGA, [](unsigned x) { return x == 1; })) {
    SmallVector<unsigned> order;
    for (int i = CTAsPerCGA.size() - 1; i >= 0; --i)
      order.push_back(i);
    return Base::get(context, CTAsPerCGA, CTASplitNum, order);
  }
  return Base::get(context, CTAsPerCGA, CTASplitNum, CTAOrder);
}

CTALayoutAttr CTALayoutAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ArrayRef<unsigned> CTAsPerCGA, ArrayRef<unsigned> CTASplitNum, ArrayRef<unsigned> CTAOrder) {
  if (llvm::all_of(CTAsPerCGA, [](unsigned x) { return x == 1; })) {
    SmallVector<unsigned> order;
    for (int i = CTAsPerCGA.size() - 1; i >= 0; --i)
      order.push_back(i);
    return Base::getChecked(emitError, context, CTAsPerCGA, CTASplitNum, order);
  }
  return Base::getChecked(emitError, context, CTAsPerCGA, CTASplitNum, CTAOrder);
}

::llvm::LogicalResult CTALayoutAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<unsigned> CTAsPerCGA, ::llvm::ArrayRef<unsigned> CTASplitNum, ::llvm::ArrayRef<unsigned> CTAOrder) {
  if (::mlir::failed(verify(emitError, CTAsPerCGA, CTASplitNum, CTAOrder)))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::ArrayRef<unsigned> CTALayoutAttr::getCTAsPerCGA() const {
  return getImpl()->CTAsPerCGA;
}

::llvm::ArrayRef<unsigned> CTALayoutAttr::getCTASplitNum() const {
  return getImpl()->CTASplitNum;
}

::llvm::ArrayRef<unsigned> CTALayoutAttr::getCTAOrder() const {
  return getImpl()->CTAOrder;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::CTALayoutAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct SharedEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, unsigned, unsigned, ::llvm::ArrayRef<unsigned>, CTALayoutAttr, bool>;
  SharedEncodingAttrStorage(unsigned vec, unsigned perPhase, unsigned maxPhase, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout, bool hasLeadingOffset) : vec(std::move(vec)), perPhase(std::move(perPhase)), maxPhase(std::move(maxPhase)), order(std::move(order)), CTALayout(std::move(CTALayout)), hasLeadingOffset(std::move(hasLeadingOffset)) {}

  KeyTy getAsKey() const {
    return KeyTy(vec, perPhase, maxPhase, order, CTALayout, hasLeadingOffset);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (vec == std::get<0>(tblgenKey)) && (perPhase == std::get<1>(tblgenKey)) && (maxPhase == std::get<2>(tblgenKey)) && (order == std::get<3>(tblgenKey)) && (CTALayout == std::get<4>(tblgenKey)) && (hasLeadingOffset == std::get<5>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey), std::get<5>(tblgenKey));
  }

  static SharedEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto vec = std::move(std::get<0>(tblgenKey));
    auto perPhase = std::move(std::get<1>(tblgenKey));
    auto maxPhase = std::move(std::get<2>(tblgenKey));
    auto order = std::move(std::get<3>(tblgenKey));
    auto CTALayout = std::move(std::get<4>(tblgenKey));
    auto hasLeadingOffset = std::move(std::get<5>(tblgenKey));
    order = allocator.copyInto(order);
    return new (allocator.allocate<SharedEncodingAttrStorage>()) SharedEncodingAttrStorage(std::move(vec), std::move(perPhase), std::move(maxPhase), std::move(order), std::move(CTALayout), std::move(hasLeadingOffset));
  }

  unsigned vec;
  unsigned perPhase;
  unsigned maxPhase;
  ::llvm::ArrayRef<unsigned> order;
  CTALayoutAttr CTALayout;
  bool hasLeadingOffset;
};
} // namespace detail
SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, unsigned vec, unsigned perPhase, unsigned maxPhase, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout, bool hasLeadingOffset) {
  return Base::get(context, std::move(vec), std::move(perPhase), std::move(maxPhase), std::move(order), std::move(CTALayout), std::move(hasLeadingOffset));
}

SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, unsigned vec, unsigned perPhase, unsigned maxPhase, ArrayRef<unsigned> order, CTALayoutAttr CTALayout) {
  bool hasLeadingOffset = false; // default value
  return Base::get(context, vec, perPhase, maxPhase, order, CTALayout, hasLeadingOffset);
}

SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, unsigned typeWidthInBit) {
  bool needTrans = false; // default value
  return get(context, dotOpEnc, shape, order, CTALayout, typeWidthInBit, needTrans);
}

SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, unsigned typeWidthInBit, bool needTrans) {
  // ---- begin GFX908/GFX90A ----
  if (auto mfmaEnc = mlir::dyn_cast<AMDMfmaEncodingAttr>(dotOpEnc.getParent())) {
    int kDimNum = dotOpEnc.getOpIdx() == 0 ? 1 : 0;
    if (needTrans)
      kDimNum = 1 - kDimNum;
    bool isKDimInner = (order[0] == kDimNum);
    if (isKDimInner) {
      const int numBanks = 32;
      const int bankBitWidth = 32;
      const int SIMDWidth = 16;

      // number of inner dimension rows per one pattern repeat
      int innerDimLength = shape[order[0]];
      int elemsPerOneBanksRow = (numBanks * bankBitWidth) / typeWidthInBit;

      int perPhase = std::max(1, elemsPerOneBanksRow / innerDimLength);
      // vecSize is set to kWidth of the dotop layout
      int vecSize = dotOpEnc.getKWidth();
      int maxPhase = std::max(std::min(SIMDWidth / perPhase, innerDimLength / vecSize), 1);

      // TODO (zhanglx): figure out better parameters for mfma4
      if (mfmaEnc.getMDim() == 4)
        maxPhase = 4;

      return get(context, vecSize, perPhase, maxPhase, order, CTALayout);
    } else {
      // Do not swizzle in case k dimension is not innermost.
      // In this case accesses will go in different banks even without swizzling.
      return get(context, 1, 1, 1, order, CTALayout);
    }
  }

  // ---- begin GFX11 ----
  if (mlir::isa<AMDWmmaEncodingAttr>(dotOpEnc.getParent())) {
    if (dotOpEnc.getOpIdx() == 0) {
      const int numBanks = 32;
      const int bankBitWidth = 32;

      // number of inner dimension rows per one pattern repeat
      int innerDimLength = shape[order[0]];
      int elemsPerOneBanksRow = (numBanks * bankBitWidth) / typeWidthInBit;

      int perPhase = std::max(1, elemsPerOneBanksRow / innerDimLength);
      int vecSize = ((typeWidthInBit == 16) ? 64 : 32 ) / typeWidthInBit;
      int maxPhase = 16 / perPhase;

      return get(context, vecSize, perPhase, maxPhase, order, CTALayout);
    } else {
      // Do not swizzle in case k dimension is not innermost.
      // In this case accesses will go in different banks even without swizzling.
      return get(context, 1, 1, 1, order, CTALayout);
    }
  }


  auto mmaEnc = mlir::dyn_cast<NvidiaMmaEncodingAttr>(dotOpEnc.getParent());

  if(!mmaEnc)
    return get(context, 1, 1, 1, order, CTALayout);

  int opIdx = dotOpEnc.getOpIdx();
  auto shapePerCTA = getShapePerCTA(CTALayout.getCTASplitNum(), shape);

  // number of rows per phase

  // index of the inner dimension in `order`
  unsigned inner = (opIdx == 0) ? 0 : 1;

  // ---- begin Ampere & Hopper ----
  if (mmaEnc.isAmpere() || mmaEnc.isHopper()) {
    int perPhase = 128 / (shapePerCTA[order[0]] * 4 / dotOpEnc.getKWidth());
    perPhase = std::max<int>(perPhase, 1);
    std::vector<size_t> matShape = {8, 8, 4 * dotOpEnc.getKWidth()};
    int vecWidth = 32 / typeWidthInBit;
    if (vecWidth != dotOpEnc.getKWidth() && order[0] == inner) {
        perPhase = std::max<int>(perPhase, 2 * vecWidth);
    }
    int rank = order.size();
    // --- handle A operand ---
    if (opIdx == 0) { // compute swizzling for A operand
        int m = (needTrans) ? matShape[2] : matShape[0];
        int k = (needTrans) ? matShape[0] : matShape[2];
        int vec = (order[0] == rank-1) ? k : m;
        int mmaStride = (order[0] == rank-1) ? m : k;
        int maxPhase = std::max(mmaStride / perPhase, 1);
        return get(context, vec, perPhase, maxPhase, order, CTALayout);
    }

    // --- handle B operand ---
    if (opIdx == 1) {
        // we compute vec and maxPhase m, n and k size of the mma
        // instruction. when matmul operands is transposed, we should
        // consider that to get m, n and k.
        int n = needTrans ? matShape[2] : matShape[1];
        int k = needTrans ? matShape[1] : matShape[2];
        int vec = (order[0] == rank-1) ? n : k;
        int mmaStride = (order[0] == rank-1) ? k : n;
        int maxPhase = std::max(mmaStride / perPhase, 1);
        return get(context, vec, perPhase, maxPhase, order, CTALayout);
    }

    llvm_unreachable("invalid operand index");
  }

  // ---- not implemented ----
  llvm_unreachable("unsupported swizzling for provided MMA version");
}

SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, Type eltTy) {
  unsigned bitwidth = eltTy.getIntOrFloatBitWidth();
  return get(context, dotOpEnc, shape, order, CTALayout, bitwidth);
}

SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, DotOperandEncodingAttr dotOpEnc, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, Type eltTy, bool needTrans) {
  unsigned bitwidth = eltTy.getIntOrFloatBitWidth();
  return get(context, dotOpEnc, shape, order, CTALayout, bitwidth, needTrans);
}

SharedEncodingAttr SharedEncodingAttr::get(::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> order, CTALayoutAttr CTALayout, Type eltTy) {
  auto shapePerCTA = getShapePerCTA(CTALayout.getCTASplitNum(), shape);

  int32_t eleBitWidth = eltTy.getIntOrFloatBitWidth();
  int32_t vec = 128 / eleBitWidth, perPhase = 1, maxPhase = 1;

  // get proper shared memory swizzling mode from the contiguous dimension
  // size of the origin blocked layout.
  auto contigDimSizeInByte = shapePerCTA[order[0]] * eleBitWidth / 8;
  if (contigDimSizeInByte >= 128 && contigDimSizeInByte % 128 == 0) {
    perPhase = 1;
    maxPhase = 8;
  } else if (contigDimSizeInByte >= 64 && contigDimSizeInByte % 64 == 0) {
    perPhase = 2;
    maxPhase = 4;
  } else if (contigDimSizeInByte >= 32 && contigDimSizeInByte % 32 == 0) {
    perPhase = 4;
    maxPhase = 2;
  } else {
    llvm_unreachable("unsupported shared memory layout for MMAv3");
  }

  return Base::get(context, vec, perPhase, maxPhase, order, CTALayout, true);
}

unsigned SharedEncodingAttr::getVec() const {
  return getImpl()->vec;
}

unsigned SharedEncodingAttr::getPerPhase() const {
  return getImpl()->perPhase;
}

unsigned SharedEncodingAttr::getMaxPhase() const {
  return getImpl()->maxPhase;
}

::llvm::ArrayRef<unsigned> SharedEncodingAttr::getOrder() const {
  return getImpl()->order;
}

CTALayoutAttr SharedEncodingAttr::getCTALayout() const {
  return getImpl()->CTALayout;
}

bool SharedEncodingAttr::getHasLeadingOffset() const {
  return getImpl()->hasLeadingOffset;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::SharedEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct LinearEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<LinearLayout>;
  LinearEncodingAttrStorage(LinearLayout linearLayout) : linearLayout(std::move(linearLayout)) {}

  KeyTy getAsKey() const {
    return KeyTy(linearLayout);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (linearLayout == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static LinearEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto linearLayout = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<LinearEncodingAttrStorage>()) LinearEncodingAttrStorage(std::move(linearLayout));
  }

  LinearLayout linearLayout;
};
} // namespace detail
LinearEncodingAttr LinearEncodingAttr::get(::mlir::MLIRContext *context, LinearLayout linearLayout) {
  return Base::get(context, std::move(linearLayout));
}

LinearEncodingAttr LinearEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, LinearLayout linearLayout) {
  return Base::getChecked(emitError, context, linearLayout);
}

::llvm::LogicalResult LinearEncodingAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, LinearLayout linearLayout) {
  if (::mlir::failed(verify(emitError, linearLayout)))
    return ::mlir::failure();
  return ::mlir::success();
}

const LinearLayout &LinearEncodingAttr::getLinearLayout() const {
  return getImpl()->linearLayout;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::LinearEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct BlockedEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<unsigned>, ::llvm::ArrayRef<unsigned>, ::llvm::ArrayRef<unsigned>, ::llvm::ArrayRef<unsigned>, CTALayoutAttr>;
  BlockedEncodingAttrStorage(::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout) : sizePerThread__(std::move(sizePerThread__)), threadsPerWarp__(std::move(threadsPerWarp__)), warpsPerCTA__(std::move(warpsPerCTA__)), order(std::move(order)), CTALayout(std::move(CTALayout)) {}

  KeyTy getAsKey() const {
    return KeyTy(sizePerThread__, threadsPerWarp__, warpsPerCTA__, order, CTALayout);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (sizePerThread__ == std::get<0>(tblgenKey)) && (threadsPerWarp__ == std::get<1>(tblgenKey)) && (warpsPerCTA__ == std::get<2>(tblgenKey)) && (order == std::get<3>(tblgenKey)) && (CTALayout == std::get<4>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey));
  }

  static BlockedEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto sizePerThread__ = std::move(std::get<0>(tblgenKey));
    auto threadsPerWarp__ = std::move(std::get<1>(tblgenKey));
    auto warpsPerCTA__ = std::move(std::get<2>(tblgenKey));
    auto order = std::move(std::get<3>(tblgenKey));
    auto CTALayout = std::move(std::get<4>(tblgenKey));
    sizePerThread__ = allocator.copyInto(sizePerThread__);
    threadsPerWarp__ = allocator.copyInto(threadsPerWarp__);
    warpsPerCTA__ = allocator.copyInto(warpsPerCTA__);
    order = allocator.copyInto(order);
    return new (allocator.allocate<BlockedEncodingAttrStorage>()) BlockedEncodingAttrStorage(std::move(sizePerThread__), std::move(threadsPerWarp__), std::move(warpsPerCTA__), std::move(order), std::move(CTALayout));
  }

  ::llvm::ArrayRef<unsigned> sizePerThread__;
  ::llvm::ArrayRef<unsigned> threadsPerWarp__;
  ::llvm::ArrayRef<unsigned> warpsPerCTA__;
  ::llvm::ArrayRef<unsigned> order;
  CTALayoutAttr CTALayout;
};
} // namespace detail
BlockedEncodingAttr BlockedEncodingAttr::get(::mlir::MLIRContext *context, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout) {
  return Base::get(context, std::move(sizePerThread__), std::move(threadsPerWarp__), std::move(warpsPerCTA__), std::move(order), std::move(CTALayout));
}

BlockedEncodingAttr BlockedEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout) {
  return Base::getChecked(emitError, context, sizePerThread__, threadsPerWarp__, warpsPerCTA__, order, CTALayout);
}

BlockedEncodingAttr BlockedEncodingAttr::get(::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, CTALayoutAttr CTALayout) {
  unsigned rank = sizePerThread.size();
  SmallVector<unsigned, 4> threadsPerWarp(rank);
  SmallVector<unsigned, 4> warpsPerCTA(rank);
  SmallVector<int64_t> shapePerCTA = getShapePerCTA(CTALayout.getCTASplitNum(), shape);

  unsigned remainingLanes = numThreadsPerWarp;
  unsigned remainingThreads = numWarps * numThreadsPerWarp;
  unsigned remainingWarps = numWarps;
  unsigned prevLanes = 1;
  unsigned prevWarps = 1;

  // starting from the contiguous dimension
  for (unsigned d = 0; d < rank - 1; ++d) {
    unsigned i = order[d];
    unsigned threadsPerCTA = std::clamp<unsigned>(remainingThreads, 1, std::max<unsigned>(1, shapePerCTA[i] / sizePerThread[i]));
    threadsPerWarp[i] = std::clamp<unsigned>(threadsPerCTA, 1, remainingLanes);
    warpsPerCTA[i] = std::clamp<unsigned>(threadsPerCTA / threadsPerWarp[i], 1, remainingWarps);
    remainingWarps /= warpsPerCTA[i];
    remainingLanes /= threadsPerWarp[i];
    remainingThreads /= threadsPerCTA;
    prevLanes *= threadsPerWarp[i];
    prevWarps *= warpsPerCTA[i];
  }

  // Expand the last dimension to fill the remaining lanes and warps
  threadsPerWarp[order[rank - 1]] = numThreadsPerWarp / prevLanes;
  warpsPerCTA[order[rank - 1]] = numWarps / prevWarps;

  return Base::get(context, sizePerThread, threadsPerWarp, warpsPerCTA, order, CTALayout);
}

BlockedEncodingAttr BlockedEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, CTALayoutAttr CTALayout) {
  unsigned rank = sizePerThread.size();
  SmallVector<unsigned, 4> threadsPerWarp(rank);
  SmallVector<unsigned, 4> warpsPerCTA(rank);
  SmallVector<int64_t> shapePerCTA = getShapePerCTA(CTALayout.getCTASplitNum(), shape);

  unsigned remainingLanes = numThreadsPerWarp;
  unsigned remainingThreads = numWarps * numThreadsPerWarp;
  unsigned remainingWarps = numWarps;
  unsigned prevLanes = 1;
  unsigned prevWarps = 1;

  // starting from the contiguous dimension
  for (unsigned d = 0; d < rank - 1; ++d) {
    unsigned i = order[d];
    unsigned threadsPerCTA = std::clamp<unsigned>(remainingThreads, 1, std::max<unsigned>(1, shapePerCTA[i] / sizePerThread[i]));
    threadsPerWarp[i] = std::clamp<unsigned>(threadsPerCTA, 1, remainingLanes);
    warpsPerCTA[i] = std::clamp<unsigned>(threadsPerCTA / threadsPerWarp[i], 1, remainingWarps);
    remainingWarps /= warpsPerCTA[i];
    remainingLanes /= threadsPerWarp[i];
    remainingThreads /= threadsPerCTA;
    prevLanes *= threadsPerWarp[i];
    prevWarps *= warpsPerCTA[i];
  }

  // Expand the last dimension to fill the remaining lanes and warps
  threadsPerWarp[order[rank - 1]] = numThreadsPerWarp / prevLanes;
  warpsPerCTA[order[rank - 1]] = numWarps / prevWarps;

  return Base::getChecked(emitError, context, sizePerThread, threadsPerWarp, warpsPerCTA, order, CTALayout);
}

BlockedEncodingAttr BlockedEncodingAttr::get(::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, unsigned numCTAs) {
  unsigned rank = sizePerThread.size();
  SmallVector<unsigned, 4> CTAsPerCGA(rank);
  SmallVector<unsigned, 4> CTASplitNum(rank);
  ArrayRef<unsigned> CTAOrder = order;

  unsigned remainingCTAs = numCTAs;

  // starting from the most strided dimension
  for (int d = rank - 1; d >= 0; --d) {
    unsigned i = order[d];
    CTAsPerCGA[i] = std::clamp<unsigned>(remainingCTAs, 1, std::max<unsigned>(1, shape[i] / sizePerThread[i]));
    CTASplitNum[i] = CTAsPerCGA[i];
    remainingCTAs /= CTAsPerCGA[i];
  }

  CTAsPerCGA[rank - 1] *= remainingCTAs; // wrap at CTA level

  CTALayoutAttr CTALayout = CTALayoutAttr::get(context, CTAsPerCGA, CTASplitNum, CTAOrder);
  return get(context, shape, sizePerThread, order, numWarps, numThreadsPerWarp, CTALayout);
}

BlockedEncodingAttr BlockedEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ArrayRef<int64_t> shape, ArrayRef<unsigned> sizePerThread, ArrayRef<unsigned> order, unsigned numWarps, unsigned numThreadsPerWarp, unsigned numCTAs) {
  unsigned rank = sizePerThread.size();
  SmallVector<unsigned, 4> CTAsPerCGA(rank);
  SmallVector<unsigned, 4> CTASplitNum(rank);
  ArrayRef<unsigned> CTAOrder = order;

  unsigned remainingCTAs = numCTAs;

  // starting from the most strided dimension
  for (int d = rank - 1; d >= 0; --d) {
    unsigned i = order[d];
    CTAsPerCGA[i] = std::clamp<unsigned>(remainingCTAs, 1, std::max<unsigned>(1, shape[i] / sizePerThread[i]));
    CTASplitNum[i] = CTAsPerCGA[i];
    remainingCTAs /= CTAsPerCGA[i];
  }

  CTAsPerCGA[rank - 1] *= remainingCTAs; // wrap at CTA level

  CTALayoutAttr CTALayout = CTALayoutAttr::get(context, CTAsPerCGA, CTASplitNum, CTAOrder);
  return get(context, shape, sizePerThread, order, numWarps, numThreadsPerWarp, CTALayout);
}

::llvm::LogicalResult BlockedEncodingAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<unsigned> sizePerThread__, ::llvm::ArrayRef<unsigned> threadsPerWarp__, ::llvm::ArrayRef<unsigned> warpsPerCTA__, ::llvm::ArrayRef<unsigned> order, CTALayoutAttr CTALayout) {
  if (::mlir::failed(verify(emitError, sizePerThread__, threadsPerWarp__, warpsPerCTA__, order, CTALayout)))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::ArrayRef<unsigned> BlockedEncodingAttr::getSizePerThread__() const {
  return getImpl()->sizePerThread__;
}

::llvm::ArrayRef<unsigned> BlockedEncodingAttr::getThreadsPerWarp__() const {
  return getImpl()->threadsPerWarp__;
}

::llvm::ArrayRef<unsigned> BlockedEncodingAttr::getWarpsPerCTA__() const {
  return getImpl()->warpsPerCTA__;
}

::llvm::ArrayRef<unsigned> BlockedEncodingAttr::getOrder() const {
  return getImpl()->order;
}

CTALayoutAttr BlockedEncodingAttr::getCTALayout() const {
  return getImpl()->CTALayout;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::BlockedEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct AMDMfmaEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, unsigned, ::llvm::ArrayRef<unsigned>, unsigned, unsigned, bool, CTALayoutAttr>;
  AMDMfmaEncodingAttrStorage(unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout) : versionMajor(std::move(versionMajor)), versionMinor(std::move(versionMinor)), warpsPerCTA__(std::move(warpsPerCTA__)), MDim(std::move(MDim)), NDim(std::move(NDim)), isTransposed(std::move(isTransposed)), CTALayout(std::move(CTALayout)) {}

  KeyTy getAsKey() const {
    return KeyTy(versionMajor, versionMinor, warpsPerCTA__, MDim, NDim, isTransposed, CTALayout);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (versionMajor == std::get<0>(tblgenKey)) && (versionMinor == std::get<1>(tblgenKey)) && (warpsPerCTA__ == std::get<2>(tblgenKey)) && (MDim == std::get<3>(tblgenKey)) && (NDim == std::get<4>(tblgenKey)) && (isTransposed == std::get<5>(tblgenKey)) && (CTALayout == std::get<6>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey), std::get<5>(tblgenKey), std::get<6>(tblgenKey));
  }

  static AMDMfmaEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto versionMajor = std::move(std::get<0>(tblgenKey));
    auto versionMinor = std::move(std::get<1>(tblgenKey));
    auto warpsPerCTA__ = std::move(std::get<2>(tblgenKey));
    auto MDim = std::move(std::get<3>(tblgenKey));
    auto NDim = std::move(std::get<4>(tblgenKey));
    auto isTransposed = std::move(std::get<5>(tblgenKey));
    auto CTALayout = std::move(std::get<6>(tblgenKey));
    warpsPerCTA__ = allocator.copyInto(warpsPerCTA__);
    return new (allocator.allocate<AMDMfmaEncodingAttrStorage>()) AMDMfmaEncodingAttrStorage(std::move(versionMajor), std::move(versionMinor), std::move(warpsPerCTA__), std::move(MDim), std::move(NDim), std::move(isTransposed), std::move(CTALayout));
  }

  unsigned versionMajor;
  unsigned versionMinor;
  ::llvm::ArrayRef<unsigned> warpsPerCTA__;
  unsigned MDim;
  unsigned NDim;
  bool isTransposed;
  CTALayoutAttr CTALayout;
};
} // namespace detail
AMDMfmaEncodingAttr AMDMfmaEncodingAttr::get(::mlir::MLIRContext *context, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout) {
  return Base::get(context, std::move(versionMajor), std::move(versionMinor), std::move(warpsPerCTA__), std::move(MDim), std::move(NDim), std::move(isTransposed), std::move(CTALayout));
}

AMDMfmaEncodingAttr AMDMfmaEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout) {
  return Base::getChecked(emitError, context, versionMajor, versionMinor, warpsPerCTA__, MDim, NDim, isTransposed, CTALayout);
}

::llvm::LogicalResult AMDMfmaEncodingAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, unsigned MDim, unsigned NDim, bool isTransposed, CTALayoutAttr CTALayout) {
  if (::mlir::failed(verify(emitError, versionMajor, versionMinor, warpsPerCTA__, MDim, NDim, isTransposed, CTALayout)))
    return ::mlir::failure();
  return ::mlir::success();
}

unsigned AMDMfmaEncodingAttr::getVersionMajor() const {
  return getImpl()->versionMajor;
}

unsigned AMDMfmaEncodingAttr::getVersionMinor() const {
  return getImpl()->versionMinor;
}

::llvm::ArrayRef<unsigned> AMDMfmaEncodingAttr::getWarpsPerCTA__() const {
  return getImpl()->warpsPerCTA__;
}

unsigned AMDMfmaEncodingAttr::getMDim() const {
  return getImpl()->MDim;
}

unsigned AMDMfmaEncodingAttr::getNDim() const {
  return getImpl()->NDim;
}

bool AMDMfmaEncodingAttr::getIsTransposed() const {
  return getImpl()->isTransposed;
}

CTALayoutAttr AMDMfmaEncodingAttr::getCTALayout() const {
  return getImpl()->CTALayout;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::AMDMfmaEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct AMDWmmaEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, bool, ::llvm::ArrayRef<unsigned>, CTALayoutAttr>;
  AMDWmmaEncodingAttrStorage(unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout) : version(std::move(version)), isTransposed(std::move(isTransposed)), warpsPerCTA__(std::move(warpsPerCTA__)), CTALayout(std::move(CTALayout)) {}

  KeyTy getAsKey() const {
    return KeyTy(version, isTransposed, warpsPerCTA__, CTALayout);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (version == std::get<0>(tblgenKey)) && (isTransposed == std::get<1>(tblgenKey)) && (warpsPerCTA__ == std::get<2>(tblgenKey)) && (CTALayout == std::get<3>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey));
  }

  static AMDWmmaEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto version = std::move(std::get<0>(tblgenKey));
    auto isTransposed = std::move(std::get<1>(tblgenKey));
    auto warpsPerCTA__ = std::move(std::get<2>(tblgenKey));
    auto CTALayout = std::move(std::get<3>(tblgenKey));
    warpsPerCTA__ = allocator.copyInto(warpsPerCTA__);
    return new (allocator.allocate<AMDWmmaEncodingAttrStorage>()) AMDWmmaEncodingAttrStorage(std::move(version), std::move(isTransposed), std::move(warpsPerCTA__), std::move(CTALayout));
  }

  unsigned version;
  bool isTransposed;
  ::llvm::ArrayRef<unsigned> warpsPerCTA__;
  CTALayoutAttr CTALayout;
};
} // namespace detail
AMDWmmaEncodingAttr AMDWmmaEncodingAttr::get(::mlir::MLIRContext *context, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout) {
  return Base::get(context, std::move(version), std::move(isTransposed), std::move(warpsPerCTA__), std::move(CTALayout));
}

AMDWmmaEncodingAttr AMDWmmaEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout) {
  return Base::getChecked(emitError, context, version, isTransposed, warpsPerCTA__, CTALayout);
}

::llvm::LogicalResult AMDWmmaEncodingAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned version, bool isTransposed, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout) {
  if (::mlir::failed(verify(emitError, version, isTransposed, warpsPerCTA__, CTALayout)))
    return ::mlir::failure();
  return ::mlir::success();
}

unsigned AMDWmmaEncodingAttr::getVersion() const {
  return getImpl()->version;
}

bool AMDWmmaEncodingAttr::getIsTransposed() const {
  return getImpl()->isTransposed;
}

::llvm::ArrayRef<unsigned> AMDWmmaEncodingAttr::getWarpsPerCTA__() const {
  return getImpl()->warpsPerCTA__;
}

CTALayoutAttr AMDWmmaEncodingAttr::getCTALayout() const {
  return getImpl()->CTALayout;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::AMDWmmaEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct NvidiaMmaEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, unsigned, ::llvm::ArrayRef<unsigned>, CTALayoutAttr, ::llvm::ArrayRef<unsigned>>;
  NvidiaMmaEncodingAttrStorage(unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout, ::llvm::ArrayRef<unsigned> instrShape) : versionMajor(std::move(versionMajor)), versionMinor(std::move(versionMinor)), warpsPerCTA__(std::move(warpsPerCTA__)), CTALayout(std::move(CTALayout)), instrShape(std::move(instrShape)) {}

  KeyTy getAsKey() const {
    return KeyTy(versionMajor, versionMinor, warpsPerCTA__, CTALayout, instrShape);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (versionMajor == std::get<0>(tblgenKey)) && (versionMinor == std::get<1>(tblgenKey)) && (warpsPerCTA__ == std::get<2>(tblgenKey)) && (CTALayout == std::get<3>(tblgenKey)) && (instrShape == std::get<4>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey));
  }

  static NvidiaMmaEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto versionMajor = std::move(std::get<0>(tblgenKey));
    auto versionMinor = std::move(std::get<1>(tblgenKey));
    auto warpsPerCTA__ = std::move(std::get<2>(tblgenKey));
    auto CTALayout = std::move(std::get<3>(tblgenKey));
    auto instrShape = std::move(std::get<4>(tblgenKey));
    warpsPerCTA__ = allocator.copyInto(warpsPerCTA__);
    instrShape = allocator.copyInto(instrShape);
    return new (allocator.allocate<NvidiaMmaEncodingAttrStorage>()) NvidiaMmaEncodingAttrStorage(std::move(versionMajor), std::move(versionMinor), std::move(warpsPerCTA__), std::move(CTALayout), std::move(instrShape));
  }

  unsigned versionMajor;
  unsigned versionMinor;
  ::llvm::ArrayRef<unsigned> warpsPerCTA__;
  CTALayoutAttr CTALayout;
  ::llvm::ArrayRef<unsigned> instrShape;
};
} // namespace detail
NvidiaMmaEncodingAttr NvidiaMmaEncodingAttr::get(::mlir::MLIRContext *context, unsigned versionMajor, unsigned versionMinor, ::llvm::ArrayRef<unsigned> warpsPerCTA__, CTALayoutAttr CTALayout, ::llvm::ArrayRef<unsigned> instrShape) {
  return Base::get(context, std::move(versionMajor), std::move(versionMinor), std::move(warpsPerCTA__), std::move(CTALayout), std::move(instrShape));
}

unsigned NvidiaMmaEncodingAttr::getVersionMajor() const {
  return getImpl()->versionMajor;
}

unsigned NvidiaMmaEncodingAttr::getVersionMinor() const {
  return getImpl()->versionMinor;
}

::llvm::ArrayRef<unsigned> NvidiaMmaEncodingAttr::getWarpsPerCTA__() const {
  return getImpl()->warpsPerCTA__;
}

CTALayoutAttr NvidiaMmaEncodingAttr::getCTALayout() const {
  return getImpl()->CTALayout;
}

::llvm::ArrayRef<unsigned> NvidiaMmaEncodingAttr::getInstrShape() const {
  return getImpl()->instrShape;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::NvidiaMmaEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct SliceEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, Attribute>;
  SliceEncodingAttrStorage(unsigned dim, Attribute parent) : dim(std::move(dim)), parent(std::move(parent)) {}

  KeyTy getAsKey() const {
    return KeyTy(dim, parent);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (dim == std::get<0>(tblgenKey)) && (parent == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static SliceEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto dim = std::move(std::get<0>(tblgenKey));
    auto parent = std::move(std::get<1>(tblgenKey));
    return new (allocator.allocate<SliceEncodingAttrStorage>()) SliceEncodingAttrStorage(std::move(dim), std::move(parent));
  }

  unsigned dim;
  Attribute parent;
};
} // namespace detail
SliceEncodingAttr SliceEncodingAttr::get(::mlir::MLIRContext *context, unsigned dim, Attribute parent) {
  return Base::get(context, std::move(dim), std::move(parent));
}

unsigned SliceEncodingAttr::getDim() const {
  return getImpl()->dim;
}

Attribute SliceEncodingAttr::getParent() const {
  return getImpl()->parent;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::SliceEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
namespace detail {
struct DotOperandEncodingAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, Attribute, unsigned>;
  DotOperandEncodingAttrStorage(unsigned opIdx, Attribute parent, unsigned kWidth) : opIdx(std::move(opIdx)), parent(std::move(parent)), kWidth(std::move(kWidth)) {}

  KeyTy getAsKey() const {
    return KeyTy(opIdx, parent, kWidth);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (opIdx == std::get<0>(tblgenKey)) && (parent == std::get<1>(tblgenKey)) && (kWidth == std::get<2>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey));
  }

  static DotOperandEncodingAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto opIdx = std::move(std::get<0>(tblgenKey));
    auto parent = std::move(std::get<1>(tblgenKey));
    auto kWidth = std::move(std::get<2>(tblgenKey));
    return new (allocator.allocate<DotOperandEncodingAttrStorage>()) DotOperandEncodingAttrStorage(std::move(opIdx), std::move(parent), std::move(kWidth));
  }

  unsigned opIdx;
  Attribute parent;
  unsigned kWidth;
};
} // namespace detail
DotOperandEncodingAttr DotOperandEncodingAttr::get(::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, unsigned kWidth) {
  return Base::get(context, std::move(opIdx), std::move(parent), std::move(kWidth));
}

DotOperandEncodingAttr DotOperandEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, unsigned kWidth) {
  return Base::getChecked(emitError, context, opIdx, parent, kWidth);
}

DotOperandEncodingAttr DotOperandEncodingAttr::get(::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, Type eltTy) {
  NvidiaMmaEncodingAttr parentAttr = mlir::dyn_cast<NvidiaMmaEncodingAttr>(parent);
  if (!parentAttr || (!parentAttr.isAmpere() && !parentAttr.isHopper()))
    return Base::get(context, opIdx, parent, 0);
  // For MMAV2 and V3
  unsigned bitwidth = eltTy.getIntOrFloatBitWidth();
  unsigned kWidth = 32 / bitwidth;
  return Base::get(context, opIdx, parent, kWidth);
}

DotOperandEncodingAttr DotOperandEncodingAttr::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, unsigned opIdx, Attribute parent, Type eltTy) {
  NvidiaMmaEncodingAttr parentAttr = mlir::dyn_cast<NvidiaMmaEncodingAttr>(parent);
  if (!parentAttr || (!parentAttr.isAmpere() && !parentAttr.isHopper()))
    return Base::getChecked(emitError, context, opIdx, parent, 0);
  // For MMAV2 and V3
  unsigned bitwidth = eltTy.getIntOrFloatBitWidth();
  unsigned kWidth = 32 / bitwidth;
  return Base::getChecked(emitError, context, opIdx, parent, kWidth);
}

::llvm::LogicalResult DotOperandEncodingAttr::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, unsigned opIdx, Attribute parent, unsigned kWidth) {
  if (::mlir::failed(verify(emitError, opIdx, parent, kWidth)))
    return ::mlir::failure();
  return ::mlir::success();
}

::mlir::Attribute DotOperandEncodingAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<unsigned> _result_opIdx;
  ::mlir::FailureOr<Attribute> _result_parent;
  ::mlir::FailureOr<unsigned> _result_kWidth;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse literal '{'
  if (odsParser.parseLBrace()) return {};
  // Parse parameter struct
  bool _seen_opIdx = false;
  bool _seen_parent = false;
  bool _seen_kWidth = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_opIdx && _paramKey == "opIdx") {
        _seen_opIdx = true;

        // Parse variable 'opIdx'
        _result_opIdx = ::mlir::FieldParser<unsigned>::parse(odsParser);
        if (::mlir::failed(_result_opIdx)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse DotOperandEncodingAttr parameter 'opIdx' which is to be a `unsigned`");
          return {};
        }
      } else if (!_seen_parent && _paramKey == "parent") {
        _seen_parent = true;

        // Parse variable 'parent'
        _result_parent = ::mlir::FieldParser<Attribute>::parse(odsParser);
        if (::mlir::failed(_result_parent)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse DotOperandEncodingAttr parameter 'parent' which is to be a `Attribute`");
          return {};
        }
      } else if (!_seen_kWidth && _paramKey == "kWidth") {
        _seen_kWidth = true;

        // Parse variable 'kWidth'
        _result_kWidth = ::mlir::FieldParser<unsigned>::parse(odsParser);
        if (::mlir::failed(_result_kWidth)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse DotOperandEncodingAttr parameter 'kWidth' which is to be a `unsigned`");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    do {
      ::llvm::StringRef _paramKey;
      if (odsParser.parseKeyword(&_paramKey)) {
        odsParser.emitError(odsParser.getCurrentLocation(),
                           "expected a parameter name in struct");
        return {};
      }
      if (!_loop_body(_paramKey)) return {};
    } while(!odsParser.parseOptionalComma());
    if (!_seen_opIdx) {
      odsParser.emitError(odsParser.getCurrentLocation(), "struct is missing required parameter: ") << "opIdx";
      return {};
    }
    if (!_seen_parent) {
      odsParser.emitError(odsParser.getCurrentLocation(), "struct is missing required parameter: ") << "parent";
      return {};
    }
  }
  // Parse literal '}'
  if (odsParser.parseRBrace()) return {};
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_opIdx));
  assert(::mlir::succeeded(_result_parent));
  return odsParser.getChecked<DotOperandEncodingAttr>(odsLoc, odsParser.getContext(),
      unsigned((*_result_opIdx)),
      Attribute((*_result_parent)),
      unsigned((_result_kWidth.value_or(0))));
}

void DotOperandEncodingAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << "{";
  {
    bool _firstPrinted = true;
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "opIdx = ";
    odsPrinter.printStrippedAttrOrType(getOpIdx());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "parent = ";
    odsPrinter.printStrippedAttrOrType(getParent());
    if (!(getKWidth() == 0)) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "kWidth = ";
      if (!(getKWidth() == 0)) {
        odsPrinter.printStrippedAttrOrType(getKWidth());
      }
    }
  }
  odsPrinter << "}";
  odsPrinter << ">";
}

unsigned DotOperandEncodingAttr::getOpIdx() const {
  return getImpl()->opIdx;
}

Attribute DotOperandEncodingAttr::getParent() const {
  return getImpl()->parent;
}

unsigned DotOperandEncodingAttr::getKWidth() const {
  return getImpl()->kWidth;
}

} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::DotOperandEncodingAttr)
namespace mlir {
namespace triton {
namespace gpu {
} // namespace gpu
} // namespace triton
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::triton::gpu::SharedMemorySpaceAttr)
namespace mlir {
namespace triton {
namespace gpu {

/// Parse an attribute registered to this dialect.
::mlir::Attribute TritonGPUDialect::parseAttribute(::mlir::DialectAsmParser &parser,
                                      ::mlir::Type type) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef attrTag;
  {
    ::mlir::Attribute attr;
    auto parseResult = generatedAttributeParser(parser, &attrTag, type, attr);
    if (parseResult.has_value())
      return attr;
  }
  
  parser.emitError(typeLoc) << "unknown attribute `"
      << attrTag << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print an attribute registered to this dialect.
void TritonGPUDialect::printAttribute(::mlir::Attribute attr,
                         ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedAttributePrinter(attr, printer)))
    return;
  
}
} // namespace gpu
} // namespace triton
} // namespace mlir

#endif  // GET_ATTRDEF_CLASSES

