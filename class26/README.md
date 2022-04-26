# Class 27 - J222 Spicy Ramen
You can brute force subtask 1 & 2:
```
count = 0
for s in 0 to R:
    count how many A[i]'s are ≤ s --> Ka
    count how many B[i]'s are ≥ s --> Kb
    if Ka + Kb >= K:
        count++
```
This brute force solution is `O(R*(M+N))` if you count `Ka` and `Kb` naively as below:
```
sort A[] and B[]
count = 0
for s in 0 to R:
    Ka = 0
    for each A[i]:
        if A[i] <= s:
            Ka++
    
    Kb = 0
    for each B[i]:
        if B[i] >= s:
            Kb++

    if Ka + Kb >= K:
        count++
```
* Can you take this solution and do better? 
* You can sort `A[]` and `B[]` and then do the counting using binary search
* Alternatively, do you notice that starting the count from `A[0]`, then `A[1]`, then `A[2]`, ... etc for each and every `s` is incredibly inefficient? If you sorted both `A[]` and `B[]`, as `s` increases 1 by 1, keep a mark of where the search ended in `A[]` and `B[]` respectively, then you would have an O(R + M + N) solution. 

## Full solution
```
concatenate A[] and B[],
but pair each A[i] with label 'A' and each B[i] with label 'B'
For example: A: {10, 20, 60, 90} and B: {30, 40, 80} would turn into:
C: {(10, A), (20, A), (60, A), (90, A), (30, B), (40, B), (80, B)}

Then, sort C[] by the numbers so it becomes:
{(10, A), (20, A), (30, B), (40, B), (60, A), (80, B), (90, A)}
Then, process each pair in C[] one by one, 
keeping track of the "height of the graph" and,
carefully including the ranges where the height is above K
```
The input:
```
4 3 4 100
10 20 60 90
30 40 80
```
can be depicted with the graphs below:
![](https://i.imgur.com/kdDU49t.jpg)

More accurately in discrete math fashion:
![](https://i.imgur.com/uQ3i9NR.jpg)

