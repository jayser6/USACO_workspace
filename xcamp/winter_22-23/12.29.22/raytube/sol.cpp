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

/*
* Idea:
*/

const ll MOD = 1000000007;
const int maxN = 5000 + 5;


int main()
{
    ll n, y1; cin >> n >> y1;
    vector<ll> top(n);
    for (int i = 0; i < n; i++) {
        cin >> top[i];
    }
    ll m, y2; cin >> m >> y2;
    vector<ll> bot(m);
    for (int i = 0; i < m; i++) {
        cin >> bot[i];
    }
    ll ans = 2;
    for (ll i = 1; i <= 32; i++) {
        ll mod = ll(1) << i;
        map<ll, ll> a;
        map<ll, ll> b;
        for (auto x : top) {
            a[x % mod]++;
        }
        for (auto x : bot) {
            b[x % mod]++;
        }
        for (auto& x : a) {
            ans = max(ans, x.second + b[(x.first + mod / 2) % (mod)]);
        }
        for (auto& x : b) {
            ans = max(ans, x.second + a[(x.first + mod / 2) % (mod)]);
        }

    }
    cout << ans << '\n';