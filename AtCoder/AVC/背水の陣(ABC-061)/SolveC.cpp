#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll k;
vector<pair<int, ll>> listab;

ll accum[MAX_N];

bool check(int next) {
  return accum[next] >= k;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  listab.emplace_back(-1, -1LL);  // dummy

  for (int i = 0; i < n; ++i) {
    int a;
    ll b;
    scanf("%d %lld", &a, &b);
    listab.emplace_back(a, b);
  }

  sort(listab.begin(), listab.end());

  accum[0] = 0LL;

  for (int i = 1; i <= n; ++i) {
    accum[i] = accum[i - 1] + listab[i].second;
  }

  int ok = n;
  int ng = 0;

  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (check(next)) {
      ok = next;
    } else {
      ng = next;
    }
  }

  int ans = listab[ok].first;

  printf("%d\n", ans);

  return 0;
}
