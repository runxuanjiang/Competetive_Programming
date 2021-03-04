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

bool isVar(string s) {
    return (s.length() == 1 && s[0] >= 'a' && s[0] <= 'z'); 
}

int main() {
    fast;
    string expr;
    int count = 1;

    while (getline(cin, expr)) {
        while (true) {
            bool reduce = false;
            string op = "", l = "";

            istringstream iss(expr);
            string s = "";
            
            string in;
            while (iss >> in) {
                if (in == "*" || in == "+" || in == "-") {
                    s += op + l;
                    op = in + " ";
                    l = "";
                }
                else if (op == "") {
                    s += in + ' ';
                }
                else if (isVar(in)) {
                    s += op + l;
                    s += in + " ";
                    op = "";
                    l = "";
                }
                else {
                    if (l == "") {
                        l = in + ' ';
                    }
                    else {
                        int left = stoi(l.substr(0, l.length() - 1));
                        int right = stoi(in);
                        int res;
                        if (op == "* ") {
                            res = left * right;
                        }
                        else if (op == "- ") {
                            res = left - right;
                        }
                        else if (op == "+ ") {
                            res = left + right;
                        }

                        s += to_string(res) + ' ';
                        reduce = true;

                        op = "";
                        l = "";
                    }
                }
            }
            expr = s;


            if (!reduce) {
                break;
            }

        }
        cout << "Case " << count << ": " << expr << endl;
        ++count;


    }
}