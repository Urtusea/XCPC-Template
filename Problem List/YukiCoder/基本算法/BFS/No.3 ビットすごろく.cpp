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

    std::vector<int> vis(n + 1, -1);
    std::queue<int> q;

    vis[1] = 1;
    q.emplace(1);

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int v1 = u + std::__popcount(u);
        int v2 = u - std::__popcount(u);
        if (v1 <= n && vis[v1] == -1) {
            q.emplace(v1);
            vis[v1] = vis[u] + 1;
        }
        if (v2 >= 1 && vis[v2] == -1) {
            q.emplace(v2);
            vis[v2] = vis[u] + 1;
        }
    }

    std::cout << vis[n] << '\n';

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