#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Lazy, typename Feat, int N> struct SegmentTree {
  Info f[(4 << std::__lg(N)) + 1];
  Lazy g[(4 << std::__lg(N)) + 1];

  void push_up(int p) {
    f[p] = f[p << 1] + f[p << 1 | 1];
  }

  void push_down(int p, int l, int r) {
    const auto edit = [&](int u, int node_size) {
      f[u].update(g[p], node_size);
      f[u].angle(f[p], node_size);
      g[u].update(g[p]);
    };
    int m = (l + r) / 2;
    edit(p << 1, m - l + 1);
    edit(p << 1 | 1, r - m);
    g[p].clear();
  }

  void build(int p, int l, int r, auto&& call) {
    g[p].clear();
    if (l == r) return void(f[p] = call(l));
    int m = (l + r) / 2 + 1;
    build(p << 1, l, m - 1, call);
    build(p << 1 | 1, m, r, call);
    push_up(p);
  }

  void update(int p, int l, int r, int L, int R, const Lazy& tag) {
    if (R <  l || r <  L) [[unlikely]] return;
    if (L <= l && r <= R) {
      f[p].update(tag, r - l + 1);
      g[p].update(tag);
      return;
    }
    int m = (l + r) / 2 + 1;
    push_down(p, l, r);
    if (L <  m) update(p << 1, l, m - 1, L, R, tag);
    if (R >= m) update(p << 1 | 1, m, r, L, R, tag);
    push_up(p);
  }

  void angel(int p, int l, int r, int L, int R, const Feat& tag, auto&& check) {
    if (R <  l || r <  L || check(f[p], tag) == 0) return;
    if (L <= l && r <= R && check(f[p], tag) == 1) return f[p].angel(tag, r - l + 1);
    int m = (l + r) / 2 + 1;
    push_down(p, l, r);
    if (L <  m) update(p << 1, l, m - 1, L, R, tag, check);
    if (R >= m) update(p << 1 | 1, m, r, L, R, tag, check);
    push_up(p);
  }

  Info query(int p, int l, int r, int L, int R) {
    if (R <  l || r <  L) [[unlikely]] return Info();
    if (L <= l && r <= R) return f[p];
    int m = (l + r) / 2 + 1;
    Info res = Info();
    push_down(p, l, r);
    if (L <  m) res = res + query(p << 1, l, m - 1, L, R);
    if (R >= m) res = res + query(p << 1 | 1, m, r, L, R);
    return res;
  }
};