#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline int get_root(int n, const auto &G) {
    std::vector<int> siz(n + 1);
    std::vector<int> msn(n + 1);
    int root = 0;

    const auto dfs = [&](auto &&self, int u, int p) -> void {
        siz[u] = 1;
        msn[u] = 0;
        for (auto to : G[u]) {
            if (to.v == p) continue;
            self(self, to.v, u);
            siz[u] += siz[to.v];
            msn[u] = std::max(msn[u], siz[to.v]);
        }
        msn[u] = std::max(msn[u], n - siz[u]);
        if (!root || msn[u] < msn[root])
            root = u;
    };

    return root;
}