/*____________________________________________________________
// started : 07/16/22
// finished: 07/18/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=529
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop() while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define DEBUG for (int kdrwer = 0; kdrwer < 0;)
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
// #define s second
#define endl "\n"
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

int BASE = ALPHA_PRIME;
ll MOD = BIG_PRIME;

// tries to find the given string hash in string s from index 'start'(inclusive)
// to 'end'(exclusive), . If the string is found, deletes the found substring
// and returns the index of the start of the substring in the string. Otherwise,
// returns -1
int match(string& s, int start, ll tHash, int m, ll maxPower) {
    ll currHash = 0;

    for (int i = start;i < s.length();i++) {
        currHash *= BASE;
        currHash %= MOD;
        currHash += s[i] - 'a' + 1;
        currHash %= MOD;
        if (i >= m + start) {
            currHash -= maxPower * (s[i - m] - 'a' + 1);
            currHash %= MOD;
            if (currHash < 0) {
                currHash += MOD;
            }
        }

        if (tHash == currHash) {
            int ssStart = i - m + 1;
            int ssEnd = i + 1;

            s.erase(s.begin() + ssStart, s.begin() + ssEnd);
            return ssStart;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    ll tHash = 0;
    ll maxPower = 1;
    FOR(m) {
        tHash *= BASE;
        tHash %= MOD;
        tHash += t[i] - 'a' + 1;
        tHash %= MOD;

        maxPower *= BASE;
        maxPower %= MOD;
    }

    int start = 0;
    loop() {
        int result = match(s, start, tHash, m, maxPower);
        if (result == -1) {
            break;
        }
        start = max(0, result - m - 1);
    }

    cout << s;

    return 0;
}
