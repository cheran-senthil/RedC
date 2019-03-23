#pragma region template

#include <bits/stdc++.h>
using namespace std;

#pragma region pbds

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    const unsigned long long RANDOM =
        (unsigned long long)(make_unique<char>().get()) ^
        chrono::steady_clock::now().time_since_epoch().count();

    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static unsigned long long hash_combine(unsigned long long a,
                                           unsigned long long b) {
        return a * 31 + b;
    }

    unsigned long operator()(unsigned long long x) const {
        return hash_f(x) ^ RANDOM;
    }
};

template <typename Key>
using UnorderedSet = gp_hash_table<Key, null_type, chash>;
#define unordered_set UnorderedSet

template <typename Key, typename Mapped>
using UnorderedMap = gp_hash_table<Key, Mapped, chash>;
#define unordered_map UnorderedMap

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma endregion

#pragma region random

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> T randint(T a, T b) {
    return uniform_int_distribution<T>(a, b)(rng);
}

#pragma endregion

#pragma region debug
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

#pragma endregion

#pragma endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
