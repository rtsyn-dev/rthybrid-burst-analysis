/**
 * @file rtsyn/rthybrid_burst_analysis.h
 * @brief Public descriptor access for the RTHybrid Burst Analysis module.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */
#ifndef RTSYN_RTHYBRID_BURST_ANALYSIS_H
#define RTSYN_RTHYBRID_BURST_ANALYSIS_H

#include <rtsyn/abi.h>

#ifdef __cplusplus
extern "C" {
#endif

RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_get_descriptor(void);

#ifdef __cplusplus
}
#endif

#endif /* RTSYN_RTHYBRID_BURST_ANALYSIS_H */
