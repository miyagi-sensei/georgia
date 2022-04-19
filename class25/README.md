# Class 25 - Algorithmic Thinking
#### 1. **Make 1000** is an interesting game that Anna and Ben are playing. The counter initially begins with 0. Each turn, the player is allowed to add an arbitrary number from 1 to 7 to the counter. They are not allowed to skip their turns. Players will take their turns alternatively. The player that makes the counter greater than or equal to 1000 will win the game. If Anna goes first, who will win the game? (Assume that both play optimally throughout the game) Choose only one.
- A. Anna
- B. Ben
- C. Both of them may win, depending on the initial number called by Anna
- D. Both of them may win, because there does not exist an optimal strategy

#### 2. Consider the **Make 1000** game above, which of the following modification(s) to the game will change your answer in the previous question? Note: The modification should be considered independently - only one modification shall be applied at one time. (Choose any number of them, or none at all)
- A. Set the counter to a random number `X` before starting the game.
- B. Each player is allowed to use `0` for a maximum of `Y` times (to be determined before the game starts) in the whole game as the number to add to the counter in a turn.
- C. Additional rule: All numbers must be used for at least `Z` times before a number can be used the (`Z+1`)-th times (`Z` is the current maximum number of times that a particular number is being used)

#### 3. Consider the 5x5 grid below labeled `A` with black and white cells.

![](https://i.imgur.com/QsLD3qu.png)

You can perform the following action an arbitrary number of times: Choose a 2x2 sub-grid completely within the grid, change each cell in the sub-grid into its opposite colours, i.e. black to white, white to black. Which of the grids (i) and (ii) can be produced from grid `A`?

#### 4. The input to the following program segment will be 199 distinct integers between 1 and 200 (inclusive).
```cpp
int i, a, x;
int f() {
    a = 0;
    for (i=0; i<199; i++) {
        cin >> x;
        a = ________A_______;
    }
    return _______B_______;
}
```
Complete function f() so that it returns the integer between 1 and 200 (inclusive) that does not appear in the input.

- A: _______________________
- B: _______________________

#### 5. Consider the following program segment.
```cpp
int a[100];
void swap(int x, int y) {
    int t;
    _________C________;
}
void f(int k) {
    int i = 0;
    while (i < _________D________) {
        swap(i, k - i - 1);
        i++;
    }
}
void g(int k) {
    _________E________
}
```
Complete the function `swap` so that it swaps the values of `a[x]` and `a[y]`. You must NOT make use of the functions `f` or `g`.
- C: _______________________

Assume that `a` is an array of 100 integers and `k` is an integer between 0 and 100 inclusive.

Complete the function `f` so that it reverses the first `k` elements in the array `a`.
- D: _______________________

Complete the function `g` so that it reverses the last `k` elements in the array `a`. You may make use of the function `swap` and `f`.
- E: _______________________

#### 6. Consider a rectangular grid, where the cell labeled with `S` is the *starting-point*, cell labeled `T` is the *target-point*, and cells labeled with `C` are the *checkpoints*. We call a path an *interesting path* if and only if it is a path that walk from the starting-point to the target-point by repeatedly walking to either the cell below or on the right, and passing through **EXACTLY ONE** checkpoint. For example, for the following 3x3 grid, there are 4 distinct interesting paths.

![](https://i.imgur.com/SakTax6.png)

Now consider the 5x5 grid below: (cell A1 labeled as `S` and cell E5 labeled as `T`)

![](https://i.imgur.com/7xFfPS0.png)

Label exactly **TWO** cells as checkpoints (`C`) so that the number of distinct interesting paths is **EXACTLY** 2.
- F: _______________________

Label exactly **TWO** cells as checkpoints (`C`) so that the number of distinct interesting paths is **EXACTLY** 31.
- G: _______________________

#### 7. Consider a string that consists of 100 lowercase letters. You may remove an arbitrary number of characters in the string without changing the order of the remaining characters. In the worst case, at least how many characters should you remove so that the remaining string is a palindrome? (Hint: Palindromes are strings that read the same forward or reversed. For example, "ABBA" is a palindrome while "ABCD" isn't.)

#### 8. Below are all 3 arrangements of tiling 3x4 grid with only 1x3 tiles:

![](https://i.imgur.com/nW1AeYs.png)

What is the number of arrangements tiling a 3x12 grid with only 1x3 tiles?

#### 9. In Heung Shing, the coin system has `n` different denominations. We use an integer array `c[n]` to represent the coin system, so that the `n` types of coins are worth, respective, `c[0]` dollars, `c[1]` dollars, ..., and `c[n-1]` dollars, where `1 = c[0] < c[1] < ... < c[n-1]`.

Alice wants to solve the coin changing problem: what is the minimum number of coins needed to make a change of exactly `m` dollars? She proposes the following greedy algorithm: first use as many as possible the most valuable coin, then use as many as possible the second most valuable coin, and so on.

(a) Complete the following program so that it implements the greedy algorithm described above. At the end of the program, `b[i]` should equal the number of `c[i]`-dollar coins used. The input and output sections of the program are omitted. You may assume that `1 ≤ n ≤ 100`.

```cpp
int b[100], c[100];
int n, m, i;
int main() {
    // input n, m, c[0], c[1], ..., c[n-1]
    for (_________H_________) {
        b[i] = 0;
        while (_________I_________) {
            b[i]++;
            m = _________J_________;
        }
    }
    // output b[0], b[1], ..., b[n-1]
}
```

- `H`: _______________________

- `I`: _______________________

- `J`: _______________________



(b) Unfortunately, Alice's greedy algorithm does not always work. Find a counter-example with `n = 3, 1 = c[0] < c[1] < c[2] ≤ 10`, and `m = 10`. Write down the values of `c[1]` and `c[2]`.

- `c[1]`: _______________________

- `c[2]`: _______________________

(c\) A coin system `c[0..n-1]` is said to be *simple*, if Alice's greedy algorithm can produce an optimal answer for every positive integer `m` not greater than 10000. Which of the following coin systems is/are simple? Write down the corresponding indices of all simple coin systems. (Example: B, C, D)

- A. `{1, 8, 20}`
- B. `{1, 2, 5, 10}`
- C. `{1, 2, 4, 8, 10}`
- D. `{1, 4, 7, 10, 13, 16, 19}`
- E. `{1, 20, 30, 40, 50, 60, 70}`

#### 10. [J222 - Spicy Ramen](https://judge.hkoi.org/task/J222)
- Subtask 1 & 2
- Subtask 3
- All subtasks

