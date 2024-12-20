#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info>
struct Sparse_Table {
    const int n;
    Info *node;

    Sparse_Table(int _n = 0) : n(_n) {
        node = new Info[(std::__lg(_n) + 1) * _n + 1]();
    }

    int pos(int i, int j) {
        return i * n + j;
    }

    void build(const std::vector<Info> &info, const auto &comp) {
        std::move(info.begin() + 1, info.end(), node + 1);
        build(comp);
    }

    void build(const auto &comp) {
        for (int k = 1; k <= std::__lg(n); k++)
            for (int i = 1; i + (1 << k) <= n + 1; i++)
                node[pos(k, i)] = comp(node[pos(k - 1, i)], node[pos(k - 1, i + (1 << (k - 1)))]);
    }

    Info query(int l, int r, const auto &comp) {
        if (l > r) return Info();
        const int k = std::__lg(r - l + 1);
        return comp(node[pos(k, l)], node[pos(k, r - (1 << k) + 1)]);
    }
};

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    std::vector<Int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];

    const auto cmp = [&b](int l, int r) -> int {
        return b[l] < b[r] ? l : r;
    };
    Sparse_Table<int> st(n);
    std::iota(st.node, st.node + n + 1, 0);
    st.build(cmp);

    constexpr Int INF = 1e18;
    std::vector f(61, std::vector<Int>(n + 1, INF));
    const auto dfs = [&](auto &&self, int l, int r, int pos) -> void {
        int lson = st.query(l, pos - 1, cmp);
        int rson = st.query(pos + 1, r, cmp);
        
        if (lson) self(self, l, pos - 1, lson);
        if (rson) self(self, pos + 1, r, rson);

        if (l < pos && pos < r) {
            f[0][pos] = std::min(f[0][pos], std::max({a[pos], f[0][lson], f[0][rson]}));
            int i = 0, j = 0;
            while (i + j + 1 <= 60) {
                f[i][lson] > f[j][rson] ? i++ : j++;
                f[i + j][pos] = std::min(f[i + j][pos], std::max({f[i][lson], f[j][rson], a[pos]}));
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

    int root = st.query(1, n, cmp);
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