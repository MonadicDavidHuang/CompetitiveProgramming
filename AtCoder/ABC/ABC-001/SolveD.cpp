#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(3e4 + 5);
const int MAX_T = (int)(2e3 + 5);

int n;
int arr[MAX_T];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    int begin = 60 * (10 * (s[0] - '0') + (s[1] - '0')) +
                (10 * (s[2] - '0') + (s[3] - '0'));
    int end = 60 * (10 * (s[5] - '0') + (s[6] - '0')) +
              (10 * (s[7] - '0') + (s[8] - '0'));

    int begin_curl = 5 * (begin / 5);
    int end_curl = 5 * ((end + 5 - 1) / 5);

    arr[begin_curl] += 1;
    arr[end_curl + 1] += -1;
  }

  for (int i = 1; i < MAX_T; ++i) {
    arr[i] += arr[i - 1];
  }

  bool flg = false;
  for (int i = 0; i < MAX_T; ++i) {
    if (!flg && arr[i] > 0) {
      printf("%02d%02d", i / 60, i % 60);
      flg = true;
    } else if (flg && arr[i] == 0) {
      printf("-%02d%02d\n", (i - 1) / 60, (i - 1) % 60);
      flg = false;
    }
  }

  return 0;
}
