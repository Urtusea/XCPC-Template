#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> E(m + 1);
    for (int i = 1; i <= m; i++) {
        auto &[u, v, w] = E[i];
        std::cin >> u >> v >> w;
    }
    std::sort(E.begin(), E.end(), [](auto l, auto r) {
        return l[2] < r[2];
    });

    std::vector<std::vector<std::array<int, 2>>> f(n + 1);
    for (int i = 1; i <= n; i++)
        f[i].push_back({0, 0});
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = E[i];
        int pos = w == f[u].back()[0] ? f[u].size() - 2 : f[u].size() - 1;
        if (f[v].back()[0] < w)
            f[v].push_back({w, f[u][pos][1] + 1});
        else
            f[v].back()[1] = std::max(f[v].back()[1], f[u][pos][1] + 1);
        f[v].back()[1] = std::max(f[v].back()[1], f[v][f[v].size() - 2][1]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, f[i].back()[1]);

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