#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct DisjointUnionSet {
  int  set[N + 1];
  Info val[N + 1];

  void init(int n) {
    std::fill(set, set + n + 1, -1);
    std::fill(val, val + n + 1, Info());
  }

  int find(int u) {
    if (set[u] < 0) return u;
    int p = find(set[u]);
    val[u] += val[set[u]];
    return set[u] = p;
  }

  int merge(int u, int v, Info w) {
    w -= dist(u, v);
    if (u = find(u), v = find(v); u == v) return w == Info() ? 0 : -1;
    set[u] <= set[v] && (val[v] =  w, set[u] += set[v], set[v] = u);
    set[u] >= set[v] && (val[u] = -w, set[v] += set[u], set[u] = v);
    return 1;
  }

  Info dist(int u) {
    return find(u), val[u];
  }

  Info dist(int u, int v) {
    return dist(v) - dist(u);
  }
};