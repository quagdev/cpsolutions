#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, temp, highest = 0;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {cin >> temp; X[i] = temp;}
    for (int i = 0; i < N; i++) {cin >> temp; Y[i] = temp;}
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int dsquared = (X[j]-X[i])*(X[j]-X[i])+(Y[j]-Y[i])*(Y[j]-Y[i]);
            highest = max(dsquared, highest);
        }
    }

    cout << highest;
}
