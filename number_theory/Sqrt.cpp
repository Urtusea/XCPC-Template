#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <std::integral T>
inline constexpr T sqrt(T n) {
  constexpr int B = std::numeric_limits<T>::digits / 2 - 1;
  T x = 0, y = 0;
  for (int i = B; i >= 0; i--) {
    y = x | (1LL << i);
    if (y * y == n) return y;
    if (y * y <  n) x = y;
  }
  return x;
}