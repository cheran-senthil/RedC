#include <math.h>
#include <tuple>
#include <vector>

using namespace std;

int iroot(int a, int n = 2) {
    if (a < 2)
        return a;

    int c = 1;
    int d = ((n - 1) * c + a / pow(c, n - 1)) / n;
    int e = ((n - 1) * d + a / pow(d, n - 1)) / n;

    while ((c != d) && (c != e))
        tie(c, d, e) = tuple{d, e, ((n - 1) * e + a / (pow(e, n - 1))) / n};

    return min(d, e);
}

vector<bool> get_primes(int n) {
    int i, j, k;
    bool flag = n % 6 == 2;
    vector<bool> sieve(n / 3 + flag, true);

    int max_i = iroot(n, 2) / 3;
    for (i = 1; i <= max_i; ++i) {
        if (sieve[i]) {
            k = (3 * i + 1) | 1;
            for (j = (k * k) / 3; j < (n / 3) + flag; j += 2 * k)
                sieve[j] = false;
            for (j = (k * (k - 2 * (i & 1) + 4)) / 3; j < (n / 3) + flag; j += 2 * k)
                sieve[j] = false;
        }
    }

    return sieve;
}
