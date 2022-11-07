// started : 04/30/22
// finished: 04/30/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=531

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

ifstream fin("superbull.in");
ofstream fout("superbull.out");

struct Edge {
    int a, b;
    ll weight;
    Edge(int a, int b, ll weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
};

bool cmp(Edge a, Edge b) {
    return a.weight > b.weight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; fin >> n;

    vector<ll> ID(n);
    for (int i = 0;i < n;i++) {
        fin >> ID[i];
    }

    vector<Edge> edges;
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            edges.pb(Edge(i, j, ID[i] ^ ID[j]));
        }
    }

    sort(ALL(edges), cmp);

    ll output = 0;
    vector<vector<int>> components(n);
    vector<int> whichComp(n);
    for (int i = 0;i < n;i++) {
        components[i].pb(i);
        whichComp[i] = i;
    }

    for (Edge curr : edges) {
        if (whichComp[curr.a] == whichComp[curr.b]) {
            continue;
        }

        output += curr.weight;

        // update DSU
        int smaller, bigger;
        if (components[whichComp[curr.a]].size() > components[whichComp[curr.b]].size()) {
            smaller = whichComp[curr.b];
            bigger = whichComp[curr.a];
        }
        else {
            smaller = whichComp[curr.a];
            bigger = whichComp[curr.b];
        }

        for (int i = 0;i < components[smaller].size();i++) {
            components[bigger].pb(components[smaller][i]);
            whichComp[components[smaller][i]] = bigger;
        }
    }

    fout << output;
}