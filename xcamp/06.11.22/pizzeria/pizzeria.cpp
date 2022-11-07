/*____________________________________________________________
// started : 06/19/22
// finished: 06/20/22
// problem : https://cses.fi/problemset/task/2206
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

int stMake(vector<int>& st, vector<int>& arr, int stI, int stS, int stE) {
    if (stS == stE) {
        st[stI] = arr[stS];
        return st[stI];
    }

    st[stI] = min(stMake(st, arr, (stI * 2) + 1, stS, mid(stS, stE)), stMake(st, arr, (stI * 2) + 2, mid(stS, stE) + 1, stE));
    return st[stI];
}

// u -> update
int stUpdate(vector<int>& st, int stI, int stS, int stE, int uIndex, int uVal) {
    if ((uIndex < stS) || (uIndex > stE)) {
        return st[stI];
    }
    else if (stS == stE) {
        st[stI] = uVal;
        return st[stI];
    }
    else {
        st[stI] = min(stUpdate(st, (stI * 2) + 1, stS, mid(stS, stE), uIndex, uVal), stUpdate(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, uIndex, uVal));
        return st[stI];
    }
}

int stMin(vector<int>& st, int stI, int stS, int stE, int qS, int qE) {
    if ((qS > stE) || (qE < stS)) {
        return 2e9; // the value of the elements are a little greater than 1e9
    }
    else if ((stS >= qS) && (stE <= qE)) {
        return st[stI];
    }
    else {
        return min(stMin(st, (stI * 2) + 1, stS, mid(stS, stE), qS, qE), stMin(st, (stI * 2) + 2, mid(stS, stE) + 1, stE, qS, qE));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> priceLeft(n), priceRight(n);
    FOR(n) {
        int input; cin >> input;
        priceLeft[i] = input - i;
        priceRight[i] = input + i;
    }

    // make the segment tree
    int stDepth = ceil(log2(n));
    int stSize = pow(2, stDepth + 1) - 1;
    vector<int> stL(stSize);
    vector<int> stR(stSize);
    stMake(stL, priceLeft, 0, 0, n - 1);
    stMake(stR, priceRight, 0, 0, n - 1);

    // take queries
    for (int q_i = 0;q_i < q;q_i++) {
        int qType, k; cin >> qType >> k;
        k--;
        if (qType == 1) {
            int x; cin >> x;
            stUpdate(stL, 0, 0, n - 1, k, x - k);
            stUpdate(stR, 0, 0, n - 1, k, x + k);
        }
        else {
            int leftMin = stMin(stL, 0, 0, n - 1, 0, k) + k;
            int rightMin = stMin(stR, 0, 0, n - 1, k, n - 1) - k;
            cout << min(leftMin, rightMin) << endl;
        }
    }
}
