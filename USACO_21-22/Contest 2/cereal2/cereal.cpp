// started : 01/28/22
// finished: 03/05/22
// problem : http://usaco.org/index.php?page=viewproblem2&cpid=1184

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

struct Edge {
    int to;
    int index;
    bool isHead; // true -> this end of the edge is the head(2nd priority)

    // I ended up not using isHead...
    Edge(int to, int index, bool isHead) {
        this->to = to;
        this->index = index;
        this->isHead = isHead;
    }
};

vector<int> cowOrder;
vector<vector<Edge>> nodes;
vector<pair<int, int>> edges;
vector<bool> nodeVisited;
vector<bool> edgeVisited;

void findComp(int nodeIndex, vector<int>& compNodes, unordered_set<int>& edgesSeen) {
    nodeVisited[nodeIndex] = true;
    compNodes.pb(nodeIndex);

    for (Edge edge : nodes[nodeIndex]) {
        edgesSeen.insert(edge.index);
        if (!nodeVisited[edge.to]) {
            edgeVisited[edge.index] = true;
            findComp(edge.to, compNodes, edgesSeen);
        }
    }
}

void DFS(int nodeIndex, int prevNode) {
    for (Edge edge : nodes[nodeIndex]) {
        if (edgeVisited[edge.index] && edge.to != prevNode) {
            cowOrder.pb(edge.index + 1);
            DFS(edge.to, nodeIndex);
        }
    }
}

void solveComp(int nodeIndex) {
    // find all nodes that is connected to node[nodeIndex]
    // and keep track of the edges that were seen and the edges
    // that were actually traveled through
    vector<int> compNodes;
    unordered_set<int> edgesSeen;
    findComp(nodeIndex, compNodes, edgesSeen);

    if (compNodes.size() == 1) {
        return;
    }

    bool isTree = true;
    for (auto it = edgesSeen.begin();it != edgesSeen.end();it++) {
        if (!edgeVisited[*it]) {
            // this is the extra node that makes the graph a cycle
            isTree = false;
            cowOrder.pb(*it + 1);
            DFS(edges[*it].f, -1);
            edgeVisited[*it] = true;
            break;
        } 
    }

    if (isTree) {
        DFS(compNodes[0], -1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    nodes = vector<vector<Edge>>(m);
    edges = vector<pair<int, int>>(n);
    for (int i = 0;i < n;i++) {
        int a, b; cin >> a >> b;
        a--; b--;
    
        edges[i].f = a;
        edges[i].s = b;

        nodes[a].pb(Edge(b, i, false));
        nodes[b].pb(Edge(a, i, true));
    }

    nodeVisited = vector<bool>(m, false);
    edgeVisited = vector<bool>(n, false);
    for (int i = 0;i < m;i++) {
        if(!nodeVisited[i]) {
            solveComp(i);
        }
    }
    
    cout << (n - cowOrder.size()) << endl;

    for (int i = 0;i < cowOrder.size();i++) {
        cout << cowOrder[i] << endl;
    }

    for (int i = 0;i < n;i++) {
        if (!edgeVisited[i]) {
            cout << (i + 1) << endl;
        }
    }
}
