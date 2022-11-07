/*____________________________________________________________
// started : 06/27/22
// finished: 06/27/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1040
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound // rust woooo
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18

using namespace std;

ifstream fin("moop.in");
ofstream fout("moop.out");

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n; fin >> n;
    vector<pair<int, int>> particles(n);
    for (pair<int, int>& particle : particles) {
        fin >> particle.f >> particle.s;
    }

    sort(ALL(particles));

    vector<int> rollMin(n); // 0, i inclusive
    int currMin = 2 * 1e9;
    FOR(n) {
        currMin = min(currMin, particles[i].s);
        rollMin[i] = currMin;
    }

    vector<int> rollMax(n); // i, n - 1 inclusive
    int currMax = -2 * 1e9;
    ROF(n) {
        currMax = max(currMax, particles[i].s);
        rollMax[i] = currMax;
    }

    int ans = 1;
    FOR(n - 1) {
        ans += rollMin[i] > rollMax[i + 1];
    }

    fout << ans;

    return 0;
}
