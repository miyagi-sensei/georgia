# Class 5
## Homework: [01090 Diligent](https://judge.hkoi.org/task/01090)
|operations||array|unordered_set|set|
|----|----|----|----|----|
|search||O(N)|O(1)|O(logN)|
|add||O(1)|O(1)|O(logN)|
|erase||O(N)|O(1)|O(logN)|

### Runtime Arithmetic
When you're confronting a problem, you try to come up with an approach (algorithm) that works. But it's very important to be able to predict the runtime performance of an approach before you write the code.
- You need to develop good intuition about runtime performance.
- The tool Computer Scientist use to analyze time complexity is the Big-O notation.
- The ability to quickly reckon the time complexity of an algorithm is the difference between bronze medal and silver medal.
- You should know the runtime performance as soon as you finished designing your algorithm, before you write the first line of code
  
> 夫未戰而廟算勝者，得算多也；未戰而廟算不勝者，得算少也。多算勝，少算不勝，而況於無算乎？吾以此觀之，勝負見矣。<br>
>       -- 《孫子兵法》第一篇末句

- 戰 = coding, implementation
- 算 = time complexity analysis

To illustrate the concept of *Abstract* Data Types, we implement solutions using each of those data structures based on the template below.
```
for each of the N id:
  if search(id):
    print("out")
    remove(id);
  else:
    print("int")
    add(id);
```

- We would only change the implementation of the `search`, `add` and `remove` functions without altering the main logic flow of the program.
- What the program does would not change. But *how* it does them would change and that has huge implications on its runtime (time complexity) and memory requirement (space complexity).

||vector|array|set|unordered_set|vector\<bool\>|bitset
|---|---|---|---|---|---|---
|code|v1.cpp|v1b.cpp|v2.cpp|v2b.cpp|v3.cpp|v3b.cpp						
||||||||
|N|||||||
|10000|0.1740|0.0680|0.0300|0.0120|0.1600|0.0100
|20000|0.6720|0.2780|0.0650|0.0380|0.1800|0.0150
|40000|2.2390|1.0600|0.1100|0.0720|0.1940|0.0400
|80000|8.8110|4.1060|0.2300|0.1560|0.2600|0.0900
|160000|35.2440|16.4240|0.4600|0.3100|0.2980|0.2100|
  
![chart](https://github.com/miyagi-sensei/georgia/blob/main/class5/runtime_charts.png)

What about space complexity?
  
- array/vector: O(N)
- set: O(N)
- lookup table: O(R) (R being the range of possible values, which can be very large)  
    
## [j212 Paint the Floor](https://judge.hkoi.org/task/j212)
  
What's the time complexity of the following pseudocode?
```
declare wall as NxN 2D int array and set it all to "white"
for each of P paint jobs (color, l):
  perform the paint job
for each of Q queries (r, c): 
  fetch the value of wall[r][c]
```

Estimate the runtime of this solution for the following cases:
1. 1 ≤ N, P ≤ 500; 1 ≤ Q ≤ 200000
2. 1 ≤ N, P ≤ 5000; 1 ≤ Q ≤ 10<sup>9</sup>
3. 1 ≤ N, P ≤ 50000; 1 ≤ Q ≤ 10<sup>7</sup>
4. 1 ≤ N, P ≤ 200000; 1 ≤ Q ≤ 200000


What's the time complexity of the following pseudocode?
```
set up a database to store all paint jobs
for each of P paint jobs (color, l):
  store this paint job into the database
for each of Q queries (r, c): 
  look up the time ranks of the 3 paint jobs that matter (if they exist)
  print the color of the latest paint job
```
  
Once again, estimate the runtime of this solution for the following cases:
1. 1 ≤ N, P ≤ 500; 1 ≤ Q ≤ 200000
2. 1 ≤ N, P ≤ 5000; 1 ≤ Q ≤ 10<sup>9</sup>
3. 1 ≤ N, P ≤ 50000; 1 ≤ Q ≤ 10<sup>7</sup>
4. 1 ≤ N, P ≤ 200000; 1 ≤ Q ≤ 200000

What about the space complexity of the above 2 solutions?

## [j184 Mysterious Area](https://judge.hkoi.org/task/j184)
### Problem Statement

- Area is a 3N x N Cartesian grid
- There are N rock pillars with height H<sub>i</sub>. All H<sub>i</sub> are permutations of 1...N
- The bird starts flying toward the right from (1, N). If it hits a rock it sicks vertically by 1 cell and turns around.
- Predict whether the bird would DROP or ESCAPE. Also print the number of steps

__________________________

What is the time complexity of the following pseudocode (simple step-by-step simulation):
```
start from (1, N) and to the right
steps = 0
while inside the area:
  if there is a rock directly ahead:
    sink 1 level and flip direction
  else:
    flying one step fowrward
  steps += 1
```
further elaborating....
```
Declare array H[] and store the height of rock i at H[i]
x = 1; y = N;
direction = "right"
steps = 0
while inside the area:
  if direction == "right":
    if there is a rock taller than y directly ahead:
      y -= 1
      direction = "left"
    else:
      x += 1
  else:
    if there is a rock taller than y directly ahead:
      y -= 1
      direction = "right"
    else:
      x -= 1
  steps += 1

if x < 1:
  print ESCAPE
else:
  print DROP
print steps
```
Estimate its run time when 1 ≤ N ≤ 2000.
Also estimate its run time when 1 ≤ N ≤ 200000.

Only O(N) solution can score 100 points. So how would you design an O(N) solution for this problem?

---

# Homework
## [j184 Mysterious Area](https://judge.hkoi.org/task/j184)
