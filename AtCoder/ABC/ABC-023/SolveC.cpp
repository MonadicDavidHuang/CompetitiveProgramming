#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int r, c, k;
int n;

int ar[MAX_N];
int ac[MAX_N];

unordered_map<int, int> row;  // row to add
unordered_map<int, int> col;

unordered_map<int, int> row_rev;  // add to row-count
unordered_map<int, int> col_rev;

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d %d", &r, &c, &k);
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int tmpr, tmpc;
    scanf("%d %d", &tmpr, &tmpc);

    row[tmpr] += 1;
    col[tmpc] += 1;

    ar[i] = tmpr;
    ac[i] = tmpc;
  }

  for (auto itr = row.begin(); itr != row.end(); ++itr) {
    row_rev[itr->second] += 1;
  }

  for (auto itr = col.begin(); itr != col.end(); ++itr) {
    col_rev[itr->second] += 1;
  }

  row_rev[0] = r - row.size();
  col_rev[0] = c - col.size();

  for (auto itr = row_rev.begin(); itr != row_rev.end(); ++itr) {
    ans += itr->second * col_rev[k - itr->first];
  }

  for (int i = 0; i < n; ++i) {
    int add = row[ar[i]] + col[ac[i]];
    if (add == k) {
      ans -= 1;
    } else if (add == k + 1) {
      ans += 1;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
