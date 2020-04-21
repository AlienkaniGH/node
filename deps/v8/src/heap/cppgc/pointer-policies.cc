// Copyright 2020 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "include/cppgc/internal/pointer-policies.h"
#include "include/cppgc/internal/persistent-node.h"

#include "include/cppgc/internal/accessors.h"
#include "src/base/macros.h"
#include "src/heap/cppgc/heap.h"

namespace cppgc {
namespace internal {

EnabledCheckingPolicy::EnabledCheckingPolicy() {
  USE(impl_);
  // TODO(chromium:1056170): Save creating heap state.
}

void EnabledCheckingPolicy::CheckPointer(const void* ptr) {
  // TODO(chromium:1056170): Provide implementation.
}

PersistentRegion& StrongPersistentPolicy::GetPersistentRegion(void* object) {
  auto* heap = Heap::From(GetHeapFromPayload(object));
  return heap->GetStrongPersistentRegion();
}

PersistentRegion& WeakPersistentPolicy::GetPersistentRegion(void* object) {
  auto* heap = Heap::From(GetHeapFromPayload(object));
  return heap->GetWeakPersistentRegion();
}

}  // namespace internal
}  // namespace cppgc
