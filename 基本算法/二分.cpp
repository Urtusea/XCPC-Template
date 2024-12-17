#include <bits/stdc++.h>

template <int Mode, std::integral T>
inline auto work(T l, T r, const auto &&func) {
    if constexpr (Mode) {
        if (func(r)) return r;
    } else {
        if (func(l)) return l;
    }
    
    while (l + 1 < r) {
        const T mid = (l + r) >> 1;
        if (func(mid)) {
            if constexpr (Mode) l = mid;
            else r = mid;
        } else {
            if constexpr (Mode) r = mid;
            else l = mid;
        }
    }

    if constexpr (Mode) return l;
    else return r;
}