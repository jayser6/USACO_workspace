/*____________________________________________________________
// started : 12/29/22
// finished: 12/29/22
// problem : https://codeforces.com/problemset/problem/1041/D
// extra   : this is the only problem I wrote on my own haha.
____________________________________________________________*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <map>
#include <chrono>
#include <cstring>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll MOD = 1000000007;
const int maxN = 1e5 + 5;

int main()
{
    int n, h; cin >> n >> h;

    vector<pair<int, int>> arr(n);
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        l[i] = arr[i].second - arr[i].first;
    }

    vector<int> gap(n - 1);
    for (int i = 0; i < n - 1; i++) {
        gap[i] = arr[i + 1].first - arr[i].second;
    }

    int sp = 0, ep = 0;
    ll ans = 0, fall = 0, dist = l[0];
    while (sp < n) {
        ans = max(ans, dist + h - fall);
        ep++;
        if (ep < n) {
            fall += gap[ep - 1];
            dist += gap[ep - 1] + l[ep];
        }
        while (0 >= h - fall || (ep >= n && sp < n)) {
            if (sp < n - 1) {
                fall -= gap[sp];
                dist -= gap[sp] + l[sp];
            }
            sp++;
        }
    }

    cout << ans;

    return 0;
}