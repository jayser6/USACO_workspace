/*____________________________________________________________
// started : 05/17/22
// finished: 05/17/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=858
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound
#define upper upper_bound
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("convention.in");
ofstream fout("convention.out");

bool canFit(ll maxTime, int m, int c, vector<ll>& cows) {
    ll startTime = cows[0];
    int cowCnt = 0;
    int busUsed = 0;
    FOR(cows.size()) {
        cowCnt++;
        if (cowCnt > c || cows[i] - startTime > maxTime) {
            busUsed++;
            cowCnt = 1;
            startTime = cows[i];
        }
    }

    busUsed++;

    return busUsed <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c; fin >> n >> m >> c;

    vector<ll> cows(n);
    for (ll& curr : cows) {
        fin >> curr;
    }

    sort(ALL(cows));

    ll ans = -1;
    ll low = 0, high = cows[n - 1] + 3;
    while (low <= high) {
        ll mid = (low + high) / 2;

        if (canFit(mid, m, c, cows)) {
            high = mid - 1;
            ans = mid;

        }
        else {
            low = mid + 1;
        }
    }

    fout << ans;
}
