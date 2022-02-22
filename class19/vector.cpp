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
	int i, j, value;
	string cmd;
	cin >> N;
	for (i=0; i<N; i++) {
		cin >> cmd;
		if (cmd == "SIZE") {
			cout << size() << endl;
		} else if (cmd == "FRONT") {
			front();
		} else if (cmd == "POP") {
			pop();
		} else {
			cin >> value;
			push(value);
		}
	}
}