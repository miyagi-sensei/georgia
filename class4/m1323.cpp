// key idea: F[i] = fib(i-j-1) * F[j] + fib(i-j) * F[j+1]
#include <iostream>
using namespace std;

int i, Fi, j, Fj, n;

int fib(int num) {
    if (num <= 1)
        return num;
    int f0 = 0, f1 = 1, ans;
    for (int k=2; k<=num; k++) {
        ans = f0 + f1;
        f0 = f1;
        f1 = ans;
    }
    return ans;
}

int main() {
    cin >> i >> Fi >> j >> Fj >> n;
    if (j > i) {    // make sure j < i
        swap(i, j);
        swap(Fi, Fj);
    }
    int Fk = (Fi - fib(i-j-1) * Fj) / fib(i-j); // Fk = F[j+1]
    // once you found F[j] and F[j+1] then you can derive the whole fibonacci sequence
    int l, ans;
    if (n == j)
        cout << Fj << endl;
    else if (n == j+1)
        cout << Fk << endl;
    else if (n > j + 1) {
        for (l=j+2; l<=n; l++) {
            ans = Fj + Fk;
            Fj = Fk;
            Fk = ans;
        }
        cout << ans << endl;
    } else { // n < j
        for (l=j-1; l>=n; l--) {
            ans = Fk - Fj;
            Fk = Fj;
            Fj = ans;
        }
        cout << ans << endl;
    }

    return 0;
}