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
        return l.first < r.first;
    }
    return l.second.first < r.second.first;
}

ld recurse(int dist, int time, const vector<ld> &erain, const vector<bool> &cover, vector<vector<ld>> &dp) {
    if (time >= erain.size() - 1) {
        if (dist >= cover.size() - 1) {
            dp[dist][time] = (1-cover.back()) * erain.back();
            return (1-cover.back()) * erain.back();
        }
        else {
            dp[dist][time] = 1000000000000;
            return 1000000000000;
        }
    }
    if (dist >= cover.size() - 1) {
        if (cover.back()) {
            dp[dist][time] = 0;
            return 0;
        }
        else {
            dp[dist][time] = erain[time] + recurse(dist, time + 1, erain, cover, dp);
            return erain[time] + recurse(dist, time + 1, erain, cover, dp);
        }
    }


    if (dp[dist][time] != -1) {
        return dp[dist][time];
    }

    if (cover[dist]) {
        dp[dist][time] = min(recurse(dist, time+1, erain, cover, dp), recurse(dist+1, time+1, erain, cover, dp));
    }
    else {
        dp[dist][time] = erain[time] + min(recurse(dist, time+1, erain, cover, dp), recurse(dist+1, time+1, erain, cover, dp));
    }

    return dp[dist][time];
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
    ld currnum = 0;
    int idx = -1;
    for (int i = 0; i <= t; ++i) {
        while (idx + 1 < sweep.size() && (sweep[idx + 1].second.first < t || (sweep[idx+1].second.first == t && !sweep[idx+1].first))) {
            ++idx;
            Cloud &cloud = clouds[sweep[idx].second.second];
            if (sweep[idx+1].first) {
                --currnum;
                currsum -= cloud.amount * cloud.ev;
            }
            else {
                ++currnum;
                currsum += cloud.amount * cloud.ev;
            }
        }
        erain[i] = currnum ? currsum / currnum : 0;
    }

    vector<bool> cover(d+1, 0);
    cover[0] = true;
    for (auto roof : roofs) {
        for (int j = roof.first; j <= roof.second; ++j) {
            cover[j] = true;
        }
    }

    vector<vector<ld>> dp(d+1, vector<ld>(t+1, -1));
    cout << setprecision(10);
    ld res = recurse(0, 0, erain, cover, dp);
    for (auto i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << res << endl;
}