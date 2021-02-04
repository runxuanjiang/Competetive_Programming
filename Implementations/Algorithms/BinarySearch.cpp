#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Finds f in vector v. If found, returns position. If not found, returns -1.
int binarySearch(vector<int> v, int f) {
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == f) return mid;
        else if (v[mid] < f) {
            left = mid+1;
        }
        else if (v[mid] > f) {
            right = mid-1;
        }
    }
    return -1;
}

// Finds first element greater or equal to f. If none, returns -1.
int lowerBound(vector<int> v, int f) {
    int left = 0;
    int right = v.size() - 1;
    int res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] >= f) {
            res = v[mid];
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }

    return res;
}

int main() {
    vector<int> test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> test1 = {0, 2, 4, 6, 8, 10};
    for (int i = 0; i < test.size(); ++i) {
        assert(binarySearch(test, i) == i);
    }

    for (int i = 0; i < test.size(); ++i) {
        assert(lowerBound(test, i) == i);
    }
    assert(lowerBound(test1, 1) == 2);
    assert(lowerBound(test1, 12) == -1);

    cout << "Tests Passed" << endl;
}