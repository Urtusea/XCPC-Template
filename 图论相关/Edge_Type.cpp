#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct edge {
    int v;
    constexpr edge(int _v = 0) : v(_v) {}
};

template <std::integral T>
struct edge_w : public edge {
    T w;
    constexpr edge_w(int _v = 0, T _w = 0) : edge(_v), w(_w) {}
};