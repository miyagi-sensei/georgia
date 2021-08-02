#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, K, M;
string chars;
string temp = "";
set<string> db;

void combinations(int x, int offset) {	
  if (x == 0) {
    if (db.size() < K) { db.insert(temp); }
    return;
  } else {
    for (int i = offset; i < N; i++) {
      temp += chars[i];
      combinations(x-1, i+1);
      temp.pop_back();
    }
  }
}

int main() {
  cin >> N >> M >> K >> chars;
  sort(chars.begin(), chars.end());
  combinations(M, 0);
  for (set<string>::iterator it = db.begin(); it != db.end(); it++) {
    cout << *it << endl;
  }
  
  return 0;
}