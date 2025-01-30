#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info>
struct Segment_Tree {
    std::vector<Info> node;

    Segment_Tree(int _n = 0)
    : node(4 << std::__lg(_n + 1)) {}

    void push_up(int p) {
        node[p] = node[p << 1] + node[p << 1 | 1];
    }

    void build(int p, int l, int r, const std::vector<Info> &info) {
        if (l == r)
            return (void)(node[p] = info[l]);
        const int m = (l + r) >> 1;
        build(p << 1, l, m, info);
        build(p << 1 | 1, m + 1, r, info);
        push_up(p);
    }

    void build(int p, int l, int r, Info init) {
        if (l == r)
            return (void)(node[p] = init);
        const int m = (l + r) >> 1;
        build(p << 1, l, m, init);
        build(p << 1 | 1, m + 1, r, init);
        push_up(p);
    }

    void update(int p, int l, int r, int u, Info x) {
        if (u < l || r < u)
            return;
        if (l == r)
            return (void)(node[p].update(x));
        const int m = (l + r) >> 1;
        update(p << 1, l, m, u, x);
        update(p << 1 | 1, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p];
        const int m = (l + r) >> 1;
        return query(p << 1, l, m, L, R) + query(p << 1 | 1, m + 1, r, L, R);
    }
};