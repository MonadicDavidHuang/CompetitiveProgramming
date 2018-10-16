#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_D = (int)(1e4 + 5);
const int MAX_K = (int)(1e4 + 5);

ll n;
int d, k;
ll l[MAX_D], r[MAX_D];
ll s[MAX_K], t[MAX_K];

int greedy(ll cs, ll ct) {
  int pos = cs;
  for (int i = 0; i < d; ++i) {
    if (l[i] <= pos && pos <= r[i]) {  // pos in range
      if (l[i] <= ct && ct <= r[i]) {  // goal in range
        return i + 1;
      } else {
        pos = (cs < ct) ? r[i] : l[i];
      }
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%lld %d %d", &n, &d, &k);

  for (int i = 0; i < d; ++i) {
    scanf("%lld %lld", &(l[i]), &(r[i]));
  }

  for (int i = 0; i < k; ++i) {
    scanf("%lld %lld", &(s[i]), &(t[i]));
  }

  for (int i = 0; i < k; ++i) {
    int cur_day = greedy(s[i], t[i]);
    printf("%d\n", cur_day);
  }

  return 0;
}
