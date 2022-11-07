/*____________________________________________________________
// started : 06/30/22
// finished: 06/30/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=384
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
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

struct Edge {
    int val;
    int a, b;
    Edge(int val, int a, int b) {
        this->val = val;
        this->a = a;
        this->b = b;
    }
};

struct Comp {
    int val, head, size, numStart; //  numstart -> number of starting points that are found before size >= t
    Comp() {}
    Comp(int head) {
        size = 1;
        val = 0;
        numStart = 0;
        this->head = head;
    }
};

bool cmp(Edge a, Edge b) {
    return a.val < b.val;
}

int findHead(vector<Comp>& comps, int curr) {
    if (curr == comps[curr].head) {
        return curr;
    }

    comps[curr].head = findHead(comps, comps[curr].head);
    return comps[curr].head;
}

void merge(vector<Comp>& comps, int a, int b) {
    int x = (comps[a].size > comps[b].size) ? a : b;
    int y = (comps[a].size <= comps[b].size) ? a : b;
    comps[y].head = x;
    comps[x].size += comps[y].size;
    comps[x].val = max(comps[x].val, comps[b].val);
    comps[x].numStart += comps[y].numStart;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);

    int n, m, t; cin >> m >> n >> t;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> startPoint(m, vector<bool>(n));
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            int in; cin >> in;
            startPoint[i][j] = in;
        }
    }

    vector<Comp> comps(n * m);
    FOR(n * m) {
        comps[i] = Comp(i);
    }

    vector<Edge> edges;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            // vertical paths
            if (i > 0) {
                int dif = abs(grid[i][j] - grid[i - 1][j]);
                edges.pb(Edge(dif, (i * n) + j, ((i - 1) * n) + j));
            }

            // horizontal paths
            if (j > 0) {
                int dif = abs(grid[i][j] - grid[i][j - 1]);
                edges.pb(Edge(dif, (i * n) + j, (i * n) + j - 1));
            }
        }
    }

    sort(ALL(edges), cmp);
    ll ans = 0;
    FOR(edges.size()) {
        int aHead = findHead(comps, edges[i].a);
        int bHead = findHead(comps, edges[i].b);

        if (aHead != bHead) {
            merge(comps, aHead, bHead);
        }
        else {
            continue;
        }

        aHead = findHead(comps, edges[i].a);
        comps[aHead].val = max(comps[aHead].val, edges[i].val);
        pair<int, int> aCoord = { edges[i].a / n, edges[i].a % n };
        pair<int, int> bCoord = { edges[i].b / n, edges[i].b % n };

        if (startPoint[aCoord.f][aCoord.s]) {
            startPoint[aCoord.f][aCoord.s] = false;
            if (comps[aHead].size < t) {
                comps[aHead].numStart++;
            }
            else {
                ans += comps[aHead].val;
            }
        }
        if (startPoint[bCoord.f][bCoord.s]) {
            startPoint[bCoord.f][bCoord.s] = false;
            if (comps[aHead].size < t) {
                comps[aHead].numStart++;
            }
            else {
                ans += comps[aHead].val;
            }
        }

        if (comps[aHead].size >= t) {
            ans += (ll)comps[aHead].val * comps[aHead].numStart;
            comps[aHead].numStart = 0;
        }
    }

    cout << ans;

    return 0;
}
