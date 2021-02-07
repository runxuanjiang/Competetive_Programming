//Competition #:
//Problem #: C
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    int r;
    scanf("%d", &r);

    vector<int> vec(r+1, 0);
    vec[0] = r+1;
    vec.push_back(r+1);

    int l = 1;

    while (l <= r) {
        int mid = l + (r-l)/2;
        int curr, currL, currR;

        if (vec[mid]) {
            curr = vec[mid];
        }
        else {
            printf("? %d\n", mid);
            fflush(stdout);
            scanf("%d", &curr);
            vec[mid] = curr;
        }
        if (curr == 1) {
            printf("! %d", mid);
            fflush(stdout);
            return 0;
        }

        if (vec[mid-1]) {
            currL = vec[mid-1];
        }
        else {
            printf("? %d\n", mid-1);
            fflush(stdout);
            scanf("%d", &currL);
            vec[mid-1] = currL;
        }
        if (currL == 1) {
            printf("! %d", mid-1);
            fflush(stdout);
            return 0;
        }

        if (vec[mid+1]) {
            currR = vec[mid+1];
        }
        else {
            printf("? %d\n", mid+1);
            fflush(stdout);
            scanf("%d", &currR);
            vec[mid+1] = currR;
        }
        if (currR == 1) {
            printf("! %d", mid+1);
            fflush(stdout);
            return 0;
        }

        if (curr < currL && curr < currR) {
            printf("! %d", mid);
            fflush(stdout);
            return 0;
        }
        else if (currL < curr) {
            r = mid-1;
        }
        else if (currR < curr) {
            l = mid+1;
        }
    }


}