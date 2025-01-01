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

    std::vector<Int> a(n + 1, 1e18);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    const auto dfs = [&](auto &&self, int l, int r) -> Int {
        if (l >= r) return l == r && a[l];
        
        Int it = 0;
        for (int i = l; i <= r; i++)
            if (a[i] < a[it]) it = i;
        Int tmp = a[it];
        for (int i = l; i <= r; i++)
            a[i] -= tmp;

        Int L = self(self, l, it - 1);
        Int R = self(self, it + 1, r);

        return std::min(L + R + tmp, r - l + 1LL);
    };

    std::cout << dfs(dfs, 1, n) << '\n';
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