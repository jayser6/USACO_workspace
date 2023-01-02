/*____________________________________________________________
// started : 01/02/22
// finished: 10/02/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=992
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
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

const int MAX_N = 1e5, MAX_W = 1e9;
vector<vector<pair<int, int>>> adj(MAX_N, vector<pair<int, int>>());
int color[MAX_N];
pair<bool, int> must_visit[MAX_N];

void dfs(int u, int c, int w) {
    color[u] = c;
    for (auto v : adj[u]) {
        if (color[v.f] == -1 && v.s >= w)
            dfs(v.f, c, w);
    }
}

bool check(int n, int w) {
    memset(color, -1, sizeof(color));

    FOR(i, n) if (color[i] == -1) dfs(i, i, w);

    FOR(i, n) if (must_visit[i].f && color[i] != color[must_visit[i].s]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;
    bool sorted = true;
    FOR(i, n) {
        int p; cin >> p;
        p--;
        if (p != i) {
            sorted = false;
            must_visit[i] = { true, p };
        }
    }

    if (sorted) {
        cout << -1;
        return 0;
    }

    FOR(i, m) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        adj[a].pb({ b, w });
        adj[b].pb({ a, w });
    }

    int low = 0, high = MAX_W + 5, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(n, mid)) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
