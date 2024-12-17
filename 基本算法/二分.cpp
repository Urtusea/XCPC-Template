#include <bits/stdc++.h>

template <std::integral T>
inline auto work(T l, T r, const auto &&func) {
    if (func(r)) return r;
    while (l + 1 < r) {
        const T mid = (l + r) >> 1;
        if (func(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}