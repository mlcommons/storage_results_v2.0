/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Rewriters                                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: Combine.td                                                           *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

static ::llvm::LogicalResult static_dag_matcher_0(::mlir::PatternRewriter &rewriter, ::mlir::Operation *op0, ::llvm::SmallVector<::mlir::Operation *, 4> &tblgen_ops, ::mlir::IntegerAttr &maxNumImpreciseAcc, ::mlir::triton::InputPrecisionAttr &inputPrecision, ::mlir::Operation::operand_range &c, ::mlir::Operation::operand_range &b, ::mlir::Operation::operand_range &a, ::mlir::triton::DotOp &res) {
  (void)tblgen_ops;
  auto castedOp1 = ::llvm::dyn_cast<::mlir::triton::DotOp>(op0); (void)castedOp1;
  if (!(castedOp1)){
    return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
      diag << "castedOp1 is not ::mlir::triton::DotOp type";
    });
  }
  res = castedOp1;
  a = castedOp1.getODSOperands(0);
  b = castedOp1.getODSOperands(1);
  c = castedOp1.getODSOperands(2);
  {
    auto tblgen_attr = op0->getAttrOfType<::mlir::triton::InputPrecisionAttr>("inputPrecision");(void)tblgen_attr;
    if (!tblgen_attr) tblgen_attr = ::mlir::triton::InputPrecisionAttr::get(rewriter.getContext(), ::mlir::triton::InputPrecision::IEEE);
    inputPrecision = tblgen_attr;
  }
  {
    auto tblgen_attr = op0->getAttrOfType<::mlir::IntegerAttr>("maxNumImpreciseAcc");(void)tblgen_attr;
    if (!tblgen_attr) tblgen_attr = rewriter.getIntegerAttr(rewriter.getIntegerType(32), 0);
    maxNumImpreciseAcc = tblgen_attr;
  }
  return ::mlir::success();
}

