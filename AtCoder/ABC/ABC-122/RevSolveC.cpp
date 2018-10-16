#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n, q;
string s;

int acc[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &q);

  cin >> s;

  int cnt_ac = 0;

  acc[0] = 0;

  for (int i = 1; i <= n - 1; ++i) {
    if (s[i] == 'C' && s[i - 1] == 'A') cnt_ac += 1;

    acc[i] = cnt_ac;
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);

    int tmp = acc[r - 1] - acc[l - 1];

    printf("%d\n", tmp);
  }

  return 0;
}
