#include <bits/stdc++.h>

using namespace std;

// BFS to find the cost only
int bfsCost(unordered_map<string,vector<pair<string,int>>> &adj, string &init, string &target) {
    unordered_map<string,bool> visited;
    queue<pair<string,int>> x;
    x.push(make_pair(init,0));
    while (!x.empty()) {
        pair<string,int> curr = x.front(); x.pop();
        for (int i=0; i<adj[curr.first].size(); i++) {
            if (!visited[adj[curr.first][i].first]) {
                visited[adj[curr.first][i].first] = true;
                x.push(make_pair(adj[curr.first][i].first, curr.second+adj[curr.first][i].second));
            }
        }
        if (curr.first == target) {
            return curr.second;
        }
    }
    return -1;
}

// BFS to find the cost & path
pair<string,int> bfs(unordered_map<string,vector<pair<string,int>>> &adj, string &init, string &target) {
    unordered_map<string,bool> visited;
    queue<tuple<string,int,string>> x;
    x.push(make_tuple(init,0,init));
    while (!x.empty()) {
        auto [curr, cost, path] = x.front(); x.pop();
        if (curr != target) {
            for (int i=0; i<adj[curr].size(); i++) {
                if (!visited[adj[curr][i].first]) {
                    visited[adj[curr][i].first] = true;
                    x.push(make_tuple(adj[curr][i].first, 
                        cost+adj[curr][i].second, 
                        path+"-"+adj[curr][i].first));
                }
            }
        } else {
            return make_pair(path,cost);
        }
    }
    return make_pair("",-1);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    unordered_map<string,vector<pair<string,int>>> b;
    for (int i=0; i<k; i++) {
        string x, y;
        int cost;
        cin >> x >> y >> cost;
        b[x].push_back(make_pair(y,cost));
        b[y].push_back(make_pair(x,cost));
    }
    auto [path, cost] = bfs(b,a[0],a[n-1]);
    if (cost < 0) {
        cout << "There is no path to the target" << endl;
    } else {
        cout << "The path is " << path << " with cost of " << cost << endl;
    }
}