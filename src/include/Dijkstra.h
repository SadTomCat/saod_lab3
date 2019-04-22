#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

uint8_t done[RAW]; //текущее расстояние до вершины
uint8_t visited[RAW]; //посещенные вершины
int prev[RAW]; //хранит  номер предшествующей вершины

void init();
void dijkstra();
void print_path(uint8_t vertex);

#endif //DIJKSTRA_H_