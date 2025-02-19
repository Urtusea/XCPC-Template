#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct Disjoint_Set_Union_Rollback {
    int p;
    int s[N + 1];
    int f[N + 1];
    int g[N + 1];
    
    void init(int n) {
        p = 0;
        std::iota(f, f + n + 1, 0);
        std::fill(g, g + n + 1, 1);
    }

    int find(int u) {
        return u == f[u] ? u : find(f[u]);
    }

    void merge(int u, int v) {
        int fu = find(u);
        int fv = find(v);
        if (fu == fv) return;

        if (g[u] > g[v]) {
            s[++p] = v;
            f[v] = u;
            g[u] += g[v];
        } else {
            s[++p] = u;
            f[u] = v;
            g[v] += g[u];
        }
    }
    void rollback() {
        int u = s[p--];
        int v = f[u];
        do {
            g[v] -= g[u];
        } while (v != f[v]);
        f[u] = u;
    }
};