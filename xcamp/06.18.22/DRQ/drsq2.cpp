/*____________________________________________________________
// started :
// finished:
// problem :
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
#define endl "\n"
#define BIG_NUMBER (ll)1e18

using namespace std;

int mid(int a, int b) { return (a + b) / 2; }

ll stMake(vector<ll>& st, vector<int>& arr, int stI, int stS, int stE) {
    if (stS == stE) {
        st[stI] = arr[stS];
        return st[stI];
    }

    st[stI] = stMake(st, arr, (stI * 2) + 1, stS, mid(stS, stE)) + stMake(st, arr, (stI * 2) + 2, mid(stS, stE) + 1, stE);
    return st[stI];
}

ll stFindSum(vector<ll>& st, int stI, int stS, int stE, int qS, int qE) {
    if ((stE < qS) || (stS > qE)) {
        return 0;
    }
    else if ((stS >= qS) && (stE <= qE)) {
        return st[stI];
    }
    else {
        return stFindSum(st, (stI * 2) + 1, stS, mid(stS, stE), qS, qE) + stFindSum(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, qS, qE);
    }
}

ll stUpdate(vector<ll>& st, int stI, int stS, int stE, int updateI, int updateVal) {
    if ((updateI < stS) || (updateI > stE)) {
        return st[stI];
    }
    else if (stS == stE) {
        st[stI] = updateVal;
        return st[stI];
    }
    else {
        st[stI] = stUpdate(st, (stI * 2) + 1, stS, mid(stS, stE), updateI, updateVal) + stUpdate(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, updateI, updateVal);
        return st[stI];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> input(n);
    for (int& in : input) {
        cin >> in;
    }

    int stDepth = ceil(log2(n));
    int stSize = pow(2, stDepth + 1) - 1;
    vector<ll> st(stSize);
    stMake(st, input, 0, 0, n - 1);

    FOR(q) {
        int qType; cin >> qType;
        if (qType == 1) {
            int k, u; cin >> k >> u;
            k--;
            stUpdate(st, 0, 0, n - 1, k, u);
        }
        else {
            int a, b; cin >> a >> b;
            a--; b--;
            cout << stFindSum(st, 0, 0, n - 1, a, b) << endl;
        }
    }

    return 0;
}
