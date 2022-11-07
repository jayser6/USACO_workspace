// started : 05/04/22
// finished: 05/05/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=788

// main idea: sort the k in decreasing order so that you can add more and more edges. 
//            each query, expand DSU

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

ifstream fin("mootube.in");
ofstream fout("mootube.out");

struct Edge {
    int a, b;
    ll r;
};

struct Query {
    int index, v;
    ll k;
};

bool cmpEdge(Edge a, Edge b) {
    return a.r > b.r;
}

bool cmpQuery(Query a, Query b) {
    return a.k > b.k;
}

int findHead(int curr, vector<pair<int, int>>& comp) {
    if (curr == comp[curr].f) {
        return curr;
    }

    comp[curr].f = findHead(comp[curr].f, comp);
    return comp[curr].f;
}

void merge(int a, int b, vector<pair<int, int>>& comp) {
    if (comp[a].s > comp[b].s) {
        comp[b].f = a;
        comp[a].s += comp[b].s;
    }
    else {
        comp[a].f = b;
        comp[b].s += comp[a].s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; fin >> n >> q;

    vector<Edge> edges(n - 1);
    for (int i = 0;i < n - 1;i++) {
        fin >> edges[i].a >> edges[i].b >> edges[i].r;
        edges[i].a--; edges[i].b--;
    }

    sort(ALL(edges), cmpEdge);

    vector<Query> queries(q);
    for (int i = 0;i < q;i++) {
        fin >> queries[i].k >> queries[i].v;
        queries[i].v--;
        queries[i].index = i;
    }

    sort(ALL(queries), cmpQuery);

    vector<pair<int, int>> comp(n); // f -> parent, s -> size of comp
    for (int i = 0;i < n;i++) {
        comp[i] = mp(i, 1);
    }

    vector<int> ans(q);
    int currEdge = 0;
    for (Query currQ : queries) {
        while (currEdge < n - 1 && edges[currEdge].r >= currQ.k) {
            Edge curr = edges[currEdge];
            currEdge++;

            int aHead = findHead(curr.a, comp);
            int bHead = findHead(curr.b, comp);

            if (aHead == bHead) {
                continue;
            }

            merge(aHead, bHead, comp);
        }

        ans[currQ.index] = comp[findHead(currQ.v, comp)].s - 1;
    }

    for (int curr : ans) {
        fout << curr << endl;
    }
}