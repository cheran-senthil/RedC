#include <bits/stdc++.h>

template <class T, class Alloc = std::allocator<T>>
struct Vector : std::vector<T, Alloc> {
    using std::vector<T, Alloc>::vector;

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

    friend Vector operator+(Vector a, const Vector &b) {
        a.extend(b);
        return a;
    }

    Vector &operator+=(const Vector &a) {
        extend(a);
        return *this;
    }

    void append(const T &x) { this->push_back(x); }

    Vector copy() {
        Vector a(*this);
        return a;
    }

    int count(const T &x) { return std::count(this->begin(), this->end(), x); }

    template <class Container> void extend(const Container &iterable) {
        std::vector<T, Alloc>::insert(this->end(), iterable.begin(),
                                      iterable.end());
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

    void insert(int i, const T &x) {
        std::vector<T, Alloc>::insert(this->begin() + i, x);
    }

    T pop(int i = -1) {
        if (i < 0) {
            i += this->size();
        }

        T x = std::move(this->at(i));

        if (i == this->size() - 1) {
            this->pop_back();
        } else {
            this->erase(this->begin() + i);
        }

        return x;
    }

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

    void remove(const T &x) { this->erase(this->begin() + index(x)); }

    void reverse() { std::reverse(this->begin(), this->end()); }
};

template <class T, class Compare = std::less<T>,
          class Alloc = std::allocator<T>>
struct Set : std::set<T, Compare, Alloc> {
    using std::set<T, Compare, Alloc>::set;

    friend Set operator|(Set<T> a, const Set<T> &b) {
        a.update(b);
        return a;
    }

    Set &operator|=(const Set<T> &a) {
        update(a);
        return *this;
    }

    friend Set operator&(Set<T> a, const Set<T> &b) {
        return a.intersection(b);
    }

    Set &operator&=(const Set<T> &a) {
        intersection_update(a);
        return *this;
    }

    friend Set operator-(Set<T> a, const Set<T> &b) { return a.difference(b); }

    Set &operator-=(const Set<T> &a) {
        difference_update(a);
        return *this;
    }

    friend Set operator^(Set<T> a, const Set<T> &b) {
        return a.symmetric_difference(b);
    }

    Set &operator^=(const Set<T> &a) {
        symmetric_difference_update(a);
        return *this;
    }

    void add(const T &elem) { this->insert(elem); }

    template <class Container> Set<T> difference(const Container &a) {
        Set<T> b;

        std::set_difference(this->cbegin(), this->cend(), a.cbegin(), a.cend(),
                            std::inserter(b, b.begin()));

        return b;
    }

    template <class Container> void difference_update(const Container &other) {
        for (const auto &x : other) {
            this->erase(x);
        }
    }

    void discard(const T &elem) { this->erase(elem); }

    Set<T> intersection(const Set<T> &other) {
        Set<T> a;

        std::set_intersection(this->cbegin(), this->cend(), other.cbegin(),
                              other.cend(), std::inserter(a, a.begin()));

        return a;
    }

    template <class Container>
    void intersection_update(const Container &other) {
        for (auto it = this->begin(); it != this->end();) {
            auto e = other.find(*it);
            if (e == other.end()) {
                it = this->erase(it);
            } else {
                it++;
            }
        }
    }

    bool is_disjoint(const Set<T> &other) {
        return intersection(other) == Set<T>();
    }

    bool issubset(const Set<T> &other) {
        return std::includes(other.begin(), other.end(), this->begin(),
                             this->end());
    }

    bool issuperset(const Set<T> &other) {
        return std::includes(this->begin(), this->end(), other.begin(),
                             other.end());
    }

    T pop() {
        T a = std::move(*(this->begin()));
        this->erase(this->begin());
        return a;
    }

    void remove(const T &elem) {
        typename std::set<T, Compare, Alloc>::iterator it = this->find(elem);

        if (it != this->end()) {
            this->erase(it);
        } else {
            throw std::out_of_range("elem not in set");
        }
    }

    Set<T> symmetric_difference(const Set<T> &other) {
        Set<T> a;

        std::set_symmetric_difference(this->cbegin(), this->cend(),
                                      other.cbegin(), other.cend(),
                                      std::inserter(a, a.begin()));

        return a;
    }

    void symmetric_difference_update(const Set<T> &other) {
        Set<T> a;

        std::set_symmetric_difference(this->cbegin(), this->cend(),
                                      other.cbegin(), other.cend(),
                                      std::inserter(a, a.begin()));

        *this = a;
    }

