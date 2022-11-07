// started : 05/02/22
// finished: 05/04/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=861

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll) pow(10, 18)

using namespace std;

ifstream fin("dining.in");
ofstream fout("dining.out");

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k; fin >> n >> m >> k;

    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0;i < m;i++) {
        int a, b; int t; fin >> a >> b >> t;
        a--; b--;

        edges[a].pb(mp(b, t));
        edges[b].pb(mp(a, t));
    }

    vector<pair<int, ll>> haybales(k);
    for (int i = 0;i < k;i++) {
        fin >> haybales[i].f >> haybales[i].s;
        haybales[i].f--;
    }

    // first dijkstra
    vector<vector<ll>> distTo(n, vector<ll>(2, BIG_NUMBER)); // 0 -> no haybales
    set<pair<ll, int>> dijkstra;
    distTo[n - 1] = { 0, 0 };
    dijkstra.insert(mp(0, n - 1));

    while (!dijkstra.empty()) {
        pair<ll, int> curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());

        if (curr.f > distTo[curr.s][0]) {
            continue;
        }

        for (pair<int, int> dest : edges[curr.s]) {
            ll nextDist = curr.f + dest.s;
            if (nextDist < distTo[dest.f][0]) {
                distTo[dest.f][0] = nextDist;
                dijkstra.insert(mp(nextDist, dest.f));
            }
        }
    }

    // run the second dijkstra
    for (pair<int, ll> haybale : haybales) {
        dijkstra.insert(mp(distTo[haybale.f][0] - haybale.s, haybale.f));
        distTo[haybale.f][1] = distTo[haybale.f][0] - haybale.s;
    }

    while (!dijkstra.empty()) {
        pair<ll, int> curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());

        if (curr.f > distTo[curr.s][1]) {
            continue;
        }

        for (pair<int, int> dest : edges[curr.s]) {
            ll nextDist = curr.f + dest.s;
            if (nextDist < distTo[dest.f][1]) {
                distTo[dest.f][1] = nextDist;
                dijkstra.insert(mp(nextDist, dest.f));
            }
        }
    }

    for (int i = 0;i < n - 1;i++) {
        if (distTo[i][0] >= distTo[i][1]) {
            fout << "1" << endl;
        }
        else {
            fout << "0" << endl;
        }
    }
}
