#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

vector<int> inpt;

int ans;

int main(void) {
  // Here your code !
  for (int i = 0; i < 3; ++i) {
    int tmp;
    scanf("%d", &tmp);
    inpt.push_back(tmp);
  }

  sort(inpt.begin(), inpt.end());

  ans = inpt[0] + inpt[1];

  printf("%d\n", ans);

  return 0;
}
