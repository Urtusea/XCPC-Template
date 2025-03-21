#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N, int Q> struct Chairman_Tree {
    struct Node {
        Info val;
        int l, r;
        constexpr Node(Info _val = Info(), int _l = 0, int _r = 0) : val(_val), l(_l), r(_r) {}
    };
    int t = 0;
    Node f[(4 << std::__lg(N)) + Q * (std::__lg(N) + 2)];

    void push_up(int p) {
        f[p].val = f[f[p].l].val + f[f[p].r].val;
    }

    void build(int &p, int l, int r, Info init) {
        if (!p) p = ++t;
        if (l == r)
            return (void)(f[p].val = init);
        int m = (l + r) >> 1;
        build(f[p].l, l, m, init);
        build(f[p].r, m + 1, r, init);
        push_up(p);
    }

    void build(int &p, int l, int r, std::vector<Info> &init) {
        if (!p) p = ++t;
        if (l == r)
            return (void)(f[p].val = init[l]);
        int m = (l + r) >> 1;
        build(f[p].l, l, m, init);
        build(f[p].r, m + 1, r, init);
        push_up(p);
    }

    void update(int &p, int l, int r, int u, Info x) {
        if (!p) p = ++t;
        if (l == r)
            return (void)(f[p].val.update(x, r - l + 1));
        int m = (l + r) >> 1;
        if (u <= m)
            update(f[p].l, l, m, u, x);
        else
            update(f[p].r, m + 1, r, u, x);
        push_up(p);
    }

    void update(int &p, int q, int l, int r, int u, Info x) {
        f[p = ++t] = f[q];
        if (l == r)
            return (void)(f[p].val.update(x, r - l + 1));
        int m = (l + r) >> 1;
        if (u <= m)
            update(f[p].l, f[q].l, l, m, u, x);
        else
            update(f[p].r, f[q].r, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return f[p].val;
        int m = (l + r) >> 1;
        return query(f[p].l, l, m, L, R) + query(f[p].r, m + 1, r, L, R);
    }
};