#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<vector<int>> triangle;
	// Layer 1: 0 -> 0 or 1
	// Layer 2: 0 -> 0 or 1 && 1 -> 1 or 2
	int max_sum = 0;
int sum = 0;
	int pointer = 0;
	if (triangle.size() >= 1) {
		// Greedy: not optimal solution
		// need to improve later
sum = triangle[0][pointer];
for (int i=1; i<triangle.size(); i++) {
		int max_val = 
triangle[i][pointer] > Triangle[i][pointer+1] 
? triangle[i][pointer] : triangle[i][pointer+1];
sum += max_val;
	}
	cout << sum << endl;
} else {
	cout << 0 << endl;
}
}
