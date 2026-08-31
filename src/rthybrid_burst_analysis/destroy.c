#include <stdlib.h>
#include "rtsyn/internal/rthybrid_burst_analysis.h"
#include "rtsyn/internal/rthybrid_burst_analysis/destroy.h"
void RTSYN_ABI_CALL rtsyn_rthybrid_burst_analysis_destroy(void *instance)
{
    free((rtsyn_rthybrid_burst_analysis_instance_t *)instance);
}
