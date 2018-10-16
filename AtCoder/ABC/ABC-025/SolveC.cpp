#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_ELEM = (int)(3 + 5);

ll b[MAX_ELEM][MAX_ELEM];
ll c[MAX_ELEM][MAX_ELEM];

int maru = 1;
int batu = -1;

map<pair<int, vector<vector<int>>>, pair<ll, ll>> memo;

pair<ll, ll> ans;

pair<ll, ll> calc_score(vector<vector<int>> board) {
  ll tak = 0;
  ll nao = 0;

  for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= 3; ++j) {
      if (board[i][j] == board[i + 1][j]) {
        tak += b[i][j];
      } else {
        nao += b[i][j];
      }
    }

  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 2; ++j) {
      if (board[i][j] == board[i][j + 1]) {
        tak += c[i][j];
      } else {
        nao += c[i][j];
      }
    }

  return make_pair(tak, nao);
}

pair<ll, ll> rec(int turn, vector<vector<int>> board, ll par_val) {
  if (memo.find(make_pair(turn, board)) != memo.end()) {
    return memo[make_pair(turn, board)];
  }

  if (turn == 10) {
    return calc_score(board);
  }

  ll tak, nao;

  if (turn % 2 == 1) {  // tak, max, par min
    ll curmax = -INF;

    for (int i = 1; i <= 3; ++i)
      for (int j = 1; j <= 3; ++j) {
        if (board[i][j] == 0) {
          vector<vector<int>> new_board(board);
          new_board[i][j] = maru;
          pair<ll, ll> tak_and_nao = rec(turn + 1, new_board, curmax);

          ll tmpmax = tak_and_nao.first - tak_and_nao.second;
          if (tmpmax > curmax) {
            tak = tak_and_nao.first;
            nao = tak_and_nao.second;
            curmax = tmpmax;

            if (par_val < curmax) {
              return make_pair(tak, nao);
            }
          }
        }
      }
  } else {  // nao, min, par max
    ll curmin = INF;

    for (int i = 1; i <= 3; ++i)
      for (int j = 1; j <= 3; ++j) {
        if (board[i][j] == 0) {
          vector<vector<int>> new_board(board);
          new_board[i][j] = batu;
          pair<ll, ll> tak_and_nao = rec(turn + 1, new_board, curmin);

          ll tmpmin = tak_and_nao.first - tak_and_nao.second;
          if (tmpmin < curmin) {
            tak = tak_and_nao.first;
            nao = tak_and_nao.second;
            curmin = tmpmin;

            if (par_val > curmin) {
              return make_pair(tak, nao);
            }
          }
        }
      }
  }

  return memo[make_pair(turn, board)] = make_pair(tak, nao);
}

int main(void) {
  // Here your code !
  for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= 3; ++j) {
      scanf("%lld", &(b[i][j]));
    }

  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 2; ++j) {
      scanf("%lld", &(c[i][j]));
    }

  vector<vector<int>> board(MAX_ELEM, vector<int>(MAX_ELEM, 0));

  ans = rec(1, board, INF);

  printf("%lld\n", ans.first);
  printf("%lld\n", ans.second);

  return 0;
}
