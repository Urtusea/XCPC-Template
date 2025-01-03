#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int N = 2e5;
int f[N + 1], g[N + 1], d[N + 1];
std::vector<int> e[N + 1];

void init() {
    std::memset(f, 0, sizeof(f));
    std::memset(g, 0, sizeof(g));
    for (int i = 1; i <= N; i++)
        for (auto j : e[i]) d[j]++;
}

void code() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        f[x]++;
    }

    int ans = 1e9;
    std::queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        g[u] += f[u];
        ans = std::min(ans, n - g[u]);
        for (auto v : e[u]) {
            g[v] = std::max(g[v], g[u]);
            if (!--d[v]) q.push(v);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1; i <= N; i++)
        for (int j = i << 1; j <= N; j += i)
            e[i].push_back(j);

    for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}