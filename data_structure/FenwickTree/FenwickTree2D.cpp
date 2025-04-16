#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct FenwickTree {
  int n;
  int m;
  Info f[N + 1];

  inline constexpr int pos(int i, int j) const noexcept {
    return (i - 1) * m + j;
  }

  void init(int _n, int _m, auto&& call) {
    n = _n;
    m = _m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[pos(i, j)] += call(i, j);
        if (i + (i & -i) <= n && j + (j & -j) <= m)
          f[pos(i + (i & -i), j + (j & -j))] += f[pos(i, j)];
      }
    }
  }

  void update(int x, int y, Info u) {
    for (int i = x; i <= n; i += i & -i)
      for (int j = y; j <= m; j += j & -j)
        f[pos(i, j)] += u;
  }

  Info query(int x, int y, Info u = Info()) {
    for (int i = x; i; i &= i - 1)
      for (int j = y; j; j &= j - 1)
        u += f[pos(i, j)];
    return u;
  }
};