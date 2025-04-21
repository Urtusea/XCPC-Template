#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N, int B> struct BitTrie {
  using T = std::conditional_t<(B <= 31), uint, uInt>;
  
  static constexpr int S = []() {
    int res = 0;
    for (int i = 0; i < B; i++) {
      res += std::min<Int>(1LL << i, N);
    }
    return res;
  }();

  int lst;
  int son[S + 1][2];
  int cnt[S + 1];
  
  inline constexpr int nxt(int& p) & noexcept {
    return p ? p : p = ++lst;
  }

  void clear() {
    std::memset(son, 0, sizeof(son[0]) * (lst + 1));
    std::memset(cnt, 0, sizeof(cnt[0]) * (lst + 1));
    lst = 0;
  }

  void insert(T x, int u = 0) {
    for (int i = B - 1; i >= 0; i--)
      cnt[u = nxt(son[u][x >> i & 1])]++;
  }

  void erase(T x, int u = 0) {
    for (int i = B - 1; i >= 0; i--)
      cnt[u = son[u][x >> i & 1]]--;
  }
};