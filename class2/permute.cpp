// generates all premutations in lexicographic order
#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
string word;

/*
1. traverse from right to left and find the first item that is not following descending order (index i-1)
2. swap the item with the smallest greater item on the right (note items in descending order right of i): swap i-1 and j-1 item
3. sort arr[i:], which is the same as reversing arr[i:]
Use example: "acfedb" => identified "c" => smallest greater char on the right is "d" => swap => "adfecb" => "adbcef"!
*/
void next_permute() {
    int i = N-1, j, closest_index;
    while (i >=0 && word[i-1] >= word[i]) {
        i--;
    }
    j = i;
    while (j < N && word[j] > word[i-1]) {
        j++;
    }
    swap(word[i-1], word[j-1]);
    for (j=i; j<(N+i)/2; j++)
        swap(word[j], word[N-1-(j-i)]);
}

int main() {
    cin >> N >> K;
    cin >> word;
    sort(word.begin(), word.end());
    while (K--) {
        cout << word << endl;
        // next_permutation(word.begin(), word.end());  // STL function
        next_permute();
    }
    return 0;
}