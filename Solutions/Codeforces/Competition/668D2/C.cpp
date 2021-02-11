//Competition #: Codeforces Round 668 Division 2
//Problem #: C
//Accepted: Yes

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    next: while (t--) {
            int n, k;
            cin >> n >> k;
        string b;
        cin >> b;
        if (k % 2 != 0) goto next;

        for (int i = 0; i < n-k; ++i) {
            if (b[i] == '?' && b[i + k] != '?') b[i] = b[i+k];
            if (b[i] != '?' && b[i+k] == '?') b[i+k] = b[i];
            if (b[i] != b[i+k]) {
                cout << "NO" << endl;
                goto next;
            }
        }
        for (int i = n-1; i >= k; --i) {
            if (b[i] == '?' && b[i - k] != '?') b[i] = b[i-k];
            if (b[i] != '?' && b[i-k] == '?') b[i-k] = b[i];
            if (b[i] != b[i-k]) {
                cout << "NO" << endl;
                goto next;
            }
        }

        int zero = 0, one = 0,  ques = 0;
        int s = 0, e = 0;
        for (; e < k; ++e) {
            if (b[e] == '0') ++ zero;
            else if (b[e] == '1') ++ one;
            else ++ ques;
        }
        e-=1;

        for (int i = 0; i <= n-k; ++i) {
            if (zero != one) {
                int diff = abs(zero - one);
                if (diff == ques) {
                    for (int j = s; j <= e; ++j) {
                        if (b[j] == '?') b[j] = (zero > one) ? '1' : '0';
                    }
                    zero = max(one, zero);
                    one = max(one, zero);
                    ques = 0;
                }
            }

            if (i < n-k) {
                if (b[s] == '0') --zero;
                else if (b[s] == '1') -- one;
                else -- ques;
                ++s;
                ++e;
                if (b[e] == '0') ++ zero;
                else if (b[e] == '1') ++ one;
                else ++ ques;
            }
        }

        zero = 0; one = 0;  ques = 0;
        s = 0; e = 0;
        for (; e < k; ++e) {
            if (b[e] == '0') ++ zero;
            else if (b[e] == '1') ++ one;
            else ++ ques;
        }
        e-=1;

        for (int i = 0; i <= n-k; ++i) {
            if (zero == one && ques % 2 != 0) {
                cout << "NO" << endl;
                goto next;
            }
            if (zero != one) {
                int diff = abs(zero - one);
                if (ques < diff) {
                    cout << "NO" << endl;
                    goto next;
                }
                if (ques % 2 != diff % 2) {
                    cout << "NO" << endl;
                    goto next;
                }
            }

            if (i < n-k) {
                if (b[s] == '0') --zero;
                else if (b[s] == '1') -- one;
                else -- ques;

                ++s;
                ++e;
                if (b[e] == '0') ++ zero;
                else if (b[e] == '1') ++ one;
                else ++ ques;
            }
        }
        cout << "YES" << endl;
    }
}