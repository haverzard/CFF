#include <bits/stdc++.h>

using namespace std;

// BFS to find the number of new connections we need to make
// to connect all the nodes
int bfsConn(unordered_map<string,vector<string>> &adj, vector<string> &nodes, int size) {
    unordered_map<string,bool> visited;
    queue<string> x;
    int i = 0, counts = 0;
    x.push(nodes[i]); i++;
    while (i < size) {
        while (!x.empty()) {
            string curr = x.front(); x.pop();
            for (int i=0; i<adj[curr].size(); i++) {
                if (!visited[adj[curr][i]]) {
                    visited[adj[curr][i]] = true;
                    x.push(adj[curr][i]);
                }
            }
        }
        while (i < size && visited[nodes[i]]) i++;
        if (i < size) {
            x.push(nodes[i]);
            i++;
            counts++;
        }
    }
    return counts;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    unordered_map<string,vector<string>> b;
    for (int i=0; i<k; i++) {
        string x, y;
        cin >> x >> y;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    cout << "The number of connections we need to make to make all of these nodes connected is "
        << bfsConn(b,a,n) << endl;
}