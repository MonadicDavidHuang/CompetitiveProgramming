#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_R = (int)(1e3 + 5);

int n, m, p, q, r;
int x[MAX_R], y[MAX_R], z[MAX_R];

ll ans;

int main(void) {
  // Here your code !
  scanf("%d %d %d %d %d", &n, &m, &p, &q, &r);

  for (int i = 0; i < r; ++i) {
    scanf("%d %d %d", &(x[i]), &(y[i]), &(z[i]));
  }

  ll max_happiness = 0;

  for (int i = 0; i < 1 << n; ++i) {
    set<int> girls;

    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) girls.insert(j + 1);
    }

    if (girls.size() != p) continue;

    map<int, int> boy2happiness;

    for (int j = 0; j < r; ++j) {
      if (girls.find(x[j]) == girls.end()) continue;
      boy2happiness[y[j]] += z[j];
    }

    vector<int> happinesses;

    for (auto &e : boy2happiness) {
      happinesses.push_back(e.second);
    }

    sort(happinesses.begin(), happinesses.end(), greater<int>());

    int size = min(q, (int)(happinesses.size()));

    ll cur_happiness = 0;

    for (int j = 0; j < size; ++j) {
      cur_happiness += happinesses[j];
    }

    max_happiness = max(max_happiness, cur_happiness);
  }

  ans = max_happiness;

  printf("%lld\n", ans);

  return 0;
}
