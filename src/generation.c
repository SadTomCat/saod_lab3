#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h> 
#include "include/generation.h"

void graph_init(int graph[][COL])
{   
    for (int i = 0; i < RAW; i++) {
        for (int j = 0; j < COL; j++) {
            graph[i][j] = 0;
        }
    }
}

void graph_generation(int graph[][COL])
{
    graph_init(graph);

    int node1 = rand() % RAW - 0;
    int node2 = rand() % COL - 0;
    int weighted;

    //нужно для того чтобы создать связный граф.
    for (int i = 0; i < RAW; i++) {            
        node1 = rand() % RAW - 0;

        while (node1 == i || graph[node1][i] != 0) {
            node1 = rand() % RAW - 0;
        }

        weighted = rand() % 10;
        graph[i][node1] = weighted;
        graph[node1][i] = weighted;
    }

    for (int i = 0; i < 90; i++) {
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

void graph_print(int graph[][COL])
{
    for (int i = 0; i <= RAW; i++) {
        if (i != RAW) {
            if (i < 10) {
                printf("%d |  ", i);
            } else {
                printf("%d|  ", i);
            }

            for (int j = 0; j < COL; j++) {
                printf("%d  ", graph[i][j]);
            }

        } else {
            printf("    ");
            
            for (int j = 0; j < COL; j++) {
                printf("---");
            }
        }

        printf("\n");
    }

    printf("     ");

    for (int i = 0; i < COL; i++) {
        
        if (i < 10) {
            printf("%d  ", i);
        } else {
            printf("%d ", i);
        }
    }
 
    printf("\n\n");
}

void num_nil(int graph[][COL]) 
{
    int nil = 0;

    for (int i = 0; i < RAW; i++) {
        for (int j = 0; j < COL; j++) {
            if (graph[i][j] == 0) {
                nil++;
            }
        }
    }

    printf("Number nil %d\n", nil); 
}

