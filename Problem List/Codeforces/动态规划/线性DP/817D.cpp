#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct Disjoint_Set_Union {
    int *set;
    int *siz;

    Disjoint_Set_Union(int _n = 0)  {
        set = new int[_n + 1]();
        siz = new int[_n + 1]();
        std::iota(set, set + _n + 1, 0);
        std::fill(siz, siz + _n + 1, 1);
    }

    int find(int u) {
        return u == set[u] ? u : set[u] = find(set[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (siz[u] > siz[v]) {
            set[v] = u;
            siz[u] += siz[v];
        } else {
            set[u] = v;
            siz[v] += siz[u];
        }
    }
};

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    std::vector<Int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::vector<int> id(n + 1);
    std::iota(id.begin() + 1, id.end(), 1);
    std::sort(id.begin() + 1, id.end(), [&](int l, int r) {
        return a[l] < a[r];
    });

    Int ans1 = 0, idx1 = 0;
    std::vector<int> vis1(n + 1);
    Disjoint_Set_Union dsu1(n);

    for (int i = 1; i <= n; i++) {
        int u = id[i];
        int l = 1;
        int r = 1;
        vis1[u] = 1;
        if (u > 1 && vis1[u - 1]) {
            l += dsu1.siz[dsu1.find(u - 1)];
            dsu1.merge(u, u - 1);
        }
        if (u < n && vis1[u + 1]) {
            r += dsu1.siz[dsu1.find(u + 1)];
            dsu1.merge(u, u + 1);
        }
        ans1 += a[u] * l * r;
    }

    Int ans2 = 0, idx2 = 0;
    std::vector<int> vis2(n + 1);
    Disjoint_Set_Union dsu2(n);

    for (int i = n; i >= 1; i--) {
        int u = id[i];
        int l = 1;
        int r = 1;
        vis2[u] = 1;
        if (u > 1 && vis2[u - 1]) {
            l += dsu2.siz[dsu2.find(u - 1)];
            dsu2.merge(u, u - 1);
        }
        if (u < n && vis2[u + 1]) {
            r += dsu2.siz[dsu2.find(u + 1)];
            dsu2.merge(u, u + 1);
        }
        ans2 += a[u] * l * r;
    }

    std::cout << ans1 - ans2 << '\n';
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