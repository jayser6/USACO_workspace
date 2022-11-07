// started : 03/12/22
// finished: 03/13/22
// problem : https://codeforces.com/problemset/problem/1608/C
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

void DFS(int node, vector<bool>& visited, vector<vector<int>>& edges) {
    visited[node] = true;

    for (int dest : edges[node]) {
        if (!visited[dest]) {
            DFS(dest, visited, edges);
        }
    }
}

void solve() {
    int n; cin >> n;

    vector<pair<ll, int>> map1(n);
    vector<pair<ll, int>> map2(n);
    for (int i = 0;i < n;i++) {
        cin >> map1[i].f;
        map1[i].s = i;
    }
    for (int i = 0;i < n;i++) {
        cin >> map2[i].f;
        map2[i].s = i;
    }

    sort(ALL(map1));
    sort(ALL(map2));

    int champ1 = map1[n - 1].s;
    int champ2 = map2[n - 1].s;

    vector<vector<int>> edges(n);
    for (int i = 0;i < n - 1;i++) {
        edges[map1[i].s].pb(map1[i + 1].s);
        edges[map2[i].s].pb(map2[i + 1].s);
    }

    vector<bool> visited(n, false);
    DFS(champ1, visited, edges);
    DFS(champ2, visited, edges);

    for (int i = 0;i < n;i++) {
        if (visited[i]) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}