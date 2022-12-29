/*____________________________________________________________
// started : 12/29/22
// finished: 12/29/22
// problem : https://cses.fi/problemset/task/1076
____________________________________________________________*/

#include <bits/stdc++.h>

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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

// low contains elements in the window <= median, high contains elements in the
// window > median
struct window {
    multiset<int> low, high;
    int low_size, high_size;

    window(int k) {
        low_size = (k / 2) + (k % 2), high_size = k / 2;
    }

    void add(int val) {
        if (low.size() == 0) {
            low.insert(val);
        }
        else {
            int median = *low.rbegin();
            if (val <= median) {
                low.insert(val);
            }
            else {
                high.insert(val);
            }
        }

        balance();
    }

    void remove(int val) {
        if (low.find(val) != low.end()) {
            low.erase(low.find(val));
        }
        else if (high.find(val) != high.end()) {
            high.erase(high.find(val));
        }
        balance();
    }

    void balance() {
        if (low.size() == 0 && high.size() > 0) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
        while (low.size() > low_size) {
            high.insert(*low.rbegin());
            low.erase(--low.end());
        }
        while (high.size() > high_size) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

    int median() {
        return *low.rbegin();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("median.in", "r", stdin);

    int n, k; cin >> n >> k;
    vector<int> arr(n); FOR(i, n) cin >> arr[i];

    window win = window(k);

    FOR(i, n) {
        win.add(arr[i]);

        if (i >= k - 1) {
            cout << win.median() << " ";
            win.remove(arr[i - k + 1]);
        }
    }

    return 0;
}
