#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct Barrett {
    uInt mod;
    uInt inv;

    constexpr Barrett(uInt _mod = 1) : mod(_mod), inv((~0ULL) / _mod + 1) {}

    constexpr friend uInt operator % (uInt x, const Barrett &P) {
        uInt res = x - ((__uint128_t(x) * P.inv) >> 64) * P.mod;
        return res >= P.mod ? res + P.mod : res;
    }
};