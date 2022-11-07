// started : 03/01/22
// finished: 03/01/22
// problem : https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;

// node index, length from their respective comparative nodes
pair<int, int> node_A; // furthest node from the root(node 0)
pair<int, int> node_B; // furthest node from node A

void DFS(int node, int length, int whichDFS) { // whichDFS: 1 -> first DFS, 2 -> second DFS
    visited[node] = true;

    if (whichDFS == 1 && node_A.s < length) {
        node_A.f = node;
        node_A.s = length;
    }
    else if (whichDFS == 2 && node_B.s < length) {
        node_B.f = node;
        node_B.s = length;
    }

    for (int destination : edges[node]) {
        if (!visited[destination]) {
            DFS(destination, length + 1, whichDFS);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    edges = vector<vector<int>>(n);
    for (int i = 0;i < n - 1;i++) {
        int a, b; cin >> a >> b;
        
        a--;
        b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    visited = vector<bool>(n, false);

    // set the root as node 0 and find the furthest node from the root
    node_A.f = 0;
    node_A.s = 0;
    DFS(0, 0, 1);

    visited = vector<bool>(n, false);

    // set the root as the furthest node from node 0, and find the furthest node from the root
    node_B.f = node_A.f;
    node_B.s = 0;
    DFS(node_A.f, 0, 2);

    cout << node_B.s;
}
