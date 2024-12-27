#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr std::vector<int> get_digit(Int x) {
    std::vector<int> res;
    for (; x; x /= 10)
        res.push_back(x % 10);
    return res;
}

void init() {
    
}

void code() {
    Int l, r;
    std::cin >> l >> r;

    const auto cal = [](Int x) -> Int {
        auto digit = get_digit(x);
        const int n = digit.size();

        std::vector<std::array<Int, 4>> mem(n, {-1, -1, -1, -1});
        const auto dfs = [&](auto &&self, int pos, int cnt, bool flag) -> Int {
            if (pos == -1) return 1;
            if (!flag && mem[pos][cnt] != -1) return mem[pos][cnt];

            Int now = 0;
            for (int i = 0; i <= (flag ? digit[pos] : 9); i++) {
                if (i == 0)
                    now += self(self, pos - 1, cnt, flag && i == digit[pos]);
                else if (cnt != 3)
                    now += self(self, pos - 1, cnt + 1, flag && i == digit[pos]);
            }

            if (!flag) mem[pos][cnt] = now;
            return now;
        };

        return dfs(dfs, n - 1, 0, true);
    };

    std::cout << cal(r) - cal(l - 1) << '\n';
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