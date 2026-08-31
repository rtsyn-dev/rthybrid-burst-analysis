#include "rtsyn/internal/rthybrid_burst_analysis.h"
#include "rtsyn/internal/rthybrid_burst_analysis/read_state.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_read_state(const void *instance, uint32_t state_index, void *out_value)
{
    const rtsyn_rthybrid_burst_analysis_instance_t *self = (const rtsyn_rthybrid_burst_analysis_instance_t *)instance;
    if (!self || !out_value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    switch (state_index) {

    case RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_OUT_MIN: *(double *)out_value = self->out_min; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_OUT_MAX: *(double *)out_value = self->out_max; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_MIN: *(double *)out_value = self->min; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_MAX: *(double *)out_value = self->max; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_TEMP_MIN: *(double *)out_value = self->temp_min; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_TEMP_MAX: *(double *)out_value = self->temp_max; return RTSYN_ABI_STATUS_OK;

    default:
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
}
