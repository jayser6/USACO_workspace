// started : 03/09/22
// finished: 03/11/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1207

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define endl '\n'

using namespace std;

struct hash_pair {
    size_t operator()(const pair<ll, ll>& p) const {
        return p.f * 239 + p.s;
    }
};

pair<int, pair<ll, ll>> convert(int num, const vector<pair<ll, ll>>& instructions, int start) {
    int numSteps = 0;
    ll x = 0, y = 0;

    int index = start;
    while (num >= 1) {
        if (num % 2 == 1) {
            x += instructions[index].f;
            y += instructions[index].s;
            numSteps++;
        }

        index++;
        num /= 2;
    }

    return mp(numSteps, mp(x, y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    ll destY, destX; cin >> destX >> destY;

    vector<pair<ll, ll>> instructions(n);
    for (int i = 0;i < n;i++) {
        cin >> instructions[i].f >> instructions[i].s;
    }

    int size1, size2;
    if (n % 2 == 0) {
        size1 = n / 2;
        size2 = n / 2;
    }
    else {
        size1 = (n / 2) + 1;
        size2 = n / 2;
    }

    hashmap<pair<ll, ll>, map<int, int>, hash_pair> firstHalf; // inside the map, f -> # of instructions, s -> number of combinations
    for (int i = 0;i < pow(2, size1);i++) {
        pair<int, pair<ll, ll>> input = convert(i, instructions, 0);

        cout << i << endl;

        ++firstHalf[input.s][input.f];
    }

    vector<ll> output(n + 1, 0);
    for (int i = 0;i < pow(2, size2);i++) {
        pair<int, pair<ll, ll>> input = convert(i, instructions, size1);

        ll xNeeded = destX - input.s.f;
        ll yNeeded = destY - input.s.s;

        auto it = firstHalf.find(mp(xNeeded, yNeeded));
        if (it != firstHalf.end()) {
            for (auto j = it->s.begin();j != it->s.end();j++) {
                output[input.f + j->f] += j->s;
            }
        }
    }

    for (int i = 1;i < n + 1;i++) {
        cout << output[i] << endl;
    }

}
