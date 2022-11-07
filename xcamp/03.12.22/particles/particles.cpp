// started : 03/14/22
// finished: 03/15/22
// probelm : https://codeforces.com/problemset/problem/1625/B

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
    int n; cin >> n;
    
    int output = -1;
    hashmap<int, int> pastParticles;
    for (int i = 0;i < n;i++) {
        int num; cin >> num; 
        auto it = pastParticles.find(num);
        if (it != pastParticles.end()) {
            output = max(output, it->s + n - i);
        }

        pastParticles[num] = i;
    }

    cout << output << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}