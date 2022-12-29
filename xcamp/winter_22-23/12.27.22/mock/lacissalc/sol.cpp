// this file and lacissalc.png were written by David Zhang

#include<bits/stdc++.h>
using namespace std;
long long fact[65], nfactorial = 1, p = 998244353; //fact[i] stores 1 divided by i!, taken modulo p
void gen(int n) {
    fact[0] = 1;
    for (int i = 1;i < 65;i++) {
        int cnt = 0;
        while ((cnt * p - fact[i - 1]) % i) {
            cnt++;
        }
        fact[i] = ((fact[i - 1] - cnt * p) / i + p) % p;
    }
    for (int i = 2;i <= n;i++) {
        nfactorial = (i * nfactorial) % p;
    }
}
int main() {
    int n, k, t;
    cin >> n >> k >> t;
    gen(n);
    int dp[k][n + 1][t + 1]; //inputs: i (as in a_i), sum of a_i so far, and number of subarrays so far // outputs: sum of 1 over factorials
    memset(dp, 0, sizeof(dp));
    //take care of a_0 separately
    for (int i = 0;i <= n;i++) {
        if ((i + 1) * i / 2 <= t) dp[0][i][(i + 1) * i / 2] = fact[i];
    }
    for (int i = 1;i < k;i++) {//i as in a_i
        for (int j = 0;j <= n;j++) {//value of a_i
            for (int l1 = 0;l1 + j <= n;l1++) {//iterate through the previous stage's dp table
                for (int l2 = 0;l2 + j * (j - 1) / 2 <= t;l2++) {
                    dp[i][l1 + j][l2 + j * (j - 1) / 2] = (dp[i][l1 + j][l2 + j * (j - 1) / 2] + dp[i - 1][l1][l2] * fact[j]) % p;
                }
            }
        }
    }
    cout << (nfactorial * dp[k - 1][n][t]) % p;
}