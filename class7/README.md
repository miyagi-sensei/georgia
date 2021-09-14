# Class 7
# [j173 - Fibonacci Word](https://judge.hkoi.org/task/j173)
```
- F(1) = 0
- F(2) = 01
- F(3) = 010 (01/0)
- F(4) = 01001 (010/01)
- F(5) = 01001010 (01001/010)
- F(6) = 0100101001001 (01001010/01001)
- F(7) = 010010100100101001010 (0100101001001/01001010)
- F    = 0100101001001010010100100101001001....  (infinite length)
```
- There isn't any `11` (subtask 1 solved)
- The length of Fibonacci word is the Fibonacci numbers, i.e. F(i) = fib(i)
- The length of Fibonacci word grows exponentially because so does Fibonacci numbers

## Subtask 2
```
generate F = F(17)
for each query (Li, Ri, Wi):
  scan from F[Li] to F[Ri] and count occurrences of Wi
```
This is O(Q*R).

---

## Partial Sum - also called Range Sum Query
Practise this first: http://dptjudge.dgs.edu.hk/task/A005

---

## Subtask 3
```
generate F = F(30)
precompute prefix_sum where prefix_sum[w][r] = occurences of w in F[1:r]
for each query (Li, Ri, Wi):
  print prefix_sum[Wi][Ri] - prefix_sum[Wi][Li]
```
if F[r]F[r+1] matches w: prefix_sum[w][r+1] = prefix_sum[w][r] + 1<br>
otherwise: prefix_sum[w][r+1] = prefix_sum[w][r]

Time complexity: O(Q).

---

## Subtask 5
### Need an O(Q) solution. Nothing else would pass within 1s.
Can we solve the following problem?<br>
Suppose `Li` = 1 in all queries and all `Ri` is a Fibonacci number.<br>
Then we just need to solve the following problem:<br>
### count(w, i) - the number of occurrences of w in F[1:fib(i)]<br>
where: fib(i) = the ith Fibnoacci number: fib(1) = 1, fib(2) = 2, fib(3) = 3, fib(4) = 5, fib(5) = 8, ...<br>
|i|1|2|3|4|5|6|7|8|9|10|11|...|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|fib(i)|1|2|3|5|8|13|21|34|55|89|144|...|

### Transition formula:
count(w, i) = count(w, i-1) + count(w, i-2)?
- if tail of count(w, i-1) and head of count(w, i-2) matches w, need to add 1

for example: to solve count("01", 7), you need to count how many "01" is in F(6) and in F(5) first.
```
F(7) = 0100101001001/01001010
```
But also notice where F(6) and F(5) joins there is another "01" not accounted for.<br>
`count("01", 7) = count("01", 6) + count("01", 5) + [1]`
> Remember optimization is needed since this is exponential time recursion. (DP)

How can we use count(w, i) to solve the problem?<br>
solve(w, r) - the number of occurrences of w in F[1:r]
```
0100101001001010010100100101001001...01001/0100101001001010010100100101...
   ^4  ^8  ^12                           ^89=f(10)                 ^r=114
```
we can break this problem into 2 parts:
1. count up to the largest fibonacci number preceding r
2. count the rest of the tail

The tail is a prefix of F. So if fib(i) is the largest Fibonacci number before r, then we just need to solve(w, r-fib(i)).<br>
One last thing, the junction needs to be counted too.
```
0100101001001010010100100101001001...01001/0100101001001010010100100101...
                                         ^ ^ => '10'
```
solve(w, r) pseudocode:
```
  if r <= 1:
    return 0
  elif r == 2:
    return w == "01"
  find the fibonacci number immediately preceding r and store its index in <i>
  (i.e. fib(i) < r <= fib(i+1))
  return count(w, i) + solve(w, r - fib(i)) + (1 if the junction of F(i) and F(i-1) forms w)
```

This is Divide and Conquer. You divided the problem into smaller subproblems. A lot of times you divide a problem into 2 halves and solve recursively (merge sort or quick sort). In this case, you divide the problem into a special class of problem (count(w,i)) and a smaller version of itself (solve(w, r - fib(i)).
