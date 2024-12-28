#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

Int f[15][15];

Int cal(Int x) {
    auto s = std::to_string(x);
    auto n = s.size();
    std::reverse(s.begin(), s.end());

    Int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= 9; j++)
            ans += f[i][j];
    for (int i = 1; i < s.back() - '0'; i++)
        ans += f[n][i];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < s[i - 1] - '0'; j++)
            if (std::abs(j - s[i] + '0') >= 2)
                ans += f[i][j];
        if (std::abs(s[i] - s[i - 1]) < 2) break;
    }

    return ans;
}

void init() {
    
}

void code() {
    Int l, r;
    std::cin >> l >> r;
    std::cout << cal(r + 1) - cal(l) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 10; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (std::abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}