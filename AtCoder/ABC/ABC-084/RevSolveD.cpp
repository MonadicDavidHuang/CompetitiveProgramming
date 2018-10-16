#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int q;

bool prime[MAX_N];

int cnt[MAX_N];

void prepare() {
  for (int i = 0; i < MAX_N; ++i) {
    prime[i] = true;
  }

  prime[0] = prime[1] = false;

  for (int i = 2; i < MAX_N; i += 2) {
    prime[i] = false;
  }

  prime[2] = true;

  for (int i = 3; i * i < MAX_N; ++i) {
    if (!prime[i]) continue;

    for (int j = i * i; j < MAX_N; j += i) {
      prime[j] = false;
    }
  }

  for (int i = 2; i < MAX_N; ++i) {
    int other = (i + 1) / 2;
    cnt[i] = cnt[i - 1] + (prime[i] && prime[other] ? 1 : 0);
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &q);

  prepare();

  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);

    printf("%d\n", cnt[r] - cnt[l - 1]);
  }

  return 0;
}
