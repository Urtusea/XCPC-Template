#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n, a, b, A, B;
    std::cin >> n >> a >> b >> A >> B;

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 2; i <= n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> dep(n + 1), dis1(n + 1), dis2(n + 1);
    const auto dfs = [&](auto &&self, int u, int p) -> void {
        dep[u] = dep[p] + 1;
        for (auto v : e[u]) {
            if (v == p) continue;
            self(self, v, u);
            if (dis1[v] >= dis1[u]) {
                dis2[u] = dis1[u];
                dis1[u] = dis1[v] + 1;
            } else if (dis1[v] >= dis2[u]) {
                dis2[u] = dis1[v] + 1;
            }
        }
    };
    dfs(dfs, a, 0);

    int len = 0;
    for (int i = 1; i <= n; i++)
        len = std::max(len, dis1[i] + dis2[i]);

    if (A >= dep[b] - dep[a]) {
        std::cout << "Alice\n";
        return;
    }

    if (2 * A >= len) {
        std::cout << "Alice\n";
        return;
    }

    if (2 * A >= B) {
        std::cout << "Alice\n";
        return;
    }

    std::cout << "Bob\n";
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