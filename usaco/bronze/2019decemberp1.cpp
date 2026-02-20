/*
    from i to N, make a vector of all x+1-N elements
    for each session, add 1 to the index (n-1) for all n cows 
    i outperformed.
    at the end, if not 0, make a pair and add to consistent vector
    output all pairs in consistent vector

    first loop, defines i, what element we are comparing
    second loop, iterates through all the sessions
    third loop, finds all numbers AFTER x, adds those to a list;
*/

#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<int> vec, int val) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    vector<pair<int, int>> consistent; 
	int K, N;
    cin >> K >> N;
    vector<vector<int>> sessions(K, vector<int>(N));
    for (vector<int> &t : sessions) {
        for (int &u : t) {
            cin >> u;
        }
    }

    for (int i = 1; i <= N; i++) {
        vector<int> poss(N, 0);
        for (int j = 0; j < K; j++) {
            int it = findIndex(sessions[j], i);
            for (int k = it+1; k < N; k++) {
                int z = sessions[j][k];
                poss[z-1]++;
            }
        }
        for (int l = 0; l < N; l++) {
            if (poss[l] == K) {
                consistent.push_back(make_pair(i, (l+1)));
            }
        }
    }

    sort(consistent.begin(), consistent.end());
    auto last = unique(consistent.begin(), consistent.end());
    consistent.erase(last, consistent.end());
    cout << consistent.size();
}
