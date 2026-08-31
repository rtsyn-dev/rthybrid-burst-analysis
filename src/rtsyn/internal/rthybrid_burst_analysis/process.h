/**
 * @file rtsyn/internal/rthybrid_burst_analysis/process.h
 * @brief process callback declaration for RTHybrid Burst Analysis.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_PROCESS_H
#define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_PROCESS_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_process(void *instance, const rtsyn_abi_runtime_context_t *context);
#ifdef __cplusplus
}
#endif
#endif
