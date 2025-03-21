#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int M[] = {0, 10, 26, 36, 26, 36, 52, 62};

template <int State, int N, int M = M[State]> struct Automaton {
    constexpr static std::array<int, 128> Map = []() -> std::array<int, 128> {
        std::array<int, 128> Map = {};
        if constexpr (State >> 0 & 1) for (char c = '0'; c <= '9'; c++) Map[c] = Map[0]++;
        if constexpr (State >> 1 & 1) for (char c = 'A'; c <= 'Z'; c++) Map[c] = Map[0]++;
        if constexpr (State >> 2 & 1) for (char c = 'a'; c <= 'z'; c++) Map[c] = Map[0]++;
        return Map;
    }();
    int p;
    int f[N + 1][M + 3];

    inline constexpr int nxt(int &u) & noexcept {
        return u ? u : u = ++p;
    }

    void clear() {
        std::memset(f, 0, sizeof(f[0]) * (p + 1));
        p = 0;
    }

    void insert(const std::string &s, int u = 0) {
        for (auto &c : s)
            f[u = nxt(f[u][Map[c]])][M]++;
        f[u][M + 1]++;
    }

    void erase(const std::string &s, int u = 0) {
        for (auto &c : s)
            f[u = nxt(f[u][Map[c]])][M]--;
        f[u][M + 1]--;
    }

    void build() {
        std::queue<int> q;
        for (int i = 0; i < M; i++)
            if (f[0][i]) q.push(f[0][i]);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (int v = 0, j = f[u][M + 2]; v < M; v++) {
                if (f[u][v]) {
                    f[f[u][v]][M + 2] = f[j][v];
                    q.push(f[u][v]);
                } else {
                    f[u][v] = f[j][v];
                }
            }
        }
    }

    int query(const std::string &s, int u = 0, int res = 0) {
        for (auto &c : s) {
            for (int v = (u = f[u][Map[c]]); v && f[v][M + 1] != -1; v = f[v][M + 2]) {
                res += f[v][M + 1];
                f[v][M + 1] = -1;
            }
        }
        return res;
    }
};