#include <stdio.h>

int getchar() {
#ifdef _WIN32
    return _getchar_nolock();
#else
    return getchar_unlocked();
#endif
}

void getnum() {}
template <class T, class... S>
inline void getnum(T &a, S &... b) {
    int chr = getchar();
    while (isspace(chr))
        chr = getchar();

    bool positive = true;
    if (chr == '-')
        positive = false, chr = getchar();

    if (isdigit(chr)) {
        a = chr - '0';
        while (isdigit(chr = getchar()))
            a = a * 10 + chr - '0';
    } else {
        a = 0;
    }

    if (chr == '.') {
        uint64_t dec_part = 0;
        int dec_len = 0;
        while (isdigit(chr = getchar()))
            dec_part = dec_part * 10 + chr - '0', ++dec_len;
        a += dec_part / pow(10, dec_len);
    }

    a = positive ? a : -a;
    getnum(b...);
}
