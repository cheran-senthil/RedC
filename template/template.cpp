#pragma region template

#include <bits/stdc++.h>
using namespace std;

#pragma region random
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> T randint(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }

#pragma endregion

#pragma region debug
string to_string(bool b) { return b ? "true" : "false"; }

string to_string(char c) { return {39, c, 39}; }

string to_string(string s) { return "\"" + s + "\""; }

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

#pragma endregion

#pragma endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(16);
}
