/*____________________________________________________________*/
// started : 06/09/22
// finished: 06/09/22
// problem : http://usaco.org/index.php?page=viewproblem2&cpid=670
/*____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define u_int unsigned int
#define hashmap unordered_map
#define p_queue priority_queue
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18

using namespace std;

ifstream fin("checklist.in");
ofstream fout("checklist.out");

struct P {
    bool which; // 0 -> h, 1 -> g
    int bCnt[2];

    u_int nrg;

    P() {}
    P(bool which, int h, int g, u_int nrg) {
        this->which = which;
        bCnt[0] = h;
        bCnt[1] = g;
        this->nrg = nrg;
    }
};

struct cmp {
    bool operator()(const P& a, const P& b) const { return a.nrg > b.nrg; }
};

u_int calcE(pair<int, int> a, pair<int, int> b) {
    u_int deltaX = a.f - b.f;
    u_int deltaY = a.s - b.s;

    return (deltaX * deltaX) + (deltaY * deltaY);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, g; fin >> h >> g;
    vector<vector<pair<int, int>>> cows(2);
    FOR(h) {
        pair<int, int> input; fin >> input.f >> input.s;
        cows[0].pb(input);
    }
    FOR(g) {
        pair<int, int> input; fin >> input.f >> input.s;
        cows[1].pb(input);
    }

    vector<vector<vector<u_int>>> dp(2, vector<vector<u_int>>(h + 1, vector<u_int>(g + 1, 4 * 1e9)));
    p_queue<P, vector<P>, cmp> dijkstra;

    dp[0][1][0] = 0;
    dijkstra.push(P(0, 1, 0, 0));
    while (!dijkstra.empty()) {
        P curr = dijkstra.top();
        dijkstra.pop();

        if (curr.nrg > dp[curr.which][curr.bCnt[0]][curr.bCnt[1]]) {
            continue;
        }

        u_int newE;
        if ((curr.bCnt[0] == h - 1) && (curr.bCnt[1] == g)) {
            newE = curr.nrg + calcE(cows[curr.which][curr.bCnt[curr.which] - 1], cows[0][h - 1]); // the cows index starts from 0, not 1
            dp[0][h][g] = min(dp[0][h][g], newE);
        }
        else {
            if (curr.bCnt[0] < h - 1) {
                newE = curr.nrg + calcE(cows[curr.which][curr.bCnt[curr.which] - 1], cows[0][curr.bCnt[0]]);
                if (newE < dp[0][curr.bCnt[0] + 1][curr.bCnt[1]]) {
                    dp[0][curr.bCnt[0] + 1][curr.bCnt[1]] = newE;
                    dijkstra.push(P(0, curr.bCnt[0] + 1, curr.bCnt[1], newE));
                }
            }
            if (curr.bCnt[1] < g) {
                newE = curr.nrg + calcE(cows[curr.which][curr.bCnt[curr.which] - 1], cows[1][curr.bCnt[1]]);
                if (newE < dp[1][curr.bCnt[0]][curr.bCnt[1] + 1]) {
                    dp[1][curr.bCnt[0]][curr.bCnt[1] + 1] = newE;
                    dijkstra.push(P(1, curr.bCnt[0], curr.bCnt[1] + 1, newE));
                }
            }
        }
    }

    fout << dp[0][h][g];

    return 0;
}
