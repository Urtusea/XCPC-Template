#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int B>
struct Xor_Linear_Basis {
    using Info = std::conditional_t<B <= 31, uint, uInt>;
    Info node[B + 1];

    Xor_Linear_Basis() {
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

void init() {
    
}

void code() {
    int n;
    std::cin >> n;

    Xor_Linear_Basis<50> basis;
    for (int i = 1; i <= n; i++) {
        Int x;
        std::cin >> x;
        basis.insert(x);
    }

    const auto query = [&]() -> Int {
        Int res = 0;
        for (int i = 50; i >= 0; i--)
            if ((res ^ basis.node[i]) > res)
                res ^= basis.node[i];
        return res;
    };

    std::cout << query() << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}