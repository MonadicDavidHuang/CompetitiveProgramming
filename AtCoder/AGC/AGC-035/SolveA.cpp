#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

unordered_map<ll, int> amp;
ll arr[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 1; i < n; ++i) {
    amp[a[i]] += 1;
  }

  arr[0] = a[0];

  bool not_found = true;

  for (int i = 1; i < n; ++i) {
    amp[a[i]] -= 1;
    ll tmp = arr[0] ^ a[i];

    if (amp[tmp] > 0) {
      arr[1] = a[i];
      not_found = false;
      break;
    }

    amp[a[i]] += 1;
  }

  if (not_found) {
    printf("No\n");
    return 0;
  }

  for (int i = 2; i < n; ++i) {
    ll tmp = arr[i - 2] ^ arr[i - 1];

    if (amp[tmp] <= 0) {
      printf("No\n");
      return 0;
    }

    amp[tmp] -= 1;
    arr[i] = tmp;
  }

  if (arr[n - 2] ^ arr[0] == arr[n - 1]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
