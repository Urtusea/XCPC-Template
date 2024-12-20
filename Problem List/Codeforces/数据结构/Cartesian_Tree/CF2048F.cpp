#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp>
struct Cartesian_Tree {
    const int n;
    const Comp comp;
    int *l;
    int *r;

    Cartesian_Tree(int _n = 0, Comp &&_comp = Comp()) : n(_n), comp(std::move(_comp)) {
        l = new int[_n + 1]();
        r = new int[_n + 1]();
    }

    void build(const std::vector<Info> &info) {
        std::vector<int> stk = {0};
        for (int i = 1; i <= n; i++) {
            while (comp(info[i], info[stk.back()])) {
                l[i] = stk.back();
                stk.pop_back();
            }
            r[stk.back()] = i;
            stk.push_back(i);
        }
    }
};

const auto cmp = [](Int l, Int r) -> bool {
    return l < r;
};
using Cartesian = Cartesian_Tree<Int, decltype(cmp)>;

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    std::vector<Int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];

    Cartesian Tree(n);
    Tree.build(b);

    constexpr Int INF = 1e18;
    std::vector f(61, std::vector<Int>(n + 1, INF));
    const auto dfs = [&](auto &&self, int l, int r, int pos) -> void {
        int lson = Tree.l[pos];
        int rson = Tree.r[pos];
        
        if (lson) self(self, l, pos - 1, lson);
        if (rson) self(self, pos + 1, r, rson);

        if (l < pos && pos < r) {
            for (int i = 0; i <= 60; i++) {
                for (int j = 0; j <= i; j++) {
                    int k = i - j;
                    Int now = a[pos];
                    now = std::max({now, f[j][lson], f[k][rson]});
                    f[i][pos] = std::min(f[i][pos], now);
                }
            }
        } else if (pos > l) {
            for (int i = 0; i <= 60; i++) {
                Int now = a[pos];
                now = std::max(now, f[i][lson]);
                f[i][pos] = std::min(f[i][pos], now);
            }
        } else if (pos < r) {
            for (int i = 0; i <= 60; i++) {
                Int now = a[pos];
                now = std::max(now, f[i][rson]);
                f[i][pos] = std::min(f[i][pos], now);
            }
        } else {
            f[0][pos] = a[pos];
        }

        for (int i = 0; i < 60; i++) {
            f[i + 1][pos] = std::min(f[i + 1][pos], (f[i][pos] + b[pos] - 1) / b[pos]);
        }
    };

    int root = Tree.r[0];
    dfs(dfs, 1, n, root);

    for (int i = 0; i <= 60; i++)
        if (f[i][root] == 1) return (void)(std::cout << i << '\n');
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