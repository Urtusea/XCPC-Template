#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct info {
    Int val;

    info(Int _val = 0)
    : val(_val) {}

    void update(info tag) {
        val += tag.val;
    }

    friend info operator + (info l, info r) {
        return info(l.val + r.val);
    }
};