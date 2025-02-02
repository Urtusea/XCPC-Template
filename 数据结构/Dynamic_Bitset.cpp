#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct Dynamic_Bitset {
    static constexpr int width = 63;
    static constexpr int digit = 6;
    int n;
    int m;
    std::vector<uInt> node;

    Dynamic_Bitset(int _n = 0)
    : n(_n), m((_n + width) >> digit), node(m) {}

    bool get(int u) {
        return node[u >> digit] >> (u & width) & 1;
    }

    void flip(int u) {
        node[u >> digit] ^= 1ULL << (u & width);
    }

    void set(int u, int state) {
         state && (node[u >> digit] &= (~0ULL) ^ (1ULL << (u & width)));
        !state && (node[u >> digit] |= 1ULL << (u & width));
    }
};