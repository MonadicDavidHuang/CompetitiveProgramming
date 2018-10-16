#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
vector<tuple<string, int, int>> sps;

bool cmp(const tuple<string, int, int> &a, const tuple<string, int, int> &b) {
  string str_a = get<0>(a);
  string str_b = get<0>(b);

  int pnt_a = get<1>(a);
  int pnt_b = get<1>(b);

  if (str_a == str_b) {
    return pnt_a > pnt_b;
  } else {
    return str_a < str_b;
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    string s;
    int p;

    cin >> s;
    scanf("%d", &p);

    sps.push_back(make_tuple(s, p, i));
  }

  sort(sps.begin(), sps.end(), cmp);

  for (auto &e : sps) {
    printf("%d\n", get<2>(e));
  }

  return 0;
}
