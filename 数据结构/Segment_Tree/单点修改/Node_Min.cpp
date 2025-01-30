#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct info {
    Int val;
    Int min_val;

    info(Int _val = 0, Int _min_val = 0)
    : val(_val), min_val(_min_val) {}

    void update(info tag) {
        val += tag.val;
        min_val += tag.val;
    }

    friend info operator + (info l, info r) {
        return info(l.val + r.val, std::max(l.min_val, r.min_val));
    }
};