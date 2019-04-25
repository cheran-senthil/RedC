#include <tuple>
#include <vector>

int isqrt(int n) {
    if (n == 0)
        return 0;
    int u = n, s = n + 1, t;
    while (u < s) {
        s = u;
        t = s + n / s;
        u = t / 2;
    }
    return s;
}

std::vector<bool> get_primes(int n) {
    int i, j, k;
    bool flag = n % 6 == 2;
    std::vector<bool> sieve(n / 3 + flag, true);

    int max_i = isqrt(n) / 3;
    for (i = 1; i <= max_i; ++i)
        if (sieve[i]) {
            k = (3 * i + 1) | 1;
            for (j = (k * k) / 3; j < (n / 3) + flag; j += 2 * k)
                sieve[j] = false;
            for (j = (k * (k - 2 * (i & 1) + 4)) / 3; j < (n / 3) + flag; j += 2 * k)
                sieve[j] = false;
        }

    return sieve;
}
