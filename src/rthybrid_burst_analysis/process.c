#include <math.h>
#include <string.h>
#include "rtsyn/internal/rthybrid_burst_analysis.h"
#include "rtsyn/internal/rthybrid_burst_analysis/process.h"

static double period_seconds_from_context(const rtsyn_abi_runtime_context_t *context)
{
    if (!context || context->period_ns == 0U) return 0.001;
    return (double)context->period_ns / 1000000000.0;
}

static int read_f64(const rtsyn_abi_runtime_context_t *context, uint32_t port_index, double *out_value)
{
    if (!context || !context->api || !context->api->read || !out_value) return 0;
    double value = 0.0;
    if (context->api->read(context, port_index, &value) != RTSYN_ABI_STATUS_OK) return 0;
    if (!isfinite(value)) return 0;
    *out_value = value;
    return 1;
}

static void clamp_f64(double *value, double fallback)
{
    if (!isfinite(*value)) {
        *value = fallback;
    } else if (fabs(*value) > 1e6) {
        *value = *value > 0.0 ? 1e6 : -1e6;
    }
}

typedef void (*rtsyn_rk4_deriv_fn_t)(const double *state, double *deriv, void *user_data);
static void rk4_step(double *state, size_t n, double dt, rtsyn_rk4_deriv_fn_t deriv_fn, void *user_data)
{
    double k1[8] = {0};
    double k2[8] = {0};
    double k3[8] = {0};
    double k4[8] = {0};
    double tmp[8] = {0};
    if (!state || !deriv_fn || n == 0 || n > 8 || dt <= 0.0) return;
    deriv_fn(state, k1, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + 0.5 * dt * k1[i];
    deriv_fn(tmp, k2, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + 0.5 * dt * k2[i];
    deriv_fn(tmp, k3, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + dt * k3[i];
    deriv_fn(tmp, k4, user_data);
    for (size_t i = 0; i < n; ++i) state[i] += (dt / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
}



rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_process(void *instance, const rtsyn_abi_runtime_context_t *context)
{
    rtsyn_rthybrid_burst_analysis_instance_t *self = (rtsyn_rthybrid_burst_analysis_instance_t *)instance;
    if (!self || !context || !context->api || !context->api->write)
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;

    (void)read_f64(context, RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_VM_V, &self->vm);
    const double period_seconds = period_seconds_from_context(context);
    double time_s = self->count * period_seconds;
    double freq = 1.0 / period_seconds;
    if (time_s > self->observation_time) {
        self->min = self->temp_min;
        self->max = self->temp_max;
        if (isfinite(self->min) && isfinite(self->max)) {
            self->out_min = self->min;
            self->out_max = self->max;
        }
        self->temp_min = 999999.0;
        self->temp_max = -999999.0;
        self->count = 0.0;
        self->sec_per_burst = self->burst_counter > 0.0 ? (self->burst_dur_sum / self->burst_counter) / freq : 0.0;
        self->out_burst_duration = isfinite(self->sec_per_burst) ? self->sec_per_burst : 0.0;
        self->pts_counter = 0.0;
        self->burst_counter = 0.0;
        self->burst_dur_sum = 0.0;
        self->old_burst_time = 0.0;
    }
    if (self->vm < self->temp_min) self->temp_min = self->vm;
    if (self->vm > self->temp_max) self->temp_max = self->vm;
    self->range = self->max - self->min;
    self->thresh_down = self->min + (self->range * 0.1);
    self->thresh_up = self->min + (self->range * 0.9);
    if (self->is_burst == 0.0 && self->vm > self->thresh_up) {
        self->is_burst = 1.0;
        self->burst_counter += 1.0;
        self->burst_dur_sum += self->pts_counter - self->old_burst_time;
        self->old_burst_time = self->pts_counter;
    } else if (self->is_burst == 1.0 && self->vm < self->thresh_down) {
        self->is_burst = 0.0;
    }
    self->pts_counter += 1.0;
    self->count += 1.0;
    (void)context->api->write(context, RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_MIN_V, &self->out_min);
    (void)context->api->write(context, RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_MAX_V, &self->out_max);
    (void)context->api->write(context, RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_BURST_DURATION_S, &self->out_burst_duration);
    return RTSYN_ABI_STATUS_OK;

}
