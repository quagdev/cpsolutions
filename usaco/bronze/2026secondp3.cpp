#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N, Q;
    cin >> N >> Q;

    vector<ll> cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i < N; i++) {
        cost[i] = min(cost[i-1]*2, cost[i]);
    }
    for (int i = N-2; i >= 0; i--) {
        cost[i] = min(cost[i], cost[i + 1]);
    }

    vector<ll> powers(N);
    powers[0] = 1;
    for (int i = 1; i < N; i++) {
        if (powers[i-1] > (2e18/2)) {
            powers[i] = 2e18;
        } else {
            powers[i] = powers[i-1]*2;
        }
    }

    while (Q--) {
        ll x, tcost = 0, min_deal = 4e18;
        cin >> x;

        int lowerbound = lower_bound(powers.begin(), powers.end(), 2e18) - powers.begin();
        if (lowerbound >= N) {lowerbound = N - 1;}

        for (int i = lowerbound; i >= 0; i--) {
            ll orders = x / powers[i];
            tcost += orders * cost[i];
            x %= powers[i];

            min_deal = min(min_deal, tcost + cost[i]);

            if (x == 0) {
                min_deal = min(min_deal, tcost);
                break;
            }
        }
        cout << min(tcost, min_deal) << "\n";
    }
}
