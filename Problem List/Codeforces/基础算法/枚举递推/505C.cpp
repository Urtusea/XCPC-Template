#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

constexpr int N = 3e4;
constexpr int M = 1e3;
constexpr int O = 400;
int ans;
int a[N + 1];
int f[M + 1][N + 1];

void init() {
    
}

void code() {
    int n, d;
    std::cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        int t;
        std::cin >> t;
        a[t] += 1;
    }

    std::memset(f, -0x3f, sizeof(f));
    ans = f[O][d] = a[0] + a[d];

    for (int i = d + 1; i <= N; i++) {
        for (int j = -350; j <= 350; j++) {
            int len = d + j;
            if (1 <= len && len <= i)
                f[j + O][i] = std::max(f[j + O][i], std::max({
                    f[j + O][i - len],
                    f[j + O - 1][i - len],
                    f[j + O + 1][i - len]
                }) + a[i]);
            ans = std::max(ans, f[j + O][i]);
        }
    }

    std::cout << ans << '\n';
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