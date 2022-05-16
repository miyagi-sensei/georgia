# Class 30 - Graph Theory
## Water Jug Problem
- There are 2 water jugs with capacities N and M liters respectively.
- Initially, both of them are empty
- You can perform the following operations for infinitely many times (one operation at a time)
    1. Empty a jug
    2. Fully fill a jug
    3. Pour water from one jug to another until either one jug is empty / full
- How to get a specific volume K in one of the jugs?
- How to do that in the minimum number of steps?

### Cases to consider
|N|M|K|
|---|---|---|
|3|4|2
|10|13|6
|10|13|8
|12|37|6
|9|15|5
|59|131|49

## [Graph Theory Slidedeck](https://assets.hkoi.org/training2019/g-i.pdf)

### Representation snippets
#### Adjacency Matrix
```cpp
int Graph[6][6] = 
{   {0,0,0,0,0,0},
    {0,0,1,0,1,0},
    {0,0,0,0,1,1},
    {0,1,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,1,0,0}};
```

#### Edge List
```cpp
    pair< pair<int, int>, int> Edges[7];
    Edges[1] = {{1, 2}, 1};
    Edges[2] = {{1, 4}, 1};
    Edges[3] = {{2, 4}, 1};
    Edges[4] = {{2, 5}, 1};
    Edges[5] = {{3, 1}, 1};
    Edges[6] = {{5, 3}, 1};
```
or use `struct`
```cpp
    struct Edge {
        int from, to, weight;
    };
    Edge Edges[7];
    Edges[1] = {1, 2, 3};
    Edges[2] = {1, 4, 1};
    Edges[3] = {2, 4, 1};
    Edges[4] = {2, 5, 1};
    Edges[5] = {3, 1, 1};
    Edges[6] = {5, 3, 1};
```

### Adjacency List
```cpp
    vector<int> Graph[6];
    Graph[1].push_back(2);
    Graph[1].push_back(4);
    Graph[2].push_back(4);
    Graph[2].push_back(5);
    Graph[3].push_back(1);
    Graph[5].push_back(3);
```

## Exercises
- DFS: [01035 Patrol Area](https://judge.hkoi.org/task/01035)
- BFS: [M1311 Dokodemo Door](https://judge.hkoi.org/task/M1311)
- Extra Credit: [T022 Bomber Man](https://judge.hkoi.org/task/T022)
