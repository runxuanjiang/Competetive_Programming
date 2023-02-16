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

struct Node{
    vector<Node*> children;

    Node() : children(11, nullptr) {

    }
};

int main() {
    fast;
    tests {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> perms(n, vector<ll>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> perms[i][j];
            }
        }

        Node* root = new Node;
        for (auto i : perms) {
            vector<ll> positions(11);
            for (int j = 0; j < m; ++j) {
                positions[i[j]] = j+1;
            }

            Node* curr = root;
            for (int j = 1; j <= m; ++j) {
                if (!curr->children[positions[j]]) {
                    curr->children[positions[j]] = new Node;
                }
                curr = curr->children[positions[j]];
            }
        }

        for (auto i : perms) {
            ll res = 0;
            Node* curr = root;
            for (auto j : i) {
                if (curr->children[j]) {
                    ++res;
                    curr = curr->children[j];
                }
                else {
                    break;
                }
            }

            cout << res << " ";
        }
        cout << endl;




    }
}