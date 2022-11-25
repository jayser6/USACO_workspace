/*____________________________________________________________
// started : 11/19/22
// finished: 11/25/22
// problem : https://codeforces.com/problemset/problem/1709/C
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
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
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int mid(int a, int b) { return (a + b) / 2; }

int st_make(vector<int>& st, vector<int>& arr, int st_i, int st_s, int st_e) {
    if (st_s == st_e) {
        st[st_i] = (arr[st_s] < 2) ? 0 : 1;
        return st[st_i];
    }

    return st[st_i] = st_make(st, arr, (st_i * 2) + 1, st_s, mid(st_s, st_e)) * st_make(st, arr, (st_i * 2) + 2, mid(st_s, st_e) + 1, st_e);
}

int st_check(vector<int>& st, int st_i, int st_s, int st_e, int q_s, int q_e) {
    if ((st_e < q_s) || (st_s > q_e))
        return 1;
    else if ((st_s >= q_s) && (st_e <= q_e))
        return st[st_i];
    else
        return st_check(st, (st_i * 2) + 1, st_s, mid(st_s, st_e), q_s, q_e) * st_check(st, (st_i * 2) + 2, mid(st_s, st_e) + 1, st_e, q_s, q_e);

}

void solve() {
    string rbs; cin >> rbs;
    int sp = 0, ep = 0; // starting and ending parenthesis
    int n = rbs.length();
    vector<int> dif(n);
    vector<int> prev_q(n);

    ROF(n) {
        if (rbs[i] == '(')
            sp++;
        else if (rbs[i] == ')')
            ep++;
    }

    int prev_close = n - 1;
    int ep_rep = 0; // rep stands for replace
    ROF(n) {
        prev_q[i] = prev_close;

        if (rbs[i] == '?' && ep_rep + ep < n / 2) {
            prev_close = i;
            ep_rep++;
        }
    }

    if (ep == n / 2 || sp == n / 2) {
        cout << "YES" << endl;
        return;
    }

    int sp_rep = 0;
    FOR(n) {
        if (i == 0)
            dif[i] = 0;
        else
            dif[i] = dif[i - 1];


        if (rbs[i] == '(') {
            dif[i]++;
        }
        else if (rbs[i] == ')') {
            dif[i]--;
        }
        else {
            if (sp + sp_rep < n / 2) {
                dif[i]++;
                sp_rep++;
            }
            else {
                dif[i]--;
            }
        }
    }

    int st_depth = ceil(log2(n));
    int st_size = pow(2, st_depth + 1) - 1;
    vector<int> st(st_size);
    st_make(st, dif, 0, 0, n - 1);

    sp_rep = 0;

    FOR(n) {
        if (rbs[i] == '?' && (sp_rep + sp) < n / 2) {
            int ret = st_check(st, 0, 0, n - 1, i, max(0, prev_q[i] - 1));
            if (ret) {
                cout << "NO" << endl;
                return;
            }
            sp_rep++;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
