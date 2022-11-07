// started : 03/16/22
// finished: 03/19/22
// problem : https://codeforces.com/problemset/problem/1624/D

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

void solve() {
    int n, k; cin >> n >> k;

    vector<bool> prevLetter(26, false);
    int numPairs = 0;
    for (int i = 0;i < n;i++) {
        char input; cin >> input;
        int toInt = (int)input - 97;

        if (prevLetter[toInt]) {
            numPairs++;
        }
        prevLetter[toInt] = !prevLetter[toInt];
    }   

    int output = (numPairs / k) * 2;
    if (n - (output * k) >= k) {
        output++;
    }

    cout << output << endl;
}

int main() {
    ios_base::sync_with_stdio(false)    ;
    cin.tie(NULL);

    int t; cin >> t; 
    for (int i = 0;i < t;i++) {
        solve();
    }


}