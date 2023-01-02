/*____________________________________________________________
// started : 01/02/22
// finished: 01/02/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=790
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
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
#define BIG (int)(INT_MAX)
#define BIGGER (ll)(LLONG_MAX)
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 1e5;
vector<vector<int>> adj(MAX_N);
int indeg[MAX_N];
int farmer_to[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    int n, k; cin >> n >> k; k--;

    FOR(i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
        indeg[a]++;
        indeg[b]++;
    }

    // topsort for farmers
    queue<int> leaves;
    fill(farmer_to, farmer_to + n, BIG);
    FOR(i, n) if (indeg[i] == 1) { leaves.push(i); farmer_to[i] = 0; }
    while (!leaves.empty()) {
        int u = leaves.front(); leaves.pop();
        for (int v : adj[u]) {
            farmer_to[v] = min(farmer_to[v], farmer_to[u] + 1);
            indeg[v]--;
            if (indeg[v] == 1) leaves.push(v);
        }
    }

    // bfs for bessie
    int ans = 0;
    queue<tuple<int, int, int>> bfs; // node, dist, parent 
    bfs.push({ k, 0, -1 });
    while (!bfs.empty()) {
        auto [u, dist, parent] = bfs.front(); bfs.pop();
        if (farmer_to[u] <= dist) ans++;
        else
            for (int v : adj[u]) if (v != parent) bfs.push({ v, dist + 1, u });
    }

    cout << ans;

    return 0;
}
