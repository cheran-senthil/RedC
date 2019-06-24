long long pow(long long x, long long y, long long z) {
    if (y == 0)
        return 1;

    long long res = 1;
    while (y > 1) {
        if (y & 1)
            res = res * x % z;
        x = x * x % z;
        y >>= 1;
    }

    return (res * x) % z;
}
