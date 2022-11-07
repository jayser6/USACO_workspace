/*____________________________________________________________
// started : 07/03/22
// finished: 07/03/22
// problem : https://cses.fi/problemset/task/1735
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

struct stNode {
    ll val, lazyAdd;
    int lazySet;
    stNode() {
        lazyAdd = 0; // if there is no lazy value to be added, 0
        lazySet = -1; // if there is no lazy value to be set, -1
    }
};

int mid(int a, int b) {
    return (a + b) / 2;
}

ll stMake(vector<stNode>& st, vector<int>& vec, int stI, int stS, int stE) {
    if (stS == stE) {
        st[stI].val = vec[stS];
        return st[stI].val;
    }

    st[stI].val = stMake(st, vec, (2 * stI) + 1, stS, mid(stS, stE)) + stMake(st, vec, (2 * stI) + 2, mid(stS, stE) + 1, stE);
    return st[stI].val;
}

void stGetLV(vector<stNode>& st, int stI, int stS, int stE, int set, ll add) {
    if (set > -1) {
        st[stI].lazyAdd = 0;
        st[stI].lazySet = set;
        st[stI].val = (stE - stS + 1) * (ll)set;
    }
    if (add > 0) { // if statement not technically needed but there for style
        st[stI].lazyAdd += add;
        st[stI].val += (stE - stS + 1) * add;
    }
}

ll stFindSum(vector<stNode>& st, int stI, int stS, int stE, int qS, int qE) {
    if ((qS > stE) || (qE < stS)) {
        // not contained at all
        return 0;
    }
    else if ((qS <= stS) && (qE >= stE)) {
        // fully contained
        return st[stI].val;
    }
    else {
        // partially contained
        stGetLV(st, (stI * 2) + 1, stS, mid(stS, stE), st[stI].lazySet, st[stI].lazyAdd);
        stGetLV(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, st[stI].lazySet, st[stI].lazyAdd);
        st[stI].lazyAdd = 0;
        st[stI].lazySet = -1;
        return stFindSum(st, (stI * 2) + 1, stS, mid(stS, stE), qS, qE) + stFindSum(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, qS, qE);
    }
}

ll stUpdate(vector<stNode>& st, int stI, int stS, int stE, int qS, int qE, int uType, int uVal) {
    if ((qS > stE) || (qE < stS)) {
        // not contained at all
        return st[stI].val;
    }
    else if ((qS <= stS) && (qE >= stE)) {
        // fully contained
        if (uType == 1) {
            stGetLV(st, stI, stS, stE, -1, uVal);
            return st[stI].val;
        }
        else {
            stGetLV(st, stI, stS, stE, uVal, 0);
            return st[stI].val;
        }
    }
    else {
        // partially contained
        stGetLV(st, (stI * 2) + 1, stS, mid(stS, stE), st[stI].lazySet, st[stI].lazyAdd);
        stGetLV(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, st[stI].lazySet, st[stI].lazyAdd);
        st[stI].lazyAdd = 0;
        st[stI].lazySet = -1;
        st[stI].val = stUpdate(st, (stI * 2) + 1, stS, mid(stS, stE), qS, qE, uType, uVal) + stUpdate(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, qS, qE, uType, uVal);
        return st[stI].val;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> vec(n);
    FOR(n) {
        cin >> vec[i];
    }

    int stDepth = ceil(log2(n));
    int stSize = pow(2, stDepth + 1) - 1;
    vector<stNode> st(stSize);
    stMake(st, vec, 0, 0, n - 1);

    FOR(q) {
        int qType, a, b, x; cin >> qType >> a >> b;
        a--; b--;

        if ((qType == 1) || (qType == 2)) {
            cin >> x;
            stUpdate(st, 0, 0, n - 1, a, b, qType, x);
        }
        else {
            cout << stFindSum(st, 0, 0, n - 1, a, b) << endl;
        }
    }

    return 0;
}
