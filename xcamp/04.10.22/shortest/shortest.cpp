// started : 4/15/22 
// finished: 4/16/22
// problem : https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define p_queue priority_queue
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> edges(n);
    for (int i = 0;i < m;i++) {
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;

        edges[a].pb(mp(b, c));
    }

    vector<ll> distance(n, BIG_NUMBER);
    set<pair<ll, int>> dijkstra;
    dijkstra.insert(mp(0, 0));

    while (!dijkstra.empty()) {
        pair<ll, int> curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());

        if (curr.f > distance[curr.s]) {
            continue;
        }

        distance[curr.s] = curr.f;
        for (pair<int, ll> dest : edges[curr.s]) {
            if (curr.f + dest.s < distance[dest.f]) {
                distance[dest.f] = curr.f + dest.s;
                dijkstra.insert(mp(curr.f + dest.s, dest.f));
            }
        }
    }

    for (ll length : distance) {
        cout << length << " ";
    }
}