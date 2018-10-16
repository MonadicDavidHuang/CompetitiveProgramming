#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, k;

int limit;

vector<pair<int, int>> ans;

void calc() {
  int cnt = 0;

  for (int i = 2; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (cnt == (limit - k)) {
        return;
      }
      ans.push_back(make_pair(i, j));
      cnt += 1;
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  limit = n * (n - 1) / 2 - (n - 1);

  if (k > limit) {
    printf("%d\n", -1);
    return 0;
  }

  for (int i = 2; i <= n; ++i) {
    ans.push_back(make_pair(1, i));
  }

  calc();

  printf("%d\n", ans.size());

  for (auto &e : ans) {
    printf("%d %d\n", e.first, e.second);
  }

  return 0;
}
