/*____________________________________________________________*/
// started : 05/12/22
// finished: 05/25/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=574
/*____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++) 
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define forever while (true)
#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("feast.in");
ofstream fout("feast.out");

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b; fin >> t >> a >> b;

    vector<vector<bool>> visited(2, vector<bool>(t + 1, false)); // i = 0 -> didn't drink water yet
    visited[0][0] = true;

    int output = 0;

    FOR(t + 1) {
        if (visited[0][i]) {
            output = i;
            if (a + i <= t) {
                visited[0][a + i] = true;
            }
            if (b + i <= t) {
                visited[0][b + i] = true;
            }
            visited[1][i / 2] = true;
        }
    }

    FOR(t + 1) {
        if (visited[1][i]) {
            output = max(output, i);
            if (a + i <= t) {
                visited[1][a + i] = true;
            }
            if (b + i <= t) {
                visited[1][b + i] = true;
            }
        }
    }

    fout << output;
}