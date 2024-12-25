#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr auto Tarjan_EBCC(int n, const auto &G) {
    int *dfn = new int[n + 1]();
    int *low = new int[n + 1]();
    int *ebcc = new int[n + 1]();

    int tiemr = 0, ebcc_cnt = 0;
    const auto tarjan = [&](auto &&self, int u, int pre_id) -> void {
        static std::vector<int> stk;
        dfn[u] = low[u] = ++tiemr;
        stk.push_back(u);

        for (auto to : G[u]) {
            if (to.id == (pre_id ^ 1)) continue;

            if (!dfn[to.v]) {
                self(self, to.v, to.id);
                low[u] = std::min(low[u], low[to.v]);
            } else if (!ebcc[to.v]) {
                low[u] = std::min(low[u], dfn[to.v]);
            }
        }

        if (dfn[u] == low[u] && ++ebcc_cnt) {
            while (!stk.empty()) {
                auto v = stk.back();
                stk.pop_back();
                ebcc[v] = ebcc_cnt;
                if (v == u) break;
            }
        }
    };

    for (int u = 1; u <= n; u++)
        if (!dfn[u]) tarjan(tarjan, u, 0);
    
    return ebcc;
}