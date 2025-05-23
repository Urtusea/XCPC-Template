#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct CartesianTree {
  int l[N + 1];
  int r[N + 1];

  void build(int n, const auto& init, auto&& comp) {
    std::vector<int> stk = {0};
    for (int i = 1; i <= n; i++) {
      while (comp(init[i], init[stk.back()])) {
        l[i] = stk.back();
        stk.pop_back();
      }
      r[stk.back()] = i;
      stk.push_back(i);
    }
  }
};