if (auto op = dyn_cast<::mlir::NVVM::Barrier0Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_barrier0,0,{},{},{},{});
    (void) inst;
    
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BarrierOp>(opInst)) {

    if (moduleTranslation.lookupValue(op.getNumberOfThreads()) && moduleTranslation.lookupValue(op.getBarrierId())) {
      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier,
                {moduleTranslation.lookupValue(op.getBarrierId()), moduleTranslation.lookupValue(op.getNumberOfThreads())});
    } else if(moduleTranslation.lookupValue(op.getBarrierId())) {
      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_n,
                {moduleTranslation.lookupValue(op.getBarrierId())});   
    } else {
      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier0);
    }
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockDimXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_ntid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockDimYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_ntid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockDimZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_ntid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockIdXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_ctaid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockIdYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_ctaid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockIdZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_ctaid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockInClusterIdXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctaid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockInClusterIdYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctaid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::BlockInClusterIdZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctaid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::Breakpoint>(opInst)) {

    createIntrinsicCall(builder, llvm::Intrinsic::debugtrap);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::Clock64Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_clock64,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClockOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_clock,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterArriveOp>(opInst)) {

      if (op.getAligned())
        createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_cluster_arrive_aligned);
      else
        createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_cluster_arrive);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterArriveRelaxedOp>(opInst)) {

      if (op.getAligned())
        createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_cluster_arrive_relaxed_aligned);
      else
        createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_cluster_arrive_relaxed);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDim>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctarank,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDimBlocksXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctaid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDimBlocksYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctaid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDimBlocksZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctaid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDimXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nclusterid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDimYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nclusterid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterDimZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nclusterid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterId>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctarank,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterIdXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_clusterid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterIdYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_clusterid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterIdZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_clusterid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ClusterWaitOp>(opInst)) {

      if (op.getAligned())
        createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_cluster_wait_aligned);
      else
        createIntrinsicCall(builder, llvm::Intrinsic::nvvm_barrier_cluster_wait);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkCommitGroupOp>(opInst)) {

    createIntrinsicCall(builder, llvm::Intrinsic::nvvm_cp_async_bulk_commit_group);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkGlobalToSharedClusterOp>(opInst)) {

    // Arguments to the intrinsic:
    // dst, mbar, src, size
    // multicast_mask, cache_hint,
    // flag for multicast_mask,
    // flag for cache_hint
    llvm::SmallVector<llvm::Value *> translatedOperands;
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getDstMem()));
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getMbar()));
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getSrcMem()));
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getSize()));

    // Multicast, if available
    llvm::LLVMContext &ctx = moduleTranslation.getLLVMContext();
    auto *i16Unused = llvm::ConstantInt::get(llvm::Type::getInt16Ty(ctx), 0);
    bool isMulticast = op.getMulticastMask() ? true : false;
    translatedOperands.push_back(isMulticast ? moduleTranslation.lookupValue(op.getMulticastMask()) : i16Unused);

    // Cachehint, if available
    auto *i64Unused = llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 0);
    bool isCacheHint = op.getL2CacheHint() ? true : false;
    translatedOperands.push_back(isCacheHint ? moduleTranslation.lookupValue(op.getL2CacheHint()) : i64Unused);

    // Flag arguments for multicast and cachehint
    translatedOperands.push_back(builder.getInt1(isMulticast));
    translatedOperands.push_back(builder.getInt1(isCacheHint));

    createIntrinsicCall(builder,
      llvm::Intrinsic::nvvm_cp_async_bulk_global_to_shared_cluster, translatedOperands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkSharedCTAToGlobalOp>(opInst)) {

    // Arguments to the intrinsic:
    // dst, src, size, cache_hint,
    // Flag for cache_hint
    //
    llvm::SmallVector<llvm::Value *> translatedOperands;
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getDstMem()));
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getSrcMem()));
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getSize()));

    // Cachehint, if available
    llvm::LLVMContext &ctx = moduleTranslation.getLLVMContext();
    auto *i64Unused = llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 0);
    bool isCacheHint = op.getL2CacheHint() ? true : false;
    translatedOperands.push_back(isCacheHint ? moduleTranslation.lookupValue(op.getL2CacheHint()) : i64Unused);

    // Flag argument for cachehint
    translatedOperands.push_back(builder.getInt1(isCacheHint));

    createIntrinsicCall(builder,
      llvm::Intrinsic::nvvm_cp_async_bulk_shared_cta_to_global, translatedOperands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkSharedCTAToSharedClusterOp>(opInst)) {

    createIntrinsicCall(builder,
      llvm::Intrinsic::nvvm_cp_async_bulk_shared_cta_to_cluster,
      {moduleTranslation.lookupValue(op.getDstMem()), moduleTranslation.lookupValue(op.getMbar()), moduleTranslation.lookupValue(op.getSrcMem()), moduleTranslation.lookupValue(op.getSize())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkTensorPrefetchOp>(opInst)) {

    // Arguments to the intrinsic:
    // tmaDesc, tensorDims, im2colOffsets
    // cache_hint(if applicable) and flag(boolean)
    llvm::SmallVector<llvm::Value *> translatedOperands;
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getTmaDescriptor()));

    for (auto v : op.getCoordinates())
      translatedOperands.push_back(moduleTranslation.lookupValue(v));

    for (auto v : op.getIm2colOffsets())
      translatedOperands.push_back(moduleTranslation.lookupValue(v));

    llvm::LLVMContext &ctx = moduleTranslation.getLLVMContext();
    auto *i64Unused = llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 0);

    bool isCacheHint = op.getL2CacheHint() ? true : false;
    translatedOperands.push_back(isCacheHint ? moduleTranslation.lookupValue(op.getL2CacheHint()) : i64Unused);
    translatedOperands.push_back(builder.getInt1(isCacheHint));

    auto intId = NVVM::CpAsyncBulkTensorPrefetchOp::getIntrinsicID(
        op.getCoordinates().size(), op.getIm2colOffsets().size() > 0);
    createIntrinsicCall(builder, intId, translatedOperands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkTensorReduceOp>(opInst)) {

    // Arguments to the intrinsic:
    // shared_mem_ptr, tmaDesc, tensorDims
    // cache_hint(if applicable) and flag(boolean)
    llvm::SmallVector<llvm::Value *> translatedOperands;
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getSrcMem()));
    translatedOperands.push_back(moduleTranslation.lookupValue(op.getTmaDescriptor()));

    for (auto v : op.getCoordinates())
      translatedOperands.push_back(moduleTranslation.lookupValue(v));

    llvm::LLVMContext &ctx = moduleTranslation.getLLVMContext();
    auto *i64Undef = llvm::UndefValue::get(llvm::IntegerType::get(ctx, 64));

    bool isCacheHint = op.getL2CacheHint() ? true : false;
    translatedOperands.push_back(isCacheHint ? moduleTranslation.lookupValue(op.getL2CacheHint()) : i64Undef);
    translatedOperands.push_back(builder.getInt1(isCacheHint));

    auto intId = NVVM::CpAsyncBulkTensorReduceOp::getIntrinsicID(
                 op.getCoordinates().size(), op.getRedKind(),
                 (op.getMode() == NVVM::TMAStoreMode::IM2COL));
    createIntrinsicCall(builder, intId, translatedOperands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncBulkWaitGroupOp>(opInst)) {

    auto intId = op.getRead() ?
      llvm::Intrinsic::nvvm_cp_async_bulk_wait_group_read :
      llvm::Intrinsic::nvvm_cp_async_bulk_wait_group;
    createIntrinsicCall(builder, intId, builder.getInt32(op.getGroup()));
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncCommitGroupOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_cp_async_commit_group);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncMBarrierArriveOp>(opInst)) {

    auto intId = op.getNoinc() ?
      llvm::Intrinsic::nvvm_cp_async_mbarrier_arrive_noinc :
      llvm::Intrinsic::nvvm_cp_async_mbarrier_arrive;

    createIntrinsicCall(builder, intId, {moduleTranslation.lookupValue(op.getAddr())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncMBarrierArriveSharedOp>(opInst)) {

    auto intId = op.getNoinc() ?
      llvm::Intrinsic::nvvm_cp_async_mbarrier_arrive_noinc_shared :
      llvm::Intrinsic::nvvm_cp_async_mbarrier_arrive_shared;

    createIntrinsicCall(builder, intId, {moduleTranslation.lookupValue(op.getAddr())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncOp>(opInst)) {

    llvm::SmallVector<llvm::Value *> translatedOperands;
    auto id = NVVM::CpAsyncOp::getIntrinsicIDAndArgs(
      *op, moduleTranslation, translatedOperands);
    createIntrinsicCall(builder, id, translatedOperands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CpAsyncWaitGroupOp>(opInst)) {

      createIntrinsicCall(
        builder,
        llvm::Intrinsic::nvvm_cp_async_wait_group,
        llvm::ConstantInt::get(
          llvm::Type::getInt32Ty(moduleTranslation.getLLVMContext()),
          op.getN()));
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::CvtFloatToTF32Op>(opInst)) {

    auto intId = NVVM::CvtFloatToTF32Op::getIntrinsicID(op.getRnd(), op.getSat(), op.getRelu());
    moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, intId, {moduleTranslation.lookupValue(op.getSrc())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ElectSyncOp>(opInst)) {

    auto *resultTuple = createIntrinsicCall(builder,
        llvm::Intrinsic::nvvm_elect_sync, {builder.getInt32(0xFFFFFFFF)});
    // Extract the second value into moduleTranslation.mapValue(op.getPred())
    moduleTranslation.mapValue(op.getPred()) = builder.CreateExtractValue(resultTuple, 1);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg0Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg0,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg1Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg1,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg2Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg2,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg3Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg3,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg4Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg4,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg5Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg5,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg6Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg6,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg7Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg7,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg8Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg8,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg9Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg9,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg10Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg10,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg11Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg11,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg12Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg12,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg13Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg13,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg14Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg14,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg15Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg15,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg16Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg16,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg17Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg17,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg18Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg18,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg19Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg19,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg20Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg20,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg21Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg21,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg22Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg22,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg23Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg23,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg24Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg24,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg25Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg25,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg26Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg26,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg27Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg27,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg28Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg28,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg29Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg29,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg30Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg30,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::EnvReg31Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_envreg31,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::Exit>(opInst)) {

    createIntrinsicCall(builder, llvm::Intrinsic::nvvm_exit);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::FenceProxyAcquireOp>(opInst)) {

    createIntrinsicCall(
        builder,
        getUnidirectionalFenceProxyID(op.getFromProxy(), op.getToProxy(), op.getScope(), false),
        {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getSize())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::FenceProxyReleaseOp>(opInst)) {

    createIntrinsicCall(builder, getUnidirectionalFenceProxyID(
                                     op.getFromProxy(), op.getToProxy(), op.getScope(), true));
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::FenceScClusterOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_fence_sc_cluster);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GlobalTimerOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_globaltimer,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GridDimXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nctaid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GridDimYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nctaid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GridDimZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nctaid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GridIdOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_gridid,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GriddepcontrolLaunchDependentsOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_griddepcontrol_launch_dependents,0,{},{},{},{});
    (void) inst;
    
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::GriddepcontrolWaitOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_griddepcontrol_wait,0,{},{},{},{});
    (void) inst;
    
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LaneIdOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_laneid,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LaneMaskEqOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_eq,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LaneMaskGeOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_ge,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LaneMaskGtOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_gt,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LaneMaskLeOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_le,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LaneMaskLtOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_lt,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::LdMatrixOp>(opInst)) {

      auto operands = moduleTranslation.lookupValues(opInst.getOperands());
      auto intId = getLdMatrixIntrinsicId(op.getLayout(), op.getNum());
      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, intId, operands, {operands[0]->getType()});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierArriveNocompleteOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_arrive_noComplete, {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getCount())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierArriveNocompleteSharedOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_arrive_noComplete_shared, {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getCount())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierArriveOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_arrive, {moduleTranslation.lookupValue(op.getAddr())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierArriveSharedOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_arrive_shared, {moduleTranslation.lookupValue(op.getAddr())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierInitOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_init, {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getCount())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierInitSharedOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_init_shared, {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getCount())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierInvalOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_inval, {moduleTranslation.lookupValue(op.getAddr())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierInvalSharedOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_inval_shared, {moduleTranslation.lookupValue(op.getAddr())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierTestWaitOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_test_wait, {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getState())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MBarrierTestWaitSharedOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, llvm::Intrinsic::nvvm_mbarrier_test_wait_shared, {moduleTranslation.lookupValue(op.getAddr()), moduleTranslation.lookupValue(op.getState())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MapaOp>(opInst)) {

    int addrSpace = llvm::cast<LLVMPointerType>(op.getA().getType()).getAddressSpace();
    
    bool isSharedMemory = addrSpace == NVVM::NVVMMemorySpace::kSharedMemorySpace;

    auto intId = isSharedMemory? llvm::Intrinsic::nvvm_mapa_shared_cluster : llvm::Intrinsic::nvvm_mapa;
    moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, intId, {moduleTranslation.lookupValue(op.getA()), moduleTranslation.lookupValue(op.getB())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::MmaOp>(opInst)) {

    auto operands = moduleTranslation.lookupValues(opInst.getOperands());
    auto intId = mlir::NVVM::MmaOp::getIntrinsicID(
        op.getShape().getM(), op.getShape().getN(), op.getShape().getK(),
        op.getB1Op(), op.getIntOverflowBehavior(),
        op.getLayoutA(), op.getLayoutB(),
        *op.getMultiplicandAPtxType(),
        *op.getMultiplicandBPtxType(),
        op.accumPtxType(),
        op.resultPtxType());

    moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(
      builder, intId, operands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::RcpApproxFtzF32Op>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_rcp_approx_ftz_f,1,{},{},{},{});
    (void) inst;
    moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ReduxOp>(opInst)) {

      auto intId = getReduxIntrinsicId(moduleTranslation.convertType(op.getResult().getType()), op.getKind());
      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, intId, {moduleTranslation.lookupValue(op.getVal()), moduleTranslation.lookupValue(op.getMaskAndClamp())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::SetMaxRegisterOp>(opInst)) {

    auto intId = (op.getAction() == NVVM::SetMaxRegisterAction::increase) ?
      llvm::Intrinsic::nvvm_setmaxnreg_inc_sync_aligned_u32 :
      llvm::Intrinsic::nvvm_setmaxnreg_dec_sync_aligned_u32;

    createIntrinsicCall(builder, intId, builder.getInt32(op.getRegCount()));
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ShflOp>(opInst)) {

      auto intId = getShflIntrinsicId(
          moduleTranslation.convertType(op.getResult().getType()), op.getKind(), static_cast<bool>(op.getReturnValueAndIsValid()));
      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder,
          intId, {moduleTranslation.lookupValue(op.getThreadMask()), moduleTranslation.lookupValue(op.getVal()), moduleTranslation.lookupValue(op.getOffset()), moduleTranslation.lookupValue(op.getMaskAndClamp())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::SmDimOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nsmid,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::SmIdOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_smid,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::SyncWarpOp>(opInst)) {

      createIntrinsicCall(builder, llvm::Intrinsic::nvvm_bar_warp_sync, {moduleTranslation.lookupValue(op.getMask())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ThreadIdXOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_tid_x,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ThreadIdYOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_tid_y,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::ThreadIdZOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_tid_z,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::VoteBallotOp>(opInst)) {

      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder,
            llvm::Intrinsic::nvvm_vote_ballot_sync, {moduleTranslation.lookupValue(op.getMask()), moduleTranslation.lookupValue(op.getPred())});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WMMALoadOp>(opInst)) {

      auto operands = moduleTranslation.lookupValues(opInst.getOperands());
      auto intId = mlir::NVVM::WMMALoadOp::getIntrinsicID(
        op.getM(), op.getN(), op.getK(), op.getLayout(), op.getEltype(), op.getFrag());
      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, intId, operands, {operands[0]->getType()});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WMMAMmaOp>(opInst)) {

      auto operands = moduleTranslation.lookupValues(opInst.getOperands());
      auto intId = mlir::NVVM::WMMAMmaOp::getIntrinsicID(
        op.getM(), op.getN(), op.getK(), op.getLayoutA(), op.getLayoutB(), op.getEltypeA(), op.getEltypeB());
      moduleTranslation.mapValue(op.getRes()) = createIntrinsicCall(builder, intId, operands);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WMMAStoreOp>(opInst)) {

      auto operands = moduleTranslation.lookupValues(opInst.getOperands());
      auto intId =
        mlir::NVVM::WMMAStoreOp::getIntrinsicID(op.getM(), op.getN(), op.getK(), op.getLayout(), op.getEltype());
      createIntrinsicCall(builder, intId, operands, {operands[0]->getType()});
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WarpDimOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_nwarpid,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WarpIdOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_warpid,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WarpSizeOp>(opInst)) {

    auto *inst = LLVM::detail::createIntrinsicCall(
      builder, moduleTranslation, &opInst, llvm::Intrinsic::nvvm_read_ptx_sreg_warpsize,1,{},{},{},{});
    (void) inst;
    
    if (op.getRange()) {
      inst->addRangeRetAttr(::llvm::ConstantRange(
        op.getRange()->getLower(), op.getRange()->getUpper()));
    }
  moduleTranslation.mapValue(op.getRes()) = inst;
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WgmmaFenceAlignedOp>(opInst)) {

    createIntrinsicCall(builder, llvm::Intrinsic::nvvm_wgmma_fence_sync_aligned);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WgmmaGroupSyncAlignedOp>(opInst)) {

    createIntrinsicCall(builder, llvm::Intrinsic::nvvm_wgmma_commit_group_sync_aligned);
  
  return success();
}
if (auto op = dyn_cast<::mlir::NVVM::WgmmaWaitGroupSyncOp>(opInst)) {

    createIntrinsicCall(builder, llvm::Intrinsic::nvvm_wgmma_wait_group_sync_aligned, builder.getInt64(op.getGroup()));
  
  return success();
}
