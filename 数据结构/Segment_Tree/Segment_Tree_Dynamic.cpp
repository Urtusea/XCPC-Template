#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, uint Size>
struct Segment_Tree_Dynamic {
    struct Node {
        Info data;
        uint lson;
        uint rson;

        Node()
        : data(Info()), lson(0), rson(0) {}
    };
    uint last;
    uint root;
    Node node[Size / (sizeof(Node) / sizeof(uint))];

    Segment_Tree_Dynamic()
    : last(0), root(0) {}

    void clear() {
        std::memset(node, 0, sizeof(node) * last);
        last = 0;
        root = 0;
    }

    void push_up(int p) {
        node[p].data = node[node[p].lson].data + node[node[p].rson].data;
    }

    void update(uint &p, int l, int r, int u, Info x) {
        if (!p) p = ++last;
        if (u < l || r < u)
            return;
        if (l == r)
            return (void)(node[p].data.update(x, r - l + 1));
        int m = (l + r) >> 1;
        update(node[p].lson, l, m, u, x);
        update(node[p].rson, m + 1, r, u, x);
        push_up(p);
    }

    Info query(uint p, int l, int r, int L, int R) {
        if (!p || R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p].data;
        int m = (l + r) >> 1;
        return query(node[p].lson, l, m, L, R) + query(node[p].rson, m + 1, r, L, R);
    }
};

enum uint_size {
    uint_64m  = 1ULL << 24,
    uint_128m = 1ULL << 25,
    uint_256m = 1ULL << 26,
    uint_512m = 1ULL << 27
};