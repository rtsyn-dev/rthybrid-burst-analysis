/**
 * @file rtsyn/internal/rthybrid_burst_analysis/start.h
 * @brief start callback declaration for RTHybrid Burst Analysis.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_START_H
#define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_START_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_start(void *instance);
#ifdef __cplusplus
}
#endif
#endif
