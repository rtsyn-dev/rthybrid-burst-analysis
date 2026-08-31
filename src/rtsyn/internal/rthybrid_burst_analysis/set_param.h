/**
 * @file rtsyn/internal/rthybrid_burst_analysis/set_param.h
 * @brief set_param callback declaration for RTHybrid Burst Analysis.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_SET_PARAM_H
#define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_SET_PARAM_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_set_param(void *instance, uint32_t param_index, const void *value);
#ifdef __cplusplus
}
#endif
#endif
