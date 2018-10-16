#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_R = (int)(1e5 + 5);

int rock = 1;
int sicer = 2;
int paper = 3;

int n;

int r[MAX_N];
int h[MAX_N];

int accum_rock[MAX_R];   // rock
int accum_sicer[MAX_R];  // sicer
int accum_paper[MAX_R];  // paper

void solve(int i) {
  int win = 0;
  int even = 0;
  int lose = 0;

  // case only rating matter
  win += accum_rock[r[i] - 1] - accum_rock[0];
  win += accum_sicer[r[i] - 1] - accum_sicer[0];
  win += accum_paper[r[i] - 1] - accum_paper[0];

  lose += accum_rock[MAX_R - 1] - accum_rock[r[i]];
  lose += accum_sicer[MAX_R - 1] - accum_sicer[r[i]];
  lose += accum_paper[MAX_R - 1] - accum_paper[r[i]];

  // case hand matter (with same rating)
  // you: rock, others: rock
  if (h[i] == rock) {
    even += accum_rock[r[i]] - accum_rock[r[i] - 1] - 1;  // you do not lose to yourself
    win += accum_sicer[r[i]] - accum_sicer[r[i] - 1];
    lose += accum_paper[r[i]] - accum_paper[r[i] - 1];
  } else if (h[i] == sicer) {
    even += accum_sicer[r[i]] - accum_sicer[r[i] - 1] - 1;  // you do not lose to yourself
    win += accum_paper[r[i]] - accum_paper[r[i] - 1];
    lose += accum_rock[r[i]] - accum_rock[r[i] - 1];
  } else {                                                  // paper
    even += accum_paper[r[i]] - accum_paper[r[i] - 1] - 1;  // you do not lose to yourself
    win += accum_rock[r[i]] - accum_rock[r[i] - 1];
    lose += accum_sicer[r[i]] - accum_sicer[r[i] - 1];
  }

  printf("%d %d %d\n", win, lose, even);
}

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &(r[i]), &(h[i]));
  }

  accum_rock[0] = accum_sicer[0] = accum_paper[0] = 0;

  for (int i = 0; i < n; ++i) {
    if (h[i] == rock) {
      accum_rock[r[i]] += 1;
    } else if (h[i] == sicer) {
      accum_sicer[r[i]] += 1;
    } else {  // paper
      accum_paper[r[i]] += 1;
    }
  }

  for (int i = 1; i < MAX_R; ++i) {
    accum_rock[i] += accum_rock[i - 1];
    accum_sicer[i] += accum_sicer[i - 1];
    accum_paper[i] += accum_paper[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    solve(i);
  }

  return 0;
}
