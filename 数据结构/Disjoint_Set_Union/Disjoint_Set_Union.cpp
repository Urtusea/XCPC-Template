#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct Disjoint_Set_Union {
    int f[N + 1];
    int g[N + 1];

    void init(int n) {
        std::iota(f, f + n + 1, 0);
        std::fill(g, g + n + 1, 1);
    }

    int find(int u) {
        return u == f[u] ? u : f[u] = find(f[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (g[u] > g[v]) {
            f[v] = u;
            g[u] += g[v];
        } else {
            f[u] = v;
            g[v] += g[u];
        }
    }
};