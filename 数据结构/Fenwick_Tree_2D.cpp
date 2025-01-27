#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info>
struct Fenwick_Tree_2D {
    int n;
    int m;
    std::vector<Info> node;

    Fenwick_Tree_2D(int _n = 0, int _m = 0)
    : n(_n), m(_m), node(_n * _m + 1) {}

    int pos(int x, int y) {
        return (x - 1) * m + y;
    }

    void update(int u, int v, Info x) {
        for (int i = u; i <= n; i += i & -i)
            for (int j = v; j <= m; j += j & -j)
                node[pos(i, j)] += x;
    }

    Info query(int u, int v, Info x = Info()) {
        for (int i = u; i; i -= i & -i)
            for (int j = v; j; j -= j & -j)
                x += node[pos(i, j)];
        return x;
    }
};