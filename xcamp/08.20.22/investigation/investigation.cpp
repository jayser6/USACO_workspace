/*____________________________________________________________
// started : 08/24/22
// finished: 08/24/22
// problem : https://cses.fi/problemset/task/1202
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
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /* get input */
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> edges(n);
    FOR(m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;

        edges[a].pb({ b, c });
    }

    /* dijkstra */
    p_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> dijkstra; // cost, index
    vector<ll> cost(n, BIG_NUMBER);
    vector<ll> num_ways(n, 0);
    vector<int> maxF(n, 0);
    vector<int> minF(n, PRIME32);

    dijkstra.push({ 0, 0 });
    cost[0] = 0;
    num_ways[0] = 1;
    maxF[0] = 0;
    minF[0] = 0;

    while (!dijkstra.empty()) {
        pair<ll, int> curr = dijkstra.top();

        dijkstra.pop();
        if (curr.f > cost[curr.s])
            continue;

        for (pair<int, int> dest : edges[curr.s]) {
            ll new_cost = dest.s + curr.f;

            if (new_cost == cost[dest.f]) {
                num_ways[dest.f] += num_ways[curr.s];
                num_ways[dest.f] %= PRIME32;
                minF[dest.f] = min(minF[dest.f], minF[curr.s] + 1);
                maxF[dest.f] = max(maxF[dest.f], maxF[curr.s] + 1);
            }
            else if (new_cost < cost[dest.f]) {
                cost[dest.f] = new_cost;
                num_ways[dest.f] = num_ways[curr.s];
                num_ways[dest.f] %= PRIME32;
                minF[dest.f] = minF[curr.s] + 1;
                maxF[dest.f] = maxF[curr.s] + 1;
                dijkstra.push({ new_cost, dest.f });
            }
        }
    }

    cout << cost[n - 1] << " " << num_ways[n - 1] << " " << minF[n - 1] << " " << maxF[n - 1];

    return 0;
}