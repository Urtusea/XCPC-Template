#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <std::integral T>
std::tuple<T, T, T> Exgcd(T a, T b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        auto [g, x0, y0] = Exgcd(b, a % b);
        return {g, y0, x0 - (a / b) * y0};
    }
}