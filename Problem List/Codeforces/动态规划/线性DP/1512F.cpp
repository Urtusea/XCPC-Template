#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n, cost;
    std::cin >> n >> cost;

    std::vector<Int> a(n + 1);
    std::vector<Int> b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <  n; i++)
        std::cin >> b[i];

    /*
        f[i]: 到我 i 个还会剩下的钱数
        g[i]: 到我 i 个等级需要花费的天数
    */

    Int ans = (cost + a[1] - 1) / a[1];
    std::vector<Int> f(n + 1), g(n + 1);
    for (int i = 2; i <= n; i++) {
        if (f[i - 1] >= b[i - 1]) {
            g[i] = g[i - 1] + 1;
            f[i] = f[i - 1] - b[i - 1];
        } else {
            g[i] = g[i - 1] + 1 + (b[i - 1] - f[i - 1] + a[i - 1] - 1) / a[i - 1];
            f[i] = f[i - 1] - b[i - 1] + (g[i] - g[i - 1] - 1) * a[i - 1];
        }
        ans = std::min(ans, g[i] + (std::max(0LL, cost - f[i]) + a[i] - 1) / a[i]);
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