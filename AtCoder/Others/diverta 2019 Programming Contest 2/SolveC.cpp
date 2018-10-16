#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;

vector<int> minus_vec;
vector<int> plus_vec;

vector<pair<int, int>> ans_pair;

int ans;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);

    if (a < 0) {
      minus_vec.push_back(a);
    } else {
      plus_vec.push_back(a);
    }
  }

  sort(plus_vec.begin(), plus_vec.end());
  sort(minus_vec.begin(), minus_vec.end(), greater<int>());

  if (plus_vec.size() == 0 && minus_vec.size() > 0) {
    if (minus_vec.size() == 2) {
      printf("%d\n", minus_vec[0] - minus_vec[1]);
      printf("%d %d\n", minus_vec[0], minus_vec[1]);

      return 0;
    }

    int cur_plus = minus_vec[0] - minus_vec[1];
    ans_pair.push_back(make_pair(minus_vec[0], minus_vec[1]));

    for (int i = 2; i < minus_vec.size(); ++i) {
      ans_pair.push_back(make_pair(cur_plus, minus_vec[i]));
      cur_plus = cur_plus - minus_vec[i];
    }

    ans = cur_plus;
  } else if (plus_vec.size() > 0 && minus_vec.size() == 0) {
    if (plus_vec.size() == 2) {
      printf("%d\n", plus_vec[1] - plus_vec[0]);
      printf("%d %d\n", plus_vec[1], plus_vec[0]);

      return 0;
    }

    int cur_minus = plus_vec[0] - plus_vec[1];
    ans_pair.push_back(make_pair(plus_vec[0], plus_vec[1]));

    for (int i = 2; i < plus_vec.size() - 1; ++i) {
      ans_pair.push_back(make_pair(cur_minus, plus_vec[i]));
      cur_minus = cur_minus - plus_vec[i];
    }

    ans = plus_vec.back() - cur_minus;
    ans_pair.push_back(make_pair(plus_vec.back(), cur_minus));
  } else {
    if (minus_vec.size() == 1 && plus_vec.size() == 1) {
      printf("%d\n", plus_vec[0] - minus_vec[0]);
      printf("%d %d\n", plus_vec[0], minus_vec[0]);

      return 0;
    }

    for (int i = 0; i < plus_vec.size() - 1; ++i) {
      ans_pair.push_back(make_pair(minus_vec[0], plus_vec[i]));
      minus_vec[0] = minus_vec[0] - plus_vec[i];

      // printf("- ");
      // for (auto e: minus_vec) {
      //   printf("%d ", e);
      // }
      // printf("\n");
    }

    int cur_plus = plus_vec.back();

    for (int i = 0; i < minus_vec.size(); ++i) {
      ans_pair.push_back(make_pair(cur_plus, minus_vec[i]));
      cur_plus = cur_plus - minus_vec[i];
    }

    ans = cur_plus;
  }

  printf("%d\n", ans);

  for (auto &e : ans_pair) {
    printf("%d %d\n", e.first, e.second);
  }

  return 0;
}
