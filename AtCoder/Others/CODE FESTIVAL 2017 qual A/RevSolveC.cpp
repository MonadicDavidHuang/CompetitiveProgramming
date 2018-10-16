#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int h, w;

char a[MAX_N][MAX_N];

unordered_map<int, int> count() {
  unordered_map<char, int> cnt;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cnt[a[i][j]] += 1;
    }
  }

  unordered_map<int, int> ret;

  for (auto &e : cnt) {
    ret[e.second % 4] += 1;
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &(a[i]));
  }

  auto cnt = count();

  string ans = "No";

  if (h % 2 == 0 && w % 2 == 0) {
    if (cnt[3] == 0 && cnt[2] == 0 && cnt[1] == 0) ans = "Yes";
  } else if (h % 2 == 1 && w % 2 == 1) {
    if (cnt[1] == 1 && cnt[3] == 0) {
      if (cnt[3] == 0 && (cnt[2] * 2 <= (h + w - 2)) && cnt[1] == 1)
        ans = "Yes";
    } else if (cnt[1] == 0 && cnt[3] == 1) {
      if (cnt[3] == 0 && (cnt[2] * 2 <= (h + w - 4)) && cnt[1] == 1)
        ans = "Yes";
    }
  } else {  // (1, 0) or (0, 1)
    int even = (h % 2 == 0) ? h : w;
    if (cnt[3] == 0 && cnt[2] * 2 <= even && cnt[1] == 0) ans = "Yes";
  }

  cout << ans << endl;

  return 0;
}
