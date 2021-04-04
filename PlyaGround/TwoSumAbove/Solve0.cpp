#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n, t;
vector<int> s;

pair<int, int> make_sorted_pair(int a, int b) {
  return make_pair(min(a, b), max(a, b));
}

int solve(vector<int> &s) {
  sort(s.begin(), s.end());

  int l = 0, r = s.size() - 1;

  int ans = 0;

  vector<pair<int, int>> view;

  while (l < r) {
    int sum = s[l] + s[r];

    if (sum >= t) {
      ans += r - l;
      r -= 1;
    } else {
      l += 1;
    }
  }

  return ans;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &t);

  for (int i = 0; i < n; ++i) {
    int e;
    scanf("%d", &e);
    s.push_back(e);
  }

  int ans = solve(s);

  printf("%d\n", ans);

  return 0;
}
