#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, k;
    cin >> T >> k;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        vector<char> keys(N, 0);
        int o_count = 0;

        for (int i = N-1; i >= 0; i--) {
            if (o_count % 2 != 0) {
                if (S[i] == 'M') {
                    keys[i] = 'O';
                } else {
                    keys[i] = 'M';
                }
            } else {
                keys[i] = S[i];
            }
            if (keys[i] == 'O') {o_count++;}
        }

        cout << "YES\n";
        if (k == 1) {
            for (char x : keys) {
                cout << x;
            }
            cout << "\n";
        }
    }
}
