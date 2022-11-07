// started : 03/16/22
// finished: 03/18/22
// problem : https://codeforces.com/problemset/problem/1626/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIGNUMBER 100000000000

using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<pair<ll, ll>> monsters(n + 1);
    monsters[0].f = -1; // this is just to avoid the special case of having to calculate for the first monster
    monsters[0].s = -1;

    for (int i = 1;i <= n;i++) {
        cin >> monsters[i].f;
    }
    for (int i = 1;i <= n;i++) {
        cin >> monsters[i].s;
    }
    
    ll output = 0;
    ll currStart = BIGNUMBER, currEnd = monsters[n].f;
    for (int i = n;i > 0;i--) {
        // update the start time of when the player needs to start shooting to eliminate all monsters from i to n
        currStart = min(currStart, monsters[i].f - monsters[i].s + 1);

        // see if mana can be saved between this monster and the next monster
        if (currStart > monsters[i - 1].f) {
            output += (currEnd - currStart + 1) * (currEnd - currStart + 2) / 2;
            currEnd = monsters[i - 1].f;
        }     
    }

    cout << output << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}