#include <bits/stdc++.h>

using namespace std;

// O(n+m)
int main() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<pair<string,string>> x(n1);
    vector<pair<string,string>> y(n2);
    pair<string,string> r1, r2;
    string start, end;
    for (int i=0; i<n1; i++) {
        cin >> start >> end;
        x[i] = make_pair(start,end);
    }
    cin >> start >> end;
    r1 = make_pair(start,end);
    for (int i=0; i<n2; i++) {
        cin >> start >> end;
        y[i] = make_pair(start,end);
    }
    cin >> start >> end;
    r2 = make_pair(start,end);

    start = get<0>(r1) > get<0>(r2) ? get<0>(r1) : get<0>(r2);
    end = get<1>(r1) < get<1>(r2) ? get<1>(r1) : get<1>(r2);
    int i=0, j=0;
    vector<pair<string,string>> solution;
    while (i < n1 || j < n2) {
        // We remove any particular timelapse that happens before our start time and update our start time
        while ((i < n1 && x[i].first <= start) || (j < n2 && y[j].first <= start)) {
            while (i < n1 && x[i].first <= start) {
                start = x[i].second > start ? x[i].second : start;
                i++;
            }
            while (j < n2 && y[j].first <= start) {
                start = y[j].second > start ? y[j].second : start;
                j++;
            }
        }
        if (i < n1 && j < n2) {
            // In here, it's guarenteed that our nearest working time will be our end time for one of our solution with the start time
            // and here we updated our start time to the end of the end working time
            pair<string,string> temp1 = x[i].first > y[j].first ? y[j] : x[i];
            solution.push_back(make_pair(start,temp1.first));
            start = temp1.second;
        } else if (i < n1 || j < n2) {
            pair<string,string> temp1 = i < n1 ? x[i] : y[j];
            solution.push_back(make_pair(start,temp1.first));
            start = temp1.second;
        }
    }
    // If we already check every timelapse, we need to make sure that there is no free time left or there is 1 last solution
    if (start != end) {
        solution.push_back(make_pair(start,end));
    }
    // We show our solution here
    for (int i=0; i<solution.size(); i++) cout << "[" << solution[i].first << "," << solution[i].second << "]" << endl;
}