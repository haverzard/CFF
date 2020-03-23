#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void intercept(vector<int> &a,vector<int> &b,vector<int> &sol) {
    for (int i=0; i<a.size(); i++) {
        if (binary_search(b.begin(),b.end(),a[i])) {
            sol.push_back(a[i]);
        }
    }
}

// Set interception problem
// Problem 3: Very unequal size sets
// Time Complexity O(n log n + m log m)
int main() {
    int x, y;
    cin >> x >> y;
    vector<int> a(x), b(y);
    for (int i=0; i<x; i++) cin >> a[i];
    for (int i=0; i<y; i++) cin >> b[i];
    // Sort array with quick sort
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    // Binary Search small set to large set
    vector<int> solution;
    if (x > y) intercept(b,a,solution);
    else intercept(b,a,solution);
    for (int k=0; k<solution.size(); k++) cout << solution[k] << endl;
}