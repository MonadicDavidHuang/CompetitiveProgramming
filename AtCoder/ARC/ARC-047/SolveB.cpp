#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const ll MAX_POS = (ll)(1e9);

int n;
ll x[MAX_N];
ll y[MAX_N];

ll xp[MAX_N];
ll yp[MAX_N];

bool check(ll cxp, ll cyp) {
  ll cx = (cxp + cyp) / 2LL;
  ll cy = (-cxp + cyp) / 2LL;

  if (cx < -MAX_POS || MAX_POS < cx || cy < -MAX_POS || MAX_POS < cy) return false;

  ll mind = INF;
  ll maxd = -INF;

  for (int i = 0; i < n; ++i) {
    mind = min(abs(cx - x[i]) + abs(cy - y[i]), mind);
    maxd = max(abs(cx - x[i]) + abs(cy - y[i]), maxd);
  }

  return mind == maxd;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &(x[i]), &(y[i]));
  }

  for (int i = 0; i < n; ++i) {
    xp[i] = x[i] - y[i];
    yp[i] = x[i] + y[i];
  }

  ll min_xp = INF;
  ll max_xp = -INF;
  ll min_yp = INF;
  ll max_yp = -INF;

  for (int i = 0; i < n; ++i) {
    min_xp = min(xp[i], min_xp);
    max_xp = max(xp[i], max_xp);

    min_yp = min(yp[i], min_yp);
    max_yp = max(yp[i], max_yp);
  }

  ll d = max(max_xp - min_xp, max_yp - min_yp);

  ll cxp1 = max_xp - d / 2LL;
  ll cxp2 = min_xp + d / 2LL;

  ll cyp1 = max_yp - d / 2LL;
  ll cyp2 = min_yp + d / 2LL;

  ll cxp = INF, cyp = INF;
  if (check(cxp1, cyp1)) {
    cxp = cxp1;
    cyp = cyp1;
  } else if (check(cxp1, cyp2)) {
    cxp = cxp1;
    cyp = cyp2;
  } else if (check(cxp2, cyp1)) {
    cxp = cxp2;
    cyp = cyp1;
  } else if (check(cxp2, cyp2)) {
    cxp = cxp2;
    cyp = cyp2;
  }

  ll cx = (cxp + cyp) / 2LL;
  ll cy = (-cxp + cyp) / 2LL;

  printf("%lld %lld\n", cx, cy);

  return 0;
}
