#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr Int mod = 998244353;

void init() {
    
}

void code() {
    Int n, m;
    std::cin >> n >> m;

    std::vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        if (p[i]) continue;
        for (int j = i << 1; j <= n; j += i)
            p[j] = 1;
    }

    std::vector<Int> f(n + 1);
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = p[i] ? f[i - 1] : std::min(m + 1, f[i - 1] * i);
    }

    Int ans1 = m % mod;
    Int ans2 = m % mod;
    std::vector<Int> g(n + 1);
    for (int i = 2; i <= n; i++) {
        ans1 = ans1 * (m % mod) % mod;
        ans2 = ans2 * (m / f[i] % mod) % mod;
        g[i] = (ans1 - ans2 + mod) % mod;
    }

    Int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += g[i];
        ans %= mod;
    }

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