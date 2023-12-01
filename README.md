# PathFinder Program

The PathFinder program is a command-line application developed for graph analysis, showcasing skills in algorithm implementation, data structures, and system design. Utilizing Dijkstra's algorithm, the program offers efficient path-finding solutions in a graph, demonstrating understanding of computational theory and practical application.

## Key Features

The program is designed to handle a variety of commands for graph processing, emphasizing algorithmic efficiency, accuracy, and robust error handling.

### Commands

#### `Stop`
- **Function**: Terminates the program.
- **Syntax**: `Stop`

#### `SinglePair <source> <destination>`
- **Function**: Computes shortest path from `source` to `destination`.
- **Syntax**: `SinglePair <source> <destination>`
- **Output**: Updates path weights and predecessors for vertices.

#### `SingleSource <source>`
- **Function**: Calculates shortest paths from a single source to all reachable vertices.
- **Syntax**: `SingleSource <source>`
- **Output**: Detailed path information for each vertex.

#### `PrintPath <s> <t>`
- **Function**: Outputs the shortest path from `s` to `t`.
- **Syntax**: `PrintPath <s> <t>`
- **Conditions**: Valid if `<s>` matches the source of the last path computation.
- **Output**: Path details or a no-path-found message.

#### `PrintLength <s> <t>`
- **Function**: Displays the length of the shortest path from `s` to `t`.
- **Syntax**: `PrintLength <s> <t>`
- **Output**: Path length or a no-path-found message.

#### `PrintADJ`
- **Function**: Prints the adjacency lists of the graph.
- **Syntax**: `PrintADJ`
- **Output**: Graph's adjacency lists.

#### Handling Invalid Commands
- **Function**: Manages unrecognized inputs.
- **Syntax**: Any non-specified command.
- **Output**: Error message to `stderr`.

## Professional Skills Demonstrated

- **Algorithm Design**: Implementation of Dijkstra's algorithm, optimized for performance.
- **Data Structures**: Efficient handling of graphs, priority queues, and auxiliary data.
- **Software Engineering**: Robust design ensuring reliable input processing and error handling.

## Usage

1. Execute the program in a command-line environment.
2. Enter the desired command as per the syntax outlined above.

A valid execution has the following form:
./pathfinder \<GraphType\> \<InputFile\>

where:

\<GraphType\> should be substituted by either Directed or Undirected,
\<InputFile\> should be the exact name of the input file.

## Input Format

The format of the input file is the following. The first line contains two positive integers, representing the number of vertices n and number of edges m, respectively. Each of the next m lines has the following format: 
edgeIndex u v w(u, v)
where u is the start vertex of edge (u, v), v is the end vertex of edge (u, v), w(u, v) is the weight of edge (u, v), and edgeIndex is the index of edge (u, v).
Below is a visual of how a graph would be converted into this format

---
![image](https://github.com/bjmnh/Pathfinder-Program/assets/88810487/b90ac204-04bf-48fe-b06d-ec96ba4d8f2f)
