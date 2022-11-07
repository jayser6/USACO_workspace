// started : 02/04/22
// finished: 02/06/22
// problem : https://codeforces.com/contest/1398/problem/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define hashmap unordered_map
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void solve() {
    int l; cin >> l;

    hashmap<int, ll> seen;
    seen.insert(mp(0, 1));

    ll answer = 0;
    int sum = 0;
    for (int i = 0;i < l;i++) {
        char c; cin >> c;
        sum += c - 48;

        int difference = sum - (i + 1);
        if (seen.find(difference) == seen.end()) {
            seen.insert(mp(difference, 1));
        }
        else {
            answer += seen.find(difference)->s;
            seen.find(difference)->s++;
        }
    }
    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }

}
