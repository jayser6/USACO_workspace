/*____________________________________________________________
// started : 08/31/22
// finished: 08/31/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=970
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

/* dfs functions */
void calc_depth(vector<vector<int>>& edges, vector<int>& depth, vector<vector<int>>& up, int curr_node, int parent) {
    for (int dest : edges[curr_node]) {
        if (dest == parent)
            continue;

        depth[dest] = depth[curr_node] + 1;
        up[dest][0] = curr_node;
        calc_depth(edges, depth, up, dest, curr_node);
    }
}

void count_types(vector<vector<int>>& edges, vector<hashmap<int, int>>& types, vector<int>& types_cnt, vector<int>& cow_type, int curr_node, int parent) {
    types_cnt[cow_type[curr_node]]++;

    for (auto& curr : types[curr_node]) {
        curr.s = types_cnt[curr.f];
    }

    for (int dest : edges[curr_node]) {
        if (dest == parent)
            continue;

        count_types(edges, types, types_cnt, cow_type, dest, curr_node);
    }

    types_cnt[cow_type[curr_node]]--;
}

/* LCA functions */
int jump(vector<vector<int>>& up, int curr_node, int height) {
    int l = 0;

    while (height > 0) {
        if (height % 2)
            curr_node = up[curr_node][l];

        height /= 2;
        l++;
    }

    return curr_node;
}

int LCA(vector<vector<int>>& up, vector<int>& depth, int a, int b) {
    const int MAX_E = up[0].size();

    a = jump(up, a, depth[a] - depth[b]);
    b = jump(up, b, depth[b] - depth[a]);

    if (a == b)
        return a;

    ROF(MAX_E) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    /* get input required to build the graph */
    int n, m; cin >> n >> m;

    vector<int> cow_type(n);
    FOR(n) {
        cin >> cow_type[i];
        cow_type[i]--;
    }

    vector<vector<int>> edges(n);
    FOR(n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    /* pre-process for binary jumping */
    const int MAX_E = log2(n) + 1;
    vector<int> depth(n, -1);
    vector<vector<int>> up(n, vector<int>(MAX_E, -1));

    depth[0] = 0;
    calc_depth(edges, depth, up, 0, -1);

    for (int l = 1;l < MAX_E;l++) {
        FOR(n) {
            if (up[i][l - 1] != -1)
                up[i][l] = up[up[i][l - 1]][l - 1];
        }
    }

    /* get input from the m farmers & store necessary data */
    vector<hashmap<int, int>> types(n);
    vector<pair<pair<int, int>, int>> farmers(m); // { a, b }, t
    FOR(m) {
        int a, b, t; cin >> a >> b >> t;
        a--; b--; t--;

        farmers[i] = { { a, b }, t };

        int lca = LCA(up, depth, a, b);

        types[a].insert({ t, 0 });
        types[b].insert({ t, 0 });
        types[lca].insert({ t, 0 });
    }

    /* dfs from root and find pSum for each node */
    vector<int> types_cnt(n, 0);
    count_types(edges, types, types_cnt, cow_type, 0, -1);

    for (auto& curr : farmers) {
        int a = curr.f.f, b = curr.f.s, t = curr.s;

        int lca = LCA(up, depth, a, b);

        if (cow_type[a] == t || cow_type[lca] == t || cow_type[b] == t) {
            cout << "1";
        }
        else if (types[a][t] != types[lca][t] || types[b][t] != types[lca][t]) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }

    return 0;
}
