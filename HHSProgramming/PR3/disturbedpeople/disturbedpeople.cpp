#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

void solve() {
    int n; cin >> n;
    
    vector<int> flats;
    for (int i = 0;i < n;i++) {
        int input; cin >> input;
        flats.pb(input);
    }

    int output = 0;
    for (int i = 1;i < n - 1;i++) {
        if ((flats.at(i) == 0) && (flats.at(i-1)) == 1 && (flats.at(i+1) == 1)) {
            flats.at(i+1) = 0;
            output++;
        }
    }

    cout << output << endl;
}

int main() {
    int t; cin >> t;
    
    for (int i = 0;i < t;i++) {
        solve();
    }
}