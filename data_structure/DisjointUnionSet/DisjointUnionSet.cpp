#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct DisjointUnionSet {
  int set[N + 1];

  void init(int n) {
    std::fill(set, set + n + 1, -1);
  }

  int find(int u) {
    return set[u] < 0 ? u : set[u] = find(set[u]);
  }

  void merge(int u, int v) {
    if (u = find(u), v = find(v); u == v) return;
    set[u] <= set[v] && (set[u] += set[v], set[v] = u);
    set[u] >= set[v] && (set[v] += set[u], set[u] = v);
  }
};