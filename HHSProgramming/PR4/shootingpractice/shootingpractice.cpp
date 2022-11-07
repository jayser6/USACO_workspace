#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back

void solve() {
    int n; cin >> n;

    vector<int> cans(n);
    for (int i = 0;i < n;i++) {
        cin >> cans.at(i);
    }
    sort(cans.begin(), cans.end(), greater<int>());

    int output = 0;
    for (int i = 0;i < n;i++) {
        output += i * cans.at(i) + 1;
    }
    cout << output << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}