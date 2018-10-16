#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_H = (int)(2e3 + 5);
const int MAX_W = (int)(2e3 + 5);

int h, w;
char field[MAX_H][MAX_W];

int row_acc[MAX_H][MAX_W];
int col_acc[MAX_W][MAX_H];

int ans = -1;

int bi_left(int ok, int ng, int row, int score) {
  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (row_acc[row][next] >= score) {
      ok = next;
    } else {
      ng = next;
    }
  }

  if (field[row - 1][ok - 1] == '#') ok += 1;

  return ok;
}

int bi_right(int ok, int ng, int row, int score) {
  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (row_acc[row][next] < score) {
      ok = next;
    } else {
      ng = next;
    }
  }

  return ok;
}

int bi_top(int ok, int ng, int col, int score) {
  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (col_acc[next][col] >= score) {
      ok = next;
    } else {
      ng = next;
    }
  }

  if (field[ok - 1][col - 1] == '#') ok += 1;

  return ok;
}

int bi_down(int ok, int ng, int col, int score) {
  while (abs(ok - ng) > 1) {
    int next = (ok + ng) / 2;

    if (col_acc[next][col] < score) {
      ok = next;
    } else {
      ng = next;
    }
  }

  return ok;
}

int main(void) {
  // Here your code !
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &(field[i]));
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      row_acc[i][j] = (field[i - 1][j - 1] == '#' ? 1 : 0);
      row_acc[i][j] += row_acc[i][j - 1];
    }
  }

  for (int j = 1; j <= w; ++j) {
    for (int i = 1; i <= h; ++i) {
      col_acc[i][j] = (field[i - 1][j - 1] == '#' ? 1 : 0);
      col_acc[i][j] += col_acc[i - 1][j];
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (field[i - 1][j - 1] == '#') continue;

      int left = bi_left(j, 0, i, row_acc[i][j]);
      int right = bi_right(j, w + 1, i, row_acc[i][j] + 1);

      int top = bi_top(i, 0, j, col_acc[i][j]);
      int down = bi_down(i, h + 1, j, col_acc[i][j] + 1);

      int cur_light = (j - left) + (right - j) + (i - top) + (down - i) + 1;

      ans = max(ans, cur_light);
    }
  }

  printf("%d\n", ans);

  return 0;
}
