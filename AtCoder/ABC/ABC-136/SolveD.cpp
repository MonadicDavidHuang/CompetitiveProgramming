#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);
const int MAX_LOG = (int)(335 + 5);

string s;

int n;
int doubling[MAX_LOG][MAX_N];

string binexp =
    "10010010010011010110100100101100101001100001101111101000000000000000000000"
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000";

void make_doubling() {
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      doubling[0][i] = i + 1;
    } else {
      doubling[0][i] = i - 1;
    }
  }

  for (int i = 1; i < MAX_LOG; ++i) {
    for (int j = 0; j < n; ++j) {
      int fst = doubling[i - 1][j];
      int snd = doubling[i - 1][fst];
      doubling[i][j] = snd;
    }
  }
}

int after[MAX_N];

int ans[MAX_N];

int main(void) {
  // Here your code !
  cin >> s;

  n = s.size();

  reverse(binexp.begin(), binexp.end());

  make_doubling();

  for (int i = 0; i < n; ++i) {
    after[i] = i;
  }

  for (int i = 0; i < binexp.size(); ++i) {
    if (binexp[i] == '0') continue;

    for (int j = 0; j < n; ++j) {
      after[j] = doubling[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    ans[after[i]] += 1;
  }

  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}
