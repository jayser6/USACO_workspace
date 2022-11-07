/*____________________________________________________________
// started : 06/29/22
// finished: 06/29/22
// problem : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b5503a
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
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
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

void solve(int testNum) {
    int n, m; cin >> n >> m;
    int sum = 0;
    FOR(n) {
        int input; cin >> input;
        sum += input;
    }

    cout << "Case #" << testNum << ": " << (sum % m) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    FORO(t + 1) {
        solve(i);
    }

    return 0;
}
