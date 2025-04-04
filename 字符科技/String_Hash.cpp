#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int B, int N> struct String_Hash {
    constexpr static std::array<int, 128> Map = []() -> std::array<int, 128> {
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
    }();
    constexpr static std::array<Info, N + 1> base = []() -> std::array<Info, N + 1> {
        std::array<Info, N + 1> base = {};
        base[0] = 1;
        for (int i = 1; i <= N; i++)
            base[i] = base[i - 1] * B;
        return base;
    }();

    int n;
    std::vector<Info> hash;

    String_Hash(const std::string &s) : n(s.size()), hash(s.size() + 1) {
        for (int i = 0; i < n; i++)
            hash[i + 1] = hash[i] + base[i] * Map[s[i]];
    }

    Info query(int l, int r) {
        return (hash[r] - hash[l - 1]) * base[N - l + 1];
    }
};