#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct SegmentTree {
  int lst;
  int son[N * (std::__lg(N) + 1)][2];
  Info f[N * (std::__lg(N) + 1)];

  void push_up(int p) {
    f[p] = f[son[p][0]] + f[son[p][1]];
  }

  void build(int p, int l, int r, auto&& call) {
    if (l == r) return f[p] = call(l);
    int m = (l + r) / 2 + 1;
    build(son[p][0] = p << 1, l, m - 1);
    build(son[p][1] = p << 1 | 1, m, r);
    push_up(p);
  }

  void update(int &p, int q, int l, int r, int u, const Info& x) {
    if (u < l || r < u) return;
    f[++p] = f[q];
    son[p][0] = son[q][0];
    son[p][1] = son[q][1];
    if (l == r) f[p].update(x);
    int m = (l + r) / 2 + 1;
    if (u < m) update(son[p][0], son[q][0], l, m - 1, u, x);
    else update(son[p][1], son[q][1], m, r, u, x);
    push_up(p);
  }

  Info query(int p, int l, int r, int L, int R) {
    if (R <  l || r <  L) [[unlikely]] return Info();
    if (L <= l && r <= R) return f[p];
    int m = (l + r) / 2 + 1;
    Info res = Info();
    if (L <  m) res = res + query(son[p][0], l, m - 1, L, R);
    if (R >= m) res = res + query(son[p][1], m, r, L, R);
    return res;
  }
};