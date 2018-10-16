#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e5 + 5);

int n, k;
int p[MAX_N];

int counter_mono_part() {
  p[n] = -1;

  int ret = 0;

  int cnt = 1;

  for (int i = 1; i <= n; ++i) {
    if (p[i - 1] < p[i])
      cnt += 1;
    else {
      if (cnt >= k) ret += 1;
      cnt = 1;
    }
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(p[i]));
  }

  set<int> st;

  for (int i = 0; i < k; ++i) {
    st.insert(p[i]);
  }

  int cnt = 1;

  int mono_part = counter_mono_part();

  for (int i = 1; (i + k - 1) < n; ++i) {
    int last_begin_ind = i - 1;
    int last_begin = p[last_begin_ind];

    int cur_end = p[i + k - 1];

    int last_max = *(--st.end());

    st.erase(st.find(last_begin));

    int cur_min = *(st.begin());

    if (!(last_begin < cur_min && last_max < cur_end)) {
      cnt += 1;
    }

    st.insert(cur_end);
  }

  int ans = cnt;

  if (mono_part >= 1) {
    ans -= mono_part;
    ans += 1;
  }

  printf("%d\n", ans);

  return 0;
}
