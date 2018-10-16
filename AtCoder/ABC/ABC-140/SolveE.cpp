#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
int p[MAX_N];

int idx[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(p[i]));
    p[i] -= 1;
    idx[p[i]] = i;
  }

  set<int> st;

  ll ans = 0LL;

  for (int x = n - 1; x >= 0; --x) {
    int i = idx[x];

    ll c = 0LL;

    {  // calc c
      st.insert(i);
      vector<int> l(2, -1);
      vector<int> r(2, n);

      {  // calc l
        auto itr = st.find(i);
        for (int j = 0; j < 2; ++j) {
          if (itr == st.begin()) break;
          --itr;
          l[j] = *itr;
        }
      }

      {  // calc r
        auto itr = st.find(i);
        for (int j = 0; j < 2; ++j) {
          ++itr;
          if (itr == st.end()) break;
          r[j] = *itr;
        }
      }

      vector<int> ls(2);
      ls[0] = i - l[0];
      ls[1] = l[0] - l[1];

      vector<int> rs(2);
      rs[0] = r[0] - i;
      rs[1] = r[1] - r[0];

      c = (ll)(ls[0] * rs[1]) + (ll)(ls[1] * rs[0]);
    }

    ans += c * (x + 1);
  }

  printf("%lld\n", ans);

  return 0;
}
