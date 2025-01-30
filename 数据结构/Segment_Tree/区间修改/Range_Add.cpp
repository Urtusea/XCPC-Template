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

    info(Int _val = 0)
    : val(_val) {}

    void update(lazy tag, int node_size) {
        val += tag.val * node_size;
    }

    friend info operator + (info l, info r) {
        return info(l.val + r.val);
    }
};