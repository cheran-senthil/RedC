#include <bits/stdc++.h>
using namespace std;

int getchar() {
#ifdef _WIN32
    return _getchar_nolock();
#else
    return getchar_unlocked();
#endif
}

void getnum() {}
template <class T, class... S> inline void getnum(T &a, S &... b) {
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

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A> string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(16);
}
