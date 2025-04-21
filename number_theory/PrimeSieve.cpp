#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline std::vector<int> PrimeSieve(int n) {
  std::vector<int> prime;
  std::vector<bool> is_prime(n + 1);
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) continue;
    for (int j = i << 1; j <= n; j += i)
      is_prime[j] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!is_prime[i]) prime.push_back(i);
  }
  return prime;
}