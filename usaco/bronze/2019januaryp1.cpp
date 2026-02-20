#include <bits/stdc++.h>
using namespace std;
int swaps;

int simulate() {
    int shells[4] = {0, 1, 2, 3};
    int s = 0, temp, x = swaps, p1 = 0, p2 = 0, p3 = 0;
    while (x>0) {
        int a, b, guess;
        cin >> a >> b >> guess;
        temp = shells[a];
        shells[a] = shells[b];
        shells[b] = temp;
        if (shells[guess] == 1) {
            p1++;
        } else if (shells[guess] == 2) {
            p2++;
        } else {
            p3++;
        }
        x--;
    }
    return max({p1, p2, p3});
}   

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    cin >> swaps;
    cout << simulate();
}
