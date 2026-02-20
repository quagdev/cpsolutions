/*
    output = 999999
    Find total sum, find all divisors of total sum and make a vector of them
    for each item in divisor vector:
        blocks = 0
        current sum = 0
        for sleep number in list:
            if current sum > divisor:
                break, next divisor;
            if current sum == divisor;
                blocks++
                current sum = 0
        output = min(output, size of the list - blocks)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
	cin >> T;
    while (T--) {
        int N, temp, tSum = 0, output = 999999999;
        cin >> N;
        vector<int> sleep(N), divisors;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            sleep[i] = temp;
        }
        for (auto x : sleep) {tSum += x;}
        if (tSum == 0) {cout << 0 << "\n"; continue;}
        for (int i = 1; i <= tSum; i++) {
            if (tSum % i == 0) {
                divisors.push_back(i);
            }
        }
        //for (auto x : divisors) { cout << x << " ";} cout << "\n";

        for (auto div : divisors) {
            int blocks = 0, currentSum = 0;
            bool poss = true;

            for (auto occ : sleep) {
                currentSum += occ;
                if (currentSum > div) {
                    poss = false;
                    break;
                } else if (currentSum == div) {
                    blocks++;
                    currentSum = 0;
                }
            }
            //cout << sleep.size() << " " << blocks << "\n";
            if (poss && currentSum == 0) {output = min(output, int(sleep.size()-blocks));}
        }

        cout << output << "\n";
    }
}
