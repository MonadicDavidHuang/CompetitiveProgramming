#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);
const int MAX_K = (int)(10 + 5);

const ll MOD = (ll)(998244353);

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

int n, k;
int l[MAX_K], r[MAX_K];

ModInt<MOD> dp[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; ++i) {
    scanf("%d %d", &l[i], &r[i]);
  }

  dp[1] += ModInt<MOD>(1);
  dp[2] += ModInt<MOD>(0) - ModInt<MOD>(1);

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i + l[j] <= n) {
        dp[i + l[j]] += dp[i];
      }
      if (i + r[j] + 1 <= n) {
        dp[i + r[j] + 1] += ModInt<MOD>(0) - dp[i];
      }
    }
    dp[i + 1] += dp[i];
  }

  ll ans = dp[n].value();

  printf("%lld\n", ans);

  return 0;
}
