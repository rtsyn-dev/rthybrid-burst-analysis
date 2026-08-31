#include <math.h>
#include "rtsyn/internal/rthybrid_burst_analysis.h"
#include "rtsyn/internal/rthybrid_burst_analysis/set_param.h"
static double finite_or(double value, double fallback) { return isfinite(value) ? value : fallback; }
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_set_param(void *instance, uint32_t param_index, const void *value)
{
    rtsyn_rthybrid_burst_analysis_instance_t *self = (rtsyn_rthybrid_burst_analysis_instance_t *)instance;
    if (!self || !value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;

    switch (param_index) {
    case RTSYN_RTHYBRID_BURST_ANALYSIS_PARAM_OBSERVATION_TIME:
        self->observation_time = *(const double *)value > 0.001 ? *(const double *)value : 0.001;
        return RTSYN_ABI_STATUS_OK;
    default:
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }

}
