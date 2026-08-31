#include "rtsyn/internal/rthybrid_burst_analysis.h"
#include "rtsyn/internal/rthybrid_burst_analysis/stop.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_stop(void *instance)
{
    return instance ? RTSYN_ABI_STATUS_OK : RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}
