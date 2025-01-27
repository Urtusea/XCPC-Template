#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename Info, typename Comp>
struct Cartesian_Tree {
    Comp comp;
    int n;
    std::vector<int> l;
    std::vector<int> r;

    Cartesian_Tree(int _n = 0)
    : comp(Comp()), n(_n), l(_n + 1), r(_n + 1) {}

    void build(const std::vector<Info> &info) {
        std::vector<int> stk = {0};
        for (int i = 1; i <= n; i++) {
            while (comp(info[i], info[stk.back()])) {
                l[i] = stk.back();
                stk.pop_back();
            }
            r[stk.back()] = i;
            stk.push_back(i);
        }
    }
};