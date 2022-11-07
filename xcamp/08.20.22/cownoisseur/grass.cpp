/*____________________________________________________________
// started : 08/26/22
// finished: 08/27/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=516
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

void dfs1(vector<vector<int>>& edges_r, vector<bool>& visited, stack<int>& scc_order, int curr_node) {
    visited[curr_node] = true;

    for (int dest : edges_r[curr_node]) {
        if (!visited[dest]) {
            dfs1(edges_r, visited, scc_order, dest);
        }
    }

    scc_order.push(curr_node);
}

void dfs2(vector<vector<int>>& edges, vector<int>& scc_id, int curr_node, int curr_id) {
    scc_id[curr_node] = curr_id;

    for (int dest : edges[curr_node]) {
        if (scc_id[dest] == -1) {
            dfs2(edges, scc_id, dest, curr_id);
        }
    }
}

void find_dist(vector<int>& dist, vector<hashset<int>>& edges, vector<int>& indeg, const vector<int>& val, const int origin) {
    stack<pair<int, bool>> topsort;

    FOR(indeg.size()) {
        if (indeg[i] == 0)
            topsort.push({ i, false });
    }

    while (!topsort.empty()) {
        int curr = topsort.top().f;
        bool should_add = topsort.top().s;

        if (curr == origin)
            should_add = true;

        topsort.pop();
        for (int dest : edges[curr]) {
            indeg[dest]--;

            if (indeg[dest] == 0)
                topsort.push({ dest, should_add });

            if (should_add) {
                dist[dest] = max(dist[dest], val[dest] + dist[curr]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("grass.in", "r", stdin);
    freopen("grass.out", "w", stdout);

    /* input */
    int n, m; cin >> n >> m;

    vector<pair<int, int>> og_edges(m);
    vector<vector<int>> edges(n), edges_r(n);
    FOR(m) {
        cin >> og_edges[i].f >> og_edges[i].s;
        og_edges[i].f--; og_edges[i].s--;

        edges[og_edges[i].f].pb(og_edges[i].s);
        edges_r[og_edges[i].s].pb(og_edges[i].f);
    }

    /* SCC */
    vector<bool> visited(n, false);
    vector<int> scc_id(n, -1);
    stack<int> scc_order;

    FOR(n) {
        if (!visited[i]) {
            dfs1(edges_r, visited, scc_order, i);
        }
    }

    int scc_cnt = 0;
    while (!scc_order.empty()) {
        int curr = scc_order.top();

        scc_order.pop();
        if (scc_id[curr] == -1) {
            dfs2(edges, scc_id, curr, scc_cnt);
            scc_cnt++;
        }
    }

    /* re-organizing the graph + initialization for topsort */
    vector<hashset<int>> edges_new(scc_cnt);
    vector<hashset<int>> edges_new_r(scc_cnt);
    vector<int> indeg(scc_cnt, 0);
    vector<int> indeg_r(scc_cnt, 0);
    vector<int> val(scc_cnt, 0);

    // since some nodes are combined, store the size of each component
    FOR(n) {
        val[scc_id[i]]++;
    }

    // nwe edges
    FOR(m) {
        int a = og_edges[i].f, b = og_edges[i].s;

        if (scc_id[a] != scc_id[b]) {
            int prev_len1 = edges_new[scc_id[a]].size();
            int prev_len2 = edges_new_r[scc_id[b]].size();

            edges_new[scc_id[a]].insert(scc_id[b]);
            edges_new_r[scc_id[b]].insert(scc_id[a]);

            if (edges_new[scc_id[a]].size() > prev_len1)
                indeg[scc_id[b]]++;
            if (edges_new_r[scc_id[b]].size() > prev_len2)
                indeg_r[scc_id[a]]++;
        }
    }

    /* find the dist between 1 to every node, then from every node to 1 */
    vector<int> val_to(scc_cnt, -1); // distance to node i
    vector<int> val_from(scc_cnt, -1); // distance from node i 

    val_to[scc_id[0]] = val[scc_id[0]];
    val_from[scc_id[0]] = 0;

    find_dist(val_to, edges_new, indeg, val, scc_id[0]);
    find_dist(val_from, edges_new_r, indeg_r, val, scc_id[0]);

    /* walk though each possible edge and determine answer */
    int ans = 0;

    for (int a = 0;a < scc_cnt;a++) {
        for (int b : edges_new_r[a]) {
            if ((val_to[a] == -1) || val_from[b] == -1) {
                continue;
            }

            int new_dist = val_to[a] + val_from[b];

            ans = max(ans, new_dist);
        }
    }

    // the origin was counted twice
    cout << ans;

    return 0;
}
