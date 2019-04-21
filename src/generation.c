#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h> 
#include "generation.h"

void init_graph()
{   
    for (uint8_t i = 0; i < RAW; i++) {
        for (uint8_t j = 0; j < COL; j++) {
            graph[i][j] = 0;
        }
    }
}

void generation_graph()
{
    init_graph();
    num_nil();
    uint8_t edge1 = rand() % RAW - 0;
    uint8_t edge2 = rand() % COL - 0;
    uint8_t weighted;

    //нужно для того чтобы создать связный граф.
    for (uint8_t i = 0; i < RAW; i++) {            
        edge1 = rand() % RAW - 0;
        while (edge1 == i || graph[edge1][i] != 0) {
            edge1 = rand() % RAW - 0;
        }
        weighted = rand() % 10;
        graph[i][edge1] = weighted;
        graph[edge1][i] = weighted;
    }

    for (uint8_t i = 0; i < 160; i++) {
        edge1 = rand() % RAW - 0;
        edge2 = rand() % COL - 0;
        while (graph[edge1][edge2] != 0) {
            edge1 = rand() % RAW - 0;
            edge2 = rand() % COL - 0;
        }
        weighted = rand() % 10;
        graph[edge1][edge2] = weighted;
        graph[edge2][edge1] = weighted;
    }
}

void print_graph()
{
    for (uint8_t i = 0; i < RAW; i++) {
        for (uint8_t j = 0; j < COL; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void num_nil() 
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
