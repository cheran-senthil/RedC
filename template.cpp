#include <bits/stdc++.h>

template <class T, int N> struct _array : std::array<T, N> {
    int index(const T &x, int start = 0, int end = 0) {
        if (end == 0) {
            end = this->size();
        }

        return std::find(this->begin() + start, this->begin() + end, x) -
               this->begin();
    }

    int count(const T &x) { return std::count(this->begin(), this->end(), x); }

    void sort(bool reverse = false) {
        if (reverse) {
            std::sort(this->rbegin(), this->rend());
        } else {
            std::sort(this->begin(), this->end());
        }
    }

    template <typename F> void sort(F key, bool reverse = false) {
        if (reverse) {
            std::sort(
                this->rbegin(), this->rend(),
                [key](const T &x, const T &y) { return (key(x) < key(y)); });
        } else {
            std::sort(
                this->begin(), this->end(),
                [key](const T &x, const T &y) { return (key(x) < key(y)); });
        }
    }

    void reverse() { std::reverse(this->begin(), this->end()); }

    _array copy() {
        _array a(*this);
        return a;
    }
};

template <class T, class Allocator = std::allocator<T>>
struct _vector : std::vector<T, Allocator> {
    using std::vector<T, Allocator>::vector;

    T &operator[](int i) {
        if (i < 0) {
            i += this->size();
        }
        return this->at(i);
    }

    const T &operator[](int i) const {
        if (i < 0) {
            i += this->size();
        }
        return this->at(i);
    }

    friend _vector operator+(_vector a, const _vector &b) {
        a.extend(b);
        return a;
    }

    _vector &operator+=(const _vector &a) {
        extend(a);
        return *this;
    }

    void append(const T &x) { this->push_back(x); }

    template <class Container> void extend(const Container &iterable) {
        std::vector<T, Allocator>::insert(this->end(), iterable.begin(),
                                          iterable.end());
    }

    void insert(int i, const T &x) {
        std::vector<T, Allocator>::insert(this->begin() + i, x);
    }

    void remove(const T &x) { this->erase(this->begin() + index(x)); }

    T pop(int i = -1) {
        if (i < 0) {
            i += this->size();
        }

        T x = move(this->at(i));

        if (i == this->size() - 1) {
            this->pop_back();
        } else {
            this->erase(this->begin() + i);
        }

        return x;
    }

    int index(const T &x, int start = 0, int end = 0) {
        if (start < 0) {
            start += this->size();
        }
        if (end <= 0) {
            end += this->size();
        }

        int i = std::find(this->begin() + start, this->begin() + end, x) -
                this->begin();

        if (i == end) {
            throw std::out_of_range("x not in range");
        }

        return i;
    }

    int count(const T &x) { return std::count(this->begin(), this->end(), x); }

    void sort(bool reverse = false) {
        if (reverse) {
            std::sort(this->rbegin(), this->rend());
        } else {
            std::sort(this->begin(), this->end());
        }
    }

    template <typename F> void sort(F key, bool reverse = false) {
        if (reverse) {
            std::sort(
                this->rbegin(), this->rend(),
                [key](const T &x, const T &y) { return (key(x) < key(y)); });
        } else {
            std::sort(
                this->begin(), this->end(),
                [key](const T &x, const T &y) { return (key(x) < key(y)); });
        }
    }

    void reverse() { std::reverse(this->begin(), this->end()); }

    _vector copy() {
        _vector a(*this);
        return a;
    }
};

using namespace std;

string input() {
    string value;
    getline(cin >> ws, value);
    return value;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define array _array
#define vector _vector

#define complex complex<long double>
#define int long long
#define float long double
#define str string

#define False false
#define True true
#define None nullptr

#define main() signed main()

main() {
    ios::sync_with_stdio(False);
    cin.tie(None);
}
