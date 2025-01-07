#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct Lowest_Common_Ancestor {
    int n;
    int *dfn;
    int *node;

    Lowest_Common_Ancestor(int _n = 0) : n(_n) {
        dfn  = new int[_n + 1]();
        node = new int[(std::__lg(_n) + 1) * n + 1]();
    }

    int comp(int l, int r) {
        return dfn[l] < dfn[r] ? l : r;
    }

    int pos(int i, int j) {
        return i * n + j;
    }

    void build(int root, const auto &G) {
        int timer = 0;
        const auto dfs = [&](auto &&self, int u, int p) -> void {
            node[dfn[u] = ++timer] = p;
            for (auto to : G[u]) {
                if (to.v == p) continue;
                self(self, to.v, u);
            }
        };
        dfs(dfs, root, 0);

        for (int k = 1; k <= std::__lg(n); k++)
            for (int i = 1; i + (1 << k) <= n + 1; i++)
                node[pos(k, i)] = comp(node[pos(k - 1, i)], node[pos(k - 1, i + (1 << (k - 1)))]);
    }

    int query(int u, int v) {
        if (u == v) return u;
        u = dfn[u];
        v = dfn[v];
        
        if (u > v) {
            const int k = std::__lg(u - v++);
            return comp(node[pos(k, v)], node[pos(k, u - (1 << k) + 1)]);
        } else {
            const int k = std::__lg(v - u++);
            return comp(node[pos(k, u)], node[pos(k, v - (1 << k) + 1)]);
        }
    }
};