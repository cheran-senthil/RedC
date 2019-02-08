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

    T operator[](int index) {
        if (index < 0)
            index += this->size();
        return vector<T, Allocator>::at(index);
    }

    void append(T x) { this->push_back(x); }

    int count(T x) { return std::count(begin(), end(), x); }

    int index(T x) {
        int index = find(begin(), end(), x) - begin();
        if (index == this->size())
            throw out_of_range("value is not in list");
        return index;
    }

    void insert(int index, T val) {
        vector<T, Allocator>::insert(begin() + index, val);
    }

    T pop() {
        T e = this->at(this->size() - 1);
        this->pop_back();
        return e;
    }

    T pop(int i) {
        if (i < 0)
            i += this->size();
        T e = this->at(i);
        this->erase(begin() + i);
        return e;
    }

    void sort() { std::sort(begin(), end()); }

    template <typename F> void sort(F key) {
        std::sort(begin(), end(),
                  [=](const T a, const T b) { return key(a) < key(b); });
    }

    void sort(bool reverse) {
        std::sort(begin(), end(),
                  [=](const T a, const T b) { return reverse != (a < b); });
    }

    template <typename F> void sort(F key, bool reverse) {
        std::sort(begin(), end(), [=](const T a, const T b) {
            return reverse != (key(a) < key(b));
        });
    }

    void reverse() { std::reverse(begin(), end()); }
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
