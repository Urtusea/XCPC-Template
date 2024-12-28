#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

using Array = std::array<Int, 10>;
Array f[15][15];
Int base[15];

Array cal(Int x) {
    auto s = std::to_string(x);
    auto n = s.size();
    std::reverse(s.begin(), s.end());

    Array res = Array();
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                res[k] += f[i][j][k];
    for (int i = 1; i < s.back() - '0'; i++)
        for (int j = 0; j <= 9; j++)
            res[j] += f[n][i][j];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < s[i - 1] - '0'; j++)
            for (int k = 0; k <= 9; k++)
                res[k] += f[i][j][k];
        for (int j = n; j > i; j--)
            res[s[j - 1] - '0'] += (s[i - 1] - '0') * base[i - 1];
    }

    return res;
}

void init() {
    for (int i = 0; i <= 9; i++)
        f[1][i][i] = 1;

    base[0] = 1;
    for (int i = 1; i <= 12; i++)
        base[i] = base[i - 1] * 10;

    for (int i = 2; i <= 12; i++) {
        for (int j = 0; j <= 9; j++) {
            f[i][j][j] += base[i - 1];
            for (int k = 0; k <= 9; k++) {
                for (int t = 0; t <= 9; t++)
                    f[i][j][t] += f[i - 1][k][t];
            }
        }
    }
}

void code() {
    Int l, r;
    std::cin >> l >> r;

    auto R = cal(r + 1);
    auto L = cal(l);

    for (int i = 0; i <= 9; i++)
        std::cout << R[i] - L[i] << " \n"[i == 9];
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