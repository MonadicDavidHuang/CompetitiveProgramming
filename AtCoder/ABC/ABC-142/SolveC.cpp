#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

vector<pair<int, int>> a_ind;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);

    a_ind.push_back(make_pair(a, i));
  }

  sort(a_ind.begin(), a_ind.end());

  for (auto &e : a_ind) {
    printf("%d ", e.second);
  }

  printf("\n");

  return 0;
}
