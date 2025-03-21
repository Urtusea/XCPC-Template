#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr std::vector<int> KMP(const std::string &a, const std::string &b) {
    std::string s = a + '#' + b;
    std::vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int j = p[i - 1];
        while (j && s[i] != s[j])
            j = p[j - 1];
        p[i] = j + (s[i] == s[j]);
    }
    return p;
}