#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <std::integral T>
inline constexpr std::tuple<T, T, T> ExGCD(T a, T b) {
  T x[4] = {1, 0, 0, 1}, c = 0;
  while (b) {
    c = a / b;
    std::tie(x[0], x[1], x[2], x[3], a, b) = std::make_tuple(
      x[2], x[3], x[0] - x[2] * c, x[1] - x[3] * c, b, a - b * c
    );
  }
  return {a, x[0], x[1]};
}