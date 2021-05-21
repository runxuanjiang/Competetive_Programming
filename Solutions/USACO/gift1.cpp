/*
ID: runxuan1
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int n;
    fin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        fin >> names[i];
    }

    unordered_map<string, pair<int, int>> money;

    for (int i = 0; i < n; ++i) {
        string name;
        fin >> name;
        int m, people;
        fin >> m >> people;
        if (people > 0) m /= people;
        money[name].first = m * people;

        for (int j = 0; j < people; ++j) {
            string recip;
            fin >> recip;
            if (money.find(recip) == money.end()) {
                money[recip] = {0, 0};
            }
            money[recip].second += m;
        }
        
    }

    for (auto i : names) {
        fout << i << " " << money[i].second - money[i].first << endl;
    }

}