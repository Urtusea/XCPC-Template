#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(k + 1));
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(k + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[j][i];
            p[a[j][i]][i] = j;
        }
    }

    std::vector<int> f(n + 1);
    std::vector<int> g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (++g[a[i][j]] == k) {
                f[a[i][j]] = 1;
                for (int x = 1; x <= n; x++) {
                    if (g[x] != k || a[i][j] == x) continue;
                    bool flag = true;
                    for (int y = 1; y <= k; y++) {
                        if (p[x][y] > p[a[i][j]][y]) flag = false;
                    }
                    if (flag) f[a[i][j]] = std::max(f[a[i][j]], f[x] + 1);
                }
            }
        }
    }

    std::cout << *std::max_element(f.begin(), f.end()) << '\n';
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