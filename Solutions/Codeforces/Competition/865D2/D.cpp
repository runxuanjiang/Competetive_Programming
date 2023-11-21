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
    tests {
        ll n;
        cin >> n;

        ll in;

        cout << "+ " << n << endl;
        cin >> in;
        if (in == -2) {
            return 0;
        }

        cout << "+ " << n+1 << endl;
        cin >> in;
        if (in == -2) {
            return 0;
        }

        unordered_map<ll, vector<ll>> dist;
        for (int i = 2; i <= n; ++i) {
            cout << "? 1 " << i << endl;
            cin >> in;
            if (in == -2) {
                return 0;
            }

            dist[in].push_back(i);
        }

        vector<ll> path;

        ll start = 1;
        ll end = n;
        while (start <= end) {
            if (start == end) {
                path.push_back(start);
            }
            else {
                path.push_back(end);
                path.push_back(start);
            }
            ++start;
            --end;
        }
        vector<ll> rpath(path.rbegin(), path.rend());
        vector<ll> perm1(n), perm2(n);

        if (dist[1].size() == 1) {
            perm1[0] = path[0];
            for (int i = 1; i < n; ++i) {
                perm1[dist[i].front() - 1] = path[i];
            }
            perm2[0] = rpath[0];
            for (int i = 1; i < n; ++i) {
                perm2[dist[i].front() - 1] = rpath[i];
            }
        }
        else {
            vector<ll> side1, side2;
            ll s1rep = dist[1].front();
            ll maxdist = 1;
            side1.push_back(dist[1].front());
            side2.push_back(dist[1].back());

            for (int i = 2; i < n; ++i) {
                if (!dist[i].empty()) {
                    maxdist = i;
                    cout << "? " << s1rep << " " << dist[i].front() << endl;
                    cin >> in;
                    if (in == -2) {
                        return 0;
                    }

                    if (in == i-1) {
                        side1.push_back(dist[i].front());
                        if (dist[i].size() == 2) {
                            side2.push_back(dist[i].back());
                        }
                    }
                    else {
                        side2.push_back(dist[i].front());
                        if (dist[i].size() == 2) {
                            side1.push_back(dist[i].back());
                        }
                    }
                }
            }

            if (side1.size() < side2.size()) {
                swap(side1, side2);
            }

            perm1[0] = path[maxdist];
            for (int i = 0; i < side1.size(); ++i) {
                perm1[side1[i]-1] = path[maxdist - i - 1];
            }
            for (int i = 0; i < side2.size(); ++i) {
                perm1[side2[i]-1] = path[maxdist + i + 1];
            }

            perm2[0] = rpath[maxdist];
            for (int i = 0; i < side1.size(); ++i) {
                perm2[side1[i]-1] = rpath[maxdist - i - 1];
            }
            for (int i = 0; i < side2.size(); ++i) {
                perm2[side2[i]-1] = rpath[maxdist + i + 1];
            }
        }

        cout << "! ";
        for (auto i : perm1) {
            cout << i << " ";
        }
        for (auto i : perm2) {
            cout << i << " ";
        }
        cout << endl;

        cin >> in;
        if (in == -2) {
            return 0;
        }

    }
}