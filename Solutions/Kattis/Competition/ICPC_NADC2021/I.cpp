//Competition #:
//Problem #: I
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

vector<int> ALLHOUR(24);
vector<int> ALLMIN(60);

vector<int> parse(string s) {
    s.insert(0, ",");
    string temp = "";
    int top = -1;
    vector<int> res;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '-') {
            top = stoi(s.substr(i+1));
            s.erase(i);
        }
        if (s[i] == ',') {
            int num = stoi(s.substr(i+1));
            s.erase(i);

            if (top != -1) {
                for (int j = num; j <= top; ++j) {
                    res.push_back(j);
                }
            }
            else {
                res.push_back(num);
            }
            top = -1;
        }
    }
    return res;
}

int main() {
    fast;
    for (int i = 0; i < 24; ++i) {
        ALLHOUR[i] = i;
    }
    for (int i = 0; i < 60; ++i) {
        ALLMIN[i] = i;
    }
    int n;
    cin >> n;
    unordered_map<int, unordered_map<int, unordered_set<int>>> seen;
    int tasks = 0;
    int starts = 0;
    for (int i = 0; i < n; ++i) {
        string h, m, s;
        cin >> h >> m >> s;
        int hour = 0, min = 0, sec = 0;
        vector<int> hours, mins, secs;
        if (h == "*") {
            hour = 24;
            hours = ALLHOUR;
        }
        else {
            hours = parse(h);
            hour = hours.size();
        }

        if (m == "*") {
            min = 60;
            mins = ALLMIN;
        }
        else {
            mins = parse(m);
            min = mins.size();
        }

        if (s == "*") {
            sec = 60;
            secs = ALLMIN;
        }
        else {
            secs = parse(s);
            sec = secs.size();
        }

        tasks += (hour*min*sec);
        for (auto hr : hours) {
            for (auto mn : mins) {
                for (auto sc : secs) {
                    if (seen[hr][mn].find(sc) == seen[hr][mn].end()) {
                        seen[hr][mn].insert(sc);
                        ++starts;
                    }
                }
            }
        }
    }
    cout << starts << " " << tasks << endl;
}