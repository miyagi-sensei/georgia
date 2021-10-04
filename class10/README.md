# Class 10
## [j194 Graffiti](https://judge.hkoi.org/task/J194)
### Problem Statement
- A triangular wall of height N
- A harmonious wall:
    - a) if brick (i, j) is black, then BOTH OF THE 2 BRICKS right below it ( (i+1, j) and (i+1, j+1) ) must be black
    - b) if brick (i, j) is white, then AT LEAST ONE of the 2 bricks right below it ( (i+1, j) and (i+1, j+1) ) must be white

- (a) means black ink flows downward
- (b) can be rewritten as: if BOTH of THE 2 BRICKS (i+1, j) and (i+1, j+1) are black, brick (i, j) must be black.
- therefore (b) means black in flows upward: if the base is black, then the whole triangle above it is also black.

![demo](https://github.com/miyagi-sensei/georgia/blob/main/class10/j194.png)

## Code Tracing
What is the output of the following program?
```c++
int arr[8] = {-3, 2, 6, 7, 9, -5, -10, 11};
int ans = 0;
int i;
int main() {
  for (i=0; i<=7; i++) {
    if (arr[i] % 2 == 1)
      ans = ans + arr[i];
    else
      ans = ans - arr[i];
  }
  cout << ans;
}
```
Work through the program using **tables**.

---

What is the output of the following program?
```c++
string s = "hkoi201718";
char temp;
int i;
int arr[6] = {1, 4, 0, 3, 5, 2};
int main() {
  for (i=0; i<=5; i++) {
    s[i + arr[i]] = s[i + 1];
  }
  cout << s;
}
```

What is the output of the following program?
```c++
string s = "hkoi201718";
char temp;
int i;
int arr[6] = {1, 4, 0, 3, 5, 2};
int main() {
  for (i=0; i<=5; i++) {
    temp = s[i + arr[i]];
    s[i + arr[i]] = s[i + 1];
    s[i+1] = temp;
  }
  cout << s;
}
```

---

## Combinatorics questions
1. There are 4 seats arranged in a row. Alice, Bob, Charlie and Dave are each going to choose a seat. Alice should not sit next to Bob, and Charlie should not sit next to Dave. How many seating arrangements are there?
<br>

________________

2. How many ways are there to pick, at the same time, two different integers between 1 and 8 (inclusive), such that their product is not a multiple of four?
<br>

________________

3. Assume function `random(n)` returns an integer from 0 to n-1 randomly with equal probability. Consider the following C++ program:
```
int i, a, b;
int main() {
  a = random(4) * 2;
  b = random(3) + random(3);
  cout << b - a;
  return 0;
}
```
What is the number of possible different outputs?

<br>

________________

4. Consider the number 214748347. It has 9 digits. There are 2<sup>9-1</sup> = 256 ways to insert (possibly zero) plus signs (+) between the digits to obtain an arithmetic expression. For example, `214748347`, `2+1+4+7+4+8+3+4+7`, and `214+74+8+347` are three ways. How many of these arithmetic expressions evaluates to an odd number?
<br>

________________

## Logic and Bitwise Operations
Which of the following pairs of statements are logically equivalent?<br>

1. If it is raining then the ground is wet.<br>
    If the ground is not wet then it isn’t raining.<br>
2. If it is raining then the ground is wet.<br>
    The ground is wet or it is not raining.<br>

A.  1 only<br>
B.  2 only<br>
C.  1 and 2<br>
D.  None of them 

<br>

____________


If Charlie gets full marks in the final exam, he feels happy; if Charlie feels happy and it is raining outside, he plays computer games at home. Charlie is not playing computer games at home. Which of the followings must be true?

A. Charlie does not get full marks in the final exam<br>
B. Charlie does not feel happy<br>
C. It is not raining outside<br>
D. None of the above

<br>

____________

Alice, Bob and Charlie are invited to a party. However, they still haven’t decided whether they will go to the party or not. If Alice goes then Bob will also go; if Alice and Bob both go, then Charlie will not go. Which of the following is/are possible situations?

i.    Only Alice and Bob go<br>
ii.   Only Alice and Charlie go<br>
iii.  Only Bob and Charlie go<br>

A. i only<br>
B. ii only<br>
C. i and iii only<br>
D. ii and iii only

<br>

____________

Suppose this statement is true: “If I eat this giant cookie, then I will feel sick.” Which of the following statements must also be true?

A. If I feel sick, then I ate that giant cookie.<br>
B. If I don’t eat this giant cookie, then I won’t feel sick.<br>
C. If I don’t feel sick, then I didn’t eat that giant cookie.

<br>

________________________________________________________________________________

“Somebody brought a flashlight.” Write the negation of this statement.

<br>

________________________________________________________________________________

“There are no prime numbers that are even.” Write the negation of this statement.

<br>

________________________________________________________________________________

“All Chinese children learn English in school.” Write the negation of this statement.

<br>

_______________________

Truth table for *NOR*
|operand 1|operand 2|result|
|---|---|---|
|F|F|T|
|F|T|F|
|T|F|F|
|T|T|F|

Which of the following expressions is equivalent to `((not A) and B)`?

A. `A nor (B nor B)`<br>
B. `(A nor A) nor B`<br>
C. `(A nor B) nor B`<br>
D. `(A nor B) nor (B nor B)`

<br>

_______________________

Suppose `x` is a boolean variable. Evaluate the following expression in C/C++.<br>
`(x && (!x)) == false`

<br>

_______________________

Given that there is only one correct answer for this question, which one is the correct answer?

A. Neither B nor C is the correct answer<br>
B. Netiher C nor D is the correct answer<br>
C. Trust me, this is the correct answer<br>
D. Neither A nor B is the correct answer

<br>

_______________________

Which of the following pair(s) of boolean expressions are logically equivalent?

1. `x || (!x && y)`<br>
    `(x && !y) || y`
2. `(x || !y) ^ (!x || y)`<br>
    `(x && !y) || (!x && y)`

A. 1 only<br>
B. 2 only<br>
C. 1 and 2<br>
D. None of them

<br>

_______________________

# Homework
- [2017/18 Junior Heat Event Paper](https://assets.hkoi.org/ref/2018hj.pdf)
- [Anser sheet](https://assets.hkoi.org/ref/2018hja.pdf)
- [Solution](https://hkoi.org/en/past-problems/)
