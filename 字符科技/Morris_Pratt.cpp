#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr int Morris_Pratt(const std::string &s) {
    int n = s.size(), i = 0, j = 1, len = 0;
    for (int len = 0; i < n && j < n && len < n; i == j && j++) {
        int l = (i + len) % n;
        int r = (j + len) % n;
        if (s[l] == s[r])
            len++;
        else {
            s[l] > s[r] ? i += len + 1 : j += len + 1;
            len = 0;
        }
    }
    return std::min(i, j);
}