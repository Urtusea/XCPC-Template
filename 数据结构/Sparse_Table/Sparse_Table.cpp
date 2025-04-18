#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, Info (*Comp)(Info l, Info r), int N> struct Sparse_Table {
    int n;
    Info f[N * (std::__lg(N) + 1) + 1];

    inline constexpr int pos(int i, int j) const noexcept {
        return i * n + j;
    }

    void init(int _n, std::vector<Info> &init) {
        n = _n;
        for (int i = 1; i <= n; i++)
            f[i] = init[i];
    }

    void build() {
        for (int j = 1; j <= std::__lg(n); j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                f[pos(j, i)] = Comp(f[pos(j - 1, i)], f[pos(j - 1, i + (1 << (j - 1)))]);
    }

    Info query(int l, int r) {
        int k = std::__lg(r - l + 1);
        return Comp(f[pos(k, l)], f[pos(k, r - (1 << k) + 1)]);
    }
};