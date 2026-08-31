# RTHybrid Burst Analysis

Tracks voltage extrema and burst duration over an observation window.

This is a C RTSyn module ported from the older RTHybrid RTSyn plugin tree. Load the module by selecting this
repository's `xmake.lua`; the RTSyn module loader will build the shared library and load the descriptor.

## Build

```sh
RTSYN_WORKSPACE=/home/seregio/Desktop/stuff/projects/rtsyn xmake f -c -y
RTSYN_WORKSPACE=/home/seregio/Desktop/stuff/projects/rtsyn xmake
```
