/*
    for each letter in the alphabet, 
    find both indexes of them
    make an alphabet vector for them
    find the letters between them, adding occ to alphabet vector
    if a letter only occ exactly once, add pair to pairs
    turn pair vector into set, output size
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    vector<pair<char, char>> pairs;
	string n, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> n;
    for (char x : alphabet) {
        int index1 = -1, index2 = -1;
        vector<int> occ(26, 0);
        for (int i = 0; i < n.length(); i++) {
            if (n[i] == x) {
                if (index1 == -1) {index1 = i;}
                else {index2 = i;}
            }
        }

        for (int j = index1+1; j < index2; j++) {
            occ[(n[j]-65)]++;
        }

        for (int k = 0; k < occ.size(); k++) {
            int t = min(x-65, k), u = max(x-65, k);
            if (occ[k] == 1) {
                pairs.push_back(pair(char(t+65), char(u+65)));
            }
        }
    }
        

    sort(pairs.begin(), pairs.end());
    auto l = unique(pairs.begin(), pairs.end());
    pairs.erase(l, pairs.end());

    cout << pairs.size();
}