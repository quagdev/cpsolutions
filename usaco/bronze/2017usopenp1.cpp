#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

	int origin, y, r = 1, output = 0;
    cin >> origin >> y;
    int lastx = origin, x = origin+r;

    if (origin < y) {
        while (x < y) {
            x = (origin+r);
            if (x > y) x = y;
            output += abs(x-lastx);
            //cout << x << " " << lastx << " " << output << "\n";
            r*=(-2);
            lastx = x;
        }
        cout << output;
    }
    if (origin > y) {
        while (x > y) {
            x = (origin+r);
            if (x < y) x = y;
            output += abs(x-lastx);
            //cout << x << " " << lastx << " " << output << "\n";
            r*=(-2);
            lastx = x;
        }
        cout << output;
    }
}