//Competition #:
//Problem #: D
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll s, t;
    cin >> s >> t;
    --s;
    --t;
    unordered_map<ll, vector<ll>> num2idx;
    for (int i = 0; i < n; ++i) {
        num2idx[a[i]].push_back(i);
    }


    vector<vector<ll>> idx2div(300001);
    vector<vector<ll>> div2idx(300001);
    unordered_set<ll> primes;
    for (int i = 2; i <= 300000; ++i) {
        if (idx2div[i].empty()) {
            primes.insert(i);
            for (int j = 1; j*i <= 300000; ++j) {
                idx2div[i*j].push_back(i);
                for (auto idx : num2idx[j*i]) {
                    div2idx[i].push_back(idx);
                }
            }
        }
    }

    if (s == t) {
        cout << 1 << endl;
        cout << s+1 << endl;
    }
    else {
        vector<ll> idxparent(n, -1);
        unordered_map<ll, ll> divparent;

        unordered_set<ll> curr, next;
        idxparent[s] = -2;
        curr.insert(s);
        while (!curr.empty()) {
            for (auto i : curr) {
                for (auto div : idx2div[a[i]]) {
                    if (divparent.find(div) == divparent.end()) {
                        next.insert(div);
                        divparent[div] = i;
                    }
                }
            }

            swap(curr, next);
            next = {};
            for (auto i : curr) {
                for (auto idx : div2idx[i]) {
                    if (idxparent[idx] == -1) {
                        next.insert(idx);
                        idxparent[idx] = i;
                    }
                }
            }

            swap(curr, next);
            next = {};
            if (idxparent[t] != -1) {
                break;
            }
        }

        if (idxparent[t] == -1) {
            cout << -1 << endl;
        }
        else {
            vector<ll> path = {t};
            ll curr = t;
            while (curr != s) {
                curr = divparent[idxparent[curr]];
                path.push_back(curr);
            }

            cout << path.size() << endl;
            for (auto i = path.rbegin(); i != path.rend(); ++i) {
                cout << *i + 1 << " ";
            }
            cout << endl;
        }


    }









    
}