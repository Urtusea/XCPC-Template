#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Lazy>
struct Segment_Tree_Lazy {
    Info *node;
    Lazy *post;

    Segment_Tree_Lazy(int _n = 0) {
        node = new Info[4 << std::__lg(_n + 1)]();
        post = new Lazy[4 << std::__lg(_n + 1)]();
    }

    void push_up(int p) {
        node[p] = node[p << 1] + node[p << 1 | 1];
    }

    void push_down(int p, int l, int r) {
        const auto edit = [&](int u, int node_size) -> void {
            node[u].update(post[p], node_size);
            post[u].update(post[p]);
        };
        const int m = (l + r) >> 1;
        edit(p << 1, m - l + 1);
        edit(p << 1 | 1, r - m);
        post[p].clear();
    }

    void build(int p, int l, int r, const std::vector<Info> &info) {
        if (l == r)
            return (void)(node[p] = info[l]);
        const int m = (l + r) >> 1;
        build(p << 1, l, m, info);
        build(p << 1 | 1, m + 1, r, info);
        push_up(p);
    }

    void build(int p, int l, int r) {
        if (l == r)
            return (void)(node[p] = Info());
        const int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        push_up(p);
    }

    void update(int p, int l, int r, int L, int R, Lazy x) {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return (void)(node[p].update(x, r - l + 1), post[p].update(x));
        const int m = (l + r) >> 1;
        push_down(p, l, r);
        update(p << 1, l, m, L, R, x);
        update(p << 1 | 1, m + 1, r, L, R, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p];
        const int m = (l + r) >> 1;
        push_down(p, l, r);
        return query(p << 1, l, m, L, R) + query(p << 1 | 1, m + 1, r, L, R);
    }
};