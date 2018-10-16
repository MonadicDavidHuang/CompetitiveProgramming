#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MAX_A = (int)(6e5 + 5);

int n;

vector<bool> primes(MAX_A);

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (ll i = 0; i < MAX_A; ++i) {
    primes[i] = true;
  }

  for (ll i = 2; i * i < MAX_A; ++i) {
    if (!primes[i]) continue;

    for (ll j = i * i; j < MAX_A; j += i) {
      primes[j] = false;
    }
  }

  int cnt = 0;

  for (ll i = 2; i < MAX_A; ++i) {
    if (cnt == n) break;

    if (primes[i] && i % 5 == 1) {
      printf("%d ", i);
      cnt += 1;
    }
  }

  printf("\n");

  return 0;
}
