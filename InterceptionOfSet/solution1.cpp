#include <iostream>
#include <vector>

using namespace std;

// Set interception problem
// Problem 1: Sorted Set
// Time Complexity O(n+m)
int main() {
    int x, y;
    cin >> x >> y;
    int a[x], b[y];
    for (int i=0; i<x; i++) cin >> a[i];
    for (int i=0; i<y; i++) cin >> b[i];
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