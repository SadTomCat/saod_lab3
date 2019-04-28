#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h> 
#include "include/generation.h"

void graph_init(uint8_t graph[][COL])
{   
    for (uint8_t i = 0; i < RAW; i++) {
        for (uint8_t j = 0; j < COL; j++) {
            graph[i][j] = 0;
        }
    }
}

void graph_generation(uint8_t graph[][COL])
{
    graph_init(graph);

    uint8_t node1 = rand() % RAW - 0;
    uint8_t node2 = rand() % COL - 0;
    uint8_t weighted;

    //нужно для того чтобы создать связный граф.
    for (uint8_t i = 0; i < RAW; i++) {            
        node1 = rand() % RAW - 0;

        while (node1 == i || graph[node1][i] != 0) {
            node1 = rand() % RAW - 0;
        }

        weighted = rand() % 10;
        graph[i][node1] = weighted;
        graph[node1][i] = weighted;
    }

    for (uint8_t i = 0; i < 160; i++) {
        node1 = rand() % RAW - 0;
        node2 = rand() % COL - 0;

        while (graph[node1][node2] != 0) {
            node1 = rand() % RAW - 0;
            node2 = rand() % COL - 0;
        }

        weighted = rand() % 10;
        graph[node1][node2] = weighted;
        graph[node2][node1] = weighted;
    }
}

void graph_print(uint8_t graph[][COL])
{
    for (uint8_t i = 0; i < RAW; i++) {
        for (uint8_t j = 0; j < COL; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}

void num_nil(uint8_t graph[][COL]) 
{
    uint16_t nil = 0;

    for (uint8_t i = 0; i < RAW; i++) {
        for (uint8_t j = 0; j < COL; j++) {
            if (graph[i][j] == 0) {
                nil++;
            }
        }
    }

    printf("Number nil %d\n", nil); 
}

