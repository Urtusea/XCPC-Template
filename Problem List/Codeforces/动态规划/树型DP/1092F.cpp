#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    std::vector<Int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 2; i <= n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    Int ans = 0;
    std::vector<Int> f(n + 1);
    std::vector<Int> g(n + 1);

    const auto dfs1 = [&](auto &&self, int u, int p) -> void {
        f[u] += a[u];
        for (auto v : e[u]) {
            if (v == p) continue;
            self(self, v, u);
            f[u] += f[v];
            g[u] += g[v] + f[v];
        }
    };
    const auto dfs2 = [&](auto &&self, int u, int p, Int pre) -> void {
        ans = std::max(ans, pre + g[u]);
        for (auto v : e[u]) {
            if (v == p) continue;
            self(self, v, u, pre + g[u] - g[v] - f[v] + f[1] - f[v]);
        }
    };
    dfs1(dfs1, 1, 0);
    dfs2(dfs2, 1, 0, 0);

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}