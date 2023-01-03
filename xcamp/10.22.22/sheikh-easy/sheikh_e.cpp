/*____________________________________________________________
// started : 01/02/23
// finished: 01/02/23
// problem : https://codeforces.com/problemset/status?my=on
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
ll arr[MAX_N], psum[MAX_N + 1], pxor[MAX_N + 1];
int garbage1, garbage2;

pair<int, int> check(int length, ll val, int n) {
    int l = 0, r = length - 1;
    while (r < n) {
        ll curr = psum[r + 1] - psum[l] - (pxor[r + 1] ^ pxor[l]);
        if (curr == val) return { l, r };
        else l++, r++;
    }
    return { -1, -1 };
}

void solve() {
    int n, q; cin >> n >> q;
    FOR(i, n) cin >> arr[i];
    cin >> garbage1 >> garbage2;

    fill(psum, psum + n, 0);
    fill(pxor, pxor + n, 0);
    FOR(i, n) {
        psum[i + 1] = psum[i] + arr[i];
        pxor[i + 1] = pxor[i] ^ arr[i];
    }

    ll val = psum[n] - pxor[n];
    int low = 0, high = n;
    pair<int, int> ans = { -1, -1 };
    while (low <= high) {
        int mid = (low + high) / 2;
        pair<int, int> range = check(mid, val, n);
        if (range.f == -1 || mid == 0) low = mid + 1;
        else ans = range, high = mid - 1;
    }

    if (ans.f == -1) cout << "1 " << n << endl;
    else cout << ans.f + 1 << " " << ans.s + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
