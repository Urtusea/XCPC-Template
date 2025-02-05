#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct Barrett {
    uInt mod, inv_mod;
    
    constexpr Barrett(uInt _mod = 1)
    : mod(_mod), inv_mod((~0ULL) / _mod + 1) {}

    constexpr uInt opt(uInt a) const {
        const uInt b = (__uint128_t(a) * inv_mod) >> 64;
        if (a < b * mod)
            return a - b * mod + mod;
        else
            return a - b * mod;
    }
};