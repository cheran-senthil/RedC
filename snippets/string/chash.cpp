#include <chrono>
#include <memory>
using namespace std;

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

