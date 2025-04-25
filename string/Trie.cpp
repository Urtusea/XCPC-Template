#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int S, int N> struct Trie {
  static constexpr int M = []() {
    int res = 0;
    if (S >> 0 & 1) res += 10;
    if (S >> 1 & 1) res += 26;
    if (S >> 2 & 1) res += 26;
    return res;
  }();
  static constexpr std::array<int, 128> Map = []() {
    std::array<int, 128> res = {};
    if (S >> 0 & 1) for (char c = '0'; c <= '9'; c++) res[c] = res[0]++;
    if (S >> 1 & 1) for (char c = 'A'; c <= 'Z'; c++) res[c] = res[0]++;
    if (S >> 2 & 1) for (char c = 'a'; c <= 'z'; c++) res[c] = res[0]++;
  }();

  int lst;
  int son[N + 1][M];
  int cnt[N + 1][2];

  inline constexpr int nxt(int& p) & noexcept {
    return p ? p : p = ++lst;
  }

  void clear() {
    std::memset(son, 0, sizeof(son[0]) * (lst + 1));
    std::memset(cnt, 0, sizeof(cnt[0]) * (lst + 1));
    lst = 0;
  }

  void insert(const std::string& s, int u = 0) {
    for (auto c : s) cnt[u = nxt(son[u][Map[c]])][0]++;
    cnt[u][1]++;
  }

  void erase(const std::string& s, int u = 0) {
    for (auto c : s) cnt[u = son[u][Map[c]]][0]--;
    cnt[u][1]--;
  }

  int count(const std::string& s, int t = 0, int u = 0) {
    for (auto c : s) if (!(u = son[u][Map[c]])) return 0;
    return cnt[u][t];
  }
};