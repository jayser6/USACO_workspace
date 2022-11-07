// started : 03/09/22
// finished: 03/12/22
// problem : https://codeforces.com/problemset/problem/1638/C

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

    stack<int> compMax;
    for (int i = 0;i < n;i++) {
        int num; cin >> num;
        if (compMax.empty() || compMax.top() < num) {
            compMax.push(num);
        }
        else {
            int greatest = -1;
            while (!compMax.empty() && compMax.top() > num) {
                greatest = max(greatest, compMax.top());
                compMax.pop();
            }
            compMax.push(greatest);
        }
    }

    cout << compMax.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}
