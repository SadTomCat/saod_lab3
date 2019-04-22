#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include "include/generation.h"
#include "include/Dijkstra.h" 

void init() {
    done[0] = 0;
    visited[0] = 0;
    prev[0] = -1;
    
    for (uint8_t i = 1; i < RAW; i++) {
        done[i] = INT8_MAX;
        visited[i] = 1;
        prev[0] = -1;
    }
}

void dijkstra()
{
    uint8_t node1 = 0;
    uint8_t node2 = 0;
    uint8_t min;
    
    init();

    for (uint8_t i = 0; i < RAW; i++) {
        
    }
}