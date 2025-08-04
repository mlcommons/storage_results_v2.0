if (intrinsicID == llvm::Intrinsic::nvvm_barrier0) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {};
    auto op = odsBuilder.create<::mlir::NVVM::Barrier0Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapNoResultOp(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_ntid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockDimXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_ntid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockDimYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_ntid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockDimZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_ctaid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockIdXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_ctaid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockIdYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_ctaid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockIdZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctaid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockInClusterIdXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctaid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockInClusterIdYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctaid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::BlockInClusterIdZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_clock64) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::Clock64Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_clock) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClockOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctarank) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDim>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctaid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDimBlocksXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctaid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDimBlocksYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_nctaid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDimBlocksZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nclusterid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDimXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nclusterid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDimYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nclusterid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterDimZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_cluster_ctarank) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterId>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_clusterid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterIdXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_clusterid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterIdYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_clusterid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ClusterIdZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg0) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg0Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg1) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg1Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg2) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg2Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg3) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg3Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg4) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg4Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg5) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg5Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg6) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg6Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg7) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg7Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg8) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg8Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg9) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg9Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg10) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg10Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg11) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg11Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg12) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg12Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg13) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg13Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg14) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg14Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg15) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg15Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg16) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg16Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg17) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg17Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg18) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg18Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg19) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg19Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg20) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg20Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg21) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg21Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg22) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg22Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg23) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg23Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg24) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg24Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg25) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg25Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg26) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg26Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg27) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg27Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg28) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg28Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg29) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg29Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg30) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg30Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_envreg31) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::EnvReg31Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_globaltimer) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::GlobalTimerOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nctaid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::GridDimXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nctaid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::GridDimYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nctaid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::GridDimZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_gridid) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::GridIdOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_griddepcontrol_launch_dependents) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {};
    auto op = odsBuilder.create<::mlir::NVVM::GriddepcontrolLaunchDependentsOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapNoResultOp(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_griddepcontrol_wait) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {};
    auto op = odsBuilder.create<::mlir::NVVM::GriddepcontrolWaitOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapNoResultOp(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_laneid) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::LaneIdOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_eq) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::LaneMaskEqOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_ge) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::LaneMaskGeOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_gt) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::LaneMaskGtOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_le) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::LaneMaskLeOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_lanemask_lt) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::LaneMaskLtOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_rcp_approx_ftz_f) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::RcpApproxFtzF32Op>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nsmid) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::SmDimOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_smid) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::SmIdOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_tid_x) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ThreadIdXOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_tid_y) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ThreadIdYOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_tid_z) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::ThreadIdZOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_nwarpid) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::WarpDimOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_warpid) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::WarpIdOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
if (intrinsicID == llvm::Intrinsic::nvvm_read_ptx_sreg_warpsize) {


    SmallVector<Value> mlirOperands;
    SmallVector<NamedAttribute> mlirAttrs;
    if (failed(moduleImport.convertIntrinsicArguments(
      llvmOperands,
      llvmOpBundles,
      false,
      {},
      {},
      mlirOperands,
      mlirAttrs))
    ) {
      return failure();
    }
    SmallVector<Type> resultTypes =
    {moduleImport.convertType(inst->getType())};
    auto op = odsBuilder.create<::mlir::NVVM::WarpSizeOp>(
      moduleImport.translateLoc(inst->getDebugLoc()), resultTypes, mlirOperands, mlirAttrs);
    
    // Note: we don't want to look in to the declaration here.
    auto rangeAttr = inst->getAttributes().getRetAttr(::llvm::Attribute::Range);
    if (rangeAttr.isValid()) {
      const ::llvm::ConstantRange& value = rangeAttr.getValueAsConstantRange();
      op.setRangeAttr(::mlir::LLVM::ConstantRangeAttr::get(odsBuilder.getContext(), value.getLower(), value.getUpper()));
    }
  moduleImport.mapValue(inst) = op;
  return success();
}
