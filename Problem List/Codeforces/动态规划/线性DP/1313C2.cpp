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

    std::vector<Int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::vector<Int> pref(n + 1);
    std::vector<Int> suff(n + 2);
    
    std::vector<std::array<Int, 2>> P;
    std::vector<std::array<Int, 2>> S;

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        std::array<Int, 2> x = {a[i], 1};
        while (!P.empty() && P.back()[0] > x[0]) {
            x[1] += P.back()[1];
            pref[i] -= P.back()[0] * P.back()[1];
            P.pop_back();
        }
        pref[i] += x[0] * x[1];
        P.push_back(x);
    }

    for (int i = n; i >= 1; i--) {
        suff[i] = suff[i + 1];
        std::array<Int, 2> x = {a[i], 1};
        while (!S.empty() && S.back()[0] > x[0]) {
            x[1] += S.back()[1];
            suff[i] -= S.back()[0] * S.back()[1];
            S.pop_back();
        }
        suff[i] += x[0] * x[1];
        S.push_back(x);
    }

    Int ans = 0, pos = 0;
    for (int i = 1; i <= n; i++) {
        if (pref[i] + suff[i] - a[i] > ans) {
            ans = pref[i] + suff[i] - a[i];
            pos = i;
        }
    }

    std::vector<Int> p(n + 1);
    p[pos] = a[pos];
    for (int i = pos - 1; i >= 1; i--)
        p[i] = std::min(a[i], p[i + 1]);
    for (int i = pos + 1; i <= n; i++)
        p[i] = std::min(a[i], p[i - 1]);
    for (int i = 1; i <= n; i++)
        std::cout << p[i] << " \n"[i == n];
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