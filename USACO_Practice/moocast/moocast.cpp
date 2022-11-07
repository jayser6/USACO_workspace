#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

struct cowInfo {
    int x, y, p;
    cowInfo(int x, int y, int p) {
        this->x = x;
        this->y = y;
        this->p = p;
    }
};

void DFS(int, int&, vector<bool>&, vector<vector<int>>);

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int n;
    fin >> n;

    vector<cowInfo> cows;
    int in1, in2, in3;
    for (int i = 0;i < n;i++) {
        fin >> in1 >> in2 >> in3;
        cows.push_back(cowInfo(in1, in2, in3));
    }

    //cout << "hello";

    vector<vector<int>> relay(n); // cow "row" can communicate with cow "column" 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int deltaX = abs(cows.at(i).x - cows.at(j).x);
            int deltaY = abs(cows.at(i).y) - cows.at(j).y;
            int distance = deltaX * deltaX + deltaY * deltaY; // its actually distance ^ 2
            
            if (distance <= cows.at(i).p * cows.at(i).p) {
                relay.at(i).push_back(j);
            }
        }
        /*
        for (int j = 0;j < relay.at(i).size();j++) {
            cout << relay.at(i).at(j) << " ";
        }
        cout << endl;
        */
    }

    int output = 0;
    vector<bool> visit;
    for (int i = 0;i < n;i++) {
        visit.assign(n, false);

        // run DFS and find the # of cows reached
        int cowsReached = 0;
        DFS(i, cowsReached, visit, relay);
        if (cowsReached > output) {
            output = cowsReached;
        }

        // reset for next DFS
        cout << "next DFS" << endl;
        for (int j = 0;j< n;j++) {
            visit.at(j) = false;
        }
    }

    fout << output;
}

void DFS(int currentCow, int& cowsReached, vector<bool>& visit, vector<vector<int>> relay) {
    cowsReached++;
    visit.at(currentCow) = true;

    cout << currentCow << endl;

    for (int i = 0;i < relay.at(currentCow).size();i++) {
        if (!visit.at(relay.at(currentCow).at(i))) {
            DFS(relay.at(currentCow).at(i), cowsReached, visit, relay);
        }
    }
}