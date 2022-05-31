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

## Graph Theory Slidedeck
- [2019 version](https://assets.hkoi.org/training2019/g-i.pdf)
- [2021 version](https://assets.hkoi.org/training2022/g-i.pdf)

### Representation snippets
<img src="https://i.imgur.com/SGGhor2.png" width="400">

The following are different ways to represent the directed graph above

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
    Edges[6] = {{4, 3}, 1};
    Edges[6].first.first = 5; // sets "from" of 6thedge
    cout << Edges[6].first.second << endl; // prints "to" of 6th edge
    cout << Edges[6].second << endl; // prints "weight" of 6th edge
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
    Edges[6] = {4, 3, 1};
    Edges[6].from = 5;
    cout << Edges[6].to << endl;
    cout << Edges[6].weight << endl;
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

    // to iterate through all the neighbhors of vertex 2:
    for (auto v: Graph[2]) {
        travel(v);    // travel() is the recursive DFS function
    }
```

---

## Exercises
- DFS: [01035 Patrol Area](https://judge.hkoi.org/task/01035)
- BFS: [M1311 Dokodemo Door](https://judge.hkoi.org/task/M1311)
- Extra Credit: [T022 Bomber Man](https://judge.hkoi.org/task/T022)
- Extra Credit: [USACO Redistributing Gifts](http://www.usaco.org/index.php?page=viewproblem2&cpid=1206)

For [USACO Redistributing Gifts](http://www.usaco.org/index.php?page=viewproblem2&cpid=1206), use this [brute force solution](https://github.com/miyagi-sensei/usaco/blob/main/usaco2002_02_silver1.py) to verify your understanding of the problem:

For example, the below input:
```
5
3 2 1 5 4
1 4 3 2 5
5 3 2 4 1
3 4 1 2 5
4 2 5 3 1
```
should yield the following output:
```
3
1
5
3
4
```
Register on the USACO website so that you can submit code.
