#include <stddef.h>
        #include "rtsyn/rthybrid_burst_analysis.h"
        #include "rtsyn/internal/rthybrid_burst_analysis.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/create.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/destroy.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/process.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/read_state.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/set_param.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/start.h"
        #include "rtsyn/internal/rthybrid_burst_analysis/stop.h"

        static const rtsyn_abi_port_descriptor_t rtsyn_rthybrid_burst_analysis_ports[RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_COUNT] = {
            [RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_VM_V] =
        {
            .name = "Vm (V)",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_MIN_V] =
        {
            .name = "Min (V)",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_MAX_V] =
        {
            .name = "Max (V)",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_BURST_DURATION_S] =
        {
            .name = "Burst duration (s)",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
        };

        static const rtsyn_abi_param_descriptor_t rtsyn_rthybrid_burst_analysis_params[RTSYN_RTHYBRID_BURST_ANALYSIS_PARAM_COUNT] = {
    [RTSYN_RTHYBRID_BURST_ANALYSIS_PARAM_OBSERVATION_TIME] =
        {
            .name = "observation_time",
            .description = "Observation window in seconds",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_state_descriptor_t rtsyn_rthybrid_burst_analysis_states[RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_COUNT] = {
    [RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_OUT_MIN] =
        {
            .name = "out_min",
            .description = "Published minimum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_OUT_MAX] =
        {
            .name = "out_max",
            .description = "Published maximum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_MIN] =
        {
            .name = "min",
            .description = "Window minimum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_MAX] =
        {
            .name = "max",
            .description = "Window maximum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_TEMP_MIN] =
        {
            .name = "temp_min",
            .description = "Temporary minimum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_TEMP_MAX] =
        {
            .name = "temp_max",
            .description = "Temporary maximum",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_node_descriptor_t rtsyn_rthybrid_burst_analysis_descriptor = {
            .name = "rthybrid_burst_analysis",
            .node_type = RTSYN_ABI_NODE_PLUGIN,
            .port_count = RTSYN_RTHYBRID_BURST_ANALYSIS_PORT_COUNT,
            .ports = rtsyn_rthybrid_burst_analysis_ports,
            .param_count = RTSYN_RTHYBRID_BURST_ANALYSIS_PARAM_COUNT,
            .params = rtsyn_rthybrid_burst_analysis_params,
            .state_count = RTSYN_RTHYBRID_BURST_ANALYSIS_STATE_COUNT,
            .states = rtsyn_rthybrid_burst_analysis_states,
            .callbacks = {
                .create = rtsyn_rthybrid_burst_analysis_create,
                .set_param = rtsyn_rthybrid_burst_analysis_set_param,
                .read_state = rtsyn_rthybrid_burst_analysis_read_state,
                .start = rtsyn_rthybrid_burst_analysis_start,
                .process = rtsyn_rthybrid_burst_analysis_process,
                .stop = rtsyn_rthybrid_burst_analysis_stop,
                .destroy = rtsyn_rthybrid_burst_analysis_destroy,
            },
        };

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_get_descriptor(void)
        {
            return &rtsyn_rthybrid_burst_analysis_descriptor;
        }

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_module_get_descriptor(void)
        {
            return rtsyn_rthybrid_burst_analysis_get_descriptor();
        }
