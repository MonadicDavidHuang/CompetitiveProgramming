#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e6 + 5);

/////////////////////////////////////////////////////////////
ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
/////////////////////////////////////////////////////////////

int n;
ll a[MAX_N];

int res[MAX_N];

bool check_is_all_gcd_equals_1() {
  ll accum = gcd(a[0], a[1]);

  for (int i = 2; i < n; ++i) {
    accum = gcd(accum, a[i]);
  }

  return (accum == 1LL);
}

void prime_factorization(ll n) {
  unordered_set<int> visited;

  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      int key = (int)(i);

      if (visited.find(key) == visited.end()) {
        res[key] += 1;
        visited.insert(key);
      }
      n /= i;
    }
  }
  int key_n = (int)(n);
  if (n != 1) {
    if (visited.find(key_n) == visited.end()) {
      res[key_n] += 1;
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  // if all gcd is not equals 1, then non of gcd(ai, aj) equals 1, as gcd is monoid
  if (!check_is_all_gcd_equals_1()) {
    printf("not coprime\n");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    prime_factorization(a[i]);
  }

  for (int i = 1; i <= 1e6; ++i) {
    if (res[i] >= 2) {
      printf("setwise coprime\n");
      return 0;
    }
  }

  printf("pairwise coprime\n");

  return 0;
}
