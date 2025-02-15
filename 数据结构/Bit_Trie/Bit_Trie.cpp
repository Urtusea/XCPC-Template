#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N, int B> struct Bit_Trie {
    using T = std::conditional_t<(B <= 31), uint, uInt>;
    constexpr static int Size = []() -> int {
        int res = 0;
        for (int i = 0; i <= B; i++) {
            res += std::min(1 << i, N);
        }
        return res;
    }();
    int p;
    int f[Size + 1][3];
    
    void clear() {
        std::memset(f, 0, sizeof(f[0]) * (p + 1));
        p = 0;
    }

    int nxt(int &u) {
        return u ? u : u = ++p;
    }

    void insert(T x, int u = 0) {
        for (int i = B; i >= 0; i--)
            f[u = nxt(f[u][x >> i & 1])][2]++;
    }

    void erase(T x, int u = 0) {
        for (int i = B; i >= 0; i--)
            f[u = f[u][x >> i & 1]][2]--;
    }
};