/*____________________________________________________________
// started : 01/07/23
// finished: 01/07/23
// problem : https://contest.xinyoudui.com/contest/19/problem/106
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
int arr[MAX_N];
int st[MAX_N * 3];

int mid(int a, int b) { return (a + b) / 2; }

int build(int st_i, int st_s, int st_e) {
    if (st_s == st_e) return st[st_i] = arr[st_s];
    int m = mid(st_s, st_e);
    return st[st_i] = build(st_i * 2 + 1, st_s, m) | build(st_i * 2 + 2, m + 1, st_e);
}

int query(int st_i, int st_s, int st_e, int q_s, int q_e) {
    if (q_s > st_e || q_e < st_s) return 0;
    else if (q_s <= st_s && q_e >= st_e) return st[st_i];
    else {
        int m = mid(st_s, st_e);
        return query(st_i * 2 + 1, st_s, m, q_s, q_e) | query(st_i * 2 + 2, m + 1, st_e, q_s, q_e);
    }
}

bool check(int n, int l) {
    int lp = 0, rp = l - 1;
    while (rp < n) {
        int cor = query(0, 0, n - 1, lp, rp);
        int lor = (lp > 0) ? query(0, 0, n - 1, 0, lp - 1) : 0;
        int ror = (rp < n - 1) ? query(0, 0, n - 1, rp + 1, n - 1) : 0;

        if (cor == (lor | ror)) return true;
        lp++, rp++;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    FOR(i, n) cin >> arr[i];

    fill(st, st + n * 3, 0);
    build(0, 0, n - 1);

    int low = 0, high = n, ans = -1;
    while (low <= high) {
        int m = mid(low, high);

        if (check(n, m)) ans = m, low = m + 1;
        else high = m - 1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
