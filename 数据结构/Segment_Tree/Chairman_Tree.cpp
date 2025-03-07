#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N, int Q> struct Chairman_Tree {
    struct Node {
        Info val;
        int l, r;
        constexpr Node(Info _val = Info(), int _l = 0, int _r = 0) : val(_val), l(_l), r(_r) {}
    };
    int t = 0;
    Node f[(4 << std::__lg(N)) + Q * (std::__lg(N) + 1)];

    void push_up(int p) {
        f[p].val = f[f[p].l].val + f[f[p].r].val;
    }

    void build(int &p, int l, int r, Info init) {
        if (!p) p = ++t;
        if (l == r)
            return (void)(f[p].val = init);
        int m = (l + r) >> 1;
        build(f[p].l, l, m, init);
        build(f[p].r, m + 1, r, init);
        push_up(p);
    }

    void build(int &p, int l, int r, std::vector<Info> &init) {
        if (!p) p = ++t;
        if (l == r)
            return (void)(f[p].val = init);
        int m = (l + r) >> 1;
        build(f[p].l, l, m, init);
        build(f[p].r, m + 1, r, init);
        push_up(p);
    }

    void update(int &p, int l, int r, int u, Info x) {
        if (!p) p = ++t;
        if (l == r)
            return (void)(f[p].val.update(x, r - l + 1));
        int m = (l + r) >> 1;
        if (u <= m)
            update(f[p].l, l, m, u, x);
        else
            update(f[p].r, m + 1, r, u, x);
        push_up(p);
    }

    void update(int &p, int q, int l, int r, int u, Info x) {
        p = ++t;
        f[p] = f[q];
        if (l == r)
            return (void)(f[p].val.update(x, r - l + 1));
        int m = (l + r) >> 1;
        if (u <= m)
            update(f[p].l, f[q].l, l, m, u, x);
        else
            update(f[p].r, f[q].r, m + 1, r, u, x);
        push_up(p);
    }

    Info query(int p, int l, int r, int L, int R) {
        if (R < l || r < L)
            return Info();
        o
    }
};

struct info {
    int val;
    
    info(int _val = 0) : val(_val) {}

    void update(info tag, int node_size) {
        val = tag.val;
    }

    friend info operator + (info l, info r) {
        return info(l.val + r.val);
    }

    friend info operator - (info l, info r) {
        return l;
    }
};

Chairman_Tree<info, (int)1e6, (int)1e6> seg;

void code() {
    int n, m;
    std::cin >> n >> m;

    std::vector<info> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].val;

    std::vector<int> root(m + 1);
    seg.build(seg.nxt(root[0]), 1, n, a);

    for (int i = 1; i <= m; i++) {
        int v, op, x, y;
        std::cin >> v >> op >> x;

        if (op == 1) {
            std::cin >> y;
            seg.update(seg.nxt(root[i]), root[v], 1, n, x, y);
        } else {
            std::cout << seg.query(root[v], 1, n, x, x).val << '\n';
            root[i] = root[v];
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
        code();

    return 0;
}