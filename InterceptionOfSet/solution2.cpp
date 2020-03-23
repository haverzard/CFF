#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Set interception problem
// Problem 2: Random Set
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
    
    int i=0, j=0;
    // Iterate all element between set 1 and set 2 (similar to merge)
    vector<int> solution;
    while (i < x && j < y) {
        if (a[i] == b[j]) {
            solution.push_back(a[i]);
            i++; j++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    for (int k=0; k<solution.size(); k++) cout << solution[k] << endl;
}