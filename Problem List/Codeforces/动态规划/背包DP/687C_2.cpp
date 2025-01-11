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

    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];

    std::vector f(std::vector(k + 1, std::vector<int>(k + 1)));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= c[i]; j--) {
            for (int l = k; l >= 0; l--) {
                if (l >= c[i])
                    f[j][l] |= f[j - c[i]][l - c[i]];
                f[j][l] |= f[j - c[i]][l];
            }
        }
    }

    std::vector<int> ans;
    for (int i = 0; i <= k; i++)
        if (f[k][i]) ans.push_back(i);

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