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

int testnum = 0;

ld dot(pair<ld, ld> a, pair<ld, ld> b) {
    return (a.first * b.first) + (a.second * b.second);
}

pair<ld, ld> sub(pair<ld, ld> a, pair<ld, ld> b) {
    return {a.first - b.first, a.second - b.second};
}

ld len(pair<ld, ld> a, pair<ld, ld> b) {
    cout << a.first << " " << a.second << " " << b.first << " " << b.second  << endl;
    return sqrtl((a.second - b.second) * (a.second - b.second) + (a.first - b.first) * (a.first - b.first));
}

ld perim(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
    return len(a, b) + len(b, c) + len(c, a);
}

ld perim(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c, pair<ld, ld> d) {
    return len(a, b) + len(b, c) + len(c, d) + len(d, a);
}

ld area(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
    return abs((a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) / 2.);
}

ld inLine(pair<ld, ld> star, pair<ld, ld> a, pair<ld, ld> b) {
    return abs(len(star, a) + len(star, b) - len(a, b)) < 0.000001;
}

bool inTriangle (pair<ld, ld> star, pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
    ld as = area(a, b, c);
    ld a1 = area(star, a, b);
    ld a2 = area(star, b, c);
    ld a3 = area(star, a, c);

    return (abs(as - (a1 + a2 + a3)) < 0.000001);
}

ld inLinePerim(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> k, const vector<pair<ld, ld>> &coords) {
    ld res = -1;
    ld s = dot(sub(b, a), sub(k, a));
    for (int l = 0; l < coords.size(); ++l) {
        ld d = dot(sub(b, a), sub(coords[l], a));
        if (abs(d) > 0.000001 && d/abs(d) != s/abs(s)) {
            if (res == -1) {
                res = perim(a, k, b, coords[l]);
            }
            else {
                res = min(res, perim(a, k, b, coords[l]));
            }
        }
    }
    return res;
}


int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        int n;
        cin >> n;
        vector<pair<ld, ld>> coords;
        pair<ld, ld> star;
        for (int i = 0; i < n; ++i) {
            ld a, b;
            cin >> a >> b;
            coords.push_back({a, b});
        }
        cin >> star.first >> star.second;

        ld res = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; j < n; ++j) {
                    if (inLine(coords[i], coords[j], coords[k])) {
                        continue;
                    }


                    if (inLine(star, coords[i], coords[j])) {
                        ld tempres = inLinePerim(coords[i], coords[j], coords[k], coords);
                        if (tempres != -1) {
                            if (res == -1) res = tempres;
                            else res = min(res, tempres);
                        }
                    }
                    else if (inLine(star, coords[j], coords[k])) {
                        ld tempres = inLinePerim(coords[j], coords[k], coords[i], coords);
                        if (tempres != -1) {
                            if (res == -1) res = tempres;
                            else res = min(res, tempres);
                        }
                    }
                    else if (inLine(star, coords[k], coords[i])) {
                        ld tempres = inLinePerim(coords[i], coords[k], coords[j], coords);
                        if (tempres != -1) {
                            if (res == -1) res = tempres;
                            else res = min(res, tempres);
                        }
                    }
                    else if (inTriangle(star, coords[i], coords[j], coords[k])) {
                        if (res == -1) {
                            res = perim(coords[i], coords[j], coords[k]);
                        }
                        else {
                            res = min(res, perim(coords[i], coords[j], coords[k]));
                        }
                    }
                }
            }
        }
        cout << setprecision(20);
        if (res == -1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << res << endl;
        }



    }
}