#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

Int f[20][20][5];

void init() {
    
}

void code() {
    Int l, r;
    std::cin >> l >> r;

    const auto cal = [](Int x) -> Int {
        auto s = std::to_string(x);
        auto n = s.size();
        std::reverse(s.begin(), s.end());

        Int ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 1; j <= 9; j++)
                for (int k = 1; k <= 3; k++)
                    ans += f[i][j][k];
        for (int i = 1; i < s.back() - '0'; i++)
            for (int j = 1; j <= 3; j++)
                ans += f[n - 1][i][j];
        for (int i = n - 2, cnt = 0; i >= 0; i--) {
            if (s[i] != '0') cnt++;
            for (int j = 0; j < s[i] - '0'; j++)
                for (int k = 0; k <= 3 - cnt; k++)
                    ans += f[i][j][k];
        }

        return ans;
    };

    std::cout << cal(r + 1) - cal(l) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    f[0][0][0] = 1;
    for (int i = 1; i <= 9; i++)
        f[0][i][1] = 1;
    for (int i = 1; i < 19; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int c = 0; c <= 3; c++) {
                for (int k = 0; k <= 9; k++) {
                    if (j == 0) {
                        f[i][j][c] += f[i - 1][k][c];
                    } else if (c) {
                        f[i][j][c] += f[i - 1][k][c - 1];
                    }
                }
            }
        }
    }

    for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}