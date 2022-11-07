#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

// the leftend(pair.first) of the mountain takes priority
bool sortMountains(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second; 
    }
    return a.first < b.first;
}

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    
    int n;
    fin >> n;
    
    vector<pair<int, int>> mountains; // first -> leftend of the mountain, second -> rightend of the mountain

    int input1;
    int input2;
    for (int i = 0;i < n;i++) {
        fin >> input1 >> input2;
        mountains.push_back(make_pair(input1 - input2, input1 + input2));
    }
    fin.close();
    sort(mountains.begin(), mountains.end(), sortMountains);
    
    int output = 0;
    int farthestRight = -1;
    for (int i = 0;i < n;i++) {
        // if 
        if (mountains.at(i).second > farthestRight) {
            farthestRight = mountains.at(i).second;
            output++;
        }
    }

    fout << output;
    fout.close();
}