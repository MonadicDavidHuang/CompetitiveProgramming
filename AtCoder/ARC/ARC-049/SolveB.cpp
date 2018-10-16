#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

int n;
int x[MAX_N];
int y[MAX_N];
int c[MAX_N];

bool check(double t) {
  double mrl = x[0] - t / (double)(c[0]);
  double mlr = x[0] + t / (double)(c[0]);

  for (int i = 0; i < n; ++i) {
    double tl = x[i] - t / (double)(c[i]);
    double tr = x[i] + t / (double)(c[i]);

    mrl = max(mrl, tl);
    mlr = min(mlr, tr);
  }

  for (int i = 0; i < n; ++i) {
    double tl = x[i] - t / (double)(c[i]);
    double tr = x[i] + t / (double)(c[i]);
    if (mrl > tr) return false;
    if (mlr < tl) return false;
  }

  double mud = y[0] - t / (double)(c[0]);
  double mdu = y[0] + t / (double)(c[0]);

  for (int i = 0; i < n; ++i) {
    double td = y[i] - t / (double)(c[i]);
    double tu = y[i] + t / (double)(c[i]);

    mud = max(mud, td);
    mdu = min(mdu, tu);
  }

  for (int i = 0; i < n; ++i) {
    double td = y[i] - t / (double)(c[i]);
    double tu = y[i] + t / (double)(c[i]);
    if (mud > tu) return false;
    if (mdu < td) return false;
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &(x[i]), &(y[i]), &(c[i]));
  }

  double ok = (double)(1e10 + 3);
  double ng = 0.0;

  for (int i = 0; i < 60; ++i) {
    double next = (ok + ng) / 2.0;
    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  double ans = ok;

  printf("%lf\n", ans);

  return 0;
}
