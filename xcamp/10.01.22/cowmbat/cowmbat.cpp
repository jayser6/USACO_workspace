/*____________________________________________________________
// started : 11/30/22
// finished:
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=971
____________________________________________________________*/

#include <bits/stdc++.h>

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
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    /* input */

    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    int a[m][m];
    int min_to[m][m];

    FOR(i, m) {
        FOR(j, m) {
            cin >> a[i][j];
            min_to[i][j] = a[i][j];
        }
    }

    /* Floyd-Warshall */

    FOR(i, m)
        FOR(j, m)
        FOR(k, m)
        min_to[i][j] = min(min_to[i][j], min_to[i][k] + min_to[k][j]);



    /* dp, where i, j is the min value for setting every cell until i to j */






    return 0;
}
