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
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    sort(ALL(a));
    
    cout << (a[n - 2] - a[1]);
}