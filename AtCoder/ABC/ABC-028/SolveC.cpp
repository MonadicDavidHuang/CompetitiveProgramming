#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5 + 5);

int alphabet[MAX_N];

vector<int> cand;

int ans;

int main(void) {
  // Here your code !
  for (int i = 0; i < 5; ++i) {
    scanf("%d", &(alphabet[i]));
  }

  int comb = (1 << 3) - 1;
  while (comb < 1 << 5) {
    int tmp = 0;
    for (int i = 0; i < 5; ++i) {
      if (comb >> i & 1) {
        tmp += alphabet[i];
      }
    }

    cand.push_back(tmp);

    int x = comb & -comb;
    int y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }

  sort(cand.begin(), cand.end(), greater<int>());

  ans = cand[2];

  printf("%d\n", ans);

  return 0;
}
