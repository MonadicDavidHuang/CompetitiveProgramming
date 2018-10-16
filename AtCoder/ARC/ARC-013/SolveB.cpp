#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_C = (int)(1e2 + 5);

int c;

int n[MAX_C];
int m[MAX_C];
int l[MAX_C];

bool check(int sn, int sm, int sl) {
  vector<int> base{sn, sm, sl};

  sort(base.begin(), base.end(), greater<int>());

  for (int i = 0; i < c; ++i) {
    vector<int> tmp{n[i], m[i], l[i]};
    sort(tmp.begin(), tmp.end(), greater<int>());

    for (int j = 0; j < 3; ++j) {
      if (base[j] - tmp[j] < 0) return false;
    }
  }

  return true;
}

int main(void) {
  // Here your code !
  scanf("%d", &c);

  for (int i = 0; i < c; ++i) {
    scanf("%d %d %d", &(n[i]), &(m[i]), &(l[i]));
  }

  int ans = INT_MAX;

  for (int i = 1; i <= 100; ++i) {
    for (int j = 1; j <= 100; ++j) {
      int ok = 100;
      int ng = 0;

      while (abs(ok - ng) > 1) {
        int next = (ok + ng) / 2;
        if (check(i, j, next))
          ok = next;
        else
          ng = next;
      }

      if (check(i, j, ok)) ans = min(ans, i * j * ok);
    }
  }

  printf("%d\n", ans);

  return 0;
}
