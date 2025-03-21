#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

struct Barrett {
    uInt mod;
    uInt inv;

    constexpr Barrett(uInt _mod = 1) : mod(_mod), inv((~0ULL) / _mod + 1) {}

    constexpr friend uInt operator % (const uInt &x, const Barrett &P) {
        uInt res = x - ((__uint128_t(x) * P.inv) >> 64) * P.mod;
        return res >= P.mod ? res + P.mod : res;
    }
};

struct Mod_Int {
    // constexpr static Barrett P = 1e9 + 7;
    // constexpr static Barrett P = 998244353;
    static Barrett P;
    uInt val;

    constexpr Mod_Int(uInt _val = 0) : val(_val) {}

    Mod_Int pow(uInt b) {
        Mod_Int res = 1;
        for (Mod_Int a = *this; b; b >>= 1, a *= a)
            if (b & 1) res *= a;
        return res;
    }

    Mod_Int inv() {
        return ~(*this);
    }

    Mod_Int operator - () {
        return Mod_Int(P.mod - val);
    }
    
    Mod_Int operator ~ () {
        assert(val != 0);
        Int a = P.mod, b = val;
        Int x = 0, y = 1;
        while (b) {
            Int tmp = a / b;
            a -= tmp * b;
            x -= tmp * y;
            std::swap(a, b);
            std::swap(x, y);
        }
        assert(a == 1);
        return x < 0 ? x + P.mod : x;
    }

    Mod_Int &operator += (Mod_Int other) & {
        (val += other.val) >= P.mod && (val -= P.mod);
        return *this;
    }

    Mod_Int &operator -= (Mod_Int other) & {
        (val -= other.val) >= P.mod && (val += P.mod);
        return *this;
    }

    Mod_Int &operator *= (Mod_Int other) & {
        val = val * other.val % P;
        return *this;
    }

    Mod_Int &operator /= (Mod_Int other) & {
        val = val * (~other).val % P;
        return *this;
    }

    friend Mod_Int operator + (Mod_Int l, Mod_Int r) {
        return l += r;
    }

    friend Mod_Int operator - (Mod_Int l, Mod_Int r) {
        return l -= r;
    }

    friend Mod_Int operator * (Mod_Int l, Mod_Int r) {
        return l *= r;
    }

    friend Mod_Int operator / (Mod_Int l, Mod_Int r) {
        return l /= r;
    }

    friend constexpr bool operator == (Mod_Int l, Mod_Int r) {
        return l.val == r.val;
    }

    friend constexpr std::strong_ordering operator <=> (Mod_Int l, Mod_Int r) {
        return l.val <=> r.val;
    }

    friend std::istream &operator >> (std::istream &is, Mod_Int &x) {
        return is >> x.val;
    }

    friend std::ostream &operator << (std::ostream &os, const Mod_Int &x) {
        return os << x.val;
    }
};