#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

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
        // be expected since, "sct[0..(r - l)] == sct[l..r]" entails
        // "sct[k..(r - l)] == sct[i..r]", but z[k] is smaller than length of
        // sct[i..r]
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

int main(void) {
  // Here your code !
  string s = "aaabaaaab";
  string t = "ab";

  ZAlgorithm za(s, t, '_');

  cout << s << endl;

  for (int i = 0; i < s.size(); ++i) {
    printf("------------------\n");
    printf("%d\n", za.z_value(i));
    if (za.match_from(i)) {
      printf("yes %c%c\n", s[i], s[i + 1]);
    } else {
      printf("no  %c%c\n", s[i], s[i + 1]);
    }
    printf("------------------\n");
  }

  return 0;
}
