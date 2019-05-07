#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

string Sep = " ";
string End = "\n";

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << Sep << p.second;
    return os;
}

template <typename T, size_t arr_size, typename = enable_if_t<!is_same<T, char>::value>>
ostream &operator<<(ostream &os, const T (&arr)[arr_size]) {
    bool at_start = true;
    for (const auto &x : arr) {
        if (!at_start)
            os << Sep;
        os << x;
        at_start = false;
    }
    return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    bool at_start = true;
    for (const auto &x : v) {
        if (!at_start)
            os << Sep;
        os << x;
        at_start = false;
    }
    return os;
}

template <typename T> void print(const T &t) { cout << t << End; }
template <typename T, typename... ArgTypes> void print(const T &t, ArgTypes const &... args) {
    cout << t << Sep;
    print(args...);
}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", print(__VA_ARGS__)

void solve() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << boolalpha;
    cout << fixed << setprecision(16);

    solve();
    return 0;
}
