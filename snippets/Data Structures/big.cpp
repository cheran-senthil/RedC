#include <bits/stdc++.h>

using namespace std;

const int LEN = 80;
const int YW = 8;
const int BASE = 100000000;

struct big {
    int a[LEN];

    int &operator[](int x) { return a[x]; }
    const int &operator[](int x) const { return a[x]; }

    big() { memset(a, 0, sizeof(a)); }

    big operator=(const big &x) {
        for (int i = x[0] + 1; i <= a[0]; i++) {
            a[i] = 0;
        }
        for (int i = 0; i <= x[0]; i++) {
            a[i] = x[i];
        }
        return *this;
    }
    big operator=(int x) {
        for (int i = a[0]; i >= 0; i--) {
            a[i] = 0;
        }
        for (; x; x /= BASE) {
            a[++a[0]] = x % BASE;
        }
        return *this;
    }

    big(int x) {
        memset(a, 0, sizeof(a));
        *this = x;
    }

    bool operator<(const big &b) const {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        for (int i = a[0]; i >= 1; i--) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return 0;
    }
    bool operator>(const big &b) const {
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }
        for (int i = a[0]; i >= 1; i--) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return 0;
    }
    bool operator<=(const big &b) const { return !(*this > b); }
    bool operator>=(const big &b) const { return !(*this < b); }
    bool operator==(const big &b) const { return !(*this > b) && !(*this < b); }
    bool operator!=(const big &b) const { return !(*this == b); }

    big operator*(const big &b) const {
        big c;
        c[0] = a[0] + b[0];
        for (int i = 1; i <= a[0]; i++) {
            for (int j = 1; j <= b[0]; j++) {
                long long x = c[i + j - 1] + 1ll * a[i] * b[j];
                c[i + j] += x / BASE;
                c[i + j - 1] = x % BASE;
            }
        }
        for (; c[0] > 0 && !c[c[0]]; c[0]--)
            ;
        return c;
    }
    big operator*(int x) const {
        big c;
        long long v = 0;
        for (int i = 1; i <= a[0] + 3; i++) {
            v = 1ll * x * a[i] + v;
            c[i] = v % BASE;
            v /= BASE;
        }
        c[0] = a[0] + 3;
        for (; c[0] > 0 && !c[c[0]]; c[0]--)
            ;
        return c;
    }

    big operator/(int x) const {
        big c;
        long long v = 0;
        for (int i = a[0]; i >= 1; i--) {
            v = v * BASE + a[i];
            c[i] = v / x;
            v %= x;
        }
        c[0] = a[0];
        for (; c[0] > 0 && !c[c[0]]; c[0]--)
            ;
        return c;
    }
    big operator/(const big &b) const {
        if (b[0] == 1 && !b[1]) {
            puts("error! divide by 0");
            exit(0);
        }
        if (*this < b)
            return big(0);
        int l1 = max(0, (a[0] - 1)) * YW;
        int l2 = max(0, (b[0] - 1)) * YW;
        int v1 = a[a[0]], v2 = b[b[0]];
        for (; v1; v1 /= 10, l1++)
            ;
        for (; v2; v2 /= 10, l2++)
            ;
        big c, chu = *this, B = b;
        for (int i = 1; i <= (l1 - l2) / YW; i++) {
            B *= BASE;
        }
        for (int i = 1; i <= (l1 - l2) % YW; i++) {
            B *= 10;
        }
        for (int i = l1 - l2; i >= 0; i--) {
            int x = 0;
            for (; chu >= B; chu -= B, x++)
                ;
            c[i / YW + 1] = c[i / YW + 1] * 10 + x;
            B /= 10;
        }
        c[0] = (l1 - l2) / YW + 1;
        for (; c[0] > 0 && !c[c[0]]; c[0]--)
            ;
        return c;
    }

    big operator+(const big &b) const {
        big c;
        c[0] = max(a[0], b[0]);
        for (int i = 1; i <= c[0]; i++) {
            c[i] = a[i] + b[i];
        }
        for (int i = 1; i <= c[0]; i++) {
            c[i + 1] += c[i] / BASE;
            c[i] %= BASE;
        }
        if (c[c[0] + 1]) {
            c[0]++;
        }
        return c;
    }
    big operator+(int x) const {
        big c = *this;
        c[1] += x;
        for (int i = 1; i <= c[0] + 1; i++) {
            if (c[i] >= BASE) {
                c[i + 1] += c[i] / BASE;
                c[i] %= BASE;
            } else {
                break;
            }
        }
        if (c[c[0] + 1]) {
            c[0]++;
        }
        return c;
    }

    big operator-(const big &b) const {
        big c;
        c[0] = a[0];
        for (int i = 1; i <= c[0]; i++) {
            c[i] = a[i] - b[i];
        }
        for (int i = 1; i <= c[0]; i++) {
            if (c[i] < 0) {
                c[i] += BASE;
                c[i + 1]--;
            }
        }
        for (; c[0] > 1 && !c[c[0]]; c[0]--)
            ;
        return c;
    }
    big operator-(int x) const {
        big c = *this;
        c[1] -= x;
        for (int i = 1; i <= c[0] + 1; i++) {
            if (c[i] < 0) {
                c[i + 1] += (c[i] + 1) / BASE - 1;
                c[i] = (c[i] + 1) % BASE + BASE - 1;
            } else {
                break;
            }
        }
        for (; c[0] > 1 && !c[c[0]]; c[0]--)
            ;
        return c;
    }

    int operator%(int x) const {
        long long ans = 0;
        for (int i = a[0]; i >= 1; i--) {
            ans = (ans * BASE + a[i]) % x;
        }
        return ans;
    }
    big operator%(const big &b) const {
        if (b[0] == 1 && !b[1]) {
            puts("error! mod by 0");
            exit(0);
        }
        if (*this < b)
            return *this;
        int l1 = max(0, (a[0] - 1)) * YW;
        int l2 = max(0, (b[0] - 1)) * YW;
        int v1 = a[a[0]], v2 = b[b[0]];
        for (; v1; v1 /= 10, l1++)
            ;
        for (; v2; v2 /= 10, l2++)
            ;
        big chu = *this, B = b;
        for (int i = 1; i <= (l1 - l2) / YW; i++) {
            B *= BASE;
        }
        for (int i = 1; i <= (l1 - l2) % YW; i++) {
            B *= 10;
        }
        for (int i = l1 - l2; i >= 0; i--) {
            for (; chu >= B; chu -= B)
                ;
            B /= 10;
        }
        return chu;
    }

    big operator+=(const big &b) { return *this = (*this + b); }
    big operator-=(const big &b) { return *this = (*this - b); }
    big operator*=(const big &b) { return *this = (*this * b); }
    big operator/=(const big &b) { return *this = (*this / b); }
    big operator%=(const big &b) { return *this = (*this % b); }
    big operator+=(int x) { return *this = (*this + x); }
    big operator-=(int x) { return *this = (*this - x); }
    big operator*=(int x) { return *this = (*this * x); }
    big operator/=(int x) { return *this = (*this / x); }

    void read() {
        char c[LEN * YW + 10];
        scanf("%s", c);
        int len = strlen(c);
        memset((*this).a, 0, sizeof((*this).a));
        reverse(c, c + len);
        a[0] = (len - 1) / YW + 1;
        for (int i = len - 1; i >= 0; i--) {
            a[i / YW + 1] = a[i / YW + 1] * 10 + c[i] - '0';
        }
    }
    void write() const {
        printf("%d", a[a[0]]);
        for (int i = a[0] - 1; i >= 1; i--) {
            printf("%08d", a[i]);
        }
    }
    void writeln() const {
        write();
        puts("");
    }
};
