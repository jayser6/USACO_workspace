/*____________________________________________________________
// started : 12/29/22
// finished: 12/31/22
// problem : https://codeforces.com/problemset/problem/1133/F2
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

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
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29


const int MAX_N = 2 * 1e5;
bool visited[MAX_N];
vector<vector<int>> edges(MAX_N);

struct dsu {
    vector<pair<int, int>> comp; // dsu[i] = {parent, size}
    int num_comps;

    dsu(int n) {
        num_comps = n;
        comp.resize(n);
        FOR(i, n) comp[i] = { i, 1 };
    }

    int find_head(int a) {
        if (comp[a].f == a) return a;
        return comp[a].f = find_head(comp[a].f);
    }

    void merge(int a, int b) {
        int a_head = find_head(a);
        int b_head = find_head(b);

        if (a_head == b_head) {
            return;
        }

        int gr, sm;
        if (comp[a_head].s > comp[b_head].s) {
            gr = a_head;
            sm = b_head;
        }
        else {
            gr = b_head;
            sm = a_head;
        }

        num_comps--;
        comp[gr].f = sm;
        comp[sm].s += comp[gr].s;
        edges[a].pb(b);
        edges[b].pb(a);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d; cin >> n >> m >> d;

    dsu s(n);
    set<int> from_1;
    FOR(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;

        if (a == 0) from_1.insert(b);
        else if (b == 0) from_1.insert(a);
        else s.merge(a, b);
    }

    int deg_0 = 0;
    for (auto it = from_1.begin(); it != from_1.end();) {
        int i = *it;
        it++;
        if (s.find_head(0) != s.find_head(i)) {
            from_1.erase(i);
            deg_0++;
        }
        s.merge(0, i);
    }

    if (deg_0 > d || s.num_comps != 1) {
        cout << "NO" << endl;
        return 0;
    }

    auto it = from_1.begin();
    while (deg_0 < d) {
        if (from_1.empty()) {
            cout << "NO" << endl;
            return 0;
        }

        int i = *it;
        it++;

        from_1.erase(i);
        edges[0].pb(i);
        deg_0++;
    }

    cout << "YES" << endl;

    stack<int> dfs;
    dfs.push(0);
    while (!dfs.empty()) {
        int u = dfs.top(); dfs.pop();

        visited[u] = true;
        for (int v : edges[u]) {
            if (!visited[v]) {
                dfs.push(v);
                visited[v] = true;
                cout << u + 1 << " " << v + 1 << endl;
            }
        }
    }

    return 0;
}
