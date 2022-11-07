// started : 03/08/22
// finished: 03/08/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1206

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

vector<vector<int>> cowPref;
vector<vector<int>> edges;
vector<vector<bool>> canReach;
vector<bool> visited;

void DFS(int from, int curr) {
    visited[curr] = true;
    canReach[from][curr] = true;

    for (int dest : edges[curr]) {
        if (!visited[dest]) {
            DFS(from, dest);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    cowPref = vector<vector<int>>(n, vector<int>(n));
    edges = vector<vector<int>>(n);
    for (int i = 0;i < n;i++) {
        bool addEdge = true;
        for (int j = 0;j < n;j++) {
            cin >> cowPref[i][j];
            cowPref[i][j]--;

            if (addEdge) {
                edges[i].pb(cowPref[i][j]);
            }
            if (cowPref[i][j] == i) {
                addEdge = false;
            }
        }
    }

    canReach = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0;i < n;i++) {
        visited = vector<bool>(n, false);
        DFS(i, i);
    }


    for (int i = 0;i < n;i++) {
        for (int gift : edges[i]) {
            if (canReach[i][gift] && canReach[gift][i]) {
                cout << (gift + 1) << endl;
                break;
            }
        }
    }
}