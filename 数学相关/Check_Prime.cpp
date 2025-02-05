#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <std::unsigned_integral T>
inline constexpr bool Check_Prime(T n) {
    constexpr int digit = std::numeric_limits<T>::digits;
    using U = std::conditional_t<digit < 63, uInt, __uint128_t>;

    if (n < 64)
        return 0x28208a20a08a28ac >> n & 1;
    if (n % 2  == 0 || n % 3  == 0 || n % 5  == 0 || n % 7  == 0 ||
        n % 11 == 0 || n % 13 == 0 || n % 17 == 0 || n % 19 == 0)
        return false;

    T cnt = std::countr_zero(n - 1);
    T cur = (n - 1) >> cnt;
    T inv = 2 - n;

    for (int i = (digit < 63); i < 5; i++)
        inv *= T(2) - n * inv;

    const auto mul = [n, inv](T x, T y) -> T {
        U res = U(x) * y;
        return n + T(res >> digit) - T((U(T(res) * inv) * n) >> digit);
    };

    T A = -U(n) % n;
    T B = -n % n;
    T C = n - B;

    const auto pow = [&](T a) -> T {
        a = mul(a, A);
        T res = B;
        for (T b = cur; b; b >>= 1, a = mul(a, a)) {
            if (b & 1) res = mul(res, a);
        }
        return res;
    };

    const auto check = [&](const std::initializer_list<T> &L) -> bool {
        return std::all_of(L.begin(), L.end(), [&](T N) -> bool {
            if (N >= n)
                return true;
            
            T res = pow(N);
            res = std::min(res, res - n);

            if (res == B || res == C)
                return true;

            for (T i = 0; i < cnt - 1; i++) {
                res = mul(res, res);
                T chk = std::min(res, res - n);
                if (chk == B)
                    return false;
                if (chk == C)
                    return true;
            }
            
            return false;
        });
    };

    if (n < 4759123141)
        return check({2, 7, 61});
    else if (n < 75792980677)
        return check({2, 379215, 457083754});
    else if (n < 21652684502221)
        return check({2, 1215, 34862, 574237825});
    else
        return check({2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}