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

    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::map<int, int> cnt[2];
    cnt[0][0] = 0;
    cnt[1][0] = 0;

    for (int i = 1; i <= n; i++) {
        std::map<int, int> now[2];

        now[1][a[i]] = b[i];

        for (auto [x, y] : cnt[0]) {
            now[0][x] = y;
            
            int g = std::gcd(a[i], x);
            if (now[1].count(g))
                now[1][g] = std::min(now[1][g], y + b[i]);
            else
                now[1][g] = y + b[i];
        }

        for (auto [x, y] : cnt[1]) {
            if (now[0].count(x))
                now[0][x] = std::min(now[0][x], y);
            else
                now[0][x] = y;

            int g = std::gcd(a[i], x);
            if (now[1].count(g))
                now[1][g] = std::min(now[1][g], y + b[i]);
            else
                now[1][g] = y + b[i];
        }

        cnt[0].swap(now[0]);
        cnt[1].swap(now[1]);
    }

    Int ans = 1e18;
    if (cnt[0].count(1))
        ans = std::min(ans, (Int)cnt[0][1]);
    if (cnt[1].count(1))
        ans = std::min(ans, (Int)cnt[1][1]);

    if (ans == 1e18)
        std::cout << -1 << '\n';
    else
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