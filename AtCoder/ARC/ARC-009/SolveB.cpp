#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

ll bs[10];
int n;
vector<string> as;

ll convert(string str) {
  ll ret = 0LL;

  ll base = 1LL;
  for (int i = str.size() - 1; i >= 0; --i) {
    int key = int(str[i] - '0');

    ret += bs[key] * base;

    base *= 10LL;
  }

  return ret;
}

int main(void) {
  // Here your code !
  for (int i = 0; i < 10; ++i) {
    int b;
    scanf("%d", &b);

    bs[b] = (ll)(i);
  }

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    as.push_back(a);
  }

  sort(as.begin(), as.end(),
       [&](string a, string b) { return convert(a) < convert(b); });

  for (auto &e : as) {
    cout << e << endl;
  }

  return 0;
}
