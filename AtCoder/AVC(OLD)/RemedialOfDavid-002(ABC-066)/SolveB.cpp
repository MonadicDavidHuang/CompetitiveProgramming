#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

string s;

bool check(int tmp_size) {
  for (int j = 0; j < tmp_size; ++j) {
    if (s[j] != s[tmp_size + j]) return false;
  }
  return true;
}

int main(void) {
  // Here your code !
  cin >> s;

  int length = 0;

  for (int i = 2; i <= s.size(); i += 2) {
    int tmp_size = (s.size() - i) / 2;

    if (!check(tmp_size)) continue;

    length = s.size() - i;
    break;
  }

  printf("%d\n", length);

  return 0;
}
