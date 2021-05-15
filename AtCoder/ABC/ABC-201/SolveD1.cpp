#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
// const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(2e3 + 5);
const int INF = (int)(1e8 + 5);
const int EMPTY = (int)(1e8 + 6);

int h, w;
char field[MAX_N][MAX_N];

int tak = 0;
int aok = 1;

// score = tak_score + -1 * aok_score
// tak: maximize score
// aok: minimize score

// memo[i][j]: max score of tak in field[i][j] (i + j) % 2 == 0
// memo[i][j]: min score of aok in field[i][j] (i + j) % 2 == 1
int memo[MAX_N][MAX_N];

bool good2go(int a, int b) {
  return (0 <= a && a < h && 0 <= b && b < w);
}

int rec_tak(int i, int j);
int rec_aok(int i, int j);

int rec_tak(int i, int j) {
  if (memo[i][j] != EMPTY) return memo[i][j];

  bool can_go_right = good2go(i, j + 1);
  bool can_go_down = good2go(i + 1, j);

  if (!can_go_down && !can_go_right) {
    return memo[i][j] = 0;
  }

  int player_right_score = -INF;
  int player_down_score = -INF;

  if (can_go_right) {  // go right
    int opponent_right_score = rec_aok(i, j + 1);
    int player_right_gain = (field[i][j + 1]) == '+' ? 1 : -1;
    player_right_score = opponent_right_score + player_right_gain;
  }

  if (can_go_down) {  // go down
    int opponent_down_score = rec_aok(i + 1, j);
    int player_down_gain = (field[i + 1][j]) == '+' ? 1 : -1;
    player_down_score = opponent_down_score + player_down_gain;
  }

  return memo[i][j] = max(player_right_score, player_down_score);
}

int rec_aok(int i, int j) {
  if (memo[i][j] != EMPTY) return memo[i][j];

  bool can_go_right = good2go(i, j + 1);
  bool can_go_down = good2go(i + 1, j);

  if (!can_go_down && !can_go_right) {
    return memo[i][j] = 0;
  }

  int player_right_score = INF;
  int player_down_score = INF;

  if (can_go_right) {  // go right
    int opponent_right_score = rec_tak(i, j + 1);
    int player_right_gain = -1 * ((field[i][j + 1]) == '+' ? 1 : -1);
    player_right_score = opponent_right_score + player_right_gain;
  }

  if (can_go_down) {  // go down
    int opponent_down_score = rec_tak(i + 1, j);
    int player_down_gain = -1 * ((field[i + 1][j]) == '+' ? 1 : -1);
    player_down_score = opponent_down_score + player_down_gain;
  }

  return memo[i][j] = min(player_right_score, player_down_score);
}

int main(void) {
  // Here your code !

  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; ++i) {
    scanf("%s", &field[i]);
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      memo[i][j] = EMPTY;
      memo[i][j] = EMPTY;
    }
  }

  int score = rec_tak(0, 0);

  if (score > 0) {
    printf("Takahashi\n");
  } else if (score == 0) {
    printf("Draw\n");
  } else {
    printf("Aoki\n");
  }

  return 0;
}
