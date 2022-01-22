//Competition #:
//Problem #: G
//Accepted: 

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
    int n, k;
    cin >> n >> k;
    vector<ll> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    vector<ll> res(n, 0);

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (r[a] > r[b]) {
            --res[a];
        }
        else if (r[b] > r[a]) {
            --res[b];
        }
    }

    vector<pair<ll, int>> scores;
    for (int i = 0; i < n; ++i) {
        scores.push_back({r[i], i});
    }

    sort(scores.begin(), scores.end());

    int lesser = 0;
    for (int i = 1; i < n; ++i) {
        if (scores[i].first > scores[i-1].first) {
            lesser = i;
        }

        res[scores[i].second] += lesser;
    }

    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;


}