# Combinatorics
### 1
There are 6 seats in a row and 6 students. How many ways are there to arrange their seats?

<br>

________________

### 2
There are 10 seats in a row and 10 students. How many ways are there to arrange their seats?

<br>

________________

### 3
6 boys and 4 girls are taking a group photo. There are 4 chairs for the girls to sit on. How many different arrangements are there for the photo?For example: the girls’ names are Amy, Belinda, Cathy, Debbie and the boys’ names are Alan, Benny, Chuck, Daniel, Ethan, Frank. And below are 2 possible arrangements:
|Seats|ACDB|
|---|---|
|Standing|DBACEF|

|Seats|DACB|
|---|---|
|Standing|EFDBAC|

<br>

________________

### 4
How many ways are there to seat 6 people at a roundtable of 6 seats? (To clarify, the orientation does not matter. What matters is merely to whom each person sits next.)

<br>

________________

### 5
A competitive programming club has 5 members. How many ways are there to choose, among the members, one president and one vice presidents?

<br>

____________

### 6
A competitive programming club has 5 members. How many ways are there to choose, among the members, 2 vice presidents?

<br>

____________

### 7
A competitive programming club has 5 members. How many ways are there to choose, among the members, one president and 2 vice presidents?

<br>

____________

### 8
A competitive programming club has 10 members. How many ways are there to choose, among the members, one president and 2 vice presidents?

<br>

____________

### 9
A competitive programming club has 6 members. How many ways are there to choose, 3 vice presidents?

<br>

____________

### 10
A competitive programming club has 10 members. How many ways are there to choose, 2 presidents and 3 vice presidents?

<br>

____________

### 11
Jane’s mother knows how to cook 10 dishes for lunch. For the next 5 days, Jane’s mother wants to create a 5-day lunch menu for Jane. How many different menus can Jane’s mother possibly create? (Jane is okay with a menu with repeating dishes)

<br>

____________

### 12
Jane’s mother knows how to cook 10 dishes for lunch. For the next 5 days, Jane’s mother wants to create a 5-day lunch menu for Jane. How many different menus can Jane’s mother possibly create? (Jane would not tolerate repeating dishes, i.e. Jane does not want to have the same lunch twice within a 5-day period)

<br>

____________

### 13
Jane’s mother knows how to cook 10 dishes for lunch. For the next 10 days, Jane’s mother wants to create a 10-day lunch menu for Jane. How many different menus can Jane’s mother possibly create? (Jane would not tolerate repeating dishes, i.e. Jane does not want to have the same lunch twice within a 5-day period)

<br>

____________


### 14
There are 4 seats arranged in a row. Alice, Bob, Charlie and Dave are each going to choose a seat. Alice should not sit next to Bob, and Charlie should not sit next to Dave. How many seating arrangements are there?

<br>

________________

### 15
There are 6 seats arranged in a row. Alice, Bob, Charlie, Dave, Ethan and Frank are each going to choose a seat. Alice should not sit next to Bob, and Charlie should not sit next to Dave. How many seating arrangements are there?
<br>
### Method of exclusion:
- If there are no rules, we would have 6!, or 720 arrangements.
- Imagine we only have 5 kids: Alice-Bob, Charlie, Dave, Ethan and Frank. There would be 5! ways to arrange them. We need to subtract every one of those arrangements from 720.
- But Notice for each of those 5! ways, we could have arranged Alice-Bob 2 ways, i.e. Alice-Bob or Bob-Alice. So there are really 5! * 2 ways to be subtracted.
- Similarly imagine we have 5 kids: Alice, Bob, Charlie-Dave, Ethan and Frank. We need to subtract another 5! * 2 ways too.
- Finally we are double-subtracting the arrangements when *both Alice-Bob and Charlie-Dave* are stuck together. We need to add them back. That's 4! * 4 because for both Alice-Bob and Charlie-Dave, we can arrange them also as Bob-Alice and/or Dave-Charlie.
- So answer is 6! - 5! * 4 + 4! * 4 = 336

________________

### 16
How many ways are there to pick, at the same time, two different integers between 1 and 8 (inclusive), such that their product is not a multiple of four?

<br>

________________

### 17
Assume function `random(n)` returns an integer from 0 to n-1 randomly with equal probability. Consider the following C++ program:
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

### 18
Consider the number 214748347. It has 9 digits. There are 2<sup>9-1</sup> = 256 ways to insert (possibly zero) plus signs (+) between the digits to obtain an arithmetic expression. For example, `214748347`, `2+1+4+7+4+8+3+4+7`, and `214+74+8+347` are three ways. How many of these arithmetic expressions evaluates to an odd number?

<br>

________________

### 19
Consider the number 2147493647. It has 10 digits. There are 2<sup>10-1</sup> = 512 ways to insert (possibly zero) multiplication signs (*) between the digits to obtain an arithmetic expression. For example, `2147493647`, `2*1*4*7*4*9*3*6*4*7`, and `214*74*9*3647` are three ways. How many of these arithmetic expressions evaluates to an odd number?

<br>

________________

## Code reading exercise
Which of the following program segments is an implementation of bubble sort?
`n` is the size of the array `int a[n]`.<br>
A.
```c++
for (i=0; i<=n-1; i++)
  for (j=i; j>=1; j--)
    if (a[j] < a[j-1]) {
      temp = a[j];
      a[j] = a[j-1];
      a[j-1] = temp;
    }
```
B.
```c++
for (i=0; i<=n-1; i++)
  for (j=i; j<=n-2; j++)
    if (a[j] > a[j+1]) {
      temp = a[j];
      a[j] = a[j+1];
      a[j+1] = temp;
    }
```
C.
```c++
for (i=0; i<=n-1; i++)
  for (j=0; j<=i-1; j++)
    if (a[j] > a[j+1]) {
      temp = a[j];
      a[j] = a[j+1];
      a[j+1] = temp;
    }
```
D.
```c++
for (i=0; i<=n-1; i++)
  for (j=n-1; j>=i+1; j--)
    if (a[j] < a[j-1]) {
      temp = a[j];
      a[j] = a[j-1];
      a[j-1] = temp;
    }
```

You need to practice enough so that you can read these code to reckon what they do. 

> Practice makes perfect!
