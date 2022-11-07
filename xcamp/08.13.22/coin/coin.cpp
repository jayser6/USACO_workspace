/*____________________________________________________________
// started : 08/20/22
// finished: 08/21/22
// problem : https://cses.fi/problemset/task/1686
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
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

// first DFS for finding SCC
void dfs1(vector<vector<int>>& edges_r, vector<bool>& visited, stack<int>& SCC_order, int curr_node) {
    visited[curr_node] = true;

    for (int dest : edges_r[curr_node]) {
        if (!visited[dest]) {
            dfs1(edges_r, visited, SCC_order, dest);
        }
    }

    SCC_order.push(curr_node);
}

// second DFS for finding SCC
void dfs2(vector<vector<int>>& edges, vector<int>& SCC, int curr_node, int curr_SCC) {
    SCC[curr_node] = curr_SCC;

    for (int dest : edges[curr_node]) {
        if (SCC[dest] == -1) {
            dfs2(edges, SCC, dest, curr_SCC);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /* input */
    int n, m; cin >> n >> m;

    vector<int> coins(n);

    FOR(n) {
        cin >> coins[i];
    }

    vector<pair<int, int>> tunnels(m); // for redbuiling the graph later
    vector<vector<int>> edges(n);
    vector<vector<int>> edges_r(n);

    FOR(m) {
        cin >> tunnels[i].f >> tunnels[i].s;
        tunnels[i].f--; tunnels[i].s--;

        edges[tunnels[i].f].pb(tunnels[i].s);
        edges_r[tunnels[i].s].pb(tunnels[i].f);
    }

    /* compress nodes into the SCC they belong in */

    // first DFS
    stack<int> SCC_order;
    vector<bool> visited(n, false);

    FOR(n) {
        if (!visited[i]) {
            dfs1(edges_r, visited, SCC_order, i);
        }
    }

    // second DFS
    vector<int> SCC(n, -1); // the SCC that node i belongs to

    int SCC_cnt = 0;
    while (!SCC_order.empty()) {
        int curr_node = SCC_order.top();

        if (SCC[curr_node] == -1) {
            dfs2(edges, SCC, curr_node, SCC_cnt);
            SCC_cnt++;
        }

        SCC_order.pop();
    }

    /* rebuild the graph and solve the problem using DP + topsort */

    // rebuilding the graph & reorganizing values
    vector<hashset<int>> edges_new(SCC_cnt);
    vector<int> indeg(SCC_cnt, 0);
    vector<ll> coins_new(SCC_cnt, 0);

    FOR(m) {
        int a = tunnels[i].f, b = tunnels[i].s;

        if (SCC[a] != SCC[b]) {
            int prev_len = edges_new[SCC[a]].size();

            edges_new[SCC[a]].insert(SCC[b]);

            if (prev_len < edges_new[SCC[a]].size())
                indeg[SCC[b]]++;
        }
    }

    FOR(n) {
        coins_new[SCC[i]] += coins[i];
    }

    // DP + topsort
    queue<int> topsort;
    vector<ll> dp(SCC_cnt);
    ll ans = 0;

    FOR(SCC_cnt) {
        dp[i] = coins_new[i];

        if (indeg[i] == 0) {
            topsort.push(i);
        }

    }

    while (!topsort.empty()) {
        int curr_node = topsort.front();

        ans = max(ans, dp[curr_node]);

        for (int dest : edges_new[curr_node]) {
            dp[dest] = max(dp[curr_node] + coins_new[dest], dp[dest]);
            indeg[dest]--;

            if (indeg[dest] == 0) {
                topsort.push(dest);
            }
        }

        topsort.pop();
    }

    cout << ans;

    return 0;
}

