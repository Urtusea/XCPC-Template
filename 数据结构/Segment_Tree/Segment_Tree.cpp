#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct Segment_Tree {
    Info f[4 << std::__lg(N)];

    void push_up(int p) {
        f[p] = f[p << 1 | 1] + f[p << 1];
    }

    void build(int p, int l, int r, Info init) {
        if (l == r)
            return (void)(f[p] = init);
        int m = (l + r) >> 1;
        build(p << 1 | 1, l, m, init);
        build(p << 1, m + 1, r, init);
        push_up(p);
    }

    void build(int p, int l, int r, std::vector<Info> &init) {
        if (l == r)
            return (void)(f[p] = init[l]);
        int m = (l + r) >> 1;
        build(p << 1 | 1, l, m, init);
        build(p << 1, m + 1, r, init);
        push_up(p);
    }

    void update(int p, int l, int r, int u, Info x) {
        if (l == r)
            return (void)(f[p].update(x));
        int m = (l + r) >> 1;
        if (u <= m)
            update(p << 1 | 1, l, m, u, x);
        else
            update(p << 1, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return f[p];
        int m = (l + r) >> 1;
        return query(p << 1 | 1, l, m, L, R) + query(p << 1, m + 1, r, L, R);
    }
};