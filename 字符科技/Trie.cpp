#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int M[] = {0, 10, 26, 36, 26, 36, 52, 62};

template <int N, int State, int M = M[State]>
struct Trie {
    constexpr static std::array<int, 128> Map = []() -> std::array<int, 128> {
        std::array<int, 128> Map = {};
        if constexpr (State >> 0 & 1) for (char c = '0'; c <= '9'; c++) Map[c] = Map[0]++;
        if constexpr (State >> 1 & 1) for (char c = 'A'; c <= 'Z'; c++) Map[c] = Map[0]++;
        if constexpr (State >> 2 & 1) for (char c = 'a'; c <= 'z'; c++) Map[c] = Map[0]++;
        return Map;
    };
    int idx;
    int nxt[N + 1][M + 2];

    void clear() {
        std::memset(nxt, 0, sizeof(nxt[0]) * (idx + 1));
        idx = 0;
    }

    int get_next(int &p) {
        return p ? p : p = ++idx;
    }

    void insert(const std::string &s, int u = 0) {
        for (auto &c : s)
            nxt[u = get_next(nxt[u][Map[c]])][M]++;
        nxt[u][M + 1]++;
    }

    void erase(const std::string &s, int u = 0) {
        for (auto &c : s)
            nxt[u = get_next(nxt[u][Map[c]])][M]--;
        nxt[u][M + 1]--;
    }

    int count(const std::string &s, int Mode = 0, int u = 0) {
        for (auto &c : s)
            if ((u = nxt[u][Map[c]]) == 0) return 0;
        return nxt[u][M + Mode];
    }
};