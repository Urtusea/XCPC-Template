#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct edge_base {
    int v;
    
    edge_base(int _v = 0) : v(_v) {}
};

template <std::integral T>
struct edge_base_w : public edge_base {
    T w;
    
    edge_base_w(int _v = 0, T _w = 0) : edge_base(_v), w(_w) {}
};