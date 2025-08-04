/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ROCDLOps.td                                                          *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace ROCDL {

class ROCDLDialect : public ::mlir::Dialect {
  explicit ROCDLDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~ROCDLDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("rocdl");
  }

  /// Parse an attribute registered to this dialect.
  ::mlir::Attribute parseAttribute(::mlir::DialectAsmParser &parser,
                                   ::mlir::Type type) const override;

  /// Print an attribute registered to this dialect.
  void printAttribute(::mlir::Attribute attr,
                      ::mlir::DialectAsmPrinter &os) const override;

    /// Provides a hook for verifying dialect attributes attached to the given
    /// op.
    ::llvm::LogicalResult verifyOperationAttribute(
        ::mlir::Operation *op, ::mlir::NamedAttribute attribute) override;

    /// Helper to manage the discardable attribute `kernel`.
    class KernelAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.kernel";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      KernelAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::UnitAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::UnitAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::UnitAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::UnitAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::UnitAttr>(name));
       op->removeAttr(name);
     }
   };
   KernelAttrHelper getKernelAttrHelper() {
     return kernelAttrName;
   }
 private:
   KernelAttrHelper kernelAttrName;
 public:

    /// Helper to manage the discardable attribute `reqd_work_group_size`.
    class ReqdWorkGroupSizeAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.reqd_work_group_size";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      ReqdWorkGroupSizeAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::DenseI32ArrayAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::DenseI32ArrayAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::DenseI32ArrayAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::DenseI32ArrayAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::DenseI32ArrayAttr>(name));
       op->removeAttr(name);
     }
   };
   ReqdWorkGroupSizeAttrHelper getReqdWorkGroupSizeAttrHelper() {
     return reqdWorkGroupSizeAttrName;
   }
 private:
   ReqdWorkGroupSizeAttrHelper reqdWorkGroupSizeAttrName;
 public:

    /// Helper to manage the discardable attribute `flat_work_group_size`.
    class FlatWorkGroupSizeAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.flat_work_group_size";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      FlatWorkGroupSizeAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::StringAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::StringAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::StringAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::StringAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::StringAttr>(name));
       op->removeAttr(name);
     }
   };
   FlatWorkGroupSizeAttrHelper getFlatWorkGroupSizeAttrHelper() {
     return flatWorkGroupSizeAttrName;
   }
 private:
   FlatWorkGroupSizeAttrHelper flatWorkGroupSizeAttrName;
 public:

    /// Helper to manage the discardable attribute `max_flat_work_group_size`.
    class MaxFlatWorkGroupSizeAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.max_flat_work_group_size";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      MaxFlatWorkGroupSizeAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::IntegerAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::IntegerAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::IntegerAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::IntegerAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::IntegerAttr>(name));
       op->removeAttr(name);
     }
   };
   MaxFlatWorkGroupSizeAttrHelper getMaxFlatWorkGroupSizeAttrHelper() {
     return maxFlatWorkGroupSizeAttrName;
   }
 private:
   MaxFlatWorkGroupSizeAttrHelper maxFlatWorkGroupSizeAttrName;
 public:

    /// Helper to manage the discardable attribute `waves_per_eu`.
    class WavesPerEuAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.waves_per_eu";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      WavesPerEuAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::IntegerAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::IntegerAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::IntegerAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::IntegerAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::IntegerAttr>(name));
       op->removeAttr(name);
     }
   };
   WavesPerEuAttrHelper getWavesPerEuAttrHelper() {
     return wavesPerEuAttrName;
   }
 private:
   WavesPerEuAttrHelper wavesPerEuAttrName;
 public:

    /// Helper to manage the discardable attribute `unsafe_fp_atomics`.
    class UnsafeFpAtomicsAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.unsafe_fp_atomics";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      UnsafeFpAtomicsAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::BoolAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::BoolAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::BoolAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::BoolAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::BoolAttr>(name));
       op->removeAttr(name);
     }
   };
   UnsafeFpAtomicsAttrHelper getUnsafeFpAtomicsAttrHelper() {
     return unsafeFpAtomicsAttrName;
   }
 private:
   UnsafeFpAtomicsAttrHelper unsafeFpAtomicsAttrName;
 public:

    /// Helper to manage the discardable attribute `last_use`.
    class LastUseAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.last_use";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      LastUseAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::UnitAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::UnitAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::UnitAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::UnitAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::UnitAttr>(name));
       op->removeAttr(name);
     }
   };
   LastUseAttrHelper getLastUseAttrHelper() {
     return lastUseAttrName;
   }
 private:
   LastUseAttrHelper lastUseAttrName;
 public:

    /// Helper to manage the discardable attribute `no_remote_memory`.
    class NoRemoteMemoryAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.no_remote_memory";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      NoRemoteMemoryAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::UnitAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::UnitAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::UnitAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::UnitAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::UnitAttr>(name));
       op->removeAttr(name);
     }
   };
   NoRemoteMemoryAttrHelper getNoRemoteMemoryAttrHelper() {
     return noRemoteMemoryAttrName;
   }
 private:
   NoRemoteMemoryAttrHelper noRemoteMemoryAttrName;
 public:

    /// Helper to manage the discardable attribute `no_fine_grained_memory`.
    class NoFineGrainedMemoryAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.no_fine_grained_memory";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      NoFineGrainedMemoryAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::UnitAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::UnitAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::UnitAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::UnitAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::UnitAttr>(name));
       op->removeAttr(name);
     }
   };
   NoFineGrainedMemoryAttrHelper getNoFineGrainedMemoryAttrHelper() {
     return noFineGrainedMemoryAttrName;
   }
 private:
   NoFineGrainedMemoryAttrHelper noFineGrainedMemoryAttrName;
 public:

    /// Helper to manage the discardable attribute `ignore_denormal_mode`.
    class IgnoreDenormalModeAttrHelper {
      ::mlir::StringAttr name;
    public:
      static constexpr ::llvm::StringLiteral getNameStr() {
        return "rocdl.ignore_denormal_mode";
      }
      constexpr ::mlir::StringAttr getName() {
        return name;
      }

      IgnoreDenormalModeAttrHelper(::mlir::MLIRContext *ctx)
        : name(::mlir::StringAttr::get(ctx, getNameStr())) {}

     ::mlir::UnitAttr getAttr(::mlir::Operation *op) {
       return op->getAttrOfType<::mlir::UnitAttr>(name);
     }
     void setAttr(::mlir::Operation *op, ::mlir::UnitAttr val) {
       op->setAttr(name, val);
     }
     bool isAttrPresent(::mlir::Operation *op) {
       return op->hasAttrOfType<::mlir::UnitAttr>(name);
     }
     void removeAttr(::mlir::Operation *op) {
       assert(op->hasAttrOfType<::mlir::UnitAttr>(name));
       op->removeAttr(name);
     }
   };
   IgnoreDenormalModeAttrHelper getIgnoreDenormalModeAttrHelper() {
     return ignoreDenormalModeAttrName;
   }
 private:
   IgnoreDenormalModeAttrHelper ignoreDenormalModeAttrName;
 public:

    /// Get the name of the attribute used to annotate external kernel
    /// functions.
    static StringRef getKernelFuncAttrName() { return "rocdl.kernel"; }
    static constexpr ::llvm::StringLiteral getFlatWorkGroupSizeAttrName() {
      return ::llvm::StringLiteral("rocdl.flat_work_group_size");
    }
    static constexpr ::llvm::StringLiteral getReqdWorkGroupSizeAttrName() {
      return ::llvm::StringLiteral("rocdl.reqd_work_group_size");
    }
    /// MLIR's gpu-related infrastructure effectively assume uniform workgroup
    /// sizes, so this attribute defaults to "true" on `rocdl.kernel` functions.
    /// It is provided here to allow overriding this assumption.
    static constexpr ::llvm::StringLiteral getUniformWorkGroupSizeAttrName() {
      return ::llvm::StringLiteral("rocdl.uniform_work_group_size");
    }

    /// The address space value that represents global memory.
    static constexpr unsigned kGlobalMemoryAddressSpace = 1;
    /// The address space value that represents shared memory.
    static constexpr unsigned kSharedMemoryAddressSpace = 3;
    /// The address space value that represents private memory.
    static constexpr unsigned kPrivateMemoryAddressSpace = 5;
  };
} // namespace ROCDL
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::ROCDL::ROCDLDialect)
