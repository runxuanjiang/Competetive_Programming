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

struct Data{
    ll max;
    ll leaves;
    ll remaining;

    Data(ll a, ll b, ll c) {
        max = a, leaves = b, remaining = c;
    }
};

Data recurse(ll node, vector<unordered_set<ll>> &cities, vector<ll> &people) {
    Data res(0, 0, 0);

    vector<Data> cmax;
    
    for (auto child : cities[node]) {
        cmax.push_back(recurse(child, cities, people));
        res.max = max(res.max, cmax.back().max);
        res.leaves += cmax.back().leaves;
    }
    if (cmax.empty()) return Data(people[node], 1, 0);
    for (auto d : cmax) {
        res.remaining += (d.remaining + (res.max - d.max) * d.leaves);
    }
    ll subtract = min(res.remaining, people[node]);
    people[node] -= subtract;
    res.remaining -= subtract;
    if (people[node] > 0) {
        ll add;
        if (people[node] % res.leaves == 0) {
            add = (people[node] / res.leaves);
            res.max += add;
        }
        else {
            add = (people[node] / res.leaves + 1);
            res.max += add;
            res.remaining += (add * res.leaves - people[node]);
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<unordered_set<ll>> cities(n);
    for (ll i = 1; i < n; ++i) {
        ll p;
        cin >> p;
        p-= 1;
        cities[p].insert(i);
    }
    vector<ll> people(n);
    for (ll i = 0; i < n; ++i) {
        cin >> people[i];
    }

    Data res = recurse(0, cities, people);
    cout << res.max;
}