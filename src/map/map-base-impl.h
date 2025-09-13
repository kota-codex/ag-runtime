#ifndef AK_MAP_BASE_IMPL_H_
#define AK_MAP_BASE_IMPL_H_

// Declarations used by all Map types
//
// Open addressed
// Pow_2 grow
// Linear probe
// Robinhood hashing
//

#include "ag-ffi-header/map/map-base.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t ag_map_find_index(
    AgMap* map,
    AgObject* key,
    size_t hash);

// Inserts the prelocked key-value, starting at pos `i`.
// It is guaranteed that `key` is not in the map
void ag_map_insert(
    AgMap* map,
    size_t    i,
    uint64_t  dist,
    int64_t   hash,
    AgObject* key,
    AgMapVal  value);

AgObject* ag_map_key_at(
    AgMap* map,
    uint64_t index);

void ag_map_clear(
    AgMap* map,
    void(*val_disposer)(AgMapVal));

AgMapVal ag_map_set_at(
    AgMap* map,
    AgObject* key,
    AgMapVal value);

AgMapVal ag_map_delete(
    AgMap* map,
    AgObject* key);

#define AG_MAP_COPY(VAL_COPIER)                                                     \
    AgMap* s = (AgMap*)src;                                                         \
    AgMap* d = (AgMap*)dst;                                                         \
    d->capacity = s->capacity;                                                      \
    d->size = s->size;                                                              \
    d->buckets = ag_alloc(s->capacity * sizeof(AgMapBucket));                       \
    ag_memcpy(d->buckets, s->buckets, s->capacity * sizeof(AgMapBucket));           \
    for (AgMapBucket* i = d->buckets, *n = d->buckets + d->capacity; i < n; i++) {  \
        if (i->key) {                                                               \
            ag_retain_shared(i->key);                                               \
            VAL_COPIER;                                                             \
        }                                                                           \
    }                                                                               \

#define AG_MAP_VISIT(VAL_VISITOR)                                                   \
    if (ag_not_null(map) && map->buckets) {                                         \
        AgMapBucket* i = map->buckets;                                              \
        AgMapBucket* term = i + map->capacity;                                      \
        for (; i < term; i++) {                                                     \
            if (i->key) {                                                           \
                visitor(&i->key, AG_VISIT_OWN, ctx);                                \
                VAL_VISITOR;                                                        \
            }                                                                       \
        }                                                                           \
    }

#ifdef __cplusplus
}  // extern "C"
#endif

#endif // AK_MAP_BASE_IMPL_H_
