/*____________________________________________________________
// started : 01/08/23
// finished: 01/08/23
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1254
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
#define tup tuple
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
#define SMALL (int)INT_MIN
#define SMALLER (ll)LLONG_MIN
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 2e5;

vector<vector<int>> adj1(MAX_N);
vector<vector<pair<int, ll>>> adj2(MAX_N);
int deg1[MAX_N];
int deg2[MAX_N];
ll barn[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll sum = 0, avg;
    FOR(i, n) {
        cin >> barn[i];
        sum += barn[i];
    }

    avg = sum / n;

    FOR(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;

        adj1[a].pb(b);
        adj1[b].pb(a);
        deg1[a]++, deg1[b]++;
    }

    queue<int> leaf;
    int ans = 0;
    FOR(i, n) if (deg1[i] == 1) leaf.push(i);
    while (!leaf.empty()) {
        int u = leaf.front();
        deg1[u] = -1;
        leaf.pop();

        for (int v : adj1[u]) {
            if (deg1[v] == -1) continue;

            deg1[v]--;
            if (deg1[v] == 1) leaf.push(v);

            if (barn[u] > avg) {
                adj2[u].pb({ v, barn[u] - avg });
                barn[v] += barn[u] - avg;
                deg2[v]++;
                ans++;
            }
            else if (barn[u] < avg) {
                adj2[v].pb({ u, avg - barn[u] });
                barn[v] -= avg - barn[u];
                deg2[u]++;
                ans++;
            }
        }
    }

    cout << ans << endl;
    FOR(i, n) if (deg2[i] == 0) leaf.push(i);
    while (!leaf.empty()) {
        int u = leaf.front();
        leaf.pop();

        for (auto [v, cost] : adj2[u]) {
            if (deg2[v] == 0) continue;

            cout << u + 1 << " " << v + 1 << " " << cost << endl;
            deg2[v]--;
            if (deg2[v] == 0) leaf.push(v);
        }
    }

    return 0;
}
