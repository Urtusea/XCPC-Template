#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct Query_Tree {
    std::vector<Info> f[4 << std::__lg(N)];

    void init(int n) {
        for (int i = 1; i < (4 << std::__lg(n)); i++)
            f[i].clear();
    }

    void add_query(int p, int l, int r, int L, int R, const Info &x) {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
            return f[p].push_back(x);
        int m = (l + r) >> 1;
        add_query(p << 1, l, m, L, R, x);
        add_query(p << 1 | 1, m + 1, r, L, R, x);
    }

    void query(int p, int l, int r, auto &&add, auto &&del, auto &&call) {
        add(f[p]);
        if (l == r) {
            call(l);
        } else {
            int m = (l + r) >> 1;
            query(p << 1, l, m, add, del, call);
            query(p << 1 | 1, m + 1, r, add, del, call);
        }
        del(f[p]);
    }
};