#include <algorithm>
#include <vector>

template <class T, class F>
struct segment_tree {
    T m_def;
    F m_func;

    int m_len, m_size;
    std::vector<T> m_data;

    segment_tree(std::vector<T> const &data, T const &def, const F &func) : m_def(def), m_func(func) {
        m_len = data.size();
        m_size = 1 << (sizeof(int) * 8 - __builtin_clz(m_len - 1));

        m_data.assign(2 * m_size, def);
        std::copy(data.begin(), data.end(), m_data.begin() + m_size);
        for (int i = m_size - 1; i >= 0; --i)
            m_data[i] = func(m_data[2 * i], m_data[2 * i + 1]);
    }

    void setitem(int index, const T &value) {
        for (m_data[index += m_size] = value; index >>= 1;)
            m_data[index] = m_func(m_data[2 * index], m_data[2 * index + 1]);
    }

    T& operator [](int index) {
        return m_data[m_size + index];
    }

    int bound(const T &value, const F &cmp) {
        if (!cmp(value, m_data[1]))
            return -1;

        int i = 2;
        for (; i < m_size; i *= 2)
            if (cmp(value, m_data[i + 1]))
                ++i;
        return i - m_size;
    }

    T query(int begin, int end) {
        T res = m_def;
        for (begin += m_size, end += m_size; begin < end; begin >>= 1, end >>= 1) {
            if (begin & 1)
                res = m_func(res, m_data[begin++]);
            if (end & 1)
                res = m_func(res, m_data[--end]);
        }
        return res;
    }
};
