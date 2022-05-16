# Class 29 - Analytical Mind <sub>("MO type questions")</sub>

### Warm up:
- What is the answer to: 1 + 2 + 3 + 4 + ... + 50
- What is the answer to: 1 + 3 + 5 + 7 + ... + 49
- What is the answer to: 1 + 4 + 9 + 16 + ... + 20<sup>2</sup>
    - What if I just ask you to choose among these 3 options?
        A) 1435
        B) 2870
        C) 5640

## Quiz
Submit your answers by email to haye@miyagiacademy.com or by DM over Discord. Don't cheat by using the calculators or with the help of any electronic devices.

#### 1. Alice has an integer between -32 and 32 (inclusive) in her mind. You can ask her some questions, each of which must be in the form of "is your number strictly less than x" (x can be any real number). You can decide the question you are going to ask according to the answers of previous questions. In the worst case, at least how many questions should be asked to know the exact value of the integer Alice has in mind?

--- 

#### 2. What is the output of the program?
```cpp
int i, sum, sum2;
int main() {
    sum = 0;
    sum2 = 0;
    for (i=1; i<=80; i++) {
        if (i % 2 == 0)
            sum += i;
            sum2 += i * i;
    }
    cout << sum << " " << sum2;
}
```
- A. 1640 86940
- B. 3280 86940
- C. 1640 173880
- D. 3280 173880

---

#### 3. Is this statement below true or false?
> In a party, some participants have shaken hands with each other. If a total of `n` participants have shaken hands and all `n` of them happen to have shaken hands with an odd number of participants, `n` must be even. 

---

#### 4. Given that the function `median(a, b, c)` returns the median of three integers `a, b, c`. Consider the following program segment:
```cpp
int f(int a) {
    if (a < 0)
        return -a;
    else
        return a;
}
int range(int a, int b, int c) {
    int m = median(a, b, c);
    return ________A________;
}
```
Complete the function `range`, so that `range(x, y, z)` returns the range of `x, y, z` (i.e. the greatest value minus the least value among `x, y, z`) for integers `x, y, z` (`-100 ≤ x, y, z ≤ 100`). You may use the function `f`.

- A: _________________________

---

#### 5. Given that `f(n)` is a function that returns the number of integers `x` where `1 ≤ x < n` and `x` and `n` are coprime (i.e. they have no common divisors except 1). Given two distinct primes `p`, `q`, find `f(p × q)`. (Choose only one)
- A. (p-1) × (q - 1)
- B. f\(p\) + f(q)
- C. p × q
- D. p + q

---

#### 6. Palindromes are strings that read the same forward or reversed. For example "ABBA" is a palindrome while "ABCD" isn't. Which of the following strings can be re-ordered to form a palindrome? (Choose any number of them, or none at all)
- i. ZZYZXYZ
- ii. BCBACCCAACA
- iii. RQPSPRQRPSPS

---

#### 7. A string `s[1...L]` of length `L` is said to be periodic, if there exists a positive divisor P or L, such that P < L and `s[i + P] = s[i]` for `1 ≤ i ≤ L - P`. Which of the following strings can be re-ordered to form a periodic string? (Choose any number of them, or none at all)
- i. THAIHTIA
- ii. ACABCABBA
- iii. AMAOOOOOOAMA

---

##### 8. Let `a[0..999]` be an integer array sorted in ascending order. In array `a`, given that there exists a value x that appears more than 500 times, at least how many elements need(s) to be accessed to obtain its value?

---

#### 9. Five teams participate in a basketball league. Every two teams play one match between them. The winner gets one point and the loser gets zero points. There are no draws. Which of the following **cannot** be the total points the team have at the end of the league? (Choose only one)
- A. 4, 2, 2, 1, 1
- B. 2, 2, 2, 2, 2
- C. 4, 3, 2, 1, 0
- D. 4, 4, 1, 1, 0

---

#### 10. Consider a `n × m` grid (`1 ≤ n, m ≤ 1000`), where every cell is placed with a light bulb that is initially turned off. Each of the `n` rows and `m` columns of the grid is connected to an individual button, which toggles (on→off, off→on) all the light bulbs in that corresponding row/column when pressed. Complete the following program so that it reads the status (pressed: `1`, not pressed `0`) of every button and outputs the number of light bulbs that are ultimately on. `r[i]` and `c[j]` stores the status of the button of the i-th row and the j-th column respectively.
```cpp
int r[1000], c[1000];
int n, m, x, y, i, j;
int main() {
    cin >> n >> m;
    x = 0;
    for (i=0; i<n; i++) {
        cin >> r[i];
        x += r[i];
    }
    y = 0;
    for (j=0; j<m; j++) {
        cin >> c[j];
        y += c[j];
    }
    cout << _______B_______;
    return 0;
}
```
- B: _________________________

---

## Answer Key
1. 7
2. C - `1640 173880`
3. true
4. `f(a - m) + f(b - m) + f(c - m)`
5. A
6. i && ii
7. i & iii
8. 1
9. D (there can't be 2 undefeated teams)
10. `x*m + y*n - 2*x*y`
