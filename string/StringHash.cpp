#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int B> struct StringHash {
  int n;
  std::vector<Info> f;
  std::vector<Info> g;

  StringHash(const std::string& s, int offset = 0) : n(s.size() - offset), f(n + 1), g(n + 1) {
    const std::string_view S(s.begin() + offset, s.end());
    for (int i = 0; i < n; i++) {
      f[i + 1] = f[i] * B + s[i];
      g[i + 1] = g[i] * B;
    }
  }

  Info query(int l, int r) {
    return f[r] - f[l - 1] * g[r - l + 1];
  }
};