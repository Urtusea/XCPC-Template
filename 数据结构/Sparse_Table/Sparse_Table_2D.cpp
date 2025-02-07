#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp>
struct Sparse_Table_2D {
    Comp comp;
    int n;
    int m;
    std::vector<std::vector<std::vector<Info>>> node;

    Sparse_Table_2D(int _n = 0, int _m = 0)
    : comp(Comp()), n(_n), m(_m), node(std::vector(std::__lg(_n) + 1, std::vector(std::__lg(_m) + 1, std::vector<Info>(_n * _m + 1)))) {}

    int pos(int i, int j) {
        return (i - 1) * m + j;
    }

    void build() {
        for (int x = 0; x <= std::__lg(n); x++) {
            for (int y = 0; y <= std::__lg(m); y++) {
                if (x == 0 && y == 0) continue;
                for (int i = 1; i + (1 << x) <= n + 1; i++) {
                    for (int j = 1; j + (1 << y) <= m + 1; j++) {
                        if (y == 0)
                            node[x][y][pos(i, j)] = comp(node[x - 1][y][pos(i, j)], node[x - 1][y][pos(i + (1 << (x - 1)), j)]);
                        else
                            node[x][y][pos(i, j)] = comp(node[x][y - 1][pos(i, j)], node[x][y - 1][pos(i, j + (1 << (y - 1)))]);
                    }
                }
            }
        }
    }

    Info query(std::array<int, 2> l, std::array<int, 2> r) {
        int x = std::__lg(r[0] - l[0] + 1);
        int y = std::__lg(r[1] - l[1] + 1);
        r[0] -= (1 << x) - 1;
        r[1] -= (1 << y) - 1;
        return comp(comp(node[x][y][pos(l[0], l[1])], node[x][y][pos(r[0], r[1])]), comp(node[x][y][pos(l[0], r[1])], node[x][y][pos(r[0], l[1])]));
    }
};