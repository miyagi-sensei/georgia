# Class 13
## Binary Search
[see slide 35-82 of this presentation](https://assets.hkoi.org/training2021/sas.pdf)

In 2018/19 Junior Heat Event Section B Question 5:
Given an array `a[0..99]` sorted in **descending order**, complete the function `f(target)` so that, among all `i` with `a[i] >= target`, it returns the largest `i`. If no such index exists, return `-1`.
The correct solution is:
```c++
int f(int target) {
    int l = 0;
    int r = 100;
    int m;
    while (l < r) {
        m = (l + r) / 2;
        if (a[m] >= target)
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}
```
Let's prove that this code is correct. (This would give you some superpower)
1. first we need to prove that the while loop always terminates.
2. then we prove that `l-1` is always the correct answer.

### Does the loop always terminate?
We won't do formal proof here but consider the broad structure of the loop:
```c++
while (l < r) {
	m = (l + r) / 2;
	if (....)
		l = m + 1;
	else
		r = m;
}
```
When `l` is right next to `r`, i.e. `l = r - 1`, would they move closer still in the next iteration? Yes. 
We can also see that the while loop terminates if and only if `l == r`. Can you see that?

### Is `l-1` always the correct answer?
- Consider this invariant: `a[l-1] >= target > a[r]`.
- An *invariant* is an expression that remains true throughout the loop. It is true before the loop. Its truth is maintained throughout the loop. And therefore it is also true after the loop.
- Before the while loop begins, this invariant is `a[-1] >= target > a[100]`. Confusing? Maybe. But for now just know that the invariant can be true in the beginning if we define `a[-1]` and `a[100]` properly.
- Now how is this invariant maintained throughout the loop?
- If the invariant `a[l-1] >= target > a[r]` is true before a particular iteration, let's prove that it will also be true after the iteration.
- `a[m] >= target` is either true or false.
- If `a[m] >= target`, then after we update `l` to `m + 1`, because then `m = l - 1`, `a[l-1] >= target`. Can you follow this deduction? This is the left half of the invariant, which is maintained. Notice the right half of the invariant `target > a[r]` remains unchanged.
- If `a[m] >= target` is false, then `target < a[m]`, then after we update `r` to `m`, `target < a[r]`. This is the right half of the invariant. The left half remains unchanged this time. 
- This proves that the invariant is maintained from 1 iteration to the next.
- We then can deduce that `a[l-1] >= target > a[r]` after the while loop terminates, which is when `l == r`.
- This clearly means `l-1` is the largest index where the value `a[i] >= target`. (because `a[r]`, right next to `a[l-1]` is already smaller than target)
- Also you should think about what happens in edge cases such as 1) when `target > a[0]` and 2) when `target < a[99]`.

## Exercise 1
Can you write a binary search that searches for the smallest `i` where `a[i] > target` when `a[0..99]` is sorted in **ascending order**?
One of the best approach is to have a versatile template but limit the degrees of freedom to filling in A, B, C and D below.
```c++
int f(int target) {
    int l = ??A??;
    int r = ??B??;
    int m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (a[m] ??C?? target)
            l = m;
        else
            r = m;
    }
    return ??D??;
}
```
You can also do:
```c++
while (l < r) {
    m = (l + r) / 2;
    if (a[m] ??C?? target)
        l = m + 1;
    else
        r = m;
}
```
Can you see how these are 2 ways to ensure that the while loop would always terminate? This is very important.

Let's write the invariant: `a[l] <= target < a[r]`. This lends itself easily to the answer for C.
```c++
while (l < r - 1) {
    m = (l + r) / 2;
    if (a[m] <= target)
        l = m;
    else
        r = m;
}
```
We can also deduce that the while loop terminates when `l == r - 1`, i.e. when `l` is right next to `r`. Along with the invariant `a[l] <= target < a[r]`, we know that `a[r]` would be the smallest number that's larger than `target`.
So we return `r`. That's the answer for D.
Finally what're the good initial values to ensure the invariant is true before the while loop? `l = 0` is not good enough because it's possible that `target < a[0]`.
The best initial values would be `l = -1` and `r = 100`.
So the correct version is:
```c++
int f(int target) {
    int l = -1;
    int r = 100;
    int m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (a[m] <= target)
            l = m;
        else
            r = m;
    }
    return r;
}
```

Don't take my word for it. Test it using the [binary search practice tooling](https://github.com/miyagi-sensei/binsearch). Read the [README.md](https://github.com/miyagi-sensei/binsearch/blob/main/README.md) for instructions.

---

## Exercises
Try the following variations one by one. Make sure you implement the brute force linear search version first and then stress test your binary search implementation against it.
- a binary search that searches for the largest `i` where `a[i] <= target` when `a[0..99]` is sorted in **ascending order**?
- a binary search that searches for the largest `i` where `a[i] >= target` when `a[0..99]` is sorted in **descending order**?
- a binary search that searches for the smallest `i` where `a[i] < target` when `a[0..99]` is sorted in **descending order**?
- a binary search that searches for the smallest `i` where `a[i] >= target` when `a[0..99]` is sorted in **ascending order**?

Practice writing the invariant. Prove your own code before you test it. How did it go? Are you getting better at getting it right in one shot?
