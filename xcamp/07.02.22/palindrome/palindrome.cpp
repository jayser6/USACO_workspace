/*____________________________________________________________
// started : 07/07/22
// finished: 07/07/22
// problem : https://cses.fi/problemset/task/2420
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
#define BIG_PRIME (int)1e9 + 7 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

const int MOD = 1e7;
const int BASE = ALPHA_PRIME;

void BITupdate(vector<int>& BITree, int index, int val) {
    while (index < BITree.size()) {
        BITree[index] += val;
        BITree[index] %= MOD;
        index += index & -index;
    }
}

int BITgetSum(vector<int>& BITree, int index) {
    int sum = 0;
    while (index > 0) {
        sum += BITree[index];
        sum %= MOD;
        index -= index & -index;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<int> powers(n + 1);
    powers[0] = 1;
    FORO(n + 1) {
        powers[i] = powers[i - 1] * BASE;
        powers[i] %= MOD;
    }

    vector<char> c(n + 1);
    vector<int> hashBIT(n + 1);
    vector<int> r_hashBIT(n + 1); // the power ordering on this BIT is reversed
    FORO(n + 1) {
        c[i] = s[i - 1];

        int char_val = c[i] - 'a' + 1;
        BITupdate(hashBIT, i, powers[i] * char_val);
        BITupdate(r_hashBIT, i, powers[n - i + 1] * char_val);
    }

    FOR(m) {
        int qType; cin >> qType;
        if (qType == 1) {
            int index; char newChar; cin >> index >> newChar;

            int diff = newChar - c[index];
            BITupdate(hashBIT, index, powers[index] * diff);
            BITupdate(r_hashBIT, index, powers[n - index + 1] * diff);
        }
        else {
            int a, b; cin >> a >> b;
            if (a == b) {
                cout << "YES" << endl;
                continue;
            }

            int mid = (a + b) / 2;
            int range = b - a + 1;
            int firstHalf = BITgetSum(hashBIT, mid - (range % 2)) - BITgetSum(hashBIT, a - 1);
            int secondHalf = BITgetSum(r_hashBIT, b) - BITgetSum(r_hashBIT, mid);

            while (firstHalf < 0) {
                firstHalf += MOD;
            }
            while (secondHalf < 0) {
                secondHalf += MOD;
            }

            firstHalf = ((ll)firstHalf * powers[n - (mid - (range % 2))]) % MOD;
            secondHalf = ((ll)secondHalf * powers[mid]) % MOD;

            if (firstHalf == secondHalf)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
