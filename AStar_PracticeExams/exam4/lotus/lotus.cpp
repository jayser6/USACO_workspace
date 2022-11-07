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

struct P {
    int t, lotus1, lotus2;
    P(int t, int lotus1, int lotus2) {
        this->t = t;
        this->lotus1 = lotus1;
        this->lotus2 = lotus2;
    }
};

struct cmp {
    bool operator()(const P& a, const P& b) const {
        if (a.t == b.t) {
            return a.lotus2 > b.lotus2;
        }
        return a.t < b.t;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, k; cin >> w >> h >> k;

    vector<pair<int, int>> lotuses(k);
    for (pair<int, int>& lotus : lotuses) {
        cin >> lotus.f >> lotus.s;
    }

    multiset<P, cmp> collisions;
    for (int i = 0;i < k;i++) {
        for (int j = i + 1;j < k;j++) {
            collisions.insert(P(max(abs(lotuses[i].f - lotuses[j].f), abs(lotuses[i].s - lotuses[j].s)) / 2, i, j));
        }
        collisions.insert(P(min(h - lotuses[i].s, min(lotuses[i].s, min(w - lotuses[i].f, lotuses[i].f))), i, -1)); // -1 means that lotus i collides with the wall or a fully grown lotus
    }

    vector<int> growth(k, pow(10, 5)); // -1 means that lotus i hasn't fullen grown yet
    while (!collisions.empty()) {
        P curr = *(collisions.begin());
        collisions.erase(collisions.begin());

        int l1 = curr.lotus1;
        int l2 = curr.lotus2;

        if (l2 == -1) {
            growth[l1] = min(curr.t, growth[l1]);
        }
        else if (growth[l1] == growth[l2]) {
            if (growth[l1] == pow(10, 5)) {
                growth[l1] = curr.t;
                growth[l2] = curr.t;
            }
        }
        else if (growth[l1] == pow(10, 5)) {
            collisions.insert(P((curr.t * 2) - growth[l2], l1, -1));
        }
        else {
            collisions.insert(P((curr.t * 2) - growth[l1], l2, -1));
        }
    }

    ll output = 0;
    for (int currGrowth : growth) {
        output += 4 * currGrowth * currGrowth;
    }

    cout << output;
}
