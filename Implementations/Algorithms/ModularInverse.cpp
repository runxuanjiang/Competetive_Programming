#include <iostream>

/**
 * returns gcd(a, m), while finding x and y such that
 * a*x + m*y = gcd(a, m)
 */
long long extendedEuclidean(long long a, long long m, long long &x, long long &y) {
    if (m > a) {
        return extendedEuclidean(m, a, y, x);
    }

    if (!m) {
        x = 1;
        y = 0;
        return a;
    }


    long long mult = a/m;
    long long prevx, prevy;
    long long res = extendedEuclidean(m, a-(m*mult), prevx, prevy);
    x = prevy;
    y = prevx - prevy * mult;
    return res;
}

long long modularInverse(long long num, long long mod) {
    long long x, _;
    long long g = extendedEuclidean(num, mod, x, _);
    return ((x % mod) + mod ) % mod;

}

int main() {
    
    for (long long i = 1; i < 13; ++i) {
        std::cout << "The modular inverse of " << i << " MOD (13) is " << modularInverse(i, 13) << std::endl;

    }
}