/*____________________________________________________________
// started : 06/29/22
// finished: 06/29/22
// problem : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b54d3b
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

void solve(int test) {
    int n, q; cin >> n >> q;

    vector<vector<int>> pSum(n + 1, vector<int>(26, 0));
    FORO(n + 1) {
        char input; cin >> input;
        input -= 'A';

        for (int j = 0;j < 26;j++) {
            pSum[i][j] = pSum[i - 1][j];
        }
        pSum[i][input]++;
    }

    int ans = 0;
    FOR(q) {
        int l, r; cin >> l >> r;
        int oddCnt = 0;
        for (int j = 0;j < 26;j++) {
            if ((pSum[r][j] - pSum[l - 1][j]) % 2 == 1) {
                oddCnt++;
            }
        }
        if (oddCnt <= 1) {
            ans++;
        }
    }

    cout << "Case #" << test << ": " << ans << endl;
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
