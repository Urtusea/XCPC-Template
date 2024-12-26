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

    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, n));
    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int i = 1; i <  n; i++) f[i][i + 1] = 1 + (c[i] != c[i + 1]);
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i + len <= n + 1; i++) {
            int l = i, r = i + len - 1;
            if (c[l] == c[r])
                f[l][r] = f[l + 1][r - 1];
            for (int j = l; j < r; j++)
                f[l][r] = std::min(f[l][r], f[l][j] + f[j + 1][r]);
        }
    }

    std::cout << f[1][n] << '\n';
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