/*____________________________________________________________
// started : 12/30/22
// finished:
// problem : https://codeforces.com/group/eZhSssSlea/contest/419284/problem/D
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
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
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 5 * 1e5;

int n;
int c[MAX_N], dp[MAX_N], dist[MAX_N];
vector<vector<int>> edges(MAX_N, vector<int>());

void dfs(int u, int parent) {
    for (int v : edges[u]) {
        if (v == parent) continue;

        dfs(v, u);
        if (dp[u] == 0) {
            dp[u] = dp[v] + 1;
        }
        else {
            int curr_first = max(dp[u], 2 * dist[u] + dp[v] + 1);
            int v_first = max(dp[v] + 1, 2 * (dist[v] + 1) + dp[u]);

            dp[u] = min(curr_first, v_first);
        }
        dist[u] += dist[v] + 1;
        int something = 0;
    }
    dp[u] = max(dp[u], c[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    FOR(i, n)
        cin >> c[i];

    FOR(i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    dfs(0, -1);

    cout << max(dp[0], c[0] + 2 * (n - 1));

    return 0;
}