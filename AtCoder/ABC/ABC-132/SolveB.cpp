#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e1 + 5);

int n;
int p[MAX_N];

int ans;

bool check(int a, int b, int c) {
  vector<int> tmp = {a, b, c};

  sort(tmp.begin(), tmp.end());

  return tmp[1] == b;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(p[i]));
  }

  ans = 0;

  for (int i = 1; i < n - 1; ++i) {
    if (check(p[i - 1], p[i], p[i + 1])) ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
