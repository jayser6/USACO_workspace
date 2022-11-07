/*____________________________________________________________
// started : 06/22/22
// finished: 06/22/22
// problem : https://cses.fi/problemset/task/1648
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define BIG_NUMBER (ll)1e18

using namespace std;

void update(vector<ll>& BITree, int index, int val) {
    while (index < BITree.size()) {
        BITree[index] += val;
        index += index & (-index);
    }
}

ll getSum(vector<ll>& BITree, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<ll> BITree(n + 1); // 1-index binary index trees for ease of use
    vector<int> input(n + 1);
    FORO(n + 1) {
        cin >> input[i];
        update(BITree, i, input[i]);
    }
    BITree[0] = 0;

    FOR(q) {
        int qType; cin >> qType;
        if (qType == 1) {
            int k, u; cin >> k >> u;
            int diff = u - input[k];
            input[k] = u;
            update(BITree, k, diff);
        }
        else {
            int a, b; cin >> a >> b;
            cout << (getSum(BITree, b) - getSum(BITree, a - 1)) << endl;
        }
    }

    return 0;
}
