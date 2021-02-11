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

int lowest(vector<int> &v, int k) {
    int cmin = v[0];
    unordered_set<int> track;
    multiset<int> curr;

    int start = 0;
    int end = k-1;
    for (int i = 0; i <= end; ++i) {
        cmin = min(cmin, v[i]);
        track.insert(v[i]);
        curr.insert(v[i]);
    }

    ++start;
    ++end;

    while (end < v.size()) {
        bool found = false;
        curr.erase(curr.lower_bound(v[start-1]));
        curr.insert(v[end]);
        for (auto i : curr) {
            if (track.find(i) != track.end()) {
                found = true;
                cmin = i;
                break;
            }
        }
        if (!found) return -1;

        ++start;
        ++end;
    }

    return cmin;

}

int main() {
    fast;
    tests{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        for (int i = 1; i <= n; ++i) {
            cout << lowest(v, i) << " ";
        }

        cout << endl;


    }
}