/*____________________________________________________________
// started : 12/16/22
// finished: 12/16/22
// problem : https://codeforces.com/contest/1760/problem/G
____________________________________________________________*/

#include <bits/stdc++.h>

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
#define BIG_NUMBER 1e18LL
#define BIG_PRIME 999998727899999LL // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

void find_req(vector<vector<pair<int, int>>>& edges, set<int>& req, int curr, int x, int parent) {
    if (parent != -1)
        req.insert(x);

    for (auto& edge : edges[curr]) {
        if (edge.f == parent)
            continue;

        find_req(edges, req, edge.f, x ^ edge.s, curr);
    }
}

bool can_reach(vector<vector<pair<int, int>>>& edges, set<int>& req, int curr, int x, int b, int parent) {
    if (req.find(x) != req.end())
        return true;

    for (auto& edge : edges[curr]) {
        if (edge.f == parent)
            continue;

        if (edge.f != b && can_reach(edges, req, edge.f, x ^ edge.s, b, curr))
            return true;
    }

    return false;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    a--; b--;

    vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
    FOR(i, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges[u].pb({ v, w });
        edges[v].pb({ u, w });
    }

    vector<bool> visited(n, false);
    // vector<int> req(n, -1); // req[i] is required to go from i to b without
    // TP
    set<int> req; // if a can reach any node with x in req, then a can reach b
    visited[b] = true;

    find_req(edges, req, b, 0, -1);
    if (can_reach(edges, req, a, 0, b, -1)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
