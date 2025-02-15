#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N, int B> struct String_Hash {
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

    int n;
    std::vector<Info> base;
    std::vector<Info> hash;

    

    Info query(int l, int r) {
        return (hash[r] - hash[l - 1]) * base[n - l + 1];
    }
};