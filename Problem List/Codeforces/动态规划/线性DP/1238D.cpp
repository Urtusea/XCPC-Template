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

    std::string s;
    std::cin >> s;

    std::vector<std::pair<char, int>> a;
    for (auto c : s) {
        if (a.empty() || a.back().first != c)
            a.push_back({c, 1});
        else
            a.back().second++;
    }

    Int ans = 1LL * n * (n - 1) / 2;
    for (int i = 0; i < a.size(); i++) {
        if (i != 0)
            ans -= a[i].second;
        if (i != a.size() - 1)
            ans -= a[i].second;
    }

    std::cout << ans + a.size() - 1 << '\n';
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