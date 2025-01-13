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

    std::vector<Int> f(n + 1);
    std::vector<int> siz(n + 1);

    const auto dfs1 = [&](auto &&self, int u, int p) -> void {
        siz[u] = 1;
        for (auto v: e[u]) {
            if (v == p) continue;
            self(self, v, u);
            f[u] += f[v];
            siz[u] += siz[v];
            if (a[u] != a[v]) {
                f[u] += (a[u] ^ a[v]) * siz[v];
            }
        }
    };
    dfs1(dfs1, 1, 0);

    std::vector<Int> ans(n + 1);

    const auto dfs2 = [&](auto &&self, int u, int p, Int pre) -> void {
        ans[u] = pre + f[u];
        for (auto v : e[u]) {
            if (v == p) continue;
            Int nxt = pre + f[u] - f[v];
            if (a[v] != a[u]) {
                nxt += (a[u] ^ a[v]) * (siz[1] - siz[v]);
                nxt -= (a[u] ^ a[v]) * siz[v];
            }
            self(self, v, u, nxt);
        }
    };
    dfs2(dfs2, 1, 0, 0);

    for (int i = 1; i <= n; i++)
        std::cout << ans[i] << " \n"[i == n];
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