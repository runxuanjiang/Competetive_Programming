#include <iostream>
using namespace std;

int main() {
    unsigned long long n, m, a;
    cin >> n >> m >> a;

    unsigned long long length = (n % a == 0) ? n/a : n/a + 1;
    unsigned long long width = (m % a == 0) ? m/a : m/a + 1;

    cout << length*width;
}