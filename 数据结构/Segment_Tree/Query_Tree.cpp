#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct Query_Tree {
    std::vector<Info> f[4 << std::__lg(N)];

    void update(int p, int l, int r, int L, int R, Info &x) {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return f[p].push_back(x);
        int m = (l + r) >> 1;
        update(p << 1 | 1, l, m, L, R, x);
        update(p << 1, m + 1, r, L, R, x);
    }

    void dfs(int p, int l, int r, auto &&add, auto &&del, auto &&call) {
        add(f[p]);
        if (l == r)
            return call();
        int m = (l + r) >> 1;
        dfs(p << 1 | 1, l, m);
        dfs(p << 1, m + 1, r);
        del(f[p]);
    }
};