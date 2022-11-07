#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

void solve() {
    int n; cin >> n;
    
    // index represents... the index, element represents the position of the camel
    vector<int> camelIndex(n); 

    // the index represents the position of the camels(i = 0 -> x = -10^4)
    // the element(pair) represents: first: is there a cow here? second: the distance of the cow's spit(0 if no cow is there)
    vector<pair<bool, int>> camelPosition(2 * 10000 + 1, make_pair(false, 0)); 
                                                                                
    for (int i = 0;i < n;i++) {
        cin >> camelIndex.at(i);
        camelIndex.at(i) += 10000;
        cin >> camelPosition.at(camelIndex.at(i)).second;
        camelPosition.at(camelIndex.at(i)).first = true;
    }

    int output = 0;
    for (int i = 0;i < n;i++) {
        int spitPosition1 = camelPosition.at(camelIndex.at(i)).second + camelIndex.at(i);
        // probably unnecessarily but keeping it just in case vector length errors occur
        if (spitPosition1 < 0 || spitPosition1 >= camelPosition.size()) {
            continue;
        }
        // no camel exists in spitPosition1
        if (!camelPosition.at(spitPosition1).first) {
            continue;
        }

        int spitPosition2 = camelPosition.at(spitPosition1).second + spitPosition1;
        if (spitPosition2 == camelIndex.at(i)) {
            output++;
        }
    }
    if (output == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }

}

int main() {
    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}