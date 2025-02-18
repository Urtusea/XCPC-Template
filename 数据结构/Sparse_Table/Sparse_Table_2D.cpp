#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp, Comp Func(Info, Info), int N, int M> struct Sparse_Table_2D {
    int n;
    int m;
    Info f[std::__lg(N) + 1][std::__lg(M) + 1][N * M + 1];

    inline constexpr int pos(int i, int j) const noexcept {
        return (i - 1) * m + j;
    }

    void init(int _n, int _m, std::vector<std::vector<Info>> &init) {
        n = _n;
        m = _m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[0][0][pos(i, j)] = init[i][j];
    }

    void build() {
        for (int k = 1; k <= std::__lg(n); k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    f[k][0][pos(i, j)] = Func(f[k - 1][0][pos(i, j)], f[k - 1][0][pos(i + (1 << (k - 1)), j)]);
        for (int k = 1; k <= std::__lg(m); k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    f[0][k][pos(i, j)] = Func(f[0][k - 1][pos(i, j)], f[0][k - 1][pos(i, j + (1 << (k - 1)))]);
        for (int x = 1; x <= std::__lg(n); x++)
            for (int y = 1; y <= std::__lg(m); y++)
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        f[x][y][pos(i, j)] = Func(f[x][y - 1][pos(i, j)], f[x][y - 1][pos(i, j + (1 << (y - 1)))]);
    }

    Info query(std::array<int, 2> l, std::array<int, 2> r) {
        int x = std::__lg(r[0] - l[0] + 1);
        int y = std::__lg(r[1] - l[1] + 1);
        r[0] -= (1 << x) - 1;
        r[1] -= (1 << y) - 1;
        return Func(Func(f[x][y][pos(l[0], l[1])], f[x][y][pos(r[0], r[1])]), Func(f[x][y][pos(l[0], r[1])], f[x][y][pos(r[0], l[1])]));
    }
};