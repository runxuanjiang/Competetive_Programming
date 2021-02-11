//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

long double dist(long double x1, long double y1, long double x2, long double y2) {
    long double dist1 = (x1 -x2) * (x1 - x2);
    long double dist2 = (y1 - y2) * (y1 - y2);
    return sqrt(dist1 + dist2);
}

struct Comp{
    bool operator() (pair<long double, pair<int, int>> l, pair<long double, pair<int, int>> r) {
        if (l.first == r.first) {
            if (l.second.first == r.second.first) {
                return l.second.second < r.second.second;
            }
            else {
                return l.second.first < r.second.first;
            }
        }
        else {
            return l.first < r.first;
        }
    }
};

int main() {
    fast;
    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<long double, long double>> judge(n), feather(m), tar(p);
    for (int i = 0; i < n; ++i) {
        long double a, b;
        cin >> a >> b;
        judge[i] = {a, b};
    }
    for (int i = 0; i < m; ++i) {
        long double a, b;
        cin >> a >> b;
        feather[i] = {a, b};
    }
    for (int i = 0; i < p; ++i) {
        long double a, b;
        cin >> a >> b;
        tar[i] = {a, b};
    }

    vector<pair<long double, pair<int, int>>> fEdges;
    vector<pair<long double, pair<int, int>>> tEdges;
    unordered_set<int> tarSeen, featherSeen, judgeSeenF, judgeSeenT;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fEdges.push_back({dist(judge[i].first, judge[i].second, feather[j].first, feather[j].second), {i, j}});
        }
        for (int j = 0; j < p; ++j) {
            tEdges.push_back({dist(judge[i].first, judge[i].second, tar[j].first, tar[j].second), {i, j}});
        }
    }

    sort(fEdges.begin(), fEdges.end(), Comp());
    sort(tEdges.begin(), tEdges.end(), Comp());

    long double res = 0;
    // for (auto edge : fEdges) {
    //     cout << edge.first << " " << edge.second.first << " " << edge.second.second << endl;
    // }
    // cout << endl << endl;
    // for (auto edge : tEdges) {
    //     cout << edge.first << " " << edge.second.first << " " << edge.second.second << endl;
    // }

    for (auto edge : fEdges) {
        if (judgeSeenF.size() == n) break;
        if (judgeSeenF.find(edge.second.first) == judgeSeenF.end() && featherSeen.find(edge.second.second) == featherSeen.end()) {
            judgeSeenF.insert(edge.second.first);
            featherSeen.insert(edge.second.second);
            res += edge.first;
            //cout << edge.first << endl;
        }
    }
    for (auto edge: tEdges) {
        if (judgeSeenT.size() == n) break;
        if (judgeSeenT.find(edge.second.first) == judgeSeenT.end() && tarSeen.find(edge.second.second) == tarSeen.end()) {
            judgeSeenT.insert(edge.second.first);
            tarSeen.insert(edge.second.second);
            res += edge.first;
            //cout << edge.first << endl;
        }
    }
    cout << fixed;
    cout << setprecision(6);
    cout << res;
}