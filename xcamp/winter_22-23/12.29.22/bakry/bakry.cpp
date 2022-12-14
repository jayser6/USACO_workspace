/*____________________________________________________________
// started : 12/29/22
// finished:
// problem :
____________________________________________________________*/

#include <bits/stdc++.h>

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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

const int MAX_N = 1e5;
int a[MAX_N];
vector<vector<int>> adj(MAX_N);

int dfs(int u, int p) {
    int xor_below = a[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        xor_below ^= dfs(v, u);
    }
    return xor_below;
}

void solve() {
    int n, k; cin >> n >> k;
    FOR(i, n) cin >> a[i];

    fill(ALL(adj), vector<int>());
    FOR(i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (dfs(0, -1) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;cin >> t;
    while (t--)
        solve();

    return 0;
}
