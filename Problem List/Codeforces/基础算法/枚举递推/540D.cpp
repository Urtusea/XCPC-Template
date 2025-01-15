#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    int A, B, C;
    std::cin >> A >> B >> C;

    double ansA = 0, ansB = 0, ansC = 0;
    std::vector f(A + 1, std::vector(B + 1, std::vector<double>(C + 1)));
    f[A][B][C] = 1;
    for (int i = A; i >= 0; i--) {
        for (int j = B; j >= 0; j--) {
            for (int k = C; k >= 0; k--) {
                double tmp = i * j + j * k + i * k;
                if (i && j) f[i][j - 1][k] += f[i][j][k] * i * j / tmp;
                if (j && k) f[i][j][k - 1] += f[i][j][k] * j * k / tmp;
                if (i && k) f[i - 1][j][k] += f[i][j][k] * i * k / tmp;
                if (i && !j && !k) ansA += f[i][j][k];
                if (!i && j && !k) ansB += f[i][j][k];
                if (!i && !j && k) ansC += f[i][j][k];
            }
        }
    }

    std::cout << ansA << ' ' << ansB << ' ' << ansC << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}