#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr auto KMP(const std::string &a, const std::string &b) {
    const std::string s = a + '#' + b;
    int *p = new int[s.size()]();
    for (int i = 1; i < s.size(); i++) {
        int j = p[i - 1];
        while (j && s[i] != s[j])
            j = p[j - 1];
        p[i] = j + (s[i] == s[j]);
    }
    return p;
}