/*____________________________________________________________
// started : 07/09/22
// finished: 07/10/22
// problem : https://cses.fi/problemset/task/2103
// note    : This gets TLE on the first test case, not sure how to fix
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < (int)n;i++)
#define FORO(n) for (int i = 1;i < (int)n;i++)
#define ROF(n) for (int i = (int)n - 1;i >= 0;i--)
#define ROFO(n) for (int i = (int)n - 1;i >= 1;i--)
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
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

const ll MOD = BIG_PRIME;
const int BASE = ALPHA_PRIME;

ll findHash(string& s) {
    ll hash = 0;

    FOR(s.length()) {
        int val = s[i] - 'a' + 1;
        hash *= BASE;
        hash += val;
        hash %= MOD;
    }

    return hash;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("patterns.in", "r", stdin);

    string s; cin >> s;
    int k; cin >> k;
    int n = s.length();

    // map<ll, int> cnt; // string hash, answer
    map<int, map<ll, int>> cnt;
    multimap<ll, pair<int, bool>> hashToIndex; // f -> string hash, s.f -> input order, s.s -> whether or not the answer was computed already
    hashset<int> sLengths; // the lengths of all the strings
    vector<ll> powers(n + 1);
    powers[0] = 1;
    FOR(k) {
        powers[i + 1] = powers[i] * BASE;
        powers[i + 1] %= MOD;

        // do the string thing
        string in; cin >> in;

        sLengths.insert(in.length());
        ll hash = findHash(in);
        // cnt.insert({ hash, 0 });
        if (cnt.find(in.length()) == cnt.end()) {
            cnt.insert({ in.length(), map<ll, int>() });
        }
        cnt[in.length()].insert({ hash, 0 });
        hashToIndex.insert({ hash, {i, false} });
    }

    int totLen = 0;
    for (int currLen : sLengths) {
        totLen += currLen;
    }

    ll calcs = 0;
    // calculate a hash for each substring of s with length "len"
    for (int len : sLengths) {
        ll currHash = 0;
        map<ll, int>& currMap = cnt[len];
        FOR(n) {
            int val1 = s[i] - 'a' + 1;
            currHash *= BASE;
            currHash += val1;
            currHash %= MOD;
            if (i >= len) {
                int val2 = s[i - len] - 'a' + 1;
                currHash -= val2 * powers[len];
                currHash %= MOD;
                if (currHash < 0) {
                    currHash += MOD;
                }
            }

            if (i + 1 >= len) {
                auto it = currMap.find(currHash);
                if (it != currMap.end()) {
                    it->s++;
                }
                // auto it = cnt.find(currHash);
                // if (it != cnt.end()) {
                //     it->s++;
                // }
            }
            calcs++;
        }
    }

    vector<int> ans(k);
    for (auto i = cnt.begin();i != cnt.end();i++) {
        for (auto j = i->s.begin();j != i->s.end();j++) {
            auto range = hashToIndex.equal_range(j->f);
            for (auto k = range.f;k != range.s;k++) {
                if (k->s.s) {
                    break;
                }
                int ansI = k->s.f;
                ans[ansI] = j->s;
                k->s.s = true;
            }
        }
    }

    // for (auto i = cnt.begin();i != cnt.end();i++) {
    //     auto range = hashToIndex.equal_range(i->f);
    //     for (auto j = range.f;j != range.s;j++) {
    //         if (j->s.s) {
    //             break;
    //         }
    //         int ansI = j->s.f;
    //         ans[ansI] = i->s;
    //         j->s.s = true;
    //     }
    // }

    FOR(k) {
        cout << ans[i] << endl;
    }

    return 0;
}
