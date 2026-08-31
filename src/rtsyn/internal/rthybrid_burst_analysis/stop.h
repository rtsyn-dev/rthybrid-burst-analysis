/**
 * @file rtsyn/internal/rthybrid_burst_analysis/stop.h
 * @brief stop callback declaration for RTHybrid Burst Analysis.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_STOP_H
#define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_STOP_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_stop(void *instance);
#ifdef __cplusplus
}
#endif
#endif
