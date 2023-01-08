/*____________________________________________________________
// started : 01/07/23
// finished: 01/07/23
// problem : https://codeforces.com/contest/1773/problem/E
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

const int MAX_N = 1e4, MAX_K = 1e4;
int mat[MAX_N][MAX_K + 1];
set<int> lin;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, n) {
        int k; cin >> k;
        mat[i][0] = k;
        FORO(j, k + 1) {
            cin >> mat[i][j];
            lin.insert(mat[i][j]);
        }
    }

    int t_cnt = n;
    FOR(i, n) {
        auto it = lin.find(mat[i][1]);
        FORO(j, mat[i][0] + 1) {
            if (it == lin.end() || *it != mat[i][j]) {
                t_cnt++;
                it = lin.find(mat[i][j]);
            }
            it++;
        }
    }

    cout << t_cnt - n << " " << t_cnt - 1;

    return 0;
}
