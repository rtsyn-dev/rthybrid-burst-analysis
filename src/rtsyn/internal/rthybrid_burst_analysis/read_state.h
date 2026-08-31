/**
 * @file rtsyn/internal/rthybrid_burst_analysis/read_state.h
 * @brief read_state callback declaration for RTHybrid Burst Analysis.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_READ_STATE_H
#define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_READ_STATE_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_read_state(const void *instance, uint32_t state_index, void *out_value);
#ifdef __cplusplus
}
#endif
#endif
