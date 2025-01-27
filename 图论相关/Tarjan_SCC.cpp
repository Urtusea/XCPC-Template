#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr std::vector<int> Tarjan_SCC(int n, const auto &G) {
    std::vector<int> dfn(n + 1);
    std::vector<int> low(n + 1);
    std::vector<int> scc(n + 1);

    int timer = 0, scc_cnt = 0;
    const auto tarjan = [&](auto &&self, int u) -> void {
        static std::vector<int> stk;
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        
        for (auto to : G[u]) {
            if (!dfn[to.v]) {
                self(self, to.v);
                low[u] = std::min(low[u], low[to.v]);
            } else if (!scc[to.v]) {
                low[u] = std::min(low[u], dfn[to.v]);
            }
        }

        if (dfn[u] == low[u] && ++scc_cnt) {
            while (!stk.empty()) {
                auto v = stk.back();
                stk.pop_back();
                scc[v] = scc_cnt;
                if (v == u) break;
            }
        }
    };

    for (int u = 1; u <= n; u++)
        if (!dfn[u]) tarjan(tarjan, u);

    return scc;
}