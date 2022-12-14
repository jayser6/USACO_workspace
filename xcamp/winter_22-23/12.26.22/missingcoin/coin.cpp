/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://cses.fi/problemset/task/2183
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
#define BIG_NUMBER 1e18LL
#define BIG_PRIME 999998727899999LL // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int coins[n];
    FOR(i, n)
        cin >> coins[i];

    sort(coins, coins + n);

    ll run_sum = 0;
    FOR(i, n) {
        if (coins[i] > run_sum + 1) {
            cout << run_sum + 1 << endl;
            return 0;
        }
        run_sum += coins[i];
    }

    cout << run_sum + 1;

    return 0;
}
