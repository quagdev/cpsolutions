/*
    x = a, y = b
    simulate all possibilites of a & b
    find m of that possiblity
    output  min m
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

	int N, B, m = 100, xx, yy;
    vector<int> x, y;
    cin >> N >> B;
    while (cin >> xx >> yy) {
        x.push_back(xx);
        y.push_back(yy);
    }
    for (int a = 0; a <= N; a+=2) {
        for (int b = 0; b <= N; b+=2) {
            int  mx, topleft = 0, topright = 0, bottomleft = 0, bottomright = 0;
            for (int k = 0; k < N; k++) {
                if (x[k] > a && y[k] > b) {topright++;}
                if (x[k] < a && y[k] > b) {topleft++;}
                if (x[k] > a && y[k] < b) {bottomright++;}
                if (x[k] < a && y[k] < b) {bottomleft++;}
            }
            mx = max({topleft, topright, bottomleft, bottomright});
            //cout << topleft << " " << topright << " " << bottomleft << " " << bottomright << " " << mx << " \n"; 
            m = min(m, mx);
        }
    }

    cout << m;
}
