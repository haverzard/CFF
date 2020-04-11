#include <bits/stdc++.h>

using namespace std;

// DFS to find the cost & path
// DFS FIFO
pair<string,int> dfs(unordered_map<string,vector<pair<string,int>>> &adj, string &init, string &target) {
    unordered_map<string,bool> visited;
    stack<tuple<string,int,string>> x;
    x.push(make_tuple(init,0,init));
    while (!x.empty()) {
        auto [curr, cost, path] = x.top(); x.pop();
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
    auto [path, cost] = dfs(b,a[0],a[n-1]);
    
    if (cost < 0) {
        cout << "There is no path to the goal" << endl;
    } else {
        cout << "The path to the goal is " << path << " with the cost of " << cost << endl;   
    }
}