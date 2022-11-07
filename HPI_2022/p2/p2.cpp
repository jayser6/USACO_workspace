#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

int main() {
    int n, q; cin >> n >> q;

    vector<int> masses(n);
    for (int i = 0; i < n;i++) {
        cin >> masses[i];
    }

    for (int j = 0;j < q;j++) {
        int l, r; cin >> l >> r;
        l--;
        r--;

        hashmap<int, int> data; 
        for (int i = l;i <= r;i++) {
            data[masses[i]]++;
        }

        int mode = -1; 
        int modeCnt = -1;
        for (auto it = data.begin();it != data.end();it++) {
            if (mode == -1) {   
                mode = it->f;
                modeCnt = it->s;
            }
            else if (modeCnt < it->s) {
                mode = it->f;
                modeCnt = it->s;
            }
            else if (modeCnt == it->s && it->f < mode) {
                mode = it->f;
                modeCnt = it->s;
            }
        }

        cout << mode << endl;
    }
}