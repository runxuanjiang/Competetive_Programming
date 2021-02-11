#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    if (n >= 4 && m >= 4) cout << -1;
    else if (n < 2 || m < 2) cout << 0;

    else {
        int count = 0;
        vector<string> matrix(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }
        if (n == 2) {
            vector<bool> c(m-1);
            for (int j = 0; j < m-1; ++j) {
                c[j] = (matrix[0][j] + matrix[1][j] + matrix[0][j+1] + matrix[1][j+1] % 2 == 1);
            }
            for (int i = 0; i < m-1; ++i) {
                if (!c[i]) {
                    if (i == m-2) ++count;
                    else if (!c[i+1]) {
                        c[i+1] = true;
                        ++count;
                    }
                    else {
                        ++count;
                    }
                }
            }
            cout << count;
        }
        else {
            vector<vector<bool>> c(2, vector<bool>(m-1));
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < m-1; ++j) {
                    c[i][j] = (matrix[i][j] + matrix[i+1][j] + matrix[i][j+1] + matrix[i+1][j+1] % 2 == 1);
                }
            }
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < m-1; ++j) {
                    cout << c[i][j];
                }
                cout << endl;
            }
            for (int j = 0; j < m-1; ++j) {
                for (int i = 0; i < 2; ++i) {
                    if (!c[i][j]) {
                        if (j == m-2) {
                            cout << "done2" << endl;
                            ++count;
                            c[1][j] = true;
                        }
                        else if (!c[0][j] && !c[0][j+1] && !c[1][j] && !c[1][j+1]) {
                            ++count;
                            c[0][j] = true;
                            c[0][j+1] = true;
                            c[1][j] = true;
                            c[1][j+1] = true;
                        }
                        else if (i == 0 && !c[1][j]) {
                            ++count;
                            c[1][j] = true;
                        }
                        else if (!c[i][j+1]) {
                            cout << "done" << endl;
                            ++count;
                            c[i][j+1] = true;
                        }
                        else {
                            if (j == 0) {
                                ++count;
                            }
                            else {
                                ++count;
                                c[i][j+1] = (!c[i][j+1]);
                            }
                        }
                        c[i][j] = true;
                    }
                }
            }
            cout << count;
        }
    }
}