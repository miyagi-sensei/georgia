# Class 27 & 28 - J222 Spicy Ramen
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

## Full Solution
```
Concatenate A[] and B[],
but pair each A[i] with label 'A' and each B[i] with label 'B'
For example: A: {5, 10, 23, 38} and B: {15, 20, 35} would turn into:
C: {(5, A), (10, A), (23, A), (38, A), (15, B), (20, B), (35, B)}

Then, sort C[] by the numbers so it becomes:
{(5, A), (10, A), (15, B), (20, B), (23, A), (35, B), (38, A)}

Then, process each pair in C[] one by one, 
keeping track of the "height of the graph" and,
carefully counting the ranges where the height is above K
```

It's great if you already understand the idea of the full solution already. If not, don't worry, this video below should get you there.

[J222 Illustration](https://youtu.be/NCWV83okqNs)
