#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <std::integral T>
inline constexpr T Sqrt(T n) {
    constexpr int bit = std::numeric_limits<T>::digits >> 1;
    T x = 0, y = 0;
    for (int i = bit - 1; i >= 0; i--) {
        y = x | 1ULL << i;
        if (y * y <= n) x = y;
    }
    return x;
}