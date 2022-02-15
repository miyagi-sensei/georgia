# Class 18 - Code Tracing (Dry Run)
**Do not cheat by using the computer to run these code. These are valuable practice exercises for your "mind muscles".**<br>
Submit your answers by email to haye@miyagiacademy.com or put the replit link to your answers at the "Info" sheet in [Grade Book](https://docs.google.com/spreadsheets/d/153Rdb201QqXYEgA10LkmzH0EehwarO_dim-_EhImt_E/edit?usp=sharing).

1. What is the output of the following program?
```cpp
int a[10] = {3, 7, 2, 6, 3, 6, 1, 7, 0, 9};
int b[10];
int main() {
    for (int i = 0; i < 10; i++)
        b[a[i]] = b[a[i]] + a[i];
    cout << b[3] << " " << b[5] << " " << b[6];
    return 0;
}
```

2. What is the output of the following program?
```cpp
int x = 345;
int main() {
    x = x / 10 + 100 * (x % 10);
    cout << x;
    return 0;
}
```

3. What is the return value of the following function?
```cpp
int f() {
    int res, x;
    res = 0;
    x = 2058;
    while (x > 0) {
        res += (x % 10);
        x = x / 10;
    }
    return res;
}
```

4. What is the output of the following program?
```cpp
int a[5][5] = { {4, 2, 4, 0, 1},
                {3, 5, 1, 1, 0},
                {3, 0, 4, 5, 2},
                {3, 2, 0, 1, 0},
                {1, 2, 4, 3, 1}}
int x, y, i, next;
int main() {
    x = 0;
    y = 0;
    i = 0;
    while ((x != 5) && (y != 5)) {
        next = a[x][y];
        if (i % 2 == 0)
            x = next;
        else
            y = next;
        i++;
    }
    cout << i;
    return 0;
}
```

5. The program tries to evaluate an additive expression from the input. However, the program contains an error. For example, the program outputs `51` when the input is `100+1`.
```cpp
 1.string s;
 2.int sum, temp, len, i, x;
 3.int main() {
 4.    cin >> s;
 5.    sum = 0;
 6.    temp = 0;
 7.    len = s.length();
 8.    i = 0;
 9.    while (i < len) {
10.        if (s[i] == '+') {
11.            sum += temp;
12.            temp = 0;
13.        }
14.        x = int(s[i]) - int('0');
15.        temp = temp * 10 + x;
16.        i++;
17.    }
18.    cout << sum + temp;
19.    return 0;
20.}
```

- What is the output when the input is `24+24`?
- The bug can be fixed by changing exactly one line. Find the line and correct it so that it outputs the correct answer:

Mistaken line: `________A________`

Correction: `_________B_________`


6. What is the return value of `fact(10, 4)`?
```cpp
int fact(int x, int y) {
    if (x <= 0)
        return 1;
    else
        return x * fact(x - y, y - 1);
}
```

7. Consider the function above again. What is the return value of `fact(12, 5)`?<br>

8. Consider the following program segment:
```cpp
bool g(int);
bool f(int n) {
    return (n == 0) || g(n - 1);
}
bool g(int n) {
    return (n != 0) && f(n - 1);
}
```
What are the return values of `f(107)` and `g(71)` respectively?
- `f(107)`: _______________
- `g(71)`: _______________

9. What is the output of the following program?
```cpp
int a[10] = {3, 1, 4, 1, 2, 7, 1, 8, 6, 5};
int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i;
int f(int x) {
    if (b[x] == x)
        return x;
    else
        return f(b[x]);
}
int main() {
    for (i = 0; i < 10; i++)
        b[i] = f(a[i]);
    cout << f(b[2]) << " ";
    cout << f(b[7]);
    return 0;
}
```

10. Consider the following program:
```cpp
int a, b, x;
int main() {
    cin >> a >> b;
    x = a / 2;
    a = a - x;
    b = b + x;
    x = b / 4;
    a = a + x;
    b = b - x;
    cout << a << " " << b;
    return 0;
}
```
Given that the output of the above program is `30 30`, which of the followings can be the program's input? (choose only one)<br>
A. `44 16`<br>
B. `46 14`<br>
C. `39 21`<br>
D. `35 25`<br>

11. What is the output of the following program?
```cpp
string s = "hkoi201718";
char temp;
int i;
int arr[6] = {1, 4, 0, 3, 5, 2};
int main() {
    for (i = 0; i < 6; i++) {
        temp = s[i + arr[i]];
        s[i + arr[i]] = s[i + 1];
        s[i+1] = temp;
    }
    cout << s;
    return 0;
}
```

12. What is the output of the following program?
```cpp
int a[8] = {3, 1, 4, 1, 5, 9, 2, 6};
int i, j;
int main() {
    for (i = 1; i < 8; i++)
        for (j = 0; j <= 7 - i; j++)
            if (a[j] > a[j + 1]) {
                a[j] = a[j + 1];
                a[j+1] = a[j];
            }
    cout << a[1] << " " << a[6];
}
```

13. What is the output of the following program?
```cpp
int dx[4] = {1, 2, 3, 4};
int dy[4] = {4, 3, 2, 1};
int x = 101, y = 100;
int i;
int main() {
    for (i = 1; i <= 200; i++) {
        x += dx[x % 4];
        y += dy[y % 4];
    }
    cout << x << ' ' << y;
    return 0;
}
```

14. What is the output of the following program?
```cpp
int a[8] = {2, 0, 2, 1, 1, 1, 1, 3};
int x;
int main() {
    x = 0;
    if (a[3] == 2)
        x++;
    else if (a[6] % 2 == 1)
        x += 2;
        if (a[4] == a[7])
            x += 3;
    else
        x += 4;
    cout << x;
    return 0;
}
```

15. What is the output of the following program?
```cpp
int n, cnt;
int i, j, k;
int main() {
    n = 10;
    cnt = 0;
    for (i = 0; i < n; i++)
        for (j = i + 2; j < n; j++)
            for (k = j - 1; k < n - 1; k++)
                cnt++;
    cout << cnt;
    return 0;
}
```

16. Consider the following program:
```cpp
int a;
int main() {
    cin >> a;
    if (a % 2 == 0)
        a = a / 2;
    if (a % 3 == 0)
        a = a / 3;
    if (a % 4 == 0)
        a = a / 4;
    if (a % 5 == 0)
        a = a / 5;
    cout << a;
    return 0;
}
```
Given that the input is an integer between `1` and `100` inclusive, for how many inputs will the program output `1`?

17. What is the output of the following program?
```cpp
int a[15], p[15];
int i, j, k;
int main() {
    k = 0;
    for (i = 0; i < 11; i++)
        a[i] = 0;
    for (i = 0; i < 11; i++) {
        if (a[i] == 0) {
            k++;
            p[k] = i;
        }
        j = 1;
        while ((j <= k) && (i * p[i] <= 10)) {
            a[i * p[j]]++;
            if (i % p[j] == 0)
                break;
            j++;
        }
    }
    cout << a[k];
    return 0;
}
```
