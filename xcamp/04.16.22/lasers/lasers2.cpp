// started : 04/22/22
// finished: 04/30/22
// problem : http://www.usaco.org/index.php?cpid=671&page=viewproblem2

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define f first
#define s second
#define yp first
#define xp second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

ifstream fin("lasers.in");
ofstream fout("lasers.out");

struct Point {
    ll y;
    ll x;
    int index;

    Point(ll y, ll x, int index) {
        this->y = y;
        this->x = x;
        this->index = index;
    }
};

struct Dijk {
    int index;
    int dist;
    bool dir;

    Dijk(int index, int dist, bool dir) {
        this->index = index;
        this->dist = dist;
        this->dir = dir;
    }
};

bool cmpY(Point a, Point b) {
    return a.y < b.y;
}

bool cmpX(Point a, Point b) {
    return a.x < b.x;
}

bool isIn(int val, int n) {
    return val >= 0 && val < n;
}

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);

    int n; ll xL, yL, xB, yB; fin >> n >> xL >> yL >> xB >> yB;

    vector<Point> fencesY(n + 2, Point(0, 0, 0));
    vector<Point> fencesX(n + 2, Point(0, 0, 0));
    for (int i = 0;i < n;i++) {
        ll x, y; fin >> x >> y;
        fencesY[i] = Point(y, x, i);
        fencesX[i] = Point(y, x, i);
    }
    fencesX[n] = Point(yB, xB, n);
    fencesY[n] = Point(yB, xB, n);
    fencesX[n + 1] = Point(yL, xL, n + 1);
    fencesY[n + 1] = Point(yL, xL, n + 1);

    sort(ALL(fencesY), cmpY);
    sort(ALL(fencesX), cmpX);

    vector<pair<int, int>> fenceOrder(n + 2);
    for (int i = 0;i < n + 2;i++) {
        fenceOrder[fencesY[i].index].f = i;
        fenceOrder[fencesX[i].index].s = i;
    }

    // run dijkstra
    vector<vector<ll>> distTo(n + 2, vector<ll>(2, BIG_NUMBER)); // 0 -> vertical
    distTo[n + 1][0] = 0;
    distTo[n + 1][1] = 0;
    deque<Dijk> dijkstra;
    dijkstra.pb(Dijk(n + 1, 0, true));
    dijkstra.pb(Dijk(n + 1, 0, false));

    while (!dijkstra.empty()) {
        Dijk curr = *(dijkstra.begin());

        dijkstra.popf();

        if (curr.dist > distTo[curr.index][curr.dir]) {
            continue;
        }

        for (int i = -1;i <= 1;i += 2) { // first make the light go vertically
            int destIndex = fenceOrder[curr.index].yp + i; // index in fencesY
            if (isIn(destIndex, n + 2) && fencesY[destIndex].y == fencesY[fenceOrder[curr.index].f].y) {
                int inputIndex = fencesY[destIndex].index;
                if (curr.dist + curr.dir < distTo[inputIndex][false]) {
                    distTo[inputIndex][false] = curr.dist + curr.dir;
                    if (curr.dir) {
                        dijkstra.pb(Dijk(inputIndex, curr.dist + 1, false));
                    }
                    else {
                        dijkstra.pf(Dijk(inputIndex, curr.dist, false));
                    }
                }
            }
        }

        for (int i = -1;i <= 1;i += 2) { // now direct the lights horizontally
            int destIndex = fenceOrder[curr.index].xp + i; // index in fencesX
            if (isIn(destIndex, n + 2) && fencesX[destIndex].x == fencesX[fenceOrder[curr.index].s].x) {
                int inputIndex = fencesX[destIndex].index;
                if (curr.dist + !curr.dir < distTo[inputIndex][true]) {
                    distTo[inputIndex][true] = curr.dist + !curr.dir;
                    if (curr.dir) {
                        dijkstra.pf(Dijk(inputIndex, curr.dist, true));
                    }
                    else {
                        dijkstra.pb(Dijk(inputIndex, curr.dist + 1, true));
                    }
                }
            }
        }
    }

    ll output = min(distTo[n][0], distTo[n][1]);
    if (output == BIG_NUMBER) {
        fout << -1;
    }
    else {
        fout << output;
    }
}
