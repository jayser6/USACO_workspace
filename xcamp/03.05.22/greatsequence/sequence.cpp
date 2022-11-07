// started : 03/08/22
// finished: 03/08/22
// problem : https://codeforces.com/contest/1641/problem/A
#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

bool canPair(hashmap<ll, int>& prevNums, ll num, int x) {
    if (num % x != 0) {
        return false;
    } 

    auto it = prevNums.find(num / x);
    if (it == prevNums.end()) {
        return false;
    }
    return true;
}

void solve() {
    int n, x; cin >> n >> x;

    vector<ll> list(n);
    for (int i = 0;i < n;i++) {
        cin >> list[i];
    }
    sort(ALL(list));

    int pairs = 0;
    hashmap<ll, int> prevNums; // key -> the number, value -> the number of times that the key has appeared in the past
    for (int i = 0;i < n;i++) {
        if (canPair(prevNums, list[i], x)) {
            pairs++;

            auto it = prevNums.find(list[i] / x);
            it->s--;
            if (it->s == 0) {
                prevNums.erase(it);
            }
        }
        else {
            auto it = prevNums.find(list[i]);

            if (it == prevNums.end()) {
                prevNums[list[i]] = 1;
            }
            else {
                it->s++;
            }
        }
    }
    
    cout << (n - (pairs * 2)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}
