#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct lazy {
    Int val;

    lazy(Int _val = 0)
    : val(_val) {}

    void update(lazy tag) {
        val += tag.val;
    }

    void clear() {
        val = 0;
    }
};

struct info {
    Int val;
    Int min_val;

    info(Int _val = 0, Int _min_val = (Int)(1e18))
    : val(_val), min_val(_min_val) {}

    void update(lazy tag, int node_size) {
        val += tag.val * node_size;
        min_val += tag.val;
    }

    friend info operator + (info l, info r) {
        return info(l.val + r.val, std::min(l.min_val, r.min_val));
    }
};