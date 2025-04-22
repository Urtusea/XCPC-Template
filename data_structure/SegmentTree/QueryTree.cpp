#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct SegmentTree {
  std::vector<Info> f[(4 << std::__lg(N)) + 1];

  void build(int p, int l, int r) {
    f[p].clear();
    if (l == r) return;
    int m = (l + r) / 2 + 1;
    build(p << 1, l, m - 1);
    build(p << 1 | 1, m, r);
  }

  void update(int p, int l, int r, int L, int R, const Info& x) {
    if (R <  l || r <  L) return;
    if (L <= l && r <= R) return f[p].push_back(x);
    int m = (l + r) / 2 + 1;
    if (L <  m) update(p << 1, l, m - 1, L, R, x);
    if (R >= m) update(p << 1 | 1, m, r, L, R, x);
  }

  void query(int p, int l, int r, int L, int R, auto&& add, auto&& del, auto&& call) {
    add(f[p]);
    if (l == r) {
      call(p);
    } else {
      int m = (l + r) / 2 + 1;
      query(p << 1, l, m - 1, L, R, add, del, call);
      query(p << 1 | 1, m, r, L, R, add, del, call);
    }
    del(f[p]);
  }
};