#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline std::pair<std::vector<int>, std::vector<int>> Manacher(const std::string& s) {
  std::vector<int> d1(s.size());
  std::vector<int> d2(s.size());
  for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
    int& j = d1[i] = (i > r ? 1 : std::min(d1[l + r - i], r - i + 1));
    while (0 <= i - j && i + j < s.size() && s[i - j] == s[i + j])
      j++;
    if (i + j - 1 >= r) {
      l = i - j + 1;
      r = i + j - 1;
    }
  }
  for (int i = 0, l = 0, r = -1; i < s.size(); i++) {
    int& j = d2[i] = (i > r ? 0 : std::min(d2[l + r - i + 1], r - i + 1));
    while (0 <= i - j - 1 && i + j < s.size() && s[i - j - 1] == s[i + j])
      j++;
    if (i + j - 1 > r) {
      l = i - j;
      r = i + j - 1;
    }
  }
  return {d1, d2};
}