#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct Lowest_Common_Ancestor {
    int n;
    int g[N + 1];
    int f[N * (std::__lg(N) + 1) + 1];

    inline constexpr int pos(int i, int j) const noexcept {
        return i * n + j;
    }
    
    int comp(int l, int r) {
        return g[l] < g[r] ? l : r;
    }

    void build(int _n, int root, const auto &G) {
        n = _n;

        int timer = 0;
        const auto dfs = [&](auto &&self, int u, int p) -> void {
            f[g[u] = ++timer] = p;
            for (auto to : G[u]) {
                if (to.v == p) continue;
                self(self, to.v, u);
            }
        };
        dfs(dfs, root, 0);

        for (int k = 1; k <= std::__lg(n); k++)
            for (int i = 1; i + (1 << k) <= n + 1; i++)
                f[pos(k, i)] = comp(f[pos(k - 1, i)], f[pos(k - 1, i + (1 << (k - 1)))]);
    }

    int query(int u, int v) {
        if (u == v) return u;
        u = g[u];
        v = g[v];
        
        if (u > v) {
            const int k = std::__lg(u - v++);
            return comp(f[pos(k, v)], f[pos(k, u - (1 << k) + 1)]);
        } else {
            const int k = std::__lg(v - u++);
            return comp(f[pos(k, u)], f[pos(k, v - (1 << k) + 1)]);
        }
    }
};