/*____________________________________________________________
// started : 07/01/22
// finished: 07/02/22
// problem : https://codeforces.com/contest/1627/problem/E
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> fire(n);
    FOR(n) {
        cin >> fire[i];
    }

    vector<int> ladders(k); // the index of the destination room, h
    vector<vector<pair<int, int>>> rooms(n); // x value of the room, index of the room

    // start and finish points
    rooms[0].pb({ 0, 0 });
    rooms[n - 1].pb({ m - 1, k * 2 + 1 });

    // build the ladders 
    FOR(k) {
        int a, b, c, d, h; cin >> a >> b >> c >> d >> h;
        a--; b--; c--; d--;

        rooms[a].pb({ b, (2 * i) + 1 });
        rooms[c].pb({ d, (2 * i) + 2 });

        ladders[i] = h;
    }

    // dp and solve
    vector<ll> dp((2 * k) + 2, BIG_NUMBER);
    dp[0] = 0;
    for (int i = 0;i < n;i++) {
        if (rooms[i].size() == 0) {
            continue;
        }

        sort(ALL(rooms[i]));

        // moving left and right 
        ll dmg = dp[rooms[i][0].s];
        for (int j = 1;j < rooms[i].size();j++) {
            dmg = min(dmg + (rooms[i][j].f - rooms[i][j - 1].f) * (ll)fire[i], dp[rooms[i][j].s]);
            dp[rooms[i][j].s] = dmg;
        }

        dmg = dp[rooms[i][rooms[i].size() - 1].s];
        for (int j = rooms[i].size() - 2;j >= 0;j--) {
            dmg = min(dmg + (rooms[i][j + 1].f - rooms[i][j].f) * (ll)fire[i], dp[rooms[i][j].s]);
            dp[rooms[i][j].s] = dmg;
        }

        // simulate going up
        for (int j = 0;j < rooms[i].size();j++) {
            int index = rooms[i][j].s;
            if ((index % 2 == 1) && (index < (2 * k) + 1) && dp[index] < BIG_NUMBER) {
                dp[index + 1] = min(dp[index + 1], dp[index] - ladders[index / 2]);
            }
        }
    }

    if (dp[(2 * k) + 1] >= BIG_NUMBER) {
        cout << "NO ESCAPE" << endl;
    }
    else {
        cout << dp[(2 * k) + 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
