//Competition #:
//Problem #: A
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

string prtNum(int num) {
    if (num == 11 || num == 12 || num == 13) {
        return to_string(num) + "th";
    }
    else if (num % 10 == 1) {
        return to_string(num) + "st";
    } 
    else if (num % 10 == 2) {
        return to_string(num) + "nd";
    }
    else if (num % 10 == 3) {
        return to_string(num) + "rd";
    }
    else {
        return to_string(num) + "th";
    }
}

void prt(string n1, string n2, int n, int m) {
    if (m == 0) {
        swap(n, m);
        swap(n1, n2);
    }
    if (n == 0) {
        if (m - n > 1) {
            cout << n2 << " is the ";
            for (int i = 0; i < (m-n-2); ++i) {
                cout << "great ";
            }
            cout << "grandchild of " << n1 << endl;
        }
        else {
            cout << n2 << " is the child of " << n1 << endl;
        }
    }

    else {
        if (n == m) {
            if (n == 1) {
                cout << n1 << " and " << n2 << " are siblings" << endl;
            }
            else {
                cout << n1 << " and " << n2 << " are " << prtNum(n-1) << " cousins" << endl; 
            }
        }
        else {
            if (m > n) {
                swap(n, m);
            }
            cout << n1 << " and " << n2 << " are " << prtNum(m-1) << " cousins, " << n-m << ((n - m == 1) ?  " time removed" : " times removed") << endl;
        }
    }

}

int main() {
    fast;
    int t, p;
    cin >> t >> p;

    unordered_map<string, pair<string, unordered_set<string>>> graph;
    for (int i = 0; i < t; ++i) {
        string name;
        int childs;
        cin >> name;
        cin >> childs;
        for (int j = 0; j < childs; ++j) {
            string child;
            cin >> child;
            graph[name].second.insert(child);
            graph[child].first = name;
        }
    }

    for (int i = 0; i < p; ++i) {
        string name1, name2;
        cin >> name1 >> name2;

        int n = 0, m = 0;
        unordered_map<string, int> anc;
        anc[name1] = 0;
        string temp = name1;
        while (graph[temp].first != "") {
            ++n;
            temp = graph[temp].first;
            anc[temp] = n;
        }

        temp = name2;
        while (anc.find(temp) == anc.end()) {
            ++m;
            temp = graph[temp].first;
        }

        n = anc[temp];

        prt(name1, name2, n, m);
    }
}