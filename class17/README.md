# Class 17 - Logic/Boolean/Bitwise
- Make sure your name and info is populated in the "Info" tab of this Google Sheet: [grade book](https://docs.google.com/spreadsheets/d/153Rdb201QqXYEgA10LkmzH0EehwarO_dim-_EhImt_E/edit?usp=sharing)
- Submit your answers by email to haye@miyagiacademy.com or by DM @sensei over Discord.
   - Or put your answers in your replit folder as a .txt file, then submit the link to the #during-training discord channel.

---

## Quiz
1. `a`, `b`, `c` are 3 integer variables whereas `a < b`. Write a boolean expression that determines whether `c` is between `a` and `b` (inclusive) **without** using the logical AND operator `&&`. <br>
In other words, write a boolean expression that is true if and only if `c` lies somewhere between `a` and `b` (inclusive).

### Boolean algebra
The following 4 equations can be derived from each other.
- `!(A || B) == !A && !B`
- `!(A && B) == !A || !B`
- `A || B == !(!A && !B)`
- `A && B == !(!A || !B)`

2. Which of the following boolean expressions are logically equivalent to `P AND (NOT (Q OR R))`?<br>
*(you may choose none, one or more than one answers)*<br>
i. `P AND ((NOT Q) AND (NOT R))`<br>
ii. `NOT ((NOT P) OR (Q OR R))`

3. Given a function `f` that takes the coordinates of two horizontal line segments as prameters, where:
    * line segment `a` connects two points `(ax1, ay)` and `(ax2, ay)` and it is guaranteed that `ax1 ≤ ax2`.
    * line segment `b` connects two points `(bx1, by)` and `(bx2, by)` and it is guaranteed that `bx1 ≤ bx2`.

    Complete `f` **WITHOUT** using any function calls, so that it returns `true` if and only if `a` and `b` share at least one point.
```
bool f(int ay, int ax1, int ax2, 
       int by, int bx1, int bx2) {
    return _______A_______
}
```
`_____A_____` should be:

* Given another function `g` that takes the coordinates of a rectangle and a line segment as parameters, where:
    * rectange`a` has `(ax1, ay1)` as bottom-left vertex and `(ax2, ay2)` as top-right vertex. It is guaranteed that `ax1 ≤ ax2` and `ay1 ≤ ay2`.
    * line segment `b` connects two points `(bx1, by)` and `(bx2, by)` and it is guaranteed that `bx1 ≤ bx2`.
* Complete `g`, so that it returns `true` if and only if `a` and `b` share at least one point. You may use function `f` in function `g`.
```
bool g(int ay1, int ay2, int ax1, int ax2,
       int by, int bx1, int bx2) {
    if (ay1 > by || ay2 < by)
        return false;
    else
        return _______B_______;
}
```
`_____B_____` should be:

4. Most Americans are confident. Most Americans are white. Therefore most white people are confident. Is this true (is this deduction logical)?

5. Most Americans are confident. Most confident people are wealthy. Therefore most Americans are wealthy. Is this true (is this deduction logical)?

6. 81% of people in UK has a British accent. Most people in UK likes beer. Therefore at least 1/3 of people with a British accent likes beer.

7. 81% of people in UK has a British accent. Of all the people with a British accent in the world, only 10% are outside UK. Most people in UK likes beer. Therefore at least 1/3 of people with a British accent likes beer.

8. Suppose `a` and `b` are 32-bit signed integer variables (`int`) each storing a positive integer, which of the following expressions are equivalent to (i)? <br>
*(you may choose none, one or more than one answers)*<br>
i. `a == b`<br>
ii. `(a ^ b) == 0`<br>
iii. `(a | b) == (a & b)`<br>
iv. `(a + b) / 2 == a`<br>

### `^` - XOR
- b is a boolean/bit (`0` or `1`)
- `1 ^ b` would "flip" the bit
- `0 ^ b` would keep it unchanged
9. What is `0^0^1^0^1^0`?
10. What about `0^0^1^0^1^1^0^0^1`?
11. What about `0^1^0^0^1^0^1^1^0^1^1^0^1`?
12. Complete the following program such that its output is `HKOI`.
```
int a[10] = {1, 2, 12, 0, 58, 74, 64, 92, 58, 0};
int i, sum;
int main() {
    a[9] = _______C_______;
    sum = 0;
    for (i = 0; i < 10; i++)
        sum = sum ^ a[i];
    if (sum == 108)
        cout << "HKOI";
    return 0;
}
```
`_____C_____` should be:

13. Truth table for *NOR*

|operand 1|operand 2|result|
|---|---|---|
|F|F|T|
|F|T|F|
|T|F|F|
|T|T|F|

Which of the following expressions is equivalent to `((not A) and B)`? (choose only one)<br>
A. `A nor (B nor B)`<br>
B. `(A nor A) nor B`<br>
C. `(A nor B) nor B`<br>
D. `(A nor B) nor (B nor B)`<br>

14. Suppose `x` is a boolean variable. Is the following expression always true?<br>
`(x && (!x)) == false`

15. Which of the following pair(s) of boolean expressions are logically equivalent?<br>
(i). `x || (!x && y)`    vs. `(x && !y) || y`<br>
(ii). `(x || !y) ^ (!x || y)` vs. `(x && !y) || (!x && y)`<br>
A. (i) only<br>
B. (ii) only<br>
C. (i) and (ii)<br>
D. None of them

16. Perform bitwise operations `17 << 1` and `17 << 2`. 
What do you notice?

17. Perform bitwise operations `17 >> 1` and `17 >> 2`. 
What do you notice?

18. Complete the function `f(x)` so that the function `g(ch)` can convert lowercasew letters to uppercase and vice versa. For example, `g('A')` should return `a` and `g('q')` should return `Q`. Fill in `_____D_____`.
```
int f(int x) {
    return ________D_______;
}
char g(char ch) {
    int tmp;
    tmp = (int)ch;
    tmp = f(tmp);
    return (char)tmp;
}
```

19. If there are COVID cases in school, school would be cancelled; if school is cancelled and it is not raining, Ocean Park would be very crowded. Ocean park is not very crowded. Which of the followings must be true? <br>
*(you may choose none, one or more than one answers)*<br>
i. There is no COVID cases in school<br>
ii. Either school is not cancelled or it is raining<br>
iii. It is raining outside<br>
iv. School is not cancelled<br>

20. If there are COVID cases in school, school would be cancelled and tuition fee would be refunded; if school is cancelled, Ocean Park would be very crowded. Ocean park is not very crowded. Which of the followings must be true? <br>
*(you may choose none, one or more than one answers)*<br>
i. There is no COVID cases in school<br>
ii. Tuition fee would be refunded<br>
iii. School would be cancelled or tuition fee would be refunded<br>
iv. School is not cancelled<br>

21. Define the truth table of a logical operator ⓧ as follows: 

|A|B|A ⓧ B|
|---|---|---|
|F|F|T|
|F|T|T|
|T|F|T|
|T|T|T|

Which of the following is logically equivalent to A ⓧ B?<br>
A. `(A OR B) OR (A XOR B)`<br>
B. `(A OR B) XOR (A XOR B)`<br>
C. `(A OR B) OR (A AND B)`<br>
D. `(A OR B) XOR (A NOR B)`<br>

22. Which of the following boolean expressions are logically equivalent?<br>
*(you may choose none, one or more than one answers)*<br>
i. `((NOT a) AND b) OR (a AND (NOT b))`<br>
ii. `NOT (a = b)`<br>
iii. `NOT ((NOT a) = (NOT b))`<br>

23. What is the output of the following program?
```
int x, i, c, t;
int main() {
    x = 79665;
    c = 0;
    for (i = 0; i <= 30; i++) {
        t = 1 << i;
        if ((x & t) != 0)
            c++;
    }
    cout << c;
    return 0;
}
```

24. Consider the following program segment:
```
int f(int n) {
    if (n % 4 == 2)
        return ______E______;
    else
        return ______F______;
}
int g(int n) {
    int i, sum;
    sum = 0;
    for (i = 1; i <= n; i++)
        sum = sum ^ i;
    return sum;
}
```
Write down the return value of `g(10)`:<br>

Complete the function `f`, so that `f(n)` returns the same value as `g(n)` for `10 ≤ n ≤ 100`.
* `______E______` should be:
* `______F______` should be:

