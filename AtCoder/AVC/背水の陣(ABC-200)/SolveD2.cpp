#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e2 + 5);

int n;
int a[MAX_N];

vector<int> cand[MAX_N];

int calc_and_get_index() {
  for (int e = 1; e < (1 << min(8, n)); ++e) {
    int cur = 0;
    for (int i = 0; i < min(8, n); ++i) {
      if ((e >> i) & 1) {
        cur += a[i];
        cur %= 200;
      }
    }

    cand[cur].push_back(e);

    if (cand[cur].size() >= 2) return cur;
  }

  return -1;
}

void print_ans(int index) {
  printf("Yes\n");

  for (auto e : cand[index]) {
    int num = 0;
    for (int i = 0; i < min(8, n); ++i) {
      if ((e >> i) & 1) num += 1;
    }
    printf("%d ", num);
    for (int i = 0; i < min(8, n); ++i) {
      if ((e >> i) & 1) printf("%d ", i + 1);
    }
    printf("\n");
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] %= 200;
  }

  if (n >= 8) {  // definitely have answer
    print_ans(calc_and_get_index());
  } else {  // possibly have answer
    int index = calc_and_get_index();

    if (index > -1)
      print_ans(index);
    else
      printf("No\n");
  }

  return 0;
}
