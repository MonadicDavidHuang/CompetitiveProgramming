#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
vector<int> b;

vector<int> ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    b.push_back(tmp);
  }

  while (!b.empty()) {
    bool flg = false;

    for (int j = b.size() - 1; j >= 0; --j) {
      if (b[j] == j + 1) {
        flg = true;
        ans.push_back(b[j]);
        b.erase(b.begin() + j);
        break;
      }
    }

    if (!flg) {
      printf("%d\n", -1);
      return 0;
    }
  }

  reverse(ans.begin(), ans.end());

  for (auto e : ans) {
    printf("%d\n", e);
  }

  return 0;
}
