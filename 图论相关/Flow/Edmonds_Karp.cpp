#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T> struct Flow_Edge {
    int u, v;
    T flow, cost;
    Flow_Edge(int _u = 0, int _v = 0, T _flow = T(), T _cost = T()) : u(_u), v(_v), flow(_flow), cost(_cost) {}
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

    void add_edge(int u, int v, T flow) {
        m += 2;
        E.emplace_back(u, v, flow, 0);
        E.emplace_back(v, u, 0, 0);
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }

    T work(int s, int t) {
        T res = T();
        while (true) {
            std::memset(a, 0, sizeof(T) * (n + 1));
            std::queue<int> q;
            q.push(s);
            a[s] = INF;
            while (!q.empty()) {
                auto x = q.front(); q.pop();
                for (auto to : G[x]) {
                    auto &[u, v, flow, cost] = E[to];
                    if (!a[v] && flow > cost) {
                        p[v] = to;
                        a[v] = std::min(a[x], flow - cost);
                        if (v == t) break;
                        q.push(v);
                    }
                }
            }
            if (!a[t]) break;
            for (int u = t; u != s; u = E[p[u]].u) {
                E[p[u]].cost += a[t];
                E[p[u] ^ 1].cost -= a[t];
            }
            res += a[t];
        }
        return res;
    }
};