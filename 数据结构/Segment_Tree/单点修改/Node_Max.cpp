#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct info {
    Int val;
    Int max_val;

    info(Int _val = 0, Int _max_val = 0)
    : val(_val), max_val(_max_val) {}

    void update(info tag) {
        val += tag.val;
        max_val += tag.val;
    }

    friend info operator + (info l, info r) {
        return info(l.val + r.val, std::max(l.max_val, r.max_val));
    }
};