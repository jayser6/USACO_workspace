/*____________________________________________________________
// started : 08/03/22
// finished: 08/03/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1138
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
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

struct edge {
    int val;
    int a, b;
    edge(int val, int a, int b) {
        this->val = val;
        this->a = a;
        this->b = b;
    }
};

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_head(vector<pair<int, int>>& comps, int curr) {
    if (curr == comps[curr].f) {
        return curr;
    }

    comps[curr].f = find_head(comps, comps[curr].f);
    return comps[curr].f;
}

void merge(vector<pair<int, int>>& comps, int a, int b) {
    if (comps[a].s > comps[b].s) {
        comps[a].s += comps[b].s;
        comps[b].f = a;
    }
    else {
        comps[b].s += comps[a].s;
        comps[a].f = b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<edge> edges;
    FOR(n) {
        int c, p1, p2, p3, p4; cin >> c >> p1 >> p2 >> p3 >> p4;
        p1--; p2--; p3--; p4--;

        // "free" edges
        edges.pb(edge(0, p1, p2));
        edges.pb(edge(0, p3, p4));

        // "switch" edges
        edges.pb(edge(c, p1, p3));
        edges.pb(edge(c, p1, p4));
        edges.pb(edge(c, p1, p4));
    }

    // run MST
    vector<pair<int, int>> comps(2 * n);
    FOR(2 * n) {
        comps[i] = { i, 1 };
    }

    ll output = 0;
    sort(ALL(edges), cmp);
    for (edge curr_edge : edges) {
        int a_head = find_head(comps, curr_edge.a);
        int b_head = find_head(comps, curr_edge.b);

        if (a_head != b_head) {
            // build this edge
            output += curr_edge.val;
            merge(comps, a_head, b_head);
        }
    }

    cout << output;

    return 0;
}
