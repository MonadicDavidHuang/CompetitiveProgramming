#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

vector<pair<ll, int>> a_sort;

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    a_sort.push_back(make_pair(a[i], i % 2));
  }

  sort(a_sort.begin(), a_sort.end());

  int odd2even = 0;
  int even2odd = 0;

  for (int i = 0; i < n; ++i) {
    int cur_parity = i % 2;

    if (cur_parity == 0 && a_sort[i].second == 1) {
      even2odd += 1;
    } else if (cur_parity == 1 && a_sort[i].second == 0) {
      odd2even += 1;
    }
  }

  ans = odd2even;

  printf("%d\n", ans);

  return 0;
}
