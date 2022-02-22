# Class 19 - Data Structure
- Stack
- Queue
- (Singly) Linked List
- .... (deque, doubly-linked-list, priority queues, trees, etc. some other day)
- What is Abstract Data Type (ADT)?

![stack and queue](https://i.imgur.com/ysW3Ev2.png)
![linked list](https://i.imgur.com/YZIF1Gn.png)

## 1. Queue
```cpp
int arr[1000000];
init(): head = 0; tail = 0;
size(): return tail - head;
push(v): arr[tail] = v; tail++;
front(): return arr[head];
pop(): head++;
```
Alternative implementations: [using array](https://github.com/miyagi-sensei/georgia/blob/main/class19/array.cpp), [using vector](https://github.com/miyagi-sensei/georgia/blob/main/class19/vector.cpp), [another way using vector](https://github.com/miyagi-sensei/georgia/blob/main/class19/vector2.cpp)
### Implementation illustration:
```
PUSH 3
PUSH 7
PUSH 4
SIZE
FRONT
POP
FRONT
POP
PUSH 5
FRONT
SIZE
```
[Queue Illustration](https://youtu.be/nvSKeowGG04)

### Application - breadth first search (BFS)
[![Demo](https://i.imgur.com/mEKMZDH.png)](https://youtube.com/embed/8ADGl4is9Qs)
 
## 2. Stack
```cpp
int arr[1000000];
init(): top = 0; bottom = 0;
size(): return top - bottom;
push(v): arr[top] = v; top++;
front(): return arr[top-1];
pop(): top--;
```
### Implementation illustration:
```
PUSH 3
PUSH 7
PUSH 4
SIZE
TOP
POP
TOP
POP
PUSH 5
TOP
SIZE
```
[Stack Illustration](https://youtu.be/VWHBA_JOkMc)

### Application - depth first search (DFS)
[![Demo](https://i.imgur.com/mEKMZDH.png)](https://youtube.com/embed/gnL54Lg6NbA)

## 3. (Singly) Linked List
- [Concept](https://youtu.be/NobHlGUjV3g)
- [Implementation](https://youtu.be/vcQIFT79_50)

### Implementation illustration: 
[Linked List Illustration](https://youtu.be/vrxPj3cwzOg)

[Linked List Insertion/Deletion](https://youtu.be/vrxPj3cwzOg)

### Application - Beiju Text
`“stacks [use more memory than [linked lists “`

[Beiju Text Illustration](https://youtu.be/0MjkZcXDtcw")
<!-- [![Demo](https://i.imgur.com/GQh4JrL.png)](https://youtube.com/embed/0MjkZcXDtcw) -->

## 4. Exercises
- [D701 Queue](https://judge.hkoi.org/task/D701)
- [D702 Stack](https://judge.hkoi.org/task/D702)
- Singly Linked List: [D703](https://judge.hkoi.org/task/D703), [D704](https://judge.hkoi.org/task/D704), [D705](https://judge.hkoi.org/task/D705)
- [01017 Car Sorter](https://judge.hkoi.org/task/01017)
- [20514 Rails](https://judge.hkoi.org/task/20514)
- [31988 Broken Keyboard (a.k.a. Beiju Text)](https://judge.hkoi.org/task/31988)
- Advanced Stack exercise: [32462 Largest Histogram](https://judge.hkoi.org/task/32462)
- 
## 5. Written Test
1. Consider the following program segment:
```cpp
int a[100];
int p;
void f(int x) {
    a[p] = x;
    p++;
}
int g() {
    p--;
    return a[p];
}
```
Which of the following data structures does the above program segment implement?<br>
A. Queue<br>
B. Cyclic queue (circular buffer)<br>
C. Stack<br>
D. Linked list<br>

2. `swap(a, b)` is a function swapping the values of `a` and `b`. Consider the following program:
```cpp
int q[5];
int i, n, h, t;
void push(int x) {
    q[t] = x;
    if (q[h] > q[t])
        swap(q[h], q[t]);
    t++;
}
void pop() {
    cout << q[h];
    h++;
    if (q[h] > q[t -1])
        swap(q[h], q[t - 1);
}
int main() {
    h = 0;
    t = 0;
    for (i = 0; i <= 3; i++) {
        q[i] = 0;
        cin >> n;
        push(n);
    }
    for (i = 0; i <= 3; i++)
        pop();
    return 0;
}
```
Which of the following inputs have the output?<br>
i. `1 4 3 2`<br>
ii. `4 3 2 1`<br>
iii. `4 2 3 1`<br>
A. i and ii only<br>
B. i and iii only<br>
C. ii and iii only<br>
D. i, ii and iii<br>

3. Suppose you now have an empty stack and a queue of 7 numbers. You can perform the following actions arbitrarily:<br>
    i. If the queue is not empty: pop the front element from the queue and push it into the stack.<br>
    ii. If the stack is not empty: pop an element from the stack and output it.<br><br>
Given the queue has 4, 7, 3, 2, 5, 1, 6 (in this order) with 4 being the front element initially. Which of the following can be an output sequence?<br>
A. 6, 1, 5, 2, 7, 3, 4<br>
B. 3, 4, 7, 5, 2, 1, 6<br>
C. 2, 3, 1, 5, 7, 6, 4<br>
D. 4, 7, 3, 1, 2, 5, 6<br>

4. What is the ouptput of the following program?
```cpp
int queue[3];
int head, tail;
void push(int x) {
    queue[tail] = x;
    tail = (tail + 1) % 3;
}
void pop() {
    if (head == tail) {
        cout << "Empty";
    } else {
        cout << queue[head] << " ";
        head = (head + 1) % 3;
    }
}
int main() {
    head = 0;
    tail = 0;
    push(5);
    push(7);
    push(3);
    pop();
    push(4);
    push(8);
    pop();
    pop();
    pop();
    return 0;
}
```
