#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M, ticket = 0;
    cin >> N >> M;
    vector<int> bspeed, lspeed;
    while (N--) {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < x; i++) {
            lspeed.push_back(y);
        }
    }
    while (M--) {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < x; i++) {
            bspeed.push_back(y);
        }
    }

    //for (auto x : bspeed) {cout << x << " ";} cout << "\n";
    //for (auto x : lspeed) {cout << x << " ";} cout << "\n";

    for (int i = 0; i < 100; i++) {
        if (bspeed[i] > lspeed[i]) {
            ticket = max(ticket, (bspeed[i]-lspeed[i]));
        }
    }
    cout << ticket << "\n";
}