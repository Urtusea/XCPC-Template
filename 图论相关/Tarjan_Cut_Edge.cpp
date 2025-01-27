#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr std::vector<int> Tarjan_Cut_Edge(int n, int m, const auto &G) {
    std::vector<int> dfn(n + 1);
    std::vector<int> low(n + 1);
    std::vector<int> cut(2 * m + 2);

    int timer = 0;
    const auto tarjan = [&](auto &&self, int u, int pre_id) -> void {
        dfn[u] = low[u] = ++timer;
        
        for (auto to : G[u]) {
            if (to.id == (pre_id ^ 1)) continue;
            
            if (!dfn[to.v]) {
                self(self, to.v, to.id);
                low[u] = std::min(low[u], low[to.v]);
                if (low[to.v] > dfn[u])
                    cut[to.id] = cut[to.id ^ 1] = 1;
            } else {
                low[u] = std::min(low[u], dfn[to.v]);
            }
        }
    };
    
    for (int u = 1; u <= n; u++)
        if (!dfn[u]) tarjan(tarjan, u, 0);
    
    return cut;
}