#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N, int B, int Build_Mode>
struct Bit_Trie {
    using T = std::conditional_t<(B <= 31), uint, uInt>;
    int idx;
    int cnt[N * B];
    int nxt[N * B][2];

    void clear() {
        std::memset(cnt, 0, sizeof(cnt[0]) * (idx + 1));
        std::memset(nxt, 0, sizeof(nxt[0]) * (idx + 1));
        idx = 0;
    }

    int get_next(int &p) {
        return p ? p : p = ++idx;
    }

    void insert(const T x, int u = 0) {
        if constexpr (Build_Mode == 1) {
            for (int i = B - 1; i >= 0; i--)
                cnt[u = get_next(nxt[u][x >> i & 1])]++;
        } else {
            for (int i = 0; i < B; i++)
                cnt[u = get_next(nxt[u][x >> i & 1])]++;
        }
    }

    void erase(const T x, int u = 0) {
        if constexpr (Build_Mode == 1) {
            for (int i = B - 1; i >= 0; i--)
                cnt[u = get_next(nxt[u][x >> i & 1])]--;
        } else {
            for (int i = 0; i < B; i++)
                cnt[u = get_next(nxt[u][x >> i & 1])]--;
        }
    }

    int count(const T x, int u = 0) {
        if constexpr (Build_Mode == 1) {
            for (int i = B - 1; i >= 0; i--)
                if ((u = nxt[u][x >> i & 1]) == 0) return 0;
        } else {
            for (int i = 0; i < B; i++)
                if ((u = nxt[u][x >> i & 1]) == 0) return 0;
        }
        return cnt[u];
    }
};