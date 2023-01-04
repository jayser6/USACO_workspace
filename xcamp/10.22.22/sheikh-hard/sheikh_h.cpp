/*____________________________________________________________
// started : 01/03/23
// finished:
// problem : https://codeforces.com/problemset/problem/1732/C2
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

const int MAX_N = 2 * 1e5;
int arr[MAX_N];
ll psum[MAX_N + 1], pxor[MAX_N + 1];
int next_nonz[MAX_N];
int prev_nonz[MAX_N];

bool in_bound(int n, int l, int r) {
    return (l < n) && (l >= 0) && (r < n) && (r >= 0) && (l <= r);
}

void solve() {
    int n, q; cin >> n >> q;

    int curr_nonz = 0;
    fill(next_nonz, next_nonz + n, -1);
    fill(prev_nonz, prev_nonz + n, -1);

    FOR(i, n) {
        cin >> arr[i];

        if (arr[i] != 0) curr_nonz = i;
        prev_nonz[i] = curr_nonz;

        psum[i + 1] = psum[i] + arr[i];
        pxor[i + 1] = pxor[i] ^ arr[i];
    }

    curr_nonz = n - 1;
    ROF(i, n) {
        if (arr[i] != 0) curr_nonz = i;
        next_nonz[i] = curr_nonz;
    }

    FOR(q_i, q) {
        int l, r; cin >> l >> r;
        l--, r--;

        ll val = psum[r + 1] - psum[l] - (pxor[r + 1] ^ pxor[l]);
        pair<int, int> ans = { l, r };

        int new_l = min(r, next_nonz[l]);
        int new_r = max(new_l, prev_nonz[r]);
        FOR(i, 31) {
            if (new_l >= n) break;
            new_l = min(r, next_nonz[new_l]);
            new_r = max(new_l, prev_nonz[r]);
            FOR(j, 31) {
                if (new_r < 0) break;
                new_r = max(new_l, prev_nonz[new_r]);

                if (in_bound(n, new_l, new_r)) {
                    ll new_val = psum[new_r + 1] - psum[new_l] - (pxor[new_r + 1] ^ pxor[new_l]);
                    if (new_val == val && new_r - new_l < ans.s - ans.f) {
                        ans = { new_l, new_r };
                    }
                }
                new_r--;
            }
            new_l++;
        }

        cout << ans.f + 1 << " " << ans.s + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
