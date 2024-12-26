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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], a[i] %= m;

    std::vector<std::vector<char>> f(2, std::vector<char>(m));
    for (int i = 1; i <= n && !f[0][0] && !f[1][0]; i++) {
        auto &pre = f[i & 1 ^ 1];
        auto &now = f[i & 1];
        for (int j = m - 1; j >= 0; j--) {
            now[j] |= pre[j];
            now[(j + a[i]) % m] |= pre[j];
        }
        now[a[i]] = 1;
    }

    if (f[0][0] || f[1][0])
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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