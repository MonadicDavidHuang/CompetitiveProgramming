#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e18 + 5);

const int MAX_N = (int)(2e5 + 5);
const ll MAX_K = (int)(1e12 + 5);
const int MAX_LOG_NK = (int)(67);

int n;
ll k;
int a[MAX_N];

ll doubling[MAX_LOG_NK][MAX_N];
vector<int> s;
bool exist[MAX_N];

int make_doubling() {
  unordered_map<int, int> ump;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      int ind = i * n + j;

      if (ump.find(a[ind % n]) == ump.end()) {
        ump[a[ind % n]] = ind;
      } else {
        int start = ump[a[ind % n]];
        if (start >= n) continue;  // [0, n) is sufficient

        doubling[1][start] = ind + 1 - start;

        ump[a[ind % n]] = ind;  // new start
      }
    }
  }

  int upper = min((int)(ceil(log2(n * k))), MAX_LOG_NK);

  for (int i = 2; i < upper; ++i) {
    for (int j = 0; j < n; ++j) {
      ll fst_buff = doubling[i - 1][j];
      int fst_ind = (int)(((ll)(j) + fst_buff) % n);
      ll snd_buff = doubling[i - 1][fst_ind];

      doubling[i][j] = (fst_buff + snd_buff);
      doubling[i][j] =
          (doubling[i][j] >= INF) ? INF : doubling[i][j];  // anyway, can't jump
    }
  }

  return upper;
}

ll fast_simulate(int upper) {
  ll last = 0LL;

  while (true) {
    int ind = (int)(last % (ll)(n));
    bool flg = false;

    for (int i = upper - 1; i >= 1; --i) {
      if (last + doubling[i][ind] < (ll)(n)*k) {
        last += doubling[i][ind];
        flg = true;  // jumped
        break;
      }
    }

    if (!flg) {  // can't jump from current pos
      return last;
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d %lld", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(a[i]));
  }

  int upper = make_doubling();

  ll jump = fast_simulate(upper);

  for (ll j = jump; j < (ll)(n)*k; ++j) {
    int ind = (int)(j % (ll)(n));

    bool flg = false;

    while (exist[a[ind]]) {
      flg = true;
      exist[s.back()] = false;
      s.pop_back();
    }

    if (!flg) {
      s.push_back(a[ind]);
      exist[a[ind]] = true;
    }
  }

  for (auto &e : s) {
    printf("%d ", e);
  }
  printf("\n");

  return 0;
}
