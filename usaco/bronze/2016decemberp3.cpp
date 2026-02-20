#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int M, N, K;
    cin >> M >> N >> K;
    while (M--) {
        string s;
        vector<char> c;
        cin >> s;
        for (int i = 0; i < N; i++) {
            c.push_back(s[i]);
        }
        for (int i = 0; i < K; i++) {
            for (auto x : c) {
                for (int j = 0; j < K; j++) {
                cout << x;
                }
            }
            cout << "\n";
        }
    }
}
