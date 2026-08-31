#include <math.h>
#include <stdlib.h>
#include "rtsyn/internal/rthybrid_burst_analysis.h"
#include "rtsyn/internal/rthybrid_burst_analysis/create.h"

rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_create(void **out_instance)
{
    if (!out_instance) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    rtsyn_rthybrid_burst_analysis_instance_t *self = (rtsyn_rthybrid_burst_analysis_instance_t *)malloc(sizeof(rtsyn_rthybrid_burst_analysis_instance_t));
    if (!self) return RTSYN_ABI_STATUS_ERROR;

    self->observation_time = 5.0;
    self->vm = 0.0;
    self->min = 0.0;
    self->max = 0.0;
    self->temp_min = 999999.0;
    self->temp_max = -999999.0;
    self->count = 0.0;
    self->thresh_up = 0.0;
    self->thresh_down = 0.0;
    self->range = 0.0;
    self->pts_counter = 0.0;
    self->burst_counter = -1.0;
    self->is_burst = 1.0;
    self->burst_dur_sum = 0.0;
    self->old_burst_time = 0.0;
    self->sec_per_burst = 0.0;
    self->out_min = 0.0;
    self->out_max = 0.0;
    self->out_burst_duration = 0.0;

    *out_instance = self;
    return RTSYN_ABI_STATUS_OK;
}
