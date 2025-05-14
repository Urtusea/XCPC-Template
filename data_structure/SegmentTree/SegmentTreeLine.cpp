#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T> struct Line {
  using type = T;
  T k, b;
  Line() : k(0), b(0) {}
  constexpr T operator () (Int x) const {
    return k * x + b;
  }
};

template <typename Info, auto Comp, int N> struct SegmentTree {
  using Type = typename Info::type;
  Info f[(4 << std::__lg(N)) + 1];

  void push_down(int p, int l, int r, Info line) {
    int m = (l + r) / 2 + 1;
    if (Comp(f[p], line, m)) std::swap(f[p], line);
    if (l == r) return;
    if (Comp(f[p], line, l)) push_down(p << 1, l, m - 1, line);
    if (Comp(f[p], line, r)) push_down(p << 1 | 1, m, r, line);
  }

  void update(int p, int l, int r, int L, int R, const Info line) {
    if (L <= l && r <= R) return push_down(p, l, r, line);
    int m = (l + r) / 2 + 1;
    if (L <  m) update(p << 1, l, m - 1, L, R, line);
    if (R >= m) update(p << 1 | 1, m, r, L, R, line);
  }

  Type query(int p, int l, int r, int x) {
    if (l == r) return f[p](x);
    int m = (l + r) / 2 + 1;
    Type res = f[p](x);
    if (x <  m) res = std::max(res, query(p << 1, l, m - 1, x));
    if (x >= m) res = std::max(res, query(p << 1 | 1, m, r, x));
    return res;
  }
};