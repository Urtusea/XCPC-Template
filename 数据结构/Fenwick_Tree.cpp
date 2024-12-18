#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info>
struct Fenwick_Tree {
    const int n;
    Info *node;

    Fenwick_Tree(int _n = 0) : n(_n) {
        node = new Info[_n + 1]();
    }

    void update(int u, Info x) {
        for (int i = u; i <= n; i += i & -i)
            node[i] += x;
    }

    Info query(int u, Info x = Info()) {
        for (int i = u; i; i -= i & -i)
            x += node[i];
        return x;
    }
};