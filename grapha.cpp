/*
Author: Ben Hanson
Date: 11/8/22
Description: This code implements functions for graph algorithms
*/

#include <cfloat>
#include <iostream>
#include "minheap.h"
#include "grapha.h"
#include "stack.h"

using namespace std;

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V + 1;
    graph->array = (struct AdjList *)malloc((V + 1) * sizeof(struct AdjList));
    graph->dist = (float *)malloc((V + 1) * sizeof(float));
    graph->parent = (int *)malloc((V + 1) * sizeof(int));

    for (int i = 0; i <= V; ++i) // initialize array of adjlists
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

struct AdjListNode *newAdjListNode(int index, int start, int dest, float weight)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->index = index;
    newNode->start = start;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

void addEdge(struct Graph *graph, int ind, int source, int dest, float weight)
{
    struct AdjListNode *newNode = newAdjListNode(ind, source, dest, weight);
    newNode->next = graph->array[source].head; // push the head back one
    graph->array[source].head = newNode;       // new head is this node that was just created
}

void printPath(struct Graph *graph, int t, int j) // print
{
    int y = j;
    int x;

    if (graph->dist[j] == FLT_MAX || graph->dist[j] < 0 || !graph->parent[j]) // if unreachable from source
    {
        fprintf(stdout, "There is no path from %d to %d.\n", t, j);
    }
    else
    {
        struct Stack *stack;
        stack = createStack(graph->V);
        do
        {
            push(stack, y);
            x = y;
            y = graph->parent[y];

        } while (y != -1);

        fprintf(stdout, "The shortest path from %d to %d is:\n", x, j);

        while (stack->top > -1)
        {
            int z = pop(stack);
            // cout << "[" << z << ":    " << graph->dist[z] << ".00]";
            fprintf(stdout, "[%d:%8.2f]", z, graph->dist[z]);
            if (stack->top > -1)
            {
                cout << "-->";
            }
            else
            {
                cout << "." << endl;
            }
        }
    }
}

void printLength(struct Graph *graph, int t, int j)
{
    if (graph->dist[j] == FLT_MAX || graph->dist[j] < 0 || !graph->parent[j]) // if unreachable from source
    {
        fprintf(stdout, "There is no path from %d to %d.\n", t, j);
    }
    else
    {
        fprintf(stdout, "The length of the shortest path from %d to %d is: %8.2f\n", t, j, graph->dist[j]);
    }
}

void dijkstraA(struct Graph *graph, int source, int dest) // O(ELogV) function
{
    int V = graph->V;

    struct MinHeap *minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v)
    {
        graph->dist[v] = FLT_MAX;
        minHeap->array[v] = newMinHeapNode(v, graph->dist[v]);
        minHeap->pos[v] = v;
    }

    graph->parent[source] = -1;
    minHeap->array[source] = newMinHeapNode(source, graph->dist[source]);
    minHeap->pos[source] = source;
    graph->dist[source] = 0;
    decreaseKey(minHeap, source, graph->dist[source]);
    minHeap->size = V;

    while (!isEmpty(minHeap))
    {
        struct MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        // go through adjacent vertices of the extracted vertext to update
        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
            if (inHeap(minHeap, v) && graph->dist[u] != FLT_MAX && pCrawl->weight + graph->dist[u] < graph->dist[v])
            {
                graph->parent[v] = u;
                graph->dist[v] = graph->dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, graph->dist[v]); // update min heap
            }
            pCrawl = pCrawl->next;
        }
    }
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 1; v < graph->V; ++v) // loop through all vertices starting at 1
    {
        fprintf(stdout, "ADJ[%d]:", v);
        struct AdjListNode *t = graph->array[v].head;
        while (t != NULL) // base case, stop when the linked list is over
        {

            fprintf(stdout, "-->[%d %d: %4.2f]", t->start, t->dest, t->weight);
            // cout << t->start << " " << t->dest << ": " << t->weight << ".00]";
            t = t->next; // crawl through the linked list ie go to next node to print out
        }
        cout << endl;
    }
}