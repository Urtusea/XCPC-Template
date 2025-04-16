#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N, int M, auto Comp> struct SparseTable {
  int n;
  int m;
  Info f[std::__lg(N) + 1][std::__lg(M) + 1][N * M + 1];

  inline constexpr int pos(int i, int j) const noexcept {
    return (i - 1) * m + j;
  }

  void init(int _n, int _m, auto&& _init) {
    n = _n;
    m = _m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        f[0][0][pos(i, j)] = _init(i, j);
    for (int x = 0; x <= std::__lg(n); x++) {
      for (int y = 0; y <= std::__lg(m); y++) {
        if (x == 0 && y == 0) [[__unlikely__]] continue;
        for (int i = 1; i + (1 << x) - 1 <= n; i++) {
          for (int j = 1; j + (1 << y) - 1 <= m; j++) {
            if (y == 0)
              f[x][y][pos(i, j)] = Comp(f[x - 1][y][pos(i, j)], f[x - 1][y][pos(i + (1 << (x - 1)), j)]);
            else
              f[x][y][pos(i, j)] = Comp(f[x][y - 1][pos(i, j)], f[x][y - 1][pos(i, j + (1 << (y - 1)))]);
          }
        } 
      }
    }
  }

  Info query(int l1, int r1, int l2, int r2) {
    const int k1 = std::__lg(l2 - l1 + 1);
    const int k2 = std::__lg(r2 - r1 + 1);
    return Comp(
      Comp(f[k1][k2][pos(l1, r1)], f[k1][k2][pos(l2 - (1 << k1) + 1, r2 - (1 << k2) + 1)]),
      Comp(f[k1][k2][pos(l1, r2 - (1 << k2) + 1)], f[k1][k2][pos(l2 - (1 << k1) + 1, r1)])
    );
  }
};

static constexpr auto Min = [](auto l, auto r) -> auto { return std::min(l, r); };
static constexpr auto Max = [](auto l, auto r) -> auto { return std::max(l, r); };
template <typename Info, int N, int M> using MinST = SparseTable<Info, N, M, Min>;
template <typename Info, int N, int M> using MaxST = SparseTable<Info, N, M, Max>;