#include <iostream>
#include <vector>
using namespace std;
vector<int> Queue;
int N, Head;
int size() {
    return Queue.size() - Head;
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
    Queue.push_back(v);
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