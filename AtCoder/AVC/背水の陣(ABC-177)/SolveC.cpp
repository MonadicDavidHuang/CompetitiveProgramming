#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);
const ll MOD = (ll)(1e9 + 7);

/////////////////////////////////////////////////////////////
template <std::uint_fast64_t Modulus>
class ModInt {
  using u64 = std::uint_fast64_t;

 public:
  u64 a;

  constexpr ModInt(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
/////////////////////////////////////////////////////////////

int n;
ll a[MAX_N];

ModInt<MOD> mi[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    mi[i] = ModInt<MOD>(a[i]);
  }

  for (int i = n - 2; i >= 0; --i) {
    mi[i] += mi[i + 1];
  }

  ModInt<MOD> ans = ModInt<MOD>(0LL);

  for (int i = 0; i < n - 1; ++i) {
    ans += ModInt<MOD>(a[i]) * mi[i + 1];
  }

  printf("%lld\n", ans.a);

  return 0;
}
