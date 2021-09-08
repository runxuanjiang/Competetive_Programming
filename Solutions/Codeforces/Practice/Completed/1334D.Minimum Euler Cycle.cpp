//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

vector<ll> getSegment(ll id, ll n) {
    if (id == n-1) {
        return {1};
    }
    int curr = id+1;
    vector<ll> res;
    for (int i = curr+1; i <= n; ++i) {
        res.push_back(curr);
        res.push_back(i);
    }
    return res;
}

int main() {
    fast;
    tests {
        ll n, l, r;
        cin >> n >> l >> r;

        vector<ll> segments;
        ll curr = 2 * (n-1);
        while (curr > 0) {
            if (segments.empty()) {
                segments.push_back(curr);
            }
            else {
                segments.push_back(curr + segments.back());
            }

            curr -= 2;
        }
        segments.push_back(segments.back() + 1);

        ll start = lower_bound(segments.begin(), segments.end(), l) - segments.begin();
        ll end = lower_bound(segments.begin(), segments.end(), r) - segments.begin();

        if (start == end) {
            vector<ll> seg = getSegment(start, n);
            ll low = seg.size() - (segments[start] - l + 1);
            ll high = seg.size() - (segments[start] - r + 1);
            for (int j = low; j <= high; ++j) {
                cout << seg[j] << " ";
            }
        }
        else {
            for (int i = start; i <= end; ++i) {
                if (i == start) {
                    vector<ll> seg = getSegment(start, n);
                    ll low = seg.size() - (segments[i] - l + 1);
                    for (int j = low; j < seg.size(); ++j) {
                        cout << seg[j] << " ";
                    }
                }
                else if (i != end) {
                    vector<ll> seg = getSegment(i, n);
                    for (auto j : seg) {
                        cout << j << " ";
                    }
                }
                else {
                    vector<ll> seg = getSegment(end, n);
                    ll high = seg.size() - (segments[i] - r + 1);
                    for (int j = 0; j <= high; ++j) {
                        cout << seg[j] << " ";
                    }
                }
            }
        }
        cout << endl;


    }
}