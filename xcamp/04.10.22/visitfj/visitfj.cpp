// started : 04/15/22
// finished: ???
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=717

#include <bits/stdc++.h>

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

ifstream fin("visitfj.in");
ofstream fout("visitfj.out");

struct info {
    int y;
    int x;
    int numMoves;
    ll time;

    info(int y, int x, int numMoves, ll time) {
        this->y = y;
        this->x = x;
        this->numMoves = numMoves;
        this->time = time;
    }
};

struct cmp {
    bool operator()(const info& a, const info& b) const { return a.time < b.time; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; fin >> n >> t;

    vector<vector<int>> fields(n, vector<int>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            fin >> fields[i][j];
        }
    }
    fields[0][0] = 0; // the top left corner of the field will never be eaten anyways

    vector<vector<vector<ll>>> timeTo(n, vector<vector<ll>>(n, vector<ll>(3, BIG_NUMBER)));
    multiset<info, cmp> dijkstra;
    dijkstra.insert(info(0, 0, 0, 0));
    pair<int, int> directions[] = { mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0) };

    while (!dijkstra.empty()) {
        info curr = *(dijkstra.begin());
        dijkstra.erase(dijkstra.begin());
        if (curr.time > timeTo[curr.y][curr.x][curr.numMoves % 3]) {
            continue;
        }

        for (auto currDir : directions) {
            int newY = currDir.f + curr.y;
            int newX = currDir.s + curr.x;
            if (newY < 0 || newY >= n || newX < 0 || newX >= n) {
                continue;
            }
            ll newTime = curr.time + t + ((curr.numMoves % 3 == 0) ? fields[curr.y][curr.x] : 0);

            if (newTime < timeTo[newY][newX][(curr.numMoves + 1) % 3]) {
                timeTo[newY][newX][(curr.numMoves + 1) % 3] = newTime;
                dijkstra.insert(info(newY, newX, curr.numMoves + 1, newTime));
            }
        }
    }

    fout << min(timeTo[n - 1][n - 1][0] + fields[n - 1][n - 1], min(timeTo[n - 1][n - 1][1], timeTo[n - 1][n - 1][2]));
}