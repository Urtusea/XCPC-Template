#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int N = 500;
bool f[N + 1][N + 1][N + 1];

void init() {
    
}

void code() {
    int n, m;
    std::cin >> n >> m;

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int c;
        std::cin >> c;
        for (int l = 0; l <= m; l++) {
            for (int r = 0; r <= m; r++) {
                if (l + c <= m)
                    f[i][l + c][r] |= f[i - 1][l][r];
                if (r + c <= m)
                    f[i][l][r + c] |= f[i - 1][l][r];
                f[i][l][r] |= f[i - 1][l][r];
            }
        }
    }

    std::vector<int> ans;
    for (int l = 0; l <= m; l++)
        for (int r = 0; r <= m; r++)
            if (l + r == m && f[n][l][r]) ans.push_back(l);
    
    std::cout << ans.size() << '\n';
    for (auto x : ans)
        std::cout << x << " \n"[x == ans.back()];
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