/*
Author: Ben Hanson
Date: 11/8/22
Description: This code implements a Navigation System
Usage: <exe> <GraphType> <InputFile>
*/

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "grapha.h"
#include "minheap.h"
#include "stack.h"

using namespace std;

int main(int argc, char **argv)
{
    // Check CMD line arguments
    if (argc != 3 || (strcmp(argv[1], "Directed") != 0 && strcmp(argv[1], "Undirected")))
    {
        fprintf(stderr, "Usage: ./PJ3 <GraphType> <InputFile>\n");
        return 0;
    }

    int graphType = 1; // Directed Default
    if ((strcmp(argv[1], "Undirected") == 0))
    {
        graphType = 2; // Undirected
    }

    struct Graph *graph;
    ifstream ifile(argv[2]);
    if (ifile.is_open()) // read from file, set up adj list and dynamically allocate data
    {
        float inpHolder[2]; // holds <#vertices> <#edges>
        float edges[4];     // holds <index> <start> <end> <weight>

        ifile >> inpHolder[0];
        ifile >> inpHolder[1];

        graph = createGraph(inpHolder[0]);

        int p = 1;
        while (p <= inpHolder[1])
        {
            p++;

            for (int i = 0; i < 4; i++)
            {
                ifile >> edges[i];
            }

            addEdge(graph, edges[0], edges[1], edges[2], edges[3]); // adds edge <index> <start> <end> <weight>

            if (graphType == 2)
            {
                addEdge(graph, edges[2], edges[2], edges[1], edges[3]); // adds complementary edge if undirected
            }
        }
        ifile.close();
    }
    else
    {
        fprintf(stderr, "File not found\n");
        return 0;
    }

    string input1;
    char input[50];
    int inp[2];
    int i, source, dest, temp_int;
    while (i != 0)
    {
        getline(cin, input1);

        stringstream str_strm;
        str_strm << input1; // convert the string input1 into stringstream
        string temp_str;

        int k = 0;
        inp[0] = -1;
        inp[1] = -1;

        str_strm >> input;

        while (!str_strm.eof())
        {
            str_strm >> temp_str; // take words into temp_str one by one
            if (stringstream(temp_str) >> temp_int)
            {                        // try to convert string to int
                inp[k++] = temp_int; // load inputs
            }
            temp_str = ""; // clear temp string
        }
        // printf("Input %s recieved!\n", input);
        if (strcmp(input, "Stop") == 0)
        {
            i = 0;
            break;
        }
        else if (strcmp(input, "SinglePair") == 0) // SinglePair <source> <destination>
        {
            if (inp[0] == -1 || inp[1] == -1)
            {
                // fprintf(stderr, "Invalid command.\n");
            }
            else
            {
                source = inp[0];
                dest = inp[1];
                dijkstraA(graph, source, dest);
            }
        }
        else if (strcmp(input, "SingleSource") == 0) // SingleSource <source>
        {
            if (inp[0] == -1)
            {
                // fprintf(stderr, "Invalid command.\n");
            }
            else
            {
                source = inp[0];
                dijkstraA(graph, source, graph->V - dest + 1);
            }
        }
        else if (strcmp(input, "PrintPath") == 0) // PrintPath <s> <t>
        {
            if (inp[0] == -1 || inp[0] != source || inp[1] == -1)
            {
                // fprintf(stderr, "Invalid command.\n");
            }
            else
            {
                source = inp[0];
                dest = inp[1];
                printPath(graph, source, dest);
            }
        }
        else if (strcmp(input, "PrintLength") == 0) // PrintLength <s> <t>
        {
            if (inp[0] == -1 || inp[0] != source || inp[1] == -1)
            {
                // fprintf(stderr, "Invalid command.\n");
            }
            else
            {
                source = inp[0];
                dest = inp[1];
                printLength(graph, source, dest);
            }
        }
        else if (strcmp(input, "PrintADJ") == 0) // PrintADJ
        {
            printGraph(graph);
        }
        else // default
        {
            // fprintf(stderr, "Invalid command.\n");
        }
    }
}
