#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e2 + 5);

int n;
int a[MAX_N];

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &(a[i]));
  }

  int whole = 0;

  for (int i = 0; i < n; ++i) {
    whole += a[i];
  }

  if (whole % n != 0) {
    printf("%d\n", -1);
    return 0;
  }

  int target = whole / n;

  int ans_left = 0;
  int left_acc = 0;
  int left_island = 0;
  for (int i = 0; i < n; ++i) {
    left_acc += a[i];
    left_island += 1;

    if (left_acc % left_island != 0 || left_acc / left_island != target) {
      ans_left += 1;
    } else {
      left_acc = 0;
      left_island = 0;
    }
  }

  int ans_right = 0;
  int right_acc = 0;
  int right_island = 0;
  for (int i = n - 1; i >= 0; --i) {
    right_acc += a[i];
    right_island += 1;

    if (right_acc % right_island != 0 || right_acc / right_island != target) {
      ans_right += 1;
    } else {
      right_acc = 0;
      right_island = 0;
    }
  }

  int ans = min(ans_left, ans_right);

  printf("%d\n", ans);

  return 0;
}
