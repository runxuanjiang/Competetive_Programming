#include <bits/stdc++.h>

using namespace std;

vector<long long> prefix_arr(string s) {
    vector<long long> res(s.size(), 0);
    long long curr = 0;
    for (long long i = 1; i < s.size(); ++i) {
        while (curr > 0 && s[i] != s[curr]) {
            curr = res[curr - 1];
        }

        if (s[i] == s[curr]) {
            ++curr;
        }
        res[i] = curr;
    }

    return res;
}

long long check_substring(string t, string s) { // check how many times that s is a substring of t
    vector<long long> p = prefix_arr(s);
    long long res = 0;
    long long curr = 0;
    for (long long i = 0; i < t.size(); ++i) {
        while (curr > 0 && t[i] != s[curr]) {
            curr = p[curr-1];
        }

        if (t[i] == s[curr]) {
            ++curr;
        }
        if (curr == s.size()) {
            ++res;
            curr = p[curr-1];
        }
    }
    return res;
}

int main() {
    string test1 = "abcabcd";
    string test2 = "aabaaab";

    vector<long long> ans1 = {0, 0, 0, 1, 2, 3, 0};
    vector<long long> ans2 = {0, 1, 0, 1, 2, 2, 3};

    vector<long long> res1 = prefix_arr(test1);
    assert(ans1.size() == res1.size());
    for (int i = 0; i < ans1.size(); ++i) {
        assert(ans1[i] == res1[i]);
    }

    vector<long long> res2 = prefix_arr(test2);
    assert(ans2.size() == res2.size());
    for (int i = 0; i < ans2.size(); ++i) {
        assert(ans2[i] == res2[i]);
    }

    string t1 = "aaaaaaaa", s1 = "aa";
    assert(check_substring(t1, s1) == 7);
    string t2 = "aabaaabaab", s2 = "aab";
    assert(check_substring(t2, s2) == 3);
    string t3 = "aabbaababaabababaabaa", s3 = "bab";
    assert(check_substring(t3, s3) == 3);
    string t4 = "aabaacaadaabaaba", s4 = "aaba";
    assert(check_substring(t4, s4) == 3);

    cout << "tests passed" << endl;
}