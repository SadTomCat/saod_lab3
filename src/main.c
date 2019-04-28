#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <limits.h>
#include "include/generation.h"
#include "include/Dijkstra.h"
#include "include/heap.h"


int printmas(int intmas[][RAW]);

int main() 
{   
    srand(time(NULL));
    int graph[RAW][COL];
    int lattice_graph[100][100];
    graph_generation(graph);
    graph_print(graph);
    Dijkstra *test = shortest_path(graph, 6);
    
    for (int i = 0; i < COL; i++) {
        printf("%d distance: %d, prev: %d, visited %d\n", i, test->distance[i], test->prev[i], test->visited[i]);
    }
    printf("\n");
    path_print(test, 13, 6);
    return 0;

}
