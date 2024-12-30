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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::vector<int> id(n + 1);
    std::iota(id.begin() + 1, id.end(), 1);
    std::sort(id.begin() + 1, id.end(), [&](int l, int r) {
        return a[l] > a[r];
    });

    std::vector<int> vis(n + 1);
    Disjoint_Set_Union dsu(n);
    
    int max_siz = 0, idx = 0;
    for (int i = 1; i <= n; i++) {
        while (max_siz < i) {
            int u = id[++idx];
            vis[u] = 1;
            if (u > 1 && vis[u - 1])
                dsu.merge(u, u - 1);
            if (u < n && vis[u + 1])
                dsu.merge(u, u + 1);
            max_siz = std::max(max_siz, dsu.siz[dsu.find(u)]);
        }
        std::cout << a[id[idx]] << " \n"[i == n];
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