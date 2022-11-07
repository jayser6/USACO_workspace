// started : 12/19/21
// finished: 1/8/21

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first 
#define s second

using namespace std;

int main() {
    //ifstream fin("intervals.in");
    //ofstream fout("intervals.out");

    int n, m; cin >> n >> m;

    vector<ll> aFrequency(m + 1, 0);
    vector<ll> bFrequency(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        aFrequency.at(a)++;
        bFrequency.at(b)++;
    }

    vector<ll> winStart(2 * m + 1, 0);
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            winStart.at(i + j) += aFrequency.at(i) * aFrequency.at(j);
        }
    }

    vector<ll> winEnd(2 * m + 1, 0);
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            winEnd.at(i + j) += bFrequency.at(i) * bFrequency.at(j);
        }
    }

    ll answer = 0;
    for (int i = 0; i <= 2 * m; i++) {
        answer += winStart.at(i);
        cout << answer << endl;
        answer -= winEnd.at(i);
    }
}