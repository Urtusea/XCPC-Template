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

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 2; i <= n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::queue<int> q;
    std::vector<int> dis(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 1) {
            q.push(i);
            dis[i] = 0;
        }
    }

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : e[u]) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }

    std::vector<int> f(n + 1);
    std::vector<int> g(n + 1);
    std::vector<int> ant(n + 1);

    const auto dfs1 = [&](auto &&self, int u, int p) -> void {
        for (auto v : e[u]) {
            if (v == p) continue;
            self(self, v, u);
            f[u] += f[v];
        }
        f[u] += dis[u] > 1;
    };
    const auto dfs2 = [&](auto &&self, int u, int p) -> void {
        if (p) g[u] = g[p] + f[p] - f[u];
        for (auto v : e[u]) {
            if (v == p) continue;
            ant[v] = u;
            self(self, v, u);
        }
    };

    dfs1(dfs1, 1, 0);
    dfs2(dfs2, 1, 0);

    Int cnt = std::count(dis.begin(), dis.end(), 0);
    Int ans = 1LL * cnt * (n - cnt);

    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0) continue;
        for (auto j : e[i]) {
            if (dis[j] != 1) continue;
            if (j == ant[i])
                ans += g[i];
            else
                ans += f[j];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}