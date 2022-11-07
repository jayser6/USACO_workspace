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

pair<ll, ll> operator+(pair<ll, ll> a, pair<ll, ll> b) {
    return mp(a.f + b.f, a.s + b.s);
}

pair<ll, ll> operator-(pair<ll, ll> a, pair<ll, ll> b) {
    return mp(a.f - b.f, a.s - b.s);
}

struct hash_pair {
    size_t operator()(const pair<ll, ll>& p) const {
        return p.f * 239 + p.s;
    }
};

// generate all possible subsets from a given vector
vector<pair<pair<ll, ll>, int>> allSubsets(vector<pair<ll, ll>>& instructions) {
    vector<pair<pair<ll, ll>, int>> subsets = {{}};
    for (pair<ll, ll>& instruction : instructions) {
        subsets.resize(2 * subsets.size());
        for (int i = 0;i < subsets.size() / 2;i++) {
            subsets[i + (subsets.size() / 2)] = mp(subsets[i].f + instruction, subsets[i].s + 1);
        }
    }
    return subsets;
}

int main() {
    int n; cin >> n;
    ll destX, destY; cin >> destX >> destY;

    vector<pair<ll, ll>> instructions(n);
    for (int i = 0;i < n;i++) {
        cin >> instructions[i].f >> instructions[i].s;
    }

    vector<pair<ll, ll>> firstInstructions(instructions.begin(), instructions.begin() + (n / 2));
    vector<pair<ll, ll>> secondInstructions(instructions.begin() + (n / 2), instructions.end());
    vector<pair<pair<ll, ll>, int>> subset1 = allSubsets(firstInstructions);
    vector<pair<pair<ll, ll>, int>> subset2 = allSubsets(secondInstructions);

    hashmap<pair<ll, ll>, hashmap<int, int>, hash_pair> firstHalf;
    for (const pair<pair<ll, ll>, int>& dest : subset1) {
        firstHalf[mp(destX, destY) - dest.f][dest.s]++;
    } 

    vector<ll> output(n + 1);
    for (const pair<pair<ll, ll>, int>& secondHalf : subset2) {
        auto it = firstHalf.find(secondHalf.f);
        if (it != firstHalf.end()) {
            for (const auto& j : it->s) {
                output[j.f + secondHalf.s] += j.s;
            }
        }
    }

    for (int i = 1;i < n + 1;i++) {
        cout << output[i] << endl;
    }
}

