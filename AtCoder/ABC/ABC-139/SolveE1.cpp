#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e3 + 5);

int n;
vector<queue<int>> ques(MAX_N);

bool last_modified[MAX_N];
bool unavailable[MAX_N];

void reset() { fill(unavailable + 1, unavailable + n + 1, false); }

void copy_modified() {
  for (int i = 1; i <= n; ++i) {
    last_modified[i] = unavailable[i];
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n - 1; ++j) {
      int a;
      scanf("%d", &a);
      ques[i].push(a);
    }
  }

  reset();  // initialize

  bool poped = false;

  for (int i = 1; i <= n; ++i) {
    if (unavailable[i]) continue;

    if (ques[i].empty()) continue;

    int j = ques[i].front();

    if (unavailable[j]) continue;

    if (ques[j].empty()) continue;

    int other = ques[j].front();

    if (i == other) {
      // printf("i, j: %d %d\n", i, j);
      ques[i].pop();
      ques[j].pop();
      unavailable[i] = true;
      unavailable[j] = true;
      poped = true;
    }
  }

  copy_modified();

  reset();

  if (!poped) {
    printf("-1\n");
    return 0;
  }

  // check done
  bool done = true;
  for (int i = 1; i <= n; ++i) {
    done &= ques[i].empty();
    if (!done) {
      break;
    }
  }

  // check done
  if (done) {
    printf("%d\n", 1);
    return 0;
  }

  int ans;

  for (int day = 2;; ++day) {
    poped = false;

    for (int i = 1; i <= n; ++i) {
      if (!last_modified[i]) continue;

      if (unavailable[i]) continue;

      if (ques[i].empty()) continue;

      int j = ques[i].front();

      if (unavailable[j]) continue;

      if (ques[j].empty()) continue;

      int other = ques[j].front();

      if (i == other) {
        ques[i].pop();
        ques[j].pop();
        unavailable[i] = true;
        unavailable[j] = true;
        poped = true;
      }
    }

    copy_modified();
    reset();

    // check match
    if (!poped) {
      ans = -1;
      break;
    }

    // check done
    bool done = true;
    for (int i = 1; i <= n; ++i) {
      done &= ques[i].empty();
      if (!done) {
        break;
      }
    }

    // check done
    if (done) {
      ans = day;
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}
