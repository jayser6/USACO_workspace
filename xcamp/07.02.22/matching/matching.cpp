/*____________________________________________________________
// started : 07/06/22
// finished: 07/06/22
// problem : https://cses.fi/problemset/task/1753
// note    : This problem implements the KMP algorithm
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

using namespace std;

void calcLPS(vector<int>& lps, string& pattern) {
    int len = 0;
    int i = 1;
    while (i < lps.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len > 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n, m; cin >> n >> m;

    vector<int> lps(m.length());
    calcLPS(lps, m);

    int ans = 0;
    int ptrN = 0, ptrM = 0;
    while (ptrN < n.length()) {
        if (n[ptrN] == m[ptrM]) {
            ptrN++;
            ptrM++;
            if (ptrM == m.length()) {
                // a match has been found
                ans++;
                ptrM = lps[m.length() - 1];
            }
        }
        else {
            if (ptrM == 0) {
                // no work can be saved, move on
                ptrN++;
            }
            else {
                // try to save work on the next iteration
                ptrM = lps[ptrM - 1];
            }
        }
    }

    cout << ans;

    return 0;
}
