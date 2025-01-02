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

    std::vector<int> id(n + 1, n + 1);
    std::vector<int> next(n + 1, n + 1);
    for (int i = n; i >= 1; i--) {
        next[i] = id[a[i]];
        id[a[i]] = i;
    }

    std::vector<int> A = {0};
    std::vector<int> B = {0};
    for (int i = 1; i <= n; i++) {
        if (a[A.back()] != a[i] && a[B.back()] != a[i]) {
            next[A.back()] <= next[B.back()] ? A.push_back(i) : B.push_back(i);
        } else if (a[A.back()] != a[i]) {
            A.push_back(i);
        } else if (a[B.back()] != a[i]) {
            B.push_back(i);
        } else {
            A.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i < A.size(); i++)
        ans += a[A[i]] != a[A[i - 1]];
    for (int i = 1; i < B.size(); i++)
        ans += a[B[i]] != a[B[i - 1]];

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