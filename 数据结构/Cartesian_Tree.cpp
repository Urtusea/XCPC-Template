#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int N> struct Cartesian_Tree {
    int l[N + 1];
    int r[N + 1];

    template <typename Info, Info (*Comp)(Info l, Info r)>
    void build(int n, std::vector<Info> &init) {
        std::vector<int> stk = {0};
        for (int i = 1; i <= n; i++) {
            while (Comp(init[i], init[stk.back()])) {
                l[i] = stk.back();
                stk.pop_back();
            }
            r[stk.back()] = i;
            stk.push_back(i);
        }
    }
};