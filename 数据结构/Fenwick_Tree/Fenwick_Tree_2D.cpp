#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct Fenwick_Tree_2D {
    int n;
    int m;
    Info f[N + 1];

    inline constexpr int pos(int i, int j) const noexcept {
        return (i - 1) * m + j;
    }

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        std::fill(f, f + n * m + 1, Info());
    }

    void update(int u, int v, Info x) {
        for (int i = u; i <= n; i += -i & i)
            for (int j = v; j <= m; j += -j & j)
                f[pos(i, j)] += x;
    }

    Info query(int u, int v, Info x = Info()) {
        for (int i = u; i; i -= -i & i)
            for (int j = v; j; j -= -j & j)
                f[pos(i, j)] += x;
    }
};