#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(5e1 + 5);

int n;
int d[MAX_N][MAX_N];
int q;
int p[MAX_N * MAX_N];

int s[MAX_N][MAX_N];
int score[MAX_N * MAX_N];

// (i, k] >< (j, l]
int get_area(int i, int j, int k, int l) {
  return s[k][l] - s[k][j] - s[i][l] + s[i][j];
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &(d[i][j]));
    }
  }

  scanf("%d", &q);

  for (int i = 1; i <= q; ++i) {
    scanf("%d", &(p[i]));
  }

  for (int i = 0; i <= n; ++i) {
    s[0][i] = 0;
    s[i][0] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + d[i][j];
    }
  }

  for (int i = 0; i < MAX_N * MAX_N; ++i) {
    score[i] = -1;
  }

  for (int il = 1; il <= n; ++il)
    for (int ir = il; ir <= n; ++ir) {
      for (int jl = 1; jl <= n; ++jl)
        for (int jr = jl; jr <= n; ++jr) {
          int num = (ir - il + 1) * (jr - jl + 1);

          int cur_score = get_area(il - 1, jl - 1, ir, jr);

          score[num] = max(score[num], cur_score);
        }
    }

  for (int i = 1; i < MAX_N * MAX_N; ++i) {
    score[i] = max(score[i], score[i - 1]);
  }

  for (int i = 1; i <= q; ++i) {
    printf("%d\n", score[p[i]]);
  }

  return 0;
}
