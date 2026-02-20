/* make pair vector
create a loop to find all possibilities, ?? how tho



appending the three words a string.
for each letter in the alphabet, find the string with most of it
and append to a vector alphabet.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> alpha(26, 0);

void count(pair<string, string> x) {
    vector<int> local_alpha(26,0), local_alpha_front(26,0), local_alpha_back(26,0);

    /*
    string pre = x.first+x.second;
    unordered_set<char> seen_chars;
    string combined = "";
    for (char c : pre) {
        if (seen_chars.find(c) == seen_chars.end()) {
            seen_chars.insert(c);
            combined += c;
        }
    }
    */

    for (char c : x.first) {
        //cout << c;
        int ascii = c - 97;
        //cout << ascii;
        local_alpha_front[ascii]++;
        local_alpha[ascii]++;
    }
    //cout << "\n";

    for (char c : x.second) {
        int ascii = c - 97;
        //cout << ascii;
        local_alpha_back[ascii]++;
        local_alpha[ascii]++;
    }

    //cout <<"\n";
    //for (auto y : local_alpha) {cout << y;}
    //cout << "\n";

    for (int i = 0; i < local_alpha.size(); i++) {
        local_alpha[i] -= min(local_alpha_front[i], local_alpha_back[i]);
        alpha[i] += local_alpha[i];
    }
}

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    string f, b;
    cin >> N;
	vector<pair<string, string>> words(N);
    vector<string> poss;
    while (cin >> f >> b) {
        words.emplace_back(f, b);
    }
    for (auto x : words) {
        count(x);
    }
    for (auto y : alpha) {
        cout << y << "\n";
    }
}
