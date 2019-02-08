#include <bits/stdc++.h>

using namespace std;

#define all(v) all_of(v.begin(), v.end(), [](bool x) { return x; })
#define any(v) any_of(v.begin(), v.end(), [](bool x) { return x; })
#define dict map
#define float long double
#define int long long
#define len(v) (v).size()
#define reversed(v) reverse((v).begin(), (v).end())
#define sorted(v) sort((v).begin(), (v).end())
#define sum(v) accumulate((v).begin(), (v).end(), 0LL)

#define False false
#define True true
#define None nullptr

#define main() signed main()

template <class T, class Allocator = std::allocator<T>>
struct _vector : vector<T, Allocator> {
    using vector<T, Allocator>::vector;
    using vector<T, Allocator>::begin;
    using vector<T, Allocator>::end;
};

#define vector _vector

string input() {
    string s;
    getline(cin >> ws, s);
    return s;
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

main() {
    ios::sync_with_stdio(False);
    cin.tie(None);

    return 0;
}
