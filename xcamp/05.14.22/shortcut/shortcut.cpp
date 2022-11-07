/*____________________________________________________________
// started : 05/17/22
// finished: 05/19/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=899
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
#define upper upper_bound
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("shortcut.in");
ofstream fout("shortcut.out");

struct P {
    int index;
    int from;
    ll time;
    P(int index, int from, ll time) {
        this->index = index;
        this->from = from;
        this->time = time;
    }
};

struct cmp {
    bool operator()(const P& a, const P& b) const {
        if (a.time == b.time) {
            return a.from < b.from;
        }
        return a.time < b.time;
    }
};

int DFS(int curr, vector<vector<int>>& revEdges, vector<int>& fields, vector<int>& cnt) {
    cnt[curr] = fields[curr];

    for (int dest : revEdges[curr]) {
        cnt[curr] += DFS(dest, revEdges, fields, cnt);
    }

    return cnt[curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t; fin >> n >> m >> t;

    vector<int> fields(n);
    for (int& field : fields) {
        fin >> field;
    }

    vector<vector<pair<int, int>>> edges(n);
    FOR(m) {
        int a, b, t_i; fin >> a >> b >> t_i;
        a--; b--;
        edges[a].pb(mp(b, t_i));
        edges[b].pb(mp(a, t_i));
    }

    vector<pair<int, ll>> distTo(n, mp(-1, BIG_NUMBER)); // f -> the previous node, s -> total distance to get to the current node
    multiset<P, cmp> dijkstra;
    dijkstra.insert(P(0, 0, 0));
    distTo[0].s = 0;

    while (!dijkstra.empty()) {
        P curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());

        if (curr.time > distTo[curr.index].s || distTo[curr.index].f != -1) {
            continue;
        }

        distTo[curr.index].f = curr.from;
        for (pair<int, int> dest : edges[curr.index]) {
            int newTime = curr.time + dest.s;
            if (newTime <= distTo[dest.f].s) {
                int before = dijkstra.size();
                distTo[dest.f].s = newTime;
                dijkstra.insert(P(dest.f, curr.index, newTime));
            }
        }
    }

    vector<vector<int>> revEdges(n);
    FORO(n) {
        if (distTo[i].f < 0 || distTo[i].f >= n) {
            cout << "yello";
        }
        revEdges[distTo[i].f].pb(i);
    }

    vector<int> cnt(n, 0); // number of cows that visit node i
    DFS(0, revEdges, fields, cnt);

    ll output = 0;
    FORO(n) {
        ll newTime = cnt[i] * (distTo[i].s - t);
        output = max(output, newTime);
    }

    fout << output;
}
