#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct FenwickTree {
  int n;
  Info f[N + 1];

  void init(int _n, auto&& call) {
    n = _n;
    for (int i = 1; i <= n; i++) {
      f[i] += call(i);
      if (i + (i & -i) <= n)
        f[i + (i & -i)] += f[i];
    }
  }

  void update(int u, Info x) {
    for (int i = u; i <= n; i += i & -i)
      f[i] += x;
  }

  Info query(int u, Info x = Info()) {
    for (int i = u; i; i &= i - 1)
      x += f[i];
    return x;
  }
};