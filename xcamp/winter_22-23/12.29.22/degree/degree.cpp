/*____________________________________________________________
// started :
// finished:
// problem :
____________________________________________________________*/

#include <bits/stdc++.h>

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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

const int MAX_N = 2 * 1e5;
pair<int, int> dsu[MAX_N];
vector<vector<int>> selected(MAX_N, vector<int>()); // selected edges 
bool visited[MAX_N];
int to_print;

int find_head(int a) {
    if (dsu[a].f == a)
        return a;

    return dsu[a].f = find_head(dsu[a].f);
}

void merge(int a, int b) {
    int a_head = find_head(a);
    int b_head = find_head(b);

    if (a_head == b_head)
        return;

    int gr, sm;
    if (dsu[a_head].s > dsu[b_head].s) {
        gr = a_head;
        sm = b_head;
    }
    else {
        gr = b_head;
        sm = a_head;
    }

    dsu[sm].f = gr;
    dsu[gr].s += dsu[sm].s;

    selected[a].pb(b);
    selected[b].pb(a);
}

void dfs(int curr) {
    visited[curr] = true;


    for (int u : selected[curr]) {
        if (!visited[u] && to_print > 0) {
            cout << curr + 1 << " " << u + 1 << endl;
            to_print--;
        }
    }

    for (int u : selected[curr]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d; cin >> n >> m >> d;

    vector<pair<int, int>> edges;
    set<int> e_from_1; // edges from 1 to another node
    FOR(i, m) {
        int u, v; cin >> u >> v; u--; v--;

        if (u == 0)
            e_from_1.insert(v);
        else if (v == 1)
            e_from_1.insert(u);
        else
            edges.pb({ u, v });
    }

    set<int> not_seen;

    FORO(i, n) {
        not_seen.insert(i);
        dsu[i] = { i, 1 };
    }

    // form a tree from the given edges if possible. This tree excludes node 0
    for (const auto& curr : edges) {
        merge(curr.f, curr.s);

        if (not_seen.find(curr.f) != not_seen.end())
            not_seen.erase(curr.f);
        if (not_seen.find(curr.s) != not_seen.end())
            not_seen.erase(curr.s);
    }

    // node 0 MUST connect to all the nodes that are in not_seen
    int curr_deg = 0;
    for (auto it = not_seen.begin();it != not_seen.end();it++) {
        int to = *it;

        if (e_from_1.find(to) == e_from_1.end()) {
            cout << "NO" << endl;
            return 0;
        }
        curr_deg++;
        e_from_1.erase(to);
        selected[0].pb(to);
        selected[to].pb(0);
    }

    // check if the case fails. If not, select more edges connecting node 0 if
    // necessary 
    if (curr_deg > d - 1) {
        cout << "NO" << endl;
        return 0;
    }

    while (curr_deg < d) {
        if (e_from_1.empty()) {
            cout << "NO" << endl;
            return 0;
        }

        int to = *e_from_1.begin();
        e_from_1.erase(to);
        selected[0].pb(to);
        selected[to].pb(0);
        curr_deg++;
    }

    // find any tree from the selected edges and print it     

    cout << "YES" << endl;
    to_print = n - 1;
    dfs(0);

    return 0;
}
