#ifndef HEAP_H_
#define HEAP_H_

typedef struct {
    int key; //для приоритета в очереди
    int value; //значение ребра
} HeapNode;

typedef struct {
    int max_size;
    int num_nodes;

    HeapNode *nodes;
} Heap;

void free_heap(Heap* buf); //
HeapNode *heap_min(Heap* buf); //
Heap *heap_create(int max_size); //
void heap_extract_min(Heap* buf); //
void heapify(Heap* buf, int index); //
void heap_swap(HeapNode* a, HeapNode* b); //
void heap_insert(Heap* buf, int key, int value); //
int heap_decrease_key(Heap* buf, int value, int new_key, int size); //

#endif //HEAP_H_