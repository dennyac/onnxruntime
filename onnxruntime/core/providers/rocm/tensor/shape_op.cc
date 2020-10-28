// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "core/providers/cpu/tensor/shape_op.h"
#include "core/providers/rocm/rocm_fwd.h"

namespace onnxruntime {
namespace rocm {

ONNX_OPERATOR_VERSIONED_KERNEL_EX(
    Shape,
    kOnnxDomain,
    1, 12,
    kRocmExecutionProvider,
    KernelDefBuilder()
        // properly force CPU/GPU synch inside the kernel
        .OutputMemoryType<OrtMemTypeCPUInput>(0)
        .TypeConstraint("T", DataTypeImpl::AllFixedSizeTensorTypes())
        .TypeConstraint("T1", DataTypeImpl::GetTensorType<int64_t>()),
    Shape);

ONNX_OPERATOR_KERNEL_EX(
    Shape,
    kOnnxDomain,
    13,
    kRocmExecutionProvider,
    KernelDefBuilder()
        // properly force CPU/GPU synch inside the kernel
        .OutputMemoryType<OrtMemTypeCPUInput>(0)
        .TypeConstraint("T", DataTypeImpl::AllFixedSizeTensorTypes())
        .TypeConstraint("T1", DataTypeImpl::GetTensorType<int64_t>()),
    Shape);

}  // namespace rocm
}  // namespace onnxruntime