#include <bits/stdc++.h>

#define complex complex<long double>
#define int long long
#define float long double
#define str string

#define False false
#define True true
#define None nullptr

#define main() signed main()

using namespace std;

template <class T, class Allocator = std::allocator<T>>
struct _vector : vector<T, Allocator> {
    using vector<T, Allocator>::vector;

    decltype(auto) operator[](int index) {
        if (index < 0)
            index += this->size();
        return this->at(index);
    }

    decltype(auto) operator[](int index) const {
        if (index < 0)
            index += this->size();
        return this->at(index);
    }

    friend _vector operator+(_vector a, const _vector &b) {
        a.extend(b);
        return a;
    }

    _vector &operator+=(const _vector &b) {
        extend(b);
        return *this;
    }

    void append(T x) { this->push_back(x); }

    template <class Container> void extend(const Container &iter) {
        vector<T, Allocator>::insert(this->end(), iter.begin(), iter.end());
    }

    void insert(int index, T val) {
        vector<T, Allocator>::insert(this->begin() + index, val);
    }

    void remove(T x) { this->erase(this->begin() + index(x)); }

    T pop() {
        T e = move(this->at(this->size() - 1));
        this->pop_back();
        return e;
    }

    T pop(int i) {
        if (i < 0)
            i += this->size();
        T e = move(this->at(i));
        this->erase(this->begin() + i);
        return e;
    }

    int index(T x) {
        int index = find(this->begin(), this->end(), x) - this->begin();
        if (index == this->size())
            throw out_of_range("x not in list");
        return index;
    }

    int count(T x) { return std::count(this->begin(), this->end(), x); }

    void sort() { std::sort(this->begin(), this->end()); }

    template <typename F> void sort(F key) {
        std::sort(this->begin(), this->end(),
                  [=](const T a, const T b) { return key(a) < key(b); });
    }

    void sort(bool reverse) {
        if (reverse)
            std::sort(this->rbegin(), this->rend());
        std::sort(this->begin(), this->end());
    }

    template <typename F> void sort(F key, bool reverse) {
        if (reverse)
            std::sort(this->rbegin(), this->rend(),
                      [=](const T a, const T b) { return (key(a) < key(b)); });
        std::sort(this->begin(), this->end(),
                  [=](const T a, const T b) { return (key(a) < key(b)); });
    }

    void reverse() { std::reverse(this->begin(), this->end()); }

    _vector copy() {
        _vector a(*this);
        return a;
    }
};

#define vector _vector

str input() {
    str s;
    getline(cin >> ws, s);
    return s;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

main() {
    ios::sync_with_stdio(False);
    cin.tie(None);
    vector<int> a(1);
    a[0] = 1;
    cout << a[0];
}
