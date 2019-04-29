#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <stdlib.h>
#include "include/generation.h"
#include "include/heap.h"
#include "include/Dijkstra.h" 


Dijkstra* shortest_path(int graph[][COL], int src)
{
    HeapNode *buf;
    HeapNode node;
    Heap *queue;
    Dijkstra *shortest = malloc(sizeof(*shortest));

    queue = heap_create(COL);
    shortest->distance[src] = 0;
    shortest->prev[src] = -1;
    shortest->visited[src] = -1;
    heap_insert(queue, shortest->distance[src], src);

    for (int i = 0; i < COL; i++) {
        if (i != src) {
            shortest->distance[i] = INT32_MAX;
            shortest->prev[i] = -1;
            shortest->visited[i] = -1;
            heap_insert(queue, INT32_MAX, i);
        }
    }
    
    for (int i = 0; i < RAW; i++) {
        buf = heap_min(queue);
        shortest->visited[buf->value] = 0;
        node = *buf;
        heap_extract_min(queue);

        for (int j = 0; j < COL; j++) {
            if ((shortest->distance[j] > shortest->distance[node.value] + 
            graph[node.value][j]) && graph[node.value][j] != 0) {
                shortest->distance[j] = shortest->distance[node.value] + graph[node.value][j];
                shortest->prev[j] = node.value;
                heap_decrease_key(queue, j, shortest->distance[j]);
            }
        }    
    }

    free_heap(queue);

    return shortest;
}

void path_print(Dijkstra *dijkstra, int vertex, int src) 
{
    int path_len = 1;
    int i = 0;
    int current_vertex = vertex;
    
    while (current_vertex != src) {
        path_len++;
        current_vertex = dijkstra->prev[current_vertex]; 
    }

    int path[path_len];
    path_len--;
    current_vertex = vertex;
    
    while (current_vertex != src) {
        path[path_len - i] = current_vertex;
        i++;
        current_vertex = dijkstra->prev[current_vertex];
    }
    path[0] = src;

    for (int i = 0; i < path_len; i++) {
        printf("%d-->", path[i]);
    }
    printf("%d\n", path[path_len]);
}
