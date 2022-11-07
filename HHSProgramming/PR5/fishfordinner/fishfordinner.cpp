#include <vector>
#include <algorithm>
#include <iostream>
#define pb push_back
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;    
    vector<int> weakestTeeth(m, -1); // weakest teeth in a row

    for (int i = 0;i < n;i++) {
        int row, durability; cin >> row >> durability;
        row--;
        if (weakestTeeth.at(row) == -1 || weakestTeeth.at(row) > durability) {
            weakestTeeth.at(row) = durability;
        }
    }

    int totalFood = 0;
    for (int i = 0;i < m;i++) {
        totalFood += weakestTeeth.at(i);
    }

    cout << min(totalFood, k) << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}