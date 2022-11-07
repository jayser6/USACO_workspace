// started : 02/02/22
// finished: 02/04/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=968

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

vector<char> cows;
vector<int> cowComps;

vector<vector<int>> paths;

void DFS(int node, int compNumber) {
    cowComps[node] = compNumber;

    for (int destination : paths[node]) {
        if (cows[destination] == cows[node] && cowComps[destination] == -1) {
            DFS(destination, compNumber);
        }
    }
}

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    // get input
    int n, m; fin >> n >> m;

    cows = vector<char>(n);
    for (int i = 0;i < n;i++) {
        fin >> cows[i];
    }

    paths = vector<vector<int>>(n);
    for (int i = 0;i < n - 1;i++) {
        int a, b; fin >> a >> b;
        a--; b--;

        paths[a].pb(b);
        paths[b].pb(a);
    }

    // calculate which comonent each cow belongs to
    cowComps = vector<int>(n, -1);
    for (int i = 0, compNumber = 0;i < n;i++) {
        if (cowComps[i] == -1) {
            DFS(i, compNumber);
            compNumber++;
        }
    }

    // get the farmer inputs and calculate answer for each farmer
    for (int i = 0;i < m;i++) {
        int start, end; fin >> start >> end;
        start--; end--;
        char preference; fin >> preference;

        if (cowComps[start] == cowComps[end]) {
            fout << (int)(cows[start] == preference);
        }
        else {
            fout << "1";
        }
    }
}
