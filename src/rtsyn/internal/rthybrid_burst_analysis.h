/**
     * @file rtsyn/internal/rthybrid_burst_analysis.h
     * @brief Internal state for the RTHybrid Burst Analysis module.
     *
     * SPDX-License-Identifier: GPL-3.0-or-later
     */
    #ifndef RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_H
    #define RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_H

    #include <stddef.h>
    #include <stdint.h>

    #ifdef __cplusplus
    extern "C" {
    #endif

    typedef struct rtsyn_rthybrid_burst_analysis_instance_s {
        double observation_time;
double vm;
double min;
double max;
double temp_min;
double temp_max;
double count;
double thresh_up;
double thresh_down;
double range;
double pts_counter;
double burst_counter;
double is_burst;
double burst_dur_sum;
double old_burst_time;
double sec_per_burst;
double out_min;
double out_max;
double out_burst_duration;
    } rtsyn_rthybrid_burst_analysis_instance_t;

    typedef enum rtsyn_rthybrid_burst_analysis_instance_ports_e : uint32_t {
        RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_VM_V = 0,
RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_MIN_V = 1,
RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_MAX_V = 2,
RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_BURST_DURATION_S = 3,
        RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_COUNT = 4,
    } rtsyn_rthybrid_burst_analysis_instance_ports_t;

    typedef enum rtsyn_rthybrid_burst_analysis_instance_params_e : uint32_t {
        RTSYN_RTHYBRID_BURST_ANALYSIS_PARAM_OBSERVATION_TIME = 0,
        RTSYN_RTHYBRID_BURST_ANALYSIS_PARAM_COUNT = 1,
    } rtsyn_rthybrid_burst_analysis_instance_params_t;

    typedef enum rtsyn_rthybrid_burst_analysis_instance_states_e : uint32_t {
        RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_OUT_MIN = 0,
RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_OUT_MAX = 1,
RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_MIN = 2,
RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_MAX = 3,
RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_TEMP_MIN = 4,
RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_TEMP_MAX = 5,
        RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_COUNT = 6,
    } rtsyn_rthybrid_burst_analysis_instance_states_t;

    #ifdef __cplusplus
    }
    #endif

    #endif /* RTSYN_INTERNAL_RTHYBRID_BURST_ANALYSIS_H */
