#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e3 + 5);

/////////////////////////////////////////////////////////////
class ZAlgorithm {
 public:
  string s;
  string t;
  string phi;
  string sct;
  vector<int> z;

  ZAlgorithm(string s, string t, char phi) {
    this->z = vector<int>(t.size() + 1 + s.size(), 0);

    this->s = s;
    this->t = t;
    this->phi = phi;
    init();
  }

  void init() {
    sct = t + phi + s;
    make_z();
  }

  void make_z() {
    int n = sct.size();
    int l = 0, r = 0;

    z[0] = sct.size();

    for (int i = 1; i < n; ++i) {
      if (i > r) {
        l = r = i;
        while (r < n && sct[r - l] == sct[r]) r += 1;

        z[i] = r - l;
        r -= 1;
      } else {
        int k = i - l;  // focus at prefix-substring (begin with sct[k]) with
                        // which already dealed

        // no prefix-substring (begin with sct[i]) longer than (r - i + 1) could
        // be expected since, "sct[0..(r - l)] == sct[l..r]" entails "sct[k..(r
        // - l)] == sct[i..r]", but z[k] is smaller than length of sct[i..r]
        if (z[k] < r - i + 1) {
          z[i] = z[k];
        } else {  // there could be longer prefix-substring (begin with sct[i])
          l = i;
          while (r < n && sct[r - l] == sct[r]) r += 1;

          z[i] = r - l;
          r -= 1;
        }
      }
    }
  }

  bool match_from(int i) { return z[t.size() + 1 + i] == t.size(); }

  int z_value(int i) { return z[t.size() + 1 + i]; }
};
/////////////////////////////////////////////////////////////

int n;
string s;

int calc(int begin) {
  string target = s.substr(begin, s.size() - begin);

  int min_inds[MAX_N];
  int max_inds[MAX_N];

  for (int i = 0; i <= s.size(); ++i) {
    min_inds[i] = s.size();
    max_inds[i] = -1;
  }

  ZAlgorithm za(s, target, '_');

  for (int i = 0; i < s.size(); ++i) {
    int cur = za.z_value(i);
    min_inds[cur] = min(min_inds[cur], i);
    max_inds[cur] = max(max_inds[cur], i);
  }

  int ind_min = s.size();
  int ind_max = -1;
  for (int i = s.size(); i > 0; --i) {
    ind_min = min(ind_min, min_inds[i]);
    ind_max = max(ind_max, max_inds[i]);

    min_inds[i] = ind_min;
    max_inds[i] = ind_max;
  }

  int ret = 0;

  for (int i = 1; i < s.size(); ++i) {
    if (min_inds[i] == max_inds[i]) continue;

    if (min_inds[i] + i - 1 < max_inds[i]) {
      ret = max(ret, i);
    }
  }

  return ret;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  cin >> s;

  int ans = 0;

  for (int i = 0; i < s.size(); ++i) {
    ans = max(ans, calc(i));
  }

  printf("%d\n", ans);

  return 0;
}
