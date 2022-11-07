/*____________________________________________________________
// started : 07/05/22
// finished: 07/05/22
// problem : https://codeforces.com/contest/1472/problem/G
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
#define BIG_PRIME 1e9 + 7 

using namespace std;

void DFS(vector<int>& dp, vector<bool>& visited, const vector<vector<int>>& edges, const vector<int>& d, int curr) {
    visited[curr] = true;
    dp[curr] = d[curr];

    for (int dest : edges[curr]) {
        if ((d[dest] > d[curr]) && (!visited[dest])) {
            DFS(dp, visited, edges, d, dest);
        }

        if (d[dest] > d[curr]) {
            dp[curr] = min(dp[curr], dp[dest]);
        }
        else {
            dp[curr] = min(dp[curr], d[dest]);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> edges(n);
    FOR(m) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
    }

    // calculate all distances using bfs
    vector<int> d(n, BIG_PRIME);
    d[0] = 0;
    queue<int> bfs;
    bfs.push(0);
    while (!bfs.empty()) {
        int curr = bfs.front();
        bfs.pop();
        for (int dest : edges[curr]) {
            if (d[dest] == BIG_PRIME) {
                d[dest] = d[curr] + 1;
                bfs.push(dest);
            }
        }
    }

    // dfs + dp and solve
    vector<int> dp(n, BIG_PRIME);
    vector<bool> visited(n, false);
    visited[0] = true;
    DFS(dp, visited, edges, d, 0);

    // output
    FOR(n) {
        cout << dp[i] << " ";
    }

    cout << endl;
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
