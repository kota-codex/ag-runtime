#ifndef AG_ARRAY_BASE_IMPL_H_
#define AG_ARRAY_BASE_IMPL_H_
#include "ag-ffi-header/array/array-base.h"
#include "ag-ffi-header/runtime.h"

// Inserts empty elements into a container
void ag_insert_into_container(AgBaseArray* c, uint64_t at, uint64_t items_count);

// Removes elements from a container (no dispose)
void ag_delete_container_items(AgBaseArray* b, uint64_t index, uint64_t count);

#endif // AG_ARRAY_BASE_IMPL_H_
