#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <memory>

using namespace std;
using namespace __gnu_pbds;

struct chash {
    const int RANDOM =
        (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();

    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};

template <typename Key>
using UnorderedSet = gp_hash_table<Key, null_type, chash>;
#define unordered_set UnorderedSet

template <typename Key, typename Mapped>
using UnorderedMap = gp_hash_table<Key, Mapped, chash>;
#define unordered_map UnorderedMap

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset =
    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
