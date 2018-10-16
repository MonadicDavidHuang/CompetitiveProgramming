#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

void rec(int cnt, string str) {
  if (cnt == n) {
    cout << str << endl;
  } else {
    string tmp_a(str);
    tmp_a.push_back('a');
    rec(cnt + 1, tmp_a);
    string tmp_b(str);
    tmp_b.push_back('b');
    rec(cnt + 1, tmp_b);
    string tmp_c(str);
    tmp_c.push_back('c');
    rec(cnt + 1, tmp_c);
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  rec(0, "");

  return 0;
}
