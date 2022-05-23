# Class 31 - Data Structure II
## [01019 - Addition II](https://judge.hkoi.org/task/01019)
Read the problem first and understand the sample input. Then consider this input:
```
5
2 14 7 6 18
```
It's always optimal to first add up the 2 smallest numbers first. Can you prove it?
```python
put the collection of numbers into DB
sum <-- 0
repeat until DB only has 1 number left:
    a <-- extract the smallest number from DB (remove it also)
    b <-- extract the smallest number from DB (remove it also)
    insert (a+b) into DB
    sum += a + b
```
In C++ terms, the main function would look like this:
```cpp
    long long num, a, b, sum = 0, i;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> num;
        insert(num);
    }
    for (i=1; i<N; i++) {
        a = extract_least();
        b = extract_least();
        insert(a + b);
        sum += a + b;
    }
    cout << sum << endl;
```
A naive way to implement `insert` and `extract_least` would be:
```cpp
#include <vector>
#include <algorithm>
vector<int> db;

void insert(int x) {
    db.push_back(x);
    sort(db.begin(), db.end());
}

int extract_least() {
    int min_val = db[0];
    db.erase(db.begin());
    return min_val;
}
```
### Time Complexity
|function|complexity|
|---|---|
|`insert`|O(`NlogN`)|
|`extract_least`|O(N)|

- You can optimize `insert` and make it O(1) (without sorting). But `extract_least` would have to be at least O(N) as long as you're choosing array or vector as the data structure.
- With N iterations, the program would have O(N<sup>2</sup>) time complexity
- Try to implement using this approach (O(1) `insert` and O(N) `extract_least`)

You can solve this problem using a *Priority Queue* because it has the following time complexity for these operations:
|function|complexity|
|---|---|
|`insert`|O(log N)|
|`get_least`|O(1)|
|`pop_least`|O(log N)|

Implementing these `insert` and `extract_least` using priority queue would give you O(`NlogN`) solution:
```cpp
priority_queue<long long> db;

void insert(int x) {
    db.push(-x);
}

int extract_least() {
    int min_val = -db.top();
    db.pop();
    return min_val;
}
```
(Note `priority_queue` puts the largest item on top so we need to make all numbers negative to get the desired outcome)

## Binary Heap
So how does a *priority queue* work under the hood?
[Slidedeck 2019](https://assets.hkoi.org/training2019/dsii.pdf)

### Try to implement your own binary heap as an exercise
Sample implementation:
```cpp
#define INF 400000001

int N;
int db[160000];
int last = 1;

void insert(int x) {
    int i = last;
    db[last] = x;
    while (i > 1 && db[i] < db[i/2] ) {
        swap(db[i], db[i/2]);
        i = i / 2;
    }
    db[last*2] = INF;
    db[last*2 + 1] = INF;
    last++;
}

int get_least() {
    return db[1];
}

void pop_least() {
    last--;
    db[1] = db[last];
    db[last] = INF;
    int i = 1, next;
    while (true) {
        if (db[2*i] <= db[2*i+1])
            next = 2*i;
        else
            next = 2*i + 1;
        if (db[i] <= db[next])
            break;
        swap(db[i], db[next]);
        i = next;
    }
}
```