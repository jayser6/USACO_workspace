// started : 01/22/22
// finished: 01/22/22
// problem : USB vs PS/2 (CF) https://codeforces.com/contest/762/problem/B

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;

    int m; cin >> m;

    vector<pair<ll, string>> mice(m);
    for (int i = 0;i < m;i++) {
        cin >> mice[i].f >> mice[i].s;
    }

    sort(ALL(mice));

    int equippedNum = 0;
    ll totalCost = 0;
    for (int i = 0;i < m;i++) {
        equippedNum++;
        totalCost += mice[i].f;
        if (mice[i].s == "USB") {
            if (a > 0) {
                a--;
            }
            else if (c > 0) {
                c--;
            }
            else {
                equippedNum--;
                totalCost -= mice[i].f;
            }
        }
        else {
            if (b > 0) {
                b--;
            }
            else if (c > 0) {
                c--;
            }
            else {
                equippedNum--;
                totalCost -= mice[i].f;
            }
        }
    }

    cout << equippedNum << " " << totalCost;
}
