#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <numeric> 
#include <algorithm> 
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
using namespace std;

// you can use this to rename functions
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define endl "\n" // endl is slower than "\n"

struct node {
    int value;
    vector<node*> paths; // use pointers to make a reference to that specific node
};

void subsets() {
    // refer to Robot from the February 2022 contest
}

void vectorExamples(int n, int m) {
    // *** IMPORTANT!!! Vectors, when passed by functions, are not a reference; instead, a copy of the vector is passed as a parameter

    // creates a 2d vector with n rows and m columns. All its values are set to 0
    vector<vector<int>> vec1(n, vector<int>(m, 0));

    // creates a 2d vector with n rows and m columns. No default values
    vector<vector<int>> vec2(n, vector<int>(m));

    // creates a 2d vector with n rows and undefined columns
    vector<vector<int>> vec3(n);
}

struct P {
    int y, x, z;
    P(int y, int x, int z) {
        this->y = y;
        this->x = x;
        this->z = z;
    }
};

bool cmp(P a, P b) {
    return a.x < b.x;
}

struct setcmp {
    bool operator()(const P& a, const P& b) const { return a.y < b.y; }
};

void setSort() {
    // sorting sets using a functor
    set<P, setcmp> mySet;
}

void priorityQueue() {
    priority_queue<int> x; // max-heap
    priority_queue<int, vector<int>, greater<int>> y; // min-heap
    priority_queue<P, vector<P>, setcmp> z; // max-heap for struct P
}

int count_digits(ll num) {
    int ans = 0;
    while (num > 0) {
        num /= 10;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    // cout << (n & -n);

    cout << __gcd(5, 4);
}
