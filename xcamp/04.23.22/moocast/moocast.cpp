// started : 04/30/22
// finished: 04/30/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=669
// note    : this revision of the solution uses optimized DSU

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define y first
#define x second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

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
    return a.weight < b.weight;
}

int findHead(int curr, vector<pair<int, int>>& parent) {
    if (curr == parent[curr].f) {
        return curr;
    }

    parent[curr].f = findHead(parent[curr].f, parent);
    return parent[curr].f;
}

void merge(int a, int b, vector<pair<int, int>>& parent) { // a and b are the heads of their  
    if (parent[a].s > parent[b].s) {                       // respective subsets
        parent[b].f = a;
        parent[a].s += parent[b].s;
    }
    else {
        parent[a].f = b;
        parent[b].s += parent[a].s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0;i < n;i++) {
        cin >> cows[i].x >> cows[i].y;
    }

    vector<Edge> edges;
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            edges.pb(Edge(i, j, (cows[i].x - cows[j].x) * (cows[i].x - cows[j].x) +
                (cows[i].y - cows[j].y) * (cows[i].y - cows[j].y)));
        }
    }

    sort(ALL(edges), cmp);

    vector<pair<int, int>> parent(n); // parent of each node i
    for (int i = 0;i < n;i++) {
        parent[i].f = i; // each node is its own parent at first
        parent[i].s = 1; // the second of the pair represents the size of the subset if the 
    }                    // head of the subset is i

    for (Edge curr : edges) {
        int aHead = findHead(curr.a, parent);
        int bHead = findHead(curr.b, parent);

        if (aHead == bHead) {
            continue;
        }

        merge(aHead, bHead, parent);
        if (parent[aHead].s == n || parent[bHead].s == n) {
            cout << curr.weight;
            break;
        }
    }
}