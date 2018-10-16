#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(1e5 + 5);

int n, m;

map<int, vector<pair<ll, ll>>> cnt;

map<int, pair<int, int>> ans;

using P = pair<ll, int>;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= m; ++i) {
    ll p;
    ll y;
    scanf("%lld %lld", &p, &y);

    cnt[p].push_back(make_pair(y, i));
  }

  for (auto &e : cnt) {
    auto tmpvec = e.second;
    sort(tmpvec.begin(), tmpvec.end(),
         [&](P a, P b) { return a.first < b.first; });
    for (int i = 0; i < tmpvec.size(); ++i) {
      auto obj = tmpvec[i];
      ans[obj.second] = make_pair(e.first, i + 1);
    }
  }

  for (auto &e : ans) {
    int fst = 6 - to_string(e.second.first).length();
    int snd = 6 - to_string(e.second.second).length();

    for (int i = 0; i < fst; ++i) {
      printf("%d", 0);
    }
    printf("%d", e.second.first);

    for (int i = 0; i < snd; ++i) {
      printf("%d", 0);
    }
    printf("%d", e.second.second);

    printf("\n");
  }

  return 0;
}
