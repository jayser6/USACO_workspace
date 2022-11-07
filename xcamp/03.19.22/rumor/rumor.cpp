// started : 03/24/22
// finished: 03/24/22
// problem : https://codeforces.com/problemset/problem/893/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void DFS(int curr, vector<bool>& visited, vector<vector<int>>& edges) {
    visited[curr] = true;

    for (int dest : edges[curr]) {
        if (!visited[dest]) {
            DFS(dest, visited, edges);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    vector<pair<ll, int>> cost(n);
    for (int i = 0;i < n;i++) {
        cin >> cost[i].f;
        cost[i].s = i;
    }

    sort(ALL(cost));

    vector<vector<int>> edges(n);
    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    ll output = 0;
    vector<bool> visited(n, false);
    for (int i = 0;i < n;i++) {
        if (!visited[cost[i].s]) {
            DFS(cost[i].s, visited, edges);
            output += cost[i].f;
        }
    }
 
    cout << output;
}