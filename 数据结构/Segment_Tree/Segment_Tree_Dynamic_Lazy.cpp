#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Lazy, uint Size>
struct Segment_Tree_Dynamic {
    struct Node {
        Info data;
        Lazy post;
        uint lson;
        uint rson;

        Node()
        : data(Info()), post(Lazy()), lson(0), rson(0) {}
    };
    uint last;
    Node node[Size / (sizeof(Node) / sizeof(uint))];

    Segment_Tree_Dynamic()
    : last(0) {}

    void clear() {
        std::memset(node, 0, sizeof(node) * last);
        last = 0;
    }

    void push_up(uint p) {
        node[p].data = node[node[p].lson].data + node[node[p].rson].data;
    }

    void push_down(uint p, int l, int r) {
        if (!node[p].lson) node[p].lson = ++last;
        if (!node[p].rson) node[p].rson = ++last;
        const auto edit = [&](int u, int node_size) -> void {
            node[u].data.update(node[p].post, node_size);
            node[u].post.update(node[p].post);
        };
        int m = (l + r) >> 1;
        edit(node[p].lson, m - l + 1);
        edit(node[p].rson, r - m);
        node[p].post.clear();
    }

    void update(uint &p, int l, int r, int L, int R, Lazy tag) {
        if (!p) p = ++last;
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return (void)(node[p].data.update(tag, r - l + 1), node[p].post.update(tag));
        int m = (l + r) >> 1;
        push_down(p, l, r);
        update(node[p].lson, l, m, L, R, tag);
        update(node[p].rson, m + 1, r, L, R, tag);
        push_up(p);
    }

    Info query(uint p, int l, int r, int L, int R) {
        if (!p || R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p].data;
        int m = (l + r) >> 1;
        push_down(p, l, r);
        return query(node[p].lson, l, m, L, R) + query(node[p].rson, m + 1, r, L, R);
    }
};

enum uint_size {
    uint_64m  = 1 << 24,
    uint_128m = 1 << 25,
    uint_256m = 1 << 26,
    uint_512m = 1 << 27
};