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

int numtests = 0;

int main() {
    fast;
    tests {
        ++numtests;
        cout << "Case #" << numtests << ": ";

        int n, m;
        cin >> n >> m;
        int a, b;
        cin >> a >> b;

        int smin = n + m - 1;
        int smax = 1000 * smin;

        if (a < smin || b < smin || a > smax || b > smax) {
            cout << "Impossible" << endl;
            continue;
        }

        int maxSteps = min(a, b);
        int tot = n + m - 1;
        int last = abs(n - m) + 2;
        int prev = tot - last;

        ld avgPrev = (ld) (maxSteps + 2000 - 1000 * last) / (ld) (2 + prev);
        if (avgPrev < 1) {
            avgPrev = 1;
        }

        ld avgLast = ((ld) maxSteps - (avgPrev * (ld) prev)) / (ld) last;
        ll extra = lround((avgPrev - floorl(avgPrev)) * (ld) prev + (avgLast - floorl(avgLast)) * (ld) last);
        ll actualPrev = lround(floorl(avgPrev));
        ll actualLast = lround(floorl(avgLast));

        vector<vector<ll>> res(n, vector<ll>(m, 1000));

        if (a > b) {
            vector<pair<ll, ll>> corners;
            int x = 0, y = m-1;
            bool vert = true;
            while (x < n-1 && y > 0) {
                res[x][y] = actualPrev;
                if (!vert) {
                    corners.push_back({x, y});
                }
                if (vert) {
                    ++x;
                }
                else {
                    --y;
                }
                vert = !vert;
            }
            corners.push_back({x, y});
            while (x < n-1 || y > 0) {
                res[x][y] = actualLast;
                if (x < n-1) {
                    ++x;
                }
                if (y > 0) {
                    --y;
                }
            }
            res[x][y] = actualLast;

            int cornerIdx = corners.size() - 1;
            while (extra--) {
                res[corners[cornerIdx].first][corners[cornerIdx].second]++;
                cornerIdx = (cornerIdx - 1 + corners.size()) % (int) corners.size();
            }

            ll sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += res[0][j];
            }
            for (int i = 1; i < n; ++i) {
                sum += res[i][m-1];
            }

            if (sum < a) {
                cout << "Impossible" << endl;
                continue;
            }

            ll diff = sum - a;
            ll pathSize = n + m - 3;
            ll pathBlock = diff / pathSize;
            ll extra = diff % pathSize;

            for (int j = 0; j < m-1; ++j) {
                res[0][j] -= pathBlock;
                if (extra) {
                    --extra;
                    --res[0][j];
                }
            }
            for (int i = 2; i < n; ++i) {
                res[i][m-1] -= pathBlock;
                if (extra) {
                    --extra;
                    --res[i][m-1];
                }
            }
        }
        else {
            vector<pair<ll, ll>> corners;
            int x = 0, y = 0;
            bool vert = true;
            while (x < n-1 && y < m-1) {
                res[x][y] = actualPrev;
                if (!vert) {
                    corners.push_back({x, y});
                }
                if (vert) {
                    ++x;
                }
                else {
                    ++y;
                }
                vert = !vert;
            }
            corners.push_back({x, y});
            while (x < n-1 || y < m-1) {
                res[x][y] = actualLast;
                if (x < n-1) {
                    ++x;
                }
                if (y < m-1) {
                    ++y;
                }
            }
            res[x][y] = actualLast;

            int cornerIdx = corners.size() - 1;
            while (extra--) {
                res[corners[cornerIdx].first][corners[cornerIdx].second]++;
                cornerIdx = (cornerIdx - 1 + corners.size()) % (int) corners.size();
            }

            ll sum = 0;
            for (int j = 1; j < m; ++j) {
                sum += res[0][j];
            }
            for (int i = 0; i < n; ++i) {
                sum += res[i][0];
            }

            if (sum < b) {
                cout << "Impossible" << endl;
                continue;
            }

            ll diff = sum - b;
            ll pathSize = n + m - 3;
            ll pathBlock = diff / pathSize;
            ll extra = diff % pathSize;

            for (int j = 1; j < m; ++j) {
                res[0][j] -= pathBlock;
                if (extra) {
                    --extra;
                    --res[0][j];
                }
            }
            for (int i = 2; i < n; ++i) {
                res[i][0] -= pathBlock;
                if (extra) {
                    --extra;
                    --res[i][0];
                }
            }
        }

        cout << "Possible" << endl;
        for (auto i : res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }

    }
}