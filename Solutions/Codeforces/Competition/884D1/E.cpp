//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)



/*
 * Orientations:
 * -1: unknown orientation (node not visited before)
 * 0: "default" orientation
 * 1: "flipped" orientation
*/
bool dfs(ll node, bool orientation, const vector<vector<pair<size_t, bool>>> &graph, vector<int> &orientations) {
    
    orientations[node] = orientation;
    for (const auto &child : graph[node]) {
        bool target_orientation = (child.second ? !orientation : orientation);
        if (orientations[child.first] == -1) {
            if (!dfs(child.first, target_orientation, graph, orientations)) {
                return false;
            }
        }
        else {
            if (target_orientation != orientations[child.first]) {
                return false;
            }
        }

    }
    return true;

}

int main() {
    fast;
    tests {
        ll n, m, k;
        cin >> n >> m >> k;

        vector<vector<pair<size_t, bool>>> row_graph(n);
        vector<vector<pair<size_t, bool>>> col_graph(m);

        vector<pair<pair<size_t, size_t>, bool>> constraints;

        for (size_t _ = 0; _ < k; ++_) {
            size_t x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1;
            --y1;
            --x2;
            --y2;

            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }

            bool orientation = (y1 < y2);
            constraints.push_back({{min(x1, x2), min(y1, y2)}, orientation});
        }

        // print out all constraints for debugging
        // for (const auto &constraint : constraints) {
        //     cerr << "Constraint: (" << constraint.first.first << ", " << constraint.first.second << ") " 
        //          << (constraint.second ? "flipped" : "default") << endl;
        // }



        bool good = true;
        for (int i = 0; i < constraints.size(); ++i) {
            for (int j = i+1; j < constraints.size(); ++j) {
                if (constraints[i].first.first == constraints[j].first.first) {
                    size_t col1 = constraints[i].first.second;
                    size_t col2 = constraints[j].first.second;
                    bool orientation_flipped = (constraints[i].second != constraints[j].second);
                    col_graph[col1].push_back({col2, orientation_flipped});
                    col_graph[col2].push_back({col1, orientation_flipped});
                }
                if (constraints[i].first.second == constraints[j].first.second) {
                    size_t row1 = constraints[i].first.first;
                    size_t row2 = constraints[j].first.first;
                    bool orientation_flipped = (constraints[i].second != constraints[j].second);
                    row_graph[row1].push_back({row2, orientation_flipped});
                    row_graph[row2].push_back({row1, orientation_flipped});
                }
                if (constraints[i].first.first == constraints[j].first.first && constraints[i].first.second == constraints[j].first.second) {
                    // contradicting constraints detected
                    good = false;
                }
            }
        }

        // print out graphs for debugging
        // cerr << "Row graph:" << endl;
        // for (size_t i = 0; i < row_graph.size(); ++i) {
        //     cerr << i << ": ";
        //     for (const auto &child : row_graph[i]) {
        //         cerr << "(" << child.first << ", " << (child.second ? "flipped" : "default") << ") ";
        //     }
        //     cerr << endl;
        // }
        // cerr << "Column graph:" << endl;
        // for (size_t i = 0; i < col_graph.size(); ++i) {
        //     cerr << i << ": ";
        //     for (const auto &child : col_graph[i]) {
        //         cerr << "(" << child.first << ", " << (child.second ? "flipped" : "default") << ") ";
        //     }
        //     cerr << endl;
        // }

        if (good) {
            vector<int> orientations(n, -1);
            for (size_t i = 0; i < n; ++i) {
                if (orientations[i] == -1) {
                    if (!dfs(i, 0, row_graph, orientations)) {
                        good = false;
                        break;
                    }
                }
            }
        }

        if (good) {
            vector<int> orientations(m, -1);
            for (size_t i = 0; i < m; ++i) {
                if (orientations[i] == -1) {
                    if (!dfs(i, 0, col_graph, orientations)) {
                        good = false;
                        break;
                    }
                }
            }
        }

        cout << (good ? "YES" : "NO") << endl;

    }
}