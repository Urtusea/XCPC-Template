#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T> struct Edge {
    int u;
    int v;
    T   c;
    T   f;
    Edge(int _u = 0, int _v = 0, T _c = T(), T _f = T()) : u(_u), v(_v), c(_c), f(_f) {}
};

template <typename T, typename Edge, int N> struct Edmonds_Karp {
    constexpr static T INF = std::numeric_limits<T>::max() / 2;
    int n;
    int m;
    int p[N + 1];
    T   a[N + 1];
    std::vector<int>  G[N + 1];
    std::vector<Edge> E;

    void init(int _n) {
        n = _n;
        m = 0;
        for (int i = 0; i <= _n; i++)
            G[i].clear();
        E.clear();
    }

    void add_edge(int u, int v, T f) {
        E.emplace_back(u, v, f, 0);
        E.emplace_back(v, u, 0, 0);
        G[u].push_back(m++);
        G[v].push_back(m++);
    }

    bool bfs(int s, int t) {
        std::memset(a, 0, sizeof(T) * (n + 1));
        std::queue<int> q;
        q.push(s);
        a[s] = INF;
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto to : G[u]) {
                auto &[u, v, c, f] = E[to];
                if (!a[v] && c > f) {
                    p[v] = to;
                    a[v] = std::max(a[u], c - f);
                    if (v == t) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    T work(int s, int t) {
        T res = T();
        while (bfs(s, t)) {
            res += a[t];
            for (int u = t; u != s; u = E[p[u]].u) {
                E[p[u]].f += a[t];
                E[p[u] ^ 1].f -= a[t];
            }
        }
        return res;
    }
};