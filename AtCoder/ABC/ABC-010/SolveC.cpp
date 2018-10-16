#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);
const double EPS = (double)(1e-7);

/////////////////////////////////////////////////////////////
ll mypow_core(ll x, int n, ll result) {
  if (n == 0) {
    return result;
  }

  if (n % 2 == 0) {
    return mypow_core(x * x, n / 2, result);
  } else {
    return mypow_core(x, n - 1, x * result);
  }
}

ll mypow(ll x, int n) { return mypow_core(x, n, 1); }
/////////////////////////////////////////////////////////////

int sx, sy, tx, ty;
int t, v;

int n;

int main(void) {
  // Here your code !
  scanf("%d %d %d %d %d %d", &sx, &sy, &tx, &ty, &t, &v);

  double target = t * v;

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);

    double fst = sqrt(mypow(abs(sx - x), 2) + mypow(abs(sy - y), 2));
    double snd = sqrt(mypow(abs(tx - x), 2) + mypow(abs(ty - y), 2));

    if (target + EPS >= fst + snd) {
      printf("YES\n");
      return 0;
    }
  }

  printf("NO\n");
  return 0;
}
