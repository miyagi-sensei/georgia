# Class 4
## [j181 Wings and Nuggets](https://judge.hkoi.org/task/J181)
- [solution: recursive implementation](https://github.com/miyagi-sensei/j181/blob/main/v1.cpp)<br>
![dfs tree](https://github.com/miyagi-sensei/georgia/blob/main/class3/j181.jpeg)
- if you implement it with recursion, this is DFS (depth-first search)
- What is the *time* complexity of subtask 3 and what is the complexity after using memoization table?
- What about *space* complexity?
- What if Y <= 50,000,000?
    1. recursion depth in C++ is limited by max stack size (even more limiting for python)
    2. run into memory limit even for inputs like below (when recursion depth isn't too bad):

### Iterative implementation instead of recursive ipmlementation
Recall Fibonnaci numbers
- f(n) = f(n-1) + f(n-2)
- f(0) = 0
- f(1) = 1

Simple recursive implementation:
```
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
```
This is actually exponential time implementation. By the way, how would you add memoization to speed it up?

Instead of recursive implementation, you can also implement it *iteratively*:
```
int fib2(int n) {
    int a = 0, b = 1, c, i;
    if (n <= 1)
        return n;
    for (i=2; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
```
```
g(y):
  n1 = 0
  n2 = 0
  n3 = 0
  if y >= N4:
    n1 = 4 + g(y - N4)
  if y >= N6:
    n2 = 6 + g(y - N6)
  if y >= N9:
    n3 = 9 + g(y - N9)
  return max(n1, n2, n3)
```
- g(y)'s solution only relies on *smaller* problem of itself => simple one-directional
- that means we can solve it in ascending order of y

Code:
```
int max_nuggets(int y) {
    int i;
    for (i=N4; i<=y; i++) {
        int n1 = 4 + Ans[i - N4];
        int n2 = 0, n3 = 0;
        if (i >= N6)
            n2 = 6 + Ans[i - N6];
        if (i >= N9)
            n3 = 9 + Ans[i - N9];
        Ans[i] = max(n1, max(n2, n3));
    }
    return Ans[y];
}
```
This huge memoization table would exceed 256MB memory limit. Do you know how to solve it without using O(Y) space complexity? 
(Hint: it'll take O(N<sub>9</sub>) space complexity instead)

### [More Fibonacci Sequence](https://judge.hkoi.org/task/M1323)
- Fibonaaci sequence definition: f(n) = f(n-1) + f(n-2)

But there are many different Fibonacci sequences.
- f(0) = 0
- f(1) = 1<br>
is *Fibonacci numbers* - the most famous *Fibonnaci sequence*

In this problem, we are given F<sub>i</sub> and F<sub>j</sub>. We are to derive F<sub>n</sub>.<br>
Assume i > j, then if we know both F<sub>j</sub> (which is given) and F<sub>j+1</sub> we can derive the whole sequence.

If j = i - 4, we are given F<sub>i</sub> and F<sub>i-4</sub>, let's try to derive F<sub>i-3</sub>

![illustration](https://github.com/miyagi-sensei/georgia/blob/main/class4/m1323.jpeg)

## [01090 Diligent](https://judge.hkoi.org/task/01090)
Use this template so you can understand data structure *abstraction* better:
```
int main() {
    int id, N;
    cin >> N;
    while (N--) {
        cin >> id;
        if (search(id)) {
            cout << "out" << endl;
            add(id);
        } else {
            cout << "in" << endl;
            erase(id);
        }
    }
}
```

## Set
Set is the best data structure for this problem.

A set is an abstract data type that:
- can store values,
- without any prarticular order,
- without repeated values
It's best to demonstrate set with some python code:
```
>>> x = set('abracadabra')
>>> x
{'b', 'a', 'c', 'd', 'r'}
>>> y = set('alacazam')
>>> y
{'z', 'a', 'c', 'm', 'l'}
>>> x - y         # difference: letters in x but not in y
{'d', 'r', 'b'}
>>> x | y         # union: letters in x or y or both
{'z', 'a', 'b', 'c', 'm', 'd', 'r', 'l'}
>>> x & y         # intersection: letters in both x and y
{'c', 'a'}
>>> x ^ y         # xor: letters in a or b but not both
{'z', 'r', 'd', 'm', 'b', 'l'}
```
In C++, [`unordered_set`](https://www.cplusplus.com/reference/unordered_set/unordered_set/) and [`set`](https://www.cplusplus.com/reference/set/set) is the standard library implementation of set. For HKOI/IOI, you can just use `set` most of the time.
|operations||array|unordered_set|set|
|----|----|----|----|----|
|search||O(N)|O(1)|O(logN)|
|add||O(1)|O(1)|O(logN)|
|erase||O(N)|O(1)|O(logN)|

But in practice `set` is often faster than `unordered_set` even though its complexity is worse. This demonstrates the relevance of "constant factor" in runtime. Also most of the time, O(logN) is not meaningfully different from O(N).

---

# Homework
## [01090 Diligent](https://judge.hkoi.org/task/01090)
## [s184 Bogo Translate](https://judge.hkoi.org/task/s184)
- Just solve subtask 2 (What really is subtask 2?)
- you will need to use `map` or `unordered_map`. research it on cplusplus.com or see [map example](map_demo.cpp)
