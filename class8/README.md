# [01068 Moliu Sorting](https://judge.hkoi.org/task/01068)
## `pair`
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
