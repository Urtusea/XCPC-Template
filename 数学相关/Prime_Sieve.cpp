#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N>
inline constexpr std::vector<int> Prime_Sieve() {
    std::bitset<N + 1> is_prime;
    std::vector<int> prime;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) continue;
        for (int j = i << 1; j <= N; j += i)
            is_prime[j] = 1;
    }
    for (int i = 2; i <= N; i++)
        if (!is_prime[i]) prime.push_back(i);
    return prime;
}