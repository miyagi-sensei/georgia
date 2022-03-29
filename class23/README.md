# Class 23 - Code Reading Quiz
**Do not cheat by using the computer to run these code. These are valuable practice exercises for your "mind muscles".**
Submit your answers by email to haye@miyagiacademy.com or by DM over Discord.

#### 1. Suppose `a` is an array of four 32-bit signed integers (`int a[4]`). Is it **true** or **false** that the following two code snippets always produce equivalent output?
```cpp
for (w=0; w<a[0]; w++)
    for (x=0; x<a[1]; x++)
        for (y=0; y<a[2]; y++)
            for (z=0; z<a[3]; z++)
                cout << "IOI" << endl;
```
```cpp
for (i=0; i<4; i++)
    for (j=0; j<a[i]; j++)
        cout << "IOI" << endl;
```

#### 2. Suppose `a` is an array of four 32-bit signed integers (`int a[4]`). Is it **true** or **false** that the following two code snippets always produce equivalent output?
```cpp
int main() {
    for (w=0; w<a[0]; w++)
        for (x=0; x<a[1]; x++)
            for (y=0; y<a[2]; y++)
                for (z=0; z<a[3]; z++)
                    cout << "IOI" << endl;
}
```
```cpp
void recur(int i) {
    if (i == 4) {
        cout << "IOI" << endl;
        return;
    }
    for (int j=0; j<a[i]; j++)
        recur(i+1);
}
int main() {
    recur(0);
}
```

#### 3. Assume that function `r()` returns a random integer between `0` and `65535` inclusive uniformly and independently, Does the function `f()` always returns `true`? (Write down **true** or **false**)
```cpp
int A() {
    return r();
}
int B() {
    return r();
}
bool f() {
    return (A() > B()) ^ (A() <= B());
}
```

#### 4. What is the output of the following program?
```cpp
int a[105];
int i, j;
int main() {
    for (i=0; i<=104; i++)
        a[i] = 1;
    for (i=2; i<=100; i++) {
        if (a[i] == 1) {
            j = i + i;
            while (j <= 100) {
                a[j] = 0;
                j = j + i;
            }
        }
    }
    cout << a[1] << " " <<  a[91] << " " << a[97];
    return 0;
}
```

#### 5. What is the output of the following program?
```cpp
int a[10] = {2, 5, 6, 9, 15, 18, 21, 35, 49, 50};
int res, x, i, j;
bool flag;
int main() {
    res = 0;
    for (i=0; i<10; i++) {
        if (a[i] == 0)
            continue;
        flag = false;
        x = a[i];
        for (j=i; j<10; j++) {
            if (a[j] % x == 0) {
                a[j] = 0;
                flag = true;
            }
        }
        if (flag)
            res++;
    }
    cout << res;
    return 0;
}
```
#### 6. Complete the following program **WITHOUT** using array `a` so that array `b` is equal to array `a`.
```cpp
int a[9], b[9];
int i;
int main() {
    for (i=0; i<9; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    for (i=1; i<9; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i-1];
    }
    for (i=1; i<9; i++)
        _________A_________
    return 0;
}
```
A: _______________

The above program is modified to the following program. Complete the following program **WITHOUT** using array `a` so that array `b` is equal to array `a`. 
```cpp
int a[9], b[9];
int i;
int main() {
    for (i=0; i<9; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    for (i=1; i<9; i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    for (i=1; i<9; i++)
        _________B_________
    return 0;
}
```
B: _______________

#### 7. Words in a dictionary are sorted in lexicographical order. Letter "a" is smaller than "b" and "b" is smaller than "c", etc. To compare two words in lexicographical order, we compare the leftmost letter from both words first. If their leftmost letters are different then the word with smaller leftmost letter is smaller. If their leftmost letters are equal then compare the next letter until the last letter of the shorter word. If we cannot determine after the above process, the shorter word is smaller. So "abc" is smaller than "d", "abc" is smaller than "abd", "abc" is equal to "abc" and "bcd" is smaller than "bcda".<br>
Complete the function `cmp`, so that the function `cmp` return `0` when string `a` is smaller than or equal string `b` and return `1` when string `a` is larger than string `b` in lexicographical order.
```cpp
int cmp(string a, string b) {
    int x = a.length();
    int y = b.length();
    int s = 0;
    while (______C______) {
        if (______D______)
            return 0;
        if (______E______)
            return 1;
        s++;
    }
    if (______F______ == x)
        return 0;
    else
        return 1;
}
```
- C: _______________
- D: _______________
- E: _______________
- F: _______________

