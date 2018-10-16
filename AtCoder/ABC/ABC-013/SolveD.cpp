#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const ll MAX_D = (ll)(1e9 + 5);
const int MAX_LOG_D = (int)(log2(MAX_D) + 5);
const int MAX_N = (int)(1e5 + 5);
const int MAX_M = (int)(2e5 + 5);

int n, m;
ll d;
int a[MAX_M];

int order[MAX_N];

int doubling[MAX_LOG_D][MAX_N];

vector<int> keys;

void swap(int *arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void make_doubling(int log2d) {
  for (int i = 1; i <= n; ++i) {
    doubling[0][i] = order[i];
  }

  for (int j = 1; j <= log2d; ++j) {
    for (int i = 1; i <= n; ++i) {
      int fst_step = doubling[j - 1][i];
      int snd_step = doubling[j - 1][fst_step];
      doubling[j][i] = snd_step;
    }
  }
}

void calc_keys(int log2d, ll target) {
  vector<ll> cand;

  cand.push_back(1LL);
  for (int i = 0; i <= log2d; ++i) {
    cand.push_back(cand.back() * 2);
  }

  for (int i = cand.size() - 1; i >= 0; --i) {
    if (cand[i] <= target) {
      target -= cand[i];
      keys.push_back(i);
    }
  }
}

int do_run(int start) {
  for (auto key : keys) {
    start = doubling[key][start];
  }

  return start;
}

int main(void) {
  // Here your code !
  scanf("%d %d %lld", &n, &m, &d);

  for (int i = 0; i < m; ++i) {
    scanf("%d", &(a[i]));
  }

  for (int i = 1; i <= n; ++i) {
    order[i] = i;
  }

  reverse(a, a + m);

  for (int i = 0; i < m; ++i) {
    swap(order, a[i], a[i] + 1);
  }

  int log2d = (int)(log2(d)) + 3;

  make_doubling(log2d);

  calc_keys(log2d, d);

  for (int i = 1; i <= n; ++i) {
    int goal = do_run(i);
    printf("%d\n", goal);
  }

  return 0;
}
