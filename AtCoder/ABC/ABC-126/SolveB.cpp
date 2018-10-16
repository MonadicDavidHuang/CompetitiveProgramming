#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

int main(void) {
  // Here your code !
  cin >> s;

  int ab_num = 10 * (s[0] - '0') + (s[1] - '0');
  int cd_num = 10 * (s[2] - '0') + (s[3] - '0');

  bool ab_is_month = (1 <= ab_num) && (ab_num <= 12);
  bool cd_is_month = (1 <= cd_num) && (cd_num <= 12);

  if (ab_is_month && cd_is_month) {
    printf("AMBIGUOUS\n");
  } else if (ab_is_month) {
    printf("MMYY\n");
  } else if (cd_is_month) {
    printf("YYMM\n");
  } else {
    printf("NA\n");
  }

  return 0;
}
