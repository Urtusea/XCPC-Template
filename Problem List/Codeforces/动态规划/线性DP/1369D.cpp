#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <int Cheat_GCC>
struct Mod_Int {
    struct Barrett {
        uInt mod, inv_mod;
        constexpr Barrett(uInt _mod = 1) : mod(_mod), inv_mod((~0ULL) / _mod + 1) {}

        constexpr uInt opt(uInt a) const {
            const uInt b = (__uint128_t(a) * inv_mod) >> 64;
            if (a < b * mod)
                return a - b * mod + mod;
            else
                return a - b * mod;
        }

        constexpr uInt mul(uInt a, uInt b) const {
            const uInt x = a * b;
            const uInt y = (__uint128_t(x) * inv_mod) >> 64;
            if (x < y * mod)
                return x - y * mod + mod;
            else
                return x - y * mod;
        }
    };
    static Barrett B;
    uInt val;

    constexpr Mod_Int() : val(0) {}
    template <std::unsigned_integral T>
    constexpr Mod_Int(T _val) : val(maintain(_val)) {}
    template <std::signed_integral T>
    constexpr Mod_Int(T _val) : val(maintain(_val)) {}

    constexpr static void replace_mod(uInt mod) {
        B = mod;
    }

    template <std::unsigned_integral T>
    constexpr T maintain(T x) const {
        return x >= B.mod ? B.opt(x) : x;
    } 

    template <std::signed_integral T>
    constexpr T maintain(T x) const {
        return x < 0 ? -(Int)B.opt(-x) + B.mod : maintain<uInt>(x);
    }

    constexpr Mod_Int pow(uInt b) const {
        Mod_Int a = *this, res = 1;
        for (; b; a *= a, b >>= 1)
            if (b & 1) res *= a;
        return res;
    }

    constexpr Mod_Int operator - () const {
        return val == 0 ? Mod_Int() : Mod_Int(B.mod - val);
    }

    constexpr Mod_Int operator ~ () const {
        assert(val != 0);

        Int a = B.mod, b = val;
        Int x = 0, y = 1;

        while (b) {
            const Int tmp = a / b;
            a -= tmp * b;
            x -= tmp * y;
            std::swap(a, b);
            std::swap(x, y);
        }
        if (x < 0) x += B.mod / a;

        assert(a == 1);
        return Mod_Int(x);
    }

    constexpr Mod_Int &operator += (Mod_Int other) & {
        (val += other.val) >= B.mod && (val -= B.mod);
        return *this;
    }

    constexpr Mod_Int &operator -= (Mod_Int other) & {
        (val -= other.val) >= B.mod && (val += B.mod);
        return *this;
    }

    constexpr Mod_Int &operator *= (Mod_Int other) & {
        val = B.mul(val, other.val);
        return *this;
    }

    constexpr Mod_Int &operator /= (Mod_Int other) & {
        val = B.mul(val, (~other).val);
        return *this;
    }

    friend constexpr Mod_Int operator + (Mod_Int l, Mod_Int r) {
        return l += r;
    }

    friend constexpr Mod_Int operator - (Mod_Int l, Mod_Int r) {
        return l -= r;
    }

    friend constexpr Mod_Int operator * (Mod_Int l, Mod_Int r) {
        return l *= r;
    }

    friend constexpr Mod_Int operator / (Mod_Int l, Mod_Int r) {
        return l /= r;
    }

    friend constexpr bool operator == (Mod_Int l, Mod_Int r) {
        return l.val == r.val;
    }

    friend constexpr std::strong_ordering operator <=> (Mod_Int l, Mod_Int r) {
        return l.val <=> r.val;
    }

    friend constexpr std::istream &operator >> (std::istream &is, Mod_Int &x) {
        return is >> x.val;
    }

    friend constexpr std::ostream &operator << (std::ostream &os, const Mod_Int &x) {
        return os << x.val;
    }
};

using mInt = Mod_Int<1>;
template <>
mInt::Barrett mInt::B = 1e9 + 7;

constexpr int N = 2e6;
mInt f[N + 1];

void init() {
    
}

void code() {
    int n;
    std::cin >> n;
    std::cout << f[n] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    f[3] = 4;
    for (int i = 4; i <= N; i++) {
        f[i] = f[i - 1] + 2 * f[i - 2];
        if (i % 3 == 0) f[i] += 4;
    }

    for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    {
        init();
        code();
    }

    return 0;
}