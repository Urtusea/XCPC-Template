#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N, auto Comp> struct SparseTable {
  int n;
  Info f[std::__lg(N) + 1][N + 1];

  void init(int _n, auto&& _init) {
    n = _n;
    for (int i = 1; i <= n; i++)
      f[0][i] = _init(i);
    for (int k = 1; k <= std::__lg(n); k++)
      for (int i = 1; i + (1 << k) - 1 <= n; i++)
        f[k][i] = Comp(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
  }

  Info query(int l, int r) {
    const int k = std::__lg(r - l + 1);
    return Comp(f[k][l], f[k][r - (1 << k) + 1]);
  }
};

static constexpr auto Min = [](auto l, auto r) -> auto { return std::min(l, r); };
static constexpr auto Max = [](auto l, auto r) -> auto { return std::max(l, r); };
template <typename Info, int N> using MinST = SparseTable<Info, N, Min>;
template <typename Info, int N> using MaxST = SparseTable<Info, N, Max>;