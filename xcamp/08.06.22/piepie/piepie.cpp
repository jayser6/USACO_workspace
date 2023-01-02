/*____________________________________________________________
// started : 01/02/22
// finished: 01/02/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=765
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
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 1e5;
int taste[MAX_N * 4]; // index -> b_b, b_e, e_b, e_e, where (pie owner, pov)
int dist[MAX_N * 4];
queue<int> bfs;
set<pair<int, int>> e_rec; // pies that elsie receives. (taste, index) 
set<pair<int, int>> b_rec; // pies that bessie receives. (taste, index)

// 0 -> b_b, 1 -> b_e, 2 -> e_b, 3 -> e_e
int get_type(int n, int index) {
    if (index < n) {
        return 0;
    }
    else if (index < 2 * n) {
        return 1;
    }
    else if (index < 3 * n) {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);

    int n, d; cin >> n >> d;

    fill(dist, dist + 4 * n, BIG);

    FOR(i, n) {
        cin >> taste[i] >> taste[i + n];
        if (taste[i + n] == 0) {
            bfs.push(i + n);
            dist[i + n] = 0;
        }
        else e_rec.insert({ taste[i + n], i + n });
    }
    FOR(i, n) {
        cin >> taste[i + 2 * n] >> taste[i + 3 * n];
        if (taste[i + 2 * n] == 0) {
            bfs.push(i + 2 * n);
            dist[i + 2 * n] = 0;
        }
        else b_rec.insert({ taste[i + 2 * n], i + 2 * n });
    }

    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        int what = get_type(n, u);

        if (what == 0) {
            for (auto it = b_rec.lower({ taste[u] - d, 0 }); it != b_rec.upper({ taste[u], BIG });) {
                int t = it->f, v = it->s;
                it++;
                b_rec.erase({ t, v });
                if (dist[u] < dist[v]) {
                    dist[v] = dist[u];
                    bfs.push(v);
                }
            }
        }
        else if (what == 1) {
            int v = u - n;
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                bfs.push(v);
            }
        }
        else if (what == 2) {
            int v = u + n;
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                bfs.push(v);
            }
        }
        else if (what == 3) {
            for (auto it = e_rec.lower({ taste[u] - d, 0 }); it != e_rec.upper({ taste[u], BIG });) {
                int t = it->f, v = it->s;
                it++;
                e_rec.erase({ t, v });
                if (dist[u] < dist[v]) {
                    dist[v] = dist[u];
                    bfs.push(v);
                }
            }
        }
    }

    FOR(i, n) cout << ((dist[i] == BIG) ? -1 : dist[i]) << endl;

    return 0;
}
