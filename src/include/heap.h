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

void free_heap(Heap* buf); //
HeapNode *heap_min(Heap* buf); //
Heap *heap_create(uint8_t max_size); //
void heap_extract_min(Heap* buf); //
void heapify(Heap* buf, uint8_t index); //
void heap_swap(HeapNode* a, HeapNode* b); //
void heap_insert(Heap* buf, uint8_t key, uint8_t value); //
int heap_increase_key(Heap* buf, uint8_t index, uint8_t new_key); //

#endif //HEAP_H_