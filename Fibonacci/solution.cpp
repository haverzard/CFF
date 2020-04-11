#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a=1, b=1, count=2;
    cin >> n;
    // Assume n input is valid for fibonacci
    while (count != n) {
        int temp = a;
        a = b;
        b = a + temp;
        count++;
    }
    cout << "Fibonacci-" << n << " is " << b << endl;
}