#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n, x;
    std::cin >> n >> x;

    std::vector<Int> a(n + 1);
    std::vector<Int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        b[i] = a[i] * x;
    }

    Int ans = 0;
    std::vector<std::array<Int, 3>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i][0] = std::max({f[i - 1][0] + a[i], a[i], 0LL});
        f[i][1] = std::max({f[i - 1][1] + b[i], f[i - 1][0] + b[i], b[i]});
        f[i][2] = std::max({f[i - 1][2] + a[i], f[i - 1][1] + a[i], a[i]});
        ans = std::max({ans, f[i][0], f[i][1], f[i][2]});
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