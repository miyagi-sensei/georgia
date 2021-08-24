# Class 6
## Insertion Sort
- [demo video](https://www.youtube.com/watch?v=OGzPmgsI-pQ)
- [exercise: D803](https://judge.hkoi.org/task/D803)
- Time Complexity: O(N<sup>2</sup>)
```
A[] - data to be sorted
declare B[] as an array for the finished array
for i in 0 to N-1:
    insert A[i] to the appropriate place in B[] (hint, loop from the back of B[])
    for j from i-1 to 0:
        if A[i] >= B[j]:
            break
        else:
            B[j+1] = B[j]
    B[j+1] = A[i]
```
## Bubble Sort
- it only does 1 thing: compare adjacent numbers and swap them if the preceding element is larger
- [demo video](https://www.youtube.com/watch?v=nmhjrI-aW5o)
- [exercise: D802](https://judge.hkoi.org/task/D802)
- Time Complexity: O(N<sup>2</sup>)
- easiest sort to write:
```
for (i=1; i<N; i++)
    for (j=1; j<N; j++)
        if (arr[j-1] > arr[j])
            swap(arr[j-1], arr[j]);
```

## MergeSort
```
how do you merge 2 sorted arrays into 1 combined sorted array in O(N) time?
a: {3, 27, 38, 43}     b: {9, 10, 82}
merged: {3, 9, 10, 27, 38, 43, 82}
```
```
# if a and b are both sorted lists, return a merged array that is also sorted
def merge(a, b):
    i = 0
    j = 0
    c = []
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    c += a[i:]
    c += b[j:]
    return c
```
- [D804 merging sorted arrays](https://judge.hkoi.org/task/D804)

Recursive formulation of MergeSort:
```
sort(arr) - sort arr[] and return the sorted array

sort(arr) = merge( sort(left half of arr[], sort(right half of arr[] )
if arr is unitary (size 1), then returns arr
```
Now sort this: {38, 27, 43, 3, 9, 82, 10}
```
                                 |
                  {38, 27, 43, 3,| 9, 82, 10}
                                 |
                |                               |
        {38, 27,| 43, 3}                     {9,| 82, 10}
                |                               |
        |                |                              |
    {38,| 27}        {43,| 3}          {9}          {82,| 10}
        |                |                              |
  {38}     {27}    {43}     {3}                   {82}     {10}
```
Arrays of size 1 are always sorted. Now we start merging
```
  {38}  +  {27}    {43}  +  {3}        {9}        {82}  +  {10}
      \     /         \     /           |            \     /
     {27, 38}    +    {3, 43}          {9}    +     {10, 82}
          \             /                 \           /
          {3, 27, 38, 43}                  {9, 10, 82}
                    \                        /
                    {3, 9, 10, 27, 38, 43, 82} 
```

Time Complexity: O(NlogN)

This is *Divide and Conquer*.

If you want to hear an MIT professor fully discuss time complexity of merge sort check out this [lecture](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/lecture-3-insertion-sort-merge-sort/).

99% of the time you just need to know how to use the `sort()` function in the `<algorithm>` library.
```
#include <algorithm>
using namespace std;
int arr[1000], N;

int main() {
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
}
```
But how do you solve a problem like [01068 Moliu Sorting](https://judge.hkoi.org/task/01068)?

---

# Suggested Homework
- [01068 Moliu Sorting](https://judge.hkoi.org/task/01068)
- Also implement insertion sort, bubble sort and mergesort for this problem above to make sure you understand those sorting algorithm. You learned very little until you start using those algorithms.

# Extra Credit
## Visualization tool: https://visualgo.net/bn/sorting
## Sorting algorithms visualization: https://youtu.be/kPRA0W1kECg

## Quicksort
If you really want to master the Divide and Conquer technique, you should learn Quicksort.

The essence of the algorithm is below.
```
def quicksort(begin, end):      # sort arr[begin...end] (exclusive of arr[end])
    if begin + 1 == end:
        return
    pivot = partition(begin, end)
    quicksort(begin, pivot)
    quicksort(pivot+1, end)
```
There are many ways to partition an array so that everything to its left is less than the pivot and everything to its right is larger than the pivot. What is your implementation?

[One way to partition](https://www.youtube.com/watch?v=PgBzjlCcFvc)
