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
        std::cin >> a[i], a[i] += a[i - 1];

    Int x = 0;
    for (int i = 1; i <= n; i++)
        x = std::max(x, (a[i] + i - 1) / i);

    int q;
    std::cin >> q;

    for (int i = 1; i <= q; i++) {
        Int t;
        std::cin >> t;

        if (t < x)
            std::cout << -1 << '\n';
        else
            std::cout << (a[n] + t - 1) / t << '\n';
    }
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