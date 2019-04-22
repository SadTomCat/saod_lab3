#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "include/heap.h"

Heap *heap_create(uint8_t max_size)
{
    Heap *buf;
    buf = malloc(sizeof(*buf));

    if (buf != NULL) {
        buf->max_size = max_size;
        buf->num_nodes = 0;
        buf->nodes = malloc(sizeof(*buf->nodes) * (max_size));

        if (buf->nodes == 0) {
            printf("ERROR: No memory for nodes has been allocated\n");
            free(buf);
            return NULL;
        }

        return buf;
    }

    printf("ERROR: No memory for heap has been allocated\n");
    return NULL;
}

void heap_insert(Heap* buf, uint8_t key, uint8_t value)
{
    if (buf == NULL) {
        printf("ERROR: Heap == NULL");
        return;
    }

    if (buf->num_nodes >= buf->max_size) {
        printf("ERROR: heap will overflow, element wasn't insert\n");
        return;
    }

    buf->nodes[buf->num_nodes].value = value;
    buf->nodes[buf->num_nodes].key = key;
    buf->num_nodes++;

    for (uint8_t i = buf->num_nodes - 1; i > 0 && buf->nodes[i].key < buf->nodes[(i - 1) / 2].key; i = (i - 1) / 2) {
        heap_swap(&buf->nodes[i], &buf->nodes[(i - 1) / 2]);
    }
}

void heap_extract_min(Heap* buf)
{
    if (buf->num_nodes == 0) {
        printf("ERROR: number nodes == 0\n");
        return;
    }

    HeapNode heap_min = buf->nodes[0];
    buf->nodes[0] = buf->nodes[buf->num_nodes - 1];
    heapify(buf, 0);
}

void heapify(Heap* buf, uint8_t index)
{
    uint8_t left;
    uint8_t right;
    uint8_t less;

    while (1) {
        left = (2 * index) + 1;
        right = (2 * index) + 2;
        less = index;

        if (buf->nodes[less].key > buf->nodes[left].key && left < buf->nodes) {
            less = left; 
        }

        if (buf->nodes[less].key > buf->nodes[right].key && right < buf->nodes) {
            less = right; 
        }

        if (less == index) {
            break;
        }

        heap_swap(&buf->nodes[less], &buf->nodes[index]);
        index = less;
    }
    
}

int heap_increase_key(Heap* buf, uint8_t index, uint8_t new_key)
{
    if (buf->nodes[index].key <= new_key) {
        printf("ERROR: New key more than old key");
        return - 1;
    }

    buf->nodes[index].key = new_key;

    while (buf->nodes[index].key < buf->nodes[(index - 1) / 2].key && index > 0) {
        heap_swap(&buf->nodes[index], &buf->nodes[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    return index;
}

HeapNode *heap_min(Heap* buf)
{
    if (buf->nodes == 0) {
        printf("ERROR: Number nodes == 0\n");
        return NULL;
    }

    return &buf->nodes[0];
} 

void heap_swap(HeapNode* a, HeapNode* b)
{   
    HeapNode tmp = *a;
    *a = *b;
    *b = tmp;
}

void free_heap(Heap* buf)
{
    free(buf->nodes);
    free(buf);
}
