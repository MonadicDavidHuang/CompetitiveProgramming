#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

/////////////////////////////////////////////////////////////
class RollingHash {
 public:
  using hash_type = tuple<ll, ll, ll>;

  string s;

  vector<ll> base;
  vector<ll> mod;

  vector<vector<ll>> hash;
  vector<vector<ll>> pow;

  RollingHash(string s) {
    this->s = s;

    base = {1009LL, 1007LL, 1005LL};
    mod = {(ll)(1e9 + 7), (ll)(1e9 + 9), (ll)(999999937)};

    hash = vector<vector<ll>>(3, vector<ll>());
    pow = vector<vector<ll>>(3, vector<ll>());

    init(s);
  }

  void init(const string &s) {
    int n = s.size();

    for (int i = 0; i < 3; ++i) hash[i].assign(n + 1, 0);
    for (int i = 0; i < 3; ++i) pow[i].assign(n + 1, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; ++j) {
        hash[j][i + 1] = (hash[j][i] + s[i]) * base[j] % mod[j];
        pow[j][i + 1] = pow[j][i] * base[j] % mod[j];
      }
    }
  }

  // 0-indexed, [l, r]
  hash_type get(int l, int r) {
    l += 1;
    r += 1;

    l -= 1;

    ll t0 =
        ((hash[0][r] - hash[0][l] * pow[0][r - l]) % mod[0] + mod[0]) % mod[0];
    ll t1 =
        ((hash[1][r] - hash[1][l] * pow[1][r - l]) % mod[1] + mod[1]) % mod[1];
    ll t2 =
        ((hash[2][r] - hash[2][l] * pow[2][r - l]) % mod[2] + mod[2]) % mod[2];

    return make_tuple(t0, t1, t2);
  }

  // get hash for whole string
  hash_type get_whole() { return get(0, s.size() - 1); }
};
/////////////////////////////////////////////////////////////

int main(void) {
  // Here your code !
  string s = "1145141919_810_1145141919";
  string t = "114514";

  RollingHash rhs(s);
  RollingHash rht(t);

  for (int i = 0; i < s.size(); ++i) {
    for (int j = i; j < s.size(); ++j) {
      int l = i;
      int r = j;

      int len = r - l + 1;
      string cur = s.substr(i, len);

      auto cur_sh = rhs.get(l, r);
      auto th = rht.get_whole();

      if (cur_sh == th) {
        cout << "-------------------------" << endl;
        printf("(l, r): (%d, %d)\n", l, r);
        cout << cur << endl;
        cout << t << endl;
        cout << "-------------------------" << endl;
      }
    }
  }

  return 0;
}
