// started : 05/06/22
// finished: 05/13/22
// problem : https://cses.fi/problemset/task/1160

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

void findTree(int currNode, int currDepth, vector<vector<int>>& edgesRev, vector<int>& depth, vector<int>& inDeg) {
    depth[currNode] = currDepth;

    for (int dest : edgesRev[currNode]) {
        if (inDeg[dest] == 0) {
            findTree(dest, currDepth + 1, edgesRev, depth, inDeg);
        }
    }
}

void findCycle(int curr, int currComp, int currOrder, vector<vector<int>>& edges, vector<pair<int, int>>& cycles) {
    cycles[curr].s = currOrder;
    cycles[curr].f = currComp;

    if (cycles[edges[curr][0]].s == -1) {
        findCycle(edges[curr][0], currComp, currOrder + 1, edges, cycles);
    }
    return;
}

int jump(int curr, int num, vector<vector<int>>& up) {
    int index = 0;
    while (num > 0) {
        if (num % 2) {
            curr = up[curr][index];
        }

        num /= 2;
        index++;
    }

    return curr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<vector<int>> up(n, vector<int>((int)log2(n) + 1, -1));
    vector<vector<int>> edgesRev(n);
    vector<int> inDeg(n, 0);
    for (int i = 0;i < n;i++) {
        cin >> up[i][0];
        up[i][0]--;
        inDeg[up[i][0]]++;
        edgesRev[up[i][0]].pb(i);
    }

    // topo sort the graph and DFS to find cycles
    queue<int> topo;
    for (int i = 0;i < n;i++) {
        if (inDeg[i] == 0) {
            topo.push(i);
        }
    }

    while (!topo.empty()) {
        int curr = topo.front();
        topo.pop();

        inDeg[up[curr][0]]--;
        if (inDeg[up[curr][0]] == 0) {
            topo.push(up[curr][0]);
        }
    }

    vector<pair<int, int>> cycles(n, mp(-1, -1)); // f -> which cycle, s -> the order of node i in its given cycle
    int compNum = 0;
    for (int i = 0;i < n;i++) {
        if (inDeg[i] != 0 && cycles[i].s == -1) {
            findCycle(i, compNum, 0, up, cycles);
            compNum++;
        }
    }

    // to calculate distances between two nodes in the same cycle
    vector<int> compSize(compNum, -1);
    for (pair<int, int> currNode : cycles) {
        if (currNode.f == -1) {
            continue;
        }

        compSize[currNode.f] = max(currNode.s + 1, compSize[currNode.f]);
    }

    vector<int> depth(n, -1);
    for (int i = 0;i < n;i++) {
        if (inDeg[i] != 0) {
            findTree(i, 0, edgesRev, depth, inDeg);
        }
    }

    // binary lifting yay
    for (int j = 1;j < log2(n) + 1;j++) {
        for (int i = 0;i < n;i++) {
            if (up[i][j - 1] != -1 && inDeg[i] == 0 && exp2(j) <= depth[i]) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    for (int i = 0;i < q;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        // go through the different cases

        // case 0: a and b are the same nodes
        if (a == b) {
            cout << "0" << endl;
            continue;
        }

        // case 1: both nodes are in a tree
        else if (inDeg[a] == 0 && inDeg[b] == 0) {
            if (depth[a] > depth[b]) {
                int ancestor = jump(a, depth[a] - depth[b], up);
                if (ancestor == b) {
                    cout << depth[a] - depth[b] << endl;
                    continue;
                }
            }
        }

        // case 2: both nodes are in the same cycle
        else if (inDeg[a] != 0 && inDeg[b] != 0 && cycles[a].f == cycles[b].f) {
            cout << (cycles[b].s - cycles[a].s + compSize[cycles[a].f]) % compSize[cycles[a].f] << endl;
            continue;
        }

        // case 3: a is in a tree, b is in a cycle
        else if (inDeg[a] == 0 && inDeg[b] != 0) {
            int ancestor = jump(a, depth[a], up);
            if (cycles[ancestor].f == cycles[b].f) {
                cout << (cycles[b].s - cycles[ancestor].s + compSize[cycles[b].f]) % compSize[cycles[b].f] + depth[a] << endl;
                continue;
            }
        }

        cout << "-1" << endl;
    }

}
