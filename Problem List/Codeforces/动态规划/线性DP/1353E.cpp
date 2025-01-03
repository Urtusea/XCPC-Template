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

    std::string s;
    std::cin >> s;
    s = '#' + s;

    std::vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + s[i] - '0';

    std::vector<int> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = std::min(
            f[std::max(0, i - k)] + pref[i - 1] - pref[std::max(0, i - k)],
            pref[i - 1]
        ) + (s[i] == '0');
        
        g[i] = std::min(
            f[std::max(0, i - k)] + pref[i - 1] - pref[std::max(0, i - k)],
            g[i - 1]
        ) + (s[i] == '1');
    }

    int ans = g[n];
    for (int i = n; i >= n - k + 1; i--)
        ans = std::min(ans, f[i] + pref[n] - pref[i]);

    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}