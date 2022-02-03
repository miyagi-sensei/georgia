# Class 16
[2021/22 Heat Event Junior Paper](https://github.com/miyagi-sensei/georgia/blob/main/class15/hkoi22hj.pdf)
- logic/boolean/bitwise: 1, 10, 19, B5, B7
- code tracing: 14, 16, 17, 22, 23
- data structure: 13
- search and sorting: 4, 15
- code reading: 2, 5, 7, 8, B1, B4, B6
- counting: 18, 24, 25
- algorithmic: 20, 21, B2
- analytical: 3, 12, B3
- encoding/basics/syntax: 6, 11

Exercise:
1. How many ways are there is tile a 3x10 grid with only 1x3 tiles?
> 28

2. Consider question A21, transform grid A to i and/or ii. Is it possible? <br>
    ![grids](https://github.com/miyagi-sensei/georgia/blob/main/class15/ex2.png)
> Grid A can be transformed to (i) but not to (ii).

3. Consider question A18. How many ways can you color each vertex? (without assigning the same color to any adjacent vertices)<br>
    ![pentagon](https://github.com/miyagi-sensei/georgia/blob/main/class15/ex3.png)
> 18

### A25
|scenario|probability|
|---|---|
|Alice got the first step wrong; Bob survives|3/4 * 1/3 * 1/4 * 1/4|
|Alice got the first step right but second step wrong; Bob survives|1/4 * 3/4 * 1/3 * 1/4|
|Alice got the first 2 steps right but third step wrong; Bob survives|1/4 * 1/4 * 3/4 * 1/3|
Add up those 3 fractions and you get 3/64.

### A13
- [Stack concepts](https://youtu.be/F1F2imiOJfk); [Stack implementation](https://youtu.be/sFVxsglODoo)
- [Queue concepts](https://youtu.be/XuCbpw6Bj1U); [Queue implementation](https://youtu.be/okr-XE8yTO8)
- [Linked list concepts](https://youtu.be/NobHlGUjV3g); [Linked list implementation](https://youtu.be/NobHlGUjV3g)

### A12
If a team wins all the time, it would get 4 points. Only 1 team can score 4 points. 2 teams cannot both beat everybody.

### A11
Syntax: study [C++ order of precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)

### A6
How many bytes do you need to encode a number that may range from 1-15000 (or 0-14999)?
|number of bits|possible range|
|---|---|
|1|2|
|2|4|
|3|8|
|4|16|
|...|...|
|8|256|
|9|512|
|10|1,024|
|11|2,048|
|12|4,096|
|15|32,768|
|16|65,536|
|20|1,048,576|
|30|1,073,741,824|
|31|2,147,483,648|
|32|4,294,967,296|

### B7
![](https://github.com/miyagi-sensei/georgia/blob/main/class16/B7.jpeg)<br>
Boolean algebra: 
- `!(A || B) == !A && !B`
- `!(A && B) == !A || !B`
- `A || B == !(!A && !B)`
- `A && B == !(!A || !B)`

### B5
|`i`|`a[i]`|binary|
|---|---|---|
|0|1|`0000001`|
|1|2|`0000010`|
|2|12|`0001100`|
|3|0|`0000000`|
|4|58|`0111010`|
|5|74|`1001010`|
|6|64|`1000000`|
|7|92|`1011100`|
|8|58|`0111010`|
|9|???|`???????`|
|`sum`|   |   |
|target|118|`1110110`|
```
0000001
0000010
0001100
0000000
0111010
1001010
1000000
1011100
0111010
-------
1011001
??????? ^
-------
1110110
```

### B2 - Coin change problem
Greedy algorithm:
```cpp
count = 0;
for (i=n-1; i>=0; i--) {
    b[i] = m / c[i];
    m -= b[i] * c[i];
}
```
- But we need to consider every possible combination.
- Define P(m) as: minimum number of coins needed to get exact change for m
- `P(m) = min( P(m-c[i]) ) + 1`         (for all i from 0 to n-1, inclusive)
```python
def change(m):
    if m == 0:
        return 0
    if m < 0:
        return 10001
    ans = 10000
    for i in 1...n-1:
        ans = min(ans, 1 + change(m - c[i])
    return ans
```
Can you optimize it with memoization table?

## Exercise
You ordered 10 container boxes of steel bars to build a bridge. Each box contains dozens of steel bars all of weight 100kg. But due to production irregularities, one box contains steel bars all weighing 101kg. You need to use a high-tech scale at the container terminal to determine which box to discard. The scale is very expensive to operate and cost $5000 every time you use it. How much budget should you ask your superior for this exercise?

Code reading: B1, B4 and B6

## Homework
Write a program to solve the Coin Change problem. First use Greedy algorithm. Then write the CORRECT solution that works all the time.
