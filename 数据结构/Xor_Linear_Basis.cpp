#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int B>
struct Xor_Linear_Basis {
    using Info = std::conditional_t<B <= 31, uint, uInt>;
    Info node[B + 1];

    void init() {
        std::memset(node, 0, sizeof(node));
    }

    void insert(Info x) {
        for (int i = B; i >= 0; i--) {
            if (!(x >> i & 1)) continue;
            if (!node[i]) {
                for (int j = i - 1; j >= 0; j--)
                    if (x >> j & 1) x ^= node[j];
                for (int j = i + 1; j <= B; j++)
                    if (node[j] >> i & 1) node[j] ^= x;
                return (void)(node[i] = x);
            }
            x ^= node[i];
        }
    }
};