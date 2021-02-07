//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
ld PI = 3.14159265358979323846;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

struct compare{
    bool operator() (pair<ld, pair<ll, bool>> lhs, pair<ld, pair<ll, bool>> rhs) {
        if (abs(lhs.first - rhs.first) < 0.0000001) {
            if (lhs.second.second && !rhs.second.second) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (lhs.first < rhs.first) {
            return true;
        }
        return false;
    }
};

int main() {
    fast;
    ll n;
    cin >> n;
    vector<ld> x(n), y(n), alpha(n), theta(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> alpha[i] >> theta[i];
    }

    ll extraIndex = n;

    vector<pair<ld, pair<ll, bool>>> coords;
    for (int i = 0; i < n; ++i) {
        ld beta1 = alpha[i] - theta[i] / 2;

        ld a = 1;
        ld b = 2*x[i]*cos(beta1) + 2*y[i]*sin(beta1);
        ld c = x[i]*x[i] + y[i]*y[i] - 1;

        ld k = (-b + sqrt(b*b - 4*a*c))/2;
        ld newX = x[i] + k*cos(beta1);
        ld newY = y[i] + k*sin(beta1);

        ld angle1 = atan2(newY, newX);

        ld beta2 = alpha[i] + theta[i] / 2;

        a = 1;
        b = 2*x[i]*cos(beta2) + 2*y[i]*sin(beta2);
        c = x[i]*x[i] + y[i]*y[i] - 1;

        k = (-b + sqrt(b*b - 4*a*c))/2;
        newX = x[i] + k*cos(beta2);
        newY = y[i] + k*sin(beta2);

        ld angle2 = atan2(newY, newX);

        if (angle1 > angle2) {
            coords.push_back({angle1 - 2*PI, {extraIndex+1, true}});
            coords.push_back({angle2, {extraIndex+1, false}});
            angle2 += 2*PI;
            extraIndex++;
        }


        coords.push_back({angle1, {i, true}});
        coords.push_back({angle2, {i, false}});
    }

    sort(coords.begin(), coords.end(), compare());
    ld start = coords[0].first;

    unordered_set<ll> active;
    for (int i = 0; i < coords.size(); ++i) {
        if (coords[i].second.second) {
            active.insert(coords[i].second.first);
        }
        else {
            active.erase(coords[i].second.first);
            if (coords[i].first + 0.0000001 >= start + 2*PI) {
                cout << "YES" << endl;
                return 0;
            }
        }

        if (active.empty()) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}