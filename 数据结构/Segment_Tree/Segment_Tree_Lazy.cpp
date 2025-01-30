#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Lazy, typename Info>
struct Segment_Tree_Lazy {
#define lson (p << 1)
#define rson (p << 1 | 1)

    std::vector<Info> node;
    std::vector<Lazy> post;

    Segment_Tree_Lazy(int _n = 0)
    : node(4 << std::__lg(_n + 1)), post(4 << std::__lg(_n + 1)) {}

    void push_up(int p) {
        node[p] = node[lson] + node[rson];
    }

    void push_down(int p, int l, int r) {
        const auto edit = [&](int u, int node_size) -> void {
            node[u].update(post[p], node_size);
            post[u].update(post[p]);
        };
        int m = (l + r) >> 1;
        edit(lson, m - l + 1);
        edit(rson, r - m);
        post[p].clear();
    }

    void build(int p, int l, int r, const auto &init) {
        if (l == r)
            return (void)(node[p] = std::is_same<decltype(init), Info>::value ? init : init[l]);
        int m = (l + r) >> 1;
        build(lson, l, m, init);
        build(rson, m + 1, r, init);
        push_up(p);
    }

    void update(int p, int l, int r, int L, int R, Lazy x) {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return (void)(node[p].update(x, r - l + 1), post[p].update(x));
        int m = (l + r) >> 1;
        push_down(p, l, r);
        update(p << 1, l, m, L, R, x);
        update(rson, m + 1, r, L, R, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p];
        int m = (l + r) >> 1;
        push_down(p, l, r);
        return query(p << 1, l, m, L, R) + query(rson, m + 1, r, L, R);
    }

#undef lson
#undef rson
};