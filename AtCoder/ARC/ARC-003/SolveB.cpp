#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;
vector<string> ss;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ss.push_back(s);
  }

  sort(ss.begin(), ss.end(), [&](string a, string b) {
    string ra(a);
    string rb(b);
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    return ra < rb;
  });

  for (auto &e : ss) {
    // e.reserve();
    cout << e << endl;
  }

  return 0;
}
