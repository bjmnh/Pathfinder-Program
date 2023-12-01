/*
Author: Ben Hanson
Date: 11/8/22
Description: This code outlines functions for graph algorithms
*/

#pragma once

using namespace std;

struct Graph
{
    int V;                 //# of vertices
    struct AdjList *array; // array of ADJ Lists
    float *dist;
    int *parent;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct AdjListNode
{
    int index;
    int start;
    int dest;
    float weight;
    struct AdjListNode *next;
};

struct Graph *createGraph(int);
struct AdjListNode *newAdjListNode(int index, int start, int dest, float weight);
void addEdge(struct Graph *graph, int ind, int src, int dest, float weight);
void printPath(struct Graph *graph, int t, int j);
void printLength(struct Graph *graph, int t, int j);
void dijkstraA(struct Graph *graph, int source, int dest);
void printGraph(struct Graph *graph);
