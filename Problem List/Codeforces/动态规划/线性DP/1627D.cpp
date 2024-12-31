#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int N = 1e6;

void init() {

}

void code() {
    int n;
    std::cin >> n;

    std::vector<int> f(N + 1);
    std::vector<int> g(N + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        f[x] = 1;
        g[x] = x;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i)
            g[i] = std::gcd(g[i], g[j]);
        if (!f[i] && g[i] == i) ans++;
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