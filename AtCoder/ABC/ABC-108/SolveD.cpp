#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int l;

int n = 20;

vector<tuple<int, int, int>> ans;

int main(void) {
  // Here your code !
  scanf("%d", &l);

  int r;

  for (ll i = 1; i <= n; ++i) {
    if ((1 << i) > l) {
      r = i - 1;
      break;
    }
  }

  for (int i = 0; i < r; ++i) {
    int node = i + 1;
    ans.push_back(make_tuple(node, node + 1, 0));
    ans.push_back(make_tuple(node, node + 1, 1 << i));
  }

  for (int i = r; i >= 1; --i) {
    if (l - (1 << r) >= (1 << (i - 1))) {
      ans.push_back(make_tuple(i, r + 1, l - (1 << (i - 1))));
      l -= 1 << (i - 1);
    }
  }

  printf("%d %d\n", r + 1, ans.size());

  for (auto &e : ans) {
    printf("%d %d %d\n", get<0>(e), get<1>(e), get<2>(e));
  }

  return 0;
}
