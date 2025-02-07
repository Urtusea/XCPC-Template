#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info>
struct Segment_Tree {
#define lson (p << 1)
#define rson (p << 1 | 1)

    std::vector<Info> node;

    Segment_Tree(int _n = 0)
    : node(4 << std::__lg(_n + 1)) {}

    void push_up(int p) {
        node[p] = node[lson] + node[rson];
    }

    void build(int p, int l, int r, Info init) {
        if (l == r)
            return (void)(node[p] = init);
        int m = (l + r) >> 1;
        build(lson, l, m, init);
        build(rson, m + 1, r, init);
        push_up(p);
    }

    void build(int p, int l, int r, std::vector<Info> &init) {
        if (l == r)
            return (void)(node[p] = init[l]);
        int m = (l + r) >> 1;
        build(lson, l, m, init);
        build(rson, m + 1, r, init);
        push_up(p);
    }

    void update(int p, int l, int r, int u, Info x) {
        if (u < l || r < u)
            return;
        if (l == r)
            return (void)(node[p].update(x));
        int m = (l + r) >> 1;
        update(lson, l, m, u, x);
        update(rson, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p];
        int m = (l + r) >> 1;
        return query(lson, l, m, L, R) + query(rson, m + 1, r, L, R);
    }

#undef lson
#undef rson
};