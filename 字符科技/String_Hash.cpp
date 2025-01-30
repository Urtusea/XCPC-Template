#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr std::array<int, 128> Rand() {
    uInt seed = 114514;
    for (auto c : __TIME__ __TIMESTAMP__) {
        seed += c;
        seed ^= seed << 13;
        seed ^= seed >> 7;
        seed ^= seed << 17;
    }
    std::array<int, 128> Map = {};
    for (char c = '0'; c <= '9'; c++) Map[c] = seed++ % 64 + 1;
    for (char c = 'A'; c <= 'Z'; c++) Map[c] = seed++ % 64 + 1;
    for (char c = 'a'; c <= 'z'; c++) Map[c] = seed++ % 64 + 1;
    return Map;
}

template <typename Info, int B>
struct String_Hash {
    constexpr static std::array<int, 128> Map = Rand();
    int n;
    Info *base;
    Info *hash;

    String_Hash(const std::string &s) {
        n = s.size();
        base = new Info[n + 1]();
        hash = new Info[n + 1]();
        base[0] = 1;
        for (int i = 0; i < n; i++) {
            base[i + 1] = base[i] * B;
            hash[i + 1] = hash[i] + base[i] * Map[s[i]];
        }
    }

    Info query(int l, int r) {
        return (hash[r] - hash[l - 1]) * base[n - l + 1];
    }
};