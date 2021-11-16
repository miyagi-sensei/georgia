# Class 14 
# Bitset
- `bitset` in C++ can be extremely convenient in many competitive coding situations.
- See [bitset reference](https://www.cplusplus.com/reference/bitset/bitset)
- Pay attention to object functions `to_ullong` and `to_string`
- Functions such as `set`, `reset`, `flip`, `any`, `none` and `all` can be convenient. But they can all be replicated with a few lines of primitive code. Do that as an exercise.

## It can give you the binary representation of an integer
```c++
int main() {
    int i, j;
    bitset<8> a, b;		// for storing 8 bits
    a = 25;
    b = 45;
    cout << "a     = " << a << endl;	// 00011001
    cout << "b     = " << b << endl;	// 00101101
}
```

You can access each individual bit by using the array notation, e.g. `a[i]`. But remember the bits are stored in the order of least significant bit (LSB) to the most significant bit (MSB), i.e. bit `0` is the least significant bit. Be careful when you print data stored in `bitset`.
```c++
    bitset<8> b = 45;		// 00101101
    cout << "bit 3 of b is: " << b[3] << endl;
```
Would the above snippet print `0` or `1`?

## The common use case for `bitset` is to apply bitwise operators to `bitset`:
```c++
    cout << "a & b = " << (a & b) << endl;	// 00001001
    cout << "a | b = " << (a | b) << endl;	// 00111101
    cout << "a ^ b = " << (a ^ b) << endl;	// 00110100
```

---

## Imagine there are 8 streaming services that have different catalogs of movies and TV shows:
|movies/tv shows|9|8|7|6|5|4|3|2|1|0|
|---|---|---|---|---|---|---|---|---|---|---|
||||||||||||
|streaming<br>service|||||||||||
|0|1|0|1|0|0|1|0|0|1|1|
|1|0|0|0|0|0|1|1|0|1|1|
|2|0|0|0|1|1|1|1|1|1|0|
|3|0|0|0|0|0|1|0|0|1|1|
|4|1|0|0|0|0|1|0|0|1|0|
|5|1|1|0|1|1|1|0|1|1|0|
|6|0|1|0|1|0|1|1|0|1|0|
|7|0|0|1|1|0|1|1|1|1|1|

Notice how the index order of movies/shows are reversed.

You can initialize the data using `bitset`:
```c++
    bitset<10> catalog[8];
    catalog[0] = 0b1010010011;
    catalog[1] = 0b0000011011;
    catalog[2] = 0b0001111110;
    catalog[3] = 0b0000010011;
    catalog[4] = 0b1000010010;
    catalog[5] = 0b1101110110;
    catalog[6] = 0b0101011010;
    catalog[7] = 0b0011011111;
```

- How do you figure out which movies are available on all streaming services? (must-haves)
- If you only subscribe to streaming service 3, 6 and 7, do you have access to all movies/shows?
- What about 3, 5, and 7?

```c++
    bitset<10> ans;
    ans.set();	// set all 10 bits to 1
    for (i=0; i<8; i++) {
        ans = ans & catalog[i];
    }
    printf("                     9876543210\n");		
    printf("                     ----------\n");
    cout << "& result             " << ans << endl;

    ans = catalog[3] | catalog[6] | catalog[7];
    cout << "3 | 6 | 7 result     " << ans << endl;

    ans = catalog[3] | catalog[5] | catalog[7];
    cout << "3 | 5 | 7 result     " << ans << endl << endl;
```

## What if we really want to watch movies 4, 5 & 6 and we want to know which streaming service(s) have all 3 available?
First we *transpose* the catalog so that each row corresponds to a movie/show instead of a streaming service:
```c++
    bitset<8> transpose[10];
    for (i=0; i<8; i++)
        for (j=0; j<10; j++)
            transpose[j][i] = catalog[i][j];
```
So now the *transposed* catalog looks like this:
```
           streaming service
           76543210
           --------
movies 0:  10001011
movies 1:  11111111
movies 2:  10100100
movies 3:  11000110
movies 4:  11111111
movies 5:  00100100
movies 6:  11100100
movies 7:  10000001
movies 8:  01100000
movies 9:  00110001
```

Then we can use the `&` operator to get the answer:
```c++
    bitset<8> ans2 = transpose[4] & transpose[5] & transpose[6];
    printf("           76543210\n");
    printf("           --------\n");
    cout << "4 & 5 & 6: " << ans2 << endl;	// 00100100
```

But why don't we just write a simple for-loop to check all 3 movies for each streaming service? Isn't it much easier?
```c++
    for (i=0; i<8; i++)
        if (catalog[i][4] & catalog[i][5] & catalog[6])
            cout << i << endl;
```

If there are a large number of streaming services, using the `bitset` method would gain marked performance improvement (precisely 64x improvement because `bitset` operates "word by word" whereas a computer word is 64-bit for most machines).

See [demo.cpp](https://github.com/miyagi-sensei/georgia/blob/main/class14/demo.cpp) for all the code snippets from above.

---

## Exercises
Solve [M2002](https://judge.hkoi.org/task/M2002)
Suggested steps:
- Solve subtask 1 & 2 using brute force method first
- Solve subtask 3 by using `bitset`

---

## Parting words
### IOI Pyramid
```
                          ****
                       **********
                    * Suffix Tree **
                  *** Convex Hull ****
                ** RMQ, segment tree ***
              *********** DSU  ***********
            ********* Graph Theory *********
          ******* Dynamic Programming ******** (class 3)
        ************ Data Structure ************ (class 4)
      ****** Divide & Conquer, Greedy, etc. ****** (class 2, 7)
    ******** Searching and Sorting, DFS, BFS ******* (class 4, 6, 8, 13)
  ***** Combinatorics, Logic and boolean algebra ***** (class 1, 11, 12)
***** Coding mechanics (loops, control flow, etc.) ***** (all the beginners' exercises)
```

- To prepare for the Final Event, make sure you attempt/complete the [beginners' exerecises](https://github.com/miyagi-sensei/georgia/blob/main/beginners.md)
- Try questions like [J191](https://judge.hkoi.org/task/J191) and [J172](https://judge.hkoi.org/task/J172) to get a feel of the mindset for some of these problems. Those questions are not demanding on coding skills but ask you to think about the problem in creative ways. They're great exercises for the competition on a non-coding level.

For example, the solution for J172 is just 9 lines:
```python
N, K = map(int, input().split())
if K * K < N:
    print('Impossible')
else:
    for n in range(N % K, 0, -1):
        print(n, end=' ')
    for i in range(N % K + 1, N + 1, K):
        for n in reversed(range(i, i+K)):
            print(n, end=' ')
```
