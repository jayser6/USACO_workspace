// started : 03/25/22
// finished: 03/25/22
// problem : https://codeforces.com/problemset/problem/1574/C#:~:text=To%20defeat%20a%20dragon%2C%20you,others%20will%20defend%20the%20castle.

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll totalStrength = 0;
    vector<ll> heroes(n);
    for (int i = 0;i < n;i++) {
        cin >> heroes[i];
        totalStrength += heroes[i];
    }

    sort(ALL(heroes));

    int m; cin >> m;
    for (int i = 0;i < m;i++) {
        ll def, atk; cin >> def >> atk;
        ll output = 3 * (ll)pow(10, 18);

        auto find = upper_bound(ALL(heroes), def);
        if (find != heroes.end()) {
            output = max(0LL, atk - (totalStrength - *find));
        }
        if (find != heroes.begin()) {
            find--;
            output = max(0LL, min(output, (def - *find) + max(0LL, atk - (totalStrength - *find))));
        }

        cout << output << endl;       
    }
    

}