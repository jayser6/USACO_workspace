// started : 01/28/22
// finished: 02/28/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1182

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define end "\n"

using namespace std;

ll calcSteps(ll a, ll b) { // get from a to b only using +1 and x2
    ll steps = 0;
    while (a != b) {
        if (b < a * 2) {
            steps += b - a;
            break;
        }
        else if (b % 2 == 1) {
            b--;
        }
        else {
            b /= 2;
        }
        steps++;
    }

    return steps;
}

void solve() {
    ll a, b; cin >> a >> b;

    ll ans = pow(10, 19); // might have to make this value bigger but prob not
    ll num = a, steps = 0;
    while (true) {
        if (num <= b) {
            ll totalSteps = calcSteps(num, b) + steps;
            ans = min(totalSteps, ans);
        }

        if (num == 1) {
            break;
        }

        if (num % 2 == 0) {
            num /= 2;
        }
        else {
            num++;
        }
        steps++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0;i < n;i++) {
        solve();
    }
}
