#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

typedef struct {
    int distance[COL]; //текущее расстояние до вершины
    int visited[COL]; //посещенные вершины
    int prev[COL]; //хранит  номер предшествующей вершины
} Dijkstra;

Dijkstra* shortest_path(int graphp[][COL], int src);
void path_print(Dijkstra *dijkstra, int vertex, int src);

#endif //DIJKSTRA_H_