#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct Fenwick_Tree {
    int n;
    Info f[N + 1];

    void init(int _n) {
        n = _n;
        std::fill(f, f + n + 1, Info());
    }

    void update(int u, Info x) {
        for (; u <= n; u += -u & u)
            f[u] += x;
    }

    Info query(int u, Info x = Info()) {
        for (; u; u -= -u & u)
            x += f[u];
        return x;
    }
};