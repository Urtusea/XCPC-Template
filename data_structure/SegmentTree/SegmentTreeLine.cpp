#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T> struct Line {
  T k, b;
  Line() {}
  constexpr T operator () (int x) const {
    return k * x + b;
  }
};

template <typename T> struct LineID : public Line<T> {
  int id;
  LineID() {}
};

template <typename Info, auto Comp, int N> struct SegmentTree {
  Info f[(4 << std::__lg(N)) + 1];

  void push_down(int p, int l, int r, const Info& line) {
    int m = (l + r) / 2 + 1;
    if (Comp(f[p], line, m)) std::swap(f[p], line);
    if (Comp(f[p], line, l)) push_down(p << 1, l, m - 1, line);
    if (Comp(f[p], line, r)) push_down(p << 1 | 1, m, r, line);
  }

  void update(int p, int l, int r, int L, int R, const Info& line) {
    if (L <= l && r <= R) return push_down(p, l, r, line);
    int m = (l + r) / 2 + 1;
    if (L <  m) update(p << 1, l, m - 1, L, R, line);
    if (R >= m) update(p << 1 | 1, m, r, L, R, line);
  }
};