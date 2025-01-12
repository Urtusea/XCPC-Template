#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void init() {
    
}

void code() {
    std::vector<int> a(7);
    for (int i = 1; i <= 6; i++)
        std::cin >> a[i];

    int n;
    std::cin >> n;

    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::vector<std::array<int, 2>> f;
    f.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++)
            f.push_back({b[i] - a[j], i});
    }
    std::sort(f.begin(), f.end(), [&](auto l, auto r) {
        return l[0] < r[0];
    });

    int m = f.size() - 1;

    int ans = 1e9;
    int cnt0 = n;
    std::deque<std::array<int, 2>> dq;
    std::vector<int> cnt(n + 1);
    for (int i = 1; i <= m; i++) {
        while (!dq.empty() && (f[i][1] == dq[0][1] || cnt[dq[0][1]] >= 2)) {
            if (!--cnt[dq[0][1]]) cnt0++;
            dq.pop_front();
        }
        if (!cnt[f[i][1]]++) cnt0--;
        dq.push_back(f[i]);
        if (cnt0 == 0) ans = std::min(ans, f[i][0] - dq[0][0]);
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