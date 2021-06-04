#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

int c[3 + 5][3 + 5];

int a[3 + 5];
int b[3 + 5];

bool check() {
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j) {
      if (a[i] + b[j] != c[i][j]) {
        return false;
      }
    }
  return true;
}

int main(void) {
  // Here your code !
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j) {
      scanf("%d", &(c[i][j]));
    }

  int sum1 = c[1][1] + c[2][1] + c[3][1];
  int sum2 = c[1][2] + c[2][2] + c[3][2];
  int sum3 = c[1][3] + c[2][3] + c[3][3];

  for (a[1] = 0; a[1] <= 100; ++(a[1])) {
    for (a[2] = 0; a[2] <= 100; ++(a[2])) {
      for (a[3] = 0; a[3] <= 100; ++(a[3])) {
        int suma = a[1] + a[2] + a[3];

        if ((sum1 - suma) % 3 != 0) continue;
        b[1] = (sum1 - suma) / 3;

        if ((sum2 - suma) % 3 != 0) continue;
        b[2] = (sum2 - suma) / 3;

        if ((sum3 - suma) % 3 != 0) continue;
        b[3] = (sum3 - suma) / 3;

        for (int i = 1; i <= 3; ++i)
          for (int j = 1; j <= 3; ++j) {
            if (check()) {
              printf("Yes\n");
              return 0;
            }
          }
      }
    }
  }

  printf("No\n");

  return 0;
}
