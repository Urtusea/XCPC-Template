#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp>
struct Sparse_Table_2D {
    const int n;
    const int m;
    const Comp comp;
    Info *node;

    Sparse_Table_2D(int _n = 0, int _m = 0, Comp &&_comp = Comp()) : n(_n), m(_m), comp(std::move(_comp)) {
        node = new Info[(std::__lg(_n) + 1) * (std::__lg(_m) + 1) * (_n + 1) * (_m + 1) + 1]();
    }

    int pos(int x, int y, int i, int j) {
        const int a = (std::__lg(m) + 1) * n * m;
        const int b = n * m;
        const int c = m;
        return a * x + b * y + c * (i - 1) + j;
    }

    void build(const std::vector<std::vector<Info>> &info) {
        for (int i = 1; i <= n; i++)
            std::move(info[i].begin() + 1, info[i].end(), node + pos(0, 0, i, 1));
        build();
    }

    void build() {
        for (int x = 0; x <= std::__lg(n); x++) {
            for (int y = 0; y <= std::__lg(m); y++) {
                if (x == 0 && y == 0) continue;
                for (int i = 1; i + (1 << x) <= n + 1; i++) {
                    for (int j = 1; j + (1 << y) <= m + 1; j++) {
                        if (y == 0)
                            node[pos(x, y, i, j)] = comp(node[pos(x - 1, y, i, j)], node[pos(x - 1, y, i + (1 << (x - 1)), j)]);
                        else
                            node[pos(x, y, i, j)] = comp(node[pos(x, y - 1, i, j)], node[pos(x, y - 1, i, j + (1 << (y - 1)))]);
                    }
                }
            }
        }
    }

    Info query(std::array<int, 2> l, std::array<int, 2> r) {
        const int x = std::__lg(r[0] - l[0] + 1);
        const int y = std::__lg(r[1] - l[1] + 1);
        r[0] -= (1 << x) - 1;
        r[1] -= (1 << y) - 1;
        return comp(comp(node[pos(x, y, l[0], l[1])], node[pos(x, y, r[0], r[1])]), comp(node[pos(x, y, l[0], r[1])], node[pos(x, y, r[0], l[1])]));
    }
};

const auto cmp = [](int l, int r) -> int {
    return std::max(l, r);
};
using ST = Sparse_Table_2D<int, decltype(cmp)>;

void init() {
    
}

void code() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    ST st(m, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> st.node[st.pos(0, 0, j, i)];
    st.build();
    
    int ans = 0;
    std::vector<int> atk(m + 1);
    std::deque<int> dq;

    const auto check = [&]() {
        int sum = 0;
        for (int i = 1; i <= m; i++)
            sum += st.query({i, dq[0]}, {i, dq.back()});
        return sum <= k;
    };

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
        while (!dq.empty() && !check())
            dq.pop_front();

        if (dq.size() > ans) {
            ans = dq.size();
            for (int j = 1; j <= m; j++)
                atk[j] = st.query({j, dq[0]}, {j, dq.back()});
        }
    }

    for (int i = 1; i <= m; i++)
        std::cout << atk[i] << " \n"[i == m];
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