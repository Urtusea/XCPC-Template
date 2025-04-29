#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline std::vector<int> KMP_Z(const std::string& s) {
  std::vector<int> p(s.size());
  for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
    if (i <= r && p[i - l] < r - i + 1)
      p[i] = p[i - l];
    else {
      p[i] = std::max(0, r - i + 1);
      while (i + p[i] < s.size() && s[p[i]] == s[i + p[i]])
        p[i]++;
    }
    if (i + p[i] - 1 > r) {
      l = i;
      r = i + p[i] - 1;
    }
  }
  return p;
}