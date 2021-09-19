# Class 8
## [j173 Fibonacci Word](https://judge.hkoi.org/task/J173)
- [brute force solution](https://github.com/miyagi-sensei/georgia/blob/main/class8/brute.py)
- [full solution](https://github.com/miyagi-sensei/georgia/blob/main/class8/p1.py) (It won't score 100pts because it's python. If you turn it into C++ code it will easily score pass)
- [full solution](https://github.com/miyagi-sensei/georgia/blob/main/class8/p2.py) (It uses bisect_left built-in binary search instead of linear search and scores 100)

## [01068 Moliu Sorting](https://judge.hkoi.org/task/01068)
### `pair`
- `pair` allows us to handle pairs of data
- super handy in HKOI/IOI for dealing with (x, y) coordinates or many other situations
- declare `pair<int, int>`
- can also do `pair<int, string>`, `pair<string, double>`, `pair<bool, int>`, `pair<char, int>`....

### Program template:
```
#include <iostream>
using namespace std;
pair<long long, long long> A[100];
int N;

void bubblesort(){
    ...
    ...
}

int main() {
    int i, j, x, y;
    cin >> N;
    for (i = 0; i < N; i++){
        cin >> x >> y;
        A[i] = {x, y};
    }
    bubblesort();
    for (i = 0; i < N; i++){
        cout << A[i].first << " " << A[i].second << endl;
    }
    return 0;
}
```
A useful function:
```
long long moliu_index(pair<long long, long long> p) {
    return p.first * p.first + p.second * p.second;
}
```
### Bubble sort:
```
void bubblesort() {
    int i, j;
    for (i=1; i<N; i++) {
        for (j=1; j<N; j++) {
            if (moliu_index(A[j-1]) > moliu_index(A[j])) {
                swap(A[j-1], A[j]);
            }
        }
    }
}
```
### Insertion sort:
```
void insertion_sort() {
    int i, j;
    for (i=1; i<N; i++)
        for (j=i-1; j>=0; j--)
            if (moliu_index(A[j]) > moliu_index(A[j+1]))
                swap(A[j], A[j+1]);
}
```

### Merge sort:
```
// merge 2 sorted arrays A[l1:r1] and A[l2:r2] (l2=r1+1 always)
// then put the merged result back in A[l1:r2]
void merge(int l1, int r1, int l2, int r2){
    int i = l1, j = l2, k = l1;
    pair<int, int> temp[100];
    while (i <= r1 && j <= r2) {
        if (moliu(A[i]) < moliu(A[j])) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    for (; i<=r1; i++, k++)
        temp[k] = A[i];
    for (; j<=r2; j++, k++)
        temp[k] = A[j];
    for (i=l1; i<=r2; i++)
        A[i] = temp[i];
}

void mergesort(int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, m+1, r);
    }
}
```
### built-in `sort()` function
"hacking" with nested `pair`, taking advantage of the way `sort()` orders based on the `first` of the `pair`
```
#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<long long, pair<int, int> > A[100];

int main()
{
    int i, j, x, y;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> x >> y;
        A[i] = {(long long)x*x + (long long)y*y, {x, y}};
    }
    sort(A, A+N);
    for (i=0; i<N; i++) {
        cout << A[i].second.first << " " << A[i].second.second << endl;
    }
    return 0;
}
```
### using built-in `sort()` to create a ranked index first
```
#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> A[100];
pair<long long, int> Ranks[100];

int main()
{
    int i, j, x, y;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> x >> y;
        A[i] = {x, y};
        Ranks[i] = {(long long) x * x + (long long)y * y, i};
    }
    sort(Ranks, Ranks+N);
    for (i=0; i<N; i++) {
        j = Ranks[i].second;
        cout << A[j].first << " " << A[j].second << endl;
    }
    return 0;
}
```
### using built-in `sort()` with a custom compare function
```
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;  // very convenient trick

int N;
pair<ll, ll> A[100];

bool comp(pair<ll, ll> x, pair<ll, ll> y) {
    ll ix = x.first * x.first + x.second * x.second;
    ll iy = y.first * y.first + y.second * y.second;
    return ix < iy;
}

int main()
{
    int i, j, x, y;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> x >> y;
        A[i] = {x, y};
    }
    sort(A, A+N, comp);
    for (i=0; i<N; i++) {
        cout << A[i].first << " " << A[i].second << endl;
    }
    return 0;
}
```

---

# Make good use of [01068 Moliu Sorting](https://judge.hkoi.org/task/01068)
- Regularly practice writing insertion sort until you can do it with ease
