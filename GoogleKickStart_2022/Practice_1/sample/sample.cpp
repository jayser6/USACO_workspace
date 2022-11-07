// started : 02/16/22
// finished: 02/16/22

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void solve(int caseNum) {
    int n, m; cin >> n >> m;

    ll total = 0;
    for (int i = 0;i < n;i++) {
        int c_i; cin >> c_i;
        total += c_i;
    }

    cout << "Case #" << caseNum << ": " << (total % m) << endl;
}

int main() {
    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve(i + 1);
    }
}
