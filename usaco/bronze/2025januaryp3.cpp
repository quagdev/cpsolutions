#include <bits/stdc++.h>
using namespace std;

int main() {

	int N;
    cin >> N;
    vector<int> a(N), b(N), count(N+1, 0);
    for (int i = 0; i < N; i++) {cin >> a[i];}
    for (int i = 0; i < N; i++) {cin >> b[i]; }

    int init_matches = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {init_matches++;}
    }

    for (int center = 0; center <= 2 * N - 2; center++) {
        int l = center / 2;
        int r = (center + 1) /2 ;
        int c = init_matches;

        while (l >= 0 && r < N) {
            if (a[l] == b[l]) {c--;}
            if (l != r && a[r] == b[r]) {c--;}
            if (a[l] == b[r]) {c++;}
            if (l != r && a[r] == b[l]) {c++;}
            count[c]++;

            l--;
            r++;
        }
    }

    for (auto x : count) {
        cout << x << "\n";
    }
}
