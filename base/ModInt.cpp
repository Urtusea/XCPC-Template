#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

inline constexpr auto inv2(auto x) {
  std::make_unsigned_t<decltype(x)> y = 1;
  while (y * x != 1) {
    y *= 2 - x * y;
  }
  return y;
}

template <typename ModInt, typename T> struct ModIntBase {
  static constexpr int bits = sizeof(T) << 3;
  using Int_   = T;
  using uInt_  = std::make_unsigned_t<T>;
  using Int2_  = std::conditional_t<bits <= 32, Int, __int128_t>;
  using uInt2_ = std::conditional_t<bits <= 32, uInt, __uint128_t>;
  static Int_   mod()  { return ModInt::mod();  }
  static uInt_  imod() { return ModInt::imod(); }
  static uInt2_ pmod() { return ModInt::pmod(); }
  
  static uInt_ reduce(uInt2_ x) {
    if (mod() % 2 == 0) [[unlikely]] {
      return uInt_(x % mod());
    } else {
      uInt2_ y = (uInt_)x * imod();
      return uInt_((x + y * mod()) >> bits);
    }
  }
  static uInt_ transform(uInt_ x) {
    if (mod() % 2 == 0) [[unlikely]] {
      return x;
    } else {
      return reduce(x * pmod());
    }
  }

  constexpr ModIntBase() : r(0) {}
  constexpr ModIntBase(Int2_ _r) : r(uInt_(_r % mod())) {
    r = transform(std::min(r, r + mod()));
  }

  ModInt pow(Int2_ b) const {
    ModInt res = ModInt(1);
    for (ModInt a = to_modint(); b; a *= a, b >>= 1)
      if (b & 1) res *= a;
    return res;
  }
  ModInt inv() const {
    assert(r != 0);
    Int_ a = mod(), b = r;
    Int_ x = 0, y = 1;
    while (b) {
      Int_ tmp = a / b;
      a -= tmp * b;
      x -= tmp * y;
      std::swap(a, b);
      std::swap(x, y);
    }
    assert(a == 1);
    return std::max(x + mod(), x);
  }
  ModInt operator - () const {
    ModInt neg; neg.r = std::min(-r, 2 * mod() - r);
    return neg;
  }
  ModInt& operator += (const ModInt& t) {
    r += t.r; r = std::min(r, r - 2 * mod());
    return to_modint();
  }
  ModInt& operator -= (const ModInt& t) {
    r -= t.r; r = std::min(r, r + 2 * mod());
    return to_modint();
  }
  ModInt& operator *= (const ModInt& t) {
    r = reduce((uInt2_)r * t.r);
    return to_modint();
  }
  ModInt& operator /= (const ModInt& t) {
    return to_modint() *= t;
  }
  ModInt operator + (const ModInt& t) const { return ModInt(to_modint()) += t; }
  ModInt operator - (const ModInt& t) const { return ModInt(to_modint()) -= t; }
  ModInt operator * (const ModInt& t) const { return ModInt(to_modint()) *= t; }
  ModInt operator / (const ModInt& t) const { return ModInt(to_modint()) /= t; }
  auto operator ==  (const ModInt& t) const { return getr() == t.getr(); }
  auto operator <=> (const ModInt& t) const { return getr() <=> t.getr(); }

  void setr(uInt_ _r) { r = transform(_r); }
  uInt_ getr() const {
    uInt_ res = reduce(r);
    return std::min(res, res - mod());
  }
private:
  uInt_ r;
  ModInt& to_modint() { return static_cast<ModInt&>(*this); }
  const ModInt& to_modint() const { return static_cast<const ModInt&>(*this); }
};

template <typename ModInt>
concept modint_type = std::is_base_of_v<ModIntBase<ModInt, typename ModInt::Int_>, ModInt>;
template <modint_type ModInt>
std::istream& operator >> (std::istream& is, ModInt& x) {
  typename ModInt::uInt_ r;
  auto &res = is >> r;
  x.setr(r);
  return res;
}
template <modint_type ModInt>
std::ostream& operator << (std::ostream& os, const ModInt& x) {
  return os << x.getr();
}

template <auto P> struct ModInt : ModIntBase<ModInt<P>, decltype(P)> {
  using Base = ModIntBase<ModInt<P>, decltype(P)>;
  using Base::Base;
  static constexpr typename Base::uInt_  iP = P % 2 ? inv2(-P) : 0;
  static constexpr typename Base::uInt_  r2 = (typename Base::uInt2_)(-1) % P + 1;
  static constexpr typename Base::Int_   mod()  { return P;  }
  static constexpr typename Base::uInt_  imod() { return iP; }
  static constexpr typename Base::uInt2_ pmod() { return r2; }
};

template <typename T = Int> struct DynamicModInt : ModIntBase<DynamicModInt<T>, T> {
  using Base = ModIntBase<DynamicModInt<T>, T>;
  using Base::Base;
  static typename Base::Int_   mod()  { return P;  }
  static typename Base::uInt_  imod() { return iP; }
  static typename Base::uInt2_ pmod() { return r2; }
  static void changeMod(typename Base::Int_ M) {
    P = M;
    iP = M % 2 ? inv2(-M) : 0;
    r2 = Base::uInt2_(-1) % M + 1;
  }
private:
  static thread_local typename Base::Int_  P;
  static thread_local typename Base::uInt_ iP, r2;
};

template <typename T>
typename DynamicModInt<T>::Base::Int_  thread_local DynamicModInt<T>::P = 1;
template <typename T>
typename DynamicModInt<T>::Base::uInt_ thread_local DynamicModInt<T>::iP = -1;
template <typename T>
typename DynamicModInt<T>::Base::uInt_ thread_local DynamicModInt<T>::r2 = 0;