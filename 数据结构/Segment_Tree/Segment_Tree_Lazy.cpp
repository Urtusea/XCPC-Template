#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Lazy, int N> struct Segment_Tree_Lazy {
    Info f[4 << std::__lg(N)];
    Lazy g[4 << std::__lg(N)];

    void push_up(int p) {
        f[p] = f[p << 1] + f[p << 1 | 1];
    }

    void push_down(int p, int l, int m, int r) {
        const auto edit = [&](int u, int node_size) -> void {
            f[u].update(g[p], node_size);
            g[u].update(g[p]);
        };
        edit(p << 1, m - l + 1);
        edit(p << 1 | 1, r - m);
        g[p].clear();
    }

    void build(int p, int l, int r, Info init) {
        if (l == r)
            return (void)(f[p] = init);
        int m = (l + r) >> 1;
        build(p << 1, l, m, init);
        build(p << 1 | 1, m + 1, r, init);
        push_up(p);
    }

    void build(int p, int l, int r, std::vector<Info> &init) {
        if (l == r)
            return (void)(f[p] = init[l]);
        int m = (l + r) >> 1;
        build(p << 1, l, m, init);
        build(p << 1 | 1, m + 1, r, init);
        push_up(p);
    }

    void update(int p, int l, int r, int L, int R, Lazy x) {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return f[p].update(x, r - l + 1), g[p].update(x);
        int m = (l + r) >> 1;
        push_down(p, l, m, r);
        update(p << 1, l, m, L, R, x);
        update(p << 1 | 1, m + 1, r, L, R, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return f[p];
        int m = (l + r) >> 1;
        push_down(p, l, m, r);
        return query(p << 1, l, m, L, R) + query(p << 1 | 1, m + 1, r, L, R);
    }
};