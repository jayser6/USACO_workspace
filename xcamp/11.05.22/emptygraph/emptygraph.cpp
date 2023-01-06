/*____________________________________________________________
// started : 01/05/23
// finished:
// problem : https://codeforces.com/problemset/problem/1712/D
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

const int MAX_N = 1e5, MAX_A = 1e9;
int n, k;
int arr[MAX_N];

bool check(int d) {
    int out = 0;
    int prev = -1, curr = -1;
    int change_end = 2;
    FOR(i, n) {
        if (arr[i] * 2 < d) {
            curr = MAX_A;
            out++;
        }
        else curr = arr[i];

        change_end = min((int)(prev < d) + (curr < d), change_end);
        prev = curr;
    }

    return (out + change_end) <= k;
}

void solve() {
    cin >> n >> k;
    FOR(i, n) cin >> arr[i];

    int low = 0, high = MAX_A, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) ans = mid, low = mid + 1;
        else high = mid - 1;
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
