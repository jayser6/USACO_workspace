/*____________________________________________________________
// started : 07/16/22
// finished: 07/16/22
// problem : https://cses.fi/problemset/task/1648
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
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

void BITupdate(vector<ll>& BITree, int index, int val) {
    while (index < BITree.size()) {
        BITree[index] += val;
        index += index & -index;
    }
}

ll BITgetSum(vector<ll>& BITree, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<ll> BITree(n + 1, 0);
    vector<int> arr(n + 1);
    FORO(n + 1) {
        cin >> arr[i];
        BITupdate(BITree, i, arr[i]);
    }

    FOR(q) {
        int qType; cin >> qType;
        if (qType == 1) {
            int k, u; cin >> k >> u;

            BITupdate(BITree, k, (u - arr[k]));
            arr[k] = u;
        }
        else {
            int a, b; cin >> a >> b;

            cout << BITgetSum(BITree, b) - BITgetSum(BITree, a - 1) << endl;
        }
    }

    return 0;
}
