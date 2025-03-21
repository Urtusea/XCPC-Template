#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, int N> struct Segment_Tree_Bit {
    constexpr static int offset = 1 << (std::__lg(N + 1) + 1);
    Info f[2 << (std::__lg(N + 1) + 1)];

    void build(int n, Info init) {
        for (int i = 1; i <= n; i++)
            f[i + offset] = init;
        for (int i = offset - 1; i >= 1; i--)
            f[i] = f[i << 1] + f[i << 1 | 1];
    }

    void build(int n, std::vector<Info> &init) {
        for (int i = 1; i <= n; i++)
            f[i + offset] = init[i];
        for (int i = offset - 1; i >= 1; i--)
            f[i] = f[i << 1] + f[i << 1 | 1];
    }

    void update(int u, Info x) {
        for (int i = u + offset; i; i >>= 1)
            f[i].update(x);
    }

    Info query(int l, int r) {
        Info Lres = Info();
        Info Rres = Info();
        for (int i = l + offset - 1, j = r + offset + 1; i ^ j ^ 1; i >>= 1, j >>= 1) {
            if (!(i & 1)) Lres = Lres + f[i ^ 1];
            if ( (j & 1)) Rres = f[j ^ 1] + Rres;
        }
        return Lres + Rres;
    }
};