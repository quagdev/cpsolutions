/*
    create spotty & plain string vectors
    for loop for each index, creating two vectors inside the loop
    one vector puts all the spotty ones atcg
    one vector puts all the plain atcg
    if the two don't overlap, count++
    output count
*/

#include <bits/stdc++.h>
using namespace std;

bool no_overlap(vector<char> v1, vector<char> v2) {
    sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
    vector<char> is;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(is));

    return is.empty();
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M, count = 0;
    string t;
    cin >> N >> M;
    vector<string> spotty, plain;
	while (cin >> t) {spotty.push_back(t);}
    for (int i = 0; i < N; i++) {
        plain.push_back(spotty.back());
        spotty.pop_back();
    }
   
    for (int i = 0; i < M; i++) {
        vector<char> cspotty, cplain;
        for (string j : spotty) {cspotty.push_back(j[i]);}
        for (string k : plain) {cplain.push_back(k[i]);}
        if (no_overlap(cspotty, cplain)) {count++;}
    }

    cout << count;
}
