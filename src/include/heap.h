#ifndef HEAP_H_
#define HEAP_H_

typedef struct {
    uint8_t key; //для приоритета в очереди
    uint8_t value; //значение ребра
} HeapNode;

typedef struct {
    uint8_t max_size;
    uint8_t num_nodes;

    HeapNode *nodes;
} Heap;

Heap *heap_create(uint8_t max_size);
void heap_swap(HeapNode* a, HeapNode* b);
void heap_insert(Heap *buf, uint8_t key, uint8_t *value);
HeapNode heap_extract_min(Heap *buf);
void heap_heapify(Heap *buf, uint8_t index);
HeapNode *heap_min(Heap *buf);
void free_heap(Heap* buf);

#endif //HEAP_H_