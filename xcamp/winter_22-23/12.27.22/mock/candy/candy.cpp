/*____________________________________________________________
// started : 12/27/22
// finished: 12/27/22
// problem : https://codeforces.com/group/eZhSssSlea/contest/418818/problem/A
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

struct node {
    int val;
    int id;
    node* forward;
    node* backward;

    node(int val, int id) {
        this->val = val;
        this->id = id;
        forward = nullptr;
        backward = nullptr;
    }

    node() {
        val = 0;
        id = -1;
        forward = nullptr;
        backward = nullptr;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;

    // build circular linked list
    node head = node();
    node* curr = &head;
    FOR(i, n) {
        int num; cin >> num;
        curr->val = num;
        curr->id = i;
        curr->forward = new node();
        curr->forward->backward = curr;
        curr = curr->forward;
    }
    curr = curr->backward;
    curr->forward = &head;
    head.backward = curr;

    // start the algorithm
    int ans = 0;
    int removed = 0;
    vector<bool> seen(n, false);
    curr = &head;
    while (true) {
        node* next = curr->forward;
        seen[curr->id] = true;
        if (curr->id == next->id || removed == n)
            break;

        if (next->val == curr->val || next->val + curr->val == x) {
            ans++;
            removed += 2;
            curr = curr->backward;
            curr->forward = next->forward;
            next->forward->backward = curr;
        }
        else {
            curr = next;
            if (seen[curr->id]) {
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
