#include <iostream>
using namespace std;
int Queue[1000];
int N, Tail, Head;
int size() {
    return Tail - Head;
}
void front() {
    if(size() == 0)
        cout << "Empty" << endl;
    else
        cout << Queue[Head] << endl;
}
void pop() {
    if(size() == 0)
        cout << "Cannot pop" << endl;
    else
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
    front();
    pop();
    front();
    pop();
    push(5);
    front();
    cout << size() << endl;
    return 0;
}