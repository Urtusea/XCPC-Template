#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct DisjointUnionSet {
  int cnt;
  int stk[N + 1];
  int set[N + 1];
  int siz[N + 1];

  void init(int n) {
    cnt = 0;
    std::iota(set, set + n + 1, 0);
    std::fill(siz, siz + n + 1, 1);
  }

  int find(int u) {
    while (u != set[u]) u = set[u]; return u;
  }

  int merge(int u, int v) {
    if (u = find(u), v = find(v); u == v) return 0;
    siz[u] >= siz[v] && (set[v] = u, siz[u] += siz[v], stk[++cnt] = v);
    siz[u] <= siz[v] && (set[u] = v, siz[v] += siz[u], stk[++cnt] = u);
    return 1;
  }

  void rollback() {
    int u = stk[cnt--];
    siz[set[u]] -= siz[u];
    set[u] = u;
  }
};