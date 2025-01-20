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

ll tn = 0;
ll firstEdges = 0;

int main() {
    fast;
    tests {
        ++tn;
        cerr << "Tests remaining: " << testCount << endl;
        ll n;
        cin >> n;

        if (tn == 1) {
            firstEdges = n;
        }

        // if (firstEdges == 6) {
        //     if (tn == 998) {
        //         cout << n << endl;
        //         for (int i = 1; i < n; ++i) {
        //             ll u, v;
        //             cin >> u >> v;
        //             cout << u << " " << v << endl;
        //         }
        //         continue;
        //     }
        //     else {
        //         for (int i = 1; i < n; ++i) {
        //             ll u, v;
        //             cin >> u >> v;
        //         }
        //         continue;
        //     }
        // }
        

        unordered_map<ll, unordered_map<ll, ll>> edges;
        vector<unordered_set<ll>> g(n);
        for (int i = 1; i < n; ++i) {
            ll u, v;
            cin >> u >> v;
            g[u-1].insert(v-1);
            g[v-1].insert(u-1);

            edges[u-1][v-1] = i;
            edges[v-1][u-1] = i;
        }



        if (n % 3 != 0) {
            cout << -1 << endl;
            continue;
        }


        vector<ll> res;
        unordered_set<ll> bfs;
        vector<ll> eb(n, -1); // exists branch
        vector<bool> done(n, false);
        ll good = true;

        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                bfs.insert(i);
            }
        }
        
        while (!bfs.empty()) {
            ll i = *bfs.begin();
            bfs.erase(bfs.begin());

            if (done[i]) {
                continue;
            }

            if (g[i].empty()) {
                good = false;
                break;
            }

            cerr << "processing node: " << i+1 << endl;

            ll j = *g[i].begin();

            if (g[j].size() > 2) {
                if (eb[j] != -1) {
                    ll k = eb[j];
                    for (auto child : g[j]) {
                        if(child != i && child != k) {
                            g[child].erase(j);
                            res.push_back(edges[child][j]);
                            if (g[child].size() == 1) {
                                bfs.insert(child);
                            }
                            if (eb[child] != -1 && g[child].size() == 2) {
                                bfs.insert(eb[child]);
                            }
                        }
                    }
                    done[i] = true;
                    done[j] = true;
                    done[k] = true;

                    cerr << "completed branch " << i+1 << " " << j+1 << " " << k+1 << " " << endl;

                }
                else {
                    eb[j] = i;
                }
            }
            else if (g[j].size() == 2) {
                g[j].erase(i);
                ll k = *g[j].begin();
                for (auto child : g[k]) {
                    if (child != j) {
                        g[child].erase(k);
                        res.push_back(edges[child][k]);
                        if (g[child].size() == 1) {
                            bfs.insert(child);
                        }
                        if (eb[child] != -1 && g[child].size() == 2) {
                            bfs.insert(eb[child]);
                        }
                    }
                }
                done[i] = true;
                done[j] = true;
                done[k] = true;
                cerr << "completed branch " << i+1 << " " << j+1 << " " << k+1 << " " << endl;
            }
        }


        for (auto i : done) {
            if (!i) {
                good = false;
            }
        }

        if (!good) {
            cout << -1 << endl;
        }

        else {
            cout << res.size() << endl;
            for (auto i : res) {
                cout << i<< " ";
            }
            cout << endl;
        }

    }
}