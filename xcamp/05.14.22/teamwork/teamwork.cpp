/*____________________________________________________________
// started : 05/20/22
// finished: 05/20/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=863
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

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; fin >> n >> k;

    vector<int> skill(n);
    for (int& input : skill) {
        fin >> input;
    }

    vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(k, mp(-1, -1))); // f -> sum, s -> max skill
    dp[0][0] = mp(skill[0], skill[0]);
    int prevMax = skill[0];
    bool where = 1;
    for (int i = 1;i < n;i++) {
        int newSum = prevMax + skill[i];
        dp[where][0] = mp(newSum, skill[i]);
        prevMax = newSum;
        for (int j = 1;j < k;j++) {
            pair<int, int> prev = dp[!where][j - 1];
            if (prev.f == -1) {
                break;
            }

            int newMax = max(prev.s, skill[i]);
            newSum = prev.f - (prev.s * (j)) + (newMax * (j + 1));
            dp[where][j] = mp(newSum, newMax);

            prevMax = max(prevMax, newSum);
        }

        where = !where;
    }

    fout << prevMax;
}
