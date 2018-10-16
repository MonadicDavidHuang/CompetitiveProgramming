#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e1 + 5);

int n;
int b[MAX_N];

map<int, int> memo;

int ans;

int calc(int boss) {
  if (memo.find(boss) != memo.end()) return memo[boss];

  vector<int> soldier_pay = {};

  for (int i = 2; i <= n; ++i) {
    if (b[i] == boss) soldier_pay.push_back(calc(i));
  }

  if (soldier_pay.empty()) return memo[boss] = 1;  // not boss

  int max_pay = *max_element(soldier_pay.begin(), soldier_pay.end());
  int min_pay = *min_element(soldier_pay.begin(), soldier_pay.end());

  return memo[boss] = max_pay + min_pay + 1;
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 2; i <= n; ++i) {
    scanf("%d", &(b[i]));
  }

  ans = calc(1);

  printf("%d\n", ans);

  // for (int i = 1; i <= n; ++i) {
  //   printf("%d %d\n", i, calc(i));
  // }

  return 0;
}
