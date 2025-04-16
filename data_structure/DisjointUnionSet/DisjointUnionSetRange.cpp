#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct DisjointUnionSet {
  int set[std::__lg(N) + 1][N + 1];

  void init(int n) {
    for (int i = 0; i <= std::__lg(n); i++)
      std::fill(set[i], set[i] + n + 1, -1);
  }

  int find(int k, int u) {
    return set[k][u] < 0 ? u : set[k][u] = find(k, set[k][u]);
  }

  void merge(int k, int u, int v) {
    if (u = find(k, u), v = find(k, v); u == v) return;
    set[k][u] <= set[k][v] && (set[k][u] += set[k][v], set[k][v] = u);
    set[k][u] >= set[k][v] && (set[k][v] += set[k][u], set[k][u] = v);
  }

  void merge_range(int k, int u, int v, auto&& call) {
    if (find(k, u) == find(k, v)) return;
    if (k == 0) {
      call(find(k, u), find(k, v));
    } else {
      merge_range(k - 1, u, v, call);
      merge_range(k - 1, u + (1 << (k - 1)), v + (1 << (k - 1)), call);
    }
    merge(k, u, v);
  }
};