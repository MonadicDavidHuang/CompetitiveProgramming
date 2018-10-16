#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

int n;

int a, b, c;

int l[MAX_N];

int base[MAX_N];

int ans = 11451419;

void rec(int cnt, map<int, int> mp) {
  if (cnt == n) {
    map<int, int> calc;

    calc[1] = 0;
    calc[2] = 0;
    calc[3] = 0;

    map<int, int> times;

    times[1] = -1;
    times[2] = -1;
    times[3] = -1;

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
      if (itr->second == 0) continue;
      calc[itr->second] += l[itr->first];
      times[itr->second] += 1;
    }

    vector<int> tmpvec;

    for (auto itr = calc.begin(); itr != calc.end(); ++itr) {
      if (itr->second == 0) return;
      tmpvec.push_back(itr->second);
    }

    sort(tmpvec.begin(), tmpvec.end());

    int tmpmagic = (times[1] + times[2] + times[3]) * 10;

    for (int i = 0; i < 3; ++i) {
      tmpmagic += abs(tmpvec[i] - base[i]);
    }

    ans = min(ans, tmpmagic);

  } else {
    for (int i = 0; i < 4; ++i) {
      mp[cnt] = i;
      rec(cnt + 1, mp);
    }
  }
}

int main(void) {
  // Here your code !

  scanf("%d", &n);
  scanf("%d %d %d", &a, &b, &c);

  base[0] = c;
  base[1] = b;
  base[2] = a;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(l[i]));
  }

  map<int, int> mp;

  rec(0, mp);

  printf("%d\n", ans);

  return 0;
}
