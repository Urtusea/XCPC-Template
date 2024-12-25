#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int B>
struct Xor_Linear_Basis {
    using Info = std::conditional_t<B <= 31, uint, uInt>;
    Info node[B + 1];

    Xor_Linear_Basis() = default;

    void insert(Info x) {
        for (int i = B; i >= 0; i--) {
            if (!(x >> i & 1)) continue;
            if (node[i]) x ^= node[i];
            else {
                
            }
        }
    }
};