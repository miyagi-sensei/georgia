#include <iostream>
#include <vector>
using namespace std;
vector<int> Queue;
int N, Head;
int size() {
    return Queue.size();
}
int front() {
    return Queue[0];
}
void pop() {
    Queue.erase(Queue.begin());
}
void push(int v) {
    Queue.push_back(v);
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