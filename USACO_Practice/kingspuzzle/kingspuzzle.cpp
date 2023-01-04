/*____________________________________________________________
// started : 01/04/23
// finished: 01/04/23
// problem : https://codeforces.com/problemset/problem/1773/K
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define tup tuple
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 500;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    if (n == 1) {
        cout << "YES" << endl;
        cout << "0" << endl;
        return 0;
    }
    else if (n == k) {
        cout << "NO" << endl;
        return 0;
    }
    else if (n == 2) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    else if (k == 1) {
        cout << "YES" << endl;
        cout << n << endl;
        FOR(i, n - 1) cout << i + 1 << " " << i + 2 << endl;
        cout << n << " " << 1 << endl;
        return 0;
    }

    pair<int, int> steps[MAX_N + 5];
    int type[MAX_N + 5];
    int idx = 0;
    int m = 0;
    steps[idx] = { n, k };

    while (steps[idx].f > 4) {
        int n_n = steps[idx].f;
        int n_k = steps[idx].s;

        if (n_n > k + 1) {
            steps[idx + 1] = { n_n - 1, n_k };
            type[idx] = 1;
            m++;
        }
        else {
            steps[idx + 1] = { n_n - 2, n_k - 2 };
            type[idx] = 2;
            m += n_n - 1;
        }

        idx++;
    }

    // finalize steps and start printing
    cout << "YES" << endl;

    int head = 1;
    if (steps[idx].f == 3) {
        m += 2;

        cout << m << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 3 << endl;
    }
    else {
        if (steps[idx].s == 2) m += 3;
        else m += 4;

        cout << m << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 1 << " " << 4 << endl;

        if (steps[idx].s == 3) cout << 2 << " " << 3 << endl;
    }

    ROF(i, idx) {
        if (type[i] == 1) cout << head << " " << steps[i].f << endl;
        else {
            FOR(j, steps[i].f - 1) cout << steps[i].f << " " << j + 1 << endl;
            head = steps[i].f;
        }
    }

    return 0;
}
