#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <std::integral T>
inline constexpr std::tuple<T, T, T> Exgcd(T a, T b) {
    T x1 = 1, x2 = 0, x3 = 0, x4 = 1, c;
    while (b) {
        c = a / b;
        std::tie(x1, x2, x3, x4, a, b) = {x3, x4, x1 - x3 * c, x2 - x4 * c, b, a - b * c};
    }
    return {a, x1, x2};
}