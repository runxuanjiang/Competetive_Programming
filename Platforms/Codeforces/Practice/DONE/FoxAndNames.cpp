//Competition #: Codeforces Round 290
//Problem #: C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const char A = 'a';

bool recurse(vector<vector<int>> &dag, vector<short> &visited, vector<int>& sorted, int i) {
    if(visited[i] == 2) return true;
    if (visited[i] == 1) return false;

    visited[i] = 1;
    for (auto child : dag[i]) {
        if (!recurse(dag, visited, sorted, child)) {
            return false;
        }
    }
    sorted.push_back(i);
    visited[i] = 2;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > dag(26);
    vector<short> visited(26, 0);

    string first;
    string second;
    cin >> first;
    for (int i = 0; i < n-1; ++i) {
        cin >> second;
        for (int j = 0; j < min(first.length(), second.length()); ++j) {
            if (first[j] != second[j]) {
                dag[first[j] - A].push_back(second[j] - A);
                break;
            }
            if (j == min(first.length(), second.length()) - 1 && first.length() > second.length()) {
                cout << "Impossible";
                return 0;
            }
        }
        first = second;
    }
    vector<int> sorted;
    bool impossible = false;
    for (int i = 0; i < dag.size(); ++i) {
        if (!recurse(dag, visited, sorted, i)) {
            impossible = true;
            break;
        }
    }
    if (impossible) cout << "Impossible";
    else {
        for (auto i = sorted.rbegin(); i != sorted.rend(); ++i) {
            char out = A + *i;
            cout << out;
        }
    }
}