#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp>
struct Sparse_Table {
    Comp comp;
    int n;
    std::vector<Info> node;

    Sparse_Table(int _n = 0)
    : comp(Comp()), n(_n), node((std::__lg(_n) + 1) * _n + 1) {}

    int pos(int i, int j) {
        return i * n + j;
    }

    void build(const auto &init) {
        for (int i = 1; i <= n; i++) {
            if constexpr (std::is_same_v<decltype(init), const Info &>)
                node[i] = init;
            else if constexpr (std::is_same_v<decltype(init), const std::vector<Info> &>)
                node[i] = init[i];
            else
                static_assert(false, "[Error] Sparse_Table::build -> 'init' type error");
        }
        for (int k = 1; k <= std::__lg(n); k++)
            for (int i = 1; i + (1 << k) <= n + 1; i++)
                node[pos(k, i)] = comp(node[pos(k - 1, i)], node[pos(k - 1, i + (1 << (k - 1)))]);
    }

    Info query(int l, int r) {
        const int k = std::__lg(r - l + 1);
        return comp(node[pos(k, l)], node[pos(k, r - (1 << k) + 1)]);
    }
};