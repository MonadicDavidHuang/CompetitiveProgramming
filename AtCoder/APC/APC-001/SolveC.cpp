#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int n;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  vector<string> s(n + 1);

  cout << 0 << endl;
  cin >> s[0];
  if (s[0] == "Vacant") return 0;

  int left = 0;
  int right = n;

  s[n] = s[0];

  if ((n - 0) % 2 == 0) return 0;

  while (true) {
    int mid = (left + right) / 2;

    cout << mid << endl;
    cin >> s[mid];

    if (s[mid] == "Vacant") return 0;

    // if left part is valid, then right part must be
    // if right part is valid, then left part must be
    // (same, even), or, (diff, odd)
    if ((s[mid] == s[left]) ^ ((mid - left) % 2 == 1))
      left = mid;
    else
      right = mid;
  }

  return 0;
}
