// started : 04/16/22
// finished: 04/18/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=969

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
// #define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("pump.in");
ofstream fout("pump.out");

struct Edge {
    int to, c, fr;

    Edge(int to, int c, int fr) {
        this->to = to;
        this->c = c;
        this->fr = fr;
    }
};

int Dijkstra(vector<vector<Edge>>& edges, int minF) {
    vector<int> costTo(edges.size(), pow(10, 8));

    set<pair<int, int>> dijkstra;
    dijkstra.insert(mp(0, 0));
    while (!dijkstra.empty()) {
        pair<int, int> curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());

        if (curr.f > costTo[curr.s]) {
            continue;
        }

        for (auto dest : edges[curr.s]) {
            if (dest.fr < minF || curr.f + dest.c > costTo[dest.to]) {
                continue;
            }

            dijkstra.insert(mp(curr.f + dest.c, dest.to));
            costTo[dest.to] = curr.f + dest.c;
        }
    }

    int ans = costTo[edges.size() - 1];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; fin >> n >> m;

    vector<vector<Edge>> edges(n);
    vector<int> fRates(m);
    for (int i = 0;i < m;i++) {
        int a, b, c, fr; fin >> a >> b >> c >> fr;
        a--; b--;

        fRates[i] = fr;
        edges[a].pb(Edge(b, c, fr));
        edges[b].pb(Edge(a, c, fr));
    }

    sort(ALL(fRates)); // this is just to make the numbers nice, isn't necessary to solve the the question

    long double ans = -1;
    for (int minF : fRates) {
        ans = max(ans, ((long double)minF / Dijkstra(edges, minF)));
    }

    // fout << fixed << setprecision(9) << ans * 1000000LL;
    fout << (int)(ans * 1000000LL);
}