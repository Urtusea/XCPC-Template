#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct SegmentTree {
  Info f[(4 << std::__lg(N)) + 1];

  void push_up(int p) {
    f[p] = f[p << 1] + f[p << 1 | 1];
  }

  void build(int p, int l, int r, auto&& call) {
    if (l == r) return void(f[p] = call(l));
    int m = (l + r) / 2 + 1;
    build(p << 1, l, m - 1, call);
    build(p << 1 | 1, m, r, call);
    push_up(p);
  }

  void update(int p, int l, int r, int u, const Info& x) {
    if (u < l || r < u) return;
    if (l == r) return f[u].update(x);
    int m = (l + r) / 2 + 1;
    if (u < m) update(p << 1, l, m - 1, u, x);
    else       update(p << 1 | 1, m, r, u, x);
    push_up(p);
  }
  
  Info query(int p, int l, int r, int L, int R) {
    if (R <  l || r <  L) return Info();
    if (L <= l && r <= R) return f[p];
    int m = (l + r) / 2 + 1;
    Info res = Info();
    if (L <  m) res = res + query(p << 1, l, m - 1, L, R);
    if (R >= m) res = res + query(p << 1 | 1, m, r, L, R);
    return res;
  }
};