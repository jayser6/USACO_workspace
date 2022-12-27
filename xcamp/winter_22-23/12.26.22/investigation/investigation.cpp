/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://cses.fi/problemset/task/1202
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
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
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME 999998727899999LL // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
    FOR(i, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;

        edges[a].pb({ b, c });
    }

    set<pair<ll, int>> dijkstra;
    vector<ll> cost(n, BIG_NUMBER);
    vector<int> num_ways(n, 0);
    vector<int> min_dist(n, PRIME32), max_dist(n, 0);

    dijkstra.insert({ 0, 0 });
    cost[0] = 0;
    num_ways[0] = 1;
    max_dist[0] = 0;
    min_dist[0] = 0;

    while (!dijkstra.empty()) {
        auto curr = *dijkstra.begin(); dijkstra.erase(dijkstra.begin());

        if (curr.f > cost[curr.s])
            continue;

        for (auto edge : edges[curr.s]) {
            ll new_cost = edge.s + curr.f;

            if (new_cost < cost[edge.f]) {
                cost[edge.f] = new_cost;
                num_ways[edge.f] = num_ways[curr.s];
                min_dist[edge.f] = min_dist[curr.s] + 1;
                max_dist[edge.f] = max_dist[curr.s] + 1;

                dijkstra.insert({ new_cost, edge.f });
            }
            else if (new_cost == cost[edge.f]) {
                num_ways[edge.f] += num_ways[curr.s];
                num_ways[edge.f] %= PRIME32;

                min_dist[edge.f] = min(min_dist[edge.f], min_dist[curr.s] + 1);
                max_dist[edge.f] = max(max_dist[edge.f], max_dist[curr.s] + 1);
            }
        }
    }

    cout << cost[n - 1] << " " << num_ways[n - 1] << " " << min_dist[n - 1] << " " << max_dist[n - 1] << endl;

    return 0;
}
