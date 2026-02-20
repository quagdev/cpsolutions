#include <bits/stdc++.h>
using namespace std;

vector<int> amount = {0, 0, 0}, capacity = {0, 0, 0};
int pouring = 1;

void pour() {
    int pour_into = pouring+1;
    if (pour_into > 3) {pour_into = 1;} 
    //cout << "Pouring into: " << pour_into << " \n";
    int pour_amount = min(amount[pouring-1], (capacity[pour_into-1] - amount[pour_into-1]));
    amount[pouring-1] -= pour_amount;
    amount[pour_into-1] += pour_amount;

    pouring++;
    if (pouring == 4) {pouring = 1;}
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    cin >> capacity[0] >> amount[0] >> capacity[1] >> amount[1] >> capacity[2] >> amount[2]; 
    for (int n = 0; n < 100; n++) {
        //cout << "Pouring: " << pouring << " \n";
        pour();
    }
    for (auto x : amount) {
        cout << x << "\n";
    }
}
