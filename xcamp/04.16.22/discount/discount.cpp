// started : 04/22/22
// finished: 04/28/22
// problem : https://cses.fi/problemset/task/1195

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

    vector<vector<ll>> costTo(n, vector<ll>(2, BIG_NUMBER));
    set<pair<ll, pair<int, bool>>> dijkstra; // cost to arrive at node, node number, ticket availability
    dijkstra.insert(mp(0, mp(0, false)));
    costTo[0][false] = 0;
    costTo[0][true] = 0;
    while (!dijkstra.empty()) {
        auto curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());
        if (curr.f > costTo[curr.s.f][curr.s.s]) {
            continue;
        }

        for (auto dest : edges[curr.s.f]) {
            if ((dest.s + curr.f) < costTo[dest.f][curr.s.s]) {
                costTo[dest.f][curr.s.s] = dest.s + curr.f;
                dijkstra.insert(mp(dest.s + curr.f, mp(dest.f, curr.s.s)));
            }

            if (!curr.s.s && (curr.f + (dest.s / 2)) < costTo[dest.f][true]) {
                costTo[dest.f][true] = curr.f + (dest.s / 2);
                dijkstra.insert(mp(curr.f + (dest.s / 2), mp(dest.f, true)));
            }
        }
    }

    cout << costTo[n - 1][true];
}