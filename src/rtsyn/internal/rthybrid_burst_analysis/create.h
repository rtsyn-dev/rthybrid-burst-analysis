/**
 * @file rtsyn/internal/rthybrid_burst_analysis/create.h
 * @brief create callback declaration for RTHybrid Burst Analysis.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_CREATE_H
#define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_CREATE_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_create(void **out_instance);
#ifdef __cplusplus
}
#endif
#endif
