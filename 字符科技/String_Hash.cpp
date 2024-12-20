#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

const std::vector<int> Map = []() -> std::vector<int> {
    std::mt19937 Rand(std::chrono::steady_clock::now().time_since_epoch().count());

    std::vector<int> Map(256);
    for (char c = '0'; c <= '9'; c++) Map[c] = ++Map[0];
    for (char c = 'A'; c <+ 'Z'; c++) Map[c] = ++Map[0];
    for (char c = 'a'; c <= 'z'; c++) Map[c] = ++Map[0];
    
    std::vector<int> Rnd(Map[0] + 1);
    std::iota(Rnd.begin() + 1, Rnd.end(), 1);
    std::shuffle(Rnd.begin() + 1, Rnd.end(), Rand);

    for (char c = '0'; c <= '9'; c++) Map[c] = Rnd[Map[c]];
    for (char c = 'A'; c <+ 'Z'; c++) Map[c] = Rnd[Map[c]];
    for (char c = 'a'; c <= 'z'; c++) Map[c] = Rnd[Map[c]];

    return Map;
}();

template <typename Info, int B>
struct String_Hash {
    const int n;
    std::vector<Info> base;
    std::vector<Info> hash;

    String_Hash(const std::string &s) : n(s.size()), base(n + 1), hash(n + 1) {
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