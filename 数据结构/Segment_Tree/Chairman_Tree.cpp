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
struct Chairman_Tree {
    struct Node {
        Info data;
        int lson;
        int rson;

        Node()
        : data(Info()), lson(0), rson(0) {}
    };
    int last;
    Node node[Size / (sizeof(Node) / sizeof(int))];

    Chairman_Tree()
    : last(0) {}

    void clear() {
        std::fill(node, node + last, Node());
        last = 0;
    }

    void push_up(int p) {
        node[p].data = node[node[p].lson].data + node[node[p].rson].data;
    }

    void build(int &p, int l, int r, Info init) {
        p = ++last;
        if (l == r)
            return (void)(node[p].data = init);
        int m = (l + r) >> 1;
        build(node[p].lson, l, m, init);
        build(node[p].rson, m + 1, r, init);
        push_up(p);
    }

    void build(int &p, int l, int r, std::vector<Info> &init) {
        p = ++last;
        if (l == r)
            return (void)(node[p].data = init[l]);
        int m = (l + r) >> 1;
        build(node[p].lson, l, m, init);
        build(node[p].rson, m + 1, r, init);
        push_up(p);
    }

    void update(int &p, int q, int l, int r, int u, Info x) {
        node[p = ++last] = node[q];
        if (l == r)
            return (void)(node[p].data.update(x, r - l + 1));
        int m = (l + r) >> 1;
        if (u <= m)
            update(node[p].lson, node[q].lson, l, m, u, x);
        else
            update(node[p].rson, node[q].rson, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int q, int l, int r, int L, int R) {
        if (!p || R < l || r < L)
            return Info();
        if (L <= l && r <= R)
            return node[p].data - node[q].data;
        int m = (l + r) >> 1;
        return query(node[p].lson, node[q].lson, l, m, L, R) + query(node[p].rson, node[q].rson, m + 1, r, L, R);
    }
};