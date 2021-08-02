// generates all permutations but not necessarily in lexicographic order assuming there is no duplicates
#include <iostream>
using namespace std;
int N, K;
string word;

void permute(int i) {   // i: the number of characters that have been chosen so far
  if (i == word.size()) {
    cout << word << endl;
    return;
  }
  for (int j=i; j<word.size(); j++) {
    swap(word[i], word[j]); // choose a[j] and put it at a[i]
    permute(i+1);  // choose the (i+1)th character
    swap(word[i], word[j]); // restore a[i] to before the swap
  }
}

int main() {
  cin >> word;
  permute(0);
  return 0;
}