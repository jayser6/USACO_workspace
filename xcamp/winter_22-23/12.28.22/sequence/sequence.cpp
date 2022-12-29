/*____________________________________________________________
// started : 12/28/22
// finished:
// problem : https://vjudge.net/problem/CodeForces-446A
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n); FOR(i, n) cin >> arr[i];

    vector<int> left_inc(n), right_inc(n);
    left_inc[0] = 1;
    FORO(i, n) {
        if (arr[i] > arr[i - 1]) {
            left_inc[i] = left_inc[i - 1] + 1;
        }
        else {
            left_inc[i] = 1;
        }
    }
    right_inc[n - 1] = 1;
    ROF(i, n - 1) {
        if (arr[i] < arr[i + 1]) {
            right_inc[i] = right_inc[i + 1] + 1;
        }
        else {
            right_inc[i] = 1;
        }
    }

    int ans = 0;

    FOR(i, n) {
        int new_length;
        if (i == 0) {
            new_length = right_inc[1] + 1;
        }
        else if (i == n - 1) {
            new_length = left_inc[n - 2] + 1;
        }
        else {
            if (arr[i - 1] > arr[i + 1] - 2) {
                new_length = max(left_inc[i - 1], right_inc[i + 1]) + 1;
            }
            else {
                new_length = left_inc[i - 1] + right_inc[i + 1] + 1;
            }
        }

        ans = max(ans, new_length);
    }

    cout << ans << endl;

    return 0;
}
