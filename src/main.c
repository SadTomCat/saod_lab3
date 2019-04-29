#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
#include <limits.h>
#include "include/generation.h"
#include "include/Dijkstra.h"
#include "include/heap.h"

double wtime();

int main() 
{   
    srand(time(NULL));
    int graph[RAW][COL];
    //common graph
    graph_generation(graph);
    graph_print(graph);

    double start = wtime();
    Dijkstra *test = shortest_path(graph, 0);
    double end = wtime();
    printf("time: %.10f\n\n", end - start);

    for (int i = 0; i < COL; i++) {
        printf("%d distance: %d, prev: %d, visited %d\n", i, test->distance[i], test->prev[i], test->visited[i]);
    }

    printf("\n");
    for (int i = 1; i < COL; i++) {
        path_print(test, i, 0);
    }

    //lattice graph

    return 0;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}