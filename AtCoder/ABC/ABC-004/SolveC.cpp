#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(6 + 5);

ll n;

int arr[MAX_N];

int main(void) {
  // Here your code !
  scanf("%lld", &n);

  ll po = n / 5;

  ll pod = po % 6;

  int pos = (pod == 0) ? 1 : 7 - pod;

  for (int i = pos, cnt = 1; i <= 6; ++i, ++cnt) {
    arr[i] = cnt;
  }

  for (int i = pos - 1, cnt = 6; i >= 1; --i, --cnt) {
    arr[i] = cnt;
  }

  for (int i = 0; i < (n % 5); ++i) {
    int tmp = arr[(i % 5) + 2];
    arr[(i % 5) + 2] = arr[(i % 5) + 1];
    arr[(i % 5) + 1] = tmp;
  }

  for (int i = 1; i <= 6; ++i) {
    printf("%d", arr[i]);
  }

  printf("\n");

  return 0;
}
