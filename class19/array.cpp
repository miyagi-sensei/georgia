#include <iostream>
using namespace std;
int Queue[1000];
int N, Tail, Head;
int size() {
    return Tail - Head;
}
int front() {
    return Queue[Head];
}
void pop() {
    Head++;
}
void push(int v) {
    Queue[Tail] = v;
    Tail++;
}
int main(){
    push(3);
    push(7);
    push(4);
    cout << size() << endl;
    cout << front() << endl;
    pop();
    cout << front() << endl;
    pop();
    push(5);
    cout << front() << endl;
    cout << size() << endl;
    return 0;
}