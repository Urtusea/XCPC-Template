#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T>
struct Line {
    T k, b;
    Line() {}
    constexpr T operator () (int x) {
        return k * x + b;
    }
};

template <typename T>
struct LineID : public Line<T> {
    T id;
    LineID() {}
    constexpr T operator () (int x) {
        return this->k * x + this->b;
    }
};

template <typename Info, bool (*Comp)(Info, Info, int), int N> struct Segment_Tree_Line {
    Info f[4 << std::__lg(N)];

    void push_down(int p, int l, int r, Info line) {
        int m = (l + r) >> 1;
        if (Comp(f[p], line, m)) std::swap(f[p], line);
        if (Comp(f[p], line, l)) push_down(p << 1, l, m, line);
        if (Comp(f[p], line, r)) push_down(p << 1 | 1, m + 1, r, line);
    }

    void update(int p, int l, int r, int L, int R, Info line) {
        if (L <= l && r <= R)
            return push_down(p, l, r, line);
        int m = (l + r) >> 1;
        if (L <= m) update(p << 1, l, m, L, R, line);
        if (m <  R) update(p << 1 | 1, m + 1, r, L, R, line);
    };
};