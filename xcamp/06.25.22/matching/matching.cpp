/*____________________________________________________________
// started : 06/28/22
// finished: 06/28/22
// problem : https://cses.fi/problemset/task/1753
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

const int RH_B = 31; // this should be a much bigger prime because ascii values for both upper and lower case characters are greater than 31 but it worked for the grader so who knows. 
const int RH_M = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n, m; cin >> n >> m;
    int nSize = n.size(), mSize = m.size();

    // compute the match hash
    int matchHash = 0;
    int maxPower = 1;
    FOR(mSize) {
        maxPower *= RH_B;
        maxPower %= RH_M;

        matchHash = (matchHash * RH_B) + m.at(i); // just use ascii values
        matchHash %= RH_M;
    }

    // rolling hash
    int ans = 0;
    int currHash = 0;
    FOR(nSize) {
        currHash = (currHash * RH_B) + n.at(i);
        currHash %= RH_M;
        if (i >= mSize) {
            currHash -= maxPower * n.at(i - mSize);
            currHash %= RH_M;
            if (currHash < 0) {
                currHash += RH_M;
            }
        }

        if (currHash == matchHash && i >= mSize - 1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}