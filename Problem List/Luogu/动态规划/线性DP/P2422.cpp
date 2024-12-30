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

    std::vector<Int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }

    std::vector<int> stk;

    std::vector<int> l(n + 1);
    while (!stk.empty()) stk.pop_back();
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.back()] >= a[i])
            stk.pop_back();
        l[i] = stk.empty() ? 1 : stk.back() + 1;
        stk.push_back(i);
    }

    std::vector<int> r(n + 1);
    while (!stk.empty()) stk.pop_back();
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[stk.back()] >= a[i])
            stk.pop_back();
        r[i] = stk.empty() ? n : stk.back() - 1;
        stk.push_back(i);
    }

    Int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, (b[r[i]] - b[l[i] - 1]) * a[i]);

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