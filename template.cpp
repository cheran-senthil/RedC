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

    decltype(auto) operator[](int i) {
        if (i < 0)
            i += this->size();
        return this->at(i);
    }

    decltype(auto) operator[](int i) const {
        if (i < 0)
            i += this->size();
        return this->at(i);
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

    template <class Container> void extend(const Container &iterable) {
        vector<T, Allocator>::insert(this->end(), iterable.begin(),
                                     iterable.end());
    }

    void insert(int i, T x) {
        vector<T, Allocator>::insert(this->begin() + i, x);
    }

    void remove(T x) { this->erase(this->begin() + index(x)); }

    T pop() {
        T x = move(this->at(this->size() - 1));
        this->pop_back();
        return x;
    }

    T pop(int i) {
        if (i < 0)
            i += this->size();
        T x = move(this->at(i));
        this->erase(this->begin() + i);
        return x;
    }

    int index(T x) {
        int i = find(this->begin(), this->end(), x) - this->begin();
        if (i == this->size())
            throw out_of_range("x not in list");
        return i;
    }

    int count(T x) { return std::count(this->begin(), this->end(), x); }

    void sort() { std::sort(this->begin(), this->end()); }

    template <typename F> void sort(F key) {
        std::sort(this->begin(), this->end(),
                  [=](const T x, const T y) { return key(x) < key(y); });
    }

    void sort(bool reverse) {
        if (reverse)
            std::sort(this->rbegin(), this->rend());
        std::sort(this->begin(), this->end());
    }

    template <typename F> void sort(F key, bool reverse) {
        if (reverse)
            std::sort(this->rbegin(), this->rend(),
                      [=](const T x, const T y) { return (key(x) < key(y)); });
        std::sort(this->begin(), this->end(),
                  [=](const T x, const T y) { return (key(x) < key(y)); });
    }

    void reverse() { std::reverse(this->begin(), this->end()); }

    _vector copy() {
        _vector a(*this);
        return a;
    }
};

#define vector _vector

str input() {
    str value;
    getline(cin >> ws, value);
    return value;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

main() {
    ios::sync_with_stdio(False);
    cin.tie(None);
}
