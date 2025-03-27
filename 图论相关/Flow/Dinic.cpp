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

template <typename T, typename Edge, int N> struct Dinic {
    constexpr static T INF = std::numeric_limits<T>::max() / 2;
    int n;
    int m;
    int d[N + 1];
    int c[N + 1];
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
        std::memset(d, 0, sizeof(int) * (n + 1));
        std::queue<int> q;
        q.push(s);
        d[s] = 1;
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto to : G[u]) {
                auto &[u, v, c, f] = E[to];
                if (!d[v] && c > f) {
                    d[v] = d[u] + 1;
                    if (v == t) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    T dfs(int u, int t, T f) {
        if (u == t || !f) return f;
        
        T F = T();
        for (int &i = c[u]; i < G[u].size() && F < f; i++) {
            int to = G[u][i];
            if (d[E[to].v] == d[u] + 1) {
                T tmp = dfs(E[to].v, t, std::min(f - F, E[to].c - E[to].f));
                F += tmp;
                E[to].f += tmp;
                E[to ^ 1].f -= tmp;
            }
        }
        return F;
    }

    T work(int s, int t) {
        T res = T();
        while (bfs(s, t)) {
            std::memset(c, 0, sizeof(c));
            res += dfs(s, t, INF);
        }
        return res;
    }
};
