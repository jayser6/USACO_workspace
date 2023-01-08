/*____________________________________________________________
// started : 01;08/23
// finished: 01/08/23
// problem : https://codeforces.com/contest/1783/problem/B
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

int a[50][50];

void print(int& cnt, int& small, int& big, int i, int j) {
    if (cnt % 2 == 0) {
        a[i][j] = small;
        small++;
    }
    else {
        a[i][j] = big;
        big--;
    }
    cnt++;
}

void solve() {
    int n; cin >> n;

    int small = 1, big = n * n;
    int cnt = 0;

    FOR(i, n) {
        if (i % 2 == 0) {
            FOR(j, n) {
                print(cnt, small, big, i, j);
            }
        }
        else {
            ROF(j, n) {
                print(cnt, small, big, i, j);
            }
        }
    }

    FOR(i, n) {
        FOR(j, n) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;cin >> t;
    while (t--) solve();

    return 0;
}