#### 8. Consider the following function:
```cpp
int f(int x) {
    int res = 0;
    int i;
    for (i=1; i<=x; i++)
        if (x % i == 0)
            res++;
    return res;
}
```
- What is the return value of `f(12)`?  __________
- What is the return value of `f(169)`?  __________

The following program uses the function `f` above. What is the output of the program?  __________
```cpp
int c, i;
int main() {
    c = 0;
    for (i=1; i<=10000; i++)
        if (f(i) == 3)
            c++;
    cout << c;
    return 0;
}
```

#### 9. What is the output of the following program?
```cpp
int x, y, z, i;
int main() {
    x = 0;
    y = 0;
    z = 0;
    for (i=1; i<=2022; i++) {
        if (i % 20 == 0)
            x++;
        else if (i % 10 == 0)
            y++;
        else
            z++;
    }
    cout << x << ' ' << y << ' ' << z;
    return 0;
}
```

#### 10. Consider the following program:
```cpp
int TOP = 150;
int up, down;
int d, h;
int main() {
    cin >> up >> down;
    d = 0;
    h = 0;
    while (true) {
        h = h + up;
        if (h >= TOP)
            break;
        h = h - down;
        d++;
    }
    cout << d << endl;
    return 0;
}
```
Which of the following input gives the smallest output number? (choose only one)
- A. `102 99`
- B. `33 24`
- C. `10 0`
- D. `50 44`


#### 11. Complete the following program such that its output is `ARENA`.
```cpp
string river = "RIVER";
int a[5];
int i;
int main() {
    for (i=0; i<5; i++)
        a[i] = (int)river[i] - (int)'A';
    for (i=0; i<5; i++) {
        a[i] = ________G________;
        a[i] = a[i] + (int)'A';
        cout << (char)a[i];
    }
    return 0;
}
```
G: ______________

#### 12. The input to the following program is 401 integers between `1` and `1000` inclusive, given in non-descending order. Complete the following program so that it outputs an integer `x`, such that the sum of absolute difference of `x` and each input number is minimized. If there are multiple `x` that can achieve the same minimum sum, the program should output the least `x`.

```cpp
int a[401];
int x, minSum, temp, i, j;
int main() {
    for (i=0; i<=400; i++)
        cin >> a[i];
    x = -1;
    minSum = 1000000000;
    for (i=1; i<=1000; i++) {
        temp = 0;
        for (j=0; j<=400; j++)
            temp = temp + _______H_______;
        if (temp < minSum) {
            minSum = ________I________;
            x = ________J________;
        }
    }
    cout << x;
    return 0;
}
```
Complete the following program so that it produces the same output as the above program.
```cpp
int a[401];
int i;
int main() {
    for (i=0; i<=400; i++)
        cin >> a[i];
    cout << ________K________;
    return 0;
}
```
- H: _______________
- I: _______________
- J: _______________
- K: _______________

#### 13. Consider the following program:
```cpp
int x, a, b;
int main() {
    cin >> x;
    a = (x - 1) / 2;
    b = (x + 1) / 2;
    if (a < b)
        cout << "<";
    if (a == b)
        cout << "=";
    if (a > b)
        cout << ">";
    return 0;
}
```
Assume that input `x` is an integer between `-1024` and `1023` inclusive. Which of the followings is/are possible output(s)? (choose any number of them, or none at all)
- A. `<=`
- B. `<`
- C. `=`
- D. `>`

#### 14. Consider the following progrma:
```cpp
int a[8], p[8];
int i;
int main() {
    for (i=0; i<8; i++)
        cin >> a[i];
    for (i=1; i<8; i++)
        p[i] = p[i-1] + a[i];
    cout << (p[6] - p[5]) * (p[4] - p[2]);
    return 0;
}
```
On which of the following inputs does the program output the largest number? (choose only one)
- A. `3 1 4 1 5 9 8 6`
- B. `5 3 5 8 9 7 3 2`
- C. `2 3 8 4 6 2 6 4`
- D. `3 3 8 3 2 7 9 5`