/* Generated from:
    external/triton/lib/Dialect/Triton/Transforms/Combine.td:42
*/
struct CombineAddPtrPattern : public ::mlir::RewritePattern {
  CombineAddPtrPattern(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("tt.addptr", 2, context, {"arith.addi", "tt.addptr"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::Operation::operand_range idx1(op0->getOperands());
    ::mlir::Operation::operand_range idx0(op0->getOperands());
    ::mlir::Operation::operand_range ptr(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::triton::AddPtrOp>(op0); (void)castedOp0;
    {
      auto *op1 = (*castedOp0.getODSOperands(0).begin()).getDefiningOp();
      if (!(op1)){
        return rewriter.notifyMatchFailure(castedOp0, [&](::mlir::Diagnostic &diag) {
          diag << "There's no operation that defines operand 0 of castedOp0";
        });
      }
      auto castedOp1 = ::llvm::dyn_cast<::mlir::triton::AddPtrOp>(op1); (void)castedOp1;
      if (!(castedOp1)){
        return rewriter.notifyMatchFailure(op1, [&](::mlir::Diagnostic &diag) {
          diag << "castedOp1 is not ::mlir::triton::AddPtrOp type";
        });
      }
      ptr = castedOp1.getODSOperands(0);
      idx0 = castedOp1.getODSOperands(1);
      tblgen_ops.push_back(op1);
    }
    idx1 = castedOp0.getODSOperands(1);
    if (!((isAddPtrOffsetCombinable((*idx0.begin()), (*idx1.begin()))))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'idx0, idx1' failed to satisfy constraint: ''";
      });
    }

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc(), tblgen_ops[1]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::arith::AddIOp tblgen_AddIOp_0;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*idx0.begin()));
      tblgen_values.push_back((*idx1.begin()));
      if (auto tmpAttr = ::mlir::arith::IntegerOverflowFlagsAttr::get(rewriter.getContext(), ::mlir::arith::IntegerOverflowFlags::none)) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("overflowFlags"), tmpAttr);
      }
      tblgen_AddIOp_0 = rewriter.create<::mlir::arith::AddIOp>(odsLoc, tblgen_values, tblgen_attrs);
    }
    ::mlir::triton::AddPtrOp tblgen_AddPtrOp_1;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*ptr.begin()));
      tblgen_values.push_back((*tblgen_AddIOp_0.getODSResults(0).begin()));
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_AddPtrOp_1 = rewriter.create<::mlir::triton::AddPtrOp>(odsLoc, tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_AddPtrOp_1.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/triton/lib/Dialect/Triton/Transforms/Combine.td:19
*/
struct CombineDotAddFPattern : public ::mlir::RewritePattern {
  CombineDotAddFPattern(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("arith.addf", 2, context, {"tt.dot"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::arith::FastMathFlagsAttr fastmath;
    ::mlir::IntegerAttr maxNumImpreciseAcc;
    ::mlir::triton::InputPrecisionAttr inputPrecision;
    ::mlir::Operation::operand_range c(op0->getOperands());
    ::mlir::Operation::operand_range b(op0->getOperands());
    ::mlir::triton::DotOp res;
    ::mlir::Operation::operand_range a(op0->getOperands());
    ::mlir::Operation::operand_range d(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::arith::AddFOp>(op0); (void)castedOp0;
    d = castedOp0.getODSOperands(0);
    {
      auto *op1 = (*castedOp0.getODSOperands(1).begin()).getDefiningOp();
      if (!(op1)){
        return rewriter.notifyMatchFailure(castedOp0, [&](::mlir::Diagnostic &diag) {
          diag << "There's no operation that defines operand 1 of castedOp0";
        });
      }
      if(::mlir::failed(static_dag_matcher_0(rewriter, op1, tblgen_ops, maxNumImpreciseAcc, inputPrecision, c, b, a, res))) {
        return ::mlir::failure();
      }
      tblgen_ops.push_back(op1);
    }
    {
      auto tblgen_attr = op0->getAttrOfType<::mlir::arith::FastMathFlagsAttr>("fastmath");(void)tblgen_attr;
      if (!tblgen_attr) tblgen_attr = ::mlir::arith::FastMathFlagsAttr::get(rewriter.getContext(), ::mlir::arith::FastMathFlags::none);
      fastmath = tblgen_attr;
    }
    if (!((isZero((*c.begin()))))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'c' failed to satisfy constraint: ''";
      });
    }
    if (!((::llvm::cast<::mlir::IntegerAttr>(maxNumImpreciseAcc).getInt() == 0))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'maxNumImpreciseAcc' failed to satisfy constraint: ''";
      });
    }
    if (!((res->hasOneUse()))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities '' failed to satisfy constraint: 'dot result has a single use'";
      });
    }

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc(), tblgen_ops[1]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::triton::DotOp tblgen_DotOp_0;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*a.begin()));
      tblgen_values.push_back((*b.begin()));
      tblgen_values.push_back((*d.begin()));
      if (auto tmpAttr = inputPrecision) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("inputPrecision"), tmpAttr);
      }
      if (auto tmpAttr = maxNumImpreciseAcc) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("maxNumImpreciseAcc"), tmpAttr);
      }
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_DotOp_0 = rewriter.create<::mlir::triton::DotOp>((*res.getODSResults(0).begin()).getLoc(), tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_DotOp_0.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/triton/lib/Dialect/Triton/Transforms/Combine.td:31
*/
struct CombineDotAddFRevPattern : public ::mlir::RewritePattern {
  CombineDotAddFRevPattern(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("arith.addf", 2, context, {"tt.dot"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::arith::FastMathFlagsAttr fastmath;
    ::mlir::IntegerAttr maxNumImpreciseAcc;
    ::mlir::triton::InputPrecisionAttr inputPrecision;
    ::mlir::Operation::operand_range c(op0->getOperands());
    ::mlir::Operation::operand_range b(op0->getOperands());
    ::mlir::Operation::operand_range d(op0->getOperands());
    ::mlir::Operation::operand_range a(op0->getOperands());
    ::mlir::triton::DotOp res;
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::arith::AddFOp>(op0); (void)castedOp0;
    {
      auto *op1 = (*castedOp0.getODSOperands(0).begin()).getDefiningOp();
      if (!(op1)){
        return rewriter.notifyMatchFailure(castedOp0, [&](::mlir::Diagnostic &diag) {
          diag << "There's no operation that defines operand 0 of castedOp0";
        });
      }
      if(::mlir::failed(static_dag_matcher_0(rewriter, op1, tblgen_ops, maxNumImpreciseAcc, inputPrecision, c, b, a, res))) {
        return ::mlir::failure();
      }
      tblgen_ops.push_back(op1);
    }
    d = castedOp0.getODSOperands(1);
    {
      auto tblgen_attr = op0->getAttrOfType<::mlir::arith::FastMathFlagsAttr>("fastmath");(void)tblgen_attr;
      if (!tblgen_attr) tblgen_attr = ::mlir::arith::FastMathFlagsAttr::get(rewriter.getContext(), ::mlir::arith::FastMathFlags::none);
      fastmath = tblgen_attr;
    }
    if (!((isZero((*c.begin()))))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'c' failed to satisfy constraint: ''";
      });
    }
    if (!((::llvm::cast<::mlir::IntegerAttr>(maxNumImpreciseAcc).getInt() == 0))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'maxNumImpreciseAcc' failed to satisfy constraint: ''";
      });
    }
    if (!((res->hasOneUse()))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities '' failed to satisfy constraint: 'dot result has a single use'";
      });
    }

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc(), tblgen_ops[1]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::triton::DotOp tblgen_DotOp_0;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*a.begin()));
      tblgen_values.push_back((*b.begin()));
      tblgen_values.push_back((*d.begin()));
      if (auto tmpAttr = inputPrecision) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("inputPrecision"), tmpAttr);
      }
      if (auto tmpAttr = maxNumImpreciseAcc) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("maxNumImpreciseAcc"), tmpAttr);
      }
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_DotOp_0 = rewriter.create<::mlir::triton::DotOp>((*res.getODSResults(0).begin()).getLoc(), tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_DotOp_0.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/triton/lib/Dialect/Triton/Transforms/Combine.td:14
*/
struct CombineDotAddIPattern : public ::mlir::RewritePattern {
  CombineDotAddIPattern(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("arith.addi", 2, context, {"tt.dot"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::arith::IntegerOverflowFlagsAttr overflow;
    ::mlir::IntegerAttr maxNumImpreciseAcc;
    ::mlir::triton::InputPrecisionAttr inputPrecision;
    ::mlir::Operation::operand_range c(op0->getOperands());
    ::mlir::Operation::operand_range b(op0->getOperands());
    ::mlir::triton::DotOp res;
    ::mlir::Operation::operand_range a(op0->getOperands());
    ::mlir::Operation::operand_range d(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::arith::AddIOp>(op0); (void)castedOp0;
    d = castedOp0.getODSOperands(0);
    {
      auto *op1 = (*castedOp0.getODSOperands(1).begin()).getDefiningOp();
      if (!(op1)){
        return rewriter.notifyMatchFailure(castedOp0, [&](::mlir::Diagnostic &diag) {
          diag << "There's no operation that defines operand 1 of castedOp0";
        });
      }
      if(::mlir::failed(static_dag_matcher_0(rewriter, op1, tblgen_ops, maxNumImpreciseAcc, inputPrecision, c, b, a, res))) {
        return ::mlir::failure();
      }
      tblgen_ops.push_back(op1);
    }
    {
      auto tblgen_attr = op0->getAttrOfType<::mlir::arith::IntegerOverflowFlagsAttr>("overflowFlags");(void)tblgen_attr;
      if (!tblgen_attr) tblgen_attr = ::mlir::arith::IntegerOverflowFlagsAttr::get(rewriter.getContext(), ::mlir::arith::IntegerOverflowFlags::none);
      overflow = tblgen_attr;
    }
    if (!((isZero((*c.begin()))))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'c' failed to satisfy constraint: ''";
      });
    }
    if (!((res->hasOneUse()))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities '' failed to satisfy constraint: 'dot result has a single use'";
      });
    }

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc(), tblgen_ops[1]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::triton::DotOp tblgen_DotOp_0;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*a.begin()));
      tblgen_values.push_back((*b.begin()));
      tblgen_values.push_back((*d.begin()));
      if (auto tmpAttr = inputPrecision) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("inputPrecision"), tmpAttr);
      }
      if (auto tmpAttr = maxNumImpreciseAcc) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("maxNumImpreciseAcc"), tmpAttr);
      }
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_DotOp_0 = rewriter.create<::mlir::triton::DotOp>((*res.getODSResults(0).begin()).getLoc(), tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_DotOp_0.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/triton/lib/Dialect/Triton/Transforms/Combine.td:26
*/
struct CombineDotAddIRevPattern : public ::mlir::RewritePattern {
  CombineDotAddIRevPattern(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("arith.addi", 2, context, {"tt.dot"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::arith::IntegerOverflowFlagsAttr overflow;
    ::mlir::IntegerAttr maxNumImpreciseAcc;
    ::mlir::triton::InputPrecisionAttr inputPrecision;
    ::mlir::Operation::operand_range c(op0->getOperands());
    ::mlir::Operation::operand_range b(op0->getOperands());
    ::mlir::Operation::operand_range d(op0->getOperands());
    ::mlir::Operation::operand_range a(op0->getOperands());
    ::mlir::triton::DotOp res;
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::arith::AddIOp>(op0); (void)castedOp0;
    {
      auto *op1 = (*castedOp0.getODSOperands(0).begin()).getDefiningOp();
      if (!(op1)){
        return rewriter.notifyMatchFailure(castedOp0, [&](::mlir::Diagnostic &diag) {
          diag << "There's no operation that defines operand 0 of castedOp0";
        });
      }
      if(::mlir::failed(static_dag_matcher_0(rewriter, op1, tblgen_ops, maxNumImpreciseAcc, inputPrecision, c, b, a, res))) {
        return ::mlir::failure();
      }
      tblgen_ops.push_back(op1);
    }
    d = castedOp0.getODSOperands(1);
    {
      auto tblgen_attr = op0->getAttrOfType<::mlir::arith::IntegerOverflowFlagsAttr>("overflowFlags");(void)tblgen_attr;
      if (!tblgen_attr) tblgen_attr = ::mlir::arith::IntegerOverflowFlagsAttr::get(rewriter.getContext(), ::mlir::arith::IntegerOverflowFlags::none);
      overflow = tblgen_attr;
    }
    if (!((isZero((*c.begin()))))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities 'c' failed to satisfy constraint: ''";
      });
    }
    if (!((res->hasOneUse()))){
      return rewriter.notifyMatchFailure(op0, [&](::mlir::Diagnostic &diag) {
        diag << "entities '' failed to satisfy constraint: 'dot result has a single use'";
      });
    }

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc(), tblgen_ops[1]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::triton::DotOp tblgen_DotOp_0;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*a.begin()));
      tblgen_values.push_back((*b.begin()));
      tblgen_values.push_back((*d.begin()));
      if (auto tmpAttr = inputPrecision) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("inputPrecision"), tmpAttr);
      }
      if (auto tmpAttr = maxNumImpreciseAcc) {
        tblgen_attrs.emplace_back(rewriter.getStringAttr("maxNumImpreciseAcc"), tmpAttr);
      }
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_DotOp_0 = rewriter.create<::mlir::triton::DotOp>((*res.getODSResults(0).begin()).getLoc(), tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_DotOp_0.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

void LLVM_ATTRIBUTE_UNUSED populateWithGenerated(::mlir::RewritePatternSet &patterns) {
  patterns.add<CombineAddPtrPattern>(patterns.getContext());
  patterns.add<CombineDotAddFPattern>(patterns.getContext());
  patterns.add<CombineDotAddFRevPattern>(patterns.getContext());
  patterns.add<CombineDotAddIPattern>(patterns.getContext());
  patterns.add<CombineDotAddIRevPattern>(patterns.getContext());
}
