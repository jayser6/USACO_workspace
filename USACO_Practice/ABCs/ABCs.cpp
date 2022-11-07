/*____________________________________________________________
// started : 06/10/22
// finished: 06/11/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1135
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
#define upper upper_bound
#define ll long long
#define u_int unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18

using namespace std;

bool arrHas(const vector<u_int>& vec, u_int val) {
    for (u_int currVal : vec) {
        if (currVal == val) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vector<u_int> nums(n);
    for (u_int& currNum : nums) {
        cin >> currNum;
    }

    nums.pb(0);
    hashset<u_int> enumerate;
    for (u_int num1 : nums) {
        enumerate.insert(num1);
        for (u_int num2 : nums) {
            if (num1 < num2) {
                enumerate.insert(num2 - num1);
            }
        }
    }

    int ans = 0;

    for (u_int a : enumerate) {
        for (u_int b : enumerate) {
            for (u_int c : enumerate) {
                if (a > b || b > c) {
                    continue;
                }

                vector<u_int> possible = { a, b, c, a + b, b + c, a + c, a + b + c };
                bool good = true;
                for (int currNum : nums) {
                    if (currNum == 0) {
                        continue;
                    }
                    if (!arrHas(possible, currNum)) {
                        good = false;
                        break;
                    }
                }

                if (good) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    FOR(t) {
        solve();
    }
}