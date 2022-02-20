//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ld dp[1001][10001];
bool cover[1001];
bool coverseg[1001];

struct Cloud {
    ll start;
    ll end;
    ld ev;
    ld amount;
    Cloud() : start(0), end(0), ev(0), amount(0) {}
    Cloud(ll a, ll b, ld c, ld d) : start(a), end(b), ev(c), amount(d) {}
};

bool comp(const pair<ll, pair<ll, ll>> &l, const pair<ll, pair<ll, ll>> &r) {
    if (l.second.first == r.second.first) {
        return l.first > r.first;
    }
    return l.second.first < r.second.first;
}

int main() {
    fast;
    ll d, t, c, r;
    cin >> d >> t >> c >> r;
    vector<Cloud> clouds(c);
    for (int i = 0; i < c; ++i) {
        ll a, b;
        ld c, d;
        cin >> a >> b;
        cin >> c >> d;
        clouds[i] = Cloud(a, b, c, d);
    }
    vector<pair<ll, ll>> roofs(r);

    for (int i = 0; i < r; ++i) {
        ll a, b;
        cin >> a >> b;
        roofs[i] = {a, b};
    }

    vector<pair<ll, pair<ll, ll>>> sweep;
    for (int i = 0; i < clouds.size(); ++i) {
        sweep.push_back({0, {clouds[i].start, i}});
        sweep.push_back({1, {clouds[i].end, i}});
    }
    sort(sweep.begin(), sweep.end(), comp);

    vector<ld> erain(t+1, 0);
    ld currsum = 0;
    int idx = -1;
    for (int i = 0; i <= t; ++i) {
        while (idx + 1 < sweep.size() && (sweep[idx + 1].second.first <= i)) {
            ++idx;
            Cloud &cloud = clouds[sweep[idx].second.second];
            if (sweep[idx].first) {
                currsum -= cloud.amount * cloud.ev;
            }
            else {
                currsum += cloud.amount * cloud.ev;
            }
        }
        erain[i] = currsum;
    }

    cover[0] = true;
    for (auto roof : roofs) {
        for (int j = roof.first; j <= roof.second; ++j) {
            cover[j] = true;
            if (j > roof.first) {
                coverseg[j-1] = true;
            }
        }
    }

    // vector<vector<ld>> dp(d+1, vector<ld>(t+1, 0));
    ld curr = 0;
    for (int j = t; j >= 0; --j) {
        curr += (1 - (int) cover[d]) * erain[j];
        dp[d][j] = curr;
    }
    for (int i = d-1; i >= 0; --i) {
        int diff = d - i;
        dp[i][t-diff + 1] = 1000000000000;
        for (int j = t-diff; j >= i; --j) {
            dp[i][j] = min((1 - (int) cover[i]) * erain[j] + dp[i][j+1], (1 - (int) coverseg[i]) * erain[j] + dp[i+1][j+1]);
        }
    }

    cout << setprecision(10);
    cout << dp[0][0] << endl;
}