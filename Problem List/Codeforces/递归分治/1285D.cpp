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
    std::sort(a.begin(), a.end());

    const auto dfs = [&](auto &&self, int l, int r, int bit) -> Int {
        if (l == r || bit == -1) return 0;

        int posl = l;
        for (int i = l; i <= r; i++) {
            if (a[i] >> bit & 1) {
                posl = i;
                break;
            }
        }

        if (posl == l)
            return self(self, l, r, bit - 1);
        else
            return std::min(self(self, l, posl - 1, bit - 1), self(self, posl, r, bit - 1)) | 1LL << bit;
    };

    std::cout << dfs(dfs, 1, n, 30) << '\n';
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