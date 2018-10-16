#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, k;
string s;

int acc[MAX_N];

int ans;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);
  cin >> s;

  if (s[0] == '0') {
    acc[0] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == '1' && s[i] == '0') {
      acc[i] = 1;
    }
  }

  for (int i = 1; i < n; ++i) {
    acc[i] += acc[i - 1];
  }

  acc[n] = acc[n - 1] + 1;

  if (acc[n - 1] <= k) {
    printf("%d\n", n);
    return 0;
  }

  ans = -1;

  for (int i = 0; i < n; ++i) {
    int buff = (s[i] == '0') ? k - 1 : k;

    int end = upper_bound(acc + i, acc + n + 1, acc[i] + buff) - acc;

    if ((acc[end] - acc[i]) != buff + 1) continue;

    ans = max(ans, end - i);
  }

  printf("%d\n", ans);

  return 0;
}
