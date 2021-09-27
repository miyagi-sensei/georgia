# Class 9
# [j194 Graffiti](https://judge.hkoi.org/task/j194)
Recommended way:
1. Solve subtask 1 first
2. S

# [j184 Mysterious Area](https://judge.hkoi.org/task/j184)
## Problem Statement

- Area is a 3N x N Cartesian grid
- There are N rock pillars with height H<sub>i</sub>. All H<sub>i</sub> are permutations of 1...N
- The bird starts flying toward the right from (1, N). If it hits a rock it sicks vertically by 1 cell and turns around.
- Predict whether the bird would DROP or ESCAPE. Also print the number of steps

__________________________

## Simulation
- Imagine a [simulation](https://github.com/miyagi-sensei/j184-mysetrious-area/blob/master/demo.py) where you plot the trajectory of the bird graphically
> !!! show code and demo it (it doesn't count steps)

Write your own flying logic with this [template](https://github.com/miyagi-sensei/j184-mysetrious-area/blob/master/v0.cpp) and see it graphically depicted:
```c++
int main() {
    int i, j;
    string direction, temp;
    cin >> N;
    for (i=0; i<N; i++)
        cin >> H[i];
    init_area();
    X = 1; Y = N;
    direction = ">>";
    area[X][Y] = direction;
    print_area();
    getline(cin, temp);
    while (true) {
        area[X][Y] = "  ";

        // *** your flying logic begins here
        ......
        ......
        // *** your flying logic ends here

        area[X][Y] = direction;
        getline(cin, temp);
        print_area();
    }
    return 0;
}
```

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
> !!! Ask if they can read pseudocode
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

> !!! Demo with worst case `6 4 2 1 3 5 7`.

Time Complexity is O(N<sup>2</sup>).
Estimate its run time when 1 ≤ N ≤ 2000.
Also estimate its run time when 1 ≤ N ≤ 200000.

Only O(N) solution can score 100 points. So how would you design an O(N) solution for this problem?
