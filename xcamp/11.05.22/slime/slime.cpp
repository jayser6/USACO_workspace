/*____________________________________________________________
// started : 01/05/23
// finished: 01/05/23
// problem : https://codeforces.com/problemset/problem/1734/D
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
int a[MAX_N];
int id[MAX_N];
ll req[MAX_N];

void solve() {
    int n, k; cin >> n >> k;
    k--;
    FOR(i, n) cin >> a[i];

    int group = 0;
    id[k] = -1;
    for (ll i = k + 1, sum = 0, c_req = BIG;i < n;i++) {
        sum += a[i];
        id[i] = group;
        c_req = min(c_req, sum);

        if (sum >= 0 || i == n - 1) {
            for (int j = i;id[j] == group;j--) req[j] = c_req;

            sum = 0;
            group++;
            c_req = BIG;
        }

    }

    for (ll i = k - 1, sum = 0, c_req = BIG; i >= 0;i--) {
        sum += a[i];
        id[i] = group;
        c_req = min(c_req, sum);

        if (sum >= 0 || i == 0) {
            for (int j = i;id[j] == group;j++) req[j] = c_req;

            sum = 0;
            group++;
            c_req = BIG;
        }
    }

    int lp = k - 1, rp = k + 1;
    ll h = a[k];

    while (lp >= 0 && rp < n) {
        bool stuck = true;

        if (h + req[lp] >= 0) {
            int curr_grp = id[lp];
            while (lp >= 0 && id[lp] == curr_grp) {
                stuck = false;
                h += a[lp];
                lp--;
            }
        }

        if (h + req[rp] >= 0) {
            int curr_grp = id[rp];
            while (rp < n && id[rp] == curr_grp) {
                stuck = false;
                h += a[rp];
                rp++;
            }
        }

        if (stuck) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
