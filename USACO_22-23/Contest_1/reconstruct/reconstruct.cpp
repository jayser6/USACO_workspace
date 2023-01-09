/*____________________________________________________________
// started : 01/08/23
// finished:
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1256
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

const int MAX_N = 300;
int r[MAX_N][MAX_N];
ll arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, n) FOR(j, n - i) cin >> r[i][j];

    ll smallest = BIG, biggest = SMALL;
    arr[0] = 0, arr[1] = r[0][1];
    for (int i = 2;i < n;i++) { // FIXME: the algorithm doesn't account for when a = b
        int a = arr[i - 2], b = arr[i - 1];
        int dif = r[i - 1][1];

        if (r[i - 2][1] == r[i - 2][2]) {
            arr[i] = (a < b) ? b - dif : b + dif;
        }
        else {
            if (r[i - 1][1] == r[i - 2][2]) {
                arr[i] = (a < b) ? b - dif : b + dif;
            }
            else {
                arr[i] = (a < b) ? b + dif : b - dif;
            }
        }

        smallest = min(smallest, arr[i]);
        biggest = max(biggest, arr[i]);
    }

    int c = 0;
    if (smallest < -1e9) c = -smallest - 1e9;
    else if (biggest > 1e9) c = 1e9 - biggest;

    FOR(i, n - 1) cout << arr[i] + c << " ";
    cout << arr[n - 1];

    return 0;
}
