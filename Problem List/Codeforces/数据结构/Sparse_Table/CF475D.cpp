#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp>
struct Sparse_Table {
    const int n;
    const Comp comp;
    Info *node;

    Sparse_Table(int _n = 0, Comp &&_comp = Comp()) : n(_n), comp(std::move(_comp)) {
        node = new Info[(std::__lg(_n) + 1) * _n + 1]();
    }

    int pos(int i, int j) {
        return i * n + j;
    }

    void build(const std::vector<Info> &info) {
        std::move(info.begin() + 1, info.end(), node + 1);
        build();
    }

    void build() {
        for (int k = 1; k <= std::__lg(n); k++)
            for (int i = 1; i + (1 << k) <= n + 1; i++)
                node[pos(k, i)] = comp(node[pos(k - 1, i)], node[pos(k - 1, i + (1 << (k - 1)))]);
    }

    Info query(int l, int r) {
        const int k = std::__lg(r - l + 1);
        return comp(node[pos(k, l)], node[pos(k, r - (1 << k) + 1)]);
    }
};

const auto GCD = [](int l, int r) -> int {
    return std::gcd(l, r);
};
using ST = Sparse_Table<int, decltype(GCD)>;

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    ST st(n);
    st.build(a);

    std::map<int, Int> cnt;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            int L = r, R = n + 1;
            while (L + 1 < R) {
                int mid = (L + R) >> 1;
                if (st.query(l, mid) == st.query(l, r))
                    L = mid;
                else
                    R = mid;
            }
            cnt[st.query(l, r)] += L - r + 1;
            r = L;
        }
    }

    int q;
    std::cin >> q;

    for (int i = 1, x; i <= q; i++) {
        std::cin >> x;
        std::cout << cnt[x] << '\n';
    }
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