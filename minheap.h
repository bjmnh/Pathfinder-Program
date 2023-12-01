/*
Author: Ben Hanson
Date: 11/8/22
Description: This code outlines a minheap
*/
#pragma once

struct MinHeapNode
{
    int v;       // node number
    float dist; // best dist from source (right now)
};
struct MinHeap
{
    int size;
    int capacity;
    int *pos; // for decreaseKey()
    struct MinHeapNode **array;
};

struct MinHeapNode *newMinHeapNode(int v, float dist);
struct MinHeap *createMinHeap(int capacity);
void swapNode(struct MinHeapNode **a, struct MinHeapNode **b);
void minHeapify(struct MinHeap *minHeap, int index);
int isEmpty(struct MinHeap *minHeap);
struct MinHeapNode *extractMin(struct MinHeap *minHeap);
void decreaseKey(struct MinHeap *minHeap, int v, float dist);
bool inHeap(struct MinHeap *minHeap, int v);