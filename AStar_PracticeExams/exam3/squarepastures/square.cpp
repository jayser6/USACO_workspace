#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l; cin >> n >> l;

    vector<vector<ll>> pSum(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> perimeterVal(n + 1, vector<ll>(n + 1, -1));
    vector<vector<ll>> minTil(n + 1, vector<ll>(n + 1, BIG_NUMBER)); // i, j is the fixed bottom right corner of the fence

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> pSum[i][j];
            pSum[i][j] += pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];

            if (i >= l && j >= l) {
                perimeterVal[i][j] = pSum[i][j] - pSum[i - l][j] - pSum[i][j - l] + pSum[i - l][j - l];
                if (l > 2) {
                    perimeterVal[i][j] -= pSum[i - 1][j - 1] - pSum[i - l + 1][j - 1] -
                        pSum[i - 1][j - l + 1] + pSum[i - l + 1][j - l + 1];
                }
                minTil[i][j] = min(perimeterVal[i][j], min(minTil[i - 1][j], minTil[i][j - 1]));
            }
        }
    }

    ll output = BIG_NUMBER;
    for (int i = n;i >= l;i--) {
        for (int j = n;j >= l;j--) {
            output = min(output, perimeterVal[i][j] + min(minTil[i - l][n], minTil[n][j - l]));
        }
    }

    cout << output;
}