#### 15. What is the output of the following program?
```cpp
int a[200];
int i, j, sum = 0;
int main() {
    for (i=30; i>=1; i--)
        a[i] = i;
    for (i=30; i>=1; i--) {
        for (j=1; j<=a[i]; j++)
            a[i-1] = a[i-1] / 2;
        sum = sum + a[i];
    }
    cout << sum;
    return 0;    
}
```

#### 16. Consider the following program:
```cpp
int x, y;
int main() {
    cin >> x >> y;
    if (x / 2 <= y / 2)
        cout << "a";
    if (x / 3 == y / 3)
        cout << "b";
    if (x / 5 >= y / 5)
        cout << "c";
    return 0;
}
```
Assume inputs `x` and `y` are integers between `1` and `100` inclusive. Which of the followings are possible outputs of the program above? (choose any number of them, or none at all)
- A. `ab`
- B. `ac`
- C. `bc`

#### 17. Consider the following function:
```cpp
int f(int n) {
    while (n % 2 == 0)
        n = n / 2;
    return n;
}
```
Which of the followings returns the largest value? (choose one only)
- A. `f(5120)`
- B. `f(122)`
- C. `f(4032)`
- D. `f(65536)`

#### 18. The input to the following program is 100 integers between `0` and `10000` inclusive. The program tries to output the number of distinct integers in the input. However, the program contains an error that can be fixed by changing exactly one line. Find the line and correct.
```cpp=
int a[100], f[10001];
int i, answer;
int main() {
    answer = 0;
    for (i=0; i<=10000; i++)
        f[i] = 0;
    for (i=0; i<100; i++)
        cin >> a[i];
    for (i=0; i<100; i++)
        f[a[i]]++;
    for (i=0; i<100; i++)
        if (f[i] > 0)
            answer++;
    cout << answer;
    return 0;
}
```
- Line number: ____________
- Correction: ________________________

#### 19. The following program tries to delete all negative numbers in the array `a`. However, the program contains an error.
```cpp=
int n, i, j, a[100];
int main() {
    cin >> n;
    i = 0;
    while (i < n) {
        cin >> a[i];
        i++;
    }
    i = 0;
    while (i < n) {
        if (a[i] < 0) {
            j = i + 1;
            while (j < n) {
                a[j-1] = a[j];
                j++;
            }
            n--;
        }
        i++;
    }
    i = 0;
    while (i < n) {
        cout << a[i] << " ";
        i++;
    }
    return 0;
}
```
The bug can be fixed by changing exactly one line. Find the line and correct it so that the program outputs the correct answers for all of the following cases:
|Input|Output|
|---|---|
|`5 1 2 -3 -4 5`|`1 2 5`|
|`2 -5 3`|`3`|
|`4 -3 -4 8 -6`|`8`|

- Line number: ________________
- Correction: ________________

---

# Answer Key
1. False
2. True
3. False (Each separate call to `A()` generates another random number. Same for `B()`)
4. `1 0 1`
5. `5`
6. A: `b[i] += b[i-1];`, <br>B: `b[9-i] -= b[8-i-];`
7. C: `s < x && s < y` or `s < min(x, y)`,<br> D: `a[s] < b[s]`, <br>E: `a[s] > b[s]`, <br>F: `s`
8. `6`, <br>`3`, <br>`25`
9. `101 101 1820`
10. D
11. `"ARENA"[i] - 'A'` or `(a[i]+9)%26` or `a[i] + (i%2)*26 - 17`
12. H: `abs(i - a[j])`, <br>I: `temp`, <br>J: `i`, <br>K: `a[200]`
13. B & C
14. C
15. `240`
16. A, B, C
17. C
18. line 11, `for (i=0; i<=10000; i++)` or `for (i=0; i<10001; i++)`
19. line 19, `else i++;` or <br>line 17, `n--; i--;` or <br>line 17, `n--; continue;` or<br>line 18, `else`
