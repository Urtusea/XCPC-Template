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

    Int cnt1 = 0, cnt2 = 0, ans = 0;
    std::vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt1 += e[i].size() == 1;
        if (e[i].size() == 1) continue;
        for (auto j : e[i])
            f[i] += e[j].size() > 1;
        cnt2 += e[i].size() == f[i];
    }

    ans = cnt1 * (n - cnt1);
    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 1 || e[i].size() == f[i])
            continue;
        ans += cnt2 * (f[i] - 1);
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