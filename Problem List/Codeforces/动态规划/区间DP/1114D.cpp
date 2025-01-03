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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int m = 1;
    for (int i = 2; i <= n; i++)
        if (a[m] != a[i]) a[++m] = a[i];
    a.resize(m + 1);

    std::vector f(m + 1, std::vector<int>(m + 1));
    for (int i = 2; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            if (a[j - i + 1] == a[j])
                f[j - i + 1][j] = f[j - i + 2][j - 1] + 1;
            else
                f[j - i + 1][j] = std::min(f[j - i + 2][j], f[j - i + 1][j - 1]) + 1;
        }
    }

    std::cout << f[1][m] << '\n';
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