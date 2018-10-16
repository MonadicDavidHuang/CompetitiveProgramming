#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int R_POS = (int)(-100);
const int G_POS = (int)(0);
const int B_POS = (int)(100);

int r, g, b;

ll ans;

ll side_spread(int num, int minlen) {
  ll ret = 0;

  int half = (num - 1) / 2;

  ret += (half + 1) * half / 2 * 2;

  if ((num - 1) % 2 == 1) {
    ret += half + 1;
  }

  return ret;
}

ll calc(int i, int j) {
  ll ret = 0;

  if (G_POS <= i) {
    ret += (i - G_POS + 1) * g;
    ret += (g - 1) * g / 2;
  } else if (j <= G_POS) {
    ret += (G_POS - j + 1) * g;
    ret += (g - 1) * g / 2;
  } else if (i < G_POS && G_POS < j) {
    int minlen = min(G_POS - i - 1, j - G_POS - 1);

    if (minlen * 2 + 1 >= g) {
      ret += side_spread(g, minlen);
    } else {
      ret += (minlen + 1) * minlen / 2 * 2;

      int remain = g - minlen * 2 - 1;
      if (remain > 0) {
        ret += remain * (minlen + 1);
        ret += (remain - 1) * remain / 2;
      }
    }
  }

  if (B_POS <= j) {
    ret += (j - B_POS) * b;
    ret += (b - 1) * b / 2;
  } else {
    int minlen = B_POS - j;

    if (minlen * 2 + 1 >= b) {
      ret += side_spread(b, minlen);
    } else {
      ret += (minlen + 1) * minlen / 2 * 2;

      int remain = b - minlen * 2 - 1;
      if (remain > 0) {
        ret += remain * (minlen + 1);
        ret += (remain - 1) * remain / 2;
      }
    }
  }

  if (i <= R_POS) {
    ret += (R_POS - i) * r;
    ret += (r - 1) * r / 2;
  } else {
    int minlen = i - R_POS;

    if (minlen * 2 + 1 >= r) {
      ret += side_spread(r, minlen);
    } else {
      ret += (minlen + 1) * minlen / 2 * 2;

      int remain = r - minlen * 2 - 1;
      if (remain > 0) {
        ret += remain * (minlen + 1);
        ret += (remain - 1) * remain / 2;
      }
    }
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d %d", &r, &g, &b);

  ans = INF;

  for (int i = -1000; i <= 1000; ++i) {
    for (int j = i + 1; j <= 1000; ++j) {
      int middle = j - i - 1;
      if (middle < g) continue;

      ans = min(ans, calc(i, j));
    }
  }

  printf("%lld\n", ans);

  return 0;
}
