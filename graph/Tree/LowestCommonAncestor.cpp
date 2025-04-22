#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct LowestCommonAncestor {
  int n;
  int g[N + 1];
  int f[std::__lg(N) + 1][N + 1];

  inline constexpr int comp(int l, int r) const noexcept {
    return g[l] < g[r] ? l : r;
  }

  void build(int _n, int root, const auto& G) {
    n = _n;
    
    int timer = 0;
    const auto dfs = [&](auto&& self, int u, int p) -> void {
      f[0][g[u] = ++timer] = p;
      for (auto to : G[u]) {
        if (to.v == p) continue;
        self(self, to.v, u);
      }
    };
    dfs(dfs, root, 0);

    for (int k = 1; k <= std::__lg(n); k++)
      for (int i = 1; i + (1 << k) - 1 <= n; i++)
        f[k][i] = comp(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
  }

  int query(int u, int v) {
    if (u == v) return u;
    u = g[u];
    v = g[v];
    if (u <= v) std::swap(u, v);
    const int k = std::__lg(u - v++);
    return comp(f[k][v], f[k][u - (1 << k) + 1]);
  }
};