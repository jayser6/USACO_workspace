/*____________________________________________________________
// started : 01/04/23
// finished: 01/04/23
// problem : https://codeforces.com/problemset/problem/1740/C
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

void solve() {
    int n; cin >> n;

    int arr[MAX_N]; FOR(i, n) cin >> arr[i];
    sort(arr, arr + n);

    uint ans = 0;
    FOR(i, n - 2) {
        uint sum = (uint)abs(arr[i] - arr[i + 1]) + abs(arr[i] - arr[n - 1]);
        ans = max(ans, sum);
    }

    for (int i = n - 1;i >= 2;i--) {
        uint sum = (uint)abs(arr[i] - arr[i - 1]) + abs(arr[i] - arr[0]);
        ans = max(ans, sum);
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
