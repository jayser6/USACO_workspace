/*____________________________________________________________
// started : 08/04/22
// finished: 08/12/22
// problem : http://www.usaco.org/current/index.php?page=viewproblem2&cpid=576
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

struct node {
    int val, depth, parent;
    node() {}
    node(int val, int depth, int parent) {
        this->val = val;
        this->depth = depth;
        this->parent = parent;
    }
};

int jump(vector<vector<int>>& up, int curr_node, int height) {
    int index = 0;
    while (height > 0) {
        if (height % 2)
            curr_node = up[curr_node][index];

        height /= 2;
        index++;
    }

    return curr_node;
}

int findLCA(vector<vector<int>>& up, vector<node>& nodes, int a, int b) {
    // bring a and b to the same depth
    {
        int depth_dif = abs(nodes[a].depth - nodes[b].depth);
        if (nodes[a].depth > nodes[b].depth)
            a = jump(up, a, depth_dif);
        else
            b = jump(up, b, depth_dif);
    }

    if (a == b)
        return a;

    int max_e = log2(up.size()) + 1;

    // binary search for the node that is right below the LCA of a and b
    ROF(max_e) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    // the LCA is right above a and b
    int LCA = up[a][0];
    return LCA;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);

    int n, k; cin >> n >> k;

    int max_e = log2(n) + 1;
    vector<node> nodes(n);
    vector<vector<int>> up(n, vector<int>(max_e, -1));
    vector<int> indeg(n, 0);
    {
        vector<vector<int>> edges(n);
        FOR(n - 1) {
            int a, b; cin >> a >> b;
            a--; b--;
            edges[a].pb(b);
            edges[b].pb(a);
        }

        vector<bool> visited(n, false);
        stack<int> dfs;

        nodes[0] = node(0, 0, -1);
        dfs.push(0);
        visited[0] = true;

        while (!dfs.empty()) {
            int curr_node = dfs.top();

            dfs.pop();

            for (int dest : edges[curr_node]) {
                if (!visited[dest]) {
                    indeg[curr_node]++;
                    visited[dest] = true;
                    nodes[dest] = node(0, nodes[curr_node].depth + 1, curr_node);
                    up[dest][0] = curr_node;

                    dfs.push(dest);
                }
            }
        }
    }

    for (int i = 1;i < max_e;i++) {
        for (int j = 0;j < n;j++) {
            if (up[j][i - 1] != -1)
                up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    FOR(k) {
        int a, b; cin >> a >> b;
        a--; b--;

        int ancestor = findLCA(up, nodes, a, b);

        if (ancestor == a) {
            if (a != 0) {
                nodes[nodes[a].parent].val--;
            }
            nodes[b].val++;
        }
        else if (ancestor == b) {
            if (b != 0) {
                nodes[nodes[b].parent].val--;
            }
            nodes[a].val++;
        }
        else {
            if (ancestor != 0) {
                nodes[nodes[ancestor].parent].val--;
            }
            nodes[ancestor].val--;
            nodes[a].val++;
            nodes[b].val++;
        }
    }

    int ans = 0;
    vector<int> flow_val(n, 0);
    queue<int> topsort;

    FOR(n) {
        if (indeg[i] == 0) {
            topsort.push(i);
        }
    }
    while (!topsort.empty()) {
        int curr_node = topsort.front();
        int curr_val = flow_val[curr_node] + nodes[curr_node].val;
        int parent = nodes[curr_node].parent;

        ans = max(curr_val, ans);
        parent = max(parent, 0);
        flow_val[parent] += curr_val;
        indeg[parent]--;
        topsort.pop();
        if (indeg[parent] == 0) {
            topsort.push(parent);
        }
    }

    cout << ans;

    return 0;
}
