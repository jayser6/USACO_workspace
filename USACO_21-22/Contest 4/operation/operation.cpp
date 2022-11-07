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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    vector<int> c_psum(s.length() + 1, 0);
    vector<int> o_psum(s.length() + 1, 0);
    vector<int> w_psum(s.length() + 1, 0);
    for (int i = 0;i < s.length();i++) {
        c_psum[i + 1] = c_psum[i];
        o_psum[i + 1] = o_psum[i];
        w_psum[i + 1] = w_psum[i];

        if (s.at(i) == 'C') {
            c_psum[i + 1]++;
        }
        else if (s.at(i) == 'O') {
            o_psum[i + 1]++;
        }
        else {
            w_psum[i + 1]++;
        }
    }

    int q; cin >> q;
    for (int i = 0;i < q;i++) {
        int l, r; cin >> l >> r;

        int C_cnt = c_psum[r] - c_psum[l - 1];
        int O_cnt = o_psum[r] - o_psum[l - 1];
        int W_cnt = w_psum[r] - w_psum[l - 1];

        if (((C_cnt + O_cnt) % 2 == 1) && ((C_cnt + W_cnt) % 2 == 1)) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }
}