    template <class Container> void update(const Container &other) {
        this->insert(other.cbegin(), other.cend());
    }
};

template <class Key, class T, class Compare = std::less<Key>,
          class Alloc = std::allocator<std::pair<const Key, T>>>
struct Map : std::map<Key, T, Compare, Alloc> {
    using std::map<Key, T, Compare, Alloc>::map;

    Map copy() {
        Map a = *this;
        return a;
    }

    T get(const Key &key, const T &d = T()) {
        typename std::map<Key, T, Compare, Alloc>::iterator it =
            this->find(key);

        if (it != this->end()) {
            return it->second;
        }

        return d;
    }

    Vector<std::pair<const Key, T>> items() {
        Vector<std::pair<const Key, T>> a;

        std::transform(
            this->begin(), this->end(), std::back_inserter(a),
            [](const std::pair<const Key, T> &item) { return item; });

        return a;
    }

    Vector<Key> keys() {
        Vector<Key> a;

        std::transform(
            this->begin(), this->end(), std::back_inserter(a),
            [](const std::pair<const Key, T> &item) { return item.first; });

        return a;
    }

    T pop(const Key &key) {
        typename std::map<Key, T, Compare, Alloc>::iterator it =
            this->find(key);

        if (it != this->end()) {
            T x = std::move(it->second);
            erase(it);
            return x;
        }

        throw std::out_of_range("key not in dict");
    }

    T pop(const Key &key, const T &d) {
        typename std::map<Key, T, Compare, Alloc>::iterator it =
            this->find(key);

        if (it != this->end()) {
            T x = std::move(it->second);
            erase(it);
            return x;
        }

        return d;
    }

    T setdefault(const Key &key, const T &d = T()) {
        typename std::map<Key, T, Compare, Alloc>::iterator it =
            this->find(key);

        if (it != this->end()) {
            return it->second;
        }

        this->insert(this->begin(), std::pair<Key, T>(key, d));
        return d;
    }

    Vector<Key> values() {
        Vector<Key> a;

        std::transform(
            this->begin(), this->end(), std::back_inserter(a),
            [](const std::pair<const Key, T> &item) { return item.second; });

        return a;
    }
};

template <class T, class Alloc = std::allocator<T>>
struct Deque : std::deque<T, Alloc> {
    using std::deque<T, Alloc>::deque;

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

    friend Deque operator+(Deque a, const Deque &b) {
        a.extend(b);
        return a;
    }

    Deque &operator+=(const Deque &a) {
        extend(a);
        return *this;
    }

    void append(const T &x) { this->push_back(x); }

    void appendleft(const T &x) { this->push_front(x); }

    Deque copy() {
        Deque a(*this);
        return a;
    }

    int count(const T &x) { return std::count(this->begin(), this->end(), x); }

    template <class Container> void extend(const Container &iterable) {
        std::deque<T, Alloc>::insert(this->end(), iterable.begin(),
                                     iterable.end());
    }

    template <class Container> void extendleft(const Container &iterable) {
        std::deque<T, Alloc>::insert(this->begin(), iterable.rbegin(),
                                     iterable.rend());
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

    void insert(int i, const T &x) {
        std::deque<T, Alloc>::insert(this->begin() + i, x);
    }

    T pop() {
        T x = std::move(this->back());
        this->pop_back();
        return x;
    }

    T popleft() {
        T x = std::move(this->front());
        this->pop_front();
        return x;
    }

    void remove(const T &x) { this->erase(this->begin() + index(x)); }

    void reverse() { std::reverse(this->begin(), this->end()); }

    void rotate(int n = 1) {
        if (n < 0) {
            n += this->size();
        }
        std::rotate(this->begin(), this->end() - n, this->end());
    }
};

std::string input() {
    std::string value;
    std::getline(std::cin >> std::ws, value);
    return value;
}

template <class Container, class Function>
auto Transform(Function fun, const Container &cont)
    -> Vector<decltype(fun(*cont.begin()))> {
    Vector<decltype(fun(*cont.begin()))> ret;
    ret.reserve(cont.size());

    for (const auto &v : cont) {
        ret.push_back(fun(v));
    }

    return ret;
}

Vector<std::string> split(std::string s) {
    Vector<std::string> a;
    std::string word;

    for (char c : s) {
        if (c == ' ') {
            a.push_back(word);
            word.clear();
        } else {
            word.push_back(c);
        }
    }
    a.push_back(word);

    return a;
}

int Stoi(const std::string &str) { return std::stoi(str); }

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define deque Deque
#define map Map
#define set Set
#define vector Vector

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
