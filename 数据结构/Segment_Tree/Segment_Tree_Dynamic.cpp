#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

enum int_size {
    int_4m   = 1 << 20,
    int_8m   = 1 << 21,
    int_16m  = 1 << 22,
    int_32m  = 1 << 23,
    int_64m  = 1 << 24,
    int_128m = 1 << 25,
    int_256m = 1 << 26,
    int_512m = 1 << 27
};

template <typename Info, int Size>
struct Segment_Tree_Dynamic {
    struct Node {
        Info data;
        int lson;
        int rson;

        Node()
        : data(Info()), lson(0), rson(0) {}
    };
    int last;
    Node node[Size / (sizeof(Node) / sizeof(int))];

    Segment_Tree_Dynamic()
    : last(0) {}

    void clear() {
        std::fill(node, node + last, Node());
        last = 0;
    }

    void push_up(int p) {
        node[p].data = node[node[p].lson].data + node[node[p].rson].data;
    }

    void update(int &p, int l, int r, int u, Info x) {
        if (!p) p = ++last;
        if (u < l || r < u)
            return;
        if (l == r)
            return (void)(node[p].data.update(x, r - l + 1));
        int m = (l + r) >> 1;
        if (u <= m)
            update(node[p].lson, l, m, u, x);
        else
            update(node[p].rson, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (!p || R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p].data;
        int m = (l + r) >> 1;
        return query(node[p].lson, l, m, L, R) + query(node[p].rson, m + 1, r, L, R);
    }
};