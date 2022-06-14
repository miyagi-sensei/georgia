# Class 33 - Computational Geometry
If you know 2 things really well, you can solve most of the O.I. geometry problems:
- any 2 points `(x1, y1)` and `(x2, y2)` on a line has the same slope
<img src="https://i.imgur.com/jNUGYo3.jpg" width="400">
    - <img src="https://latex.codecogs.com/svg.image?\inline&space;\LARGE&space;\bg{white}\frac{y-y_1}{x-x_1}&space;=&space;\frac{y_2-y_1}{x_2-x_1}">
    - corrollary: the product of the slopes of 2 perpendicular lines is `-1` (m<sub>AB</sub> x m<sub>CD</sub> = -1 if AB is ⟂ to CD)
- Pythagoras Theorem: distance between 2 points (x1, y1) and (x2, y2) is
<img src="https://latex.codecogs.com/svg.image?\sqrt{(x_2-x_1)^2&space;&plus;&space;(y_2-y_1)^2}">

## [M2005 Corona and Office](https://judge.hkoi.org/task/M2005)
### N = 1
Subtask 1 can be solved kinda brute force by considering every grid point's distance from the line segment AB.
<img src="https://i.imgur.com/6Sa5ugF.jpg" width="600">

You'll need to pay attention to whether the "projection point" C lies within AB or not. If it lies outside AB, you can just compute the distance between AE (or BE, if the projection point lies on the other end).

There are many ways to derive a computational formula for EC, i.e. the distance from E to the line segment AB. But the following apporach makes it convenient to detect whether the projection point falls within segment AB:

First define △x = x<sub>2</sub> - x<sub>1</sub> and △y = y<sub>2</sub> - y<sub>1</sub>
Then think of C as (x<sub>1</sub> + *t*\*△x, y<sub>1</sub> + *t*\*△y) whereas 0 ≤ t ≤ 1.
Using the fact that EC and AB are perpendicular, you can solve for t:
![](https://latex.codecogs.com/svg.image?\inline&space;\LARGE&space;\bg{white}t=\frac{\Delta&space;x(x_1-x)&plus;\Delta&space;y(y_1-y)}{\Delta&space;x^2&plus;\Delta&space;y^2})

Clipping t within the range [0, 1], you can then easily calculate the distance of (x, y) from the line segment AB:
dist<sup>2</sup> = [x - (x<sub>1</sub> + t*△x)]<sup>2</sup> + [y - (y<sub>1</sub> + t * △y)]<sup>2</sup>

### N > 1
- There is overlap between various paths of infection. To deal with the duplicates, insert every infected grid point into a `set`. (see below [Appendix](#Appendix---using-set) for more about C++ `set`)

### Code template
```cpp
#include <iostream>
#include <set>
using namespace std;
int N, D;
pair<int,int> Points[10];
set<pair<int,int>> Infected;

void travel(int x1, int y1, int x2, int y2) {
    // ------------ YOUR CODE ------------
    // define up, down, left, right 
    // to box in all the grid points to be considered
    for (int x=left; x<=right; x++) {
        for (int y=down; y<=up; y++) {
        // ------------ YOUR CODE ------------
        // calculates distance from (x,y) to line segment (x1,y1)-(x2,y2)
        double dist;
        if (dist <= D)	// put all infected grid into the set
            Infected.insert({x, y});
        }
    }
}

int main() {
    int i;
    cin >> N >> D;
    for (i=0; i<=N; i++)
        cin >> Points[i].first >> Points[i].second;
    for (i=0; i<N; i++)
        travel(Points[i].first, Points[i].second, Points[i+1].first, Points[i+1].second);
    cout << Infected.size() << endl;
    return 0;
}
```
### Floating Point Precision Problem
Be careful about the floating point precision problem.
```cpp
    double a, b, c;
    a = 0.4;
    b = 0.3;
    cout << (a - b) * 20 << endl;    // 2
    c = 2.0;
    cout << ((a-b) * 10 == c) << endl;    // 0
    printf("%0.20lf\n", (a-b) * 10);
    printf("%0.20lf\n", c);
    printf("%0.20lf\n", c - (a-b) * 10);
```

Whenever feasible, you should avoid division arithmetic (or √, etc.) that requires the use of floating point numbers. How would you do it in this problem?

### The power of vector arithmetic (skip if you're not familiar with vector)
If you're particularly familiar with vector arithmetic, this problem can be a breeze. This is how you can use `struct` to make vector dot product and vector cross product effortless:
```cpp
struct Vector {
    int x, y;
    Vector operator-(Vector T) {
        return {x - T.x, y - T.y};
    }
    int dot(Vector T) {
        return x * T.x + y * T.y;
    }
    int cross(Vector T) {
        return x * T.y - y * T.x;
    }
    int magnitude() {
        return x * x + y * y;
    }
};
Vector Points[10];
```
Dot product and cross product come in handy for this problem.
```cpp
void travel(Vector a, Vector b) {
    Vector u, v, e;
    int x1 = a.x, y1 = a.y;
    int x2 = b.x, y2 = b.y;
    int left = min(x1, x2) - D;
    int right = max(x1, x2) + D;
    int down = min(y1, y2) - D;
    int up = max(y1, y2) + D;
    u = b - a;
    int limit = D * D * u.magnitude();  // multiply by u^2 to avoid division which causes floating point precision problem
    int x, y, dist;
    for (x=left; x<=right; x++) {
        for (y=down; y<=up; y++) {
            e = {x, y};
            v = e - a;
            if (u.dot(v) <= 0)  // outside the A side of the rectangle
                dist = v.magnitude() * u.magnitude();
            else if (u.dot(v) > u.magnitude())  // outside the B side of the rectangle
                dist = (e - b).magnitude() * u.magnitude();
            else
                dist = u.cross(v) * u.cross(v);
            if (dist <= limit)
                Infected.insert({x, y});
        }
    }
}
```

### Full solution
- To turn a "2D scan" algorithm of O(N<sup>2</sup>) complexity to one with O(N) complexity, often we can try to do "1D scan" along the x-axis or y-axis.
- For each integer x within `left` and `right` bound, solve for upper intercept and the lower intercept using algebra
- For each `x`, you would then end up with a list of ranges that may or may not overlap. Merge the overlap and count the number of discrete grid points.

## Appendix - using `set`
```cpp
#include <iostream>
#include <set>

using namespace std;

void print_set(set<int> s) {
    for (auto num: s)
        cout << num << " ";
    cout << endl;
}

int main()
{
    set<int> s1;

    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
    cout << "size is now: " << s1.size() << endl;
    // only one 50 can exist in the set
    s1.insert(50);
    s1.insert(10);
    cout << "after inserting 50 and 10, size is now: " << s1.size() << endl;

    // printing set s1
    cout << "\nThe set s1 is : \n";
    print_set(s1);

    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());

    // remove all elements up to 30 in s2
    cout << "\ns2 after removal of elements less than 30:\n";
    s2.erase(s2.begin(), s2.find(30));
    print_set(s2);

    // remove element with value 50 in s2
    int num;
    num = s2.erase(50);
    cout << "\ns2.erase(50) : ";
    cout << num << " removed\n";
    print_set(s2);

    // lower bound and upper bound for set s1
    cout << "\ns1.lower_bound(30) : \n" 
        << *s1.lower_bound(30) << endl;
    cout << "s1.upper_bound(30) : \n"
        << *s1.upper_bound(30) << endl;

    return 0;
}
```