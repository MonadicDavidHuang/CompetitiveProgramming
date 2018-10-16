#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e13 + 5);

const int MAX_N = (int)(2e2 + 5);

int n;
ll bag;

ll v[MAX_N];
ll w[MAX_N];

ll ans;

ll small_num() {
  int half = n / 2;
  vector<pair<ll, ll>> first;  // weight, value
  for (int s = 0; s < 1 << half; ++s) {
    ll tmp_weight = 0;
    ll tmp_value = 0;
    for (int j = 0; j < half; ++j) {
      if (s >> j & 1) {
        tmp_weight += w[j + 1];
        tmp_value += v[j + 1];
      }
    }
    first.push_back(make_pair(tmp_weight, tmp_value));
  }

  vector<pair<ll, ll>> snd;  // weight, value

  sort(first.begin(), first.end());

  snd.push_back(first[0]);

  for (auto e : first) {
    if (e.second > snd.back().second) {
      snd.push_back(e);
    }
  }

  ll ret = -1;

  int next_half = (n - half);
  for (int s = 0; s < 1 << next_half; ++s) {
    ll tmp_weight = 0;
    ll tmp_value = 0;
    for (int j = 0; j < next_half; ++j) {
      if (s >> j & 1) {
        tmp_weight += w[j + half + 1];
        tmp_value += v[j + half + 1];
      }
    }

    if (tmp_weight > bag) continue;
    ll tmp_part_value =
        (lower_bound(snd.begin(), snd.end(), make_pair(bag - tmp_weight, INF)) -
         1)
            ->second;
    ret = max(ret, tmp_value + tmp_part_value);
  }

  return ret;
}

ll small_value(ll max_value) {
  int range = n * max_value + 5;

  map<int, vector<ll>> dp;
  vector<ll> fst(range, INF);
  vector<ll> snd(range, INF);
  dp[0] = fst;
  dp[1] = snd;

  dp[0][0] = 0LL;

  for (int i = 1; i <= n; ++i) {
    int cur_ind = i % 2;
    int last_ind = (i - 1) % 2;

    for (int j = 0; j < range; ++j) {
      dp[cur_ind][j] = min(dp[cur_ind][j], dp[last_ind][j]);

      if (dp[last_ind][j] == INF) continue;
      if ((j + v[i]) >= range) continue;

      dp[cur_ind][j + v[i]] =
          min(dp[cur_ind][j + v[i]], dp[last_ind][j] + w[i]);
    }

    for (int j = 0; j < range; ++j) {
      dp[last_ind][j] = INF;
    }
  }

  ll ret = -1;

  for (int j = 0; j < range; ++j) {
    if (dp[n % 2][j] <= bag) ret = j;
  }

  return ret;
}

ll small_weight(ll max_weight) {
  int range = n * max_weight + 5;

  map<int, vector<ll>> dp;
  vector<ll> fst(range, -1);
  vector<ll> snd(range, -1);
  dp[0] = fst;
  dp[1] = snd;

  dp[0][0] = 0LL;

  for (int i = 1; i <= n; ++i) {
    int cur_ind = i % 2;
    int last_ind = (i - 1) % 2;

    for (int j = 0; j < range; ++j) {
      dp[cur_ind][j] = max(dp[cur_ind][j], dp[last_ind][j]);

      if (dp[last_ind][j] == -1) continue;
      if ((j + w[i]) >= range) continue;

      dp[cur_ind][j + w[i]] =
          max(dp[cur_ind][j + w[i]], dp[last_ind][j] + v[i]);
    }

    for (int j = 0; j < range; ++j) {
      dp[last_ind][j] = -1;
    }
  }

  ll ret = -1;

  for (int j = 0; j < range; ++j) {
    if (j <= bag) ret = max(ret, dp[n % 2][j]);
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &bag);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &(v[i]), &(w[i]));
  }

  ll max_value = -1;
  ll max_weight = -1;
  for (int i = 1; i <= n; ++i) {
    max_value = max(max_value, v[i]);
    max_weight = max(max_weight, w[i]);
  }

  if (n <= 30) {
    ans = small_num();
  } else {
    ll max_value = -1;
    ll max_weight = -1;
    for (int i = 1; i <= n; ++i) {
      max_value = max(max_value, v[i]);
      max_weight = max(max_weight, w[i]);
    }

    if (max_value <= 1000) {
      ans = small_value(max_value);
    } else if (max_weight <= 1000) {
      ans = small_weight(max_weight);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
