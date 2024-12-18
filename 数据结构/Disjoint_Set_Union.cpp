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