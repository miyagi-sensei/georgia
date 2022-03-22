# Class 21-23
## 1. Binary Search
|index|0|1|2|3|4|5|6|7|8
|-|-|-|-|-|-|-|-|-|-|
|value|2|3|5|7|11|13|17|19|∞

Find the largest number less than or equal to `13`.
```cpp
int INF=1000000001;
int arr[9] = {2, 3, 5, 7, 11, 13, 17, 19, INF};
int search(int target) {
    int l = 0, r = 8, m;
    // invariant: arr[l] <= target < arr[r]
    while (r > l+1) { // terminates when r == l + 1
        m = (l + r) / 2;
        if (target < arr[m])
            r = m;
        else          // arr[m] <= target
            l = m;
    }
    return l;         // arr[l] <= target < arr[l+1]
}
int main() {
    cout << search(13) << endl;
}
```
- Review [Class 13 notes](https://github.com/miyagi-sensei/georgia/tree/main/class13)
### Exercises
- [D801](https://judge.hkoi.org/task/D801)
- [M1023 Seating Plan](https://judge.hkoi.org/task/M1023)<br>
        - Ask: Can I pick M seats with minimum distance of d? (Call this boolean function `try(d)`)<br>
        - With this function, perform a search to find the largest d where try(d) is `true`<br>
        - You can perform a linear search first and then optimize it to binary search afterwards
- Extra Credit: [M1222 Longest Increasing Subsequence](https://judge.hkoi.org/task/M1222)

---

## 2. Sorting
[Visual Illustration](https://visualgo.net/en/sorting)

### Insertion Sort
```cpp
for(i=1; i<n; i++) {
    temp = a[i];
    for(j=i-1; j>=0; j--)
        if (temp > a[j])
            break;
        else
            a[j+1]=a[j];
    a[j+1] = temp;
}
```
Alternative version:
```cpp
for(i=1; i<n; i++)
    for(j=i-1; j>=0; j--)
        if (a[j] > a[j+1])
            swap(a[j], a[j+1]);
```
Time Complexity: O(N<sup>2</sup>)

### Bubble Sort
```cpp
for (i=1; i<N; i++)
    for (j=1; j<N; j++)
        if (a[j-1] > a[j])
            swap(a[j-1], a[j]);
```
Time Complexity: O(N<sup>2</sup>)

### Exercises
- [D803 Insertion Sort](https://judge.hkoi.org/task/D803)
- [D802 Bubble Sort](https://judge.hkoi.org/task/D802)
- [01068 Moliu Sorting I](https://judge.hkoi.org/task/01068)
- To use the built-in `sort(begin, end)` function, you pass a *pointer* to the beginning and a *pointer* to the end (exclusive) of the array/vector.
```cpp
#include <algorithm>
int myints[7] = {32,71,12,45,26,80,53,33};
sort(myints, myints+5);    // sort first 5 elements
sort(myints, myints+7);    // sort the whole array
```
> The bulit-in `sort()` function takes good care of `pair`'s nicely.
- Solve [01068 Moliu Sorting I](https://judge.hkoi.org/task/01068) using `sort()` and `pair`
```cpp
typedef long long ll;
pair<ll, pair<ll, ll> > A[100];
......
for (i=0; i<N; i++) {
    cin >> x >> y;
    A[i] = {x*x + y*y, {x, y}};
}
sort(A, A+N);
```
You can also solve it using a *rank index* or by defining a custom *compare* function. Try the rank index method as an exercise of index manipulation. See [Class 8 Notes](https://github.com/miyagi-sensei/georgia/blob/main/class8/README.md) for more details.

### Merge Sort

- Review [Class 6 notes](https://github.com/miyagi-sensei/georgia/tree/main/class6)

### Exercises
- [D804 Mergin Arrays](https://judge.hkoi.org/task/D804)
- Solve [01068 Moliu Sorting I](https://judge.hkoi.org/task/01068) by implementing a merge sort

> Demo swap function and pass by reference

---

## 3. Written Test
1. Is the following statement true or false?
> When determining whether an element exists in a sorted array with at least 100 elements, binary search always requires fewer comparisons than linear search. 

2. Given the sequence `5, 7, 2, 6, 4`. What is the minimum number of adjacent swaps required to sort the sequence in increasing order?

3. Given the sequence `8, 7, 6, 5, 4, 3, 2, 1`. What is the minimum number of adjacent swaps required to sort the sequence in increasing order?

4. Given the sequence `8, 7, 6, 4, 5, 3, 2, 1`. What is the minimum number of adjacent swaps required to sort the sequence in increasing order?

5. Given the sequence `10, 9, 8, 5, 6, 7, 4, 3, 2, 1`. What is the minimum number of adjacent swaps required to sort the sequence in increasing order?

6. Binary search can be used to replace linear search to find the minimum element from an array of integers as a faster alternative.

7. Given that `a` is an array of length `10`, which of the following expressions must be true after the function `mysort` has been executed?
```cpp
int a[10];
void mysort() {
    int i, j, tmp;
    for (i=0; i<10; i++)
        for (j=0; j<8; j++)
            if (a[j] > a[j+2]) {
                tmp = a[j];
                a[j] = a[j+2];
                a[j+2] = tmp;
            }
}
```
i. `a[0] <= a[1]`<br>
ii. `a[0] <= a[2]`<br>
iii. `a[5] <= a[7]`<br>
A. i only<br>
B. i and ii only<br>
C. ii and iii only<br>
D. i, ii and iii<br>
E. None of them<br>

8. Which of the following sorting algorithms apply divide and conquer?
i. Quick sort<br>
ii. Insertion sort<br>
iii. Merge sort<br>
A. i only<br>
B. ii only<br>
C. i and iii only<br>
D. ii and iii<br>
E. i, ii and iii<br>
F. None of them<br>

9. What is the maximum number of swaps necessary to sort an array of N elements in ascending order?

10. `SwapInt(&x, &y)` and `SwapChar(&x, &y)` are functions that swap the values of `x` and `y`. Consider the following program:
```cpp
string s;
int a[50];
int n, i, j;
void SwapInt(int& x, int& y) {
    int t;
    t = x; x = y; y = t;
}
void SwapChar(char& x, char& y) {
    char t;
    t = x; x = y; y = t;
}
int main() {
    cin >> s;
    n = s.length();
    for (i=0; i<n; i++)
        a[i] = i+1;
    for (i=0; i<n; i++)
        for (j=i; j<n-1; j++)
            if (s[j] > s[j+1]) {
                SwapInt(a[j], a[j+1]);
                SwapChar(s[j], s[j+1]);
            }
    for (i=0; i<n; i++)
        cout << a[i];
    return 0;
}
```
Part 1: If the input is `BABBAB`, what is the output?<br>
Part 2: Give an input with `A` and `B` **only**, such that the program outputs `246135`.<br>


---

## 4. Bonus Materials
Proof that no *comparison* sorting algorithm can be faster than `O(NlogN)`: https://youtu.be/Nz1KZXbghj8?t=1224
> That's why computer scientist need to be strong in logic (so you can prove things) and in discrete math (so you can count and then draw mathematical conclusion for performance).
