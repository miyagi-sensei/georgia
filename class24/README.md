# Class 24 - Counting Quiz

Submit your answers by email to haye@miyagiacademy.com or by DM over Discord.

#### 1. A fair 6-faced dice is thrown 3 times. What is the probability that the 3 numbers thrown are strictly increasing? (Express it in a fraction, e.g. `7/216`)

#### 2. How many different arrangements can be made if Stan (a boy), 5 other boys and 5 other girls are to take a photo together in a horizontal line, where Tom must either stand at the leftmost or rightmost end of the line, and boys and girls must stand alternatively in the photo?

#### 3. Assume that function `r()` returns a random integer between `0` and `65535` inclusive uniformly and independently. Which of the following expressions generate an integer between `0` and `2` inclusive randomly with equal probability?  (choose any number of them, or none at all)
a. `r() % 3`

b. `(r() + r() + r()) % 3`

#### 4. Assume that function `myrand(n)` returns an integer from `0` to `n-1` inclusive randomly with equal probability. Consider the following program:
```cpp
int main() {
    int x = (myrand(50) - 30) % 6;
    cout << x;
    return 0;
}
```
What is the number of possible different outputs?

#### 5. Two players are playing a game. In every independent round, both players have equal probability to win, and winner gets the point. What is the probability that, the first tie occurs at the end of the sixth round?

#### 6. There are four doors numbered from 1 to 4. A gift is placed behind one of these four doors. You have the following information:
|Door|Time to unlock this door|Probability of the gift behind this door|
|---|---|---|
|1|10 seconds|0.2|
|2|10 seconds|0.25|
|3|15 seconds|0.2|
|4|30 seconds|0.5|

You are going to unlock the doors one by one in any order you want, until you find the gift. What is the best strategy to unlock the doors so that the expected time required can be minimized? (The time walking between doors can be omitted) Choose one answer

A. Door 2 -> Door 1 -> Door 3 -> Door 4

B. Door 4 -> Door 3 -> Door 1 -> Door 2

C. Door 2 -> Door 3 -> Door 4 -> Door 1

D. Door 2 -> Door 1 -> Door 4 -> Door 3

#### 7. Consider the following program:
```cpp
int a, n;
int main() {
    a = 0;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = n - 1;
        a++;
    }
    cout << a;
    return 0;
}
```
How many integer inputs between 1 and 50 inclusive will cause the program to output 7?

#### 8. Evelyn is navigating through a maze which can be represented by a grid of 8x8 cells. She is currently at cell A and would like to reach cell B. In each move, he may only move to the cell to the right or the cell below. Also, he cannot pass through the maze walls (indicated by thick lines). How many different paths may Evelyn take?


<img src="https://i.imgur.com/6WnI1UA.png" width="400"/>

#### 9. Evelyn is navigating through a maze which can be represented by a grid of 8x8 cells. She is currently at cell A and would like to reach cell B. In each move, he may only move to the cell to the right or the cell below. Also, he cannot pass through the maze walls (indicated by thick lines). How many different paths may Evelyn take?

<img src="https://i.imgur.com/Cr8HvEl.png" width="400"/>

#### 10. You are given a pentagon with 5 vertices labeled from 1 to 5 (see the figure below). Find the number of ways to color each vertex in one of red, green or blue so that no two neighbouring vertices have the same color. Note: Two ways of coloring are considered different if there exists a vertex which is colored differently.

<img src="https://raw.githubusercontent.com/miyagi-sensei/georgia/main/class15/ex3.png" width="400"/>

#### 11. There are 6 numbers 0, 2, 3, 4, 5, 9. You can take any of them (from none to all). How many ways can you take such that the sum of the numbers you take is between 10 and 24 inclusive?

#### 12. 
Alice and Bob are in a survival game, in which they must cross an elevated bridge in order. There are 3 steps to the end of the bridge, with each step having 3 normal glasses and 1 tempered glass a player can step on. For each step, a player steps on 1 of the 4 glass panels ahead uniformly at random. If the glass is tempered, they proceed to the next step. Otherwise, the glass breaks and the player is eliminated.
When the first player is eliminated, the next player begins to cross the bridge. Assume that they always follow tempered glass steps that the previous player has stepped on.
A player wins if and only if they arrive at the other end of the bridge first. If Alice goes first, what is the probability of Bob winning the game?

![](https://i.imgur.com/yVHnGDv.jpg)
